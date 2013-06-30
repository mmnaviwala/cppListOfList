/* * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * * * *
* Author: Muhammad Naviwala
* Date: 06/29/2013
* Description: This program demonstrates how linked list of linked list work.
  No STL classes have been used in this program.
  As a result the program displays numbers from 0-99, where numbers 0-9 are part
  of first list and then each number has its own list which is 'that number + 10' 
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <stdlib.h>
using namespace std;

// declaring second node
// declaring second node first, because its needed to be part of the first node
class nodeB
{
public:
	int j;
	nodeB *nextB;
};

// declaring first node
class nodeA
{
public:
	int i;
	nodeA *nextA;
	nodeB *nextAB;
};

// Global pointer for nodeA. This will serve as head of the list
nodeA *head1;

int main()
{
	// ========================================================================================
	// using n1 and n2 to traverse the list
	nodeA *n1;
	nodeB *n2;
	// ========================================================================================

	// ========================================================================================
	// initializing the list (at this point only variables and pointers were "declared")
	head1 = new nodeA;
	head1->nextA = 0;	// setting to NULL
	n1 = head1;			// from this point using n1 to traverse through the list
	// ========================================================================================



	// ========================================================================================
	for(int x=0; x<10; x++)
	{
		// going to the current pointer place
		if ( n1 != 0 ) 
		{
			while ( n1->nextA != 0)
				n1 = n1->nextA;
		}

		n1->nextA = new nodeA;
		n1 = n1->nextA;
		n1->nextA = 0;

		n1->i = x;


		// ----------------------------------------------------------------------------------------
		n1->nextAB = new nodeB;
		n1->nextAB->nextB = 0;
		n2 = n1->nextAB;
		// ----------------------------------------------------------------------------------------

		for(int y=x+10; y<100; y=y+10)
		{

			// ----------------------------------------------------------------------------------------
			// going to the current pointer place
			if ( n2 != 0 ) 
			{
				while ( n2->nextB != 0)
					n2 = n2->nextB;
			}

			n2->nextB = new nodeB;
			n2 = n2->nextB;
			n2->nextB = 0;

			n2->j = y;
			// ----------------------------------------------------------------------------------------
		}
	}
	// ========================================================================================

	// ========================================================================================
	// now for printing the list
	nodeA *print1;
	nodeB *print2;

	print1 = head1;
	print1 = print1->nextA;

	cout << endl;
	while ( print1 != NULL ) 
	{
		cout << print1->i << "->";

		print2 = print1->nextAB;
		print2 = print2->nextB;

		while( print2 != NULL)
		{
			cout << print2->j;
		
			if(print2->nextB != NULL)
			{
				cout << "->";
			}
		
			print2 = print2->nextB;
		}

		if(print1->nextA != NULL)
		{
			cout << endl << "|" << endl << "V" << endl;
		}

		print1 = print1->nextA;
	}
	cout << endl;
	// ========================================================================================
}