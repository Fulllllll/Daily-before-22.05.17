// ====== Computer Graphics Experiment #3 ======
// |          Boundary-Fill Algorithm          |
// =============================================
//
// Requirement:
//	Implement Boundary-Fill algorithm to fill polygon. 


#include "MyStack.h"
#define WINDOW_HEIGHT 400


void Boundaryfill(int seedx, int seedy)
{
	CMyStack stk1;
	long color = RGB(255, 0, 0); //填充颜色
	long boundary_color = RGB(255, 255, 255); //边界颜色
	unsigned char params[4]; //保存读取的一个像素点的颜色值
	dcpt p1;
	p1.x = seedx;
	p1.y = seedy;
	
	stk1.push(p1);
	while (!stk1.isEmpty())
	{
		p1 = stk1.getTop();
		stk1.pop();
		glColor3f(1, 0, 0);
		glBegin(GL_POINTS);
			glVertex2i(p1.x, p1.y);
		glEnd();

		dcpt del[4] = { {-1,0},{0,1},{1,0},{0,-1} };
		for (int i = 0; i < 4; i++)			//检查左上右下的像素点
		{
			//设置左上右下像素点 t
			dcpt t;
			t.x = p1.x + del[i].x;
			t.y = p1.y + del[i].y;
			//获取出栈像素点t的颜色值
			glReadPixels(t.x, t.y, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, params);
			long t_RGB = RGB(params[0], params[1], params[2]);
			if (t_RGB != boundary_color && t_RGB != color)
				stk1.push(t);
		}
	}
}

void MyPolygonFill(int n, dcpt* vertices)
// n --- Number of vertices
// vertices --- vertex coordinates
{


	int max = vertices[0].x;
	int mix = vertices[0].x;
	int may = vertices[0].y;
	int miy = vertices[0].y;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < n; i++)
	{
		glVertex2i(vertices[i].x, vertices[i].y);
		if (vertices[i].x > max)
			max = vertices[i].x;
		if (vertices[i].x < mix)
			mix = vertices[i].x;
		if (vertices[i].y > may)
			may = vertices[i].y;
		if (vertices[i].y < miy)
			miy = vertices[i].y;
	}
	glEnd();
	int sx = (max + mix) / 2;
	int sy = (may + miy) / 2;
	Boundaryfill(sx, sy);


}

// Initialization function
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glPixelStorei(GL_PACK_ALIGNMENT, 1);
}

// Display callback function
void display(void)
{
	static dcpt v[4];
	v[0].x = 260, v[0].y = 150;
	v[1].x = 281, v[1].y = 200;
	v[2].x = 340, v[2].y = 230;
	v[3].x = 370, v[3].y = 150;

	glClear(GL_COLOR_BUFFER_BIT);

	MyPolygonFill(4, v);

	glFlush();
}

// Reshape callback function
void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
}

// Keyboard callback function
void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 27: exit(0);
	}
}

// Main program entrance
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(650, 400);
	glutInitWindowPosition(50, 100);
	glutCreateWindow("Polygon Fill");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}