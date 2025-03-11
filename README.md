# N-Body Simulation in C++ using OpenGL, Eigen, and Barnes-Hut Algorithm

## Overview
This project implements an **N-Body Simulation** in C++ using **OpenGL** for visualization, **Eigen** for matrix operations, and the **Barnes-Hut algorithm** to optimize gravitational calculations. The Barnes-Hut approach reduces the time complexity from **O(N²)** to **O(N log N)**, making it suitable for large simulations.

## Features
- **Barnes-Hut Algorithm** for efficient force calculations
- **OpenGL Visualization** for real-time rendering
- **Eigen Library** for fast linear algebra operations
- **Multithreading** (optional) using OpenMP for improved performance
- **Adjustable simulation parameters** such as timestep, softening factor, and number of bodies

## Requirements
### Dependencies
Ensure you have the following libraries installed before building:
- **C++17 or later**
- **OpenGL** (for visualization)
- **GLFW** (window management)
- **GLEW** (OpenGL extension loading)
- **Eigen3** (for linear algebra operations)
- **OpenMP** (optional, for parallelization)

### Installing Dependencies (Linux)
```sh
sudo apt update && sudo apt install -y libglfw3-dev libglew-dev libeigen3-dev
```

### Installing Dependencies (MacOS)
```sh
brew install glfw glew eigen
```

## Building the Project
### Clone the Repository
```sh
git clone https://github.com/yourusername/nbody-sim.git
cd nbody-sim
```

### Compile with CMake
```sh
mkdir build && cd build
cmake ..
make
```

### Run the Simulation
```sh
./nbody_sim
```

## Code Structure
```
📂 nbody-sim
├── 📂 src          # Source code files
│   ├── main.cpp   # Entry point of the simulation
│   ├── body.cpp   # Body struct and physics calculations
│   ├── barnes_hut.cpp # Barnes-Hut implementation
│   ├── opengl_renderer.cpp # OpenGL visualization
│   ├── utils.cpp  # Helper functions
│
├── 📂 include      # Header files
├── 📂 shaders      # OpenGL shaders
├── 📂 assets       # Textures, icons, or external files
├── CMakeLists.txt  # CMake build script
└── README.md       # Project documentation
```

## Simulation Parameters
You can modify the **config.json** file (or change values in `main.cpp`) to adjust the simulation:
```json
{
    "num_bodies": 1000,
    "time_step": 0.001,
    "softening": 0.1,
    "theta": 0.5
}
```
- `num_bodies`: Number of bodies in the simulation
- `time_step`: Time step for integration
- `softening`: Softening factor to prevent singularities
- `theta`: Threshold parameter for Barnes-Hut approximation

## Key Implementations
### Barnes-Hut Algorithm
- Uses a **quadtree (2D)** or **octree (3D)** to divide space into regions
- Approximates distant bodies as a single mass to reduce computational complexity
- Provides an optimal balance between accuracy and performance

### Integration Methods
- **Verlet Integration** (default) for stable motion
- **Runge-Kutta (RK4)** (optional) for higher accuracy

## Visualization
The simulation uses **OpenGL** to render particles in real-time.
- **Zoom & Pan:** Use the mouse scroll to zoom in/out and click-drag to pan.
- **Pause/Resume:** Press `Space`.
- **Adjust Speed:** Increase/decrease timestep dynamically.

## Performance Optimization
- **Multithreading (OpenMP)**: Parallelize force calculations
- **Barnes-Hut Quadtree**: Reduce time complexity from `O(N²) → O(N log N)`
- **Eigen Library**: Optimized linear algebra for physics calculations

## TODO
- [ ] Implement GPU acceleration using CUDA/OpenCL
- [ ] Add user interaction features (toggle Barnes-Hut, change parameters live)
- [ ] Improve OpenGL rendering (shading, trails, better UI)

## License
This project is licensed under the **MIT License**.

## Acknowledgments
- **Barnes & Hut (1986)** for their hierarchical N-body simulation algorithm.
- **Eigen** for providing a fast and user-friendly C++ linear algebra library.
- **OpenGL & GLFW** for graphics rendering.

---
Happy coding! 🚀
