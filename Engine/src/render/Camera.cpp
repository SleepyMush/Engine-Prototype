#include "Camera.h"

Camera::Camera(glm::vec3 position, glm::vec3 Up, glm::vec3 front, float yaw, float pitch)
{
	Position = position;
	WorldUp = Up;
	Yaw = yaw;
	Pitch = pitch;
	Front = front;
}

void Camera::CameraMatrix(int width, int height, float fov, float near, float far, Shader& shader, const char* uniform) 
{
	glm::mat4 projection = glm::mat4(1.0f);
	glm::mat4 view = glm::mat4(1.0f);

	view = glm::lookAt(Position, Position + Front, WorldUp);
	projection = glm::perspective(glm::radians(fov), (float)width / height, near, far);

	glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(projection * view));
}
