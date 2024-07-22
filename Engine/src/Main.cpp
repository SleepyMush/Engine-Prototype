//Engine
#include "core/Windows.h"
#include "render/Render.h"
#include "render/Shader.h"
#include "render/Texture.h"
#include "render/Camera.h"

Window  window;
Render  render;
Texture texture;

int width = 1920;
int height = 1080;


int main()
{
	window.CreateWindow(width, height, "Surivior-Demo");
	Shader shader("res/shader/vertex.vert", "res/shader/fragment.frag");
	texture.loadtexture("res/texture/NumGrid_ALB (1).png");

	std::vector<Render::Vertex> vertices =
	{
		{glm::vec3(0.5f, 0.5f, 0.0f),    glm::vec2(1.0, 1.0)},
		{glm::vec3(0.5f, -0.5f, 0.0f),	 glm::vec2(1.0, 0.0)},
		{glm::vec3(-0.5f, -0.5f, 0.0f),  glm::vec2(0.0, 0.0)},
		{glm::vec3(-0.5f,  0.5f, 0.0f),  glm::vec2(0.0, 1.0)}
	};

	std::vector<uint16_t> indices = {
		0, 1, 3,
		1, 2, 3
	};

	Render::Mesh mesh = render.create_mesh(vertices, indices);
	Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));

	glEnable(GL_DEPTH_TEST);

	while (!glfwWindowShouldClose(window)) 
	{
		glfwSwapBuffers(window);
		glfwPollEvents();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.2, 0.4, 0.2, 1.0);

		window.processInput(window);

		shader.use();
		camera.CameraMatrix(width, height, 45.0f, 0.1f, 100.0f, shader,"Matrix");

		texture.bind(0);
		glBindVertexArray(mesh.vao);
		glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(indices.size()), GL_UNSIGNED_SHORT, nullptr);
	}
	texture.cleanUp();
	return 0;
}

void Window::processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}