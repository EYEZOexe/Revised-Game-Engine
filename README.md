# Labyrinth Engine

A custom **2D game engine** built from scratch in C++ using CMake, designed with modularity and flexibility at its core.

## Overview

Labyrinth Engine was developed as part of my Game Software Engineering degree at Bournemouth University. The engine mirrors Unreal Engine's architectural principles — featuring a hybrid inheritance/component system that enables scalable feature development and code reuse.

## Features

- **Hybrid Architecture** — Combines inheritance-based class hierarchy with a component system for maximum flexibility
- **Swappable Graphics Pipeline** — Modular renderer design allowing different graphics backends to be plugged in without changing game logic
- **Component System** — Attach and detach behaviours at runtime for dynamic entity configuration
- **Input Handling** — Abstracted input system supporting keyboard and controller
- **Physics** — Basic 2D collision detection and response

## Tech Stack

- **Language:** C++
- **Build System:** CMake
- **Architecture:** Entity-Component hybrid with modular subsystems

## Architecture Highlights

```
Engine/
├── Core/          # Engine loop, timing, memory
├── Graphics/      # Swappable rendering pipeline
├── Physics/       # Collision detection & response
├── Input/         # Abstracted input handling
├── Components/    # Reusable behaviour components
└── Entities/      # Game object hierarchy
```

## Documentation

- 📄 [Technical Report (PDF)](https://github.com/user-attachments/files/16913723/S5216712.Labyrinth.Engine.Technical.Report.pdf)

## Author

**Thomas Malandris** — [GitHub](https://github.com/EYEZOexe) · [Website](https://thomasmalandris.com)
