import pandas as pd
import matplotlib.pyplot as plt
print("**Plot started**")
df = pd.read_csv("simulation_output.csv", comment="#")

# Position
plt.figure()
plt.plot(df["time"], df["x"], label="x")
plt.plot(df["time"], df["y"], label="y")
plt.xlabel("Time")
plt.ylabel("Position")
plt.title("Position vs Time")
plt.legend()
plt.grid(True)

# Velocity
plt.figure()
plt.plot(df["time"], df["vx"], label="vx")
plt.plot(df["time"], df["vy"], label="vy")
plt.xlabel("Time")
plt.ylabel("Velocity")
plt.title("Velocity vs Time")
plt.legend()
plt.grid(True)

# Energy components
plt.figure()
plt.plot(df["time"], df["K"], label="Kinetic")
plt.plot(df["time"], df["P"], label="Potential")
plt.plot(df["time"], df["E"], label="Total")
plt.xlabel("Time")
plt.ylabel("Energy")
plt.title("Energy vs Time")
plt.legend()
plt.grid(True)

# Energy Drift
plt.figure()
plt.plot(df["time"], df["E"] - df["E"].iloc[0])
plt.xlabel("Time")
plt.ylabel("Energy Drift")
plt.title("Energy Drift vs Time")
plt.grid(True)
plt.savefig("energy_drift.png")

print("**Plot Finished**")
plt.show()

print("done")