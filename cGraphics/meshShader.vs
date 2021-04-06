#version 330 core
layout (location = 0) in vec3 aPos; // the position variable has attribute position 0
layout (location = 1) in vec3 aColor;
uniform mat4 projection;
uniform mat4 translation;
uniform mat4 rotation;
out vec4 vertexColor; // specify a color output to the fragment shader
void main()
{
    gl_Position = transpose(projection)*rotation*translation*vec4(aPos, 1.0);
    vertexColor = vec4(aColor, 1.0);
}
