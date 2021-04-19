#version 330 core
layout (location = 0) in vec3 aPos; // the position variable has attribute position 0
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 aTextCoord;
layout (location = 3) in float aTextIndex;

uniform mat4 sceneTransform; //camera transform
//uniform mat4 posTransform; //position of mesh
out vec4 vertexColor; // specify a color output to the fragment shader
out vec2 textCoord;
out float textIndex;

void main()
{
    gl_Position = sceneTransform*vec4(aPos, 1.0);
    vertexColor = vec4(1,1,1,1.0);//vec4(1,1,1,1.0);
    textIndex = aTextIndex;
    textCoord = vec2(aTextCoord.x,-aTextCoord.y);
}
