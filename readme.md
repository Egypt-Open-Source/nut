
# Nut Graphics Engine

## Description

The Nut Engine is a lightweight and modular graphics engine designed to facilitate the development of 3D applications using OpenGL. It abstracts the complexity of OpenGL setup and rendering, providing a simple interface for loading models, shaders, and rendering scenes. The engine is built with C++ and utilizes GLFW for window management and GLM for mathematics.

## Features

- **Model Loading**: Supports loading and rendering 3D models.
- **Shader Management**: Allows for easy integration and management of vertex and fragment shaders.
- **Camera Control**: Implements basic camera movements and view transformations.
- **OpenGL Integration**: Simplifies OpenGL initialization and rendering processes.
- **Extensible Architecture**: Easily add new features and extend functionality.

## Project Structure

```
nut/
├── build/                   # Directory for build files
├── external/                # External libraries
│   ├── glfw/                # GLFW library
│   └── glad/                # GLAD library
|   |__ etc..                # the rest of the dep.
├── src/                     # Source files
│   ├── Shader.cpp           # Shader class implementation
│   ├── Model.cpp            # Model class implementation
│   ├── Renderer.cpp         # Renderer class implementation
│   └── Engine.cpp           # Main engine implementation
├── shaders/                 # Shader files
│   ├── vertex_shader.glsl   # Vertex shader source
│   └── fragment_shader.glsl # Fragment shader source
├── Makefile                 # CMake build configuration

main.cpp                 # Entry point for the application
```

## Requirements

- C++17
- CMake (version 3.10 or higher)
- GLFW (included in external folder)
- GLAD (included in external folder)
- OpenGL 

## Building the Project

To build the project, follow these steps:

1. **Clone the repository** or download the project files.
2. Open a terminal and navigate to the project directory.
3. Create a build directory:
   ```bash
   mkdir build
   ```
4. Compile the project:
   ```bash
   make
   ```
5. Run the application:
   ```bash
   build/app
   ```

## Usage

To use the engine, create an instance of the `Engine` class and call the `render` method with the path to the model you want to load. For example:

```cpp
Engine engine;
engine.render("path/to/your/model.obj");
```

## Contributing

Contributions are welcome! If you have suggestions or improvements, please feel free to open an issue or submit a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more information.


