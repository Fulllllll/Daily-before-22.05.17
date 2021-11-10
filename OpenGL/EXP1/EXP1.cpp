// ====== Computer Graphics Experiment #1 ======
// |     Bresenham's Line Drawing Algorithm    |
// |                                           |
// =============================================
//
// Requirement:
// Implement a general Bresenham's Line Drawing Algorithm.
// Only use GL_POINTS drawing mode. 
// Do not use OpenGL line drawing capability.


#include <windows.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.14159265359
int width, height;



// Bresenham line algorithm
void MyLine(int xs, int ys, int xe, int ye)
{
	int dx = xe - xs;
	int dy = ye - ys;
	int x = xs;
	int y = ys;
	int p = 0;
	double m = fabs(1.0 * dy / dx);
	if (m <= 1)
	{
		p = 2 * fabs(dy) - fabs(dx);////
		glBegin(GL_POINTS);
		for (int i = 0; i < fabs(dx); ++i)
		{
			glVertex2i(x, y);
			x += dx >= 0 ? 1 : -1;
			if (p < 0) p += 2 * fabs(dy);
			else
			{
				y += (dy >= 0 ? 1 : -1);
				p += 2 * fabs(dy) - 2 * fabs(dx);
			}
		}
		glEnd();
	}
	else
	{
		p = 2 * fabs(dx) - fabs(dy);
		glBegin(GL_POINTS);
		for (int i = 0; i < fabs(dy); ++i)
		{
			glVertex2i(x, y);
			y += (dy >= 0 ? 1 : -1);
			if (p < 0) p += 2 * fabs(dx);
			else
			{
				x += dx >= 0 ? 1 : -1;
				p += 2 * fabs(dx) - 2 * fabs(dy);
			}
		}
		glEnd();
	}
}


// Initialization function
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

// Display callback function
void display(void)
{
	int i, x0, y0, x, y;
	double a;

	glClear(GL_COLOR_BUFFER_BIT);

	x0 = width / 2;
	y0 = height / 2;

	glColor3f(1.0, 1.0, 1.0);

	// Draw lines
	for (i = 0; i < 360; i += 15)
	{
		a = (double)i / 180.0 * PI;
		x = 0.45 * width * cos(a);
		y = 0.45 * height * sin(a);
		if (i == 0 || i == 180) y = 0;
		if (i == 90 || i == 270) x = 0;
		MyLine(x0, y0, x0 + x, y0 + y);
	}

	glFlush();
}

// Reshape callback function
void reshape(int w, int h)
{
	// Record width and height of program window
	width = w;
	height = h;

	// Set clipping window and viewport equal to
	// view area of program window
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, w, 0.0, h);
}

// Keyboard callback function
void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 27:
		exit(0);

	}
}

// Main program entrance
int main(int argc, char* argv[])
{
	// Create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Lines");

	// Initialization
	init();

	// Define callback functions
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);

	// Main program loop. (Event loop)
	glutMainLoop();

	return 0;
}