#include <gl/glut.h>
// #include <GL/>// �ý��ۿ� �ִ� OpenGL�̴�. �浹 ���ɼ��� �ֱ� ������ �ҹ��ڸ� ����.

void Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);

	// gl �����Ұž�
	glBegin(GL_TRIANGLES);
	glVertex2f(0.0f, 0.5f);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.5f, -0.5f);
	glBegin(GL_TRIANGLES);
	glVertex2f(1.0f, 0.5f);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(1.0f, -1.0f);

	glEnd();
	glFlush(); // ������ ������ �о���ϴ�.
}


// ��ƿ��Ƽ
int main(int args, char** b)
{
	glutInit(&args, b);
	glutCreateWindow("�ܱ⽺Ʈ");
	glutDisplayFunc(Draw); // �ݹ��Լ�
	glutMainLoop();

	return 0;
}