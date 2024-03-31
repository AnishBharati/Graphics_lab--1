#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void drawLine(int x0, int y0, int x1, int y1)
{
    // BLA implementation
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (true)
    {
        glVertex2i(x0, y0);

        if (x0 == x1 && y0 == y1)
            break;
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
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

    glOrtho(0, 800, 0, 600, -1, 1); // Set the coordinate system

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glPointSize(2.0f); // Set point size
        glBegin(GL_POINTS);
        glColor3f(0.0f, 0.0f, 0.0f); // Black color for the lines

        int shiftLeft = 100; // Amount to shift left

        // Adjusted x-coordinate for the vertical line
        drawLine(400 - shiftLeft, 100, 400 - shiftLeft, 500);

        // Calculate midpoint of the adjusted line
        float middleX = 400.0f - shiftLeft;
        float middleY = (100.0f + 500.0f) / 2.0f;

        // Angle calculations remain the same
        float angle = 45.0f * M_PI / 180.0f;
        float diagonallength = (500.0f - 100.0f) / 4.0f;

        // Adjust x-coordinates for the diagonal lines
        float lineendx = middleX + 3 * diagonallength * cos(angle);
        float lineendy = middleY + 2.5 * diagonallength * sin(angle);

        float neglineendx = middleX + 3 * diagonallength * cos(-angle);
        float neglineendy = middleY + 2.5 * diagonallength * sin(-angle);

        // Draw adjusted lines
        drawLine(middleX, middleY, lineendx, lineendy);
        drawLine(middleX, middleY, neglineendx, neglineendy);

        float lineEndX = neglineendx + 3 * diagonallength * cos(angle);
        float lineEndY = neglineendy + 2.5 * diagonallength * sin(angle);

        drawLine(neglineendx, neglineendy, lineEndX, lineEndY);

        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}