#include "include/renderer.h"
#include "include/state.h"

Vector2 getEndPos(Branch *branch) {
    float x = branch->length * sinf(branch->theta);
    float y = branch->length * cosf(branch->theta);
    return (Vector2) {branch->startPos.x + x, branch->startPos.y - y};
}

Branch getChild(Branch *parent, char side) {
    Branch child;
    child.length = parent->length * RATIO;
    child.startPos = getEndPos(parent);
    child.thickness = parent->thickness * RATIO;

    if (side == 'L') {
        child.theta = parent->theta - ANGLE;
    } else if (side == 'R') {
        child.theta = parent->theta + ANGLE;
    }
    return child;
}

void init(Branch *branch) {
    branch->length = INITIAL_LEN;
    branch->theta = 0;
    branch->thickness = INITIAL_THICHNESS;
    branch->startPos = (Vector2){ WIDTH / 2, HEIGHT - 5};
}