#include "solution.h"
solution::solution(digit**grid):
	grid(grid), numbers(new int[N]{1,2,3,4,5,6,7,8,9}){
	std::random_shuffle(numbers,numbers+8);
}

/* 
 *Går igenom hela sukokut rad för rad från vänster 
 *till höger ovanfrån till botten och ser om det 
 *finns tomma rutor, returnerar true om den hittar en tom ruta 
 */
bool solution::Find_unassigned_location( int&row, int&col)
{
	for (row = 0; row < N; row++)
	{
		for (col = 0; col < N; col++)
		{
			if (grid[row][col].value == UNASSIGNED)
			{
				return true;
			}
		}
	}
	return false;
}

bool solution::is_safe( int row, int col, int num)
{
	return (!check_row( row, num) &&
		!check_col( col, num) &&
		!check_box(row-row%3, col-col%3,num));
}

bool solution::solved_sudoku()
{
	int row, col;
	if (!Find_unassigned_location( row, col)) // om de inte finns tomma rutor returnera true
	{
		return true;
	}
	for(int*num=numbers;num!=numbers+N;num++)
	//for (int num = 1; num <= N; num++)
	{
		if (is_safe(row, col, *num))
		{
			grid[row][col].value = *num;
			if (solved_sudoku())
			{
				return true;
			}
			grid[row][col](); // this is where the backtracking starts
		}
	}
	return false; //om inget av talen passade

}
bool solution::check_row( int row, int num) 
{
	for (int col = 0; col < N; col++)
	{
		if (grid[row][col].value == num)
		{
			return true;
		}
	}
	return false;
}
bool solution::check_col( int col, int num)
{
	for (int row = 0; row < N; row++)
	{
		if (grid[row][col].value == num)
		{
			return true;
		}
	}
	return false;
}
bool solution::check_box( int boxStartRow, int BoxStartCol, int num)
{
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++)
		{
			if (grid[row + boxStartRow][col + BoxStartCol].value == num)
			{
				return true;
			}
		}
	}
	return false;
}


digit**solution::operator()()
{
	solved_sudoku();
	return grid;
}