#pragma once
#include "Vec2.h"

Vec2 compute_spring_force(const Vec2& displacement, const Vec2& velocity, double k, double c) {
    Vec2 restoring_force = -k * displacement;
    Vec2 damping_force = c * velocity;
    Vec2 spring_force = restoring_force - damping_force;
    return spring_force;
};
