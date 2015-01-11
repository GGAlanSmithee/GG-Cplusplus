#version 330

layout (location = 0) in vec3 Position;
layout (location = 1) in vec2 TexCoord;

uniform mat4 MVP;

out vec2 TexCoord0;

void main()
{
    gl_Position = MVP * vec4(Position, 1);
    TexCoord0 = TexCoord;
}
