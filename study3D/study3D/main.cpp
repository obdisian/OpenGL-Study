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

int msecs = 17;


//  カメラ位置
GLfloat cameraPosX = 3 * 1.5f;
GLfloat cameraPosY = 2 * 1.5f;
GLfloat cameraPosZ = 5 * 1.5f;


//  光源情報
GLfloat lightAmb[] = { 0, 0, 0, 1 };
GLfloat lightDiff[] = { 1, 1, 1, 1 };
GLfloat lightSpec[] = { 1, 1, 1, 0 };


//  金色の材質
GLfloat goldAmb[] = { 0.24725f, 0.1995f, 0.0745f, 1 };
GLfloat goldDiff[] = { 0.75164f, 0.60648f, 0.22648f, 1 };
GLfloat goldSpec[] = { 0.628281, 0.555802f, 0.366065f, 1 };
GLfloat goldShin = 51.2f;



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
    
    
    glPushMatrix();
    
    
    //  ライティングの有効化
    glEnable(GL_LIGHTING);

//    glRotatef(rotAngle, 0, 1, 0);
    
    //  カラーマテリアルの有効化
//    glEnable(GL_COLOR_MATERIAL);

    
    //  材質設定
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, goldAmb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, goldDiff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, goldSpec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, goldShin);
    
    //  計算モデルをフラット
    glShadeModel(GL_FLAT);
    
//    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT);
//    glColor4fv(goldAmb);
//    glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
//    glColor4fv(goldDiff);
//    glColorMaterial(GL_FRONT_AND_BACK, GL_SPECULAR);
//    glColor4fv(goldSpec);
    
//    glutSolidCube(1);
    glutSolidSphere(1, 20, 20);
//    glutSolidTeapot(1);

    glDisable(GL_LIGHTING);
    
//    glColor3f(1, 1, 1);
//    glutWireSphere(1.05f, 20, 20);
    glColor3f(1, 1, 1);
//    glutWireTeapot(1.01);
    
    glPopMatrix();
    
    
    
    glPushMatrix();
    
    glRotatef(rotAngle, 1, 1, 0);
    glTranslatef(2, 0, 0);
    glColor3f(1, 0, 0);
    glutWireSphere(0.2f, 10, 10);
    
    //  ライトの位置を設定
    GLfloat lightPos[] = { 2, 0, 0, 0 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

    
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
    
    
    //  光源設定
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiff);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpec);
    
    //  光源の有効化
    glEnable(GL_LIGHT0);
    
    GLfloat gray = 0.19607843f;
    glClearColor(gray, gray, gray, 1);
    glClearDepth(1);    //  0-1、1に近いほど遠い
    
    glutMainLoop();
    
    
    return 0;
}
