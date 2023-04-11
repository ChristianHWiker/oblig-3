#version 410 core

layout(location = 0) in vec4 positionIn;
layout(location = 1) in vec4 colorIn;
layout(loaction = 2) in vec2 aTexCoord;

out vec4 color;
out vec2 TexCoord;
uniform mat4 mMatrix;
uniform mat4 vMatrix;
uniform mat4 pMatrix;

void main(){
    color = colorIn;
    TexCoord = aTexCoord;
    gl_Position = pMatrix * vMatrix * mMatrix * positionIn;
}
