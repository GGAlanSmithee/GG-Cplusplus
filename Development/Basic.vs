#version 330

layout (location = 0) in vec3 Position;

uniform float Scale;
uniform mat4 World;

out vec4 Color;

void main()
{
    gl_Position = World * vec4(Scale * Position.x, Scale * Position.y, Position.z, 1.0);
    Color = vec4(clamp(Position, 0.0, 1.0), 1.0);
}
