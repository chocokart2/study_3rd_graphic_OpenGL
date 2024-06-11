#include <gl/glut.h>
// #include <GL/>// 시스템에 있는 OpenGL이다. 충돌 가능성이 있기 때문에 소문자를 쓴다.

void Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);

	// gl 시작할거야
	glBegin(GL_TRIANGLES);
	glVertex2f(0.0f, 0.5f);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.5f, -0.5f);
	glBegin(GL_TRIANGLES);
	glVertex2f(1.0f, 0.5f);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(1.0f, -1.0f);

	glEnd();
	glFlush(); // 버퍼의 내용을 밀어냅니다.
}


// 유틸리티
int main(int args, char** b)
{
	glutInit(&args, b);
	glutCreateWindow("햄기스트");
	glutDisplayFunc(Draw); // 콜백함수
	glutMainLoop();

	return 0;
}