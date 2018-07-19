#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
float c1,c2,c3,c4,c5,c6;
bool statusExit = false;
int houseCount = 0, count = 0, status =1, time = 20, stopTime = 5572,choice = 2,N;
char houseNo = '1';
float zoom = 0.0, a = 0.0 , strip = 0.0, fillArea = 0.0,color1 = 0.196078, color2 = 0.6, color3 = 0.8,mc1 = 0.0 , mc2 = 1.0 ,mc3 = 0.0;

void drawDetails(const char ch[] , float x,float y)
{
    int i;
    glRasterPos2f(x,y);
    for(i = 0; ch[i] != '\0'; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,ch[i]);
    }
}
void drawWheels()
{
    int i;
    float pi = 3.14/180;
    glColor3f(0.329412 , 0.329412 , 0.329412);
    glBegin(GL_POLYGON);
        for(i=0 ; i<360; i++)
        {
            float x = 0.05 * cos(i*pi);
            float y = 0.05 * sin(i*pi);
            glVertex2f(x,y);
        }
    glEnd();

}

void drawInnerWheels()
{
    int i;
    float pi = 3.14/180;
    glColor3f(0.74902 , 0.847059 , 0.847059);
    glBegin(GL_POLYGON);
        for(i=0 ; i<360; i++)
        {
            float x = 0.025 * cos(i*pi);
            float y = 0.025 * sin(i*pi);
            glVertex2f(x,y);
        }
    glEnd();

}
void drawTruck()
{
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
        glVertex2f(1.2,0.2); //1
        glVertex2f(1.2,0.5); //2
        glVertex2f(1.27,0.55); //3
        glVertex2f(1.31,0.64); //4
        glVertex2f(1.41,0.64); //5
        glVertex2f(1.46,0.64); //6
        glVertex2f(1.83,0.64); //7
        glVertex2f(1.83,0.2); //8
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex2f(1.41,0.64);
        glVertex2f(1.44,0.64);
        glVertex2f(1.41,0.73);
    glEnd();

    glColor3f(1.0,1.0,1.0);

    glColor3f(0.74902,0.847059 ,0.847059);
    glBegin(GL_QUADS);
        glVertex2f(1.43,0.62);
        glVertex2f(1.82,0.62);
        glVertex2f(1.82,0.3);
        glVertex2f(1.43,0.3);
    glEnd();

     glBegin(GL_QUADS);
        glVertex2f(1.43,0.28);
        glVertex2f(1.55,0.28);
        glVertex2f(1.55,0.17);
        glVertex2f(1.43,0.17);
    glEnd();

    glColor3f(mc1,mc2,mc3);
    glBegin(GL_POLYGON);
        glVertex2f(1.43,0.3);
        glVertex2f(1.82,0.3);
        glVertex2f(1.82,0.3 + fillArea);
        glVertex2f(1.43,0.3 + fillArea);
    glEnd();

    glColor3f(0.560784 , 0.560784 ,0.737255);
    glBegin(GL_POLYGON);
        glVertex2f(1.212,0.22);
        glVertex2f(1.212,0.49);
        glVertex2f(1.275,0.53);
        glVertex2f(1.32,0.62);
        glVertex2f(1.41,0.62);
        glVertex2f(1.41,0.22);
    glEnd();

    glColor3f(1,0.5,0);
    glBegin(GL_QUADS);
        glVertex2f(1.212,0.33);
        glVertex2f(1.212,0.39);
        glVertex2f(1.25,0.39);
        glVertex2f(1.25,0.35);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(1.27,0.5);
        glVertex2f(1.325,0.61);
        glVertex2f(1.4,0.61);
        glVertex2f(1.4,0.28);
        glVertex2f(1.27,0.28);
        glVertex2f(1.27,0.5);
        glVertex2f(1.4,0.5);
    glEnd();

    glPushMatrix();
        glTranslated(1.3,0.22,0);
        drawWheels();
    glPopMatrix();

    glPushMatrix();
        glTranslated(1.62,0.22,0);
        drawWheels();
    glPopMatrix();

    glPushMatrix();
        glTranslated(1.735,0.22,0);
        drawWheels();
    glPopMatrix();

    glPushMatrix();
        glTranslated(1.3,0.22,0);
        drawInnerWheels();
    glPopMatrix();

    glPushMatrix();
        glTranslated(1.62,0.22,0);
        drawInnerWheels();
    glPopMatrix();

    glPushMatrix();
        glTranslated(1.735,0.22,0);
        drawInnerWheels();
    glPopMatrix();
}
void drawText()
{
    glRasterPos2f(0.0,0.0);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,houseNo);
}

void drawWhiteStrip()
{
    glColor3f(1.0,1.0,1.0);
    int i;
    float extra = 0.0;
    for(i=0; i<8; i++)
    {
        glBegin(GL_POLYGON);
            glVertex2f(-0.3 + extra + strip,0.19);
            glVertex2f(-0.3 + extra + strip,0.21);
            glVertex2f(-0.05 + extra + strip,0.21);
            glVertex2f(-0.05 + extra + strip,0.19);
        glEnd();

        extra = extra + 0.3;
    }
}

void drawDustbinUpeerPart()
{
    int i;
    glColor3f(c1,c2,c3);
    float pi = 3.14/180;
    glBegin(GL_POLYGON);
        for(i=0 ; i<360; i++)
        {
            float x = 0.05 * cos(i*pi);
            float y = 0.05 * sin(i*pi);
            glVertex2f(x,y);
        }
    glEnd();
}

void drawDustbin()
{
    glColor3f(c4,c5,c6);
    glBegin(GL_POLYGON);
        glVertex2f(-0.6 + a,0.6);
        glVertex2f(-0.7 + a,0.6);
        glVertex2f(-0.7 + a,0.75);
        glVertex2f(-0.6 + a,0.75);
    glEnd();
}
void drawDoor()
{
    glColor3f(0.184314 , 0.184314 , 0.309804);
    glBegin(GL_POLYGON);
        glVertex2f(-0.25+a,0.6);
        glVertex2f(-0.35+a,0.6);
        glVertex2f(-0.35+a,0.8);
        glVertex2f(-0.25+a,0.8);
    glEnd();
}
void drawSun()
{
    int i;
    glColor3f(1.0,1.0,0.0);
    float pi = 3.14/180;
    glBegin(GL_POLYGON);
        for(i=0 ; i<360; i++)
        {
            float x = 0.15 * cos(i*pi);
            float y = 0.15 * sin(i*pi);
            glVertex2f(x,y);
        }
    glEnd();
}
void stopTranslation(int t)
{
    if(status == 1)
    {
        status = 0;
        houseCount = houseCount + 1;
        printf("%d\n",houseCount);
        c1 = 0.196078;
        c2 = 0.6;
        c3 = 0.8;
        c4 = 0.196078;
        c5 = 0.6;
        c6 = 0.8;
        fillArea = fillArea + 0.01;
    }
    else
        status = 1;
    if(statusExit == true)
    {
        status = 0;
        color1 = 0.0;
        color2 = 1.0;
        color3 = 0.0;
        mc1 = 0.74902 , mc2 = 0.847059 ,mc3 = 0.847059;
    }
    glutTimerFunc(stopTime,stopTranslation,0);
    glutPostRedisplay();
}
void timer(int t)
{
    if(status == 1)
        a = a + 0.01;
    if(status == 1)
        strip = strip + 0.01;
    if(strip >= 0.3)
        strip = 0;
    if(a >= 2.700000)
    {
        a = 0.0;
        houseCount = houseCount + 1;
        houseNo = houseNo+1;
        c1 = 0.0; c2 = 0.0; c3 = 0.0; c4 = 0.0; c5 = 1.0; c6 = 0.0;
    }
    glutTimerFunc(time,timer,0);
    glutPostRedisplay();
}
void drawHouse()
{
    glColor3f( 0.329412 ,0.329412,0.329412);
    glBegin(GL_POLYGON);
        glVertex2f(-0.1+a,0.6);
        glVertex2f(-0.5+a,0.6);
        glVertex2f(-0.5+a,1.0);
        glVertex2f(-0.1+a,1.0);
    glEnd();

    glColor3f(0.858824 ,0.439216 ,0.576471);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.05 + a,1.0);
        glVertex2f(-0.55 + a,1.0);
        glVertex2f(-0.3 + a,1.3);
    glEnd();
}
void drawTriangleTree()
{
    glColor3f(0.52 , 0.37 , 0.26);
    glBegin(GL_POLYGON);
        glVertex2f(-0.53 + a,0.6);
        glVertex2f(-0.57 + a,0.6);
        glVertex2f(-0.57 + a,0.9);
        glVertex2f(-0.53 + a,0.9);
    glEnd();

    glColor3f(0.184314 , 0.309804 , 0.184314);
    glBegin(GL_TRIANGLES);

        glVertex2f(-0.4 + a,0.9);
        glVertex2f(-0.7 + a,0.9);
        glVertex2f(-0.55 + a,1.2);

        glVertex2f(-0.4 + a,1.0);
        glVertex2f(-0.7 + a,1.0);
        glVertex2f(-0.55 + a,1.3);

        glVertex2f(-0.4 + a,1.1);
        glVertex2f(-0.7 + a,1.1);
        glVertex2f(-0.55 + a,1.4);
    glEnd();
}
void drawLargeDustbin()
{
     glColor3f(0.52 , 0.37 , 0.26);
     glBegin(GL_LINES);
        glVertex2f(-1.5 + a,0.4);
        glVertex2f(-1.5 + a,1.1);
     glEnd();
     glBegin(GL_POLYGON);
        glVertex2f(-1.55+a,1.1);
        glVertex2f(-1.55+a,1.2);
        glVertex2f(-1.05+a,1.2);
        glVertex2f(-1.05+a,1.1);
    glEnd();
    glBegin(GL_LINES);
        glVertex2f(-1.1 + a,0.4);
        glVertex2f(-1.1 + a,1.1);
     glEnd();

     glBegin(GL_LINES);
        glVertex2f(-1.45 + a,0.45);
        glVertex2f(-1.15 + a,0.45);

        glVertex2f(-1.15 + a,0.45);
        glVertex2f(-1.15 + a,0.85);

        glVertex2f(-1.45 + a,0.45);
        glVertex2f(-1.45 + a,0.85);
     glEnd();

     glColor3f(color1,color2,color3);
     glBegin(GL_POLYGON);
        glVertex2f(-1.45 + a, 0.55);
        glVertex2f(-1.35 + a, 0.65);
        glVertex2f(-1.25 + a, 0.6);
        glVertex2f(-1.15 + a, 0.7);
        glVertex2f(-1.15 + a,0.45);
        glVertex2f(-1.45 + a,0.45);
     glEnd();
     glColor3f(1.0,1.0,1.0);
     glPushMatrix();
        drawDetails("DumpYard",-1.4 + a, 1.135);
     glPopMatrix();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if(choice == 1)
    {
        drawDetails("COMPUTER GRAPHICS AND VISUALIZATION MINI PROJECT",0.5,1.6);
        drawDetails("PROJECT : DUMP TRUCK",0.8,1.4);
        drawDetails("NAME : SANTOSH",0.6,1.2);
        drawDetails("USN : 1PE15CS138",0.6,1.0);
        drawDetails("NAME : SAMARTH BANSAL",0.6,0.8);
        drawDetails("USN : 1PE15CS136",0.6,0.6);
    }
    else if(choice == 2)
    {
        glColor3f(0.0,0.0,0.0);

        glBegin(GL_POLYGON);
            glVertex2f(0,0);
            glVertex2f(0,0.4);
            glVertex2f(2,0.4);
            glVertex2f(2,0.0);
        glEnd();

        if(houseCount >= 2*N)
        {
            glPushMatrix();
                glTranslated(1.7,1.7,0.0);
                drawSun();
            glPopMatrix();
            drawLargeDustbin();
            drawWhiteStrip();
            drawTruck();
            statusExit = true;
        }
        else
        {
        glPushMatrix();
            glTranslated(-0.65 + a,0.75,0.0);
            drawDustbinUpeerPart();
        glPopMatrix();

        glPushMatrix();
            drawTriangleTree();
            drawHouse();
            drawDoor();
            drawDustbin();
            drawWhiteStrip();
        glPopMatrix();

        glPushMatrix();
            glTranslated(-0.31 + a, 0.85,0);
            drawText();
        glPopMatrix();

        glPushMatrix();
            glTranslated(1.7,1.7,0.0);
            drawSun();
        glPopMatrix();

        glPushMatrix();
            drawTruck();
        glPopMatrix();
        }
    }
    glutSwapBuffers();
}
void menu(int id)
{
    switch(id)
    {
        case 1 : choice = 1;
                 break;
        case 2 : choice = 2;
                 break;
        case 3 : exit(0);
    }
    glutPostRedisplay();
}
void init()
{
    glClearColor(0.196078, 0.6, 0.8,1.0);
    c1 = c2 = c3 = 0.0;
    c4 = c6  = 0.0;
    c5 = 1.0;
    gluOrtho2D(0,2,0,2);
}
int main(int argc,char **argv)
{
    printf("Enter the number of houses\n");
    scanf("%d",&N);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(1000,600);
    glutCreateWindow("Dump Truck Computer Graphics Project");
    init();
    glutCreateMenu(menu);
    glutAddMenuEntry("Our Details",1);
    glutAddMenuEntry("Project Demo",2);
    glutAddMenuEntry("Exit",3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutDisplayFunc(display);
    glutTimerFunc(100,timer,0);
    glutTimerFunc(4300,stopTranslation,0);
    glutMainLoop();
    return 0;
}
