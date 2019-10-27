#ifndef SOLUTION_H
#define SOLUTION_H

#include <iostream>
#include <algorithm> //shuffle
#include "digit.h"
/** solution class
*  This class's purpose is to solve a sudoku using 
* \n a backtracking algorithm found at 
* \n https://en.wikipedia.org/wiki/Sudoku_solving_algorithms under Backtracking.
* \n The algorithm is also used to generate a sudoku.
*  Example:
*  @code
*  #include <algorithm> // shuffle
*  #include "digit.h"
*
*  void main() {
*	  digit**grid;
*     solution sol(grid);
* 	  grid=sol.exec();
*  }
*  @endcode
*/
class solution
{
	/// this is the grid that is getting solved
	digit**grid;

	/// This is an array of numbers 1-9
	int*numbers;

	///This method is used to find a unassigned digit
	/**
	* @param row by reference is the current Row its checking
	* @param col by reference is the current column its checking
	* @return true if the digit is unassigned
	*/
	bool Find_unassigned_location(int&row, int&col);

	/// This method is used to check if a digit is allowed in a location.
	/**
	* @param row is the current Row its checking
	* @param col is the current column its checking
	* @param num is the current number its checking
	* @return true if the digit could be placed
	*/
	bool is_safe(int row, int col, int num);
	/**
	* This method solves the sudoku using a backtracking algorithm. 
	* testing first index from numbers, if it works, it test the next. 
	* if it fails it increases numbers index.
	* if all indexes of number is tested 
	* @return true if the sudoku was solveble
	*/
	bool solved_sudoku();
	/**
	* This method checks the horizontal row if theres another "num".
	* @param row is the current Row its checking
	* @param num is the number its looking for
	*/
	bool check_row(int row, int num);
	/**
	* This method checks the vertical column if theres another "num".
	* @param col is the current column its checking
	* @param num is the number its looking for
	*/
	bool check_col(int col, int num);
	/**
	* This method checks the 3x3 boxes if there if theres another "num".
	* @param box_start_row is the upper horizontal line of the 3x3 box
	* @param box_start_col is the left vertical line of the 3x3 box
	* @param num is the number its looking for
	*/
	bool check_box(int box_start_row, int box_start_col, int num);

public:
	/**
	* This constructor is used for creating an object of the solution
	* \n it shuffles the private member "number" to get random solutions
	* @param grid is a unsolved sudoku double array
	*
	*/
	solution(digit**grid);
	/**
	* This operator is used to generate a solution for a sudoku
	*
	*  @return gives back a full solution for the sudoku
	*/
	digit**operator()();
};

#endif