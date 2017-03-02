#include "Game.h"

Game::Game()
{

}

Game::~Game()
{
	cout << "Object Destroyed" << endl;
}

void Game::classicMode(char** grid, char** tempGrid, int length, int width)
{
	/*
		1. If a location has ONE or fewer neighbors, the location will be empty in the next generation.
		2. If a location has TWO neighbors, the location stays stable (stays the same).
		3. If a location has THREE neighbors, the location will have a cell in the next generation if doesnt already have one.
		4. If a location has FOUR or MORE neigbors, the location will be empty in the next generation.
		5. Copy all the locations from grid1(Current Generation) to the tempGrid(Next GEneration).
	*/
	for(int i = 0; i < length; ++i)
	{
		for(int j = 0; j < width; ++j)
		{
			int count = 0; 
			if(i == 0 && j == 0){ // Checks the first location on the first row (the upper left corner)
				if(grid[i][j+1] == 'X' || grid[i][j+1] == 'x') count++;
				if(grid[i+i][j] == 'X' || grid[i+i][j] == 'x') count++;
				if(grid[i+1][j+1] == 'X' || grid[i+1][j+1] == 'x') count++;
				if(count == 0 || count == 1) tempGrid[i][j] = '-';
				if(count == 2) tempGrid[i][j] = grid[i][j];
				if(count == 3) tempGrid[i][j] = 'X';
				continue;
			}
			else if(i == 0 && j == (width-1)) { // Checks the last location of the first row (the upper right corner)
				if(grid[i][j-2] == 'X' || grid[i][j-2] == 'x') count++;
				if(grid[i+1][j-2] == 'X' || grid[i+1][j-2] == 'x') count++;
				if(grid[i+1][j-1] == 'X' || grid[i+1][j-1] == 'x') count++;
				if(count == 0 || count == 1) tempGrid[i][j] = '-';
				if(count == 2) tempGrid[i][j] = grid[i][j];
				if(count == 3) tempGrid[i][j] = 'X';
				continue;
			}
			else if(i == 0 && j != (width-1)){ // Checks any other location in the first row (except the corners)
				if(grid[i][j-1] == 'X' || grid[i][j-1] == 'x') count++;
				if(grid[i+1][j-1] == 'X' || grid[i+1][j-1] == 'x') count++;
				if(grid[i+1][j] == 'X' || grid[i+1][j] == 'x') count++;
				if(grid[i+1][j+1] == 'X' || grid[i+1][j+1] == 'x') count++;
				if(grid[i][j+1] == 'X' || grid[i][j+1] == 'x') count++;
				if(count == 0 || count == 1) tempGrid[i][j] = '-';
				if(count == 2) tempGrid[i][j] = grid[i][j];
				if(count == 3) tempGrid[i][j] = 'X';
				if(count == 4 || count == 5) tempGrid[i][j] = '-';
				continue;
			}
			else if(j == 0 && i != 0 && i != (length-1)){ // Checks the first column in between the corners
				if(grid[i-1][j] == 'X' || grid[i-1][j] == 'x') count++;
				if(grid[i-1][j+1] == 'X' || grid[i-1][j+1] == 'x') count++;
				if(grid [i][j+1] == 'X' || grid [i][j+1] == 'x') count++;
				if(grid[i+1][j+1] == 'X' || grid[i+1][j+1] == 'x') count++;
				if(grid[i+1][j] == 'X' || grid[i+1][j] == 'x') count++;
				if(count == 0 || count == 1) tempGrid[i][j] = '-';
				if(count == 2) tempGrid[i][j] = grid[i][j];
				if(count == 3) tempGrid[i][j] = 'X';
				if(count == 4 || count == 5) tempGrid[i][j] = '-';
				continue;
			}
			else if(j == 0 && i == (length-1)){ // Checks the bottom left corner of the first column
				if(grid[i-1][j] == 'X' || grid[i-1][j] == 'x') count++;
				if(grid[i-1][j+1] == 'X' || grid[i-1][j+1] == 'x') count++;
				if(grid[i][j+1] == 'X' || grid[i][j+1] == 'x') count++;
				if(count == 0 || count == 1) tempGrid[i][j] = '-';
				if(count == 2) tempGrid[i][j] = grid[i][j];
				if(count == 3) tempGrid[i][j] = 'X';
				continue;
			}
			else if(j == (width-1) && i != 0 && i != (length-1)){ // Checks inbetween locations from the corners of the last column
				if(grid[i-1][j] == 'X' || grid[i-1][j] == 'x') count++;
				if(grid[i-1][j-1] == 'X' || grid[i-1][j-1] == 'x') count++;
				if(grid[i][j-1] == 'X' || grid[i][j-1] == 'x') count++;
				if(grid[i+1][j-1] == 'X' || grid[i+1][j-1] == 'x') count++;
				if(grid[i+1][j+1] == 'X' || grid[i+1][j+1] == 'x') count++;
				if(count == 0 || count == 1) tempGrid[i][j] = '-';
				if(count == 2) tempGrid[i][j] = grid[i][j];
				if(count == 3) tempGrid[i][j] = 'X';
				if(count == 4 || count == 5) tempGrid[i][j] = '-';
				continue;
			}
			else if(i == (length-1) && j != 0 && j!= (width-1)) // Checks inbetween locations from the corners of the bottom row
			{
				if(grid[i][j-1] == 'X' || grid[i][j-1] == 'x') count++;
				if(grid[i-1][j-1] == 'X' || grid[i-1][j-1] == 'x') count++;
				if(grid[i-1][j] == 'X' || grid[i-1][j] == 'x') count++;
				if(grid[i-1][j+1] == 'X' || grid[i-1][j+1] == 'x') count++;
				if(grid[i][j+1] == 'X' || grid[i][j+1] == 'x') count++;
				if(count == 0 || count == 1) tempGrid[i][j] = '-';
				if(count == 2) tempGrid[i][j] = grid[i][j];
				if(count == 3) tempGrid[i][j] = 'X';
				if(count == 4 || count == 5) tempGrid[i][j] = '-';
				continue;				
			}
			else if(i == (length-1) && i == (width-1)) { // Checking for the last location (bottom right corner)
				if(grid[i][j-1] == 'X' || grid[i][j-1] == 'x') count++;
				if(grid[i-1][j-1] == 'X' || grid[i-1][j-1] == 'x') count++;
				if(grid[i-1][j] == 'X' || grid[i-1][j] == 'x') count++;
				if(count == 0 || count == 1) tempGrid[i][j] = '-';
				if(count == 2) tempGrid[i][j] = grid[i][j];
				if(count == 3) tempGrid[i][j] = 'X';
				continue;
			}
			else { // Checks for any other location that is not in the border of the grid
				if(grid[i-1][j-1] == 'X' || grid[i-1][j-1] == 'x') count++;
				if(grid[i-1][j] == 'X' || grid[i-1][j] == 'x') count++;
				if(grid[i-1][j+1] == 'X' || grid[i-1][j+1] == 'x') count++;
				if(grid[i][j+1] == 'X' || grid[i][j+1] == 'x') count++;
				if(grid[i+1][j+1] == 'X' || grid[i+1][j+1] == 'x') count++;
				if(grid[i+1][j] == 'X' || grid[i+1][j] == 'x') count++;
				if(grid[i+1][j-1] == 'X' || grid[i+1][j-1] == 'x') count++;
				if(grid[i][j-1] == 'X' || grid[i][j-1] == 'x') count++;
				if(count == 0 || count == 1) tempGrid[i][j] = '-';
				if(count == 2) tempGrid[i][j] = grid[i][j];
				if(count == 3) tempGrid[i][j] = 'X';
				if(count == 4 || count == 5 || count == 6 || count == 7 || count == 8) tempGrid[i][j] = '-';
				continue;	
			}
		}
	}

}

void Game::doughnutMode(char** grid, char** tempGrid, int length, int width)
{
	for(int i = 0; i < length; ++i)
	{
		for(int j = 0; j < width; ++j)
		{
			int count = 0;

			if(i == 0 && j == 0){ // Checks the first location on the first row (the upper left corner)
				if(grid[length-1][j] == 'X' || grid[length-1][j] == 'x') count++;
				if(grid[length-1][j+1] == 'X' || grid[length-1][j+1] == 'x') count++;
				if(grid[i][width-1] == 'X' || grid[i][width-1] == 'x') count++;
				if(grid[i+1][width-1] == 'X' || grid[i+1][width-1] == 'x') count++;
				if(grid[i][j+1] == 'X' || grid[i][j+1] == 'x') count++;
				if(grid[i+i][j] == 'X' || grid[i+i][j] == 'x') count++;
				if(grid[i+1][j+1] == 'X' || grid[i+1][j+1] == 'X') count++;
				if(count == 0 || count == 1) tempGrid[i][j] = '-';
				if(count == 2) tempGrid[i][j] = grid[i][j];
				if(count == 3) tempGrid[i][j] = 'X';
				if(count == 4 || count == 5 || count == 6 || count == 7) tempGrid[i][j] = '-';
				continue;
			}

			else if(i == 0 && j == (width-1)) { // Checks the last location of the first row (the upper right corner)
				if(grid[0][0] == 'X' || grid[0][0] == 'x') count++;
				if(grid[1][0] == 'X' || grid[1][0] == 'x') count++;
				if(grid[width-1][length-1] == 'X' || grid[width-1][length-1] == 'x') count++;
				if(grid[width-1][length-2] == 'X' || grid[width-1][length-2] == 'x') count++;
				if(grid[i][j-2] == 'X' || grid[i][j-2] == 'x') count++;
				if(grid[i+1][j-2] == 'X' || grid[i+1][j-2] == 'x') count++;
				if(grid[i+1][j-1] == 'X' || grid[i+1][j-1] == 'x') count++;
				if(count == 0 || count == 1) tempGrid[i][j] = '-';
				if(count == 2) tempGrid[i][j] = grid[i][j];
				if(count == 3) tempGrid[i][j] = 'X';
				if(count == 4 || count == 5 || count == 6 || count == 7) tempGrid[i][j] = '-';
				continue;
			}	

			else if(j == 0 && i == (length-1)){ // Checks the bottom left corner of the first column
				if(grid[length-2][width-1] == 'X' || grid[length-2][width-1] == 'x') count++;
				if(grid[length-1][width-1] == 'X' || grid[length-1][width-1] == 'x') count++;
				if(grid[0][j] == 'X' || grid[0][j] == 'x') count++;
				if(grid[0][j+1] == 'X' || grid[0][j+1] == 'x') count++;
				if(grid[i-1][j] == 'X' || grid[i-1][j] == 'x') count++;
				if(grid[i-1][j+1] == 'X' || grid[i-1][j+1] == 'x') count++;
				if(grid[i][j+1] == 'X' || grid[i][j+1] == 'x') count++;
				if(count == 0 || count == 1) tempGrid[i][j] = '-';
				if(count == 2) tempGrid[i][j] = grid[i][j];
				if(count == 3) tempGrid[i][j] = 'X';
				if(count == 4 || count == 5 || count == 6 || count == 7) tempGrid[i][j] = '-';
				continue;
			}

			else if(i == (length-1) && i == (width-1)) { // Checking for the last location (bottom right corner)
				if(grid[length-2][0] == 'X' || grid[length-2][0] == 'x') count++;
				if(grid[length-1][0] == 'X' || grid[length-1][0] == 'x') count++;
				if(grid[0][width-2] == 'X' || grid[0][width-2] == 'x') count++;
				if(grid[0][width-1] == 'X' || grid[0][width-1] == 'x') count++;
				if(grid[i][j-1] == 'X' || grid[i][j-1] == 'x') count++;
				if(grid[i-1][j-1] == 'X' || grid[i-1][j-1] == 'x') count++;
				if(grid[i-1][j] == 'X' || grid[i-1][j] == 'x') count++;
				if(count == 0 || count == 1) tempGrid[i][j] = '-';
				if(count == 2) tempGrid[i][j] = grid[i][j];
				if(count == 3) tempGrid[i][j] = 'X';
				if(count == 4 || count == 5 || count == 6 || count == 7) tempGrid[i][j] = '-';
				continue;
			}

			else if(i == 0 && j != (width-1)){ // Checks any other location in the first row (except the corners)
				if(grid[length-1][j-1] == 'X' || grid[length-1][j-1] == 'x') count++;
				if(grid[length-1][j] == 'X' || grid[length-1][j] == 'x') count++;
				if(grid[length-1][j+1] == 'X' || grid[length-1][j+1] == 'x') count++;
				if(grid[i][j-1] == 'X' || grid[i][j-1] == 'x') count++;
				if(grid[i+1][j-1] == 'X' || grid[i+1][j-1] == 'x') count++;
				if(grid[i+1][j] == 'X' || grid[i+1][j] == 'x') count++;
				if(grid[i+1][j+1] == 'X' || grid[i+1][j+1] == 'x') count++;
				if(grid[i][j+1] == 'X' || grid[i][j+1] == 'x') count++;
				if(count == 0 || count == 1) tempGrid[i][j] = '-';
				if(count == 2) tempGrid[i][j] = grid[i][j];
				if(count == 3) tempGrid[i][j] = 'X';
				if(count == 4 || count == 5 || count == 6 || count == 7 || count == 8) tempGrid[i][j] = '-';
				continue;
			}

			else if(j == 0 && i != 0 && i != (length-1)){ // Checks the first column in between the corners
				if(grid[i-1][width-1] == 'X' || grid[i-1][width-1] == 'x') count++;
				if(grid[i][width-1] == 'X' || grid[i][width-1] == 'x') count++;
				if(grid[i+1][width-1] == 'X' || grid[i+1][width-1] == 'x') count++;
				if(grid[i-1][j] == 'X' || grid[i-1][j] == 'x') count++;
				if(grid[i-1][j+1] == 'X' || grid[i-1][j+1] == 'x') count++;
				if(grid [i][j+1] == 'X' || grid [i][j+1] == 'x') count++;
				if(grid[i+1][j+1] == 'X' || grid[i+1][j+1] == 'x') count++;
				if(grid[i+1][j] == 'X' || grid[i+1][j] == 'x') count++;
				if(count == 0 || count == 1) tempGrid[i][j] = '-';
				if(count == 2) tempGrid[i][j] = grid[i][j];
				if(count == 3) tempGrid[i][j] = 'X';
				if(count == 4 || count == 5 || count == 6 || count == 7 || count == 8) tempGrid[i][j] = '-';
				continue;
			}

			else if(j == (width-1) && i != 0 && i != (length-1)){ // Checks inbetween locations from the corners of the last column
				if(grid[i-1][0] == 'X' || grid[i-1][0] == 'x') count++;
				if(grid[i][0] == 'X' || grid[i][0] == 'x') count++;
				if(grid[i+1][0] == 'X' || grid[i+1][0] == 'x') count++;
				if(grid[i-1][j] == 'X' || grid[i-1][j] == 'x') count++;
				if(grid[i-1][j-1] == 'X' || grid[i-1][j-1] == 'x') count++;
				if(grid[i][j-1] == 'X' || grid[i][j-1] == 'x') count++;
				if(grid[i+1][j-1] == 'X' || grid[i+1][j-1] == 'x') count++;
				if(grid[i+1][j+1] == 'X' || grid[i+1][j+1] == 'x') count++;
				if(count == 0 || count == 1) tempGrid[i][j] = '-';
				if(count == 2) tempGrid[i][j] = grid[i][j];
				if(count == 3) tempGrid[i][j] = 'X';
				if(count == 4 || count == 5 || count == 6 || count == 7 || count == 8) tempGrid[i][j] = '-';
				continue;
			}

			else if(i == (length-1) && j != 0 && j!= (width-1)) // Checks inbetween locations from the corners of the bottom row
			{
				if(grid[0][j-1] == 'X' || grid[0][j-1] == 'x') count++;
				if(grid[0][j] == 'X' || grid[0][j] == 'x') count++;
				if(grid[0][j+1] == 'X' || grid[0][j+1] == 'x') count++;
				if(grid[i][j-1] == 'X' || grid[i][j-1] == 'x') count++;
				if(grid[i-1][j-1] == 'X' || grid[i-1][j-1] == 'x') count++;
				if(grid[i-1][j] == 'X' || grid[i-1][j] == 'x') count++;
				if(grid[i-1][j+1] == 'X' || grid[i-1][j+1] == 'x') count++;
				if(grid[i][j+1] == 'X' || grid[i][j+1] == 'x') count++;
				if(count == 0 || count == 1) tempGrid[i][j] = '-';
				if(count == 2) tempGrid[i][j] = grid[i][j];
				if(count == 3) tempGrid[i][j] = 'X';
				if(count == 4 || count == 5 || count == 6 || count == 7 || count == 8) tempGrid[i][j] = '-';
				continue;				
			}

			else { // Checks for any other location that is not in the border of the grid
				if(grid[i-1][j-1] == 'X' || grid[i-1][j-1] == 'x') count++;
				if(grid[i-1][j] == 'X' || grid[i-1][j] == 'x') count++;
				if(grid[i-1][j+1] == 'X' || grid[i-1][j+1] == 'x') count++;
				if(grid[i][j+1] == 'X' || grid[i][j+1] == 'x') count++;
				if(grid[i+1][j+1] == 'X' || grid[i+1][j+1] == 'x') count++;
				if(grid[i+1][j] == 'X' || grid[i+1][j] == 'x') count++;
				if(grid[i+1][j-1] == 'X' || grid[i+1][j-1] == 'x') count++;
				if(grid[i][j-1] == 'X' || grid[i][j-1] == 'x') count++;
				if(count == 0 || count == 1) tempGrid[i][j] = '-';
				if(count == 2) tempGrid[i][j] = grid[i][j];
				if(count == 3) tempGrid[i][j] = 'X';
				if(count == 4 || count == 5 || count == 6 || count == 7 || count == 8) tempGrid[i][j] = '-';
				continue;	
			}
		}
	}
}

void Game::mirrorMode(char** grid, char** tempGrid, int length, int width)
{
	/*
		1. If a location has ONE or fewer neighbors, the location will be empty in the next generation.
		2. If a location has TWO neighbors, the location stays stable (stays the same).
		3. If a location has THREE neighbors, the location will have a cell in the next generation if doesnt already have one.
		4. If a location has FOUR or MORE neigbors, the location will be empty in the next generation.
		5. Copy all the locations from grid1(Current Generation) to the tempGrid(Next GEneration).
		6. Mirror mode reflects that current edge space onto the border.
		7. If that space is occupied then it counts as two spaces occupied.
	*/
	for(int i = 0; i < length; ++i)
	{
		for(int j = 0; j < width; ++j)
		{
			//cout << i <<" "<< j << endl;
			int count = 0; 
			if(i == 0 && j == 0){ // Checks the first location on the first row (the upper left corner)
				if(grid[i][j] == 'X' || grid[i][j] == 'x'){
					count += 3;
				}
				if(grid[i][j+1] == 'X' || grid[i][j+1] == 'x') count++;
				if(grid[i+i][j] == 'X' || grid[i][j+1] == 'x') count++;
				if(grid[i+1][j+1] == 'X' || grid[i][j+1] == 'x') count++;
				//cout<< "neighbors " << count << endl;
				if(count == 0 || count == 1) tempGrid[i][j] = '-';
				if(count == 2) tempGrid[i][j] = grid[i][j];
				if(count == 3) tempGrid[i][j] = 'X';
				if(count >= 4) tempGrid[i][j] = '-';
				continue;
			}
			if(i == 0 && j == (width-1)) { // Checks the last location of the first row (the upper right corner)
				if(grid[i][j] == 'X' || grid[i][j] == 'x'){
					count +=3;
				}
				if(grid[i][j-2] == 'X' || grid[i][j+1] == 'x') count++;
				if(grid[i+1][j-2] == 'X' || grid[i][j+1] == 'x') count++;
				if(grid[i+1][j-1] == 'X' || grid[i][j+1] == 'x') count++;
				//cout<< "neighbors " << count << endl;
				if(count == 0 || count == 1) tempGrid[i][j] = '-';
				if(count == 2) tempGrid[i][j] = grid[i][j];
				if(count == 3) tempGrid[i][j] = 'X';
				if(count >= 4) tempGrid[i][j] = '-';
				continue;
			}
			if(i == 0 && j != (width-1)){ // Checks any other location in the first row (except the corners)
				if(grid[i][j] == 'X' || grid[i][j] == 'x') count++;
				if(grid[i][j-1] == 'X' || grid[i][j+1] == 'x') count++;
				if(grid[i+1][j-1] == 'X' || grid[i][j+1] == 'x') count++;
				if(grid[i+1][j] == 'X' || grid[i][j+1] == 'x') count++;
				if(grid[i+1][j+1] == 'X' || grid[i][j+1] == 'x') count++;
				if(grid[i][j+1] == 'X' || grid[i][j+1] == 'x') count++;
				//cout<< "neighbors " << count << endl;
				if(count == 0 || count == 1) tempGrid[i][j] = '-';
				if(count == 2) tempGrid[i][j] = grid[i][j];
				if(count == 3) tempGrid[i][j] = 'X';
				if(count >= 4) tempGrid[i][j] = '-';
				continue;
			}
			if(j == 0 && i != 0 && i != (length-1)){ // Checks the first column in between the corners
				if(grid[i][j] == 'X' || grid[i][j] == 'x') count++;
				if(grid[i-1][j] == 'X' || grid[i][j+1] == 'x') count++;
				if(grid[i-1][j+1] == 'X' || grid[i][j+1] == 'x') count++;
				if(grid [i][j+1] == 'X' || grid[i][j+1] == 'x') count++;
				if(grid[i+1][j+1] == 'X' || grid[i][j+1] == 'x') count++;
				if(grid[i+1][j] == 'X' || grid[i][j+1] == 'x') count++;
				//cout<< "neighbors " << count << endl;
				if(count == 0 || count == 1) tempGrid[i][j] = '-';
				if(count == 2) tempGrid[i][j] = grid[i][j];
				if(count == 3) tempGrid[i][j] = 'X';
				if(count >= 4) tempGrid[i][j] = '-';
				continue;
			}
			if(j == 0 && i == (length-1)){ // Checks the bottom left corner of the first column
				if(grid[i][j] == 'X' || grid[i][j] == 'x'){
					count +=3;
				}
				if(grid[i-1][j] == 'X' || grid[i][j+1] == 'x') count++;
				if(grid[i-1][j+1] == 'X' || grid[i][j+1] == 'x') count++;
				if(grid[i][j+1] == 'X' || grid[i][j+1] == 'x') count++;
				//cout<< "neighbors " << count << endl;
				if(count == 0 || count == 1) tempGrid[i][j] = '-';
				if(count == 2) tempGrid[i][j] = grid[i][j];
				if(count == 3) tempGrid[i][j] = 'X';
				if(count >= 4) tempGrid[i][j] = '-';
				continue;
			}
			if(j == (width-1) && i != 0 && i != (length-1)){ // Checks inbetween locations from the corners of the last column
				if(grid[i][j] == 'X' || grid[i][j] == 'x') count++;
				if(grid[i-1][j] == 'X' || grid[i][j+1] == 'x') count++;
				if(grid[i-1][j-1] == 'X' || grid[i][j+1] == 'x') count++;
				if(grid[i][j-1] == 'X' || grid[i][j+1] == 'x') count++;
				if(grid[i+1][j-1] == 'X' || grid[i][j+1] == 'x') count++;
				if(grid[i+1][j+1] == 'X' || grid[i][j+1] == 'x') count++;
				//cout<< "neighbors " << count << endl;
				if(count == 0 || count == 1) tempGrid[i][j] = '-';
				if(count == 2) tempGrid[i][j] = grid[i][j];
				if(count == 3) tempGrid[i][j] = 'X';
				if(count >= 4) tempGrid[i][j] = '-';
				continue;
			}
			if(i == (length-1) && j != 0 && j!= (width-1)) // Checks inbetween locations from the corners of the bottom row
			{
				if(grid[i][j] == 'X' || grid[i][j] == 'x') count++;
				if(grid[i][j-1] == 'X' || grid[i][j+1] == 'x') count++;
				if(grid[i-1][j-1] == 'X' || grid[i][j+1] == 'x') count++;
				if(grid[i-1][j] == 'X' || grid[i][j+1] == 'x') count++;
				if(grid[i-1][j+1] == 'X' || grid[i][j+1] == 'x') count++;
				if(grid[i][j+1] == 'X' || grid[i][j+1] == 'x') count++;
				//cout<< "neighbors " << count << endl;
				if(count == 0 || count == 1) tempGrid[i][j] = '-';
				if(count == 2) tempGrid[i][j] = grid[i][j];
				if(count == 3) tempGrid[i][j] = 'X';
				if(count >= 4) tempGrid[i][j] = '-';
				continue;				
			}
			if(i == (length-1) && j == (width-1)) { // Checking for the last location (bottom right corner)
				if(grid[i][j] == 'X' || grid[i][j] == 'x'){
					count +=3;
				}
				if(grid[i][j-1] == 'X' || grid[i][j+1] == 'x') count++;
				if(grid[i-1][j-1] == 'X' || grid[i][j+1] == 'x') count++;
				if(grid[i-1][j] == 'X' || grid[i][j+1] == 'x') count++;
				//cout<< "neighbors " << count << endl;
				if(count == 0 || count == 1) tempGrid[i][j] = '-';
				if(count == 2) tempGrid[i][j] = grid[i][j];
				if(count == 3) tempGrid[i][j] = 'X';
				if(count >= 4) tempGrid[i][j] = '-';
				continue;
			}
			else { // Checks for any other location that is not in the border of the grid
				if(grid[i-1][j-1] == 'X' || grid[i][j+1] == 'x') count++;
				if(grid[i-1][j] == 'X' || grid[i][j+1] == 'x') count++;
				if(grid[i-1][j+1] == 'X' || grid[i][j+1] == 'x') count++;
				if(grid[i][j+1] == 'X' || grid[i][j+1] == 'x') count++;
				if(grid[i+1][j+1] == 'X' || grid[i][j+1] == 'x') count++;
				if(grid[i+1][j] == 'X' || grid[i][j+1] == 'x') count++;
				if(grid[i+1][j-1] == 'X' || grid[i][j+1] == 'x') count++;
				if(grid[i][j-1] == 'X' || grid[i][j+1] == 'x') count++;
				//cout<< "neighbors " << count << endl;
				if(count == 0 || count == 1) tempGrid[i][j] = '-';
				if(count == 2) tempGrid[i][j] = grid[i][j];
				if(count == 3) tempGrid[i][j] = 'X';
				if(count == 4 || count == 5 || count == 6 || count == 7 || count == 8) tempGrid[i][j] = '-';
				continue;	
			}
		}
	}
}
