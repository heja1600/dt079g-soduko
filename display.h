#ifndef DISPLAY_H
#define DISPLAY_H
#include <iostream>
#include <Windows.h>
#include <string>
#include "digit.h"

//these defines enables modification of placement where you want your menus
#define display_menu_x 15 // where the menu should start from the left of the screen
#define display_menu_y 12 // where the menu should start from the top of the screen
#define display_grid_x 65 // where the grid should start from the left of the screen
#define display_grid_y 10 // where the grid should start from the top of the screen
#define display_error_x 66 // where the error message should start from the left of the screen
#define display_error_y 2 // where the error message should start from the top of the screen
#define display_command_gap 8 // gap between the command and the command information

/**
* display Class
* \n this class is used to display everything on the screen. 
* \n it prints all the menus and the grid to the screen
* \n changes the colors and sets cursor pointer
*Example:
*  @code
*  #include "digit.h"
*  #include <Windows.h>
*
*  void main() {
*	  display disp;
*     disp.fullscreen(); 
* 	  disp.draw_box();
*	  disp.display_main_menu();
*  }
*  @endcode
*/
class display
{
	
	///this is used to create the grids horizontal and vertical lines
	char ch[2] = { '_','|' };

	///This method is used to change the std::cout color.
	/*
	* @param a color using the <Windows.h> defines, if -1 it returns to the standard color "white".
	* @code
	 *  #include "digit.h"
	 *
	 *  display::void function() {
	 *     setcolor(FOREGROUND_RED);
	 *  }
	 *  @endcode
	*
	*/
	void set_color(int color)const;

	
	///This method clears all the current menus to use other menus
	void display_clear_menu()const;

public:
	display();

	
	///This method makes the window fullscreen
	void fullscreen()const;

	
	///This method displays the main menu on the screen
	void display_main_menu()const;

	///This method displays the play menu on the screen
	void display_play_menu()const;

	///This method shows digit change menu
	/**
	* This method displays the menu where you can change different positions in
	* the grid from 1-9 and unassigned.
	*/
	void display_digit_change_menu()const;

	
	///This method displays some information about the game
	void display_information()const;

	///This method displays an error text if needed
	/**
	* @param a string of error text
	*  Example:
	 *  @code
	 *  #include "display.h"
	 *
	 *  void main() {
	 *     display disp;
	 *	   disp.display_error_text("here you can type your error message");
	 *  }
	 *  @endcode
	*/
	void display_error_text(std::string error_text)const;

	/// This method clears the error text
	void remove_error_text()const;

	/// This method draws the soduko map corners and other lines
	void draw_box()const;

	/// This method displays the playable grid to the screen.
	/**
	* Example:
	 *  @code
	 *  #include "display.h"
	 *
	 *  void main() {
	 *     display disp;
 	 *	   disp.display_game_grid(grid);
	 *  }
	 *  @endcode
	 * @param grid is the sudoku you want to display
	*/
	void display_game_grid(digit**&grid)const;

	/// This method clears the sudoku map(grid)
	void display_clear_grid()const;

	///This method sets the cursor point to a different place to optimize the std::cout
	/**
	*  Example:
	*  @code
	*  #include "display.h"
	*
	*  void main() {
	*     display disp;
	*	  disp.setcursorp(20,20);
	*	  std::cout<<"now i type 20 from the top and 20 from the left";
	*  }
	*  @endcode
	*	@param x how long from the left side you want to put the cursor
	*	@param y how long from the top side you want to put the cursor
	*/
	void setcursorp(int x, int y)const;
};

#endif