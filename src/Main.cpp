#include <fstream>
#include <iostream>
#include <iomanip>

#include "SimulationParams.h"
#include "Simulation.h"

int main(){
    
    SimulationParams params;
    
    params.initial_pos = {5.0, 5.0};
    params.initial_vel = {0.0, 0.0};
    params.anchor = {0.0, 0.0};
    params.mass = 1.0;
    params.k = 5;
    params.c = 0.2; // spring constant, small but visibible effect at 0.2
    params.dt = 0.0025;
    params.steps = 1000;

    std::ofstream file("simulation_output.csv");

    if (!file) { 
        std::cerr << "Error: could not open simulation_output.csv\n";
        return 1;
    }

    file << std::fixed << std::setprecision(3);

    file << "# ==== Simulation ====\n\n";
    file << "# Parameters:\n";
    file << "# Anchor Point: " << params.anchor << "\n";
    file << "# Initial Position: " << params.initial_pos << "\n";
    file << "# Initial Velocity: " << params.initial_vel << "\n";
    file << "# Particle Mass: " << params.mass << "\n";
    file << "# Spring Stiffness: " << params.k << "\n";
    file << "# Damping Ratio: " << params.c << "\n";
    file << "# Timestep: " << params.dt << "\n";
    file << "# Number of Iterations: " << params.steps << "\n\n";

    run_simulation(params, file);

    std::cout << "Simulation Complete. Output written to simulation_output.csv\n";
    return 0;
}