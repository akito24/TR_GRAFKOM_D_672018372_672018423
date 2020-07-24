#include <Windows.h>
#include <GL/gLut.h>
#include <stdio.h>
#include"imageloader.h"

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
float xt = 0.0f;
float yt = 0.0f;
float zt = 0.0f;

int w = 1000, h = 600, z = 0;
int x1 = 0, y1 = 0, sudut = 0, z1 = 0;
float skalaX = 1, skalaY = 1, skalaZ = 1;

GLuint _textureId1;
GLuint _textureId2;
GLuint _textureId3;

GLuint loadTexture1(Image* image1) {
	GLuint textureId1;
	glGenTextures(1, &textureId1);
	glBindTexture(GL_TEXTURE_2D, textureId1);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image1->width, image1->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image1->pixels);
	return textureId1;
}
GLuint loadTexture2(Image* image2) {
	GLuint textureId2;
	glGenTextures(1, &textureId2);
	glBindTexture(GL_TEXTURE_2D, textureId2);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image2->width, image2->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image2->pixels);
	return textureId2;
}
GLuint loadTexture3(Image* image3) {
	GLuint textureId3;
	glGenTextures(1, &textureId3);
	glBindTexture(GL_TEXTURE_2D, textureId3);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image3->width, image3->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image3->pixels);
	return textureId3;
}


void init(void) {
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 70.0 };
	GLfloat light_position[] = { 0.0, 50.0, 100.0, 0.0 };
	glClearColor(0.0, 0.2, 0.8, 1.0);
	glShadeModel(GL_SMOOTH);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
	is_depth = 1;
	glMatrixMode(GL_MODELVIEW);

	Image* image1 = loadBMP("aspal.bmp");
	_textureId1 = loadTexture1(image1);
	delete image1;
	Image* image2 = loadBMP("rumput.bmp");
	_textureId2 = loadTexture2(image2);
	delete image2;
	Image* image3 = loadBMP("tanah.bmp");
	_textureId3 = loadTexture2(image3);
	delete image3;

	glPointSize(9.0);
	glLineWidth(8.0f);
}

void aspal(void) {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	float x1 = -10.0, y1 = -10, z1 = 30.0;
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 1.0f);
		glVertex3f(x1, y1, z1);
		glTexCoord2f(0.0, 0.0f);
		glVertex3f(x1 + 20, y1, z1);
		glTexCoord2f(1.0, 0.0f);
		glVertex3f(x1 + 20, y1, z1 - 60);
		glTexCoord2f(1.0, 1.0f);
		glVertex3f(x1, y1, z1 - 60);
		glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

void rumput1(void) {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	float x1 = -30, y1 = -10, z1 = 30.0;
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 1.0f);
	glVertex3f(x1, y1, z1);
	glTexCoord2f(0.0, 0.0f);
	glVertex3f(x1 + 20, y1, z1);
	glTexCoord2f(1.0, 0.0f);
	glVertex3f(x1 + 20, y1, z1 - 60);
	glTexCoord2f(1.0, 1.0f);
	glVertex3f(x1, y1, z1 - 60);
	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

void rumput2(void) {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	float x1 = 10, y1 = -10, z1 = 30.0;
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 1.0f);
	glVertex3f(x1, y1, z1);
	glTexCoord2f(0.0, 0.0f);
	glVertex3f(x1 + 20, y1, z1);
	glTexCoord2f(1.0, 0.0f);
	glVertex3f(x1 + 20, y1, z1 - 60);
	glTexCoord2f(1.0, 1.0f);
	glVertex3f(x1, y1, z1 - 60);
	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

void tanah(void) {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId3);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	//depan
	float x1 = -30.0, y1 = -10.01, z1 = 30.0;
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 1.0f);
	glVertex3f(x1, y1, z1);
	glTexCoord2f(0.0, 0.0f);
	glVertex3f(x1 + 60, y1, z1);
	glTexCoord2f(1.0, 0.0f);
	glVertex3f(x1 + 60, y1 - 4.99, z1);
	glTexCoord2f(1.0, 1.0f);
	glVertex3f(x1, y1 - 4.99, z1);
	glEnd();
	//belakang
	float x2 = -30., y2 = -10.01, z2 = -30;
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 1.0f);
	glVertex3f(x2, y2, z2);
	glTexCoord2f(0.0, 0.0f);
	glVertex3f(x2 + 60, y2, z2);
	glTexCoord2f(1.0, 0.0f);
	glVertex3f(x2 + 60, y2 - 4.99, z2);
	glTexCoord2f(1.0, 1.0f);
	glVertex3f(x2, y2 - 4.99, z2);
	glEnd();
	//kiri
	float x3 = -30., y3 = -10.01, z3 = 30;
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 1.0f);
	glVertex3f(x3, y3, z3);
	glTexCoord2f(0.0, 0.0f);
	glVertex3f(x3 , y3, z3 - 60);
	glTexCoord2f(1.0, 0.0f);
	glVertex3f(x3 , y3 - 4.99, z3 - 60);
	glTexCoord2f(1.0, 1.0f);
	glVertex3f(x3, y3 - 4.99, z3);
	glEnd();
	//kanan
	float x4 = 30., y4 = -10.01, z4 = 30;
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 1.0f);
	glVertex3f(x4, y4, z4);
	glTexCoord2f(0.0, 0.0f);
	glVertex3f(x4, y4, z4 - 60);
	glTexCoord2f(1.0, 0.0f);
	glVertex3f(x4, y4 - 4.99, z4 - 60);
	glTexCoord2f(1.0, 1.0f);
	glVertex3f(x4, y4 - 4.99, z4);
	glEnd();
	//bawah
	float x5 = -30., y5 = -15., z5 = 30;
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 1.0f);
	glVertex3f(x5, y5, z5);
	glTexCoord2f(0.0, 0.0f);
	glVertex3f(x5 + 60, y5, z5);
	glTexCoord2f(1.0, 0.0f);
	glVertex3f(x5 +60, y5, z5 - 60);
	glTexCoord2f(1.0, 1.0f);
	glVertex3f(x5, y5, z5 - 60);
	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}
void awan(void)
{
	glPushMatrix();//tengah
	glColor3f(1, 1, 1);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glutSolidSphere(8, 30, 30);//ukuran
	glPopMatrix();
	glPushMatrix();//kanan
	glTranslatef(7, 0, 1);//pcc
	glutSolidSphere(7, 30, 30);//ukuran
	glPopMatrix();
	glPushMatrix();//atas
	glTranslatef(-2, 6, -2);//pcc
	glutSolidSphere(6, 30, 30);//ukuran
	glPopMatrix();
	glPushMatrix();//kiri
	glTranslatef(-7, -3, 0);//pcc
	glutSolidSphere(7, 30, 30);//ukuran
	glPopMatrix();
}
void pohon(void) {
	//batang
	GLUquadricObj* pObj;
	pObj = gluNewQuadric();
	gluQuadricNormals(pObj, GLU_SMOOTH);

	glPushMatrix();
	glColor3ub(104, 70, 14);
	glRotatef(270, 1, 0, 0);
	gluCylinder(pObj, 1, 0.2, 12, 5, 5);//ukuranbatang
	glPopMatrix();
}

//ranting
void ranting(void) {
	GLUquadricObj* pObj;
	pObj = gluNewQuadric();
	gluQuadricNormals(pObj, GLU_SMOOTH);
	glPushMatrix();
	glColor3ub(104, 70, 14);
	glTranslatef(0, 7, 0);//pcc
	glRotatef(330, 1, 0, 0);
	gluCylinder(pObj, 0.3, 0.1, 5, 10, 10);//ukuranranting
	glPopMatrix();

	//daun
	glPushMatrix();
	glColor3ub(18, 118, 13);
	glScaled(2, 2, 2);//ukurandaun
	glTranslatef(0, 5, 3);//pcc
	glutSolidDodecahedron();
	glPopMatrix();
}

void kursi(void) {
	glPushMatrix();
	glColor3f(0.7, 0.2, 0.0);
	glBegin(GL_QUADS);//papanatas
	glVertex3f(-18, -8, 25);
	glVertex3f(-15, -8, 25);
	glVertex3f(-15, -8, 15);
	glVertex3f(-18, -8, 15);
	glEnd();
	glBegin(GL_QUADS);//papanbawah
	glVertex3f(-18, -8.4, 25);
	glVertex3f(-15, -8.4, 25);
	glVertex3f(-15, -8.4, 15);
	glVertex3f(-18, -8.4, 15);
	glEnd();
	glBegin(GL_QUADS);//bingkaidpn
	glVertex3f(-15, -8., 25);
	glVertex3f(-15, -8.4, 25);
	glVertex3f(-15, -8.4, 15);
	glVertex3f(-15, -8., 15);
	glEnd();
	glBegin(GL_QUADS);//bingkaikanan
	glVertex3f(-15, -8., 15);
	glVertex3f(-15, -8.4, 15);
	glVertex3f(-18, -8.4, 15);
	glVertex3f(-18, -8., 15);
	glEnd();
	glBegin(GL_QUADS);//bingkaikiri
	glVertex3f(-15, -8., 25);
	glVertex3f(-15, -8.4, 25);
	glVertex3f(-18, -8.4, 25);
	glVertex3f(-18, -8., 25);
	glEnd();
	glBegin(GL_QUADS);//bingkaiblkng
	glVertex3f(-18, -6, 25);
	glVertex3f(-18, -8.4, 25);
	glVertex3f(-18, -8.4, 15);
	glVertex3f(-18, -6, 15);
	glEnd();
	glBegin(GL_QUADS);//bingkaiblkng2
	glVertex3f(-18.3, -6, 25);
	glVertex3f(-18.3, -8.4, 25);
	glVertex3f(-18.3, -8.4, 15);
	glVertex3f(-18.3, -6, 15);
	glEnd();
	glBegin(GL_QUADS);//bingkaiblkngbawah
	glVertex3f(-18., -8.4, 25);
	glVertex3f(-18.3, -8.4, 25);
	glVertex3f(-18.3, -8.4, 15);
	glVertex3f(-18., -8.4, 15);
	glEnd();
	glBegin(GL_QUADS);//bingkaiblkngatas
	glVertex3f(-18., -6, 25);
	glVertex3f(-18.3, -6, 25);
	glVertex3f(-18.3, -6, 15);
	glVertex3f(-18., -6, 15);
	glEnd();
	glBegin(GL_QUADS);//kaki1
	glVertex3f(-18.3, -6, 25);
	glVertex3f(-18., -6, 25);
	glVertex3f(-18., -10, 25);
	glVertex3f(-18.3, -10, 25);
	glEnd();
	glBegin(GL_QUADS);//kaki11
	glVertex3f(-18.3, -6, 24.5);
	glVertex3f(-18., -6, 24.5);
	glVertex3f(-18., -10, 24.5);
	glVertex3f(-18.3, -10, 24.5);
	glEnd();
	glBegin(GL_QUADS);//kaki12
	glVertex3f(-18.3, -6, 24.5);
	glVertex3f(-18.3, -6, 25);
	glVertex3f(-18.3, -10, 25);
	glVertex3f(-18.3, -10, 24.5);
	glEnd();
	glBegin(GL_QUADS);//kaki2
	glVertex3f(-18.3, -6, 15);
	glVertex3f(-18., -6, 15);
	glVertex3f(-18., -10, 15);
	glVertex3f(-18.3, -10, 15);
	glEnd();
	glBegin(GL_QUADS);//kaki21
	glVertex3f(-18.3, -6, 15.5);
	glVertex3f(-18., -6, 15.5);
	glVertex3f(-18., -10, 15.5);
	glVertex3f(-18.3, -10, 15.5);
	glEnd();
	glBegin(GL_QUADS);//kaki22
	glVertex3f(-18.3, -6, 15.5);
	glVertex3f(-18.3, -6, 15);
	glVertex3f(-18.3, -10, 15);
	glVertex3f(-18.3, -10, 15.5);
	glEnd();
	glBegin(GL_QUADS);//kaki3
	glVertex3f(-15.3, -8.4, 15);
	glVertex3f(-15., -8.4, 15);
	glVertex3f(-15., -10, 15);
	glVertex3f(-15.3, -10, 15);
	glEnd();
	glBegin(GL_QUADS);//kaki31
	glVertex3f(-15.3, -8.4, 15.5);
	glVertex3f(-15., -8.4, 15.5);
	glVertex3f(-15., -10, 15.5);
	glVertex3f(-15.3, -10, 15.5);
	glEnd();
	glBegin(GL_QUADS);//kaki32
	glVertex3f(-15., -8.4, 15.5);
	glVertex3f(-15., -8.4, 15.);
	glVertex3f(-15., -10, 15.);
	glVertex3f(-15., -10, 15.5);
	glEnd();
	glBegin(GL_QUADS);//kaki4
	glVertex3f(-15.3, -8.4, 25);
	glVertex3f(-15., -8.4, 25);
	glVertex3f(-15., -10, 25);
	glVertex3f(-15.3, -10, 25);
	glEnd();
	glBegin(GL_QUADS);//kaki41
	glVertex3f(-15.3, -8.4, 24.5);
	glVertex3f(-15., -8.4, 24.5);
	glVertex3f(-15., -10, 24.5);
	glVertex3f(-15.3, -10, 24.5);
	glEnd();
	glBegin(GL_QUADS);//kaki42
	glVertex3f(-15., -8.4, 24.5);
	glVertex3f(-15., -8.4, 25.);
	glVertex3f(-15., -10, 25.);
	glVertex3f(-15., -10, 24.5);
	glEnd();
	glPopMatrix();
}

void lampu(void) {
	GLUquadricObj* pObj;
	pObj = gluNewQuadric();
	gluQuadricNormals(pObj, GLU_SMOOTH);

	glPushMatrix();//tiang
	glColor3f(0., 0., 0.);
	glRotatef(90, 1, 0, 0);
	gluCylinder(pObj, 0.4, 0.4, 10, 5, 5);//ukuran
	glPopMatrix();

	glPushMatrix();//lingkaran
	glColor3f(1, 1, 0);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glutSolidSphere(2, 30, 30);//ukuran
	glPopMatrix();
}

void tampil(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	glTranslatef(xt, yt, zt);
	glRotatef(sudut, x1, y1, z1);
	glScalef(skalaX, skalaY, skalaZ);
	gluLookAt(0.0f, 0.0f, 3.0f, 0.0, 0.0f, 0.0f, 0.0, 1.0f, 0.0f);
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	glPushMatrix();

	aspal();
	rumput1();
	rumput2();
	tanah();
	kursi();
	
	//kursi2
	glPushMatrix();
	glRotated(180, 0, 90, 0);//rotasi
	glTranslatef(0, 0, -40);//posisi
	kursi();
	glPopMatrix();

	//kursi3
	glPushMatrix();
	glRotated(180, 0, 90, 0);//rotasi
	glTranslatef(0, 0, -10);//posisi
	kursi();
	glPopMatrix();

	//kursi4
	glPushMatrix();
	glTranslatef(0, 0, -30);//posisi
	kursi();
	glPopMatrix();

	//lampu1
	glPushMatrix();
	glTranslatef(-12, 0, 28);//posisi
	lampu();
	glPopMatrix();

	//lampu2
	glPushMatrix();
	glTranslatef(-12, 0, 5);//posisi
	lampu();
	glPopMatrix();


	//lampu4
	glPushMatrix();
	glTranslatef(12, 0, 28);//posisi
	lampu();
	glPopMatrix();

	//lampu5
	glPushMatrix();
	glTranslatef(12, 0, 5);//posisi
	lampu();
	glPopMatrix();


	//awan1
	glPushMatrix();
	glScalef(1., 1., 1.);
	glRotated(45, 1, 0, 0);
	glTranslatef(0, 50, -20);//posisi
	awan();
	glPopMatrix();
	//awan2
	glPushMatrix();
	glScalef(1., 1., 1.);
	glRotated(45, 1, 0, 0);
	glTranslatef(20, 30, -50);//posisi
	awan();
	glPopMatrix();
	//awan3
	glPushMatrix();
	glScalef(1., 1., 1.);
	glRotated(45, 1, 0, 0);
	glTranslatef(-20, 0, -60);//posisi
	awan();
	glPopMatrix();

	//pohon1
	glPushMatrix();
	glTranslatef(-25, -10, -10);//pcc
	glRotatef(0, 0, 1, 0);//rotasiranting
	pohon();
	ranting();
	glPushMatrix();//rantingdaunkanan
	glScalef(.8, .8, .8);
	glTranslatef(0, 9, 6);//pcc
	glRotatef(250, 1, 0, 0);
	ranting();
	glPopMatrix();
	glPushMatrix();//rantingdaunatas
	glScalef(1.2, 1.2, 1.2);
	glTranslatef(0, 2, 6);
	glRotatef(-60, 1, 0, 0);
	ranting();
	glPopMatrix();
	glPopMatrix();

	//pohon2
	glPushMatrix();
	glTranslatef(-25, -10, 10);//pcc
	glRotatef(0, 0, 1, 0);//rotasiranting
	pohon();
	ranting();
	glPushMatrix();//rantingdaunkanan
	glScalef(.8, .8, .8);
	glTranslatef(0, 9, 6);//pcc
	glRotatef(250, 1, 0, 0);
	ranting();
	glPopMatrix();
	glPushMatrix();//rantingdaunatas
	glScalef(1.2, 1.2, 1.2);
	glTranslatef(0, 2, 6);
	glRotatef(-60, 1, 0, 0);
	ranting();
	glPopMatrix();
	glPopMatrix();

	//pohon3
	glPushMatrix();
	glTranslatef(25, -10, 10);//pcc
	glRotatef(0, 0, 1, 0);//rotasiranting
	pohon();
	ranting();
	glPushMatrix();//rantingdaunkiri
	glScalef(.8, .8, .8);
	glTranslatef(0, 9, 6);//pcc
	glRotatef(250, 1, 0, 0);
	ranting();
	glPopMatrix();
	glPushMatrix();//rantingdaunatas
	glScalef(1.2, 1.2, 1.2);
	glTranslatef(0, 2, 6);
	glRotatef(-60, 1, 0, 0);
	ranting();
	glPopMatrix();
	glPopMatrix();

	//pohon4
	glPushMatrix();
	glTranslatef(25, -10, -10);//pcc
	glRotatef(0, 0, 1, 0);//rotasiranting
	pohon();
	ranting();
	glPushMatrix();//rantingdaunkiri
	glScalef(.8, .8, .8);
	glTranslatef(0, 9, 6);//pcc
	glRotatef(250, 1, 0, 0);
	ranting();
	glPopMatrix();
	glPushMatrix();//rantingdaunatas
	glScalef(1.2, 1.2, 1.2);
	glTranslatef(0, 2, 6);
	glRotatef(-60, 1, 0, 0);
	ranting();
	glPopMatrix();
	glPopMatrix();
	//EIFEL
	glBegin(GL_QUADS);//dasar
	glColor3f(0.9, 0.9, 0.9);
	glVertex3f(-7, 5.0, -20.0);
	glVertex3f(7.0, 5.0, -20.0);
	glVertex3f(7.0, 5.0, -27.0);
	glVertex3f(-7.0, 5.0, -27.0);
	glEnd();

	glBegin(GL_LINES);//dasar
	glColor3f(0.9, 0.1, 0.5);
	glVertex3f(-7, 5, -20.0);
	glVertex3f(7.0, 5.0, -20.0);
	glVertex3f(7.0, 5.0, -27.0);
	glVertex3f(-7.0, 5.0, -27.0);

	glVertex3f(7, 5, -20.0);//sampingkanan
	glVertex3f(7.0, 5.0, -27.0);
	glVertex3f(-7, 5, -20.0);//sampingkiri
	glVertex3f(-7.0, 5.0, -27.0);
	glEnd();



	glBegin(GL_LINES);//dasar
	glColor3f(0.3, 0.25, 0.2);
	glVertex3f(-5.0, 5.0, -20.0);
	glVertex3f(-11.0, -10.5, -17.0);
	glVertex3f(-5.0, 5.0, -27.0);
	glVertex3f(-11.0, -10.5, -29.0);
	glVertex3f(5.0, 5.0, -20.0);
	glVertex3f(11.0, -10.5, -17.0);
	glVertex3f(5.0, 5.0, -27.0);
	glVertex3f(11.0, -10.5, -29.0);
	glEnd();



	glBegin(GL_QUADS);//ke-2
	glColor3f(0.9, 0.9, 0.9);
	glVertex3f(-4.2, 15.0, -21.5);
	glVertex3f(4.2, 15.0, -21.5);
	glVertex3f(4.2, 15.0, -26.5);
	glVertex3f(-4.2, 15.0, -26.5);
	glEnd();

	glBegin(GL_LINES);//ke2
	glColor3f(1.0, 0.01, 3.0);
	glVertex3f(-4.2, 15.0, -21.5);
	glVertex3f(4.2, 15.0, -21.5);
	glVertex3f(4.2, 15.0, -26.5);
	glVertex3f(-4.2, 15.0, -26.5);

	glVertex3f(4.2, 15.0, -21.5);//samping kanan
	glVertex3f(4.2, 15.0, -26.5);
	glVertex3f(-4.2, 15.0, -21.5);//samping kiri
	glVertex3f(-4.2, 15.0, -26.5);

	glEnd();

	glBegin(GL_LINES);//ke2
	glColor3f(0.3, 0.25, 0.2);
	glVertex3f(-2.6, 15.0, -21.5);
	glVertex3f(-5.0, 5.0, -20.0);
	glVertex3f(-2.6, 15.0, -26.5);
	glVertex3f(-5.0, 5.0, -27.0);
	glVertex3f(2.5, 15.0, -21.5);
	glVertex3f(5.0, 5.0, -20.0);
	glVertex3f(2.5, 15.0, -26.5);
	glVertex3f(5.0, 5.0, -27.0);
	glEnd();

	glBegin(GL_QUADS);//ke-3
	glColor3f(0.9, 0.9, 0.9);
	glVertex3f(-2.2, 33.0, -23.0);
	glVertex3f(2.2, 33.0, -23.0);
	glVertex3f(2.2, 33.0, -25.0);
	glVertex3f(-2.2, 33.0, -25.0);
	glEnd();


	glBegin(GL_LINES);//ke3
	glColor3f(0.9, 0.01, .5);
	glVertex3f(-2.2, 33.0, -23.0);
	glVertex3f(2.2, 33.0, -23.0);
	glVertex3f(2.2, 33.0, -25.0);
	glVertex3f(-2.2, 33.0, -25.0);

	glVertex3f(2.2, 33.0, -23.0);//samping kanan
	glVertex3f(2.2, 33.0, -25.0);
	glVertex3f(-2.2, 33.0, -23.0);//samping kiri
	glVertex3f(-2.2, 33.0, -25.0);
	glEnd();

	glBegin(GL_LINES);//ke3
	glColor3f(0.3, 0.25, 0.2);
	glVertex3f(-0.5, 33.0, -23.0);
	glVertex3f(-2.5, 15.0, -21.5);
	glVertex3f(-0.5, 33.0, -25.0);
	glVertex3f(-2.5, 15.0, -26.5);
	glVertex3f(0.5, 33.0, -23.0);
	glVertex3f(2.5, 15.0, -21.5);
	glVertex3f(0.5, 33.0, -25.0);
	glVertex3f(2.5, 15.0, -26.5);
	glEnd();

	glBegin(GL_LINES);//UJUNG
	glColor3f(0.3, 0.25, 0.2);
	glVertex3f(0, 40.0, -24);
	glVertex3f(-0.5, 33.0, -23);
	glVertex3f(0, 40.0, -24);
	glVertex3f(-0.5, 33.0, -25);
	glVertex3f(0, 40.0, -24);
	glVertex3f(0.5, 33.0, -23);
	glVertex3f(0, 40.0, -24);
	glVertex3f(0.5, 33.0, -25);
	glEnd();

	glBegin(GL_LINES);//bawah
	glColor3f(0.3, 0.25, 0.2);
	glVertex3f(-7.0, 5.0, -20);
	glVertex3f(-13.0, -10.0, -17);
	glVertex3f(-7.0, 5.0, -27);
	glVertex3f(-13.0, -10.0, -29);
	glVertex3f(7.0, 5.0, -20);
	glVertex3f(13.0, -10.0, -17);
	glVertex3f(7.0, 5.0, -27);
	glVertex3f(13.0, -10.0, -29);
	glEnd();

	glBegin(GL_LINES);//bawahsamping
	glColor3f(.9, .9, 0.9);
	glVertex3f(13.0, -10.0, -29);
	glVertex3f(11.5, -6.0, -17.8);
	glVertex3f(11.5, -6.0, -17.8);
	glVertex3f(10, -2.0, -28.);
	glVertex3f(10, -2.0, -28);
	glVertex3f(8.3, 2, -19.4);
	glVertex3f(8.3, 2, -19.4);
	glVertex3f(7, 5.0, -27);
	//2
	glVertex3f(13.0, -10.0, -17);
	glVertex3f(11.5, -6.0, -28.5);
	glVertex3f(11.5, -6.0, -28.5);
	glVertex3f(10, -2.0, -18.6);
	glVertex3f(10, -2.0, -18.6);
	glVertex3f(8.3, 2, -27.4);
	glVertex3f(8.3, 2, -27.4);
	glVertex3f(7, 5.0, -20);
	//3
	glVertex3f(-13.0, -10.0, -17);
	glVertex3f(-11.5, -6.0, -28.5);
	glVertex3f(-11.5, -6.0, -28.5);
	glVertex3f(-10, -2.0, -18.6);
	glVertex3f(-10, -2.0, -18.6);
	glVertex3f(-8.3, 2, -27.4);
	glVertex3f(-8.3, 2, -27.4);
	glVertex3f(-7, 5.0, -20);
	//4
	glVertex3f(-13.0, -10.0, -29);
	glVertex3f(-11.5, -6.0, -17.8);
	glVertex3f(-11.5, -6.0, -17.8);
	glVertex3f(-10, -2.0, -28.);
	glVertex3f(-10, -2.0, -28);
	glVertex3f(-8.3, 2, -19.4);
	glVertex3f(-8.3, 2, -19.4);
	glVertex3f(-7, 5.0, -27);

	glEnd();

	glBegin(GL_LINES);//Tengah
	glColor3f(0.3, 0.25, 0.2);
	glVertex3f(-4.0, 15.0, -21.5);
	glVertex3f(-7.0, 5.0, -20.0);
	glVertex3f(-4.0, 15.0, -26.5);
	glVertex3f(-7.0, 5.0, -27.0);
	glVertex3f(4.0, 15.0, -21.5);
	glVertex3f(7.0, 5.0, -20.0);
	glVertex3f(4.0, 15.0, -26.5);
	glVertex3f(7.0, 5.0, -27.0);
	glEnd();
	glBegin(GL_LINES);//Samping
	glColor3f(0.9, 0.9, 0.9);
	glVertex3f(7.0, 5.0, -27.);
	glVertex3f(6.2, 8.0, -20.5);
	glVertex3f(6.2, 8.0, -20.5);
	glVertex3f(5.3, 11.0, -26.8);
	glVertex3f(5.3, 11.0, -26.8);
	glVertex3f(4.0, 15.0, -21.5);
	//2
	glVertex3f(7.0, 5.0, -20.);
	glVertex3f(6.2, 8.0, -26.8);
	glVertex3f(6.2, 8.0, -26.8);
	glVertex3f(5.3, 11.0, -20.9);
	glVertex3f(5.3, 11.0, -20.9);
	glVertex3f(4.0, 15.0, -26.5);
	//3
	glVertex3f(-7.0, 5.0, -27.);
	glVertex3f(-6.2, 8.0, -20.5);
	glVertex3f(-6.2, 8.0, -20.5);
	glVertex3f(-5.3, 11.0, -26.8);
	glVertex3f(-5.3, 11.0, -26.8);
	glVertex3f(-4.0, 15.0, -21.5);
	//4
	glVertex3f(-7.0, 5.0, -20.);
	glVertex3f(-6.2, 8.0, -26.8);
	glVertex3f(-6.2, 8.0, -26.8);
	glVertex3f(-5.3, 11.0, -20.9);
	glVertex3f(-5.3, 11.0, -20.9);
	glVertex3f(-4.0, 15.0, -26.5);
	glEnd();

	glBegin(GL_LINES);//Aatas
	glColor3f(0.3, 0.25, 0.2);
	glVertex3f(-1.5, 33.0, -23.0);
	glVertex3f(-4.0, 15.0, -21.5);
	glVertex3f(-1.5, 33.0, -25.0);
	glVertex3f(-4.0, 15.0, -26.5);
	glVertex3f(1.5, 33.0, -23.0);
	glVertex3f(4.0, 15.0, -21.5);
	glVertex3f(1.5, 33.0, -25.0);
	glVertex3f(4.0, 15.0, -26.5);
	glEnd();
	glBegin(GL_LINES);//Sampingatas
	glColor3f(0.9, 0.9, 0.9);
	glVertex3f(4.0, 15.0, -21.5);
	glVertex3f(3.5, 19.0, -26.2);
	glVertex3f(3.5, 19.0, -26.2);
	glVertex3f(3.0, 23.0, -22.2);
	glVertex3f(3.0, 23.0, -22.2);
	glVertex3f(2.4, 27.0, -25.5);
	glVertex3f(2.4, 27.0, -25.5);
	glVertex3f(1.5, 33.0, -23.);
	//2
	glVertex3f(4.0, 15.0, -26.5);
	glVertex3f(3.5, 19.0, -21.8);
	glVertex3f(3.5, 19.0, -21.8);
	glVertex3f(3.0, 23.0, -25.8);
	glVertex3f(3.0, 23.0, -25.8);
	glVertex3f(2.4, 27.0, -22.5);
	glVertex3f(2.4, 27.0, -22.5);
	glVertex3f(1.5, 33.0, -25.);
	//3
	glVertex3f(-4.0, 15.0, -21.5);
	glVertex3f(-3.5, 19.0, -26.2);
	glVertex3f(-3.5, 19.0, -26.2);
	glVertex3f(-3.0, 23.0, -22.2);
	glVertex3f(-3.0, 23.0, -22.2);
	glVertex3f(-2.4, 27.0, -25.5);
	glVertex3f(-2.4, 27.0, -25.5);
	glVertex3f(-1.5, 33.0, -23.);
	//4
	glVertex3f(-4.0, 15.0, -26.5);
	glVertex3f(-3.5, 19.0, -21.8);
	glVertex3f(-3.5, 19.0, -21.8);
	glVertex3f(-3.0, 23.0, -25.8);
	glVertex3f(-3.0, 23.0, -25.8);
	glVertex3f(-2.4, 27.0, -22.5);
	glVertex3f(-2.4, 27.0, -22.5);
	glVertex3f(-1.5, 33.0, -25.);

	glEnd();

	glBegin(GL_LINES);//kiri depan
	glColor3f(0.3, 0.25, 0.2);
	glVertex3f(-9.0, -5.0, -18);
	glVertex3f(-13.0, -10.0, -17);
	glVertex3f(-11.0, -5.0, -18);
	glVertex3f(-11.0, -10.0, -17);

	glVertex3f(-7.0, -0.0, -19);
	glVertex3f(-11.0, -5.0, -18);
	glVertex3f(-9.0, -0.0, -19);
	glVertex3f(-9.0, -5.0, -18);

	glVertex3f(-5.0, 5.0, -20);
	glVertex3f(-9.0, -0.0, -19);
	glVertex3f(-7.0, 5.0, -20);
	glVertex3f(-7.0, -0.0, -19);

	glVertex3f(-3.8, 10.0, -20.8);
	glVertex3f(-7.0, 5.0, -20);
	glVertex3f(-5.5, 10.0, -20.8);
	glVertex3f(-5.0, 5.0, -20);

	glVertex3f(-2.6, 15.0, -21.5);
	glVertex3f(-5.5, 10.0, -20.8);
	glVertex3f(-4.0, 15.0, -21.5);
	glVertex3f(-3.8, 10.0, -20.8);

	glVertex3f(-2.0, 20.0, -22.0);
	glVertex3f(-4.0, 15.0, -21.5);
	glVertex3f(-3.3, 20.0, -22.0);
	glVertex3f(-2.6, 15.0, -21.5);

	glVertex3f(-1.4, 25.0, -22.5);
	glVertex3f(-3.3, 20.0, -22.0);
	glVertex3f(-2.6, 25.0, -22.5);
	glVertex3f(-2.0, 20.0, -22.0);

	glVertex3f(-0.9, 30.0, -22.8);
	glVertex3f(-2.6, 25.0, -22.5);
	glVertex3f(-1.9, 30.0, -22.8);
	glVertex3f(-1.4, 25.0, -22.5);

	glVertex3f(-0.6, 33.0, -23.3);
	glVertex3f(-1.9, 30.0, -22.8);
	glVertex3f(-1.2, 33.0, -23.3);
	glVertex3f(-0.9, 30.0, -22.8);
	glEnd();

	glBegin(GL_LINES);//kanan depan
	glColor3f(0.3, 0.25, 0.2);
	glVertex3f(9.0, -5.0, -18);
	glVertex3f(13.0, -10.0, -17);
	glVertex3f(11.0, -5.0, -18);
	glVertex3f(11.0, -10.0, -17);

	glVertex3f(7.0, -0.0, -19);
	glVertex3f(11.0, -5.0, -18);
	glVertex3f(9.0, -0.0, -19);
	glVertex3f(9.0, -5.0, -18);

	glVertex3f(5.0, 5.0, -20);
	glVertex3f(9.0, -0.0, -19);
	glVertex3f(7.0, 5.0, -20);
	glVertex3f(7.0, -0.0, -19);

	glVertex3f(3.8, 10.0, -20.8);
	glVertex3f(7.0, 5.0, -20);
	glVertex3f(5.5, 10.0, -20.8);
	glVertex3f(5.0, 5.0, -20);

	glVertex3f(2.6, 15.0, -21.5);
	glVertex3f(5.5, 10.0, -20.8);
	glVertex3f(4.0, 15.0, -21.5);
	glVertex3f(3.8, 10.0, -20.8);

	glVertex3f(2.0, 20.0, -22.0);
	glVertex3f(4.0, 15.0, -21.5);
	glVertex3f(3.3, 20.0, -22.0);
	glVertex3f(2.6, 15.0, -21.5);

	glVertex3f(1.4, 25.0, -22.5);
	glVertex3f(3.3, 20.0, -22.0);
	glVertex3f(2.6, 25.0, -22.5);
	glVertex3f(2.0, 20.0, -22.0);

	glVertex3f(0.9, 30.0, -22.8);
	glVertex3f(2.6, 25.0, -22.5);
	glVertex3f(1.9, 30.0, -22.8);
	glVertex3f(1.4, 25.0, -22.5);

	glVertex3f(0.6, 33.0, -23.3);
	glVertex3f(1.9, 30.0, -22.8);
	glVertex3f(1.2, 33.0, -23.3);
	glVertex3f(0.9, 30.0, -22.8);
	glEnd();


	glBegin(GL_LINES);//kiri belakang
	glColor3f(0.3, 0.25, 0.2);
	glVertex3f(-9.0, -5.0, -28.5);
	glVertex3f(-13.0, -10.0, -29);
	glVertex3f(-11.0, -5.0, -28.5);
	glVertex3f(-11.0, -10.0, -29.0);

	glVertex3f(-7.0, -0.0, -27.8);
	glVertex3f(-11.0, -5.0, -28.5);
	glVertex3f(-9.0, -0.0, -27.8);
	glVertex3f(-9.0, -5.0, -28.5);

	glVertex3f(-5.0, 5.0, -27.2);
	glVertex3f(-9.0, -0.0, -27.8);
	glVertex3f(-7.0, 5.0, -27.2);
	glVertex3f(-7.0, -0.0, -27.8);

	glVertex3f(-4.0, 10.0, -26.90);
	glVertex3f(-7.0, 5.0, -27.2);
	glVertex3f(-5.5, 10.0, -26.90);
	glVertex3f(-5.0, 5.0, -27.2);

	glVertex3f(-2.5, 15.0, -26.6);
	glVertex3f(-5.5, 10.0, -26.90);
	glVertex3f(-4.0, 15.0, -26.6);
	glVertex3f(-4.0, 10.0, -26.90);

	glVertex3f(-2.0, 20.0, -26.3);
	glVertex3f(-4.0, 15.0, -26.6);
	glVertex3f(-3.3, 20.0, -26.3);
	glVertex3f(-2.5, 15.0, -26.6);

	glVertex3f(-1.4, 25.0, -26.0);
	glVertex3f(-3.3, 20.0, -26.3);
	glVertex3f(-2.6, 25.0, -26.0);
	glVertex3f(-2.0, 20.0, -26.3);

	glVertex3f(-0.9, 30.0, -25.3);
	glVertex3f(-2.6, 25.0, -26.0);
	glVertex3f(-1.9, 30.0, -25.3);
	glVertex3f(-1.4, 25.0, -26.0);
	
	glVertex3f(-0.6, 33.0, -25);
	glVertex3f(-1.9, 30.0, -25.3);
	glVertex3f(-1.5, 33.0, -25);
	glVertex3f(-0.9, 30.0, -25.3);
	glEnd();

	glBegin(GL_LINES);//kanan belakang
	glColor3f(0.3, 0.25, 0.2);
	glVertex3f(9.0, -5.0, -28.5);
	glVertex3f(13.0, -10.0, -29);
	glVertex3f(11.0, -5.0, -28.5);
	glVertex3f(11.0, -10.0, -29.0);

	glVertex3f(7.0, -0.0, -27.8);
	glVertex3f(11.0, -5.0, -28.5);
	glVertex3f(9.0, -0.0, -27.8);
	glVertex3f(9.0, -5.0, -28.5);

	glVertex3f(5.0, 5.0, -27.2);
	glVertex3f(9.0, -0.0, -27.8);
	glVertex3f(7.0, 5.0, -27.2);
	glVertex3f(7.0, -0.0, -27.8);

	glVertex3f(4.0, 10.0, -26.90);
	glVertex3f(7.0, 5.0, -27.2);
	glVertex3f(5.5, 10.0, -26.90);
	glVertex3f(5.0, 5.0, -27.2);

	glVertex3f(2.5, 15.0, -26.6);
	glVertex3f(5.5, 10.0, -26.90);
	glVertex3f(4.0, 15.0, -26.6);
	glVertex3f(4.0, 10.0, -26.90);

	glVertex3f(2.0, 20.0, -26.3);
	glVertex3f(4.0, 15.0, -26.6);
	glVertex3f(3.3, 20.0, -26.3);
	glVertex3f(2.5, 15.0, -26.6);

	glVertex3f(1.4, 25.0, -26.0);
	glVertex3f(3.3, 20.0, -26.3);
	glVertex3f(2.6, 25.0, -26.0);
	glVertex3f(2.0, 20.0, -26.3);

	glVertex3f(0.9, 30.0, -25.3);
	glVertex3f(2.6, 25.0, -26.0);
	glVertex3f(1.9, 30.0, -25.3);
	glVertex3f(1.4, 25.0, -26.0);

	glVertex3f(0.6, 33.0, -25.);
	glVertex3f(1.9, 30.0, -25.3);
	glVertex3f(1.2, 33.0, -25.);
	glVertex3f(0.9, 30.0, -25.3);
	glEnd();

	//pucuk
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-3.0, 1.5, -19);
	glVertex3f(3.0, 1.5, -19);
	glVertex3f(-3.0, 1.5, -19);
	glVertex3f(-8.0, -3.0, -18.5);
	glVertex3f(3.0, 1.5, -19);
	glVertex3f(8.0, -3.0, -18.5);

	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-3.0, 1.5, -27.58);
	glVertex3f(3.0, 1.5, -27.58);
	glVertex3f(-3.0, 1.5, -27.58);
	glVertex3f(-8.0, -3.0, -28);
	glVertex3f(3.0, 1.5, -27.58);
	glVertex3f(8.0, -3.0, -28);
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
	if (key == 'w') zt += 5;//zoom in
	else if (key == 's') zt -= 5;//zoom out
	else if (key == 'a') xt += 5;//kiri
	else if (key == 'd') xt -= 5;//kanan
	else if (key == 'q') yt -= 5;//atas
	else if (key == 'z') yt += 5;//bawah

}

void ukuran(int w1, int h1) {
	glViewport(0, 0, w1, h1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (float)w1 / (float)h1, 1.0, 300.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

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