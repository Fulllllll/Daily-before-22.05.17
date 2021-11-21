// ====== Computer Graphics Experiment #5 ======
// |       Two-Dimensional Transformation      |
// =============================================
//
// Requirement:
// (1) Implement functions to generate 2D transformation matrix.
// (2) Implement function to transform 2D point using 
//     transformation matrix.
// (3) Implement functions to rotate, scale and translate objects 
//     using keyboard.

#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include<iostream>
using namespace std;
#define PI 3.1415926535
// 2D point class
class CPoint2D
{
public:
	float x, y;
};

// 2D transformation matrix
float My2DMatrix[3][3];

void M_mul(float M[3][3],float My2DMatrix[3][3])
{
	float temp[3][3] = {0.0};
	int i = 0, j = 0, k = 0;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			for (k = 0; k < 3; k++)
			{
				temp[i][j] += (M[i][k] * My2DMatrix[k][j]);
			}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			My2DMatrix[i][j] = temp[i][j];
		}
	}
}

// Generate translation matrix
void TranslationMatrix(float tx, float ty, float M[3][3])
// tx, ty --- Translation vector
{
	M[0][0] = 1.0; M[0][1] = 0.0; M[0][2] = tx;
	M[1][0] = 0.0; M[1][1] = 1.0; M[1][2] = ty;
	M[2][0] = 0.0; M[2][1] = 0.0; M[2][2] = 1.0;
}

// Generate rotation matrix
void RotationMatrix(float theta, float M[3][3])
// theta --- Rotation angle in degree
{
	//float theta = 180.0 / angle;
	M[0][0] = cos(theta); M[0][1] = -sin(theta); M[0][2] = 0.0;
	M[1][0] = sin(theta); M[1][1] = cos(theta); M[1][2] = 0.0;
	M[2][0] = 0.0; M[2][1] = 0.0; M[2][2] = 1.0;
}

// Generate scaling matrix
void ScalingMatrix(float sx, float sy, float M[3][3])
// sx, sy --- Scaling factors
{
	M[0][0] = sx; M[0][1] = 0.0; M[0][2] = 0.0;
	M[1][0] = 0.0; M[1][1] = sy; M[1][2] = 0.0;
	M[2][0] = 0.0; M[2][1] = 0.0; M[2][2] = 1.0;
}


// Translate
void Translate(float tx, float ty)
// tx, ty --- Translation vector
{
	float M[3][3];
	TranslationMatrix(tx, ty, M);

	M_mul(M, My2DMatrix);
	// Multiply M to the left of My2DMatrix
}

// Rotate
void Rotate(float theta)
// theta --- Rotation angle in degree
{
	float M[3][3];
	RotationMatrix(theta, M);
	M_mul(M, My2DMatrix);
	// Multiply M to the left of My2DMatrix
}

// Scale
void Scale(float sx, float sy)
// sx, sy --- Scaling factors
{
	float M[3][3];
	ScalingMatrix(sx, sy, M);

	M_mul(M, My2DMatrix);
	// Multiply M to the left of My2DMatrix
}

// Transform 2D point
void Transform2DPoint(CPoint2D* p, float M[3][3], CPoint2D* q)
// p --- Input point
// M --- Transformation matrix
// q --- Output point
{
	q->x = M[0][0] * p->x + M[0][1] * p->y + M[0][2];
	q->y = M[1][0] * p->x + M[1][1] * p->y + M[1][2];
}

void IdentityMatrix(float M[3][3])
{
	M[0][0] = 1.0; M[0][1] = 0.0; M[0][2] = 0.0;
	M[1][0] = 0.0; M[1][1] = 1.0; M[1][2] = 0.0;
	M[2][0] = 0.0; M[2][1] = 0.0; M[2][2] = 1.0;
}

// Initialization function
void init(void)
{
	glClearColor(0.0, 0.0, 0.5, 0.0);
	IdentityMatrix(My2DMatrix);
}

// Display callback function
void display(void)
{
	static CPoint2D MyObject[] =
	{ {0.0, 63.0},
	{-60.0, 20.0}, {-60.0, -20.0},
	{60.0, -20.0}, {60.0, 20.0} };
	CPoint2D pp;
	int i;

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);

	glBegin(GL_POLYGON);
	for (i = 0; i < 5; ++i)
	{
		Transform2DPoint(MyObject + i, My2DMatrix, &pp);
		glVertex2f(pp.x, pp.y);
	}
	glEnd();

	glutSwapBuffers();
}

// Reshape callback function
void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
}

// Keyboard callback function
void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 27: exit(0);
	}
}

//Special keyboard callback function
void special_key(int key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_LEFT:
		Translate(-1.0, 0.0); glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT:
		Translate(1.0, 0.0); glutPostRedisplay();
		break;
	case GLUT_KEY_DOWN:
		Translate(0.0, -1.0); glutPostRedisplay();
		break;
	case GLUT_KEY_UP:
		Translate(0.0, 1.0); glutPostRedisplay();
		break;
	case GLUT_KEY_PAGE_UP:
		Scale(1.1, 1.1); glutPostRedisplay();
		break;
	case GLUT_KEY_PAGE_DOWN:
		Scale(0.9, 0.9); glutPostRedisplay();
		break;
	case GLUT_KEY_HOME:
		Rotate(PI/4);	glutPostRedisplay();
		break;
	case GLUT_KEY_END:
		Rotate(-PI/4);	glutPostRedisplay();
		break;
	case GLUT_KEY_INSERT:
		break;
	}
}

// Main program entrance
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Test 2D Transformation");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(special_key);
	glutMainLoop();
	return 0;
}