#include "C:\Users\marcu\Desktop\Folder of Death\n-body-sim\master\src\vector.h" // Update this path to the correct location of vector.h
#pragma once

class Particle {
public:
    Vector pos;
    Vector vel;
    Vector nextPos;
    Vector nextVel;
    float heat;

    Particle(Vector pos, Vector vel) 
        : pos(pos), vel(vel), nextPos(pos), nextVel(vel), heat(1.0f) {}

    void update(float dt) {
        pos = pos.add(vel.mult(dt));
        heat *= 0.999f;
    }

    void display() {
        stroke(getColor(heat / 15.0f));
        point(pos.x, pos.y);
    }
};