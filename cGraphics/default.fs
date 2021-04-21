#version 330 core
#define MESHES_PER_BATCH 16 // max number of textures

out vec4 fragColor;
in vec4 vertexColor;
in vec2 textCoord;
in float textIndex;

uniform sampler2D textures[MESHES_PER_BATCH];

void main()
{
    int index = int(textIndex);
    fragColor = texture(textures[index], textCoord);
    //FragColor = vertexColor;//*texture(ourTexture, textCoord);
}
