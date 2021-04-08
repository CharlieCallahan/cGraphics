#version 330 core
out vec4 FragColor;
in vec4 vertexColor;
in vec2 textCoord;
uniform sampler2D ourTexture;

void main()
{
FragColor = vertexColor;
    FragColor = texture(ourTexture, textCoord);
}
