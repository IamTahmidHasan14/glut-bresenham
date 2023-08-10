#include <windows.h>
#include <GL/glut.h>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
float m, mm, x, y, dx, dy, p, Xst, Xen, Yst, Yen;
void Bresenham()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINES);
        glVertex2f(-1.0,0.0);
        glVertex2f(1.0,0.0);
        glVertex2f(0.0,-1.0);
        glVertex2f(0.0,1.0);
    glEnd();
    dx=abs(Xst - Xen);
    dy=abs(Yst - Yen);
    m=(Yen-Yst)/(Xen-Xst);
    glColor3f(1.0,0.0,0.0);
    glPointSize(4.7);
    if(m<1){
        if(Xst>Xen){
            swap(Xst,Xen);
            swap(Yst,Yen);
        }
        x=Xst; y=Yst;
        p=2*dy - dx;
        glBegin(GL_POINTS);
        glVertex2f(x/100,y/100);
        while(x<=Xen){
            if(p>=0){
                x++; y++;
                p=p+2*dy-2*dx;
            }
            else{
                x++;
                p=p+2*dy;
            }
            glVertex2f(x/100,y/100);
        }
        glEnd();
    }
    else if(m>1){
    glColor3f(0.0,0.0,1.0);
        if(Xst>Xen){
            swap(Xst,Xen);
            swap(Yst,Yen);
        }
        x=Xst; y=Yst;
        p=2*dx - dy;
        glBegin(GL_POINTS);
            glVertex2f(x/100,y/100);
        while(x<=Xen){
            if(p>=0){
                x++; y++;
                p=p+2*dx-2*dy;
            }
            else{
                y++;
                p=p+2*dx;
            }
            glVertex2f(x/100,y/100);
        }
        glEnd();
    }
    glFlush();
}

int main(int argc, char *argv[])
{
    cout<<"Enter starting points (X start, Y start): ";
    cin>>Xst>>Yst;
    cout<<"Enter Ending points (X end, Y end): ";
    cin>>Xen>>Yen;
    ///Xst=5, Yst=5, Xen=100, Yen=25;
    glutInit(&argc, argv);
    glutInitWindowSize(1366,768);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
    glutCreateWindow("LAB 2");
    glutDisplayFunc(Bresenham);
    glutMainLoop();
    return 0;
}
