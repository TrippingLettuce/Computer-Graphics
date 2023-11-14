#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <cmath>

// Vertex shader
const char* vertexShaderSource = R"glsl(
#version 330 core
layout (location = 0) in vec3 position;
void main() {
    gl_Position = vec4(position, 1.0);
}
)glsl";

// Fragment shader
const char* fragmentShaderSource = R"glsl(
#version 330 core
out vec4 FragColor;
void main() {
    FragColor = vec4(0.0f, 1.0f, 0.0f, 1.0f); // Green color
}
)glsl";

// Function to generate sphere vertices
void generateSphereVertices(std::vector<float>& vertices, int stacks, int slices, float radius) {
    for (int i = 0; i <= stacks; ++i) {
        float lat0 = M_PI * (-0.5 + float(i - 1) / stacks);
        float z0  = sin(lat0);
        float zr0 = cos(lat0);

        float lat1 = M_PI * (-0.5 + float(i) / stacks);
        float z1 = sin(lat1);
        float zr1 = cos(lat1);

        for (int j = 0; j <= slices; ++j) {
            float lng = 2 * M_PI * float(j - 1) / slices;
            float x = cos(lng);
            float y = sin(lng);

            // vertices for the first triangle
            vertices.push_back(x * zr0 * radius);
            vertices.push_back(y * zr0 * radius);
            vertices.push_back(z0 * radius);
            vertices.push_back(x * zr1 * radius);
            vertices.push_back(y * zr1 * radius);
            vertices.push_back(z1 * radius);

            // vertices for the second triangle
            vertices.push_back(x * zr1 * radius);
            vertices.push_back(y * zr1 * radius);
            vertices.push_back(z1 * radius);
            vertices.push_back(x * zr0 * radius);
            vertices.push_back(y * zr0 * radius);
            vertices.push_back(z0 * radius);
        }
    }
}

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Create window
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Sphere", nullptr, nullptr);
    if (window == nullptr) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    // Define the viewport dimensions
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    // Shader program
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // Generate sphere vertices
    std::vector<float> vertices;
    generateSphereVertices(vertices, 50, 50, 1.0f); // 50 stacks and 50 slices

    // Setup sphere VAO and VBO
    GLuint VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Check and call events
        glfwPollEvents();

        // Render
        // Clear the color buffer
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw the sphere
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, vertices.size() / 3);

        // Swap the screen buffers
        glfwSwapBuffers(window);
    }

    // Deallocate all resources
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    // Terminate GLFW, clearing any resources allocated by GLFW.
    glfwTerminate();

    return 0;
}
