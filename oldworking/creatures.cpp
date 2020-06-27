#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <math.h>
#include "Classes/base.h"

using namespace std;

#define windowWidth 1000
#define windowHeight 1000

typedef struct _bixinho{
	float radius;
	float x;
	float y;
	float theta;
	float r,g,b;
}Bixinho;

// Cria os bixinhos: (radius) (x,y,theta)       (r,g,b)
Bixinho wilson =     {20,      200, 200,0,          0.8,0,0};
Bixinho robson =     {20,      300, 300,M_PI,       0,0.8,0};
Bixinho dikson =     {20,      800, 800,M_PI/2,    0,0,0.8};

//---------- Protótipos de função ----------//
void draw();// Função para desenhar
void timer(int);// Função de loop
void rotateBixinho(Bixinho *bixinho, float angle);// Girar bixinho
void moveBixinho(Bixinho *bixinho, float distance);// Mover bixinho
void drawBixinho(Bixinho bixinho);// Desenhar bixinho

//------------------ Main -----------------//
int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Living Beings - by Molotov");
	gluOrtho2D(0, 1000, 0, 1000);
	glClearColor(0.3, 0.5, 0.0, 0.0);
	glutDisplayFunc(draw);
	glutTimerFunc(0, timer, 0);// Define qual será a função de loop
	glutMainLoop();

	return 0;
}

//------------------ Draw -----------------//
void draw(){
	glClear(GL_COLOR_BUFFER_BIT);

	drawBixinho(wilson);
	drawBixinho(robson);
	drawBixinho(dikson);

	glutSwapBuffers();
}

//------------------ Timer -----------------//
void timer(int){
	// Essa função é chamada em loop, é aqui que realizaremos as animações

	// Tenta ficar mudando os parâmetros para ver o que muda! :)

	// Para mover os bixinhos
	moveBixinho(&wilson, 1);
	moveBixinho(&robson, 1);
	moveBixinho(&dikson, 1);

	// Para girar os bixinhos
	rotateBixinho(&wilson, 1);
	rotateBixinho(&robson, -1);
	rotateBixinho(&dikson, -1);

	// Executa a função draw para desenhar novamente
	glutPostRedisplay();

	// O primeiro parâmetro define de quanto em quanto tempo em milissegundos timer será chaamdo
	// Eu coloquei 1000/60 para definir que vai atualizar a 60hz
	glutTimerFunc(1000/60, timer, 0);// Garante que esta função será chamada de novo
}


//----------------------------------------------//
//----------- Funções para o bixinho -----------//
//----------------------------------------------//
void rotateBixinho(Bixinho *bixinho, float side)
{//side -> -1 = clockwise, 1 = counter-clockwise;
	bixinho->theta+= (0.05 * side);
	bixinho->theta= bixinho->theta >= 360 ? 0 : bixinho->theta;
	bixinho->theta= bixinho->theta <= -360 ? 0 : bixinho->theta; 
}

void moveBixinho(Bixinho *bixinho, float distance){
	// Para mover para onde ele está olhando (na direção theta)
	bixinho->x = bixinho->x + distance * cos(bixinho->theta);
	bixinho->y = bixinho->y + distance * sin(bixinho->theta);


	// Impede que o wilson saia da tela
	bixinho->x = bixinho->x<1 ? 1 : bixinho->x;
	bixinho->y = bixinho->y<1 ? 1 : bixinho->y;
	bixinho->x = bixinho->x>1000 ? 999 : bixinho->x;
	bixinho->y = bixinho->y>1000 ? 999 : bixinho->y;

}

void drawBixinho(Bixinho bixinho){
	// Função para desenhar o bixinho
	float radius = bixinho.radius;
	float x = bixinho.x;
	float y = bixinho.y;
	float theta = bixinho.theta;
	float vision = 150;
	float angleVision = 105;
	//----- Draw the vision field -----//

	glColor3f(0.5, 0, 0);
	glBegin(GL_POLYGON);

	glVertex2d(x, y);

	float thetaD = theta*180.0/M_PI;
	for (float i = thetaD-angleVision/2; i<thetaD+angleVision/2; i+=15)
	{
		float posX = vision*cos(i/180.0*M_PI);
		float posY = vision*sin(i/180.0*M_PI);
		glVertex2d( posX + x, posY + y);
	}

	glEnd();


	//----- Desenha corpo do bixinho -----//
	glColor3f(bixinho.r, bixinho.g, bixinho.b);// Bixinho verde
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i+=15) {
		glVertex2d( radius*cos(i/180.0*M_PI) + x, radius*sin(i/180.0*M_PI) + y);
	}
	glEnd();



	//----- Desenha olho direito do bixinho -----//
	float eyeRadius = radius/8;
	float eyeDist = M_PI/6;

	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i+=20) {
		float shiftX = radius/2*cos(theta-eyeDist);
		float shiftY = radius/2*sin(theta-eyeDist);
		glVertex2d( eyeRadius*cos(i/180.0*M_PI) + x + shiftX, eyeRadius*sin(i/180.0*M_PI) + y + shiftY);
	}
	glEnd();

	//----- Desenha olho esquerdo do bixinho -----//
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i+=20) {
		float shiftX = radius/2*cos(theta+eyeDist);
		float shiftY = radius/2*sin(theta+eyeDist);

		glVertex2d( eyeRadius*cos(i/180.0*M_PI) + x + shiftX, eyeRadius*sin(i/180.0*M_PI) + y + shiftY);
	}
	glEnd();
}
