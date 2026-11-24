# Gameplay Quest Framework — Complete User Guide

Welcome to the **Gameplay Quest Framework** user guide. This document provides step-by-step instructions for game designers and C++/Blueprint programmers to create quests, track objectives, handle multiplayer co-op, persist player progress, and debug live gameplay in Unreal Engine 5.

---

## Table of Contents

1. [Quick Start: Setting Up the Quest Manager](#1-quick-start-setting-up-the-quest-manager)
2. [Authoring Your First Quest (Primary Data Asset)](#2-authoring-your-first-quest-primary-data-asset)
3. [Configuring Modular Objectives](#3-configuring-modular-objectives)
   - [Kill Objective](#kill-objective)
   - [Collect Objective](#collect-objective)
   - [Interact Objective](#interact-objective)
   - [Reach Area Objective](#reach-area-objective)
   - [Timer Objective](#timer-objective)
   - [Composite Objective (AND / OR Groups)](#composite-objective-and--or-groups)
4. [Broadcasting World Events](#4-broadcasting-world-events)
5. [Setting Up Quest Giver NPCs & Mission Boards](#5-setting-up-quest-giver-npcs--mission-boards)
6. [Multiplayer Co-Op & Party Sharing Policies](#6-multiplayer-co-op--party-sharing-policies)
7. [Cross-World & Level Travel Persistence](#7-cross-world--level-travel-persistence)
8. [Dual Persistence Engine (Local SaveGame & Cloud DB JSON)](#8-dual-persistence-engine-local-savegame--cloud-db-json)
9. [Developer Console Commands & Slate Debugger HUD](#9-developer-console-commands--slate-debugger-hud)
10. [Troubleshooting & FAQ](#10-troubleshooting--faq)

---

## 1. Quick Start: Setting Up the Quest Manager

To enable an actor (e.g. Player Character, Player Controller, or Player State) to participate in quests:

1. Open your Player Blueprint (or C++ class, e.g. `BP_HeroCharacter` or `BP_PlayerController`).
2. In the **Components** panel, click **Add** and select **Gameplay Quest Manager Component** (`UGameplayQuestManagerComponent`).
3. (Optional but recommended) In the Blueprint's **Class Settings**, add the **Gameplay Quest Manager Interface** (`IGameplayQuestManagerInterface`) and implement `GetQuestManagerComponent` returning your added component. This provides instant $O(1)$ lookup for all system queries.

```
[ Player Controller / Character Blueprint ]
  ├── Add Component: UGameplayQuestManagerComponent
  └── Implement Interface: IGameplayQuestManagerInterface -> returns ManagerComponent
```

---

## 2. Authoring Your First Quest (Primary Data Asset)

Quests in `GameplayQuestFramework` are authored as lightweight, version-controlled **Primary Data Assets**:

1. In the Content Browser, right-click and select **Miscellaneous -> Data Asset**.
2. Select **GameplayQuestDefinition** as the asset class and name it (e.g. `DA_Quest_DefeatGoblins`).
3. Open the asset and configure its properties:
   - **Quest Tag**: Unique identifier (e.g. `Quest.Side.GoblinsInTheWoods`).
   - **Quest Title & Description**: Display text for your UI journal.
   - **Progression Flow Tag**:
     - `Quest.Progression.Sequential`: Stages unlock one by one.
     - `Quest.Progression.Concurrent`: All stages run concurrently.
   - **Stages Array**: Add stage items containing one or more inline objectives.
   - **Prerequisites Tag Query**: Optional `FGameplayTagQuery` checking player tags before allowing quest start.
   - **Sharing Policy**: Choose how party members share progress (`SoloOnly`, `PartyUniform`, `PartyProximity`, or `WorldShared`).

---

## 3. Configuring Modular Objectives

Objectives are instanced directly inside the `Objectives` array of a Quest Stage. Click the **+** button on `Objectives` and select the desired objective type:

### Kill Objective (`UKillObjectiveDefinition`)
- **Target Tag**: GameplayTag identifying the enemy class (e.g. `Target.Enemy.Goblin`).
- **Required Count**: Number of enemies to eliminate (e.g. `5`).

### Collect Objective (`UCollectObjectiveDefinition`)
- **Item Tag**: GameplayTag representing the item (e.g. `Item.Quest.Relic`).
- **Required Count**: Quantity needed (e.g. `3`).
- **bConsumeOnComplete**: If true, items are removed upon quest turn-in.

### Interact Objective (`UInteractObjectiveDefinition`)
- **Interactable Tag**: Tag identifying the target object (e.g. `Quest.Target.Interact.AncientChest`).
- **Required Count**: Usually `1`.

### Reach Area Objective (`UReachAreaObjectiveDefinition`)
- **Area Tag**: Tag matching an in-world `AGameplayQuestTriggerVolume` (e.g. `Zone.Dungeon.BossChamber`).

### Timer Objective (`UTimerObjectiveDefinition`)
- **Duration**: Countdown in seconds.
- **bFailOnExpire**: If true, failing to complete other stage objectives before timeout marks the quest as `Failed.Timeout`.

### Composite Objective (`UCompositeObjectiveDefinition`)
- Allows combining multiple sub-objectives with **AND** (all must complete) or **OR** (completing any branch completes the objective).

---

## 4. Broadcasting World Events

Broadcasting events in your game does **not** require referencing the Quest Manager or character classes. Broadcasters simply call the static `UGameplayQuestFunctionLibrary`:

### In Blueprints:
- **On Enemy Defeated**: Call `BroadcastKillEvent(WorldContext, KillerActor, VictimActor, EnemyTag)`.
- **On Item Picked Up**: Call `BroadcastCollectEvent(WorldContext, CollectorActor, ItemTag, Quantity)`.
- **On Interaction**: Call `BroadcastInteractEvent(WorldContext, InteractorActor, TargetActor, InteractTag)`.
- **On Area Entered**: Call `BroadcastAreaReachedEvent(WorldContext, Pawn, AreaTag)`.

### In C++:
```cpp
#include "GameplayQuestFunctionLibrary.h"

// Enemy death trigger
UGameplayQuestFunctionLibrary::BroadcastKillEvent(this, KillerPawn, VictimActor, FGameplayTag::RequestGameplayTag("Target.Enemy.Goblin"));

// Item pickup trigger
UGameplayQuestFunctionLibrary::BroadcastCollectEvent(this, CollectorPawn, FGameplayTag::RequestGameplayTag("Item.Quest.Relic"), 1);
```

---

## 5. Setting Up Quest Giver NPCs & Mission Boards

1. Add a **Gameplay Quest Giver Component** (`UGameplayQuestGiverComponent`) to your NPC or Mission Board Blueprint.
2. In the Details panel, populate **Offered Quests** with your quest tags (e.g. `Quest.Main.Awakening`).
3. When the player talks to the NPC:
   - Call `UGameplayQuestGiverComponent::InteractWithGiver(PlayerActor)` or `OfferQuestsToInteractor(PlayerActor)`.
   - The component automatically checks prerequisites and assigns available quests to the player's Quest Manager.

---

## 6. Multiplayer Co-Op & Party Sharing Policies

The framework features built-in co-op policies configured per quest:

- **Solo Only (`Quest.Policy.Sharing.SoloOnly`)**: Only the player performing the action gets objective progress.
- **Party Uniform (`Quest.Policy.Sharing.PartyUniform`)**: When any member in the party scores a kill or collect, all members in the party receive progress regardless of distance.
- **Party Proximity (`Quest.Policy.Sharing.PartyProximity`)**: Party members within `DefaultPartyShareRadius` (default: 5000 cm) receive credit.
- **World Shared (`Quest.Policy.Sharing.WorldShared`)**: Any player in the same world / map instance shares progress (ideal for MMO world bosses and public events).

Party membership is decoupled through `IGameplayQuestPartyProvider`, which can be implemented by your `GameState` or `PartySubsystem`.

---

## 7. Cross-World & Level Travel Persistence

In multi-level or open-world games:
1. When a player transitions levels (via `OpenLevel` or Server Travel), the player actor and components are destroyed by Unreal Engine.
2. The `UGameplayQuestDataSubsystem` (`UGameInstanceSubsystem`) automatically preserves active quest states and elapsed timers across the transition.
3. Upon arriving in the new world, the player's new `UGameplayQuestManagerComponent` automatically restores the quest portfolio in $O(1)$ time during `BeginPlay`.

---

## 8. Dual Persistence Engine (Local SaveGame & Cloud DB JSON)

### Binary SaveGame Serialization (Local / Dedicated Server Migration)
```cpp
TArray<uint8> SaveBuffer;
QuestManager->ExportSaveData(PlayerGuid).ExportToBinary(SaveBuffer);

// Hydrate into another manager:
FGameplayQuestSaveData RestoredData;
RestoredData.ImportFromBinary(SaveBuffer);
QuestManager->ImportSaveData(RestoredData);
```

### JSON Serialization (Cloud / MMORPG Databases)
```cpp
FString JsonString;
QuestManager->ExportSaveData(PlayerGuid).ExportToJson(JsonString);

// REST API / Database read:
FGameplayQuestSaveData RestoredData;
RestoredData.ImportFromJson(JsonString);
QuestManager->ImportSaveData(RestoredData);
```

---

## 9. Developer Console Commands & Slate Debugger HUD

During PIE or standalone testing, use the built-in developer console commands:

| Command | Description |
| :--- | :--- |
| `quest.list` | Dumps all active, completed, and failed quests for the local player to the console log. |
| `quest.progress <QuestTag> <ObjectiveTag> [Qty]` | Manually increments progress on an objective for rapid QA testing. |
| `quest.complete <QuestTag>` | Instantly completes an active quest and triggers rewards. |
| `quest.hud [0\|1]` | Toggles the lightweight on-screen Slate Debugger HUD. |

---

## 10. Troubleshooting & FAQ

**Q: My objective is not receiving events.**  
A: Ensure the event is broadcast with the exact matching GameplayTag, and verify if the objective has a `ZoneScopeTag` that matches the current world's `ZoneTag`.

**Q: How do I test late-joiner replication?**  
A: Start a dedicated server session with 2 players. Have Player 1 accept a quest and complete stage 1. Have Player 2 join late. Player 2's replicated `ActiveQuestList` and `OnRep_CompletedQuestTags` will automatically synchronize without any server multicast calls.
