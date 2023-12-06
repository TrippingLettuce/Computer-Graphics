#version 330 core
out vec4 FragColor;

in vec3 Normal; 
in vec3 FragPos;
in vec2 TexCoords_Frag;

uniform vec3 lightPos; 
uniform vec3 viewPos; 
uniform vec3 lightColor; 
uniform vec3 cylinderColor = vec3(1.0, 1.0, 1.0); // Set to white to see original texture color
uniform sampler2D textureSampler;

void main()
{
    // Ambient lighting
    float ambientStrength = 0.8;
    vec3 ambient = ambientStrength * lightColor;

    // Diffuse lighting
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    // Specular lighting
    float specularStrength = 0.25;
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 8);
    vec3 specular = specularStrength * spec * lightColor;

    // Combine results
    vec3 result = (ambient + diffuse + specular) * cylinderColor;
    vec4 texColor = texture(textureSampler, TexCoords_Frag);
    FragColor = texColor;

}
