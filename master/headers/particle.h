#include "C:\Users\marcu\Desktop\Folder of Death\n-body-sim\master\headers\vector.h"
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
    void display();
};