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
    glVertex2f(-10,0);
    glVertex2f(8,0);
    glVertex2f(8,18);
    glVertex2f(4,22);
    glVertex2f(-10,22);
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

    glVertex2f(64,19);
    glVertex2f(66,19);

    glVertex2f(64,21);
    glVertex2f(66,21);
    glEnd();

    glBegin(GL_QUADS); //pijakan jembatan
    glColor3f(0.5, 0, 0);
    glVertex2f(22,19);
    glVertex2f(64,19);
    glVertex2f(64,21);
    glVertex2f(22,21);
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

    glVertex2f(20,19);
    glVertex2f(22,19);

    glVertex2f(20,21);
    glVertex2f(22,21);
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
    glColor3f(0.5, 0, 0);
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
    glVertex2f(19,18);
    glVertex2f(18.5,18);
    glVertex2f(18.5,20);
    glVertex2f(19,20);
    glEnd();

    glBegin(GL_QUADS); //kaki domba
    glColor3f(0, 0, 0);
    glVertex2f(18.2,18);
    glVertex2f(17.7,18);
    glVertex2f(17.7,20);
    glVertex2f(18.2,20);
    glEnd();

    glBegin(GL_QUADS); //kaki domba
    glColor3f(0, 0, 0);
    glVertex2f(15,18);
    glVertex2f(15.5,18);
    glVertex2f(15.5,20);
    glVertex2f(15,20);
    glEnd();

    glBegin(GL_QUADS); //kaki domba
    glColor3f(0, 0, 0);
    glVertex2f(14.7,18);
    glVertex2f(14.2,18);
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

    glBegin(GL_POLYGON); //kepala doma
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

    glBegin(GL_POLYGON); //rumput
    glColor3f(0,1,0);//untuk warna rumput
    glVertex2f(92,24);
    glVertex2f(96,24);
    glVertex2f(96,26);
    glVertex2f(92,26);
    glEnd();

    glBegin(GL_LINES); //tali rumput
    glColor3f(1,1,1);//untuk warna tali rumput
    glVertex2f(93,24);
    glVertex2f(93,26);

    glVertex2f(94,24);
    glVertex2f(94,26);

    glVertex2f(95,24);
    glVertex2f(95,26);

    glVertex2f(92,25);
    glVertex2f(96,25);
    glEnd();

    glBegin(GL_QUADS); //kotak
    glColor3f(0.5,0,0);//untuk warna kotak
    glVertex2f(91.5,22);
    glVertex2f(96.5,22);
    glVertex2f(96.5,24.5);
    glVertex2f(91.5,24.5);

    glColor3f(0.5,0.5,0.5);//untuk warna kotak
    glVertex2f(91.5,23.5);
    glVertex2f(96.5,23.5);
    glVertex2f(96.5,24);
    glVertex2f(91.5,24);
    glEnd();

    glBegin(GL_POLYGON); //awal serigala kaki kanan depan
    glColor3f(0, 0, 0);
    glVertex2f(70.67,19.68);
    glVertex2f(70.4,18.5);
    glVertex2f(70.34,18);
    glVertex2f(69,18);
    glVertex2f(69.25,18.45);
    glVertex2f(69.82,18.65);
    glVertex2f(70.12,19.65);
    glVertex2f(70.08,20.53);
    glVertex2f(70.01,21.59);
    glVertex2f(70.91,21.81);
    glEnd();

    glBegin(GL_POLYGON); //serigala kaki kiri depan
    glColor3f(0, 0, 0);
    glVertex2f(68.34,20.59);
    glVertex2f(68.71,19.94);
    glVertex2f(68.8,19.4);
    glVertex2f(68.45,18.69);
    glVertex2f(68.15,19.05);
    glVertex2f(68.32,19.62);
    glVertex2f(67.77,20.41);
    glVertex2f(67.75,21.06);
    glVertex2f(69.45,22.03);
    glVertex2f(70.01,21.59);
    glVertex2f(69,21);
    glEnd();

    glBegin(GL_POLYGON); //awal serigala badan
    glColor3f(0, 0, 0);
    glVertex2f(75.21,21.01);
    glVertex2f(73.84,21.25);
    glVertex2f(72.98,21.66);
    glVertex2f(71.68,21.81);
    glVertex2f(70.39,21.21);
    glVertex2f(69.41,21.44);
    glVertex2f(68.76,22.15);
    glVertex2f(68.61,22.7);
    glVertex2f(68.53,23.16);
    glVertex2f(68.42,23.9);
    glVertex2f(70.78,24.59);
    glVertex2f(71.56,23.85);
    glVertex2f(73.62,23.8);
    glVertex2f(74.86,23.81);
    glVertex2f(75.33,23.7);
    glVertex2f(75.75,23.3);
    glVertex2f(75.96,22.54);
    glVertex2f(75.79,22);
    glEnd();

    glBegin(GL_POLYGON); //serigala kaki kiri belakang
    glColor3f(0, 0, 0);
    glVertex2f(73.23,21.96);
    glVertex2f(73.45,21.59);
    glVertex2f(73.42,21.17);
    glVertex2f(73.26,20.6);
    glVertex2f(73.39,20.18);
    glVertex2f(73.74,19.97);
    glVertex2f(73.48,18.58);
    glVertex2f(73.49,18.22);
    glVertex2f(73,18);
    glVertex2f(72.67,18);
    glVertex2f(72.73,18.26);
    glVertex2f(73.05,18.41);
    glVertex2f(73.1,18.67);
    glVertex2f(73.17,19.4);
    glVertex2f(73.14,19.69);
    glVertex2f(72.63,19.99);
    glVertex2f(72.34,20.46);
    glVertex2f(72.26,20.97);
    glVertex2f(72.28,21.84);
    glEnd();

    glBegin(GL_POLYGON); //awal serigala kaki kanan belakang
    glColor3f(0, 0, 0);
    glVertex2f(74.56,18.4);
    glVertex2f(74.71,19.89);
    glVertex2f(74.29,20.1);
    glVertex2f(74.06,20.57);
    glVertex2f(73.87,21.15);
    glVertex2f(73.67,21.94);
    glVertex2f(75.21,21.01);
    glVertex2f(74.95,20.6);
    glVertex2f(75.04,20.24);
    glVertex2f(75.3,20.04);
    glVertex2f(74.98,18.24);
    glVertex2f(75,18);
    glVertex2f(73.87,18);
    glVertex2f(74.1,18.32);
    glEnd();

    glBegin(GL_POLYGON); //serigala ekor
    glColor3f(0, 0, 0);
    glVertex2f(75.52,23.49);
    glVertex2f(76.34,23.95);
    glVertex2f(77.33,23.79);
    glVertex2f(78.56,23.02); //
    glVertex2f(79.24,22.23);
    glVertex2f(79.66,21.4);
    glVertex2f(79.73,20.24);
    glVertex2f(78.83,21.11);
    glVertex2f(77.88,21.56);
    glVertex2f(77.04,21.83);
    glVertex2f(76.43,21.98);
    glVertex2f(75.85,22.41);
    glEnd();

    glBegin(GL_POLYGON); //serigala kepala
    glColor3f(0, 0, 0);
    glVertex2f(68.42,23.9);
    glVertex2f(68.54,23.84);
    glVertex2f(68.52,24.49);
    glVertex2f(67,24);
    glVertex2f(66.51,24.13);
    glVertex2f(66.42,24.4);
    glVertex2f(67.06,24.74);
    glVertex2f(67.7,25.15);
    glVertex2f(68.06,25.6);
    glVertex2f(68.76,25.8);
    glVertex2f(69.62,26.73);
    glVertex2f(69.47,25.84);
    glVertex2f(70.29,26.63);
    glVertex2f(69.82,25.44);
    glVertex2f(70.27,25.01);
    glVertex2f(70.78,24.59);
    glEnd();

    glBegin(GL_POLYGON); //serigala mata
    glColor3f(1, 0, 0);
    glVertex2f(68.1,25.17);
    glVertex2f(68.16,25.31);
    glVertex2f(68.47,25.42);
    glVertex2f(68.37,25.21);
    glVertex2f(68.22,25.14);
    glEnd();

    glBegin(GL_LINES); //serigala mata
    glColor3f(1, 0, 0);
    glVertex2f(67.9,24.62);
    glVertex2f(66.64,24.07);
    glEnd();

    glBegin(GL_POLYGON); //Sepatu
    glColor3f(0.5, 0.5, 0.5);
    glVertex2f(54,21);
    glVertex2f(57,21);
    glVertex2f(57,22);
    glVertex2f(55,22);
    glEnd();

    glBegin(GL_POLYGON); // sepatu belakang
    glColor3f(0.5, 0.5, 0.5);
    glVertex2f(58,21);
    glVertex2f(59,22);
    glVertex2f(61,22);
    glVertex2f(61,21);
    glEnd();

    glBegin(GL_POLYGON); //Celana
    glColor3f(0,0,0);
    glVertex2f(57,22);
    glVertex2f(56,25);
    glVertex2f(57,25);
    glVertex2f(59,22);
    glVertex2f(61,22);
    glVertex2f(59,25);
    glVertex2f(60,27);
    glVertex2f(55,27);
    glVertex2f(54,25);
    glVertex2f(55,22);
    glEnd();

    glBegin(GL_POLYGON); //Tangan
    glColor3f(0.5, 0.5, 0.5);
    glVertex2f(52,29);
    glVertex2f(51.5,29.5);
    glVertex2f(51,29);
    glVertex2f(50.5,29);
    glVertex2f(50,28.5);
    glVertex2f(50,28);
    glVertex2f(50.5,27.5);
    glVertex2f(51,27.5);
    glVertex2f(51.5,28);
    glVertex2f(51.5,28.5);
    glEnd();

    glBegin(GL_POLYGON); //Saku
    glColor3f(1,1,1);
    glVertex2f(54.5,26);
    glVertex2f(55,26);
    glVertex2f(56,27);
    glVertex2f(55,27);
    glEnd();

    glBegin(GL_POLYGON); //Baju
    glColor3f(0.5, 0, 0);
    glVertex2f(55,27);
    glVertex2f(60,27);
    glVertex2f(59,32);
    glVertex2f(56,32);
    glEnd();

    glBegin(GL_POLYGON); // Lengan
    glColor3f(0.5, 0, 0);
    glVertex2f(56,32);
    glVertex2f(56,31);
    glVertex2f(52,28.5);
    glVertex2f(51,29.5);
    glEnd();

    glBegin(GL_POLYGON); // Kera
    glColor3f(0,0,0);
    glVertex2f(59,32);
    glVertex2f(59,33);
    glVertex2f(56.5,33);
    glVertex2f(56,32);
    glEnd();

    glBegin(GL_POLYGON); // Kepala
    glColor3f(0.5, 0.5, 0.5);
    glVertex2f(58.5,33);
    glVertex2f(58.5,33.5);
    glVertex2f(59.5,34);
    glVertex2f(60,35);
    glVertex2f(60,36);
    glVertex2f(59.5,37);
    glVertex2f(59,37.5);
    glVertex2f(56.5,37.5);
    glVertex2f(56,37);
    glVertex2f(55.5,36);
    glVertex2f(55.5,35);
    glVertex2f(56,34);
    glVertex2f(57,33.5);
    glVertex2f(57,33);
    glEnd();

    glBegin(GL_POLYGON); // Topi
    glColor3f(0.5, 1, 0);
    glVertex2f(61,37.5);
    glVertex2f(57.5,39.5);
    glVertex2f(54,37.5);
    glEnd();

    glBegin(GL_POLYGON); // Mata
    glColor3f(1, 1, 1);
    glVertex2f(56.5,37);
    glVertex2f(57,37);
    glVertex2f(57.5,36.5);
    glVertex2f(57.5,36);
    glVertex2f(57,35.5);
    glVertex2f(56.5,35.5);
    glVertex2f(56,36);
    glVertex2f(56,36.5);
    glEnd();

    glBegin(GL_POLYGON); // Bola Mata
    glColor3f(0, 0, 0);
    glVertex2f(57,36);
    glVertex2f(57,36.5);
    glVertex2f(56.5,36.5);
    glVertex2f(56.5,36);
    glEnd();

    glBegin(GL_POLYGON); // Mulut
    glColor3f(0, 0, 0);
    glVertex2f(55.5,35);
    glVertex2f(57,35);
    glVertex2f(56,34);
    glEnd();

	glutSwapBuffers();
}
void utama()
{
    displayMe();


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
	gluOrtho2D(-10, 100, 0, 50); //mengatur proyeksi hasil eksekusi
	glutMainLoop();
	return 0;
}
