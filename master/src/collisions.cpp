#include "C:\Users\marcu\Desktop\Folder of Death\n-body-sim\master\headers\collisions.h"
#include "C:\Users\marcu\Desktop\Folder of Death\n-body-sim\master\headers\vector.h"
#include "C:\Users\marcu\Desktop\Folder of Death\n-body-sim\master\headers\particle.h"
#include "C:\Users\marcu\Desktop\Folder of Death\n-body-sim\master\headers\quadtree.h"
#include <vector>
#include <cmath>

const float r = 1.0; // Assuming radius of particles
const float restitution = 0.9; // Assuming restitution coefficient

void collide(std::vector<Particle>& particles, Quadtree& root) {
    for (Particle& p : particles) {
        p.nextPos = p.pos.copy();
        p.nextVel = p.vel.copy();
    }
    for (Particle& p : particles) {
        collide(p, root);
    }

    for (Particle& p : particles) {
        p.pos = p.nextPos;
        p.vel = p.nextVel;
    }
}

void collide(Particle& p, Quadtree& tn) {
    // Collide with a particle
    if (tn.leaf) {
        if (tn.particleCount == 0 || &p == &tn.particle) return;

        float dist = p.pos.dist(tn.particle.pos);
        collide(p, tn.particle, dist);
        return;
    }

    // Find which quadrant to collide with
    for (Quadtree& child : tn.children) {
        bool outside = p.pos.x + 2 * r < child.x || p.pos.x - 2 * r > child.x + child.w
                    || p.pos.y + 2 * r < child.y || p.pos.y - 2 * r > child.y + child.w;
        if (!outside) {
            collide(p, child);
        }
    }
}

// From https://stackoverflow.com/questions/345838/ball-to-ball-collision-detection-and-handling
void collide(Particle& a, Particle& b, float dist) {
    if (dist > 2 * r) return;

    Vector dPos = Vector::sub(a.pos, b.pos);
    dPos.normalize();

    // Push-pull them apart (mtd stands for "minimum translation distance")
    float invHeatA = 1 / (a.heat + 1);
    float invHeatB = 1 / (b.heat + 1);
    Vector mtd = Vector::mult(dPos, (2 * r - dist) * invHeatA / (invHeatA + invHeatB));
    a.nextPos.add(mtd);

    float impactSpeed = Vector::dot(Vector::sub(a.vel, b.vel), dPos);
    a.heat += std::abs(impactSpeed) * 0.1;

    // If already moving away from each other, return
    if (impactSpeed > 0) return;

    Vector force = Vector::mult(dPos, impactSpeed * (1 + restitution) * 0.5);
    a.nextVel.sub(force);
}