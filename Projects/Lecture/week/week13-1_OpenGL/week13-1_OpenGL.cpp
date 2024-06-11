// week13-1_OpenGL.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <gl/freeglut.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <Windows.h>
#include <stdio.h>

void DoDisplay();
void Key(unsigned char key, int x, int y);
void DrawPyramid();

GLfloat xAngle;
GLfloat yAngle;
GLfloat zAngle;
GLfloat ex;
GLfloat ey;
GLfloat ez;

void DoDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
    glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
    glRotatef(zAngle, 0.0f, 0.0f, 1.0f);

    gluLookAt(
        ex, ey, ez,
        0.0, 0.0, -1.0,
        0.0, 1.0, 0.0
    );

    DrawPyramid();

    glFlush();
}

void Key(unsigned char key, int x, int y)
{
    switch (key) {
    case 'a':yAngle += 2; break;
    case 'd':yAngle -= 2; break;
    case 'w':xAngle += 2; break;
    case 's':xAngle -= 2; break;
    case 'q':zAngle += 2; break;
    case 'e':zAngle -= 2; break;
    case 'z':xAngle = yAngle = zAngle = 0.0; break;

    case 'j':ex += 0.1; break;
    case 'l':ex -= 0.1; break;
    case 'i':ey -= 0.1; break;
    case 'k':ey += 0.1; break;
    case 'u':ez += 0.1; break;
    case 'o':ez -= 0.1; break;
    case 'm':ex = ey = ez = 0.0; break;
    }

    char info[128];

    sprintf_s(info, "ex=%.1f, ey=%.1f, ez=%.1f", ex, ey, ez);

    glutSetWindowTitle(info);

    glutPostRedisplay();
}

void DrawPyramid()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glShadeModel(GL_FLAT);

    if (GL_TRUE)
    {
        glEnable(GL_DEPTH_TEST);
    }
    else
    {
        glDisable(GL_DEPTH_TEST);
    }

    if (GL_TRUE)
    {
        glEnable(GL_CULL_FACE);
    }
    else
    {
        glDisable(GL_CULL_FACE);
    }

    glPushMatrix();
    //glRotatef(xAngle, 1.0f, 1.0f, 1.0f);
    //glRotatef(yAngle, 1.0f, 1.0f, 1.0f);
    //glRotatef(zAngle, 1.0f, 1.0f, 1.0f);
    glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
    glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
    glRotatef(zAngle, 0.0f, 0.0f, 1.0f);

    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);

    GLboolean isQuadCCW = GL_TRUE;
    if (isQuadCCW)
    {
        glVertex2f(-0.5, 0.5);
        glVertex2f(0.5, 0.5);
        glVertex2f(0.5, -0.5);
        glVertex2f(-0.5, -0.5);
    }
    else
    {
        glVertex2f(-0.5, -0.5);
        glVertex2f(0.5, -0.5);
        glVertex2f(0.5, 0.5);
        glVertex2f(-0.5, 0.5);
    }

    glEnd();

    // // 위쪽 빨간 변
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1, 1, 1);
    glVertex3f(0.0, 0.0, -0.8);
    glColor3f(1, 0, 0);
    glVertex3f(0.0, 0.0, -0.8);
    glVertex2f(0.5, 0.5);
    glVertex2f(-0.5, 0.5);

    //// 왼쪽 노란 변
    glColor3f(1, 1, 0);
    glVertex2f(-0.5, -0.5);

    // 아래쪽 초록 변
    glColor3f(0, 1, 0);
    glVertex2f(0.5f, -0.5f);

    // 오른쪽 파란 변
    glColor3f(0, 0, 1);
    glVertex2f(0.5, 0.5);
    glEnd();

    glPopMatrix();
    glFlush();
}

int main(int a, char** b)
{
    glutInit(&a, b);
    glutCreateWindow("3D 도형 처리");
    glutDisplayFunc(DoDisplay);
    glutKeyboardFunc(Key);
    glutMainLoop();
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
