#include "Grid.h"

int main(int argc, char** argv)
{
	Grid g;
	Grid tempGrid;
	int response;
	bool errorOccured = false;

	do
	{
		cout << "Enter 1 if you wish to provide a map file or enter 2 if you would like a random assignment" << endl;
		cin >> response;
		errorOccured = response < 1 || response > 2 || cin.fail();
		if(errorOccured)
		{
			cout << "Error: invalid input!" << endl;
			cin.clear();
			cin.ignore();
			errorOccured = true;
		}
	}while(errorOccured);

	g.promptUser(response);

	return 0;
}
