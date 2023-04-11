#version 410 core

layout(location = 0) in vec4 positionIn;    // 1st attribute buffer = vertex positions
layout(location = 1) in vec4 colorIn;       // 2nd attribute buffer = colors
out vec4 color;                             //color sent to rest of pipeline

uniform mat4 pmatrix;
uniform mat4 vmatrix;
uniform mat4 matrix;                        //the matrix for the model

void main() {
   color = colorIn;                         //passing on the vertex color //&gl_Position = matrix * positionIn;       //calculate the position of the model

   gl_Position = pmatrix * vmatrix * matrix * positionIn;
}

//layout (location = 0) in vec3 pos; // 3D object
//layout (location = 1) in vec2 tex; // 2D texture
//out vec4 vCol; // color out
//out vec2 texCoord; // texture coordinates out
//uniform mat4 model;
//uniform mat4 projection;
//uniform mat4 view;

//void main()
//{
//gl_Position = projection * view * model * vec4(pos, 1.0);
//vCol = vec4(clamp(pos, 0.0f, 1.0f), 1.0f);
//texCoord = tex; //
//}
