#include <GL/gl.h> //Import library yang akan digunakan
#include <GL/glu.h> //Import library yang akan digunakan
#include <GL/glut.h> //Import library yang akan digunakan
#include <math.h> //import rumus matematika
const double PI = 3.142857143;
int i,radius,jumlah_titik,x_tengah,y_tengah;

void displayMe(void) //yang akan ditampilkan
{
    glClear(GL_COLOR_BUFFER_BIT); //membersihkan frame

    glBegin(GL_POLYGON); //tanah kiri 1
    glColor3f(1, 1, 0);
    glVertex2f(0,0);
    glVertex2f(8,0);
    glVertex2f(8,18);
    glVertex2f(4,22);
    glVertex2f(0,22);
    glEnd();

    glBegin(GL_POLYGON); //tanah kiri 2
    glColor3f(1, 1, 0);
    glVertex2f(8,0);
    glVertex2f(16,0);
    glVertex2f(22,14);
    glVertex2f(22,18);
    glVertex2f(8,18);
    glEnd();

    glBegin(GL_POLYGON); //air bawah
    glColor3f(0.5, 1, 1);
    glVertex2f(16,0);
    glVertex2f(70,0);
    glVertex2f(64,14);
    glVertex2f(22,14);
    glEnd();

    glBegin(GL_POLYGON); //tanah kanan 2
    glColor3f(1, 1, 0);
    glVertex2f(70,0);
    glVertex2f(78,0);
    glVertex2f(78,18);
    glVertex2f(64,18);
    glVertex2f(64,14);
    glEnd();

    glBegin(GL_POLYGON); //tanah kanan 1
    glColor3f(1, 1, 0);
    glVertex2f(78,0);
    glVertex2f(100,0);
    glVertex2f(100,22);
    glVertex2f(82,22);
    glVertex2f(78,18);
    glEnd();

    glBegin(GL_QUADS); //penyanggah jembatan kanan
    glColor3f(0, 0, 0);
    glVertex2f(64,18);
    glVertex2f(66,18);
    glVertex2f(66,26);
    glVertex2f(64,26);
    glEnd();

    glBegin(GL_LINES); //tali jembatan kanan
    glColor3f(1, 1, 1);
    glVertex2f(64,20);
    glVertex2f(66,20);

    glVertex2f(64,21);
    glVertex2f(66,21);

    glVertex2f(64,22);
    glVertex2f(66,22);
    glEnd();

    glBegin(GL_QUADS); //pijakan jembatan
    glColor3f(0.5, 0, 0);
    glVertex2f(22,20);
    glVertex2f(64,20);
    glVertex2f(64,22);
    glVertex2f(22,22);
    glEnd();

    glBegin(GL_QUADS); //penyanggah jembatan kiri
    glColor3f(0, 0, 0);
    glVertex2f(20,18);
    glVertex2f(22,18);
    glVertex2f(22,26);
    glVertex2f(20,26);
    glEnd();

    glBegin(GL_LINES); //tali jembatan kiri
    glColor3f(1, 1, 1);
    glVertex2f(20,20);
    glVertex2f(22,20);

    glVertex2f(20,21);
    glVertex2f(22,21);

    glVertex2f(20,22);
    glVertex2f(22,22);
    glEnd();

    glBegin(GL_POLYGON); //ombak 1 kiri
    glColor3f(0.5, 1, 1);
    glVertex2f(22,14);
    glVertex2f(30,14);
    glVertex2f(28,18);
    glVertex2f(24,18);
    glEnd();

    glBegin(GL_POLYGON); //ombak 2
    glColor3f(0.5, 1, 1);
    glVertex2f(30,14);
    glVertex2f(38,14);
    glVertex2f(36,18);
    glVertex2f(32,18);
    glEnd();

    glBegin(GL_POLYGON); //ombak 3
    glColor3f(0.5, 1, 1);
    glVertex2f(38,14);
    glVertex2f(46,14);
    glVertex2f(44,18);
    glVertex2f(40,18);
    glEnd();

    glBegin(GL_POLYGON); //ombak 4
    glColor3f(0.5, 1, 1);
    glVertex2f(46,14);
    glVertex2f(54,14);
    glVertex2f(52,18);
    glVertex2f(48,18);
    glEnd();

    glBegin(GL_POLYGON); //ombak 5
    glColor3f(0.5, 1, 1);
    glVertex2f(54,14);
    glVertex2f(62,14);
    glVertex2f(60,18);
    glVertex2f(56,18);
    glEnd();

    glBegin(GL_TRIANGLES); //ombak 6
    glColor3f(0.5, 1, 1);
    glVertex2f(62,14);
    glVertex2f(64,14);
    glVertex2f(64,18);
    glEnd();

    glBegin(GL_QUADS); //batang pohon
    glColor3f(1, 1, 1);
    glVertex2f(84,22);
    glVertex2f(90,22);
    glVertex2f(90,32);
    glVertex2f(84,32);
    glEnd();

    glBegin(GL_TRIANGLES); //daun cemara
    glColor3f(0, 1, 0);
    glVertex2f(78,28);
    glVertex2f(96,28);
    glVertex2f(87,36);
    glEnd();

    glBegin(GL_TRIANGLES); //daun cemara
    glColor3f(0, 1, 0);
    glVertex2f(78,34);
    glVertex2f(96,34);
    glVertex2f(87,42);
    glEnd();

    glBegin(GL_TRIANGLES); //daun cemara
    glColor3f(0, 1, 0);
    glVertex2f(78,40);
    glVertex2f(96,40);
    glVertex2f(87,48);
    glEnd();

    glBegin(GL_QUADS); //kaki domba
    glColor3f(0, 0, 0);
    glVertex2f(19,18.3);
    glVertex2f(18.5,18.3);
    glVertex2f(18.5,20);
    glVertex2f(19,20);
    glEnd();

    glBegin(GL_QUADS); //kaki domba
    glColor3f(0, 0, 0);
    glVertex2f(18.2,18.3);
    glVertex2f(17.7,18.3);
    glVertex2f(17.7,20);
    glVertex2f(18.2,20);
    glEnd();

    glBegin(GL_QUADS); //kaki domba
    glColor3f(0, 0, 0);
    glVertex2f(15,18.3);
    glVertex2f(15.5,18.3);
    glVertex2f(15.5,20);
    glVertex2f(15,20);
    glEnd();

    glBegin(GL_QUADS); //kaki domba
    glColor3f(0, 0, 0);
    glVertex2f(14.7,18.3);
    glVertex2f(14.2,18.3);
    glVertex2f(14.2,20);
    glVertex2f(14.7,20);
    glEnd();

    glBegin(GL_POLYGON); //domba
    glColor3f(1,1,1);//untuk warna domba
       radius = 250;
       jumlah_titik = 60;
       x_tengah = 800;
       y_tengah = 2200;

       for (i=0;i<=360;i++)
       {
              float sudut=i*(2*PI/jumlah_titik);
              float x=x_tengah+radius*cos (sudut);
              float y=y_tengah+radius*sin (sudut);
              glVertex2f(x/50,y/100);
       }
    glEnd();

    glBegin(GL_POLYGON); //kepala domba
    glColor3f(0,0,0);
       radius = 140;
       jumlah_titik = 60;
       x_tengah = 850;
       y_tengah = 2000;

       for (i=0;i<=360;i++)
       {
              float sudut=i*(2*PI/jumlah_titik);
              float x=x_tengah+radius*cos (sudut);
              float y=y_tengah+radius*sin (sudut);
              glVertex2f(x/80,y/90);
       }
    glEnd();

    glBegin(GL_POLYGON); //mata domba
    glColor3f(1,1,1);//untuk warna domba
       radius = 35;
       jumlah_titik = 60;
       x_tengah = 970;
       y_tengah = 2260;

       for (i=0;i<=360;i++)
       {
              float sudut=i*(2*PI/jumlah_titik);
              float x=x_tengah+radius*cos (sudut);
              float y=y_tengah+radius*sin (sudut);
              glVertex2f(x/100,y/100);
       }
    glEnd();

    glBegin(GL_POLYGON); //mata domba
    glColor3f(0,0,0);//untuk warna domba
       radius = 20;
       jumlah_titik = 60;
       x_tengah = 970;
       y_tengah = 2260;

       for (i=0;i<=360;i++)
       {
              float sudut=i*(2*PI/jumlah_titik);
              float x=x_tengah+radius*cos (sudut);
              float y=y_tengah+radius*sin (sudut);
              glVertex2f(x/100,y/100);
       }
    glEnd();

    glBegin(GL_POLYGON); //mata domba
    glColor3f(1,1,1);//untuk warna domba
       radius = 35;
       jumlah_titik = 60;
       x_tengah = 1100;
       y_tengah = 2260;

       for (i=0;i<=360;i++)
       {
              float sudut=i*(2*PI/jumlah_titik);
              float x=x_tengah+radius*cos (sudut);
              float y=y_tengah+radius*sin (sudut);
              glVertex2f(x/100,y/100);
       }
    glEnd();

    glBegin(GL_POLYGON); //mata domba
    glColor3f(0,0,0);//untuk warna domba
       radius = 20;
       jumlah_titik = 60;
       x_tengah = 1100;
       y_tengah = 2260;

       for (i=0;i<=360;i++)
       {
              float sudut=i*(2*PI/jumlah_titik);
              float x=x_tengah+radius*cos (sudut);
              float y=y_tengah+radius*sin (sudut);
              glVertex2f(x/100,y/100);
       }
    glEnd();

    glBegin(GL_POLYGON); //ekor
    glColor3f(1,1,1);
       radius = 50;
       jumlah_titik = 60;
       x_tengah = 1500;
       y_tengah = 2600;

       for (i=0;i<=360;i++)
       {
              float sudut=i*(2*PI/jumlah_titik);
              float x=x_tengah+radius*cos (sudut);
              float y=y_tengah+radius*sin (sudut);
              glVertex2f(x/70,y/120);
       }
    glEnd();

    glBegin(GL_POLYGON); //telinga
    glColor3f(0,0,0);
       radius = 40;
       jumlah_titik = 60;
       x_tengah = 640;
       y_tengah = 2330;

       for (i=0;i<=360;i++)
       {
              float sudut=i*(2*PI/jumlah_titik);
              float x=x_tengah+radius*cos (sudut);
              float y=y_tengah+radius*sin (sudut);
              glVertex2f(x/50,y/100);
       }
    glEnd();

    glBegin(GL_POLYGON); //telinga
    glColor3f(0,0,0);
       radius = 40;
       jumlah_titik = 60;
       x_tengah = 420;
       y_tengah = 2330;

       for (i=0;i<=360;i++)
       {
              float sudut=i*(2*PI/jumlah_titik);
              float x=x_tengah+radius*cos (sudut);
              float y=y_tengah+radius*sin (sudut);
              glVertex2f(x/50,y/100);
       }
    glEnd();

	glutSwapBuffers();
}
void petani(void)
{
	glBegin(GL_POLYGON); //Sepatu
    glColor3f(0.5, 1, 1);
    glVertex2f(60,20);
    glVertex2f(60,20.5);
    glVertex2f(59,20.5);
    glVertex2f(58.5,20);

    glVertex2f(58.5,20);
    glVertex2f(58.5,20.5);
    glVertex2f(57.5,20.5);
    glVertex2f(57,20);
    glEnd();

    glBegin(GL_POLYGON); //Celana
    glColor3f(0.5, 1, 1);
    glVertex2f(60,20.5);
    glVertex2f(58.5,22);
    glVertex2f(59.5,24);
    glVertex2f(57.5,24);
    glVertex2f(56.5,22);
    glVertex2f(57.5,20.5);
    glVertex2f(58.5,20.5);
    glVertex2f(57.5,22);
    glEnd();

    glBegin(GL_POLYGON); //Tangan
    glColor3f(0.5, 1, 1);
    glVertex2f(56.4,25.1);
    glVertex2f(56.2,24.8);
    glVertex2f(56.3,24.6);
    glVertex2f(56.2,24.4);
    glVertex2f(56,24.3);
    glVertex2f(55.8,24.3);
    glVertex2f(55.6,24.4);
    glVertex2f(55.4,24.6);
    glVertex2f(55.3,24.8);
    glVertex2f(55.3,25);
    glVertex2f(55.4,25.2);
    glVertex2f(55.6,25.3);
    glVertex2f(55.8,25.2);
    glVertex2f(56.1,25.4);
    glEnd();

    glBegin(GL_POLYGON); //Baju
    glColor3f(0.5, 1, 1);
    glVertex2f(59.5,24);
    glVertex2f(59,27);
    glVertex2f(58,27);
    glVertex2f(57.5,24);

    glVertex2f(58,27);
    glVertex2f(58,26.5);
    glVertex2f(56.5,25);
    glVertex2f(56,25.5);
    glEnd();

    glBegin(GL_POLYGON); // Kepala
    glColor3f(0.5, 1, 1);
    glVertex2f(58.9,27.2);
    glVertex2f(58.9,27.4);
    glVertex2f(59.2,27.5);
    glVertex2f(59.4,27.7);
    glVertex2f(59.5,27.9);
    glVertex2f(59.5,28.3);
    glVertex2f(59.4,28.5);
    glVertex2f(59.2,28.7);
    glVertex2f(58,28.7);
    glVertex2f(57.8,28.5);
    glVertex2f(57.7,28.3);
    glVertex2f(57.7,27.9);
    glVertex2f(57.8,27.7);
    glVertex2f(58,27.5);
    glVertex2f(58.3,27.4);
    glVertex2f(58.3,27.2);
    glEnd();

    glBegin(GL_POLYGON); // Topi
    glColor3f(0.5, 1, 1);
    glVertex2f(57,28.7);
    glVertex2f(58.7,24.9);
    glVertex2f(60,28.7);
    glEnd();

    glBegin(GL_POLYGON); // Mata
    glColor3f(0.5, 1, 1);
    glVertex2f(57.9,28.4);
    glVertex2f(58.1,28.4);
    glVertex2f(58.2,28.3);
    glVertex2f(58.2,28.4);
    glVertex2f(58.1,28);
    glVertex2f(58.9,28);
    glVertex2f(57.8,28.1);
    glVertex2f(57.8,28.3);
    glEnd();

    glBegin(GL_POLYGON); // Bola Mata
    glColor3f(0.5, 1, 1);
    glVertex2f(58,28.3);
    glVertex2f(58.1,28.2);
    glVertex2f(58,28.1);
    glVertex2f(57.9,28.2);
    glEnd();

    glBegin(GL_POLYGON); // Mulut
    glColor3f(0.5, 1, 1);
    glVertex2f(57.7,27.9);
    glVertex2f(58,27.85);
    glVertex2f(58.15,27.9);
    glVertex2f(58,27.75);
    glVertex2f(57.8,27.7);
    glEnd();
}

void utama()
{
    displayMe();

    petani();

    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); //atur display
	glutInitWindowSize(1000, 700); //ukurann display
	glutInitWindowPosition(180,0); //posisi display
	glutCreateWindow("Tugas"); //membuat window
	glutDisplayFunc(utama); //memanggil display
	glClearColor(0,0,1,1);
	gluOrtho2D(0, 100, 0, 50); //mengatur proyeksi hasil eksekusi
	glutMainLoop();
	return 0;
}
