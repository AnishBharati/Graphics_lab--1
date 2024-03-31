#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void drawShapes()
{
    float verticalLineStartX = -0.8f;
    float verticalLineStartY = -0.8f;
    float verticalLineEndX = -0.8f;
    float verticalLineEndY = 0.8f;

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f); // Black color for the line
    glVertex2f(verticalLineStartX, verticalLineStartY);
    glVertex2f(verticalLineEndX, verticalLineEndY);
    glEnd();

    float middleX = (verticalLineStartX + verticalLineEndX) / 2.0f;
    float middleY = (verticalLineStartY + verticalLineEndY) / 2.0f;

    float verticalLineLength = std::abs(verticalLineEndY - verticalLineStartY);
    float diagonalLineLength = verticalLineLength / 2.0f;

    float angle = 45.0f * M_PI / 180.0f;
    float negAngle = -45.0f * M_PI / 180.0f;

    float diagonalLineEndX = middleX + 1.2f * diagonalLineLength * cos(angle);
    float diagonalLineEndY = middleY + 1.2f * diagonalLineLength * sin(angle);

    float negDiagonalLineEndX = middleX + 1.2f * diagonalLineLength * cos(negAngle);
    float negDiagonalLineEndY = middleY + 1.2f * diagonalLineLength * sin(negAngle);

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f); // Black color for the lines
    glVertex2f(middleX, middleY);
    glVertex2f(diagonalLineEndX, diagonalLineEndY);

    glVertex2f(middleX, middleY);
    glVertex2f(negDiagonalLineEndX, negDiagonalLineEndY);

    float newLineEndX = negDiagonalLineEndX + 1.2f * diagonalLineLength * cos(angle);
    float newLineEndY = negDiagonalLineEndY + 1.2f * diagonalLineLength * sin(angle);

    glVertex2f(negDiagonalLineEndX, negDiagonalLineEndY);
    glVertex2f(newLineEndX, newLineEndY);

    glEnd();
}

int main()
{
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    GLFWwindow *window = glfwCreateWindow(800, 600, "KU Logo", NULL, NULL);
    if (!window)
    {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Failed to initialize GLAD\n";
        return -1;
    }

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        drawShapes();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
