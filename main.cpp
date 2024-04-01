#include <GL/glut.h>
#include <cmath>

// function to create lines
void drawLines()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    glColor3f(1.0, 1.0, 1.0); // make the line color white
    glBegin(GL_LINES);        // start the line

    // vertical line
    glVertex2f(-0.25, -0.5); // starting point
    glVertex2f(-0.25, 0.5);  // end point

    glVertex2f(-0.3, -0.5);
    glVertex2f(-0.3, 0.5);

    glVertex2f(-0.25, -0.5);
    glVertex2f(-0.3, -0.5);

    glVertex2f(-0.25, 0.5);
    glVertex2f(-0.3, 0.5);

    // for U rotating in 60 degree
    float angle = 60.0 * 3.14159 / 180.0; // degree into radian
    float dx = cos(angle) * 0.5;          // new x
    float dy = sin(angle) * 0.5;          // new y

    // drawing the line for U in top
    glVertex2f(-0.25, 0.0);
    glVertex2f(dx, dy);

    // double lining for the U in top
    glVertex2f(-0.25, 0.05);
    glVertex2f(dx, dy + 0.05);

    // joining both double line in top
    glVertex2f(dx, dy);
    glVertex2f(dx, dy + 0.05);

    // for U rotating in negative 60 degree
    float negangle = -60.0 * 3.14159 / 180.0;
    float negdx = cos(negangle) * 0.5;
    float negdy = sin(negangle) * 0.5;

    // drawing line for U in the bottom
    glVertex2f(-0.25, 0.0);
    glVertex2f(negdx, negdy);

    // double lining for the U in the bottom
    glVertex2f(-0.25, -0.05);
    glVertex2f(negdx, negdy - 0.05);

    // another angle for drawing line starting from the end point of the U in the bottom for making U
    float x = cos(angle) * 1.414;
    float y = sin(angle) * 1.414;

    // another line starting from the end of the bottom U
    glVertex2f(negdx, negdy);
    glVertex2f(3 * dx, 0);

    // double lining of that end of the bottom U
    glVertex2f(negdx, negdy - 0.05);
    glVertex2f(3 * dx, -0.05);

    // joining the lines of the end points of the above line
    glVertex2f(3 * dx, 0);
    glVertex2f(3 * dx, -0.05);

    glEnd(); // drawing all these lines

    glFlush(); // Flush the OpenGL pipeline
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);                       // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode
    glutInitWindowSize(800, 800);                // Set window size
    glutInitWindowPosition(100, 100);            // Set window position
    glutCreateWindow("KU Logo");                 // Create the window

    glClearColor(0.0, 0.0, 0.0, 0.0); // Set clear color to black

    // Register the display callback function
    glutDisplayFunc(drawLines);

    glutMainLoop(); // Enter the GLUT event processing loop

    return 0;
}
