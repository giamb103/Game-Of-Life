#include <iostream>
#include <fstream>
#include <string>
using namespace std; //Edgar Delgado

class Grid
{
	private:
		bool halt;
		int generation;
		int length, width;
		int choice, printChoice;
		float density;
		char** grid1;
		char** grid2;
		string fileName, line;

	public:
		Grid();
		~Grid();

		void setLength(int length);
		int getLength();
		void setWidth(int width);
		int getWidth();

		void copyGrid(char** gridA, char** gridB);
		void printGrid(char** grid);
		void populateGrid(char** grid, float density);
		void promptUser(int response);
		void readFiles(char* fileName);
		bool emptyGrid(char** grid, int length, int width);
		bool stabilizeGrid(char** gridA, char** gridB);
};
