#ifndef DEFINES_H
#define DEFINES_H


//---------------------------------//
//------- Window parameters -------//
//---------------------------------//
#define MAIN_WINDOW_WIDTH 800
#define MAIN_WINDOW_HEIGHT 600
#define WINDOW_RESIZABLE false
#define WINDOW_FULLSCREEN false
#define WINDOW_CURSOR_DISABLED false


//---------------------------------//
//----- Simulation parameters -----//
//---------------------------------//
#define QTYLAKE     4 // quantity of points of water
#define QTYOBSTACLE 8 // quantity of obstacles

#define MAXFAU 100 // max size of population
#define QTYFAU 10  // quantity initial of population
#define MAXFLO 50  // max size of population
#define QTYFLO 30  // quantity initial of plant


//---------------------------------//
//------ Terminal Color Code ------//
//---------------------------------//
// https://stackoverflow.com/questions/9158150/colored-output-in-c/9158263
// The following are UBUNTU/LINUX, and MacOS ONLY terminal color codes.
#define RESET   	"\033[0m"
#define BLACK   	"\033[30m"      		/* Black */
#define RED     	"\033[31m"      		/* Red */
#define GREEN   	"\033[32m"      		/* Green */
#define YELLOW  	"\033[33m"      		/* Yellow */
#define BLUE    	"\033[34m"      		/* Blue */
#define MAGENTA 	"\033[35m"      		/* Magenta */
#define CYAN    	"\033[36m"      		/* Cyan */
#define WHITE   	"\033[37m"      		/* White */
#define BOLDBLACK   "\033[1m\033[30m"      	/* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      	/* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      	/* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      	/* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      	/* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      	/* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      	/* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      	/* Bold White */


#endif //DEFINES_H
