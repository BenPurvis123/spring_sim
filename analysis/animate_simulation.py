import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation, PillowWriter

# Load simulation data
df = pd.read_csv("data/simulation_output.csv", comment="#")

# Anchor point
anchor_x = 0.0
anchor_y = 0.0

# Create figure
fig, ax = plt.subplots()
ax.set_title("Spring Simulation")
ax.set_xlabel("x")
ax.set_ylabel("y")
ax.grid(True)
ax.set_aspect("equal")

# Set plot limits
padding = 1.0
x_min = min(df["x"].min(), anchor_x) - padding
x_max = max(df["x"].max(), anchor_x) + padding
y_min = min(df["y"].min(), anchor_y) - padding
y_max = max(df["y"].max(), anchor_y) + padding
ax.set_xlim(x_min, x_max)
ax.set_ylim(y_min, y_max)

# Static anchor
ax.plot(anchor_x, anchor_y, marker="o", linestyle="None", label="Anchor")

# Animated objects
spring_line, = ax.plot([], [])
particle_dot, = ax.plot([], [], marker="o", linestyle="None", label="Particle")

ax.legend()

def init():
    spring_line.set_data([], [])
    particle_dot.set_data([], [])
    return spring_line, particle_dot

def update(frame):
    x = df["x"].iloc[frame]
    y = df["y"].iloc[frame]

    spring_line.set_data([anchor_x, x], [anchor_y, y])
    particle_dot.set_data([x], [y])

    return spring_line, particle_dot

frame_step = 5

anim = FuncAnimation(
    fig,
    update,
    frames=range(0, len(df), frame_step),
    init_func=init,
    blit=True,
    interval=20
)

print("saving gif...")
anim.save("spring_animation.gif", writer=PillowWriter(fps=20))
print("gif saved")

plt.show()