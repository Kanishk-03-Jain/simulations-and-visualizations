# Doppler Effect Simulator

A lightweight, interactive physics simulation demonstrating the [Doppler Effect](https://en.wikipedia.org/wiki/Doppler_effect), written in C using the [raylib](https://www.raylib.com/) library. 

##  Features

- **Interactive Emitter**: Move the sound source (emitter) in real-time.
- **Dynamic Waves**: Emits circular sound waves at a constant frequency.
- **Doppler Shift Visualization**: Observe how moving the emitter causes sound waves to bunch up in the direction of motion (higher frequency) and spread out behind it (lower frequency).

## Prerequisites

To build and run this project, you need:
- A C compiler (`gcc` recommended)
- `make`
- [raylib](https://www.raylib.com/) installed on your system.

## Building & Running

A `Makefile` is provided for easy compilation.

**To build the project:**
```bash
make build
```

**To run the simulator:**
```bash
make run
```
*(You can also run both commands at once using `make build && make run`)*

**To clean the build files:**
```bash
make clean
```

## Controls

- <kbd>↑</kbd> <kbd>↓</kbd> <kbd>←</kbd> <kbd>→</kbd> : Move the sound emitter around the screen.
