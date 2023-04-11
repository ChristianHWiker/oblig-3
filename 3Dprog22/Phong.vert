#version 330 core
layout (location = 0) in vec3 vertexPosition;
layout (location = 1) in vec3 vertexNormal;
layout (location = 2 ) in vec2 vertexUV;

out vec3 fragmentPosition;
out vec3 normalTransposed;

uniform mat4 mMatrix;
uniform mat4 vMatrix;
uniform mat4 pMatrix;

void main()
{
    fragmentPosition = vec3(mMatrix * vec4(vertexPosition, 1.0));
    normalTransposed = vertexNormal;

    gl_Position = pMatrix * vMatrix * mMatrix * vec4(vertexPosition, 1.0);
}
