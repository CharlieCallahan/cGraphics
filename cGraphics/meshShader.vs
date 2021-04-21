#version 330 core
#define MESHES_PER_BATCH 16 
layout (location = 0) in vec3 aPos; // the position variable has attribute position 0
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 aTextCoord;
layout (location = 3) in float modelIndex;

uniform mat4 sceneTransform; //camera transform
uniform mat4 modelTransforms [MESHES_PER_BATCH];

out vec4 vertexColor; // specify a color output to the fragment shader
out vec2 textCoord;
out float textIndex;

void main()
{
    int index = int(modelIndex);
    gl_Position = sceneTransform*modelTransforms[index]*vec4(aPos, 1.0);
    vertexColor = vec4(1,1,1,1.0);//vec4(1,1,1,1.0);
    textIndex = modelIndex;
    textCoord = vec2(aTextCoord.x,-aTextCoord.y);
}
