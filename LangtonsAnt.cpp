/*********************************************************************
** Author:		Billy R. Shelton
** Date:		6/28/2018
** Description:   This is the client code file which implements 
Langton's Ant.  The user determines the size of the array, where the ant
starts and the number of steps the ant will take.  Then the following rules 
are repeated until the ant either crashes into a wall or until the ant completes
all the steps.  
For the Ant there are two simple rules. The rules are:
	1. In a white square, turn right 90 degrees and change the square to black.
	2. In a black square, turn left 90 degrees and change the square to white. 
*********************************************************************/


#include <iostream>
#include "Ant.hpp"
#include <string>
#include <unistd.h>				//used to call sleep function
#include <stdlib.h>				//used to call random function
#include <time.h>				//used to call the time function
#include <math.h>
using namespace std;
void InputValidation(double &size, double &steps, double &row, double &column);		//Input Validation Function Prototype


int main()
{	

	double row, column, steps, size;
	InputValidation(size, steps, row, column);		//The user is aked for correct inputs
	cout << endl;
	cout << "Now let's watch your ant go.";
	int time1 = 1000;
	int usleep(useconds_t time1);
	system("cls");

	//An object is created
	Ant UserAnt(row, column, steps, size);			//An ant object is created

	//An object function is used
	UserAnt.run();									//the object's function run is applied

	return 0;
}










void InputValidation(double &size, double &steps, double &row, double &column)
{
	//Introduction
		cout << "Welcome to a program that implements Langton's Ant algorithm." << endl;
	cout << endl;
	//Sleep(4000);

	//double size;
	//double steps;

	//Checks the size of the board is an integer > 1 and not a double
	do
	{
		cout << "Please enter an integer greater than 1 to determine the square" << endl;
		cout << "size of the board on which your ant will traverse." << endl;
		cout << endl;
		//Sleep(1000);
		cout << "I suggest entering a value less than 65." << endl;
		cout << endl;
		cout << "Size: ";
		cin >> size;
		cout << endl;
	} while ((size < 1) || (fmod(size, 1) != 0) || (size > 65));





	//Checks the steps of the board is an integer > 1 and not a double
		//double steps;
		do
		{
		cout << "How many steps would you like your ant to take?" << endl;
		cout << "Steps: ";
		cin >> steps;
		cout << endl;
		} while ((steps < 1) || (fmod(steps, 1) != 0));

		//Asks the user if they would like to choose the position of their ant
		cout << "Would you like to choose on the board where to initially place your ant?" << endl;
	string answer;
	cin >> answer;
	cout << endl;

	//double column;
	//double row;

	//If so, the starting column and row are asked
	if ((answer == "yes") || (answer == "YES") || (answer == "Yes") || (answer == "y") || (answer == "Y"))
	{
		cout << "Ok, at which column and row would you like to place your ant?" << endl;

		do
		{
			cout << "Enter an integer greater than or equal to 1." << endl;
			cout << "Column:";
			cin >> column;
			cout << endl;
		} while ((column < 1) || (fmod(column, 1) != 0));

		do
		{
			cout << "Enter an integer greater than or equal to 1." << endl;
			cout << "Row:";
			cin >> row;
			cout << endl;
		} while ((row < 1) || (fmod(row, 1) != 0));
	}

	//If no, a random column and row are created
	else
	{
		srand(time(NULL));						//random seed is generated using current calendar time at runtime
		column = fmod(rand(), size) + 1;			//random column is generated using random function and seed
		row = fmod(rand(), size) + 1;			//random row is generated using random function and seed
		cout << "Very well, your ant will be randomly placed on the board at," << endl;

		cout << "Column: " << column << endl;
		cout << "Row: " << row << endl;
	}
}
