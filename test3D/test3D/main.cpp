//
//  main.cpp
//  test3D
//
//  Created by naohiro nomura on 2016/07/07.
//  Copyright © 2016年 naohiro nomura. All rights reserved.
//

#include <iostream>
#include <GLUT/GLUT.h>




static const int Window_Width = 400;
static const int Window_Height = 400;




//********************************************************************************
//  描画関数
//********************************************************************************
void display () {
    
    //  カラー・バッファの初期化
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f (0, 1, 1);
    glutWireTeapot(1.0);
    
    
    //  命令の実行
    glFlush();
}



//********************************************************************************
//  サイズ変更時
//********************************************************************************
void reshape (int w, int h) {
    //  ビューポートの設定
    glViewport(0, 0, w, h);
    
    
    
    //  行列モードで対象を切り替えて、その対象に行列を当てはめていく
    //  対象を切り替えたら「glLoadIdentity」で初期化を行う
    
    //  射影行列の設定
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //  視体積の設定
    gluPerspective(30.0, (double)(w / h), 1.0, 100.0);
    
    //  モデルビュー行列の設定
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //  視点位置の設定
    gluLookAt(3.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}



//********************************************************************************
//  メイン関数
//********************************************************************************
int main(int argc, char * argv[]) {
    
    glutInit(&argc, argv);
    
    
    //  ウィンドウ作成
    glutInitWindowSize(Window_Width, Window_Height);
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow("OpenGL 3DTest");
    
    
    
    //++++++++++++++++++++++++++++++++++++++++
    //  コールバック関数登録
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    
    
    
    //  カラーバッファの初期値
    glClearColor(0, 0, 0, 1);

    
    //  メインループ
    glutMainLoop();
    
    
    return 0;
}
