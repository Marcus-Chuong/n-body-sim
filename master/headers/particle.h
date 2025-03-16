#include "C:\Users\marcu\Desktop\Folder of Death\n-body-sim\master\headers\vector.h" // Update this path to the correct location of vector.h
#pragma once

class Particle {
public:
    Vector pos;
    Vector vel;
    Vector nextPos;
    Vector nextVel;
    float heat;

    Particle();
    Particle(Vector pos, Vector vel);
    void update(float dt);
    void display() {
        /*stroke(getColor(heat / 15.0f));
        point(pos.x, pos.y);*/
    }
};