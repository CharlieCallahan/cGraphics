#version 330 core
layout (location = 0) in vec3 aPos; // the position variable has attribute position 0
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 aTextCoord;

uniform mat4 sceneTransform;
out vec4 vertexColor; // specify a color output to the fragment shader
out vec2 textCoord;
void main()
{
    gl_Position = sceneTransform*vec4(aPos, 1.0);
    vertexColor = vec4(1,1,1,1.0);
    textCoord = vec2(aTextCoord.x,-aTextCoord.y);//vec2(.25,.75);
}
