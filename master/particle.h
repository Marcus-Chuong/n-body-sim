#include "C:\Users\marcu\Desktop\Folder of Death\n-body-sim\master\src\vector.h" // Update this path to the correct location of vector.h
#pragma once

class Particle {
public:
    Vector position, velocity, acceleration;
    
    void update(float dt);
    void display();


}