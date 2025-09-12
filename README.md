# Gameplay Quest System Plugin (UE5)

A lightweight, Blueprint-friendly quest framework for Unreal Engine 5 that centralizes quest flow and event handling so designers can focus on gameplay, not plumbing.

---

## ✨ Features
- **Centralized Quest Flow** via `UGameplayQuestBase`
- **Three Core Native Events** to override in your Quest BP:
  - `Start Quest`
  - `Complete Quest`
  - `Reset Quest`
- **Quest Manager Subsystem** as the **central hub** for all quest registration, event flow, and tracking
- **Event-Driven with Gameplay Tags**: broadcast and respond to tagged gameplay events instead of hard references
- **Designer-First**: 100% Blueprint workflow, no C++ required

---

## 🚀 Blueprint Workflow (Quick Start)

1. **Create Your Quest Blueprint**
   - Inherit from `UGameplayQuestBase` (e.g., `BP_MyQuest`).
   - Override the **native events** in Blueprint:
     - `Start Quest` → Called when quest is activated.
     - `Complete Quest` → Called when quest finishes.
     - `Reset Quest` → Called when quest restarts/clears.
   - Add quest-specific variables (e.g., target count, objectives).

2. **Activate (Register) the Quest**
   - Anywhere in your game (UI button, overlap, narrative cue):
     - **Get Game Instance Subsystem → Gameplay Quest Manager Subsystem**
     - Call **Register Quest** with your Quest Class (e.g., `BP_MyQuest`).
     - Store the returned **Quest Ref**.

3. **Start the Quest**
   - Call **Start Quest** on the Quest Ref to trigger its logic.

4. **Broadcast Gameplay Events**
   - From gameplay systems (pickups, combat, triggers):
     - Call **Broadcast Quest Event** on the **Quest Manager Subsystem**.
     - Provide a **Gameplay Tag** (e.g., `Event.Item.Collected`).
     - Optionally pass data (e.g., actor, name, int).

5. **Quest Responds to Events**
   - In your Quest BP (`BP_MyQuest`):
     - Use **Switch on Gameplay Tag** inside the event listener.
     - Example:
       - `Event.Item.Collected` → Increment item count.
       - `Event.Enemy.Defeated` → Mark boss defeated.

6. **Complete or Reset**
   - When objectives are done → Call **Complete Quest**.
   - To replay/reset → Call **Reset Quest**.
   - Subsystem updates global state and notifies listeners.

---

## 🧭 Example Flow (Blueprint Pseudograph)

- **Trigger (UI/Overlap/BeginPlay)**  
  → Register Quest (`BP_MyQuest`)  
  → Start Quest  

- **Gameplay Producer (e.g., Pickup Actor)**  
  → Broadcast Quest Event (Tag: `Event.Item.Collected`)  

- **Quest BP (`BP_MyQuest`)**  
  - `Start Quest` → Show UI objective  
  - Switch on Gameplay Tag:  
    - `Event.Item.Collected` → Update progress; if target reached → `Complete Quest`  
  - `Complete Quest` → Reward player, update journal  
  - `Reset Quest` → Clear progress, hide UI  

---

## 🧪 Sample Project
Try the **sample UE5 project** that demonstrates the plugin in action:  
👉 [Sample UE5 Quest System Project]([https://github.com/yourusername/QuestSystemSample](https://drive.google.com/drive/folders/1N2vbHkmcZg7wRXJsU60csybFuRw8tn6X?usp=sharing))  

> ⚠️ Requires **Unreal Engine 5.3+** and the **Gameplay Tags plugin enabled**.

---

## 🔧 Tips
- Keep **event tags consistent** (e.g., `Event.Item.Collected`, `Event.Enemy.Defeated`).
- The **Quest Manager Subsystem** is the **single source of truth** — all events go through it.
- Use the three **native events** (`Start Quest`, `Complete Quest`, `Reset Quest`) to tailor quest logic in Blueprint.

---

## 🔒 Requirements
- Unreal Engine **5.3+**
- **Gameplay Tags plugin** enabled
- Fully Blueprint-compatible

---

## 📜 License
MIT — see `LICENSE`.
