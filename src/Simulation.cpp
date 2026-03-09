#include "Simulation.h"
#include "SimulationParams.h"

#include <fstream>
#include <iomanip>

#include "Vec2.h"
#include "Particle.h"
#include "SpringForce.h"

void run_simulation(const SimulationParams& params, std::ostream& out) {
    out << "time,x,y,vx,vy,ax,ay,K,P,E\n\n";
    
    Particle p(params.initial_pos, params.initial_vel, params.anchor, params.mass);

    for(int i = 1; i <= params.steps; i++) {
        Vec2 d = p.displacement(); 

        Vec2 force = compute_spring_force(d, p.vel, params.k, params.c);
        Vec2 acceleration = force / p.mass;

        p.vel += acceleration * params.dt;
        p.pos += p.vel * params.dt;

        double K = 0.5 * p.mass * length_sq(p.vel);
        double P = 0.5 * params.k * length_sq(d); // position - anchor = displacement
        double E = K + P;

        double t = i * params.dt;

        out << t << ","
                  << p.pos.x << "," << p.pos.y << ","
                  << p.vel.x << "," << p.vel.y << ","
                  << acceleration.x << "," << acceleration.y << ","
                  << K << "," << P << "," << E << "\n";
    };
};
