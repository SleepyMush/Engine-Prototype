#include "Render.h"

Render::Mesh Render::create_mesh(std::vector<Vertex> const& vertices, std::vector<uint16_t> const& indices)
{
    Mesh mesh;

    // Generate VAO, VBO, and EBO
    glGenVertexArrays(1, &mesh.vao);
    glGenBuffers(1, &mesh.vbo);
    glGenBuffers(1, &mesh.ebo);

    // Bind VAO
    glBindVertexArray(mesh.vao);

    // Setup VBO
    glBindBuffer(GL_ARRAY_BUFFER, mesh.vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texture));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    // Setup EBO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh.ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(uint16_t), indices.data(), GL_STATIC_DRAW);

    // Unbind VAO
    glBindVertexArray(0);

	return mesh;
}