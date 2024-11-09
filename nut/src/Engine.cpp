#include "Engine.h"
#include <iostream>
#include "../external/glm/glm/ext/matrix_clip_space.hpp"
#include "../external/glm/glm/ext/matrix_float4x4.hpp"
#include "../external/glm/glm/ext/matrix_transform.hpp"
#include "../external/glm/glm/gtc/type_ptr.hpp"
#include "../external/glad/include/glad/glad.h"

Engine::Engine() : model(nullptr), renderer(nullptr), shader(nullptr), window(nullptr) {
    init();
    renderer = new Renderer();
    shader = new Shader("src/shaders/vertex_shader.glsl", "src/shaders/fragment_shader.glsl");
}

Engine::~Engine() {
    if (renderer) delete renderer;
    if (shader) delete shader;
    if (model) delete model;
}

void Engine::init() {
    if (!glfwInit()) {
        std::cerr << "[NUT DEBUG SERVICE] Failed to initialize GLFW" << std::endl;
        exit(EXIT_FAILURE);
    }

    window = glfwCreateWindow(800, 600, "OpenGL Engine", nullptr, nullptr);
    if (!window) {
        std::cerr << "[NUT DEBUG SERVICE] Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);

    // Load OpenGL functions using GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "[NUT DEBUG SERVICE] Failed to initialize GLAD" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Engine::render(const std::string& modelPath) {
    if (!model) {
        model = new Model(modelPath);
        model->loadModel(modelPath);
    }

    glEnable(GL_DEPTH_TEST);
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glm::mat4 modfl = glm::mat4(1.0f);
        glm::mat4 view = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

        shader->use();
        shader->setMat4("model", glm::value_ptr(modfl));
        shader->setMat4("view", glm::value_ptr(view));
        shader->setMat4("projection", glm::value_ptr(projection));

        model->draw(*shader);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}
