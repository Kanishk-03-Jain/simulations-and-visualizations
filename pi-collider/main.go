package main

import (
	"fmt"

	rl "github.com/gen2brain/raylib-go/raylib"
)

const (
	Width  = 900
	Height = 600

	SmallBlockSize = 50
	BigBlockSize   = 100

	TimeSteps = 100000
)

type Block struct {
	X    float64
	Vx   float64
	M    float64
	Size float64
}

type Simulation struct {
	BigBlock   Block
	SmallBlock Block
	Collisions int
}

func NewSimulation() *Simulation {
	return &Simulation{
		BigBlock:   Block{X: Width * 0.75, Vx: -100, M: 10000000000, Size: BigBlockSize},
		SmallBlock: Block{X: Width * 0.25, Vx: 0, M: 1, Size: SmallBlockSize},
		Collisions: 0,
	}
}

func (s *Simulation) UpdatePhysics(dt float64) {
	// Divide the frame into tiny steps.
	// This ensures blocks never pass through each other between frames.
	subDt := dt / float64(TimeSteps)

	for i := 0; i < TimeSteps; i++ {
		// Check Wall Collision
		if s.SmallBlock.X <= 0 && s.SmallBlock.Vx < 0 {
			s.SmallBlock.Vx = -s.SmallBlock.Vx
			s.Collisions++
		}

		// Check Block Collision
		if s.SmallBlock.X+s.SmallBlock.Size >= s.BigBlock.X && s.SmallBlock.Vx > s.BigBlock.Vx {
			// Elastic collision formula
			mB, mS := s.BigBlock.M, s.SmallBlock.M
			vB, vS := s.BigBlock.Vx, s.SmallBlock.Vx

			newVB := ((mB-mS)*vB + 2*mS*vS) / (mB + mS)
			newVS := ((mS-mB)*vS + 2*mB*vB) / (mB + mS)

			s.BigBlock.Vx = newVB
			s.SmallBlock.Vx = newVS
			s.Collisions++
		}

		// Update Positions by the tiny time step
		s.BigBlock.X += s.BigBlock.Vx * subDt
		s.SmallBlock.X += s.SmallBlock.Vx * subDt
	}
}

func (s *Simulation) Draw() {
	rl.DrawRectangle(int32(s.BigBlock.X), Height/2, BigBlockSize, BigBlockSize, rl.White)
	rl.DrawRectangle(int32(s.SmallBlock.X), Height/2+(BigBlockSize-SmallBlockSize), SmallBlockSize, SmallBlockSize, rl.White)

	txt := fmt.Sprintf("Collisions: %d", s.Collisions)
	rl.DrawText(txt, 100, 10, 50, rl.White)
}

func main() {
	rl.InitWindow(Width, Height, "PI collider")
	defer rl.CloseWindow()

	rl.SetTargetFPS(60)

	sim := NewSimulation()

	for !rl.WindowShouldClose() {
		sim.UpdatePhysics(float64(rl.GetFrameTime()))

		rl.BeginDrawing()
		rl.ClearBackground(rl.Black)

		sim.Draw()

		rl.EndDrawing()
	}
}
