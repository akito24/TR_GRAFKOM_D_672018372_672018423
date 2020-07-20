#include <Windows.h>
#include <GL/gLut.h>
#include <stdio.h>

//coding with DEV C++

void init(void);
void tampil(void);
void mouse(int button, int state, int x, int y);
void ukuran(int, int);
void mouseMotion(int x, int y);
void myKeyboard(unsigned char key, int x, int y);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;

int w = 500, h = 500, z = 0;
int x1 = 0, y1 = 0, sudut = 0, z1 = 0;
float skalaX = 1, skalaY = 1, skalaZ = 1;

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(w, h);
	glutInitWindowPosition(250, 80);
	glutCreateWindow("TR_GRAFKOM_D_672018423_672018372");
	init();
	glutDisplayFunc(tampil);
	glutReshapeFunc(ukuran);

	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutKeyboardFunc(myKeyboard);

	glutIdleFunc(tampil);
	glutMainLoop();
	return 0;
}

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
	is_depth = 1;
	glMatrixMode(GL_MODELVIEW);
	glPointSize(9.0);
	glLineWidth(6.0f);
}

void tampil(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	glTranslatef(0, 0, z);
	glRotatef(sudut, x1, y1, z1);
	glScalef(skalaX, skalaY, skalaZ);

	gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	glPushMatrix();


	//jalan
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-10.0, -9.998, 30.0);
	glVertex3f(10.0, -9.998, 30.0);
	glVertex3f(10.0, -9.998, -30.0);
	glVertex3f(-10.0, -9.998, -30.0);
	glEnd();

	//garis jalan
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-1.0, -9.996, 25.0);
	glVertex3f(1.0, -9.996, 25.0);
	glVertex3f(1.0, -9.996, 20.0);
	glVertex3f(-1.0, -9.996, 20.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-1.0, -9.996, 15.0);
	glVertex3f(1.0, -9.996, 15.0);
	glVertex3f(1.0, -9.996, 10.0);
	glVertex3f(-1.0, -9.996, 10.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-1.0, -9.996, 5.0);
	glVertex3f(1.0, -9.996, 5.0);
	glVertex3f(1.0, -9.996, 0.0);
	glVertex3f(-1.0, -9.996, 0.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-1.0, -9.996, -5.0);
	glVertex3f(1.0, -9.996, -5.0);
	glVertex3f(1.0, -9.996, -10.0);
	glVertex3f(-1.0, -9.996, -10.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-1.0, -9.996, -15.0);
	glVertex3f(1.0, -9.996, -15.0);
	glVertex3f(1.0, -9.996, -20.0);
	glVertex3f(-1.0, -9.996, -20.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-1.0, -9.996, -25.0);
	glVertex3f(1.0, -9.996, -25.0);
	glVertex3f(1.0, -9.996, -30.0);
	glVertex3f(-1.0, -9.996, -30.0);
	glEnd();


	//EIFEL
	glBegin(GL_QUADS);//dasar
	glColor3f(3.0, 2.0, 5.0);
	glVertex3f(-5, -6.0, -20.0);
	glVertex3f(5.0, -6.0, -20.0);
	glVertex3f(5.0, -6.0, -27.0);
	glVertex3f(-5.0, -6.0, -27.0);
	glEnd();

	glBegin(GL_LINES);//dasar
	glColor3f(1.0, 0.01, .0);
	glVertex3f(-5, -6.0, -20.0);
	glVertex3f(5.0, -6.0, -20.0);
	glVertex3f(5.0, -6.0, -27.0);
	glVertex3f(-5.0, -6.0, -27.0);
	glEnd();

	glBegin(GL_LINES);//dasar
	glColor3f(3.0, 3.0, 0.0);
	glVertex3f(-5.0, -6.0, -20.0);
	glVertex3f(-11.0, -9.5, -17.0);
	glVertex3f(-5.0, -6.0, -27.0);
	glVertex3f(-11.0, -9.5, -29.0);
	glVertex3f(5.0, -6.0, -20.0);
	glVertex3f(11.0, -9.5, -17.0);
	glVertex3f(5.0, -6.0, -27.0);
	glVertex3f(11.0, -9.5, -29.0);
	glEnd();

	glBegin(GL_QUADS);//ke-2
	glColor3f(3.0, 2.0, 5.0);
	glVertex3f(-2.5, 0.0, -20.0);
	glVertex3f(2.5, 0.0, -20.0);
	glVertex3f(2.5, 0.0, -27.0);
	glVertex3f(-2.5, 0.0, -27.0);
	glEnd();

	glBegin(GL_LINES);//ke2
	glColor3f(1.0, 0.01, .0);
	glVertex3f(-2.5, 0.0, -20.0);
	glVertex3f(2.5, 0.0, -20.0);
	glVertex3f(2.5, 0.0, -27.0);
	glVertex3f(-2.5, 0.0, -27.0);
	glEnd();

	glBegin(GL_LINES);//ke2
	glColor3f(3.0, 3.0, 0.0);
	glVertex3f(-2.6, -0.0, -20.0);
	glVertex3f(-5.0, -6.0, -20.0);
	glVertex3f(-2.6, -0.0, -27.0);
	glVertex3f(-5.0, -6.0, -27.0);
	glVertex3f(2.5, -0.0, -20.0);
	glVertex3f(5.0, -6.0, -20.0);
	glVertex3f(2.5, -0.0, -27.0);
	glVertex3f(5.0, -6.0, -27.0);
	glEnd();

	glBegin(GL_QUADS);//ke-3
	glColor3f(3.0, 2.0, 5.0);
	glVertex3f(-0.5, 7.0, -20.0);
	glVertex3f(0.5, 7.0, -20.0);
	glVertex3f(0.5, 7.0, -27.0);
	glVertex3f(-0.5, 7.0, -27.0);
	glEnd();


	glBegin(GL_LINES);//ke3
	glColor3f(1.0, 0.01, .0);
	glVertex3f(-0.5, 0.0, -20.0);
	glVertex3f(0.5, 0.0, -20.0);
	glVertex3f(0.5, 0.0, -27.0);
	glVertex3f(-0.5, 0.0, -27.0);
	glEnd();

	glBegin(GL_LINES);//ke2
	glColor3f(3.0, 3.0, 0.0);
	glVertex3f(-0.5, 7.0, -20.0);
	glVertex3f(-2.5, -0.0, -20.0);
	glVertex3f(-0.5, 7.0, -27.0);
	glVertex3f(-2.5, -0.0, -27.0);
	glVertex3f(0.5, 7.0, -20.0);
	glVertex3f(2.5, 0.0, -20.0);
	glVertex3f(0.5, 7.0, -27.0);
	glVertex3f(2.5, 0.0, -27.0);
	glEnd();

	//kursi
	glBegin(GL_QUADS);
	glColor3f(1.0, 3.0, .0);
	glVertex3f(11.0, -9.0, 25.0);
	glVertex3f(15.0, -9.0, 25.0);
	glVertex3f(15.0, -9.0, 13.0);
	glVertex3f(11.0, -9.0, 13.0);
	glEnd();


	glBegin(GL_LINES);
	glColor3f(5.0, 3.0, 1.0);
	glVertex3f(11.0, -9.0, 25.0);
	glVertex3f(15.0, -9.0, 25.0);
	glVertex3f(15.0, -9.0, 13.0);
	glVertex3f(11.0, -9.0, 13.0);
	glEnd();

	//hijau
	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-30.0, -10.0, 30.0);
	glVertex3f(30.0, -10.0, 30.0);
	glVertex3f(30.0, -10.0, -30.0);
	glVertex3f(-30.0, -10.0, -30.0);
	glEnd();




	glPopMatrix();
	glutSwapBuffers();
}

void idle() {
	if (!mouseDown)
	{
		xrot += 0.3f;
		yrot += 0.4f;
	}
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouseDown = true;
		xdiff = x - yrot;
		ydiff = -y + xrot;
	}
	else
		mouseDown = false;
}

void mouseMotion(int x, int y) {
	if (mouseDown)
	{
		yrot = x - xdiff;
		xrot = y + ydiff;

		glutPostRedisplay();
	}
}

void myKeyboard(unsigned char key, int x, int y) {
	if (key == 'a') z += 5;
	else if (key == 'd') z -= 5;
}

void ukuran(int w1, int h1) {
	glViewport(0, 0, w1, h1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (float)w1 / (float)h1, 1.0, 300.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
