#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#define ROCK 0
#define TREE 1
#define ARBUST 2

#include <vector>
#include "plant.cpp"
#include "animal.cpp"


typedef struct lake{
	int x, y;
	float size;
}Lake;

typedef struct obstacle{
	int type;  //rock or tree or arbust
	int x, y;
	float size;
}Obstacle;

class Environment
{
	public:
		Environment();
		~Environment();

		void inWater(lake, obstacle);
		void drawWater();
		void drawObstacles(obstacle);
		void createTerrain();

		void draw();
		void run();
	private:
		int _qtyLake;
		int _qtyObstacle;

		std::vector <lake> _lake;
		std::vector <obstacle> _obstacle;

		std::vector <Plant*> _flora; 
		std::vector <Animal*> _fauna; 
};
#endif // ENVIRONMENT_H



