#ifndef ANIMAL_H
#define ANIMAL_H

class Animal
{
	public:
		Animal();
		~Animal();

		void randomWalk();
		void rotate();
		void drink();
		void hungry();
		void dryness();
		void move();
		void create();
		void destroy();

		void draw();
		void run();
	private:
		float _x;
		float _y;
		float _size; 
		float _theta;
		//float r,g,b;

		float _life[2]; // how much life remaing and max life
		//lose other things when life drop
		float _thisrt[2]; // need to drink water or lose life
		int _feed; //plants or meet or both
		float _hunger[2]; // need to eat or lose life
		char _stats[20];
		float _vision; //skill to see things
		//locate with precision if do not has things blockin
		float _smell; //skill to smell things
		//locate the direction without precision
		//can smell from past things with less precision
		float _hear; //skill to listening things
		//locate the direction without precision
		float _speed[2]; //skill to moviment
		float _strenght; //skill to fight
		float _persist[2]; //how much they persist to do things
		bool _showStats;

};
#endif //ANIMAL_H


// typedef struct _animal{
	
// 	//? just ideas
// 	//float memory[2]; //can remenber a x and a y
// 	//float type; //land or water or fly

	
// }Animal[100];

