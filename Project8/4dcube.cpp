#include <GL/glew.h>  // This should be the first OpenGL-related include
#include <GLFW/glfw3.h>
#include <GL/glut.h>  // If you're using GLUT
#include <GL/glu.h>   // Include GLU header
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <iostream>


struct P4Vector {
    float x, y, z, w;

    P4Vector(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
};

enum RotationMode {
    MODE_1, MODE_2, MODE_3, MODE_4, MODE_5, MODE_6, MODE_7
};
RotationMode currentMode = MODE_1;


std::vector<P4Vector> tesseractVertices;
std::vector<std::pair<int, int>> edges;
bool partyMode = false;
glm::vec3 lineColor = glm::vec3(1.0f, 1.0f, 1.0f); // Initially white
glm::vec4 backgroundColor = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f); // Initially black


void createTesseract() {
    // Define the vertices of a tesseract
    for (int i = 0; i < 16; ++i) {
        tesseractVertices.push_back({
            (i & 1) ? -1.0f : 1.0f,
            (i & 2) ? -1.0f : 1.0f,
            (i & 4) ? -1.0f : 1.0f,
            (i & 8) ? -1.0f : 1.0f
        });
    }

    // Define the edges
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            int diff = i ^ j;
            if (diff == 1 || diff == 2 || diff == 4 || diff == 8) {
                edges.push_back({i, j});
            }
        }
    }
}

P4Vector rotate4D(const P4Vector& v, float angle, int plane1, int plane2) {
    glm::mat4 rot = glm::mat4(1.0f);
    rot[plane1][plane1] = rot[plane2][plane2] = cos(angle);
    rot[plane1][plane2] = -sin(angle);
    rot[plane2][plane1] = sin(angle);

    glm::vec4 result = rot * glm::vec4(v.x, v.y, v.z, v.w);
    return P4Vector(result.x, result.y, result.z, result.w);
}

glm::vec3 projectTo3D(const P4Vector& v) {
    // Simple orthographic projection from 4D to 3D
    return glm::vec3(v.x, v.y, v.z);
}

void applyRotations(P4Vector& v, float angle) {
    switch (currentMode) {
        case MODE_1:
            v = rotate4D(v, angle, 3, 2);
            v = rotate4D(v, angle, 0, 3);
            break;
        case MODE_2:
            v = rotate4D(v, angle, 2, 1);
            v = rotate4D(v, angle, 2, 3);
            break;
        case MODE_3:
            v = rotate4D(v, angle, 3, 0);
            v = rotate4D(v, angle, 2, 3);
            break;
        case MODE_4:
            v = rotate4D(v, angle, 3, 1);
            v = rotate4D(v, angle, 2, 0);
            break;
        case MODE_5:
            v = rotate4D(v, angle, 3, 1);
            v = rotate4D(v, angle, 1, 1);
            break;
        case MODE_6:
            v = rotate4D(v, angle, 0, 3);
            v = rotate4D(v, angle, 2, 3);
            break;

        default:
            break;
    }
}

void renderHypercube() {
    if (partyMode) {
        // Change to a random color
        lineColor = glm::vec3(static_cast<float>(rand()) / RAND_MAX,
                            static_cast<float>(rand()) / RAND_MAX,
                            static_cast<float>(rand()) / RAND_MAX);
    }
    glColor3f(lineColor.r, lineColor.g, lineColor.b);
    static float angle = 0.0f;
    angle += 0.0025f;
    

    // Rotate and project vertices
    std::vector<glm::vec3> projectedVertices;
    for (const auto& v : tesseractVertices) {
        P4Vector rotated = v;
        applyRotations(rotated, angle);
        projectedVertices.push_back(projectTo3D(rotated));
    }
    // Draw edges
    glBegin(GL_LINES);
    for (const auto& edge : edges) {
        const auto& p1 = projectedVertices[edge.first];
        const auto& p2 = projectedVertices[edge.second];
        glVertex3f(p1.x, p1.y, p1.z);
        glVertex3f(p2.x, p2.y, p2.z);
    }
    glEnd();
}



int main() {
    // Initialize GLFW
    srand(static_cast<unsigned int>(time(nullptr)));
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(800, 600, "4D Hypercube", NULL, NULL);
    if (!window) {
        glfwTerminate();
        std::cerr << "Failed to create GLFW window" << std::endl;
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Set up viewport, projection, etc.
    glViewport(0, 0, 800, 600);
    // ... Additional OpenGL setup ...

    // Loop until the user closes the window
    createTesseract();

    while (!glfwWindowShouldClose(window)) {
        // Render here
            // Set the background color
        glClearColor(backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
            // Clear the color buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
            currentMode = static_cast<RotationMode>((currentMode + 1) % 7);  // Cycle through modes
        }
        if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS) {
        // Change background color, for example to a random color
        backgroundColor.r = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        backgroundColor.g = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        backgroundColor.b = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        }
        if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS) {
            // Change color, for example to a random color
            lineColor = glm::vec3(static_cast<float>(rand()) / RAND_MAX,
                                static_cast<float>(rand()) / RAND_MAX,
                                static_cast<float>(rand()) / RAND_MAX);
        }
        if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS) {
            partyMode = !partyMode;  // Toggle party mode
        }

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45.0, 800.0 / 600.0, 0.1, 100.0);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(8, 6, 10, 0, 0, 0, 0, 1, 0);

        // Render the 4D Hypercube
        renderHypercube();

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    // Cleanup
    glfwTerminate();
    return 0;
}