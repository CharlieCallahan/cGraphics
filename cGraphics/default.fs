#version 330 core
out vec4 fragColor;
in vec4 vertexColor;
in vec2 textCoord;
in float textIndex;
//in vec2 textCoord;
uniform sampler2D textures[2];

void main()
{
    int index = int(textIndex);
    fragColor = texture(textures[index], textCoord);
    //FragColor = vertexColor;//*texture(ourTexture, textCoord);
}
