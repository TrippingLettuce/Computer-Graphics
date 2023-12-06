#version 330 core
out vec4 FragColor;

in vec3 Normal;      // Received from vertex shader
in vec3 FragPos;     // Received from vertex shader
in vec2 TexCoords;   // Received from vertex shader

uniform vec3 lightPos;
uniform vec3 viewPos;
uniform vec3 lightColor;
uniform sampler2D ourTexture; // Texture sampler

void main() {
    // Ambient lighting
    float ambientStrength = 0.8;
    vec3 ambient = ambientStrength * lightColor;

    // Diffuse lighting
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    // Specular lighting
    float specularStrength = 0.25f;
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * lightColor;

    // Texture color
    vec3 textureColor = texture(ourTexture, TexCoords).rgb;

    // Combine results
    vec3 result = (ambient + diffuse + specular) * textureColor;
    FragColor = vec4(result, 1.0f);
}
