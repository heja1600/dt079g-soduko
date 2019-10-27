#include "Sudoku.h"

Sudoku::Sudoku()
{
}

int Sudoku::exec()
{
	display disp;
	disp.fullscreen();
	
	char choice='-1';
	do {
		disp.display_main_menu();
		disp.draw_box();
		choice = _getch();
		switch (choice)
		{
		case 'p': { // playsudoku
			playgrid playgrid;
			if (playgrid()) { //går tilbaka
				disp.display_clear_grid();
			}
			break;
		}
		case 'i': //information
			disp.display_information();
			while (!_kbhit()) 
			{}
			break;
		}
	} while (1);

	return 0;
}
