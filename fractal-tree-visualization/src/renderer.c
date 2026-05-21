#include "include/renderer.h"
#include "include/state.h"

void drawBranch(Branch *branch) {
    Vector2 endPos = getEndPos(branch);
    DrawLineEx(branch->startPos, endPos, branch->thickness, WHITE);
}

void drawFractal(Branch *branch, int depth) {
    if (depth == 0) {
        return;
    }
    drawBranch(branch);

    Branch left = getChild(branch, 'L');
    Branch right = getChild(branch, 'R');

    drawFractal(&left, depth - 1);
    drawFractal(&right, depth - 1);
}