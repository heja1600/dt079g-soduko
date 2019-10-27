#include "playgrid.h"

playgrid::playgrid():
	current_cursor_x(0), current_cursor_y(0) // startposition
{

}
bool playgrid::operator()() {

	initialisation init(60);
	grid = init();
	disp.display_game_grid(grid);
	disp.display_play_menu();
	char choice = '-1';
	do {
		disp.setcursorp(grid[current_cursor_x][current_cursor_y].x, grid[current_cursor_x][current_cursor_y].y); //sätter cursor där den ska vara
		choice = _getch();
		disp.remove_error_text();
		switch (choice)
		{
		case 'a'://up
			if (current_cursor_y - 1 != -1)
			{
				current_cursor_y--;
			}
			else
			{
				disp.display_error_text("cannot move there");
			}
			break;
		case 'd'://down
			if (current_cursor_y + 1 != N)
			{
				current_cursor_y++;
			}
			else
			{
				disp.display_error_text("cannot move there");
			}
			break;
		case 'w'://up
			if (current_cursor_x - 1 != -1)
			{
				current_cursor_x--;
			}
			else
			{
				disp.display_error_text("cannot move there");
			}
			break;
		case 's'://down
			if (current_cursor_x + 1 != N)
			{
				current_cursor_x++;
			}
			else
			{
				disp.display_error_text("cannot move there");
			}
			break;
		case 'S'://Select
			if (grid[current_cursor_x][current_cursor_y].changeable) //så de inte är en röd siffra
			{
				if (!digit_change()) //om de är quit
				{
					disp.setcursorp(grid[current_cursor_x][current_cursor_y].x, grid[current_cursor_x][current_cursor_y].y);
					std::cout << " ";
				}
				disp.display_play_menu();
			}
			else
			{
				disp.display_error_text("cannot change red numbers");
			}
			break;
		case 'R':
			init.set_changeble_dig_to_null(grid); //för att ta bort eventuella fel från spelaren
			solution sol(grid);
			grid = sol();
			disp.display_game_grid(grid);
			break;
		}
		if (choice == 'b') {
			return true;
		}
	} while (1);
}
bool playgrid::digit_change()
{
	disp.display_digit_change_menu();
	int number = grid[current_cursor_x][current_cursor_y].value;
	char choice = '-1';
	do {
		disp.setcursorp(grid[current_cursor_x][current_cursor_y].x, grid[current_cursor_x][current_cursor_y].y); // sätter tillbaka cursor efter flyttat runt tal
		if (number == 0)
		{
			std::cout << "_";
		}
		else {
			std::cout << number;
		}

		choice = _getch();
		disp.remove_error_text();
		switch (choice)
		{
		case 'w':
			if (number + 1 != 10) // om talet inte är fö högt
			{
				number++;
			}
			else {
				disp.display_error_text("too high number");
			}
			break;
		case 's':
			if (number - 1 != -1) // om talet inte är för lågt
			{
				number--;
			}
			else {
				disp.display_error_text("too low number");
			}
			break;
		case 'S':
			grid[current_cursor_x][current_cursor_y].value = number;
			return true;
		case 'b':
			return false;
		}
	} while (1);
}

