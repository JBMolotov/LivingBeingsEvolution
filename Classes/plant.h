class Plant
{
	public:
		Plant();
		~Plant();

		void create();
		void destroy();

		void draw();
		void run();
	private:
		int _x; int _y;
		float _size; // are the size
		float _life[2]; // how much life remaing
		float _grow; // how much recover life per second
		int _showInfo; // show the info in screen
		//? ideas
		//float toxicity;
};
//#endif //PLANT_H

