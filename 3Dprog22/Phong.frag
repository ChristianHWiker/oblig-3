#version 330 core
out vec4 FragColor;

in vec3 = normalTransposed;
in vec3 = fragmentPosition;


uniform float ambientStrength = 0.1;
uniform float lightStrength = 0.7;
uniform vec3 objectColor = vec3(0.7, 0.7, 0.7);
uniform vec3 lightColor = vec3(0.8, 0.8, 0.3);
uniform vec3 lightPosition;

void main()
{
    vec3 ambient = ambientStrength * lightColor;

    vec3 normalCorrected = normalize(normalTransposed);
    vec3 lightDirection = normalize(lightPosition - fragmentPosition);
    float angleFactor = max(dot(normalCorrected, lightDirection), 0.0);
    vec3 diffuse = angleFactor * objectColor * lightColor * lightStrength;

    vec3 result = ambient + diffuse;
    fragColor = vec4(result, 1.0);
}
