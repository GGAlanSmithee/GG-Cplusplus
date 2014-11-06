#version 330

layout (location = 0) in vec3 Position;

out vec4 Color;

void main()
{
    gl_Position = vec4(0.5 * Position.x, 0.5 * Position.y, Position.z, 1.0);
}
