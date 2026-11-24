# Gameplay Quest Framework for Unreal Engine 5

[![Unreal Engine](https://img.shields.io/badge/Unreal%20Engine-5.8%2B-blue?logo=unrealengine&logoColor=white)](https://www.unrealengine.com/)
[![Tests](https://img.shields.io/badge/Automated%20Tests-33%20Enterprise%20Passing-brightgreen)](USER_GUIDE.md)
[![Architecture](https://img.shields.io/badge/Architecture-Zero--Tick%20Tag%20Routing-blue)](#key-highlights)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![Author](https://img.shields.io/badge/Author-Shankharaj%20Datta-blue?logo=linkedin)](https://www.linkedin.com/in/shankharaj-datta-45921a28a/)

A production-grade, zero-tick, modular, and authoritative C++ quest and objective framework engineered for Unreal Engine 5 (UE 5.8+).

Designed from first principles to power single-player story campaigns, co-op multiplayer adventures, and high-density MMORPG questing environments without relying on asset bloat or per-frame tick overhead.

---

## Key Highlights

- **Pure C++ Architecture & Zero Asset Bloat**: 100% decoupled from project-specific characters, meshes, audio cues, or UI templates. Integrate on any `AActor`, `APlayerController`, `APlayerState`, or `ACharacter` via modular components and interfaces.
- **Zero-Tick Inverted Tag Event Routing**: Objectives subscribe directly to hierarchical GameplayTags (`Quest.Event.*`) in an inverted tag index (`UGameplayQuestEventSubsystem`). Dispatched world events resolve in sub-microsecond $O(1)$ lookups, eliminating polling loops and actor tick overhead.
- **Strict Network Authority & Zero Multicast RPCs**: Powered entirely by `FFastArraySerializer` dirty-delta serialization and client `RepNotify` delegates. Guaranteed bandwidth efficiency, zero packet storming, and rock-solid late-joiner / reconnect synchronization.
- **Primary Data Asset Inline Objectives**: Quests are authored as `UGameplayQuestDefinition` PrimaryDataAssets with inline instanced `UGameplayObjectiveDefinition` objects, supporting composite branches, sequential and concurrent stages, prerequisites tag queries, and failure timers.
- **Cross-World & Multi-Level Session Bridge**: `UGameplayQuestDataSubsystem` (`UGameInstanceSubsystem`) preserves active quest portfolios across level streaming, World Partition cells, and `OpenLevel` / Server Travel transitions without requiring mid-game disk writes.
- **World & Zone Scope Scrim**: Every objective supports optional `ZoneScopeTag` filtering (e.g. `Zone.Dungeon.Citadel`), isolating dungeon encounters from hub progression in co-op sessions.
- **Dual Persistence Engine**: Native support for compact binary serialization (`ExportToBinary` / `ImportFromBinary` for `USaveGame` and dedicated server migration) alongside human-readable JSON schema serialization (`ExportToJson` / `ImportFromJson` for cloud databases, MongoDB, PostgreSQL, and REST backends).
- **Designer & Live QA Ergonomics**: Built-in developer console commands (`quest.list`, `quest.progress`, `quest.complete`, `quest.hud`) and a low-overhead Slate HUD widget for real-time in-viewport debugging.
- **Comprehensive Automated Test Coverage**: 33 enterprise unit, integration, network, persistence, architecture audit, and benchmark tests passing headless with 100% success rate.

---

## Architectural Systems Breakdown

```text
[ World Event Broadcaster / Enemy / Interactable / Trigger ]
  │
  ├── UGameplayQuestFunctionLibrary::BroadcastKillEvent / Collect / Interact / Area
  ▼
[ UGameplayQuestEventSubsystem (UWorldSubsystem) ]
  │  • Inverted Tag Index: Maps FGameplayTag -> Subscribed Objective Records
  │  • Zone Scope Validation: Tags events with current World ZoneTag
  ▼
[ UGameplayQuestManagerComponent (Server Authority) ]
  │  • Replicated State Machine (FFastArraySerializer: FGameplayQuestItemList)
  │  • Stage Sequencer (Sequential vs. Concurrent Stage Progression)
  │  • Objective Evaluator (Kill, Collect, Interact, ReachArea, Timer, Composite)
  │  • Auto-Persistence (GameInstance Cross-World Travel Cache)
  ▼
[ Network Replication Layer ]
  │  • Dirty Delta Bunches (Zero Multicast RPCs)
  │  • Client RepNotify: OnRep_CompletedQuestTags, OnRep_FailedQuestTags
  ▼
[ Client UI / Slate Debugger HUD ]
  └── SGameplayQuestDebugHUD (Low-overhead Slate Compound Widget)
```

---

## Plugin Directory Structure

```text
GameplayQuestFramework/
├── Config/
│   └── FilterPlugin.ini                # Packaging filter configuration
├── Resources/
│   ├── Icon128.png                     # Plugin marketplace & browser icon
│   └── Icons/                          # High-DPI Slate class icons & thumbnails
│       ├── GameplayObjectiveDefinition_16.png / _64.png
│       ├── GameplayQuestDefinition_16.png / _64.png
│       ├── GameplayQuestGiverComponent_16.png / _64.png
│       ├── GameplayQuestManagerComponent_16.png / _64.png
│       └── GameplayQuestTriggerVolume_16.png / _64.png
├── Source/
│   └── GameplayQuestFramework/         # Primary runtime & editor module
│       ├── Public/
│       │   ├── Interfaces/             # Manager, Giver, Interactable, Party interfaces
│       │   ├── Objectives/             # Modular objective definitions (Kill, Collect, etc.)
│       │   ├── UI/                     # Slate Debug HUD widget
│       │   ├── GameplayObjectiveDefinition.h
│       │   ├── GameplayQuestDataSubsystem.h
│       │   ├── GameplayQuestDefinition.h
│       │   ├── GameplayQuestEventSubsystem.h
│       │   ├── GameplayQuestFunctionLibrary.h
│       │   ├── GameplayQuestGiverComponent.h
│       │   ├── GameplayQuestManagerComponent.h
│       │   ├── GameplayQuestSaveData.h
│       │   ├── GameplayQuestSettings.h
│       │   ├── GameplayQuestTags.h
│       │   ├── GameplayQuestTriggerVolume.h
│       │   └── GameplayQuestTypes.h
│       └── Private/
│           ├── Tests/                  # 33 automated domain-driven tests
│           │   ├── Audit/              # Zero-NetMulticast architecture audit
│           │   ├── Integration/        # Lifecycle, interface, and party tests
│           │   ├── Network/            # FastArray delta & RepNotify tests
│           │   ├── Performance/        # 10,000-event stress & save throughput benchmarks
│           │   ├── Persistence/        # Binary & JSON schema roundtrip tests
│           │   └── Unit/               # Objectives, settings, subsystems, and tags
│           ├── GameplayQuestConsole.cpp
│           └── GameplayQuestModule.cpp # Slate style set registration
├── LICENSE                             # License terms
├── README.md                           # Overview & architectural reference
├── USER_GUIDE.md                       # Comprehensive step-by-step user manual
└── GameplayQuestFramework.uplugin      # Plugin descriptor
```

---

## Core Systems Reference

### 1. `UGameplayQuestManagerComponent`
Authoritative actor component managing active, completed, and failed quests for a player or AI agent.
- Attach to `APlayerController`, `APlayerState`, or `ACharacter`.
- Implements `FFastArraySerializer` replicated item list for net-efficient synchronization.
- Automatically handles cross-level travel caching via `UGameplayQuestDataSubsystem`.

### 2. `UGameplayQuestDefinition`
Primary Data Asset defining quest metadata, progression flow, requirements, and rewards:
- **Stages**: Array of `FGameplayQuestStage` structs holding instanced objectives.
- **Progression Flow**: Sequential stages (Stage $N+1$ unlocks after Stage $N$) or Concurrent.
- **Prerequisite Queries**: `FGameplayTagQuery` checking player level, completed quests, or story milestones.
- **Co-Op Sharing Policy**: Solo only, Party Uniform, Party Proximity, or World Shared.

### 3. Modular Objective Definitions (`UGameplayObjectiveDefinition`)
Inline instanced objective definitions:
- `UKillObjectiveDefinition`: Target enemy tag and required count.
- `UCollectObjectiveDefinition`: Item tag, quantity, and consumption policy.
- `UInteractObjectiveDefinition`: World interactable actor query.
- `UReachAreaObjectiveDefinition`: Trigger volume or zone boundary detection.
- `UTimerObjectiveDefinition`: Countdown timer with zero-tick manager timer handles.
- `UCompositeObjectiveDefinition`: AND / OR logical grouping of child objectives.

---

## Verification & Automated Testing

Run the headless automation test suite in Unreal Engine:

```powershell
& "UnrealEditor-Cmd.exe" "<ProjectPath>/<ProjectName>.uproject" -ExecCmds="Automation RunTests GameplayQuest; Quit" -unattended -nopause -nullrhi -nosound
```

All 33 tests execute across 6 architectural domains with **Exit Code: 0** and **0 Failures**.

---

## License & Attribution

Distributed under the **MIT License**. See [LICENSE](LICENSE) for details.

Created by **[Shankharaj Datta](https://www.linkedin.com/in/shankharaj-datta-45921a28a/)**.
