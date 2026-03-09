#pragma once
#include "Vec2.h"

class Particle {
    public: 
        Vec2 pos;  
        Vec2 vel;
        Vec2 anchor;
        const double mass;

        Particle(const Vec2& p, const Vec2& v, const Vec2& anch, double m) : pos(p), vel(v), anchor(anch), mass(m) {}
        
        Vec2 displacement() const {
            return pos - anchor;
        };
};