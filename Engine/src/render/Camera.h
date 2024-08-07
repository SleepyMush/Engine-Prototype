#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.h"

class Camera
{
public:
	glm::vec3 Position;
	glm::vec3 WorldUp;
	glm::vec3 Front = glm::vec3(0.0f, 0.0f, -1.0f);
	float Yaw;
	float Pitch;

	Camera(
		glm::vec3 position = glm::vec3(0.0f ,0.0f, 0.0f),
		glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f),
		glm::vec3 front = glm::vec3(0.0f,0.0f,-1.0f),
		float yaw = -90.0f,
		float pitch = 0.0f);

	void CameraMatrix(int width, int height, float fov, float near, float far, Shader& shader, const char* uniform);
};
