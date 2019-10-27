#ifndef DIGIT_H
#define DIGIT_H
#include <Windows.h>
#define N 9
#define UNASSIGNED 0

/**
* This is the structure of all the digits in the sudoku
*  Example:
*  @code
*	digit grid[9][9];
*   gird[1][1].value=UNASSIGNED;
*  
*  @endcode
*/
struct digit {
	
	///This operator sets the digit to UNASSIGNED
	void operator ()() {
		value = UNASSIGNED;
	}
	///This is the value of digit from 1-9 and UNASSIGNED
	int value;

	///This is where the digit is located at from the left at the screen, for playgrid
	int x;

	///This is where the digit is located at from the top at the screen, for playgrid
	int y;
	
	///This bool is true if you can change the digit, otherwise its a preset value.
	bool changeable;
};

#endif