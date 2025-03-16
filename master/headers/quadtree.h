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

    Quadtree(float x, float y, float w);
    void Split();
    void Insert(Particle p);
    void findParticle(std::vector<Particle>& particles);
    void display();
};