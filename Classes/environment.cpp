#include "environment.h"


Environment::Environment():
_qtyLake(QTYLAKE), _qtyObstacle(QTYOBSTACLE)
{
	createTerrain();

	for( int i = 0; i < QTYFLO; i++)
	{
		Plant* plant = new Plant;
		_flora.push_back(plant);
	}

	for( int j = 0; j < QTYFAU; j++)
	{
		Animal* animal = new Animal;
		_fauna.push_back(animal);
	}
}

Environment::~Environment()
{
	
}

void Environment::createTerrain() 
{
	for (int i = 0; i < _qtyLake; i++)
	{
		lake newlake;
		newlake.size = rand() % 100 + 50;
		newlake.x = rand() % MAIN_WINDOW_WIDTH;
		newlake.y = rand() % MAIN_WINDOW_HEIGHT;
		_lake.push_back(newlake);
	}
	

	for (int i = 0; i < _qtyObstacle; i++)
	{
		obstacle newobstacle;
		newobstacle.type = rand() % 3;
		newobstacle.size = rand() % 50;
		newobstacle.x = rand() % MAIN_WINDOW_WIDTH;
		newobstacle.y = rand() % MAIN_WINDOW_HEIGHT;
		_obstacle.push_back(newobstacle);
	}
	
	for (auto lke : _lake)
	{
		for (auto obt : _obstacle)
		{
			inWater(lke, obt);
		}
	}
}

void Environment::draw()
{
	for (auto l : _lake )
	{
		glColor3f(0, 0, 1); //blue
		glBegin(GL_POLYGON);
		for (int i = 0; i < 360; i+=15) {
			glVertex2d( l.size*cos(i/180.0*M_PI) + l.x, l.size*sin(i/180.0*M_PI) + l.y);
		}
		glEnd();
	}
	
	for (auto o : _obstacle)
	{
		switch (o.type)
		{
		case ROCK:
			glColor3f(0, 0, 0);
			glBegin(GL_POLYGON);
			for (int i = 0; i < 360; i+=15) {
				glVertex2d( o.size*cos(i/180.0*M_PI) + o.x, o.size*sin(i/180.0*M_PI) + o.y);
			}
			glEnd();
			break;
		
		case TREE:
			glColor3f(0, 0, 0);
			glBegin(GL_POLYGON);
			for (int i = 0; i < 360; i+=15) {
				glVertex2d( o.size*cos(i/180.0*M_PI) + o.x, o.size*sin(i/180.0*M_PI) + o.y);
			}
			glEnd();
			break;
		
		case ARBUST:
			glColor3f(0, 0, 0);
			glBegin(GL_POLYGON);
			for (int i = 0; i < 360; i+=15) {
				glVertex2d( o.size*cos(i/180.0*M_PI) + o.x, o.size*sin(i/180.0*M_PI) + o.y);
			}
			glEnd();
			break;
		
		default:
			break;
		}
	}

	for (auto p : _flora)
	{
		p->draw();
	}

	for (auto a : _fauna)
	{
		a->draw();
	}
}


void Environment::inWater (lake lke, obstacle obt) //not tottally effective, but low the chances
{
	while ((lke.x - obt.x) > lke.size)
	{
		obt.x = rand() % MAIN_WINDOW_WIDTH;
	}

	while ((lke.y - obt.y) > lke.size)
	{
		obt.y = rand() % MAIN_WINDOW_HEIGHT;
	}
}


void Environment::run()
{
	for (auto animal : _fauna)
	{
		animal->run();
	}

	for (auto plant : _flora)
	{
		plant->run();
	}
}