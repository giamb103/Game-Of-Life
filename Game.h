#include <iostream>
using namespace std;

class Game
{
	public:
		Game();
		~Game();
		void classicMode(char** grid, char** tempGrid, int length, int width);
		void doughnutMode(char** grid, char** tempGrid, int length, int width);
		void mirrorMode(char** grid, char** tempGrid, int length, int width);
};
