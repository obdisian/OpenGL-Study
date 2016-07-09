//
//  main.cpp
//  study3D
//
//  Created by naohiro nomura on 2016/07/09.
//  Copyright © 2016年 naohiro nomura. All rights reserved.
//

#include <iostream>
#include <GLUT/GLUT.h>


int rotAngle = 0;

int msecs = 30;


int cameraPosX = 3;
int cameraPosY = 2;
int cameraPosZ = 5;



void display () {
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glColor3f(0, 0, 0);
    
//    glutWireCube(1);
    
    
    
    int lineLength = 100;
    //  ライン描画
    glBegin(GL_LINES);
    //  x軸
    glColor3f(1, 0, 0);
    glVertex3f(lineLength, 0, 0);
    glVertex3f(-lineLength, 0, 0);
    
    //  y軸
    glColor3f(0, 1, 0);
    glVertex3f(0, lineLength, 0);
    glVertex3f(0, -lineLength, 0);
    
    //  z軸
    glColor3f(0, 0, 1);
    glVertex3f(0, 0, lineLength);
    glVertex3f(0, 0, -lineLength);
    
    glEnd();
    
    
    
    glEnable(GL_DEPTH_TEST);
    
    
    rotAngle++;
    
    
    glColor3f(0, 1, 1);
    
    glPushMatrix();
    
    glRotatef(rotAngle, 0, 1, 0);
    glutWireSphere(1, 20, 20);
    
    glPopMatrix();
    
    
    
    glColor3f(1, 0, 1);
    
    glPushMatrix();
    
    glRotatef(rotAngle, 0, 1, 0);
    glTranslatef(2, 0, 0);
    glutWireSphere(1, 20, 20);
    
    glPopMatrix();
    
    glDisable(GL_DEPTH_TEST);
    
    
    glutSwapBuffers();
}



void reshape (int w, int h) {
    glViewport(0, 0, w, h);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0, (double)(w / h), 1.0, 100.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(cameraPosX, cameraPosY, cameraPosZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}



void idle () {
    glutPostRedisplay();
}


void timer (int t) {
    glutPostRedisplay();
    glutTimerFunc(t, timer, msecs);
}



int main(int argc, char * argv[]) {
    
    glutInit(&argc, argv);
    
    glutInitWindowSize(400, 400);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("study3D");
    
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
//    glutIdleFunc(idle);
    glutTimerFunc(0, timer, msecs);
    
    
    glClearColor(0, 0, 0, 1);
    glClearDepth(1);    //  0-1、1に近いほど遠い
    
    glutMainLoop();
    
    
    return 0;
}
