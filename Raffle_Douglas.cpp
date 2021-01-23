/*
*		Name: Christian Douglas
*		Project Name: RaffleChooser
*		Date: January 22, 2021
*		Purpose: Allows the user to enter a text file of names
*		and randomly generate 2 names for a raffle.
*/

#include <iostream>
#include <fstream>			//used to read in the input file
#include <cstdlib>			//used for srand and rand											
#include <ctime>			//used for the time function with srand
#include <map>				//used to map the position the names 
							//from the infile are in the list
using namespace std;

/*
*	Name: generateWinner
*	Params: members, roster
*	Return: void
*	Purpose: Randomly chooses 2 numbers that are
*	assigned to names in a map called roster. 
*	The random number generator uses the system clock
*	to truly choose randomly from 1 to the value of member.
*	roster.erase(winner) removes the first choice from the
*	list to prevent the same name to be chosen again.
*/
void generateWinner(int members, map<int, string> roster)
{
	map<int, string>::iterator it;
	int place = 0;

	srand(time(NULL));
	for (int i = 0; i < 2; i++)
	{
		int winner = (rand()% members) + 1;
		cout <<"Winner " << ++place << " is: " 
			<< roster.find(winner)->second << endl;
		roster.erase(winner);
	}
	
	
}

int main()
{
	ifstream input;					//used for reading the the input file
	map<int, string> roster;		//uses int and string to assign a number
									//to each name
	int members = 0;				//accumulator to obtain the number of names
									//in a list
	char names[30] = " ";			//used for getline to read in the full names
									//up to 30 characters
	
	input.open("input.txt");		//opens the text file containing names
	
	while (!input.eof())			//reads to the end of file
	{
		members++;			
		input.getline(names, 30);
		roster.insert(pair<int, string>(members, names));
	}
	generateWinner(members, roster);

	input.close();					//closes the text file

	return 0;
}