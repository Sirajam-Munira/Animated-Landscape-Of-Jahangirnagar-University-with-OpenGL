#include <bits/stdc++.h>
using namespace std;
#include<windows.h>
#include <MMSystem.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>


float X=0,Y=0,Z=0;

GLfloat mu=0;
void update(int value)
{
    mu+=180;
    if(mu>180)
        mu=0;
    glutPostRedisplay();
    glutTimerFunc(100,update,0);
}


void rect(int x1,int y1,int x2,int y2)
{
    glBegin(GL_POLYGON);
    glVertex2i(x1,y1);
    glVertex2i(x1,y2);
    glVertex2i(x2,y2);
    glVertex2i(x2,y1);
    glEnd();
}

void fld()
{
    glBegin(GL_POLYGON);
    glColor3ub(64,120,2);
    glVertex2i(0,0);
    glVertex2i(0,600);
    glVertex2i(1600,600);
    glVertex2i(1600,0);
    glEnd();
}

void sky()
{
    glBegin(GL_POLYGON);
    glColor3ub(135,206,235);
    glVertex2i(0,600);
    glVertex2i(0,1000);
    glVertex2i(1600,1000);
    glVertex2i(1600,600);
    glEnd();
}
void road()
{
    glBegin(GL_POLYGON);
    glColor3ub(183,105,52);
    glVertex2i(0,290);
    glVertex2i(0,370);
    glVertex2i(800,570);
    glVertex2i(800,490);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(183,105,52);
    glVertex2i(800,570);
    glVertex2i(1600,370);
    glVertex2i(1600,290);
    glVertex2i(800,490);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(183,105,52);
    glVertex2i(140,330);
    glVertex2i(260,370);
    glVertex2i(800,250);
    glVertex2i(700,210);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(183,105,52);
    glVertex2i(800,250);
    glVertex2i(900,210);
    glVertex2i(1460,330);
    glVertex2i(1320,370);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(183,105,52);
    glVertex2i(700,0);
    glVertex2i(900,0);
    glVertex2i(900,210);
    glVertex2i(700,210);
    glEnd();
}


void road1()
{
    glBegin(GL_POLYGON);
    glColor3ub(244,164,96);
    glVertex2i(0,300);
    glVertex2i(0,380);
    glVertex2i(800,580);
    glVertex2i(800,500);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(244,164,96);
    glVertex2i(800,580);
    glVertex2i(1600,380);
    glVertex2i(1600,300);
    glVertex2i(800,500);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(244,164,96);
    glVertex2i(140,340);
    glVertex2i(260,380);
    glVertex2i(800,260);
    glVertex2i(700,220);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(244,164,96);
    glVertex2i(800,260);
    glVertex2i(900,220);
    glVertex2i(1460,340);
    glVertex2i(1320,380);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(244,164,96);
    glVertex2i(700,0);
    glVertex2i(900,0);
    glVertex2i(900,220);
    glVertex2i(700,220);
    glEnd();
}

void ellipse(int rx, int ry, int xc, int yc)
{
    float dx, dy, d1, d2, x, y;
    x = 0;
    y = ry;

    d1 = (ry * ry) - (rx * rx * ry) +
         (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;

    while (dx < dy)
    {
        glBegin(GL_POLYGON);
        glVertex2i(x+xc,y+yc);
        glVertex2i(-x+xc,-y+yc);
        glVertex2i(x+xc,-y+yc);
        glVertex2i(-x+xc,y+yc);
        glEnd();

        if (d1 < 0)
        {
            x++;
            dx = dx + (2 * ry * ry);
            d1 = d1 + dx + (ry * ry);
        }
        else
        {
            x++;
            y--;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d1 = d1 + dx - dy + (ry * ry);
        }
    }

    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) +
         ((rx * rx) * ((y - 1) * (y - 1))) -
         (rx * rx * ry * ry);

    while (y >= 0)
    {
        glBegin(GL_POLYGON);
        glVertex2i(x+xc,y+yc);
        glVertex2i(-x+xc,-y+yc);
        glVertex2i(x+xc,-y+yc);
        glVertex2i(-x+xc,y+yc);
        glEnd();

        if (d2 > 0)
        {
            y--;
            dy = dy - (2 * rx * rx);
            d2 = d2 + (rx * rx) - dy;
        }
        else
        {
            y--;
            x++;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d2 = d2 + dx - dy + (rx * rx);
        }
    }
}


void draw_pixel(int xc, int yc, int x, int y)
{
    glBegin(GL_POLYGON);
    glVertex2i(x+xc,y+yc);
    glVertex2i(-x+xc,-y+yc);
    glVertex2i(x+xc,-y+yc);
    glVertex2i(-x+xc,y+yc);
    glVertex2i(y+xc,x+yc);
    glVertex2i(-y+xc,-x+yc);
    glVertex2i(y+xc,-x+yc);
    glVertex2i(-y+xc,x+yc);
    glEnd();
}

void circle(int xc, int yc, int r)
{
    int x, y, d;
    x = 0;
    y = r;
    d = 1 - r;
    draw_pixel(xc, yc, x, y);
    while (x<=y)
    {
        x++;
        if (d > 0)
        {
            y--;
            d = d + 2*(x - y) + 5;
        }
        else
            d = d + 2*x + 3;
        draw_pixel(xc, yc, x, y);
    }
    //glFlush();
}

void khamba1()
{
    glBegin(GL_POLYGON);
    glColor3ub(183,75,53);
    glVertex2i(780,340);
    glVertex2i(820,340);
    glVertex2i(820,780);
    glVertex2i(780,780);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(183,75,53);
    glVertex2i(780,340);
    glVertex2i(700,300);
    glVertex2i(900,300);
    glVertex2i(820,340);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(212,100,76);
    glVertex2i(700,300);
    glVertex2i(760,300);
    glVertex2i(760,820);
    glVertex2i(700,820);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(212,100,76);
    glVertex2i(840,300);
    glVertex2i(900,300);
    glVertex2i(900,820);
    glVertex2i(840,820);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(212,100,76);
    glVertex2i(760,360);
    glVertex2i(780,380);
    glVertex2i(780,500);
    glVertex2i(760,520);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(212,100,76);
    glVertex2i(780,380);
    glVertex2i(820,380);
    glVertex2i(820,500);
    glVertex2i(780,500);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(212,100,76);
    glVertex2i(820,380);
    glVertex2i(840,360);
    glVertex2i(840,520);
    glVertex2i(820,500);
    glEnd();
}

void stage()
{
    glColor3ub(183,105,52);
    ellipse(520,200,800,210);
    circle(1187,210,120);
    circle(413,210,119);

    glColor3ub(244,164,96);
    ellipse(520,200,800,220);
    circle(1187,220,120);
    circle(413,220,119);

    glColor3ub(183,105,52);
    ellipse(400,120,800,210);
    circle(468,210,60);
    circle(1134,210,60);

    glColor3ub(229,142,76);
    ellipse(400,120,800,220);
    circle(468,220,60);
    circle(1134,220,60);
}

void siri()
{
    glBegin(GL_POLYGON);
    glColor3ub(183,105,52);
    glVertex2i(560,200);
    glVertex2i(1040,200);
    glVertex2i(1060,240);
    glVertex2i(800,400);
    glVertex2i(540,240);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(191,112,58);
    glVertex2i(570,210);
    glVertex2i(1030,210);
    glVertex2i(1050,250);
    glVertex2i(800,400);
    glVertex2i(550,250);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(201,121,67);
    glVertex2i(580,220);
    glVertex2i(1020,220);
    glVertex2i(1040,260);
    glVertex2i(800,400);
    glVertex2i(560,260);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(209,129,74);
    glVertex2i(590,230);
    glVertex2i(1010,230);
    glVertex2i(1030,270);
    glVertex2i(800,400);
    glVertex2i(570,270);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(219,133,75);
    glVertex2i(600,240);
    glVertex2i(1000,240);
    glVertex2i(1020,280);
    glVertex2i(800,400);
    glVertex2i(580,280);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(229,138,76);
    glVertex2i(610,250);
    glVertex2i(990,250);
    glVertex2i(1010,290);
    glVertex2i(800,400);
    glVertex2i(590,290);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(242,147,76);
    glVertex2i(620,260);
    glVertex2i(980,260);
    glVertex2i(1000,300);
    glVertex2i(800,400);
    glVertex2i(600,300);
    glEnd();


}
void tree()
{
    //backtree1
    glColor3ub(102,20,14);
    rect(200,420,220,600);
    glColor3ub(24,68,25);
    circle(190,600,60);
    circle(240,600,60);
    circle(220,660,60);

    //backtree2
    glColor3ub(102,20,14);
    rect(400,480,420,620);
    glColor3ub(24,68,25);
    circle(390,640,60);
    circle(440,640,60);
    circle(420,700,60);

    //backtree3
    glColor3ub(102,20,14);
    rect(600,530,620,640);
    glColor3ub(24,68,25);
    circle(590,660,60);
    circle(640,650,60);
    circle(620,720,60);

    //backtree4
    glColor3ub(102,20,14);
    rect(980,530,1000,640);
    glColor3ub(24,68,25);
    circle(970,660,60);
    circle(1020,650,60);
    circle(1000,720,60);

    //backtree5
    glColor3ub(102,20,14);
    rect(1180,480,1200,620);
    glColor3ub(24,68,25);
    circle(1170,640,60);
    circle(1220,640,60);
    circle(1200,700,60);

    //backtree6
    glColor3ub(102,20,14);
    rect(1400,420,1420,600);
    glColor3ub(24,68,25);
    circle(1390,600,60);
    circle(1440,600,60);
    circle(1420,660,60);

    //extra
    glColor3ub(24,68,25);
    circle(0,580,60);

    circle(700,650,60);
    circle(780,650,60);
    circle(730,700,60);

    circle(840,650,60);
    circle(930,650,60);
    circle(880,700,60);

    circle(1600,580,60);


    //tree1
    glColor3ub(114,26,12);
    rect(80,320,100,500);
    glColor3ub(15,81,3);
    circle(70,500,60);
    circle(120,500,60);
    circle(100,560,60);

    //tree2
    glColor3ub(114,26,12);
    rect(300,380,320,520);
    glColor3ub(15,81,3);
    circle(290,540,60);
    circle(340,540,60);
    circle(320,600,60);

    //tree3
    glColor3ub(114,26,12);
    rect(520,430,540,580);
    glColor3ub(15,81,3);
    circle(510,600,60);
    circle(560,600,60);
    circle(540,660,60);

    //tree4
    glColor3ub(114,26,12);
    rect(1040,430,1060,580);
    glColor3ub(15,81,3);
    circle(1030,600,60);
    circle(1080,600,60);
    circle(1060,660,60);

    //tree5
    glColor3ub(114,26,12);
    rect(1280,380,1300,520);
    glColor3ub(15,81,3);
    circle(1270,540,60);
    circle(1320,540,60);
    circle(1300,600,60);

    //tree6
    glColor3ub(114,26,12);
    rect(1500,320,1520,500);
    glColor3ub(15,81,3);
    circle(1490,500,60);
    circle(1540,500,60);
    circle(1520,560,60);
}

//megh
void cloud()
{
    glColor3ub(255,255,255);
    //cloud1
    circle(200+X,800,80);
    circle(140+X,780,60);
    circle(280+X,780,60);

    //cloud2
    circle(800+X,880,80);
    circle(740+X,860,60);
    circle(880+X,860,60);

    //cloud2
    circle(1400+X,840,80);
    circle(1340+X,820,60);
    circle(1480+X,820,60);
}
void sun()
{
    glColor3ub(255,109,58);
    circle(500,850,70);
}
void bird()
{
    //body
    glColor3ub(255,0,0);
    ellipse(30,15,200+Z,840);
    //head
    glColor3ub(244,110,110);
    circle(240+Z,840,18);

    //eye
    glColor3ub(0,0,0);
    circle(245+Z,845,5);

    //lej
    glBegin(GL_POLYGON);
    glColor3ub(244,110,110);
    glVertex2i(140+Z,830);
    glVertex2i(180+Z,840);
    glVertex2i(140+Z,850);
    glEnd();

    //dana
    glPushMatrix();
    glTranslated(0,0,mu);
    glBegin(GL_POLYGON);
    glColor3ub(244,110,110);
    glVertex2i(200+Z,840);
    glVertex2i(230+Z,870);
    glVertex2i(170+Z,870);
    glEnd();
    glPopMatrix();

    //thot
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex2i(255+Z,830);
    glVertex2i(270+Z,840);
    glVertex2i(255+Z,850);
    glEnd();



}

void bird2()
{
    //body
    glColor3ub(113,24,77);
    ellipse(30,15,600+Z,800);
    //head
    glColor3ub(220,153,195);
    circle(640+Z,800,18);

    //eye
    glColor3ub(0,0,0);
    circle(645+Z,805,5);

    //lej
    glBegin(GL_POLYGON);
    glColor3ub(220,153,195);
    glVertex2i(540+Z,790);
    glVertex2i(580+Z,800);
    glVertex2i(540+Z,810);
    glEnd();

    //dana
    glPushMatrix();
    glTranslated(0,0,mu);
    glBegin(GL_POLYGON);
    glColor3ub(220,153,195);
    glVertex2i(600+Z,800);
    glVertex2i(630+Z,830);
    glVertex2i(570+Z,830);
    glEnd();
    glPopMatrix();

    //thot
    glBegin(GL_POLYGON);
    glColor3ub(68,5,47);
    glVertex2i(655+Z,790);
    glVertex2i(670+Z,800);
    glVertex2i(655+Z,810);
    glEnd();



}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    //function
    fld();
    sky();
    sun();
    cloud();
    road();
    road1();
    stage();
    siri();
    tree();
    khamba1();
    bird();
    bird2();


    glFlush();
}
void idle()
{
    if(X>=-200&&X<1600)
        X+=0.7;
    if(X>=1600)
        X=-200;

    if(Z>=-550&&Z<1600)
        Z+=3.0;
    if(Z>=1600)
        Z=-550;
    glutPostRedisplay();
}

void myInit()
{
    glColor3f(1.0,1.0,1.0);
    glColor3ub(255,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,1600,0,1000);
}

int main(int munira, char** muniras)
{
    glutInit(&munira, muniras);
    glutInitWindowSize(1050,650);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutCreateWindow("Munira");
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    sndPlaySound("G:\\3-2\\Computer Graphics\\Codes\\myproj\\music.wav",SND_ASYNC);

    myInit();
    glutTimerFunc(100,update,0);
    glutMainLoop();
    return 0;
}
