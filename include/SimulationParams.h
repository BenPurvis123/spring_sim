#pragma once
#include "Vec2.h"

struct SimulationParams {
    Vec2 initial_pos;
    Vec2 initial_vel;
    Vec2 anchor;
    double mass;

    double k;   // spring constant
    double c;   // damping constant
    double dt;  // timestep
    int steps;  // number of iterations
};