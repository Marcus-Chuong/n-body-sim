#include "C:\Users\marcu\Desktop\Folder of Death\n-body-sim\master\headers\quadtree.h"
#include <iostream>
#include <vector>
#include "C:\Users\marcu\Desktop\Folder of Death\n-body-sim\master\headers\particle.h"

Quadtree::Quadtree(float x, float y, float w) {
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

void Quadtree::Split(){
    float halfWidth = w / 2;
    float x = this->x;
    float y = this->y;
    children[0] = Quadtree(x, y, halfWidth);
    children[1] = Quadtree(x + halfWidth, y, halfWidth);
    children[2] = Quadtree(x, y + halfWidth, halfWidth);
    children[3] = Quadtree(x + halfWidth, y + halfWidth, halfWidth);
    leaf = false;
}

void Quadtree::Insert(Particle p){
    if (leaf){
        if (particleCount == 0){
            particle = p;
            totalCenterOfMass = Vector::add(totalCenterOfMass, Vector::mult(p.pos, p.heat));
            totalMass += p.heat;
            particleCount++;
        } else {
            if (particleCount == 1){
                Split();
                for (int i = 0; i < 4; i++){
                    children[i].Insert(particle);
                }
                particleCount++;
                particle = Particle();
                totalCenterOfMass = Vector::add(totalCenterOfMass, Vector::mult(p.pos, p.heat));
                totalMass += p.heat;
                for (int i = 0; i < 4; i++){
                    children[i].Insert(p);
                }
            } else {
                totalCenterOfMass = Vector::add(totalCenterOfMass, Vector::mult(p.pos, p.heat));
                totalMass += p.heat;
                for (int i = 0; i < 4; i++){
                    children[i].Insert(p);
                }
            }
        }
    } else {
        totalCenterOfMass = Vector::add(totalCenterOfMass, Vector::mult(p.pos, p.heat));
        totalMass += p.heat;
        for (int i = 0; i < 4; i++){
            children[i].Insert(p);
        }
    }
}