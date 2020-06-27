#include "plant.h"

Plant::Plant()
{
	create();
}

Plant::~Plant()
{

}

void Plant::create()
{
	_x = rand() % MAIN_WINDOW_WIDTH;
	_y = rand() % MAIN_WINDOW_HEIGHT;
	_size = rand() % 15 + 5;
	_life[1] = rand() % 15 + 5;
	_life[0] = _life[1];
	_grow = (rand()%100)/10000.0f;
}

void Plant::draw()
{
	glColor3f(0.19, 0.8, 0.19); //other green
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i+=15)
	{
		glVertex2d( _size*cos(i/180.0*M_PI) + _x,  _size*sin(i/180.0*M_PI) + _y);
		i+=25;
		glVertex2d((_size+8)*cos(i/180.0*M_PI) + _x,  (_size+8)*sin(i/180.0*M_PI) + _y);
	}
	glEnd();
}

// void Plant::drawInfo()
// {
// 	if(flora[i].showInfo)
// 	{
// 		// Print info
// 		char info[30]={'\0'};
// 		sprintf(info, "Life %.1f/%.1f", flora[i].life, flora[i].maxlife);// Text
// 		glColor3f(1.0,1.0,1.0);// Text color
// 		glRasterPos2f( flora[i].x, flora[i].y + 5);// Print position
// 		// Print each char
// 		for(int j=0;j<30;j++){
// 			glutBitmapCharacter(GLUT_BITMAP_8_BY_13, info[j]);
// 		}

// 		//print second line
// 		char info2[30]={'\0'};
// 		sprintf(info2, "Grow factor: %.1f", flora[i].grow*1000);// Text
// 		glColor3f(1.0,1.0,1.0);// Text color
// 		glRasterPos2f( flora[i].x, flora[i].y + 15);// Print position
// 		// Print each char
// 		for(int j=0;j<30;j++){
// 			glutBitmapCharacter(GLUT_BITMAP_8_BY_13, info2[j]);
// 		}
// 	}
// }

void Plant::run()
{
	
}