#pragma once

#include <raylib.h>
#include <math.h>

#define ANGLE PI/11.0f
#define RATIO 0.75f
#define MAX_DEPTH 16
#define INITIAL_LEN 200
#define INITIAL_THICHNESS 20

typedef struct {
    float length;
    float theta;
    float thickness;
    Vector2 startPos;
} Branch;


Vector2 getEndPos(Branch *branch);

Branch getChild(Branch *parent, char side);

void init(Branch *branch);