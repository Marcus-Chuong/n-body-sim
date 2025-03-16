#include <vector>
#include "C:\Users\marcu\Desktop\Folder of Death\n-body-sim\master\headers\vector.h"
#include "C:\Users\marcu\Desktop\Folder of Death\n-body-sim\master\headers\particle.h"
#include "C:\Users\marcu\Desktop\Folder of Death\n-body-sim\master\headers\quadtree.h"

void collide(std::vector<Particle>& particles, Quadtree& root);
void collide(Particle& p, Quadtree& tn);
void collide(Particle& a, Particle& b, float dist);