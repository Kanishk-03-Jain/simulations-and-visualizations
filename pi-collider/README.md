# PI Collider

A simple 2D physics simulation written in Go using [raylib-go](https://github.com/gen2brain/raylib-go). It simulates perfectly elastic collisions between two blocks and a wall to calculate the digits of Pi. 

This project is inspired by the famous mathematical observation (popularized by 3Blue1Brown) where the number of collisions between two sliding blocks and a wall, where one block's mass is a power of 100 times the other, corresponds to the digits of Pi.

## Features

- Real-time physics simulation using Raylib.
- Object-oriented simulation structure in Go.
- Precision sub-stepping for collision detection to prevent tunneling effects.

## Prerequisites

To run this project, you will need:
- [Go](https://golang.org/doc/install) installed on your system.
- A C compiler (like GCC or Clang) since `raylib-go` relies on Cgo.

## Running the Simulation

1. Clone or download this repository.
2. Navigate to the project directory in your terminal:
   ```bash
   cd path/to/pi-collider
   ```
3. Run the simulation using the Go CLI:
   ```bash
   go run main.go
   ```

## How It Works

- The **Small Block** has a mass of $1$.
- The **Big Block** has a much larger mass ($10^{n}$).
- All collisions are assumed to be perfectly elastic (no energy lost).
- As the Big Block slides towards the Small Block, it repeatedly bounces the Small Block between itself and the wall. 
- The total number of collisions before the blocks drift apart forever gives the digits of Pi!

## Modifying the Simulation

You can adjust the simulation variables in `main.go` under the `NewSimulation` function or the `const` block:
- **`TimeSteps`**: Increase this value if you increase the mass ratio, to ensure high-precision collision detection.
- **`M` (Mass)**: Change the mass of the `BigBlock`. For example, setting the mass to $100^d$ will compute $d+1$ digits of $\pi$.
