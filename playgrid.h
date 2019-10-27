#ifndef PLAYGRID_H
#define PLAYGRID_H

#include <conio.h>
#include "digit.h"
#include "solution.h"
#include "display.h"
#include "initialisation.h"


/**
* playgrid Class
* \n this class takes care of all the playing actions
* \n it enables changing different digits in the sudoku 
* \n and displaying all different menus 
*Example:
*  @code
*  #include "initialisation.h"
*  #include "Sudoku.h"
*
*  void main() {
*		playgrid play;
*		if(play.exec())
*		{
*			//some code
*		}
*  }
*  @endcode
*/
class playgrid
{
	
	/// A object of display which could be used within the methods
	/**
	*Example:
	*@code
	*#include "playgrid.h"
	*playgrid::void function(){
	*	disp.display_main_menu();
	*	disp.draw_box();
	*@endcode
	*}
	*/
	display disp;

	///The sudoku grid that you are currently playing on
	digit**grid;

	/// the current position where the cursor is located from left side in the sudoku grid.
	int current_cursor_x;

	/// the current position where the cursor is located from top side in the sudoku grid.
	int current_cursor_y;

	///this method changes digit value
	/**
	* This method changes the digit private member value from 1-9
	* \n it displays a menu where you can change it 
	* @return true if the value has been changed.
	* \n in the sudoku grid.
	*/
	bool digit_change();
public:

	///This constructor sets the current_x and current_y to 0 and 0
	playgrid();

	///This operator runs the game and lets you play,
	/**
	* @return true if you want to exit the game
	*/
	bool operator()();
};

#endif