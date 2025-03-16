#include "C:\Users\marcu\Desktop\Folder of Death\n-body-sim\master\headers\particle.h"
#include <iostream>
#include <vector>

class Particle {
public:
    Vector pos;
    Vector vel;
    Vector nextPos;
    Vector nextVel;
    float heat;

    Particle() : pos(Vector()), vel(Vector()), nextPos(Vector()), nextVel(Vector()), heat(1.0f) {}
    Particle(Vector pos, Vector vel) : pos(pos), vel(vel), nextPos(pos), nextVel(vel), heat(1.0f) {}

    void update(float dt) {
        pos = Vector::add(pos, Vector::mult(vel, dt));
        heat *= 0.999f;
    }

    void display() {
        // Define the stroke function or include the appropriate header file
        // For example, if stroke is a function that sets the color for drawing:
        // void stroke(Color color) { /* implementation */ }

        // Assuming getColor is defined elsewhere
       /* Color color = getColor(heat / 15.0f);
        stroke(color);
        point(pos.x, pos.y);*/
    }



};
