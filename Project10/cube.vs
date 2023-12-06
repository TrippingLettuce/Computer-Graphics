#version 330 core
layout (location = 0) in vec3 aPos;       // Vertex position
layout (location = 1) in vec3 aNormal;    // Normal vector
layout (location = 2) in vec2 aTexCoords; // Texture coordinates

out vec3 Normal;      // For fragment shader
out vec3 FragPos;     // For fragment shader
out vec2 TexCoords;   // For fragment shader

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
    FragPos = vec3(model * vec4(aPos, 1.0)); // Transform vertex position
    Normal = mat3(transpose(inverse(model))) * aNormal; // Transform normals
    TexCoords = aTexCoords; // Pass texture coordinates

    gl_Position = projection * view * vec4(FragPos, 1.0); // Calculate final position
}
