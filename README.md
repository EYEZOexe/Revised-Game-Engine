# Labyrinth Engine

A custom **2D game engine** built from scratch in C++ using CMake, designed with modularity and flexibility at its core.

## Overview

Labyrinth Engine was developed as part of my Game Software Engineering degree at Bournemouth University. The engine mirrors Unreal Engine's architectural principles — featuring a hybrid inheritance/component system that enables scalable feature development and code reuse.

## Features

- **Hybrid Architecture** — Combines inheritance-based class hierarchy with a component system for maximum flexibility
- **Swappable Graphics Pipeline** — Modular renderer design allowing different graphics backends to be plugged in without changing game logic
- **Physics System** — 2D collision detection and response
- **Audio Manager** — Integrated audio playback system
- **Asset Manager** — Centralised asset loading and management
- **UI Framework** — Widget-based UI system with buttons, text, images, status meters, and HUD support
- **Particle System** — VFX through the LabyrinthVFX module
- **Game Stage System** — Stage-based game flow management

## Tech Stack

- **Language:** C++
- **Build System:** CMake
- **Architecture:** Entity-Component hybrid with modular subsystems

## Project Structure

```
LabyrinthEngine/
├── include/
│   ├── LabyrinthFramework/   # Core engine (Actor, Application, World, Physics, Audio, Assets)
│   ├── LabyrinthVFX/         # Particle system
│   ├── Gameplay/             # Game stages and flow control
│   └── UI/                   # Widget-based UI (Buttons, Text, Images, HUD, StatusMeter)
├── src/                      # Implementation files (mirrors include structure)
└── CMakeLists.txt
Game/                         # Sample game built on the engine
CMakeLists.txt                # Root build configuration
```

## Documentation

- 📄 [Technical Report (PDF)](https://github.com/user-attachments/files/16913723/S5216712.Labyrinth.Engine.Technical.Report.pdf)

## Author

**Thomas Malandris** — [GitHub](https://github.com/EYEZOexe) · [Website](https://thomasmalandris.com)
