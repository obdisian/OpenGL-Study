//
//  main.cpp
//  GLTextureTest
//
//  Created by naohiro nomura on 2016/07/10.
//  Copyright © 2016年 naohiro nomura. All rights reserved.
//

#include <iostream>
#include <GLUT/GLUT.h>


namespace Data
{
    const int msecs = 30;
}


//================================================================================
//  テクスチャの読み込み
//================================================================================
void LoadTexture ()
{
    
}


//================================================================================
//  描画
//================================================================================
void display ()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(1, 1, 1);
    
    glutWireTeapot(1);
    
    
    //  ダブルバッファ
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
    gluPerspective(30.0, (double)(w / h), 1.0, 100.0);
}


//================================================================================
//  定期的に描画を更新
//================================================================================
void timer (int t) {
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
    glutCreateWindow("Texture Test");
    
    glutInitDisplayMode(GL_RGBA | GLUT_DOUBLE);
    
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, Data::msecs);
    
    
    glClearColor(0, 0, 0, 1);
    
    
    glutMainLoop();
    
    return 0;
}
