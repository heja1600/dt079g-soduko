#ifndef SUDOKU_H
#define SUBOKU_H

#include <Windows.h>
#include <iostream>
#include <conio.h>
#include "display.h"
#include "playgrid.h"

/** Sudoku Class.
*
*  To use the library, its header file needs to be included and an object of the Sudoku has to be created.
*
*  Example:
*  @code
*  #include "display.h"
*  #include "playgrid.h"
*
*  
*  void main() {	
*	   Sudoku app;
*     return app.exec();
*
* }
*  @endcode
*/

class Sudoku
{	
public:
	Sudoku();

	///This method runs the sudoku application
	int exec();
};

#endif