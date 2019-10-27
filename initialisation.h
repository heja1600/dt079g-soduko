#ifndef INITIALISATION_H
#define INITIALISATION_H

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <functional>
#include "solution.h"
#include "digit.h"
/**
* initialisation class
* \n this class is used to generate a sudoku using the backtracking 
* \n solution algorithm with empty grid.
*
*  Example:
*  @code
*  #include "initialisation.h"
*
*  void main() {
*	   int**grid;
*     initialisation init(60);
*	   grid=init.exec();
*  }

*/
class initialisation
{
private:

	///The playable sudoku grid
	digit**grid;

	///numbers of deleted digits from the grid, difficulty
	int remove_number_from_grid;
	
	///This method is used to fill the grid with unassigned.
	void generate_empty();
	
	///This method is used to remove random digits in the grid.
	void remove_numbers();

	///This method sets all the unassigned digits to changeble, they can be modified
	void set_changeble();
public:

	/// This constructor is used for creating a double array for the sudoku.
	/** 
	* @param remove_number_from_grid How many digits you want to set to UNASSIGNED
	* \n to remove from the sudoku in order to provide different difficulties.
	*/
	initialisation(int remove_number_from_grid);

	/// This Operator is used for creating a playeble grid
	 /**
	 *  @return a solveble and fully playeble grid(sudoku)
	 */
	digit** operator()();

	///  This method changes all the changeble digits to unnasigned.
	/**
	* \n Its used to remove users faults for the solver to work properly
	* \n @param grid is the a double array you want to change
	*/
	void set_changeble_dig_to_null(digit**&grid);

};
#endif