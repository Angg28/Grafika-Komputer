#include <GL/glut.h>
#include <math.h>
#include <iostream>
using namespace std;

#define FPS 120
#define TO_RADIANS 3.14/180.0

//  Anggota Kelompok X
//  Andreas David Dl Hardi(672020009)
//  ANGGASTA NAUFAL AKMA(672020145)
//  Yoga Agung Prasetia(672020193)
//  SHEILA AYU MENTARI NOVERIA(672020219)
//  Aryudha Willy Putra Hattu (672020232)

const int width = 1280;
const int height = 720;
int i;
float sudut;
double x_geser, y_geser, z_geser;

float pitch = 0.0, yaw = 0.0;
float camX = 0.0, camZ = 1500, terbang = -300;

void display();
void reshape(int w, int h);
void timer(int);
void passive_motion(int, int);
void camera();
void keyboard(unsigned char key, int x, int y);
void keyboard_up(unsigned char key, int x, int y);

struct Motion {
    bool Forward, Backward, Left, Right, Naik, Turun;
};
Motion motion = { false,false,false,false,false,false };

void init() {
    glClearColor(0, 0.11, 0.23, 0.0);
    glutSetCursor(GLUT_CURSOR_NONE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthFunc(GL_LEQUAL);
    glutWarpPointer(width / 2, height / 2);
}
void bulan() {
    int mboh = 200;
    for (int i = 0; i < 20; i++) {
        glPushMatrix();
        glColor4f(0.82, 0.93, 0.98, 0.1);
        glTranslatef(1255, 1570, -125);
        glutSolidSphere(mboh, 64, 64);
        glPopMatrix();

        mboh += 10;
    }

    glPushMatrix();
    glColor4f(0.82, 0.93, 0.98, 0.02);
    glTranslatef(1255, 1570, -125);
    glutSolidSphere(600, 360, 360);
    glPopMatrix();

    glPushMatrix();
    glColor4f(0.92, 0.96, 0.99, 0.05);
    glTranslatef(1255, 1570, -125);
    glutSolidSphere(11000, 150, 12);
    glPopMatrix();
}
void podiumjalan()
{
    glBegin(GL_POLYGON);        //podium jalan
    glColor3f(0.79, 0.69, 0.63);
    glVertex3f(-266.5, 25.0, -200.0);
    glVertex3f(266.5, 25.0, -200.0);
    glVertex3f(266.5, 25.0, 1000.0);
    glVertex3f(-266.5, 25.0, 1000.0);
    glEnd();

    glBegin(GL_POLYGON);        //podium jalan side depan
    glColor3f(0.7, 0.6, 0.6);
    glVertex3f(266.5, 25.0f, 1000.0f);
    glVertex3f(-266.5, 25.0f, 1000.0f);
    glVertex3f(-266.5, -13.5, 1000.0f);
    glVertex3f(266.5, -13.5, 1000.0f);
    glEnd();

    glBegin(GL_POLYGON);        //podium jalan side kanan
    glColor3f(0.7, 0.6, 0.6);
    glVertex3f(266.5, 25.0, -200.0);
    glVertex3f(266.5, 25.0, 1000.0);
    glVertex3f(266.5, -13.5, 1000.0);
    glVertex3f(266.5, -13.5, -200.0);
    glEnd();

    glBegin(GL_POLYGON);        //podium jalan side kiri
    glColor3f(0.7, 0.6, 0.6);
    glVertex3f(-266.5, 25.0, -200.0);
    glVertex3f(-266.5, 25.0, 1000.0);
    glVertex3f(-266.5, -13.5, 1000.0);
    glVertex3f(-266.5, -13.5, -200.0);
    glEnd();
}
void segitigatangga1() {
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(50.0, 98.0, 450.0);
    glVertex3f(50.0, 25.0, 450.0);
    glVertex3f(50.0, 25.0, 520.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(60.0, 98.0, 450.0);
    glVertex3f(60.0, 25.0, 450.0);
    glVertex3f(60.0, 25.0, 520.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(50.0, 98.0, 450.0);
    glVertex3f(60.0, 98.0, 450.0);
    glVertex3f(60.0, 25.0, 520.0);
    glVertex3f(50.0, 25.0, 520.0);
    glEnd();
}
void tangga() {
    glBegin(GL_POLYGON);
    glColor3f(0.45, 0.45, 0.45);
    glVertex3f(-251.5, 90.0, 440.0);
    glVertex3f(251.5, 90.0, 440.0);
    glVertex3f(251.5, 90.0, 455.0);
    glVertex3f(-251.5, 90.0, 455.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(251.5, 90.0, 455.0);
    glVertex3f(-251.5, 90.0, 455.0);
    glVertex3f(-251.5, 0.0, 455.0);
    glVertex3f(251.5, 0.0, 455.0);
    glEnd();

    //tangga2
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(-251.5, 75.0, 455.0);
    glVertex3f(251.5, 75.0, 455.0);
    glVertex3f(251.5, 75.0, 470.0);
    glVertex3f(-251.5, 75.0, 470.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(251.5, 75.0, 470.0);
    glVertex3f(-251.5, 75.0, 470.0);
    glVertex3f(-251.5, 0.0, 470.0);
    glVertex3f(251.5, 0.0, 470.0);
    glEnd();

    //tangga3
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(-251.5, 60.0, 470.0);
    glVertex3f(251.5, 60.0, 470.0);
    glVertex3f(251.5, 60.0, 485.0);
    glVertex3f(-251.5, 60.0, 485.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(251.5, 60.0, 485.0);
    glVertex3f(-251.5, 60.0, 485.0);
    glVertex3f(-251.5, 0.0, 485.0);
    glVertex3f(251.5, 0.0, 485.0);
    glEnd();

    //tangga4
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(-251.5, 45.0, 485.0);
    glVertex3f(251.5, 45.0, 485.0);
    glVertex3f(251.5, 45.0, 500.0);
    glVertex3f(-251.5, 45.0, 500.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(251.5, 45.0, 500.0);
    glVertex3f(-251.5, 45.0, 500.0);
    glVertex3f(-251.5, 0.0, 500.0);
    glVertex3f(251.5, 0.0, 500.0);
    glEnd();

    //tangga5
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(-251.5, 30.0, 500.0);
    glVertex3f(251.5, 30.0, 500.0);
    glVertex3f(251.5, 30.0, 515.0);
    glVertex3f(-251.5, 30.0, 515.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(251.5, 30.0, 515.0);
    glVertex3f(-251.5, 30.0, 515.0);
    glVertex3f(-251.5, 0.0, 515.0);
    glVertex3f(251.5, 0.0, 515.0);
    glEnd();
}
void segitigatangga2() {
    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(250.5, 26, 581);
    glVertex3f(250.5, -462, 693);
    glVertex3f(250.5, -462, 1004.5);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(232, 26, 581);
    glVertex3f(232, -462, 693);
    glVertex3f(232, -462, 1004.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(232.1, 25, 581);
    glVertex3f(250.9, 25, 581);
    glVertex3f(250.4, -462, 1004.5);
    glVertex3f(231.6, -462, 1004.5);
    glEnd();
}
void tanggabawah()
{
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(-245, 90.0, 420.0);
    glVertex3f(250, 90.0, 420.0);
    glVertex3f(250, 90.0, 455.0);
    glVertex3f(-245, 90.0, 455.0);
    glEnd();
}
void bawahtangga()
{
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(250, 109.5, 440);
    glVertex3f(-245, 109.5, 440);
    glVertex3f(-242, 0, 441.5);
    glVertex3f(253, 0, 441.5);
    glEnd();
}
void tiang() {
    glPushMatrix();
    glColor3f(0.71, 0.11, 0.11);
    glRotatef(90.0f, -1.0f, 0.0f, 0.0f);
    glTranslatef(-390.0, -370.0, 25.0);
    gluCylinder(gluNewQuadric(), 10.0f, 10.0f, 350.0f, 32, 32);
    glPopMatrix();
}
void lampionlantai1() {
    //1 
    glBegin(GL_LINE_LOOP); //tali gantungan
    glColor3f(0, 0, 0);
    glVertex3f(175, 250, 175);
    glVertex3f(175, 215, 175);
    glEnd();
    glPushMatrix();//bola merah
    glColor3f(0.71, 0.11, 0.11);
    glTranslatef(175, 215, 175);
    glRotatef(90.0, 100.0, 0, -1.0);
    glutSolidTorus(10.0, 0.0, 20, 60);
    glEnd();
    glPopMatrix();
    glPushMatrix(); //bola hitam
    glColor4f(0, 0, 0, 0.5);
    glTranslatef(175, 215, 175);
    glRotatef(90.0, 100.0, 0, -1.0);
    glutWireTorus(10.05, 0.0, 20, 12);
    glEnd();
    glPopMatrix();
    glPushMatrix(); //kuning atas
    glColor3f(1, 1, 0);
    glTranslatef(175, 225, 175);
    glRotatef(90, 100, 0, -1.0);
    gluCylinder(gluNewQuadric(), 5.0f, 5.0f, 10.0f, 32, 32);
    glEnd();
    glPopMatrix();
    glPushMatrix(); //kuning bawah
    glColor3f(1, 1, 0);
    glTranslatef(175, 210, 175);
    glRotatef(90, 100, 0, -1.0);
    gluCylinder(gluNewQuadric(), 5.0f, 5.0f, 10.0f, 32, 32);
    glEnd();
    glPopMatrix();
    glPushMatrix(); //kuning bawah 2
    glColor3f(1, 1, 0);
    glTranslatef(175, 210, 175);
    glRotatef(90, 100, 0, -1.0);
    gluCylinder(gluNewQuadric(), 0.5f, 0.5f, 20.0f, 32, 32);
    glEnd();
    glPopMatrix();

}
void lampu_base() {
    glPushMatrix();
    glColor3f(0.71, 0.11, 0.11);
    glRotatef(90.0f, -1.0f, 0.0f, 0.0f);
    glTranslatef(230, -800, 0);
    gluCylinder(gluNewQuadric(), 5.0f, 5.0f, 200.0f, 32, 32);
    glPopMatrix();
}
void lampu_tiang() {
    glPushMatrix();
    glColor3f(0.71, 0.11, 0.11);
    glRotatef(90.0f, -1.0f, 90.0f, 0.0f);
    glTranslatef(0, -100, 0);
    gluCylinder(gluNewQuadric(), 5.0f, 5.0f, 100.0f, 32, 32);
    glPopMatrix();
}
void lampu_lampion() {
    glPushMatrix();
    glColor3f(1, 0.92, 0);
    glTranslatef(0, -100, 0);
    glutSolidSphere(20.0, 30, 30);
    glPopMatrix();

    int nggih = 15;
    for (i = 0; i < 10; i++)
    {
        glPushMatrix();
        glColor4f(1, 0.92, 0, 0.09);
        glTranslatef(0, -100, 0);
        glutSolidSphere(nggih, 30, 30);
        glPopMatrix();

        nggih += 5;
    }
}
void lampu_tali() {
    glPushMatrix();
    glColor3f(0.71, 0.11, 0.11);
    glRotatef(90.0f, -1.0f, 0.0f, 0.0f);
    glTranslatef(0, 0, 0);
    gluCylinder(gluNewQuadric(), 2.0f, 2.0f, 30.0f, 32, 32);
    glPopMatrix();
}
void lampu_lampion_kanan()
{
    glPushMatrix();         //tiang bawah
    glTranslatef(0, -463, 0);
    lampu_base();
    glPopMatrix();

    glPushMatrix();     //tiang horizontal atas
    glTranslatef(154.5, -186, 801);
    lampu_tiang();
    glPopMatrix();

    glPushMatrix();     //tiang 1 kecil
    glTranslatef(170, -311, 800);
    lampu_tali();
    glPopMatrix();

    glPushMatrix();     //bola lampion
    glTranslatef(170, -226, 800);
    lampu_lampion();
    glPopMatrix();

}
void lampu_lampion_kiri()
{
    glPushMatrix();         //tiang bawah
    glTranslatef(0, -463, 0);
    lampu_base();
    glPopMatrix();

    glPushMatrix();     //tiang horizontal atas
    glTranslatef(202.5, -186, 801);
    lampu_tiang();
    glPopMatrix();

    glPushMatrix();     //tiang 1 kecil
    glTranslatef(291.5, -311, 800);
    lampu_tali();
    glPopMatrix();

    glPushMatrix();     //bola lampion
    glTranslatef(291.5, -226, 800);
    lampu_lampion();
    glPopMatrix();

}
void pagar() {
    glPushMatrix();
    glColor3f(0.71, 0.11, 0.11);
    glRotatef(90.0f, -1.0f, 0.0f, 0.0f);
    glTranslatef(0, 0, 0);
    gluCylinder(gluNewQuadric(), 3.0f, 3.0f, 98.0f, 32, 32);
    glPopMatrix();
}
void pagarujung() {
    glPushMatrix();
    glColor3f(0.71, 0.11, 0.11);
    glRotatef(90.0f, -1.0f, 0.0f, 0.0f);
    glTranslatef(0, 0, 0);
    gluCylinder(gluNewQuadric(), 8.0f, 8.0f, 110.0f, 32, 32);
    glPopMatrix();
}
void pagar_turu1() {
    glPushMatrix();
    glColor3f(0.71, 0.11, 0.11);
    glRotatef(180.0f, 0.0f, 90.0f, 0.0f);
    glTranslatef(0, 0, 0);
    gluCylinder(gluNewQuadric(), 3.0f, 3.0f, 1155.0f, 32, 32);
    glPopMatrix();
}
void pagar_turu2() {
    glPushMatrix();
    glColor3f(0.71, 0.11, 0.11);
    glRotatef(90.0f, 0.0f, 90.0f, 0.0f);
    glTranslatef(0, 0, 0);
    gluCylinder(gluNewQuadric(), 3.0f, 3.0f, 1170.0f, 32, 32);
    glPopMatrix();
}
void pagar_turu3() {        //pagar turu buat depan
    glPushMatrix();
    glColor3f(0.71, 0.11, 0.11);
    glRotatef(90.0f, 0.0f, 90.0f, 0.0f);
    glTranslatef(0, 0, 0);
    gluCylinder(gluNewQuadric(), 3.0f, 3.0f, 330.0f, 32, 32);
    glPopMatrix();
}
//------------buat pagr lt2 dst---------
void pagarujunglt2() {
    glPushMatrix();
    glColor3f(0.71, 0.11, 0.11);
    glRotatef(90.0f, -1.0f, 0.0f, 0.0f);
    glTranslatef(0, 0, 0);
    gluCylinder(gluNewQuadric(), 6.0f, 6.0f, 80.0f, 32, 32);
    glPopMatrix();
}
void pagar_turu1lt2() {
    glPushMatrix();
    glColor3f(0.71, 0.11, 0.11);
    glRotatef(180.0f, 0.0f, 90.0f, 0.0f);
    glTranslatef(0, 0, 0);
    gluCylinder(gluNewQuadric(), 2.0f, 2.0f, 845.0f, 32, 32);
    glPopMatrix();
}
void pagar_turu2lt2() {
    glPushMatrix();
    glColor3f(0.71, 0.11, 0.11);
    glRotatef(90.0f, 0.0f, 90.0f, 0.0f);
    glTranslatef(0, 0, 0);
    gluCylinder(gluNewQuadric(), 2.0f, 2.0f, 960.0f, 32, 32);
    glPopMatrix();
}
void pagarisilt2() {
    glPushMatrix();
    glColor3f(0.71, 0.11, 0.11);
    glRotatef(90.0f, -1.0f, 0.0f, 0.0f);
    glTranslatef(0, 0, 0);
    gluCylinder(gluNewQuadric(), 2.0f, 2.0f, 65.0f, 32, 32);
    glPopMatrix();
}
void pagarlt2()
{
    glPushMatrix();
    glTranslatef(482, 373, 411);
    pagarujunglt2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-481, 373, 411);
    pagarujunglt2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-481, 373, -432);
    pagarujunglt2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(482, 373, -432);
    pagarujunglt2();
    glPopMatrix();

    int xpglt2 = 484, zpglt2 = -432;
    for (int i = 0; i <= 1; i++)           //pagar atas kanan kiri
    {
        glPushMatrix();
        glTranslatef(xpglt2, 437, 414);
        pagar_turu1lt2();
        glPopMatrix();

        xpglt2 -= 968;
    }
    for (int j = 0; j <= 1; j++)
    {
        glPushMatrix();                  //pagar atas depan belakang
        glTranslatef(-480, 437, zpglt2);
        pagar_turu2lt2();
        glPopMatrix();

        zpglt2 += 844;
    }
    xpglt2 = 484, zpglt2 = 295.5;
    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j <= 5; j++)
        {
            glPushMatrix();
            glTranslatef(xpglt2, 373, zpglt2);
            pagarisilt2();
            glPopMatrix();

            zpglt2 -= 120;
        }
        zpglt2 = 295.5;
        xpglt2 -= 968;

    }
    xpglt2 = 365, zpglt2 = 412;
    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j <= 6; j++)
        {
            glPushMatrix();
            glTranslatef(xpglt2, 373, zpglt2);
            pagarisilt2();
            glPopMatrix();

            xpglt2 -= 120;
        }
        xpglt2 = 365;
        zpglt2 -= 844.5;
    }
}
void torivertikal()
{
    glPushMatrix();
    glColor3f(0.71, 0.11, 0.11);
    glRotatef(90.0f, -1.0f, 0.0f, 0.0f);
    glTranslatef(-150.0, -950.0, 0.0);
    gluCylinder(gluNewQuadric(), 12.0f, 12.0f, 350.0f, 32, 32);
    glPopMatrix();
}
void torihorizontal()
{
    glPushMatrix();
    glColor3f(0.71, 0.11, 0.11);
    glRotatef(90.0f, -1.0f, 90.0f, 0.0f);
    glTranslatef(-950, 298, -200);
    gluCylinder(gluNewQuadric(), 12.0f, 12.0f, 400.0f, 32, 32);
    glPopMatrix();
}
void kayuDekor() {
    glColor3f(0.71, 0.11, 0.11);
    glutSolidCube(20.0);

}
void kayuDekor2() {
    glColor3f(0.71, 0.11, 0.11);
    glutSolidCube(20.0);

}
void gagangpintu()
{
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(-4, 100, 377);
    glVertex3f(-4, 228.5, 377);
    glVertex3f(3, 228.5, 377);
    glVertex3f(3, 100, 377);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(-19, 158, 377);
    glVertex3f(-19, 174, 377);
    glVertex3f(-12, 174, 377);
    glVertex3f(-12, 158, 377);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(19, 158, 377);
    glVertex3f(19, 174, 377);
    glVertex3f(12, 174, 377);
    glVertex3f(12, 158, 377);
    glEnd();
}
void jendela() {

    glBegin(GL_QUADS);
    glVertex3f(350.0, 430.0, -100.0);
    glVertex3f(350.0, 430.0, -250.0);//lebar, belakang depan, atas
    glVertex3f(250.0, 430.0, -250.0);
    glVertex3f(250.0, 430.0, -100.0);
    glEnd();
}
void dinding() {
    glColor3f(149.0f / 255.0f, 150.0f / 255.0f, 145.0f / 255.0f);
    glutSolidCube(20.0);
}
void jendelaJadi() {
    glPushMatrix();
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glTranslatef(-145, -50, 0);
    glColor3f(149.0f / 255.0f, 150.0f / 255.0f, 145.0f / 255.0f);
    jendela();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glTranslatef(-145, -60, 0);
    glColor3f(149.0f / 255.0f, 150.0f / 255.0f, 145.0f / 255.0f);
    jendela();
    glPopMatrix();


    glPushMatrix();
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glTranslatef(-145, -55, 0);
    glColor3f(149.0f / 255.0f, 150.0f / 255.0f, 145.0f / 255.0f);
    glLineWidth(25.0f);
    glBegin(GL_LINE_STRIP);
    glVertex3f(350.0, 430.0, -100.0);
    glVertex3f(350.0, 430.0, -250.0);//lebar, belakang depan, atas
    glVertex3f(250.0, 430.0, -250.0);
    glVertex3f(250.0, 430.0, -100.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glTranslatef(-145, -51, -50);
    glTranslatef(0, 3, 0);
    glColor3f(15.0f / 255.0f, 247.0f / 255.0f, 77.0f / 255.0f);
    glBegin(GL_QUADS);
    glVertex3f(330.0, 430.0, -90.0);
    glVertex3f(330.0, 430.0, -170.0);//lebar, belakang depan, atas
    glVertex3f(270.0, 430.0, -170.0);
    glVertex3f(270.0, 430.0, -90.0);
    glEnd();
    glPopMatrix();

}
void jendela_lt1() {
    glBegin(GL_POLYGON); //Tembok Depan
    glColor3f(0.3, 0.5, 0.5);
    glVertex3f(130, 200, 371);
    glVertex3f(210, 200, 371);
    glVertex3f(210, 140, 371);
    glVertex3f(130, 140, 371);
    glEnd();

    glBegin(GL_POLYGON); //Tembok Depan
    glColor3f(0.3, 0.5, 0.5);
    glVertex3f(130, 200, 371);
    glVertex3f(170, 230, 371);
    glVertex3f(210, 200, 371);
    glEnd();

}
void jendela_list_lt1() {
    glBegin(GL_POLYGON); //Tembok Depan
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(125, 205, 370.5);
    glVertex3f(215, 205, 370.5);
    glVertex3f(215, 135, 370.5);
    glVertex3f(125, 135, 370.5);
    glEnd();

    glBegin(GL_POLYGON); //Tembok Depan
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(125, 205, 370.5);
    glVertex3f(170, 240, 370.5);
    glVertex3f(215, 205, 370.5);
    glEnd();

}
void jendela_lt2() {

    //Jendela List
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(125, 235, 370.5);
    glVertex3f(235, 235, 370.5);
    glVertex3f(235, 135, 370.5);
    glVertex3f(125, 135, 370.5);
    glEnd();


    //Jendela Dasar
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.5, 0.5);
    glVertex3f(130, 230, 371);
    glVertex3f(230, 230, 371);
    glVertex3f(230, 140, 371);
    glVertex3f(130, 140, 371);
    glEnd();

}
void daun() {
    int gapPohon = 0;
    for (int i = 0; i < 5; i++) {
        glColor3f(9.0f / 255.0f, 70 / 255.0f, 2 / 255.0f);
        glutSolidCone(40.0 - gapPohon, 110.0 + gapPohon, 20, 20);
        gapPohon += 5;
    }
}
void batang() {
    glColor3f(62.0f / 255.0f, 48 / 255.0f, 19 / 255.0f);
    gluCylinder(gluNewQuadric(), 10.0f, 10.0f, 90.0f, 32, 32);
}
void pohon() {
    glPushMatrix();
    glRotatef(90.0, -1.0, 0.0, 0.0);
    glTranslatef(0.0, 9.0, 0.0);
    daun();
    glPopMatrix();
    glPushMatrix();
    glRotatef(90.0, -1.0, 0.0, 0.0);
    glTranslatef(-1.5, 9, -54);
    batang();
    glPopMatrix();
}
void pot() {
    glColor3f(0.62, 0.62, 0.62);
    glutSolidCube(20.0);
}
void exPintu() {
    glColor3f(0.71, 0.11, 0.11);
    glutSolidCube(20.0);
}
void balokDekor() {
    glColor3f(0.71, 0.11, 0.11);
    glutSolidCube(20.0);
}
void allBalok() {
    glPushMatrix();
    glTranslatef(-64.0, -420.5, 793.5);
    glTranslatef(415.5, 0.0, 655.5);
    glTranslatef(-111, 543, -1074);
    glScalef(1.0, 19.0, 0.5);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-64.0, -420.5, 793.5);
    glTranslatef(415.5, 0.0, 655.5);
    glTranslatef(-111, 543, -1074);
    glTranslatef(-484.5, 0, 0);
    glScalef(1.0, 19.0, 0.5);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-64.0, -420.5, 793.5);
    glTranslatef(415.5, 0.0, 655.5);
    glTranslatef(-111, 543, -1074);
    glTranslatef(-484.5, 0, 0);
    glTranslatef(153, 54, 1.5);
    glScalef(1.0, 19.0, 0.5);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-64.0, -420.5, 793.5);
    glTranslatef(415.5, 0.0, 655.5);
    glTranslatef(-111, 543, -1074);
    glTranslatef(-484.5, 0, 0);
    glTranslatef(153, 54, 1.5);
    glTranslatef(181.5, 0, 0);
    glScalef(1.0, 19.0, 0.5);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-64.0, -420.5, 793.5);
    glTranslatef(415.5, 0.0, 655.5);
    glTranslatef(-111, 543, -1074);
    glTranslatef(-484.5, 0.0, 0);
    glScalef(15.0, 0.7, 1.0);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-64.0, -420.5, 793.5);
    glTranslatef(415.5, 0.0, 655.5);
    glTranslatef(-111, 543, -1074);
    glTranslatef(-484.5, 0.0, 0);
    glTranslatef(474, 0, 0);
    glScalef(15.0, 0.7, 1.0);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-64.0, -420.5, 793.5);
    glTranslatef(415.5, 0.0, 655.5);
    glTranslatef(-111, 543, -1074);
    glTranslatef(-484.5, 0.0, 0);
    glTranslatef(246, 178.5, 1.5);
    glScalef(39.0, 0.7, 1.0);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-64.0, -420.5, 793.5);
    glTranslatef(415.5, 0.0, 655.5);
    glTranslatef(-111, 543, -1074);
    glTranslatef(-484.5, 0.0, 0);
    glTranslatef(246, 178.5, 1.5);
    glTranslatef(0, -49.5, 0);
    glScalef(39.0, 0.7, 1.0);
    balokDekor();
    glPopMatrix();
}
void allBalokBelakang() {
    glPushMatrix();
    glTranslatef(-64.0, -420.5, 793.5);
    glTranslatef(415.5, 0.0, 655.5);
    glTranslatef(-111, 543, -1074);
    glTranslatef(-70.5, 0, 0);
    glScalef(1.0, 19.0, 0.5);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-64.0, -420.5, 793.5);
    glTranslatef(415.5, 0.0, 655.5);
    glTranslatef(-111, 543, -1074);
    glTranslatef(-484.5, 0, 0);
    glTranslatef(81, 0, 0);
    glScalef(1.0, 19.0, 0.5);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-64.0, -420.5, 793.5);
    glTranslatef(415.5, 0.0, 655.5);
    glTranslatef(-111, 543, -1074);
    glTranslatef(-484.5, 0.0, 0);
    glTranslatef(246, 178.5, 1.5);
    glScalef(39.0, 0.7, 1.0);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-64.0, -420.5, 793.5);
    glTranslatef(415.5, 0.0, 655.5);
    glTranslatef(-111, 543, -1074);
    glTranslatef(-484.5, 0.0, 0);
    glTranslatef(246, 178.5, 1.5);
    glTranslatef(0, -51, 0);
    glScalef(39.0, 0.7, 1.0);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-64.0, -420.5, 793.5);
    glTranslatef(415.5, 0.0, 655.5);
    glTranslatef(-111, 543, -1074);
    glTranslatef(-484.5, 0.0, 0);
    glTranslatef(246, 178.5, 1.5);
    glTranslatef(0, -51, 0);
    glScalef(39.0, 0.7, 1.0);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-64.0, -420.5, 793.5);
    glTranslatef(415.5, 0.0, 655.5);
    glTranslatef(-111, 543, -1074);
    glTranslatef(-484.5, 0.0, 0);
    glTranslatef(246, 178.5, 1.5);
    glTranslatef(0, -126, 0);
    glTranslatef(0, -51, 0);
    glScalef(39.0, 0.7, 1.0);
    balokDekor();
    glPopMatrix();

}
void allBalok2() {
    //samping v
    glPushMatrix();
    glTranslatef(381, 136.5, -7.5);
    glTranslatef(12, 25, -3);
    glTranslatef(0, 39, -70.5);
    glScalef(0.5, 10.0, 1.0);
    glTranslatef(-1.5, 0, -58.5);
    balokDekor();
    glPopMatrix();

    //samping v
    glPushMatrix();
    glTranslatef(381, 136.5, -7.5);
    glTranslatef(12, 25, -3);
    glTranslatef(0, 39, -70.5);
    glTranslatef(0, 0, 192);
    glTranslatef(0, 0, 13.5);
    glScalef(0.5, 10.0, 1.0);
    balokDekor();
    glPopMatrix();

    //samping h
    glPushMatrix();
    glTranslatef(381, 136.5, -7.5);
    glTranslatef(12, 25, -3);
    glTranslatef(0, 39, -70.5);
    glTranslatef(0, -81, 69);
    glScalef(1.0, 0.7, 38.0);
    balokDekor();
    glPopMatrix();

    //samping h
    glPushMatrix();
    glTranslatef(381, 136.5, -7.5);
    glTranslatef(12, 25, -3);
    glTranslatef(0, 39, -70.5);
    glTranslatef(0, -81, 69);
    glTranslatef(-1.5, 126, 0);
    glScalef(1.0, 0.7, 38.0);
    balokDekor();
    glPopMatrix();

    //samping h
    glPushMatrix();
    glTranslatef(381, 136.5, -7.5);
    glTranslatef(12, 25, -3);
    glTranslatef(0, 39, -70.5);
    glTranslatef(0, -81, 69);
    glTranslatef(-1.5, 126, 0);
    glTranslatef(0, 51, 16.5);
    glScalef(1.0, 0.7, 38.0);
    balokDekor();
    glPopMatrix();
}
void dekorDepanLt2() {
    glPushMatrix();
    glTranslatef(0, 636, 279);
    glTranslatef(0, -10.5, 0);
    glTranslatef(-202.5, -160.5, 0);
    glScalef(12.0, 0.7, 1.0);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 636, 279);
    glTranslatef(0, -10.5, 0);
    glTranslatef(-202.5, -160.5, 0);
    glTranslatef(406.5, 0, 0);
    glScalef(12.0, 0.7, 1.0);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 636, 279);
    glTranslatef(0, -10.5, 0);
    glTranslatef(1.5, -22.5, 0);
    glTranslatef(0, -3, -1.5);
    glTranslatef(0, 24, 0);
    glScalef(33.0, 0.7, 0.7);
    balokDekor();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0, 636, 279);
    glTranslatef(0, -10.5, 0);
    glScalef(33.0, 0.7, 1.0);
    glTranslatef(0, 33, 0);
    glTranslatef(0, 58.5, 0);
    glTranslatef(0, -91.5, -2.5);
    glTranslatef(0, 94.5, -0.5);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(73.5, 493.5, 313.5);
    glTranslatef(3, 0, 5.5);
    glTranslatef(0, 15, -40);
    glScalef(1.0, 17.7, 0.7);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(73.5, 493.5, 313.5);
    glTranslatef(3, 0, 5.5);
    glTranslatef(-151.5, 0, 0);
    glTranslatef(0, 15, -40);
    glScalef(1.0, 17.7, 0.7);
    balokDekor();
    glPopMatrix();
}
void dekorBelakangLt2() {

    glPushMatrix();
    glTranslatef(0, 636, 279);
    glTranslatef(0, -10.5, 0);
    glTranslatef(0, 0, 6.5);
    glScalef(33.0, 0.7, 1.0);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 636, 279);
    glTranslatef(0, -10.5, 0);
    glScalef(33.0, 1.0, 1.0);
    glTranslatef(0, 33, 0);
    glTranslatef(0, 58.5, 0);
    glTranslatef(0, -24, 6.5);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 636, 279);
    glTranslatef(0, -10.5, 0);
    glScalef(33.0, 1.0, 1.0);
    glTranslatef(0, 33, 0);
    glTranslatef(0, 58.5, 0);
    glTranslatef(0, -24, 6.5);
    glTranslatef(0, -226.5, 0);
    balokDekor();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0, 636, 279);
    glTranslatef(0, -10.5, 0);
    glScalef(33.0, 1.0, 1.0);
    glTranslatef(0, 33, 0);
    glTranslatef(0, 58.5, 0);
    glTranslatef(0, -322.5, 0);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(162, 516, 288);
    glScalef(1.0, 19.7, 1.0);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(162, 516, 288);
    glTranslatef(-328.5, 0, 0);
    glScalef(1.0, 19.7, 1.0);
    balokDekor();
    glPopMatrix();
}
void dekorDepanLt2Samping() {
    glPushMatrix();
    glTranslatef(0, 636, 279);
    glTranslatef(0, -10.5, 0);
    glTranslatef(-202.5, -160.5, 0);
    glTranslatef(-402, 0, 0);
    glTranslatef(270, 96, -154.5);
    glTranslatef(0, 13.5, 0);
    glScalef(0.5, 12.7, 1.0);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 636, 279);
    glTranslatef(0, -10.5, 0);
    glTranslatef(-202.5, -160.5, 0);
    glTranslatef(-402, 0, 0);
    glTranslatef(270, 96, -154.5);
    glTranslatef(0, 13.5, 0);
    glTranslatef(1.5, 0, -253.5);
    glScalef(0.5, 12.7, 1.0);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 636, 279);
    glTranslatef(0, -10.5, 0);
    glTranslatef(-202.5, -160.5, 0);
    glTranslatef(-402, 0, 0);
    glTranslatef(270, 96, -154.5);
    glTranslatef(0, 13.5, 0);
    glTranslatef(1.5, 0, -253.5);
    glTranslatef(4.5, -111, 121.5);
    glScalef(1.0, 0.7, 29.0);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 636, 279);
    glTranslatef(0, -10.5, 0);
    glTranslatef(-202.5, -160.5, 0);
    glTranslatef(-402, 0, 0);
    glTranslatef(270, 96, -154.5);
    glTranslatef(0, 13.5, 0);
    glTranslatef(1.5, 0, -253.5);
    glTranslatef(4.5, -111, 121.5);
    glTranslatef(0, 160.5, 0);
    glScalef(1.0, 0.7, 29.0);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 636, 279);
    glTranslatef(0, -10.5, 0);
    glTranslatef(-202.5, -160.5, 0);
    glTranslatef(-402, 0, 0);
    glTranslatef(270, 96, -154.5);
    glTranslatef(0, 13.5, 0);
    glTranslatef(1.5, 0, -253.5);
    glTranslatef(4.5, -111, 121.5);
    glTranslatef(0, 160.5, 0);
    glTranslatef(0, 19.5, 0);
    glScalef(1.0, 0.7, 29.0);
    glTranslatef(0, 69, 0);
    balokDekor();
    glPopMatrix();
}
void AllBaloklt3() {
    glPushMatrix();
    glTranslatef(0, 819, 243);
    glTranslatef(184.5, -33, -19.5);
    glTranslatef(-9, -3, -6);
    glScalef(11.0, 0.5, 0.7);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 819, 243);
    glTranslatef(184.5, -33, -19.5);
    glTranslatef(-9, -3, -6);
    glScalef(11.0, 0.5, 0.7);
    glTranslatef(-31.5, 0, 0);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 819, 243);
    glTranslatef(184.5, -33, -19.5);
    glTranslatef(-9, -3, -6);
    glTranslatef(0, 115.5, 0);
    glTranslatef(736.5, 3, 0);
    glScalef(29.0, 0.5, 0.7);
    glTranslatef(-31.5, 0, 0);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 819, 243);
    glTranslatef(184.5, -33, -19.5);
    glTranslatef(-9, -3, -6);
    glTranslatef(0, 115.5, 0);
    glTranslatef(736.5, 3, 0);
    glTranslatef(0, 36, 0);
    glScalef(29.0, 0.5, 0.7);
    glTranslatef(-31.5, 0, 0);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(162, 516, 288);
    glTranslatef(-328.5, 0, 0);
    glTranslatef(99, 340.5, -80);
    glScalef(1.0, 9.7, 1.0);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(162, 516, 288);
    glTranslatef(-328.5, 0, 0);
    glTranslatef(99, 340.5, -80);
    glTranslatef(136.5, 0, 0);
    glScalef(1.0, 9.7, 1.0);
    balokDekor();
    glPopMatrix();
}
void AllBaloklt3Belakang() {

    glPushMatrix();
    glTranslatef(0, 819, 243);
    glTranslatef(184.5, -33, -19.5);
    glTranslatef(-9, -3, -6);
    glTranslatef(0, 115.5, 0);
    glTranslatef(736.5, 3, 0);
    glScalef(29.0, 0.7, 1.0);
    glTranslatef(-31.5, 0, 0);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 819, 243);
    glTranslatef(184.5, -33, -19.5);
    glTranslatef(-9, -3, -6);
    glTranslatef(0, 115.5, 0);
    glTranslatef(736.5, 3, 0);
    glTranslatef(0, 36, 0);
    glTranslatef(-1.5, 3, 0);
    glScalef(29.0, 0.7, 1.0);
    glTranslatef(-31.5, 0, 0);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 819, 243);
    glTranslatef(184.5, -33, -19.5);
    glTranslatef(-9, -3, -6);
    glTranslatef(0, 115.5, 0);
    glTranslatef(736.5, 3, 0);
    glTranslatef(0, 36, 0);
    glTranslatef(-1.5, 3, 0);
    glTranslatef(0, -154.5, 0);
    glScalef(29.0, 0.7, 1.0);
    glTranslatef(-31.5, 0, 0);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(154.5, 781.5, 222);
    glTranslatef(-309, 0, 3);
    glTranslatef(-6, 0, 0);
    glScalef(1.0, 16.0, 1.0);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(154.5, 781.5, 222);
    glTranslatef(-309, 0, 3);
    glTranslatef(-6, 0, 0);
    glTranslatef(318, 0, 0);
    glScalef(1.0, 16.0, 1.0);
    balokDekor();
    glPopMatrix();

}
void AllBaloklt3Samping() {
    glPushMatrix();
    glTranslatef(0, 0, 871.5);
    glTranslatef(-282, 780, -756);
    glScalef(0.5, 16.7, 1.0);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 871.5);
    glTranslatef(-282, 780, -756);
    glScalef(0.5, 16.7, 1.0);
    glTranslatef(0, 0, -241.5);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 871.5);
    glTranslatef(-282, 780, -756);
    glTranslatef(0, 0, -120);
    glScalef(0.5, 0.7, 22.6);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 871.5);
    glTranslatef(-282, 780, -756);
    glTranslatef(0, 0, -120);
    glTranslatef(0, 123, 0);
    glScalef(0.5, 0.7, 22.6);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 871.5);
    glTranslatef(-282, 780, -756);
    glTranslatef(0, 0, -120);
    glTranslatef(0, 123, 0);
    glTranslatef(0, 36, 0);
    glScalef(0.5, 0.7, 22.6);
    balokDekor();
    glPopMatrix();
}
void AllBaloklt4() {
    glPushMatrix();
    glTranslatef(235.5, 1063.5, 150);
    glTranslatef(-84, 3, 0);
    glScalef(9.0, 0.7, 1.0);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(235.5, 1063.5, 150);
    glTranslatef(-84, 3, 0);
    glTranslatef(-301.5, 0, 0);
    glScalef(9.0, 0.7, 1.0);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(235.5, 1063.5, 150);
    glTranslatef(-84, 3, 0);
    glTranslatef(-301.5, 0, 0);
    glTranslatef(147, 166.5, 0);
    glScalef(23.7, 0.7, 1.0);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(235.5, 1063.5, 150);
    glTranslatef(-84, 3, 0);
    glTranslatef(-301.5, 0, 0);
    glTranslatef(147, 166.5, 0);
    glScalef(23.7, 0.7, 1.0);
    glTranslatef(0, 81, 0);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(73.5, 493.5, 313.5);
    glTranslatef(3, 0, 5.5);
    glTranslatef(-151.5, 0, 0);
    glTranslatef(0, 15, -40);
    glTranslatef(16.5, 676.5, -127);
    glScalef(1.0, 13.7, 0.7);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(73.5, 493.5, 313.5);
    glTranslatef(3, 0, 5.5);
    glTranslatef(-151.5, 0, 0);
    glTranslatef(0, 15, -40);
    glTranslatef(16.5, 676.5, -127);
    glTranslatef(117, 0, 0);
    glScalef(1.0, 13.7, 0.7);
    balokDekor();
    glPopMatrix();
}
void AllBaloklt4Belakang() {
    glPushMatrix();
    glTranslatef(235.5, 1063.5, 150);
    glTranslatef(-84, 3, 0);
    glTranslatef(-301.5, 0, 0);
    glTranslatef(147, 166.5, 0);
    glTranslatef(0, -226.5, 0);
    glScalef(23.7, 0.7, 1.0);
    glTranslatef(0, 81, 0);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(235.5, 1063.5, 150);
    glTranslatef(-84, 3, 0);
    glTranslatef(-301.5, 0, 0);
    glTranslatef(147, 166.5, 0);
    glScalef(23.7, 0.7, 1.0);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(235.5, 1063.5, 150);
    glTranslatef(-84, 3, 0);
    glTranslatef(-301.5, 0, 0);
    glTranslatef(147, 166.5, 0);
    glScalef(23.7, 0.7, 1.0);
    glTranslatef(0, 81, 0);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 88.5, -202.5);
    glTranslatef(148.5, 1066.5, 345);
    glTranslatef(0, 0, 9);
    glScalef(1.0, 12.7, 1.0);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 88.5, -202.5);
    glTranslatef(148.5, 1066.5, 345);
    glTranslatef(-312, 0, 0);
    glTranslatef(0, 0, 9);
    glScalef(1.0, 12.7, 1.0);
    balokDekor();
    glPopMatrix();
}
void AllBaloklt4Samping() {
    glPushMatrix();
    glTranslatef(238.5, 1060.5, -19.5);
    glScalef(1.0, 0.7, 16.0);
    glTranslatef(0, 7.5, 1);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(238.5, 1060.5, -19.5);
    glScalef(1.0, 0.7, 16.0);
    glTranslatef(0, 7.5, 1);
    glTranslatef(0, 238.5, 0);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(238.5, 1060.5, -19.5);
    glScalef(1.0, 0.7, 16.0);
    glTranslatef(0, 7.5, 1);
    glTranslatef(0, 238.5, 0);
    glTranslatef(0, 82.5, 0);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(238.5, 1060.5, -19.5);
    glTranslatef(-3, 106.5, 132.5);
    glScalef(0.7, 12.0, 1.0);
    balokDekor();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(238.5, 1060.5, -19.5);
    glTranslatef(-3, 106.5, 132.5);
    glTranslatef(0, 0, -243);
    glScalef(0.7, 12.0, 1.0);
    balokDekor();
    glPopMatrix();
}

void ground() {
    glBegin(GL_QUADS);
    glColor3f(0.19, 0.63, 0.13);
    glVertex3f(-1000.0, -500, -1000.0);

    glColor3f(0.19, 0.63, 0.13);
    glVertex3f(1000.0, -500, -1000.0);

    glColor3f(0.19, 0.63, 0.13);
    glVertex3f(1000.0, -500, 1500.0);

    glColor3f(0.19, 0.63, 0.13);
    glVertex3f(-1000.0, -500, 1500.0);
    glEnd();
}
void bangunan() {
    //-----------------------------------------------------Tembok Lantai 1---------------------------------------------------------
    glBegin(GL_POLYGON); //Tembok Belakang
    glColor3f(0.95, 0.83, 0.83);
    glVertex3f(400.0, 350, -390.0);
    glVertex3f(-400.0, 350, -390.0);
    glVertex3f(-400.0, 98.0, -390.0);
    glVertex3f(400.0, 98.0, -390.0);
    glEnd();

    glBegin(GL_POLYGON); //Tembok Depan
    glColor3f(0.95, 0.83, 0.83);
    glVertex3f(400.0, 350, 370.0);
    glVertex3f(-400.0, 350, 370.0);
    glVertex3f(-400.0, 98.0, 370.0);
    glVertex3f(400.0, 98.0, 370.0);
    glEnd();

    glBegin(GL_POLYGON); //Tembok Kanan
    glColor3f(0.95, 0.83, 0.83);
    glVertex3f(390.0, 350, -390.0);
    glVertex3f(390.0, 350, 370.0);
    glVertex3f(390.0, 98.0, 370.0);
    glVertex3f(390.0, 98.0, -390.0);
    glEnd();

    glBegin(GL_POLYGON); //Tembok Kiri
    glColor3f(0.95, 0.83, 0.83);
    glVertex3f(-390.0, 350, -390.0);
    glVertex3f(-390.0, 350, 370.0);
    glVertex3f(-390.0, 98.0, 370.0);
    glVertex3f(-390.0, 98.0, -390.0);
    glEnd();

    //-----------------------------------------------------lampion bawah atap---------------------------------------------------------
    int xlam = -1000, zlam = -116.5;

    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            glPushMatrix();
            glTranslatef(xlam, -381, zlam); -657,
                glScalef(3, 3, 3);
            lampionlantai1();
            glPopMatrix();

            zlam -= 840;
        }
        zlam = -116.5;
        xlam += 940;
    }
    //-----------------------------------------------------Jendela Lantai 1---------------------------------------------------------
    //Jendela Kanan 1
    glPushMatrix();
    jendela_list_lt1();
    jendela_lt1();
    glPopMatrix();

    //Jendela Kanan 2
    glPushMatrix();
    glTranslatef(150, 0, 0);
    jendela_list_lt1();
    jendela_lt1();
    glPopMatrix();

    //Jendela Kiri 1
    glPushMatrix();
    glTranslatef(-340, 0, 0);
    jendela_list_lt1();
    jendela_lt1();
    glPopMatrix();

    //Jendela Kiri 2
    glPushMatrix();
    glTranslatef(-490, 0, 0);
    jendela_list_lt1();
    jendela_lt1();
    glPopMatrix();


    //-------------------pintu-------------


    //-----------------------------------------------------Podium tingkat 2--------------------------------------------------------
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-450.0, 98.0, 430.0);
    glVertex3f(450.0, 98.0, 430.0);
    glVertex3f(450.0, 98.0, -450.0);
    glVertex3f(-450.0, 98.0, -450.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-450.0, 98.0, 450.0);
    glVertex3f(-251.5, 98.0, 450.0);
    glVertex3f(-251.5, 98.0, 430.0);
    glVertex3f(-450.0, 98.0, 430.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(248.5, 98.0, 450.0);
    glVertex3f(450.0, 98.0, 450.0);
    glVertex3f(450.0, 98.0, 430.0);
    glVertex3f(248.5, 98.0, 430.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(-440.0, 99.0, 440.0);
    glVertex3f(440.0, 99.0, 440.0);
    glVertex3f(440.0, 99.0, -440.0);
    glVertex3f(-440.0, 99.0, -440.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-400.0, 100.0, 380.0);
    glVertex3f(400.0, 100.0, 380.0);
    glVertex3f(400.0, 100.0, -400.0);
    glVertex3f(-400.0, 100.0, -400.0);
    glEnd();


    //podium tingkat 2 side kanan
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(450.0, 98.0, -450.0);
    glVertex3f(450.0, 98.0, 450.0);
    glVertex3f(450.0, -98.0, 450.0);
    glVertex3f(450.0, -98.0, -450.0);
    glEnd();

    //podium tingkat 2 side kiri
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-450.0, 98.0, -450.0);
    glVertex3f(-450.0, 98.0, 450.0);
    glVertex3f(-450.0, 0.0, 450.0);
    glVertex3f(-450.0, 0.0, -450.0);
    glEnd();

    //podium tingkat 2 side depan

    glBegin(GL_POLYGON);    //kiri
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-251.5, 98.0, 450.0);
    glVertex3f(-450.0, 98.0, 450.0);
    glVertex3f(-450.0, 0.0, 450.0);
    glVertex3f(-251.5, 0.0, 450.0);
    glEnd();

    glBegin(GL_POLYGON);    //kanan 2
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(450.0, 98.0, 450.0);
    glVertex3f(251.5, 98.0, 450.0);
    glVertex3f(251.5, 0.0, 450.0);
    glVertex3f(450.0, 0.0, 450.0);
    glEnd();

    glBegin(GL_POLYGON); //side depan tengah masuk
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(251.5, 99.0, 440.0);
    glVertex3f(-251.5, 99.0, 440.0);
    glVertex3f(-251.5, 0.0, 440.0);
    glVertex3f(251.5, 0.0, 440.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-251.5, 98.0, 430.0);
    glVertex3f(-251.5, 98.0, 450.0);
    glVertex3f(-251.5, 0.0, 450.0);
    glVertex3f(-251.5, 0.0, 430.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(248.5, 98.0, 430.0);
    glVertex3f(248.5, 98.0, 450.0);
    glVertex3f(248.5, -98.0, 450.0);
    glVertex3f(248.5, -98.0, 430.0);
    glEnd();

    //podium tingkat 2 side belakang
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(450.0, 98.0, -450.0);
    glVertex3f(-450.0, 98.0, -450.0);
    glVertex3f(-450.0, 0.0, -450.0);
    glVertex3f(450.0, 0.0, -450.0);
    glEnd();

    //------------------------------------------------------------tiang------------------------------------------------------------
    glPushMatrix();     //tiang 1
    glTranslatef(0, 0, 0);
    tiang();
    glPopMatrix();

    glPushMatrix();     //tiang 2
    glTranslatef(780, 0, 0);
    tiang();
    glPopMatrix();

    glPushMatrix();     //tiang 3
    glTranslatef(0, 0, -760);
    tiang();
    glPopMatrix();

    glPushMatrix();     //tiang 4
    glTranslatef(780, 0, -760);
    tiang();
    glPopMatrix();


    //-----------------------------------------------------Atap Lantai 1---------------------------------------------------------
    //Sisi Bawah Atap
    glPushMatrix();
    glTranslatef(0, 250.0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.16, 0.08);
    glVertex3f(-500.0, 100.0, 430.0);
    glVertex3f(500.0, 100.0, 430.0);
    glVertex3f(500.0, 100.0, -450.0);
    glVertex3f(-500.0, 100.0, -450.0);
    glEnd();
    glPopMatrix();

    //Sisi Atas Atap
    glPushMatrix();
    glTranslatef(0, 275.0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-500.0, 100.0, 430.0);
    glVertex3f(500.0, 100.0, 430.0);
    glVertex3f(500.0, 100.0, -450.0);
    glVertex3f(-500.0, 100.0, -450.0);
    glEnd();
    glPopMatrix();

    //Sisi Kanan Atap
    glPushMatrix();
    glTranslatef(0, 275.0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.71, 0.11, 0.11);
    glVertex3f(500.0, 100.0, -450.0);
    glVertex3f(500.0, 100.0, 430.0);
    glVertex3f(500.0, 75.0, 430.0);
    glVertex3f(500.0, 75.0, -450.0);
    glEnd();
    glPopMatrix();

    //Sisi Kiri Atap
    glPushMatrix();
    glTranslatef(0, 275.0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.71, 0.11, 0.11);
    glVertex3f(-500.0, 100.0, -450.0);
    glVertex3f(-500.0, 100.0, 430.0);
    glVertex3f(-500.0, 75.0, 430.0);
    glVertex3f(-500.0, 75.0, -450.0);
    glEnd();
    glPopMatrix();

    //Sisi Depan Atap
    glPushMatrix();
    glTranslatef(0, 275, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.71, 0.11, 0.11);
    glVertex3f(500.0, 100.0, 430.0);
    glVertex3f(-500.0, 100.0, 430.0);
    glVertex3f(-500.0, 75.0, 430.0);
    glVertex3f(500.0, 75.0, 430.0);
    glEnd();
    glPopMatrix();

    //Sisi Belakang Atap
    glPushMatrix();
    glTranslatef(0, 275.0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.71, 0.11, 0.11);
    glVertex3f(500.0, 100.0, -450.0);
    glVertex3f(-500.0, 100.0, -450.0);
    glVertex3f(-500.0, 75.0, -450.0);
    glVertex3f(500.0, 75.0, -450.0);
    glEnd();
    glPopMatrix();

    //Atap Penutup Depan Miring
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.16, 0.08);
    glVertex3f(500.0, 350, 430.0);
    glVertex3f(-500.0, 350, 430.0);
    glVertex3f(-400.0, 300, 370.0);
    glVertex3f(400, 300, 370.0);
    glEnd();


    //Atap Penutup Belakang Miring
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.16, 0.08);
    glVertex3f(500.0, 350, -450.0);
    glVertex3f(-500.0, 350, -450.0);
    glVertex3f(-390.0, 300, -390.0);
    glVertex3f(390, 300, -390.0);
    glEnd();

    //Atap Penutup Kanan Miring
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.16, 0.08);
    glVertex3f(500.0, 350, -450.0);
    glVertex3f(500.0, 350, 430.0);
    glVertex3f(390.0, 300, 370.0);
    glVertex3f(390.0, 300, -390.0);
    glEnd();

    //Atap Penutup Kiri Miring
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.16, 0.08);
    glVertex3f(-500.0, 350, -450.0);
    glVertex3f(-500.0, 350, 430.0);
    glVertex3f(-390.0, 300, 370.0);
    glVertex3f(-390.0, 300, -390.0);
    glEnd();

    glPushMatrix();         //teko 
    glColor3f(0.84, 0, 0);
    glTranslatef(0, 169, -141);
    glutSolidTeapot(100);
    glPopMatrix();

}

void bangunan2() {



    //-----------------------------------------------------Tembok Lantai 2---------------------------------------------------------
    glBegin(GL_POLYGON); //Tembok Belakang
    glColor3f(0.95, 0.83, 0.83);
    glVertex3f(400.0, 350, -390.0);
    glVertex3f(-400.0, 350, -390.0);
    glVertex3f(-400.0, 98.0, -390.0);
    glVertex3f(400.0, 98.0, -390.0);
    glEnd();

    glBegin(GL_POLYGON); //Tembok Depan
    glColor3f(0.95, 0.83, 0.83);
    glVertex3f(400.0, 350, 370.0);
    glVertex3f(-400.0, 350, 370.0);
    glVertex3f(-400.0, 98.0, 370.0);
    glVertex3f(400.0, 98.0, 370.0);
    glEnd();

    glBegin(GL_POLYGON); //Tembok Kanan
    glColor3f(0.95, 0.83, 0.83);
    glVertex3f(390.0, 350, -390.0);
    glVertex3f(390.0, 350, 370.0);
    glVertex3f(390.0, 98.0, 370.0);
    glVertex3f(390.0, 98.0, -390.0);
    glEnd();

    glBegin(GL_POLYGON); //Tembok Kiri
    glColor3f(0.95, 0.83, 0.83);
    glVertex3f(-390.0, 350, -390.0);
    glVertex3f(-390.0, 350, 370.0);
    glVertex3f(-390.0, 98.0, 370.0);
    glVertex3f(-390.0, 98.0, -390.0);
    glEnd();

    //-----------------------------------------------------Jendela ---------------------------------------------------------
    //Jendela Kanan 1
    glPushMatrix();
    jendela_lt2();
    glPopMatrix();

    //Jendela Kanan 2
    glPushMatrix();
    glTranslatef(130, 0, 0);
    jendela_lt2();
    glPopMatrix();

    //Jendela Kiri 1
    glPushMatrix();
    glTranslatef(-360, 0, 0);
    jendela_lt2();
    glPopMatrix();

    //Jendela Kiri 2
    glPushMatrix();
    glTranslatef(-490, 0, 0);
    jendela_lt2();
    glPopMatrix();


    //-------------------pintu-------------

    //-----------------------------------------------------Podium tingkat 2--------------------------------------------------------
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(-450.0, 98.0, 450.0);
    glVertex3f(450.0, 98.0, 450.0);
    glVertex3f(450.0, 98.0, -450.0);
    glVertex3f(-450.0, 98.0, -450.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(-440.0, 99.0, 440.0);
    glVertex3f(440.0, 99.0, 440.0);
    glVertex3f(440.0, 99.0, -440.0);
    glVertex3f(-440.0, 99.0, -440.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-400.0, 100.0, 380.0);
    glVertex3f(400.0, 100.0, 380.0);
    glVertex3f(400.0, 100.0, -400.0);
    glVertex3f(-400.0, 100.0, -400.0);
    glEnd();


    //podium tingkat 2 side kanan
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(450.0, 98.0, -450.0);
    glVertex3f(450.0, 98.0, 450.0);
    glVertex3f(450.0, 0, 450.0);
    glVertex3f(450.0, 0, -450.0);
    glEnd();

    //podium tingkat 2 side kiri
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-450.0, 98.0, -450.0);
    glVertex3f(-450.0, 98.0, 450.0);
    glVertex3f(-450.0, 0.0, 450.0);
    glVertex3f(-450.0, 0.0, -450.0);
    glEnd();

    //podium tingkat 2 side depan

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(450.0, 98.0, 450.0);
    glVertex3f(-450, 98.0, 450.0);
    glVertex3f(-450, 0.0, 450.0);
    glVertex3f(450.0, 0.0, 450.0);
    glEnd();


    //podium tingkat 2 side belakang
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(450.0, 98.0, -450.0);
    glVertex3f(-450.0, 98.0, -450.0);
    glVertex3f(-450.0, 0.0, -450.0);
    glVertex3f(450.0, 0.0, -450.0);
    glEnd();

    //------------------------------------------------------------tiang------------------------------------------------------------
    glPushMatrix();     //tiang 1
    glTranslatef(0, 0, 0);
    tiang();
    glPopMatrix();

    glPushMatrix();     //tiang 2
    glTranslatef(780, 0, 0);
    tiang();
    glPopMatrix();

    glPushMatrix();     //tiang 3
    glTranslatef(0, 0, -760);
    tiang();
    glPopMatrix();

    glPushMatrix();     //tiang 4
    glTranslatef(780, 0, -760);
    tiang();
    glPopMatrix();


    //-----------------------------------------------------lampion bawah atap---------------------------------------------------------
    int xlam = -1000, zlam = -116.5;

    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            glPushMatrix();
            glTranslatef(xlam, -381, zlam); -657,
                glScalef(3, 3, 3);
            lampionlantai1();
            glPopMatrix();

            zlam -= 840;
        }
        zlam = -116.5;
        xlam += 940;
    }

    //-----------------------------------------------------Atap Lantai 2---------------------------------------------------------
    //Sisi Bawah Atap
    glPushMatrix();
    glTranslatef(0, 250.0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.16, 0.08);
    glVertex3f(-500.0, 100.0, 430.0);
    glVertex3f(500.0, 100.0, 430.0);
    glVertex3f(500.0, 100.0, -450.0);
    glVertex3f(-500.0, 100.0, -450.0);
    glEnd();
    glPopMatrix();

    //Sisi Atas Atap
    glPushMatrix();
    glTranslatef(0, 275.0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.6, 0.6);
    glVertex3f(-500.0, 100.0, 430.0);
    glVertex3f(500.0, 100.0, 430.0);
    glVertex3f(500.0, 100.0, -450.0);
    glVertex3f(-500.0, 100.0, -450.0);
    glEnd();
    glPopMatrix();

    //Sisi Kanan Atap
    glPushMatrix();
    glTranslatef(0, 275.0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.71, 0.11, 0.11);
    glVertex3f(500.0, 100.0, -450.0);
    glVertex3f(500.0, 100.0, 430.0);
    glVertex3f(500.0, 75.0, 430.0);
    glVertex3f(500.0, 75.0, -450.0);
    glEnd();
    glPopMatrix();

    //Sisi Kiri Atap
    glPushMatrix();
    glTranslatef(0, 275.0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.71, 0.11, 0.11);
    glVertex3f(-500.0, 100.0, -450.0);
    glVertex3f(-500.0, 100.0, 430.0);
    glVertex3f(-500.0, 75.0, 430.0);
    glVertex3f(-500.0, 75.0, -450.0);
    glEnd();
    glPopMatrix();

    //Sisi Depan Atap
    glPushMatrix();
    glTranslatef(0, 275, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.71, 0.11, 0.11);
    glVertex3f(500.0, 100.0, 430.0);
    glVertex3f(-500.0, 100.0, 430.0);
    glVertex3f(-500.0, 75.0, 430.0);
    glVertex3f(500.0, 75.0, 430.0);
    glEnd();
    glPopMatrix();

    //Sisi Belakang Atap
    glPushMatrix();
    glTranslatef(0, 275.0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.15, 0.71, 0.67);
    glVertex3f(500.0, 100.0, -450.0);
    glVertex3f(-500.0, 100.0, -450.0);
    glVertex3f(-500.0, 75.0, -450.0);
    glVertex3f(500.0, 75.0, -450.0);
    glEnd();
    glPopMatrix();

    //Atap Miring Depan
    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.65, 0.62);
    glVertex3f(500.0, 355, 430.0);
    glVertex3f(-500.0, 355, 430.0);
    glVertex3f(-620.0, 300, 550.0);
    glVertex3f(620.0, 300, 550.0);
    glEnd();

    //Atap Miring Belakang
    glBegin(GL_POLYGON);
    glColor3f(0.15, 0.71, 0.67);
    glVertex3f(500.0, 355, -450.0);
    glVertex3f(-500.0, 355, -450.0);
    glVertex3f(-620.0, 300, -570.0);
    glVertex3f(620.0, 300, -570.0);
    glEnd();

    //Atap Miring Kanan
    glBegin(GL_POLYGON);
    glColor3f(0.15, 0.71, 0.67);
    glVertex3f(500.5, 355, -450.0);
    glVertex3f(500.5, 355, 430.5);
    glVertex3f(620.0, 300, 550.0);
    glVertex3f(620.0, 300, -570.0);
    glEnd();

    //Atap Miring Kiri
    glBegin(GL_POLYGON);
    glColor3f(0.11, 0.63, 0.6);
    glVertex3f(-500.5, 355, -450.0);
    glVertex3f(-500.5, 355, 430.5);
    glVertex3f(-620.0, 300, 550.0);
    glVertex3f(-620.0, 300, -570.0);
    glEnd();

}

void draw() {

    glPushMatrix();
    bulan();
    glPopMatrix();

    ground();
    //-----------------------------------------------tanaman------------------------------------------
    int gapPohon = 0;
    for (int i = 0; i < 3; i++) {
        glPushMatrix();
        glTranslatef(-744.0 + gapPohon, -420.5, 793.5);
        pohon();
        glPopMatrix();
        gapPohon += 200;
    }
    int gapPohon1 = 0;
    for (int i = 0; i < 3; i++) {
        glPushMatrix();
        glTranslatef(344.0 + gapPohon1, -420.5, 793.5);
        pohon();
        glPopMatrix();
        gapPohon1 += 200;
    }
    int gapPot = 0;
    for (int i = 0; i < 3; i++) {
        glPushMatrix();
        glTranslatef(-744.0 + gapPot, -490.0, 784.5);
        glScalef(4.5, 1.0, 3.0);
        pot();
        glPopMatrix();
        gapPot += 200;
    }

    int gapPot1 = 0;
    for (int i = 0; i < 3; i++) {
        glPushMatrix();
        glTranslatef(344.0 + gapPot1, -490.0, 784.5);
        glScalef(4.5, 1.0, 3.0);
        pot();
        glPopMatrix();
        gapPot1 += 200;
    }

    glPushMatrix();
    glTranslatef(-744.0, -420.5, 793.5);
    glTranslatef(415.5, 0.0, 655.5);
    pohon();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-64.0, -420.5, 793.5);
    glTranslatef(415.5, 0.0, 655.5);
    pohon();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-744.0, -480.0, 784.5);
    glTranslatef(414.0, 0.0, 657.0);
    glScalef(4.5, 1.0, 3.0);
    pot();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-64.0, -490.0, 784.5);
    glTranslatef(414.0, 0.0, 657.0);
    glScalef(4.5, 1.0, 3.0);
    pot();
    glPopMatrix();

    //---------------------------------------------------------------Dekorasi Dinding lt1--------------------------------------------------
   //depan
    glPushMatrix();
    glTranslatef(0, 0, -3);
    allBalok();
    glPopMatrix();

    //belakang v
    glPushMatrix();
    glTranslatef(-64.0, -490.0, 784.5);
    glTranslatef(414.0, 0.0, 657.0);
    glTranslatef(-352.5, 490.5, -2205);
    allBalokBelakang();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-1.5, 4.5, -4.5);
    allBalok2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-783, 1.5, 0);
    glTranslatef(-1.5, 3, -3);
    allBalok2();
    glPopMatrix();

    //=================================Akhir Dekorasi Dinding lt1=====================================
    glPushMatrix();
    dekorDepanLt2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, -576);
    dekorBelakangLt2();
    glPopMatrix();

    //SAMPING
    glPushMatrix();
    dekorDepanLt2Samping();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(661.5, 0, 0);
    dekorDepanLt2Samping();
    glPopMatrix();

    //===========================

    glPushMatrix();
    AllBaloklt3();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5, -1.5, -442.5);
    AllBaloklt3Belakang();
    glPopMatrix();

    glPushMatrix();
    AllBaloklt3Samping();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(567, 0, 0);
    AllBaloklt3Samping();
    glPopMatrix();

    //===
    glPushMatrix();
    AllBaloklt4();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, -307.5);
    AllBaloklt4Belakang();
    glPopMatrix();

    glPushMatrix();
    AllBaloklt4Samping();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-474, 1.5, 0);
    AllBaloklt4Samping();
    glPopMatrix();

    //=================================Pintu =====================================

    glPushMatrix();
    glTranslatef(0, 0, 0);
    gagangpintu();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-744.0, -420.5, 793.5);
    glTranslatef(754.5, 562.5, -427.5);
    glTranslatef(-10.5, 0.0, 0.0);
    glScalef(7.0, 8.7, 1.0);
    exPintu();
    glPopMatrix();

    //lt2

    glPushMatrix();
    glTranslatef(0, 352.5, -92);
    gagangpintu();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-744.0, -420.5, 793.5);
    glTranslatef(754.5, 562.5, -427.5);
    glTranslatef(-10.5, 0.0, 0.0);
    glTranslatef(0, 363, -91.5);
    glScalef(6.0, 7.7, 1.0);
    exPintu();
    glPopMatrix();

    //lt3
    glPushMatrix();
    glTranslatef(0, 630, -159.5);
    gagangpintu();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-744.0, -420.5, 793.5);
    glTranslatef(754.5, 562.5, -427.5);
    glTranslatef(-10.5, 0.0, 0.0);
    glTranslatef(0, 363, -91.5);
    glTranslatef(0, 286.5, -67.5);
    glScalef(5.0, 6.7, 1.0);
    exPintu();
    glPopMatrix();

    //lt4
    glPushMatrix();
    glTranslatef(0, 949.5, -220.5);
    gagangpintu();

    glPopMatrix();
    glPushMatrix();
    glTranslatef(-744.0, -420.5, 793.5);
    glTranslatef(754.5, 562.5, -427.5);
    glTranslatef(-10.5, 0.0, 0.0);
    glTranslatef(0, 363, -91.5);
    glTranslatef(0, 286.5, -67.5);
    glTranslatef(0, 321, -61);
    glScalef(4.0, 6.7, 1.0);
    exPintu();
    glPopMatrix();

    //-----------------------------------------------------Base bukit bawah--------------------------------------------------------
    glBegin(GL_POLYGON);        //depan
    glColor3f(0.35, 0.35, 0.35);
    glVertex3f(600.0f, 0.0f, 580.0);
    glVertex3f(-600.0f, 0.0f, 580.0);
    glVertex3f(-800.0f, -500.0f, 700.0);
    glVertex3f(800.0f, -500.0f, 700.0);
    glEnd();

    glBegin(GL_POLYGON);        //belakang
    glColor3f(0.36, 0.36, 0.36);
    glVertex3f(600.0f, 0.0f, -600.0);
    glVertex3f(-600.0f, 0.0f, -600.0);
    glVertex3f(-800.0f, -500.0f, -700.0);
    glVertex3f(800.0f, -500.0f, -700.0);
    glEnd();

    glBegin(GL_POLYGON);        //kiri
    glColor3f(0.31, 0.31, 0.31);
    glVertex3f(-600.0, 0.0, -600.0);
    glVertex3f(-600.0, 0.0, 580.0);
    glVertex3f(-800, -500.0, 700);
    glVertex3f(-800.0, -500.0, -700.0);
    glEnd();

    glBegin(GL_POLYGON);        //kanan
    glColor3f(0.36, 0.36, 0.36);
    glVertex3f(600.0, 0.0, -600.0);
    glVertex3f(600.0, 0.0, 580.0);
    glVertex3f(800, -500.0, 700);
    glVertex3f(800.0, -500.0, -700.0);
    glEnd();

    //-----------------------------------------------------LANTAI 1--------------------------------------------------------
    //-----------------------------------------------------Podium tingkat 1--------------------------------------------------------
    glBegin(GL_POLYGON);
    glColor3f(0.62, 0.62, 0.62);
    glVertex3f(-600.0, 25.0, 580.0);
    glVertex3f(600.0, 25.0, 580.0);
    glVertex3f(600.0, 25.0, -600.0);
    glVertex3f(-600.0, 25.0, -600.0);
    glEnd();
    //-----------------------------------------------------gerbang--------------------------------------------------------
    int xtori = 0, ytori = -471;
    for (int i = 0; i <= 1; i++)
    {
        glPushMatrix(); //kiri
        glTranslatef(xtori, -468, 538.5);
        torivertikal();
        glPopMatrix();

        xtori += 300;
    }

    for (int i = 0; i <= 1; i++)
    {
        glPushMatrix(); //kiri
        glTranslatef(0, ytori, 542);
        torihorizontal();
        glPopMatrix();

        ytori += 50;
    }

    //--------------------------------------------------------- Lampu Lampion ------------------------------------------------------------
    glBegin(GL_POLYGON);        //podium 1 side kanan
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(600.0, 25.0, -600.0);
    glVertex3f(600.0, 25.0, 580.0);
    glVertex3f(600.0, -25.0, 580.0);
    glVertex3f(600.0, -25.0, -600.0);
    glEnd();

    glBegin(GL_POLYGON);        //podium 1 side kiri
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-600.0, 25.0, -600.0);
    glVertex3f(-600.0, 25.0, 580.0);
    glVertex3f(-600.0, -25.0, 580.0);
    glVertex3f(-600.0, -25.0, -600.0);
    glEnd();

    glBegin(GL_POLYGON);        //podium 1 side depan
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(600.0f, 25.0f, 580.0);
    glVertex3f(-600.0f, 25.0f, 580.0);
    glVertex3f(-600.0f, 0.0f, 580.0);
    glVertex3f(600.0f, 0.0f, 580.0);
    glEnd();

    glBegin(GL_POLYGON);        //podium 1 side belakang
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(600.0f, 25.0f, -600.0f);
    glVertex3f(-600.0f, 25.0f, -600.0f);
    glVertex3f(-600.0f, 0.0f, -600.0f);
    glVertex3f(600.0f, 0.0f, -600.0f);
    glEnd();

    glPushMatrix();
    glTranslatef(1.5, -487, 501);
    podiumjalan();
    glPopMatrix();

    //-----------------------------------------------------pagar--------------------------------------------------------
    glPushMatrix();
    glTranslatef(256.5, 25, 570);
    pagarujung();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-256.5, 25, 570);
    pagarujung();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(590, 25, 570);
    pagarujung();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-590, 25, 570);
    pagarujung();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(590, 25, -590);
    pagarujung();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-590, 25, -590);
    pagarujung();
    glPopMatrix();

    int xpagaratas = 590, ypagaratas = 125;
    for (int i = 0; i <= 1; i++)         //pagar atas kanan kiri
    {
        for (int j = 0; j <= 1; j++)
        {
            glPushMatrix();
            glTranslatef(xpagaratas, ypagaratas, 570);
            pagar_turu1();
            glPopMatrix();

            ypagaratas -= 60;
        }
        ypagaratas = 125;
        xpagaratas -= 1180;
    }

    for (int j = 0; j <= 1; j++)
    {
        glPushMatrix();                     //pagar atas belakang
        glTranslatef(-588, ypagaratas, -589.5);
        pagar_turu2();
        glPopMatrix();

        ypagaratas -= 60;
    }
    ypagaratas = 125;
    xpagaratas = -583;
    for (int i = 0; i <= 1; i++)           //pagar atas double depan
    {
        for (int j = 0; j <= 1; j++)
        {
            glPushMatrix();
            glTranslatef(xpagaratas, ypagaratas, 570);
            pagar_turu3();
            glPopMatrix();

            ypagaratas -= 60;
        }
        ypagaratas = 125;
        xpagaratas += 847;
    }
    int xpagardepan = -474, ypagardepan = 25, zpagardepan = 570;
    for (int i = 0; i <= 2; i++)           //pagar double depan
    {
        for (int j = 0; j <= 1; j++)
        {
            glPushMatrix();
            glTranslatef(xpagardepan, ypagardepan, zpagardepan);
            pagar();
            glPopMatrix();

            xpagardepan += 116;
        }
        xpagardepan = -474;
        xpagardepan += 840;
    }
    int xpagar = 590, ypagar = 25, zpagar = 570;
    for (int i = 0; i <= 1; i++)         //pagar kanan kiri
    {
        for (int j = 0; j <= 10; j++)
        {
            glPushMatrix();
            glTranslatef(xpagar, ypagar, zpagar);
            pagar();
            glPopMatrix();
            zpagar -= 116;
        }
        zpagar = 570;
        xpagar -= 1180;
    }
    xpagar = 590;
    for (int j = 0; j <= 10; j++)//pagar belakang
    {
        glPushMatrix();
        glTranslatef(xpagar, 25, -590);
        pagar();
        glPopMatrix();
        xpagar -= 118;
    }

    //------------------------------------------------------------tangga atas------------------------------------------------------------
    glPushMatrix();     //segitiga tangga kiri
    glTranslatef(-311.5, 0, 0);
    segitigatangga1();
    glPopMatrix();

    glPushMatrix();     //segitiga tangga kanan
    glTranslatef(198.5, 0, 0);
    segitigatangga1();
    glPopMatrix();

    glPushMatrix();     //tangga tengah
    glTranslatef(0, 0, 0);
    tangga();
    glPopMatrix();

    //------------------------------------------------------------tangga bawah------------------------------------------------------------
    glPushMatrix();     //segitiga tangga kiri
    glTranslatef(16.5, 0, 0);
    segitigatangga2();
    glPopMatrix();

    glPushMatrix();     //segitiga tangga kanan
    glTranslatef(-496, 0, 0);
    segitigatangga2();
    glPopMatrix();

    int ytb = -87, ztb = 142.5;
    int ybt = -106.5, zbt = 157.5;
    for (int i = 0; i <= 11; i++)
    {
        glPushMatrix();     //tangga tengah
        glTranslatef(0, ytb, ztb);
        tanggabawah();
        glPopMatrix();

        glPushMatrix();     //bawahtangga
        glTranslatef(1.5, ybt, zbt);
        bawahtangga();
        glPopMatrix();

        ytb -= 40;
        ybt -= 40;
        ztb += 35;
        zbt += 35;
    }
    //--------------------LAMPU LAMPION----------------//
    int zlam = 270;
    for (int i = 0; i <= 2; i++)
    {
        glPushMatrix(); //lampu kanan
        glTranslatef(28.5, 0, zlam);
        lampu_lampion_kanan();
        glPopMatrix();

        glPushMatrix(); //lampu kiri
        glTranslatef(-486, 0, zlam);
        lampu_lampion_kiri();
        glPopMatrix();

        zlam += 150;
    }
    //------------------------------------------------------------Bangunan lt1------------------------------------------------------------
    glPushMatrix();     //tiang 1
    glTranslatef(0, 0, 0);
    pagarlt2();
    bangunan();
    glPopMatrix();
    //------------------------------------------------------------Bangunan lt2------------------------------------------------------------
    glPushMatrix();
    glScalef(0.85, 1, 0.75);
    glTranslatef(0, 350, 0);
    pagarlt2();
    bangunan2();
    glPopMatrix();

    //------------------------------------------------------------Bangunan lt3------------------------------------------------------------
    glPushMatrix();
    glScalef(0.73, 0.7, 0.58);
    glTranslatef(0, 1000, 0);
    pagarlt2();
    bangunan2();
    glPopMatrix();

    //------------------------------------------------------------Bangunan lt4------------------------------------------------------------
    glPushMatrix();
    glScalef(0.62, 1, 0.42);
    glTranslatef(0, 950, 0);
    bangunan2();
    glPopMatrix();

    //------------------------------------------------------------Atap Banget-----------------------------------------------------
    //BOX atap
    glPushMatrix();
    glColor3f(0.73, 0.55, 0.05);
    glTranslatef(0, 1600, 0);
    glutSolidCube(150.0);
    glPopMatrix();

    //Atap Miring Depan
    glBegin(GL_POLYGON);
    glColor3f(0.13, 0.65, 0.62);
    glVertex3f(75.0, 1600, 75);
    glVertex3f(-75.0, 1600, 75);
    glVertex3f(-384.5, 1250, 231.0);
    glVertex3f(384.5, 1250, 231.0);
    glEnd();

    //Atap Miring Belakang
    glBegin(GL_POLYGON);
    glColor3f(0.15, 0.71, 0.67);
    glVertex3f(75.0, 1600, -75);
    glVertex3f(-75.0, 1600, -75);
    glVertex3f(-383, 1250, -237);
    glVertex3f(384.5, 1250, -240.0);
    glEnd();

    //Atap Miring Kanan
    glBegin(GL_POLYGON);
    glColor3f(0.16, 0.72, 0.68);
    glVertex3f(75, 1600, -75.0);
    glVertex3f(75, 1600, 75.0);
    glVertex3f(384.5, 1250, 231.0);
    glVertex3f(384.5, 1250, -240);
    glEnd();

    //Atap Miring kiri
    glBegin(GL_POLYGON);
    glColor3f(0.11, 0.63, 0.6);
    glVertex3f(-75, 1600, -75.0);
    glVertex3f(-75, 1600, 75.0);
    glVertex3f(-384.5, 1250, 231.0);
    glVertex3f(-384.5, 1250, -240);
    glEnd();

    //Silinder Tengah Cube
    glPushMatrix();
    glColor3f(0.71, 0.11, 0.11);
    glTranslatef(0, 1600, 0);
    glRotatef(90.0f, -1.0f, 0.0f, 0.0f);
    gluCylinder(gluNewQuadric(), 10.0f, 10.0f, 300.0f, 32, 32);
    glPopMatrix();

    //Donut Di Tengah Silinder
    int ydonat = 1730;
    int ldonat = 20;
    for (int i = 0; i <= 3; i++) {
        //Silinder Tengah Cube
        glPushMatrix();
        glColor3f(1, 1, 1);
        glTranslatef(0, ydonat, 0);
        glRotatef(90.0f, -1.0f, 0.0f, 0.0f);
        glutSolidTorus(10.0, ldonat, 20, 4);
        glPopMatrix();

        ydonat += 50;
        ldonat -= 5;
    }

    //Sphere Di Ujung Atas
    //Silinder Tengah Cube
    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(0, 1920, 0);
    glRotatef(90.0f, -1.0f, 0.0f, 0.0f);
    glutSolidSphere(30.0, 30, 30);
    glPopMatrix();

    cout << x_geser << ", " << y_geser << ", " << z_geser << endl;
    glFlush();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    camera();
    draw();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50, 16.0 / 9.0, 2, 10000);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int) {
    glutPostRedisplay();
    glutWarpPointer(width / 2, height / 2);
    glutTimerFunc(1000 / FPS, timer, 0);
}

void passive_motion(int x, int y) {
    int dev_x, dev_y;
    dev_x = (width / 2) - x;
    dev_y = (height / 2) - y;
    yaw += (float)dev_x / 20.0;
    pitch += (float)dev_y / 20.0;
}

void camera() {
    if (motion.Forward) {
        camX += cos((yaw + 90) * TO_RADIANS) * 2;
        camZ -= sin((yaw + 90) * TO_RADIANS) * 2;
    }
    if (motion.Backward) {
        camX += cos((yaw + 90 + 180) * TO_RADIANS) * 2;
        camZ -= sin((yaw + 90 + 180) * TO_RADIANS) * 2;
    }
    if (motion.Left) {
        camX += cos((yaw + 90 + 90) * TO_RADIANS) * 2;
        camZ -= sin((yaw + 90 + 90) * TO_RADIANS) * 2;
    }
    if (motion.Right) {
        camX += cos((yaw + 90 - 90) * TO_RADIANS) * 2;
        camZ -= sin((yaw + 90 - 90) * TO_RADIANS) * 2;
    }
    if (motion.Naik) {
        terbang -= 2.0;
    }
    if (motion.Turun) {
        terbang += 2.0;
    }

    if (pitch >= 70)
        pitch = 70;
    if (pitch <= -90)
        pitch = -90;

    glRotatef(-pitch, 1.0, 0.0, 0.0);
    glRotatef(-yaw, 0.0, 1.0, 0.0);

    glTranslatef(-camX, -terbang, -350 - camZ);
    if (terbang < 25 - 500)
        terbang = 24 - 500;
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'W':
    case 'w':
        motion.Forward = true;
        break;
    case 'A':
    case 'a':
        motion.Left = true;
        break;
    case 'S':
    case 's':
        motion.Backward = true;
        break;
    case 'D':
    case 'd':
        motion.Right = true;
        break;
    case 'E':
    case 'e':
        motion.Naik = true;
        break;
    case 'Q':
    case 'q':
        motion.Turun = true;
        break;
    case '6':
        x_geser += 1.5;
        break;
    case '4':
        x_geser -= 1.5;
        break;
    case '9':
        y_geser += 1.5;
        break;
    case '3':
        y_geser -= 1.5;
        break;
    case '8':
        z_geser -= 1.5;
        break;
    case '5':
        z_geser += 0.5;
        break;
    case '`': // KELUAR DARI PROGRAM
        exit(1);
    }
}

void keyboard_up(unsigned char key, int x, int y) {
    switch (key) {
    case 'W':
    case 'w':
        motion.Forward = false;
        break;
    case 'A':
    case 'a':
        motion.Left = false;
        break;
    case 'S':
    case 's':
        motion.Backward = false;
        break;
    case 'D':
    case 'd':
        motion.Right = false;
        break;
    case 'E':
    case 'e':
        motion.Naik = false;
        break;
    case 'Q':
    case 'q':
        motion.Turun = false;
        break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(100, 50);
    glutCreateWindow("TR GRAFKOM KELOMPOK X");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutPassiveMotionFunc(passive_motion);
    glutTimerFunc(0, timer, 0);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboard_up);

    glutMainLoop();
    return 0;
}
