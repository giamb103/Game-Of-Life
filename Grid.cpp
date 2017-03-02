#include "Grid.h"
#include "Game.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

Grid::Grid()
{
	generation = 0;
	halt = false;
}

Grid::~Grid()
{
	//exit(4);
	for(int i = 0; i < length; ++i)
	{
		delete [] grid1[i];
		delete [] grid2[i];
	}
	delete [] grid1;
	delete [] grid2;
	cout << "Object destroyed" << endl;
}

void Grid::setLength(int length)
{
	this->length = length;
}
int Grid::getLength()
{
	return length;
}
void Grid::setWidth(int width)
{
	this->width = width;
}
int Grid::getWidth()
{
	return width;
}

void Grid::copyGrid(char** gridA, char** gridB)
{
	for(int i = 0; i < length; ++i)
	{
		for(int j = 0; j < width; ++j)
		{
			gridA[i][j] = gridB[i][j];
		}
	}
}

void Grid::printGrid(char** grid)
{
	for(int i = 0; i < length; i++)
	{
		for(int j = 0; j < width; j++)
		{
			cout << grid[i][j];
		}
		cout << endl;
	}
}

void Grid::populateGrid(char** grid, float density)
{
	float newDensity = density * 100;
	int count = 0;
	double populated;
	
	for(int i = 0; i < length; ++i){
		for(int j = 0; j < width; ++j){
			populated = rand() % 100 + 1;

			if(populated <= newDensity && count < newDensity){
				grid[i][j] = 'X';
				count++;
			}
			else
				grid[i][j] = '-';
		}
	}
}

bool Grid::emptyGrid(char** grid, int length, int width)
{
	bool isEmpty = true;
	for(int i = 0; i < length; ++i)
	{
		for(int j = 0; j < width; ++j)
		{
			if(grid[i][j] != '-') isEmpty = false;
		}
	}
	return isEmpty;
}

bool Grid::stabilizeGrid(char** gridA, char** gridB)
{
	bool isStable = true;
	for(int i = 0; i < length; ++i)
	{
		for(int j = 0; j < width; ++j)
		{
			if(gridA[i][j] != gridB[i][j]) isStable = false;
		}
	}
	return isStable;
}

void Grid::promptUser(int response)
{
	Game firstGame;

	if(response == 1) //A Map File
	{
		ifstream file; 
		cout << "Enter the file name: " << endl;
		cin >> fileName;
		const char* fName = fileName.c_str();
		
		file.open(fName);
		int lineCount = 0;
		if(file.is_open())
		{
			while(getline(file, line)) //Loops through the lines of the file
			{
				if(lineCount == 0){ //This if statement is trying to get the size for length
					length = atoi(line.c_str());
					lineCount++;
					continue;
				}
				if(lineCount == 1){ //This if statement is trying to get the size for width
					width = atoi(line.c_str());
					lineCount++;
					break;
				}
			}

				cout << "Length: " << length << endl;
				cout << "Width: " << width << endl;
				grid1 = new char*[length]; // Allocating new memory for char pointer
				grid2 = new char*[length]; // Grid 2 acts like the temp grid
				for(int i = 0; i < length; ++i){
					grid1[i] = new char[width];
					grid2[i] = new char[width];
				}

			int rowNum = 0;
			while(getline(file, line))//Looping through all lines in the file
			{
				cout << "LINE = " << line << endl;
				if(lineCount == 2)
				{
					for(int i = 0; i < width; ++i)
					{
						grid1[rowNum][i] = char(line[i]); //Asigning the values to grid One
					}
					rowNum++;
				}
			}
		}
	}
	else if(response == 2){ //A Random Assingment
		cout << "Enter length(rows), width(colums), and density" << endl;
		cin >> length >> width >> density;

		grid1 = new char*[length];
		grid2 = new char*[length];
		for(int i = 0; i < length; ++i){
			grid1[i] = new char[width];
			grid2[i] = new char[width];
		}
		populateGrid(grid1, density);
	}

	cout << "What kind of boundary mode do you want to run in? Enter 1 for Classic mode, 2 for Doughnut mode, or 3 for Mirror mode" << endl;
	cin >> choice;
		switch(choice)
		{
			case 1: //Classic Mode
				cout << "We're in Classic Mode" << endl;
				// firstGame.displayOption();
				cout << "Enter 1 if you want a brief pause between generations." << endl
				<< "Enter 2 if you to press \"Enter\" to display the next generation." << endl
				<< "Enter 3 if you to output everything into a file." << endl;
				cin >> printChoice;
				if(printChoice == 1) //Pause between generations
				{	
					//printChoiceOne(grid1, grid2, length, width);
					do
					{
						firstGame.classicMode(grid1, grid2, length, width);
						cout << "Generation: #" << generation << endl;
						generation++;
						printGrid(grid1); 
						cout << "*************\n";
						if(emptyGrid(grid2, length, width) == true)
						{
							cout << "The World is now empty!" << endl;
							printGrid(grid2);
							// cout << "\nPress Enter to exit the program." << endl;
							// getchar();
							// cin.get();
							halt = true;
						}
						if(stabilizeGrid(grid1,grid2) == true)
						{
							cout << "The program is being stabilized." << endl;
							printGrid(grid2);
							// cout << "\nPress Enter to exit the program." << endl;
							// getchar();
							// //getchar();
							// cin.get();
							halt = true;
						}
						sleep(2); // The sleep function pauses for how many seconds you input as a parameter
						copyGrid(grid1, grid2);
					} while(halt == false);
					break;
				}
				if(printChoice == 2) //Press Enter to display next generation
				{
					do
					{	
						firstGame.classicMode(grid1, grid2, length, width);
						cout << "Generation: #" << generation << endl;
						generation++;
						printGrid(grid1); 
						cout << "*************\n";
						cout << "Press Enter to display next generation" << endl;
						getchar(); // Makes the user press enter to keep going
						if(emptyGrid(grid2, length, width) == true)
						{
							cout << "The World is now empty!" << endl;
							printGrid(grid2);
							// cout << "\nPress Enter to exit the program." << endl;
							// getchar();
							halt = true;
						}
						if(stabilizeGrid(grid1,grid2) == true)
						{
							cout << "The program is being stabilized." << endl;
							printGrid(grid2);
							// cout << "\nPres Enter to exit the program." << endl;
							// getchar();
							halt = true;
						}
						copyGrid(grid1, grid2);
					} while(halt == false);
					break;
				}
				if(printChoice == 3) //Output to a file
				{
					string outputFile;
					
					cout << "Enter the name of the file: " << endl;
					cin >> outputFile;

					const char* fileOutput = outputFile.c_str();

					ofstream output (fileOutput, ios::out | ios::binary);
					if(output.is_open()){
						do
						{
							firstGame.classicMode(grid1, grid2, length, width);
							output << "Generation: #" << generation << endl;
							generation++;
							//gridToFile(grid1, (char*)fileOutput); 
							for(int i = 0; i < length; i++)
							{
								for(int j = 0; j < width; j++)
								{
									output << grid1[i][j];
								}
								output << endl;
							}
							if(emptyGrid(grid2, length, width) == true)
							{
								output << "The World is now empty!" << endl;
								//gridToFile(grid2, (char*)fileOutput);
								for(int i = 0; i < length; i++)
								{
									for(int j = 0; j < width; j++)
									{
										output << grid2[i][j];
									}
									output << endl;
								}
								halt = true;
							}
							if(stabilizeGrid(grid1,grid2) == true)
							{
								output << "The program is being stabilized." << endl;
								for(int i = 0; i < length; i++)
								{
									for(int j = 0; j < width; j++)
									{
										output << grid2[i][j];
									}
									output << endl;
								}
								//gridToFile(grid2, (char*)fileOutput);
								halt = true;
							}
							copyGrid(grid1, grid2);
						} while(halt == false);
					}
				}
				break;
			case 2: //Doughnut Mode
				cout << "We're in Doughnut Mode" << endl;
				// firstGame.displayOption();
				cout << "Enter 1 if you want a brief pause between generations." << endl
				<< "Enter 2 if you to press \"Enter\" to display the next generation." << endl
				<< "Enter 3 if you to output everything into a file." << endl;
				cin >> printChoice;
				if(printChoice == 1) //Pause between generations
				{	
					//printChoiceOne(grid1, grid2, length, width);
					do
					{
						firstGame.classicMode(grid1, grid2, length, width);
						cout << "Generation: #" << generation << endl;
						generation++;
						printGrid(grid1); 
						cout << "*************\n";
						if(emptyGrid(grid2, length, width) == true)
						{
							cout << "The World is now empty!" << endl;
							printGrid(grid2);
							// cout << "\nPress Enter to exit the program." << endl;
							// getchar();
							// cin.get();
							halt = true;
						}
						if(stabilizeGrid(grid1,grid2) == true)
						{
							cout << "The program is being stabilized." << endl;
							printGrid(grid2);
							// cout << "\nPress Enter to exit the program." << endl;
							// getchar();
							// //getchar();
							// cin.get();
							halt = true;
						}
						sleep(2); // The sleep function pauses for how many seconds you input as a parameter
						copyGrid(grid1, grid2);
					} while(halt == false);
					break;
				}
				if(printChoice == 2) //Press Enter to display next generation
				{
					do
					{	
						firstGame.classicMode(grid1, grid2, length, width);
						cout << "Generation: #" << generation << endl;
						generation++;
						printGrid(grid1); 
						cout << "*************\n";
						cout << "Press Enter to display next generation" << endl;
						getchar(); // Makes the user press enter to keep going
						if(emptyGrid(grid2, length, width) == true)
						{
							cout << "The World is now empty!" << endl;
							printGrid(grid2);
							// cout << "\nPress Enter to exit the program." << endl;
							// getchar();
							halt = true;
						}
						if(stabilizeGrid(grid1,grid2) == true)
						{
							cout << "The program is being stabilized." << endl;
							printGrid(grid2);
							// cout << "\nPres Enter to exit the program." << endl;
							// getchar();
							halt = true;
						}
						copyGrid(grid1, grid2);
					} while(halt == false);
					break;
				}
				if(printChoice == 3) //Output to a file
				{
					string outputFile;
					
					cout << "Enter the name of the file: " << endl;
					cin >> outputFile;

					const char* fileOutput = outputFile.c_str();

					ofstream output (fileOutput, ios::out | ios::binary);
					if(output.is_open()){
						do
						{
							firstGame.doughnutMode(grid1, grid2, length, width);
							output << "Generation: #" << generation << endl;
							generation++;
							//gridToFile(grid1, (char*)fileOutput); 
							for(int i = 0; i < length; i++)
							{
								for(int j = 0; j < width; j++)
								{
									output << grid1[i][j];
								}
								output << endl;
							}
							if(emptyGrid(grid2, length, width) == true)
							{
								output << "The World is now empty!" << endl;
								//gridToFile(grid2, (char*)fileOutput);
								for(int i = 0; i < length; i++)
								{
									for(int j = 0; j < width; j++)
									{
										output << grid2[i][j];
									}
									output << endl;
								}
								halt = true;
							}
							if(stabilizeGrid(grid1,grid2) == true)
							{
								output << "The program is being stabilized." << endl;
								for(int i = 0; i < length; i++)
								{
									for(int j = 0; j < width; j++)
									{
										output << grid2[i][j];
									}
									output << endl;
								}
								//gridToFile(grid2, (char*)fileOutput);
								halt = true;
							}
							copyGrid(grid1, grid2);
						} while(halt == false);
					}
				}
				break;
			case 3: //Mirror Mode
				cout << "We're in Mirror Mode" << endl;
				// firstGame.displayOption();
				//firstGame.mirrorMode();
				cout << "Enter 1 if you want a brief pause between generations." << endl
				<< "Enter 2 if you to press \"Enter\" to display the next generation." << endl
				<< "Enter 3 if you to output everything into a file." << endl;
				cin >> printChoice;
				if(printChoice == 1) //Pause between generations
				{	
					//printChoiceOne(grid1, grid2, length, width);
					do
					{
						firstGame.classicMode(grid1, grid2, length, width);
						cout << "Generation: #" << generation << endl;
						generation++;
						printGrid(grid1); 
						cout << "*************\n";
						if(emptyGrid(grid2, length, width) == true)
						{
							cout << "The World is now empty!" << endl;
							printGrid(grid2);
							// cout << "\nPress Enter to exit the program." << endl;
							// getchar();
							// cin.get();
							halt = true;
						}
						if(stabilizeGrid(grid1,grid2) == true)
						{
							cout << "The program is being stabilized." << endl;
							printGrid(grid2);
							// cout << "\nPress Enter to exit the program." << endl;
							// getchar();
							// //getchar();
							// cin.get();
							halt = true;
						}
						sleep(2); // The sleep function pauses for how many seconds you input as a parameter
						copyGrid(grid1, grid2);
					} while(halt == false);
					break;
				}
				if(printChoice == 2) //Press Enter to display next generation
				{
					do
					{	
						firstGame.classicMode(grid1, grid2, length, width);
						cout << "Generation: #" << generation << endl;
						generation++;
						printGrid(grid1); 
						cout << "*************\n";
						cout << "Press Enter to display next generation" << endl;
						getchar(); // Makes the user press enter to keep going
						if(emptyGrid(grid2, length, width) == true)
						{
							cout << "The World is now empty!" << endl;
							printGrid(grid2);
							// cout << "\nPress Enter to exit the program." << endl;
							// getchar();
							halt = true;
						}
						if(stabilizeGrid(grid1,grid2) == true)
						{
							cout << "The program is being stabilized." << endl;
							printGrid(grid2);
							// cout << "\nPres Enter to exit the program." << endl;
							// getchar();
							halt = true;
						}
						copyGrid(grid1, grid2);
					} while(halt == false);
					break;
				}
				if(printChoice == 3) //Output to a file
				{
					string outputFile;
					
					cout << "Enter the name of the file: " << endl;
					cin >> outputFile;

					const char* fileOutput = outputFile.c_str();

					ofstream output (fileOutput, ios::out | ios::binary);
					if(output.is_open()){
						do
						{
							firstGame.classicMode(grid1, grid2, length, width);
							output << "Generation: #" << generation << endl;
							generation++;
							//gridToFile(grid1, (char*)fileOutput); 
							for(int i = 0; i < length; i++)
							{
								for(int j = 0; j < width; j++)
								{
									output << grid1[i][j];
								}
								output << endl;
							}
							if(emptyGrid(grid2, length, width) == true)
							{
								output << "The World is now empty!" << endl;
								//gridToFile(grid2, (char*)fileOutput);
								for(int i = 0; i < length; i++)
								{
									for(int j = 0; j < width; j++)
									{
										output << grid2[i][j];
									}
									output << endl;
								}
								halt = true;
							}
							if(stabilizeGrid(grid1,grid2) == true)
							{
								output << "The program is being stabilized." << endl;
								for(int i = 0; i < length; i++)
								{
									for(int j = 0; j < width; j++)
									{
										output << grid2[i][j];
									}
									output << endl;
								}
								//gridToFile(grid2, (char*)fileOutput);
								halt = true;
							}
							copyGrid(grid1, grid2);
						} while(halt == false);
					}
				}
				break;
		}
}
