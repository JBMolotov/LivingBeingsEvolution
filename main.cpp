#include "Classes/base.h"

// Ambient terrain;
// Plant flora;
// Animal fauna;
//int info = {0, 0, 0};

//---------- Function prototypes ----------//
// void draw();
// void onObjects(Animal, Ambient);
// void bornConflict(Animal, Ambient);
// void timer(int); // loop
// void mouse(int button, int state, int x, int y);
// void once(); //do a function, one time
// void routineFauna(Animal, int);

//------------------ Main -----------------//
int main(int argc, char** argv)
{
	//srand(time(NULL));
	srand(4.20);

	Environment env = Environment();

	Window window = Window();
	window.draw = [&env](){ env.draw(); };
	window.run =  [&env](){ env.run(); };
	window.start();

	return 0;
}


//------------------ Timer -----------------//
// void timer(int)
// {
// 	routineFauna(fauna, QTTFAU);
// 	onObjects(fauna, terrain);
// 	//routineFlora();

// 	// Executa a função draw para desenhar novamente
// 	glutPostRedisplay();

// 	// O primeiro parâmetro define de quanto em quanto tempo em milissegundos timer será chaamdo
// 	// Eu coloquei 1000/60 para definir que vai atualizar a 60hz
// 	glutTimerFunc(1000/60, timer, 0);// Garante que esta função será chamada de novo
// }


// //------------------ Draw -----------------//
// void draw(){
// 	glClear(GL_COLOR_BUFFER_BIT);

// 	drawPlants(flora, QTTFLO);
// 	drawTerrain(terrain, QTTWAT, QTTOBT);

// 	drawAnimals(fauna, QTTFAU);

// 	drawFloraInfo(flora, QTTFLO);
// 	drawFaunaInfo(fauna, QTTFAU);
// 	//=========================================== DRAW THE POP
// 	glutSwapBuffers();
// }

// //-------------- functions ---------------//

// void once ()
// {
// 	terrain = createTerrain(QTTWAT, QTTOBT);
// 	floraCreate(flora, QTTFLO);
// 	faunaCreate(fauna, QTTFAU);
// 	bornConflict(fauna, terrain);
// }

// void routineFauna(Animal fauna, int qttpop)
// {
// 	//fugir (if the hunter is hunting
// 	for(int i = 0; i < qttpop; i++)
// 	{
		
// 		//hungry(fauna, i);
// 		thirstiness(fauna, i);
// 		if (strcmp(fauna[i].stats, "Drinking"))
// 		{
// 			if (fauna[i].thisrt <= fauna[i].maxthisrt/2)
// 			{
// 				strcpy(fauna[i].stats, "Searching water");
// 				//searchWater(fauna);
// 			}
// 			else
// 			{
// 				if(fauna[i].hunger <= fauna[i].maxhunger/2)
// 				{
// 					strcpy(fauna[i].stats, "Searching food");
// 					//searchFood(fauna);
// 				}
// 				else
// 				{
// 					strcpy(fauna[i].stats, "Wandering");
// 					randomWalk(fauna, i);
// 				}
// 			}
// 		}
// 		//rotasteBixinho(fauna, i, -1);
// 	}
	
// }

// bool isInside(int circle_x, int circle_y, float rad, int x, int y) 
// { 
//     // Compare radius of circle with distance  
//     // of its center from given point 
//     if ((x - circle_x) * (x - circle_x) + (y - circle_y) * (y - circle_y) <= rad * rad) 
//         return true; 
//     else
//         return false; 
// }

// int circle(int x1, int y1, int x2,  
//            int y2, int r1, int r2) 
// { 
//     int distSq = ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))/100; 
//     int radSumSq = ((r1 + r2) * (r1 + r2))/100; 
//     if (distSq == radSumSq) 
//         return 1; 
//     else if (distSq > radSumSq) 
//         return distSq; 
//     else
//         return 0; 
// } 

// void onObjects(Animal fauna, Ambient terrain)
// {
// 	for(int i = 0;i < QTTFAU; i++)
// 	{
// 		for(int j = 0; j < QTTWAT; j++)
// 		{
// 			if(isInside(terrain.lake[j].x, terrain.lake[j].y, terrain.lake[j].size, fauna[i].x, fauna[i].y))
// 			{
// 				if( !strcmp(fauna[i].stats, "Searching water") || !strcmp(fauna[i].stats, "Drinking"))
// 					drinkWater(fauna, i);
// 				else
// 				{
// 					fauna[i].speed = fauna[i].maxspeed/2;
// 					//strcat(fauna[i].stats, " (Water)");
// 				}
				
// 				break;	
// 			}
// 			else
// 			{
// 				fauna[i].speed = fauna[i].maxspeed;
// 			}
			
// 		}
// 		for(int j = 0; j < QTTOBT; j++)
// 		{
// 			if(isInside(terrain.lake[j].x, terrain.lake[j].y, terrain.lake[j].size, fauna[i].x, fauna[i].y))
// 			{
// 				fauna[i].speed = fauna[i].maxspeed/4;
// 				break;	
// 			}
// 			else
// 			{
// 				fauna[i].speed = fauna[i].maxspeed;
// 			}
// 		}
// 	}
// }

// void bornConflict(Animal fauna, Ambient terrain)
// {
// 	for(int i = 0;i < QTTFAU; i++)
// 	{
// 		for(int j = 0; j < QTTWAT; j++)
// 		{
// 			if(isInside(terrain.lake[j].x, terrain.lake[j].y, (terrain.lake[j].size+2), fauna[i].x, fauna[i].y))
// 			{
// 				fauna[i].x = rand() % 800;
// 				fauna[i].y = rand() % 600;
// 				bornConflict(fauna, terrain);
// 			}
// 		}

// 		for(int j = 0; j < QTTOBT; j++)
// 		{
// 			if(isInside(terrain.obstacle[j].x, terrain.obstacle[j].y, (terrain.obstacle[j].size+2), fauna[i].x, fauna[i].y))
// 			{
// 				fauna[i].x = rand() % 800;
// 				fauna[i].y = rand() % 600;
// 				bornConflict(fauna, terrain);
// 			}
// 		}
// 	}
// }

// //------------------ Mouse -----------------//
// void mouse(int button, int state, int x, int y)
// {
//   if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
//   {
// 	for (int i = 0; i < QTTFLO; i++)
// 	{
// 		if(isInside(flora[i].x, flora[i].y, flora[i].size, x, y))
// 		{
// 			if (!flora[i].showInfo)
// 			{
// 				flora[i].showInfo = 1;
// 			}
// 			else
// 			{
// 				flora[i].showInfo = 0;
// 			}
// 		}	
// 	}
// 	for (int i = 0; i < QTTFAU; i++)
// 	{
// 		if(isInside(fauna[i].x, fauna[i].y, fauna[i].size, x, y))
// 		{
// 			if (!fauna[i].showInfo)
// 			{
// 				fauna[i].showInfo = 1;
// 			}
// 			else
// 			{
// 				fauna[i].showInfo = 0;
// 			}
// 		}	
// 	}
//   }
// }

