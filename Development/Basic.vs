#version 330

layout (location = 0) in vec3 Position;

uniform mat4 MVP;

out vec4 Color;

void main()
{
    gl_Position = MVP * vec4(Position, 1);
    Color = vec4(clamp(Position, 0.0, 1.0), 1.0);
}
