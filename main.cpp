#include <GL/gl.h> //Import library yang akan digunakan
#include <GL/glu.h> //Import library yang akan digunakan
#include <GL/glut.h> //Import library yang akan digunakan
#include <math.h> //import rumus matematika
#include <stdio.h>
#include <stdlib.h>
const double PI = 3.142857143;
int i,radius,jumlah_titik,a_tengah,b_tengah, gerak1, gerak2, c,c1,c2,d,d1,d2,o,o1,o2;
float x,y,z;
bool atas1 = true, atas2 = true, statusRumput, statusDomba, statusSerigala;
void latar(void) //yang akan ditampilkan
{

    glBegin(GL_POLYGON); //tanah kiri 1
    glColor3f(1, 1, 0);
    glVertex2f(-20,0);
    glVertex2f(8,0);
    glVertex2f(8,18);
    glVertex2f(4,22);
    glVertex2f(-20,22);
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
    glVertex2f(110,0);
    glVertex2f(110,22);
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
}
void domba(void)
{
    glBegin(GL_QUADS); //kaki domba
    glColor3f(0, 0, 0);
    glVertex2f(89,22);
    glVertex2f(90,22);
    glVertex2f(90,24);
    glVertex2f(89,24);
    glEnd();

    glBegin(GL_QUADS); //kaki domba
    glColor3f(0, 0, 0);
    glVertex2f(87,22);
    glVertex2f(88,22);
    glVertex2f(88,24);
    glVertex2f(87,24);
    glEnd();

    glBegin(GL_QUADS); //kaki domba
    glColor3f(0, 0, 0);
    glVertex2f(84,22);
    glVertex2f(85,22);
    glVertex2f(85,24);
    glVertex2f(84,24);
    glEnd();

    glBegin(GL_QUADS); //kaki domba
    glColor3f(0, 0, 0);
    glVertex2f(82.7,22);
    glVertex2f(83.7,22);
    glVertex2f(83.7,24);
    glVertex2f(82.7,24);
    glEnd();

    glBegin(GL_POLYGON); //domba
    glColor3f(1,1,1);//untuk warna domba
       radius = 250;
       jumlah_titik = 60;
       a_tengah = 4300;
       b_tengah = 2550;
       for (i=0;i<=360;i++)
       {
              float sudut=i*(2*PI/jumlah_titik);
              float a=a_tengah+radius*cos (sudut);
              float b=b_tengah+radius*sin (sudut);
              glVertex2f(a/50,b/100);
       }
    glEnd();

    glBegin(GL_POLYGON); //kepala doma
    glColor3f(0,0,0);
       radius = 140;
       jumlah_titik = 60;
       a_tengah = 6400;
       b_tengah = 2300;

       for (i=0;i<=360;i++)
       {
              float sudut=i*(2*PI/jumlah_titik);
              float a=a_tengah+radius*cos (sudut);
              float b=b_tengah+radius*sin (sudut);
              glVertex2f(a/80,b/90);
       }
    glEnd();

    glBegin(GL_POLYGON); //mata domba
    glColor3f(1,1,1);//untuk warna domba
       radius = 35;
       jumlah_titik = 60;
       a_tengah = 7870;
       b_tengah = 2560;

       for (i=0;i<=360;i++)
       {
              float sudut=i*(2*PI/jumlah_titik);
              float a=a_tengah+radius*cos (sudut);
              float b=b_tengah+radius*sin (sudut);
              glVertex2f(a/100,b/100);
       }
    glEnd();

    glBegin(GL_POLYGON); //mata domba
    glColor3f(0,0,0);//untuk warna domba
       radius = 20;
       jumlah_titik = 60;
       a_tengah = 7870;
       b_tengah = 2560;

       for (i=0;i<=360;i++)
       {
              float sudut=i*(2*PI/jumlah_titik);
              float a=a_tengah+radius*cos (sudut);
              float b=b_tengah+radius*sin (sudut);
              glVertex2f(a/100,b/100);
       }
    glEnd();

    glBegin(GL_POLYGON); //mata domba
    glColor3f(1,1,1);//untuk warna domba
       radius = 35;
       jumlah_titik = 60;
       a_tengah = 8000;
       b_tengah = 2560;

       for (i=0;i<=360;i++)
       {
              float sudut=i*(2*PI/jumlah_titik);
              float a=a_tengah+radius*cos (sudut);
              float b=b_tengah+radius*sin (sudut);
              glVertex2f(a/100,b/100);
       }
    glEnd();

    glBegin(GL_POLYGON); //mata domba
    glColor3f(0,0,0);//untuk warna domba
       radius = 20;
       jumlah_titik = 60;
       a_tengah = 8000;
       b_tengah = 2560;

       for (i=0;i<=360;i++)
       {
              float sudut=i*(2*PI/jumlah_titik);
              float a=a_tengah+radius*cos (sudut);
              float b=b_tengah+radius*sin (sudut);
              glVertex2f(a/100,b/100);
       }
    glEnd();

    glBegin(GL_POLYGON); //telinga
    glColor3f(0,0,0);
       radius = 40;
       jumlah_titik = 60;
       a_tengah = 4100;
       b_tengah = 2650;

       for (i=0;i<=360;i++)
       {
              float sudut=i*(2*PI/jumlah_titik);
              float a=a_tengah+radius*cos (sudut);
              float b=b_tengah+radius*sin (sudut);
              glVertex2f(a/50,b/100);
       }
    glEnd();

    glBegin(GL_POLYGON); //telinga
    glColor3f(0,0,0);
       radius = 40;
       jumlah_titik = 60;
       a_tengah = 3900;
       b_tengah = 2650;

       for (i=0;i<=360;i++)
       {
              float sudut=i*(2*PI/jumlah_titik);
              float a=a_tengah+radius*cos (sudut);
              float b=b_tengah+radius*sin (sudut);
              glVertex2f(a/50,b/100);
       }
    glEnd();
}
void rumput(void)
{
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
}
void serigala(void)
{
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
}
void petani(void)
{
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
}
void awan1 (void)
{
    glBegin(GL_POLYGON);
    glColor3f(0.5,0.5,0.5);//untuk warna lingkaran
    radius = 90;
    jumlah_titik = 60;
    a_tengah = 200;
    b_tengah = 4500;
    for (i=0;i<=360;i++)
    {
       float sudut=i*(2*PI/jumlah_titik);
       float a=a_tengah+radius*cos (sudut);
       float b=b_tengah+radius*sin (sudut);
       glVertex2f(a/10,b/105);
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5,0.5,0.5);//untuk warna lingkaran
    radius = 190;
    jumlah_titik = 60;
    a_tengah = 1500;
    b_tengah = 4000;
    for (i=0;i<=360;i++)
    {
       float sudut=i*(2*PI/jumlah_titik);
       float a=a_tengah+radius*cos (sudut);
       float b=b_tengah+radius*sin (sudut);
       glVertex2f(a/80,b/90);
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.5,0.5,0.5);//untuk warna lingkaran
    radius = 190;
    jumlah_titik = 60;
    a_tengah = 1700;
    b_tengah = 4000;
    for (i=0;i<=360;i++)
    {
       float sudut=i*(2*PI/jumlah_titik);
       float a=a_tengah+radius*cos (sudut);
       float b=b_tengah+radius*sin (sudut);
       glVertex2f(a/80,b/90);
    }
    glEnd();
}
void awan2 (void)
{
    glBegin(GL_POLYGON);
    glColor3f(0.5,0.5,0.5);//untuk warna lingkaran
    radius = 90;
    jumlah_titik = 60;
    a_tengah = 200;
    b_tengah = 4000;
    for (i=0;i<=360;i++)
    {
       float sudut=i*(2*PI/jumlah_titik);
       float a=a_tengah+radius*cos (sudut);
       float b=b_tengah+radius*sin (sudut);
       glVertex2f(a/10,b/105);
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5,0.5,0.5);//untuk warna lingkaran
    radius = 190;
    jumlah_titik = 60;
    a_tengah = 1000;
    b_tengah = 3600;
    for (i=0;i<=360;i++)
    {
       float sudut=i*(2*PI/jumlah_titik);
       float a=a_tengah+radius*cos (sudut);
       float b=b_tengah+radius*sin (sudut);
       glVertex2f(a/50,b/90);
    }
    glEnd();
}
void myKeyboard(unsigned char key, int x, int y)
{
        if(key == 'a')
            if(o == 0){
                statusRumput=1;
                o+=1;
            }else if(statusRumput==2){
                cout<<"Mohon maaf Runput sudah berada di tujuan"<<endl;
            }else{
                statusRumput=0;
                o-=1;
            }
        if(key == 's')
            if(o1 == 0){
                statusDomba=1;
                o1+=1;
            }else if(statusDomba==2){
                cout<<"Mohon maaf Domba sudah berada di tujuan"<<endl;
            }else{
                statusDomba=0;
                o1-=1;
            }
        if(key == 'd')
            if(o2 == 0){
                statusSerigala=1;
                o2+=1;
            }else if(statusSerigala==2){
                cout<<"Mohon maaf Serigala sudah berada di tujuan"<<endl;
            }else{
                statusSerigala=0;
                o2-=1;
            }
        if(key == 'g')
            if (statusRumput==1&&statusDomba==1&&statusSerigala==1){
                o=o1=o2=0; c=c1=c2 = 0; d=d1=d2 = 0;
                statusDomba=statusRumput=statusSerigala=0;
                cout<<"Mohon maaf hanya bisa membawa 1 barang"<<endl;
            }else if(statusRumput==1&&statusDomba==1){
                o=o1=0; c=c1= 0; d=d1= 0;
                statusDomba=statusRumput=0;
                cout<<"Mohon maaf hanya bisa membawa 1 barang"<<endl;
            }else if(statusSerigala==1&&statusDomba==1){
                o2=o1=0; c2=c1= 0; d2=d1= 0;
                statusDomba=statusSerigala=0;
                cout<<"Mohon maaf hanya bisa membawa 1 barang"<<endl;
            }else if(statusRumput==1&&statusSerigala==1){
                o=o2=0; c=c2= 0; d=d2= 0;
                statusSerigala=statusRumput=0;
                cout<<"Mohon maaf hanya bisa membawa 1 barang"<<endl;
            }else if(o3 == 0 && statusRumput == 1){
                if(o3 == 0 && statusRumput == 1&&statusDomba==0&&statusSerigala==2){
                    statusPetani=1;
                    statusRumput=2;
                    o3 = 1;
                }else if(o3 == 0 && statusRumput == 1&&statusDomba==0){
                    o=0; c= 0; d= 0;
                    statusRumput=0;
                    cout<<"Mohon maaf tidak bisa mengabaikan Domba bersama Serigala "<<endl;
                }else{
                    statusPetani=1;
                    statusRumput=2;
                    o3 = 1;
                }
            }else if(o3 == 0 && statusSerigala == 1){
                if(o3 == 0 && statusSerigala == 1&&statusDomba==0&&statusRumput==2){
                    statusPetani=1;
                    statusSerigala=2;
                    o3 = 1;
                }else if(o3 == 0 && statusSerigala == 1&&statusDomba==0){
                    o2=0; c2= 0; d2= 0;
                    statusSerigala=0;
                    cout<<"Mohon maaf tidak bisa mengabaikan Domba bersama Rumput "<<endl;
                }else{
                    statusPetani=1;
                    statusSerigala=2;
                    o3 = 1;
                }
            }else if(o3 == 0 && statusDomba == 1){
                statusPetani=1;
                statusDomba=2;
                o3 = 1;
            }else if(o3 == 1){
                if(o3 == 1&&statusRumput==2&&statusDomba==0&&statusSerigala==2){
                    statusPetani=0;
                    o3 = 0;
                }else if(o3 == 1&&statusRumput==2&&statusDomba==2&&statusSerigala==0){
                    statusPetani=statusRumput=0;
                    o=o3 = 0; c= 0; d= 0;
                    cout<<"Mohon maaf tidak bisa mengabaikan Domba bersama Rumput "<<endl;
                }else if(o3 == 1&&statusRumput==0&&statusDomba==2&&statusSerigala==2){
                    statusPetani=statusDomba=0;
                    o1=o3 = 0; c1= 0; d1= 0;
                    cout<<"Mohon maaf tidak bisa mengabaikan Domba bersama Serigala "<<endl;
                }else{
                    statusPetani=0;
                    o3 = 0;
                }
            }else{
                statusPetani=0;
                o3 = 0;
            }
}

void utama()
{

    glClear(GL_COLOR_BUFFER_BIT);
    latar();

    glPushMatrix();
    glTranslatef( gerak1, 0,0);
    awan1();
    glFlush();
    glPopMatrix();

    glPushMatrix();
    glTranslatef( gerak2, 0,0);
    awan2();
    glFlush();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(c,d,0);
    rumput();
    glPopMatrix();
    glFlush();

    glPushMatrix();
    glTranslatef(c1,d1,0);
    domba();
    glPopMatrix();
    glFlush();

    glPushMatrix();
    glTranslatef(c2,d2,0);
    serigala();
    glPopMatrix();
    glFlush();

    petani();
    glutSwapBuffers();
}
void timer_awan1(int value)
{
    if (atas1){
        gerak1 += 1;
    } else {
        gerak1 -= 1;
    }
    if (gerak1 > 70) {
        atas1 = false;
    } else if(gerak1 < -20){
        atas1 = true;
    }
 glutPostRedisplay();

 glutTimerFunc(50,timer_awan1,0);
}
void timer_awan2(int value)
{
    if (atas2){
        gerak2 -= 1;
    } else {
        gerak2 += 1;
    }
    if (gerak2 < -20) {
        atas2 = false;
    } else if(gerak2 > 70){
        atas2 = true;
    }
 glutPostRedisplay();

 glutTimerFunc(50,timer_awan2,0);
}

void timerRumput(int value)
{
    if (statusRumput){
        c = -45; d = -1;
    } else {
        c = 0; d = 0;
    }
    glutPostRedisplay();
    glutTimerFunc(50,timerRumput,0);
}
void timerDomba(int value)
{
    if (statusDomba){
        c1 = -45; d1 = -1;
    } else {
        c1 = 0; d1 = 0;
    }
    glutPostRedisplay();
    glutTimerFunc(50,timerDomba,0);
}
void timerSerigala(int value)
{
    if (statusSerigala){
        c2 = -45; d2 = -1;
    } else {
        c2 = 0; d2 = 0;
    }
    glutPostRedisplay();
    glutTimerFunc(50,timerSerigala,0);
}
void timerPetani(int value)
{
    if (statusPetani==1 && statusRumput==2){
        c3 = -30; d3 = 0;
        c = -110; d = 0;
    }else if (statusPetani==1 && statusDomba==2){
        c3 = -30; d3 = 0;
        c1 = -72; d1 = -4;
    }else if (statusPetani==1 && statusSerigala==2){
        c3 = -30; d3 = 0;
        c2 = -78; d2 = 4;
    } else {
        c3 = 0; d3 = 0;
    }
    glutPostRedisplay();
    glutTimerFunc(50,timerPetani,0);
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
	gluOrtho2D(-20, 110, 0, 50); //mengatur proyeksi hasil eksekusi
	glutTimerFunc(1,timerRumput,0);
	glutTimerFunc(1,timerDomba,0);
	glutTimerFunc(1,timerSerigala,0);
    glutTimerFunc(1,timer_awan1,0);
    glutTimerFunc(1,timer_awan2,0);
    glutKeyboardFunc(myKeyboard);
	glutMainLoop();
	return 0;
}
