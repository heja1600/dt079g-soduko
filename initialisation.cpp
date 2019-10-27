#include "initialisation.h"



initialisation::initialisation(int remove_number_from_grid) :
	grid(new digit*[N]),remove_number_from_grid(remove_number_from_grid)
{
	for (int i = 0; i < N; ++i) // creates N new arrays where all of the induvidually points at another array
		grid[i] = new digit[N];
}

digit**initialisation::operator()()
{
	generate_empty();
	solution sol(grid);
	grid = sol();
	remove_numbers();
	return grid;
}

void initialisation::generate_empty()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			grid[i][j]();
			grid[i][j].changeable = false;
		}
	}
}
void initialisation::remove_numbers() {
		for (int i = 0; i < remove_number_from_grid; i++)
		{
			grid[rand() % N][rand() % N](); //random place in the N*N grid
		}
		set_changeble();
}

void initialisation::set_changeble()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (grid[i][j].value == UNASSIGNED) {
				grid[i][j].changeable = true;
			}
		}
	}
}

void initialisation::set_changeble_dig_to_null(digit**&grid)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (grid[i][j].changeable) {
				grid[i][j]();
			}
		}
	}
}

//std::function<void>func = {
	//grid[i][j].value = UNASSIGNED;
