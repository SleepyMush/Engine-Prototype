#version 460 core
layout (location = 0)in vec3 position;
layout (location = 1)in vec2 texturecoordinates;

out vec2 TexCoord;

uniform mat4 Matrix;

void main()
{
	gl_Position = Matrix * vec4(position.x, position.y, position.z, 1.0);
	TexCoord = texturecoordinates;
}
