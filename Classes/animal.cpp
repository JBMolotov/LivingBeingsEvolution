#include "animal.h"

Animal::Animal()
{
	create();
}

Animal::~Animal()
{

}

void Animal::create()
{
	_x = rand() % MAIN_WINDOW_WIDTH;
	_y = rand() % MAIN_WINDOW_HEIGHT;
	_size = rand() % 25 + 10;
	_theta =  rand() % 6;
	_life[1] = rand() % 25 + 10;
	_life[0] = _life[1];
	_thisrt[1] = rand() % 25 + 10;
	_thisrt[0] = _thisrt[1];
	_feed = rand() % 3 - 1;
	_hunger[1] = rand() % 25 + 10;
	_hunger[0] = _hunger[1];
	strcpy(_stats, "Wandering");
	_vision = rand() % 150 + 50;
	_smell = rand() % 100 + 20;
	_hear = rand() % 100 + 50;
	_speed[1] = rand() % 100;
	_speed[0] = _speed[1];
	_strenght = rand() % 100;
	_persist[0] = 0;
	_persist[1] = rand() % 1000;

	_showStats = false;
}

void Animal::randomWalk()
{
	_persist[0] += 0.1;
	if (_persist[0] > _persist[1])
	{
		_persist[0] = 0;
		_persist[1] = rand() % 1000;
		_theta = rand() % 6;
	}
	move();
}


//substitiuir o side para o local pra onde ele quer
void Animal::rotate()
{//side -> -1 = clockwise, 1 = counter-clockwise;
	_theta+= (0.005 * 1);
	_theta= _theta >= 6.28 ? 0 : _theta;
	_theta= _theta <= -6.28 ? 0 : _theta;
}

void Animal::move()
{
	// Para mover para onde ele está olhando (na direção theta)
	_x = _x + (_speed[0]/1000) * cos(_theta);
	_y = _y + (_speed[0]/1000) * sin(_theta);

	//_x = _x>800 ? 800 : _x; //old way
	_x = _x> MAIN_WINDOW_WIDTH ? MAIN_WINDOW_WIDTH : _x;
	_x = _x<0 ? 0 : _x;
	_y = _y>MAIN_WINDOW_HEIGHT ? MAIN_WINDOW_HEIGHT : _y;
	_y = _y<0 ? 0 : _y;

	
	if (_x >= MAIN_WINDOW_WIDTH || _y >= MAIN_WINDOW_HEIGHT || _x <= 0 || _y <= 0)
		_theta = rand() % 6;

}

void Animal::drink()
{
	if (_thisrt[0] < _thisrt[1])
	{
		strcpy(_stats, "Drinking");
		_thisrt[0] += 0.2;
		_speed[0] = 0;
	}
	else
	{
		strcpy(_stats, "Wandering");
	}
	
}

void Animal::hungry()
{
	if (_hunger[0] <= 0)
	{
		_hunger[0] = 0;
		_life[0] -= 0.006;
		if(_life[0] <= 0)
		{
			_life[0] = 0;
		}
	}
	else
		_hunger[0] -= 0.01;
}

void Animal::dryness()
{
	if (_thisrt[0] <= 0)
	{
		_thisrt[0] = 0;
		_life[0] -= 0.001;
		if(_life[0] <= 0)
		{
			_life[0] = 0;
		}
	}
	else
		_thisrt[0] -= 0.002;
}


void Animal::draw(){
	float angleVision = 105;

	if(_showStats)
	{
		//----- Draw the smell field -----//
		glColor4f(0.5, 0.5, 0, 0.5);
		glBegin(GL_POLYGON);
		for (int i = 0; i < 360; i+=15) 
		{
			glVertex2d( _smell*cos(i/180.0*M_PI) + _x, _smell*sin(i/180.0*M_PI) + _y);
		}

		glEnd();
		
		//----- Draw the vision field -----//
		glColor4f(0.5, 0, 0, 0.5);
		glBegin(GL_POLYGON);

		glVertex2d(_x, _y);

		float thetaD = _theta*180.0/M_PI;
		for (float i = thetaD-angleVision/2; i<thetaD+angleVision/2; i+=15)
		{
			float posX = _vision*cos(i/180.0*M_PI);
			float posY = _vision*sin(i/180.0*M_PI);
			glVertex2d( posX + _x, posY + _y);
		}

		glEnd();

		
	}


	//----- Desenha corpo do bixinho -----//
	glColor3f(0.7, 0.5, 0.5);// Bixinho verde
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i+=15) {
		glVertex2d( _size*cos(i/180.0*M_PI) + _x, _size*sin(i/180.0*M_PI) + _y);
	}
	glEnd();



	//----- Desenha olho direito do bixinho -----//
	float eyeRadius = _size/8;
	float eyeDist = M_PI/6;

	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i+=20) {
		float shiftX = _size/2*cos(_theta-eyeDist);
		float shiftY = _size/2*sin(_theta-eyeDist);
		glVertex2d( eyeRadius*cos(i/180.0*M_PI) + _x + shiftX, eyeRadius*sin(i/180.0*M_PI) + _y + shiftY);
	}
	glEnd();

	//----- Desenha olho esquerdo do bixinho -----//
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i+=20) {
		float shiftX = _size/2*cos(_theta+eyeDist);
		float shiftY = _size/2*sin(_theta+eyeDist);

		glVertex2d( eyeRadius*cos(i/180.0*M_PI) + _x + shiftX, eyeRadius*sin(i/180.0*M_PI) + _y + shiftY);
	}
	glEnd();
	
}

// void Animal::drawStats( int qttpop)
// {
//     for (int i = 0; i < qttpop; i++)
//     {
//         if(_showInfo)
//         {
//             // Print info
//             char info[30]={'\0'};
//             sprintf(info, "Life %.1f/%.1f", _life, _maxlife);// Text
//             glColor3f(1.0,1.0,1.0);// Text color
//             glRasterPos2f( _x, _y + 5);// Print position
//             // Print each char
//             for(int j=0;j<30;j++){
//                 glutBitmapCharacter(GLUT_BITMAP_8_BY_13, info[j]);
//             }

// 			//print second line
// 			char info2[30]={'\0'};
// 			sprintf(info2, "Stats: ");// Text
// 			strcat(info2, _stats);
// 			glColor3f(1.0,1.0,1.0);// Text color
// 			glRasterPos2f( _x, _y + 15);// Print position
// 			// Print each char
//             for(int j=0;j<30;j++){
//                 glutBitmapCharacter(GLUT_BITMAP_8_BY_13, info2[j]);
//             }

// 			// Print info
//             char hunger[30]={'\0'};
//             sprintf(hunger, "Hunger: %.1f/%.1f", _hunger, _maxhunger);// Text
//             glColor3f(1.0,1.0,1.0);// Text color
//             glRasterPos2f( _x, _y + 25);// Print position
//             // Print each char
//             for(int j=0;j<30;j++){
//                 glutBitmapCharacter(GLUT_BITMAP_8_BY_13, hunger[j]);
//             }

// 			// Print info
//             char thirst[30]={'\0'};
//             sprintf(thirst, "Thirst: %.1f/%.1f", _thisrt, _maxthisrt);// Text
//             glColor3f(1.0,1.0,1.0);// Text color
//             glRasterPos2f( _x, _y + 35);// Print position
//             // Print each char
//             for(int j=0;j<30;j++){
//                 glutBitmapCharacter(GLUT_BITMAP_8_BY_13, thirst[j]);
//             }
//         }
//     }
// }

void Animal::run()
{
	dryness();
	if (strcmp(_stats, "Drinking"))
	{
		if (_thisrt[0] <= _thisrt[1]/2)
		{
			strcpy(_stats, "Searching water");
			//searchWater(fauna);
		}
		else
		{
			if(_hunger[0] <= _hunger[1]/2)
			{
				strcpy(_stats, "Searching food");
				//searchFood(fauna);
			}
			else
			{
				strcpy(_stats, "Wandering");
				randomWalk();
			}
		}
	}
	//rotasteBixinho(fauna, i, -1);
}