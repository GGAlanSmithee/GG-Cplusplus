#version 330

precision highp float;

in vec2 TexCoord0;

uniform sampler2D TextureSampler;

out vec4 FragColor;

void main()
{
    FragColor = texture2D(TextureSampler, TexCoord0.xy);
}
