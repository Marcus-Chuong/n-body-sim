// quadtree header file
#include <vector>
#include "particle.h"
#define QUADTREE_H

class Quadtree {
public:
    float x, y, w;
    std::vector<Quadtree> children;
    bool leaf;
    Particle particle;

    Vector totalCenterOfMass;
    Vector centerOfMass;
    float totalMass;
    int particleCount;

    Quadtree(float x, float y, float w) {
        this->x = x;
        this->y = y;
        this->w = w;
        this->leaf = true;
        this->particle = Particle(); // Assuming Particle has a default constructor
        this->children = std::vector<Quadtree>(4); // Initialize with 4 children
        this->totalCenterOfMass = Vector(0, 0); // Assuming Vector has a constructor that takes two floats
        this->centerOfMass = Vector(); // Assuming Vector has a default constructor
        this->totalMass = 0;
        this->particleCount = 0;
    }

    void Split();
    void Insert(Particle p);
    void findParticle(std::vector<Particle>);
    void display();


};