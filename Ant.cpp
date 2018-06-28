/*********************************************************************
** Author:		Billy R. Shelton
** Date:		1/21/2016
** Description:   This is an implementation file which defines the
functions created in the Ant.hpp file.  
*********************************************************************/

#include "Ant.hpp"
#include <string>
#include <iostream>
#include <iomanip>			//used to call set width function
#include <unistd.h>			//used to call sleep function
#include <cstdlib>
using namespace std;

/*********************************************************************
Student(string, double);
** Description:  This is a 2-parameter constructor which initializes
the data members.
*********************************************************************/

Ant::Ant(int rowIn, int columnIn, int stepsIn, int sizeIn)
{
	row = rowIn;
	column = columnIn;
	steps = stepsIn;
	size = sizeIn;
}


void Ant::run()
{
	string **board = 0;					//board is created based on user inputted size
	board = new string*[size];			//our pointer to a pointer to a string is set to point to an array of pointers to strings
										//rows are created

	for (int i = 0; i < size; i++)		//the number of columns for each row is created
	{
		board[i] = new string[size];
	}




	for (int i = 0; i < size; i++)			//the board is filled with empty spaces
	{
		for (int j = 0; j < size; j++)
		{
			board[i][j] = ".";
		}
	}




	for (int i = 0; i < size; i++)			//the board is printed
	{
		for (int j = 0; j < size; j++)
		{
			cout << setw(2) << board[i][j];
		}
		cout << endl;
	}
	
	int time2 = 100000;
	int usleep(useconds_t time2);
	system("clear");



	board[(row - 1)][(column - 1)] = char(157); //the ant is placed at the starting position

	for (int i = 0; i < size; i++)			//the board is printed
	{
		for (int j = 0; j < size; j++)
		{
			cout << setw(2) << board[i][j];
		}
		cout << endl;
	}
	int usleep(useconds_t time2);
	system("clear");




	int orientation = 1;
	string current_position = ".";


	for (int i = 0; i < steps; i++)
	{
		//UP and Blank Space
		if (orientation == 1 && (current_position == "."))
		{
			board[(row - 1)][(column - 1)] = "#";


			column++;

			if (column > (size))
			{
				cout << "Your ant tried to move a wall and died." << endl;
				cout << "Farewell!";
				cout << "UP AND BLANK";
				goto deallocation;
			}
			current_position = board[(row - 1)][(column - 1)];
			board[(row - 1)][(column - 1)] = char(157);

			orientation = 3;
		}







		//UP and Black Space
		else if (orientation == 1 && (current_position == "#"))
		{
			board[(row - 1)][(column - 1)] = ".";


			column--;

			if (column < (1))
			{
				cout << "Your ant tried to move a wall and died." << endl;
				cout << "Farewell!";
				cout << "UP AND BLACK";
				goto deallocation;
			}
			current_position = board[(row - 1)][(column - 1)];
			board[(row - 1)][(column - 1)] = char(157);

			orientation = 4;
		}









		//DOWN and Blank Space
		else if (orientation == 2 && (current_position == "."))
		{
			board[(row - 1)][(column - 1)] = "#";


			column--;

			if (column < (1))
			{
				cout << "Your ant tried to move a wall and died." << endl;
				cout << "Farewell!";
				cout << "DOWN AND BLANK";
				goto deallocation;
			}
			current_position = board[(row - 1)][(column - 1)];
			board[(row - 1)][(column - 1)] = char(157);

			orientation = 4;
		}







		//DOWN and Black Space
		else if (orientation == 2 && (current_position == "#"))
		{
			board[(row - 1)][(column - 1)] = ".";


			column++;

			if (column > (size))
			{
				cout << "Your ant tried to move a wall and died." << endl;
				cout << "Farewell!";

				cout << "DOWN AND BLACK";
				goto deallocation;
			}
			current_position = board[(row - 1)][(column - 1)];
			board[(row - 1)][(column - 1)] = char(157);

			orientation = 3;
		}






		//RIGHT and Blank Space
		else if (orientation == 3 && (current_position == "."))
		{
			board[(row - 1)][(column - 1)] = "#";


			row++;

			if (row > (size))
			{
				cout << "Your ant tried to move a wall and died." << endl;
				cout << "Farewell!";
				cout << "RIGHT AND BLANK";
				goto deallocation;
			}
			current_position = board[(row - 1)][(column - 1)];
			board[(row - 1)][(column - 1)] = char(157);

			orientation = 2;
		}







		//RIGHT and Black Space
		else if (orientation == 3 && (current_position == "#"))
		{
			board[(row - 1)][(column - 1)] = ".";


			row--;

			if (row < (1))
			{
				cout << "Your ant tried to move a wall and died." << endl;
				cout << "Farewell!";
				cout << "RIGHT AND BLACK";
				goto deallocation;
			}
			current_position = board[(row - 1)][(column - 1)];
			board[(row - 1)][(column - 1)] = char(157);

			orientation = 1;
		}
		







		//LEFT and Blank Space
		else if (orientation == 4 && (current_position == "."))
		{
			board[(row - 1)][(column - 1)] = "#";


			row--;

			if (row < (1))
			{
				cout << "Your ant tried to move a wall and died." << endl;
				cout << "Farewell!";
				cout << "LEFT AND BLANK";
				goto deallocation;
			}
			current_position = board[(row - 1)][(column - 1)];
			board[(row - 1)][(column - 1)] = char(157);

			orientation = 1;

		}




		//LEFT and Black Space
		else if (orientation == 4 && (current_position == "#"))
		{
			board[(row - 1)][(column - 1)] = ".";


			row++;

			if (row > (size))
			{
				cout << "Your ant tried to move a wall and died." << endl;
				cout << "Farewell!";
				cout << "LEFT AND BLACK";
				goto deallocation;
			}
			current_position = board[(row - 1)][(column - 1)];
			board[(row - 1)][(column - 1)] = char(157);

			orientation = 2;
		}






		






		for (int i = 0; i < size; i++)			//the board is printed
		{
			for (int j = 0; j < size; j++)
			{
				cout << setw(2) << board[i][j];
			}
			cout << endl;
		}
		int time3 = 100000;
		int usleep(useconds_t time3);
		system("clear");


	}

	//for (int i = 0; i < size - 1; i++)			//prints final board
	//{
	//	for (int j = 0; j < size - 1; j++)
	//	{
	//		cout << setw(2) << board[i][j];
	//	}
	//	cout << endl;
	//}




deallocation:
	for (int i = 0; i < size; i++)			//Deallocate board
	{
		delete[] board[i];
	}
	delete[]board;

}



