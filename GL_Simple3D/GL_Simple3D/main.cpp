//
//  main.cpp
//  GL_Simple3D
//
//  Created by naohiro nomura on 2016/07/10.
//  Copyright © 2016年 naohiro nomura. All rights reserved.
//

#include <iostream>
#include <GLUT/GLUT.h>


namespace Data
{
    
    const int msecs = 17;
    
    GLfloat cameraPosX = 3 * 1.5f;
    GLfloat cameraPosY = 2 * 1.5f;
    GLfloat cameraPosZ = 5 * 1.5f;
    
    GLfloat lightAmb[] = { 0, 0, 0, 1 };
    GLfloat lightDiff[] = { 1, 1, 1, 1 };
    GLfloat lightSpec[] = { 1, 1, 1, 0 };
}



//================================================================================
//  描画
//================================================================================
void display ()
{
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    
    glColor3f(1, 1, 1);
    
    glEnable(GL_DEPTH_TEST);
    
    //  ライティングの有効化
    glEnable(GL_LIGHTING);
    
    //  カラーマテリアルの有効化
    glEnable(GL_COLOR_MATERIAL);
    
    //  計算モデルをフラット
    glShadeModel(GL_FLAT);
    
    glutSolidTeapot(1);
    
    glDisable(GL_LIGHTING);
    
    
    //  ライトの位置を設定
    GLfloat lightPos[] = { 3, 2, 5, 0 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    
    
    glDisable(GL_DEPTH_TEST);
    
    glutSwapBuffers();
}


//================================================================================
//  ウィンドウサイズ変更時
//================================================================================
void reshape (int w, int h)
{
    glViewport(0, 0, w, h);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30, (double)(w / h), 1, 100);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(Data::cameraPosX, Data::cameraPosY, Data::cameraPosZ, 0, 0, 0, 0, 1, 0);
}


//================================================================================
//  定期的に描画を更新
//================================================================================
void timer (int t)
{
    glutPostRedisplay();
    glutTimerFunc(t, timer, Data::msecs);
}


//================================================================================
//  メインスレッド
//================================================================================
int main(int argc, char * argv[])
{
    
    glutInit(&argc, argv);
    
    glutInitWindowSize(400, 400);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("study3D");
    
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, Data::msecs);
    
    
    //  光源設定
    glLightfv(GL_LIGHT0, GL_AMBIENT, Data::lightAmb);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, Data::lightDiff);
    glLightfv(GL_LIGHT0, GL_SPECULAR, Data::lightSpec);
    
    //  光源の有効化
    glEnable(GL_LIGHT0);
    
    GLfloat gray = 0.19607843f;
    glClearColor(gray, gray, gray, 1);
    glClearDepth(1);    //  0-1、1に近いほど遠い
    
    glutMainLoop();
    
    
    return 0;
}
