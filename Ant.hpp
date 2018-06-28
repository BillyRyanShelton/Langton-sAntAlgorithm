#pragma once
/*********************************************************************
** Author:		Billy R. Shelton
** Date:		6/28/2018
** Description:  This is a header file which creates the class Ant.  The
class has 4 data members.  The member functions are created but not defined
here.  
*********************************************************************/


#pragma once
#ifndef ANT_HPP
#define ANT_HPP

class Ant													//Ant class declaration
{
private:													//4 data members are created
	int row;
	int column;
	int steps;
	int size;

public:														//prototype member functions are created
	Ant(int, int, int, int);								//constructor that initializes values data members
	void run();													
};
#endif
