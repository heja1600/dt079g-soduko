#include "display.h"



display::display()
{

}
void display::display_information()const {
	set_color(FOREGROUND_GREEN);
	setcursorp(display_menu_x, display_menu_y);
	std::cout << "The goal of sudoku is to fill each";
	setcursorp(display_menu_x, display_menu_y+1);
	std::cout << " nine-square row, each nine-square  ";
	setcursorp(display_menu_x, display_menu_y + 2);
	std::cout<<"column and each nine-square box with ";
	setcursorp(display_menu_x, display_menu_y + 3);
	std::cout << "the numbers 1 through 9, with each  ";
	setcursorp(display_menu_x, display_menu_y + 4);
	std::cout << "number used once and only once in";
	setcursorp(display_menu_x, display_menu_y + 5);
	std::cout << "each section. It's the interaction ";
	setcursorp(display_menu_x, display_menu_y + 6);
	std::cout << "between the rows, columns and boxes";
	setcursorp(display_menu_x, display_menu_y + 7);
	std::cout << "that tells you where the numbers";
	setcursorp(display_menu_x, display_menu_y + 8);
	std::cout << " need to go. So if you  were to ";
	setcursorp(display_menu_x, display_menu_y + 9);
	std::cout << "start with a blank grid and fill ";
	setcursorp(display_menu_x, display_menu_y + 10);
	std::cout << "in the numbersfor row 1, column ";
	setcursorp(display_menu_x, display_menu_y + 11);
	std::cout << "2 and box 4 according to the sudoku rules. ";
	setcursorp(display_menu_x, display_menu_y + 13);
	std::cout << "-p";
	setcursorp(display_menu_x+display_command_gap, display_menu_y + 13);
	std::cout << "to play the game";
	set_color(-1);
}

void display::fullscreen()const {
	HWND hWnd;
	SetConsoleTitle("SUDOKU");
	hWnd = FindWindow(NULL, "SUDOKU");
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD NewSBSize = GetLargestConsoleWindowSize(hOut);
	SMALL_RECT DisplayArea = { 0, 0, 0, 0 };
	SetConsoleScreenBufferSize(hOut, NewSBSize);
	DisplayArea.Right = NewSBSize.X - 1;
	DisplayArea.Bottom = NewSBSize.Y - 1;
	SetConsoleWindowInfo(hOut, TRUE, &DisplayArea);
	ShowWindow(hWnd, SW_MAXIMIZE);
}
void display::display_main_menu()const {
	display_clear_menu();
	set_color(FOREGROUND_GREEN);
	setcursorp(display_menu_x + 8, display_menu_y);
	std::cout << "WELCOME TO SUDOKU";
	setcursorp(display_menu_x, display_menu_y+2);
	std::cout << "-p";
	setcursorp(display_menu_x + display_command_gap, display_menu_y + 2);
	std::cout << "TO PLAY SUDOKU";
	setcursorp(display_menu_x, display_menu_y + 3);
	std::cout << "-i";
	setcursorp(display_menu_x + display_command_gap, display_menu_y + 3);
	std::cout << "FOR INFORMATION ABOUT THE GAME";
	set_color(-1);
}
void display::display_play_menu()const {
	display_clear_menu();
	set_color(FOREGROUND_GREEN);
	setcursorp(display_menu_x, display_menu_y);
	std::cout << "-w";
	setcursorp(display_menu_x+display_command_gap, display_menu_y);
	std::cout << "TO MOVE UP";
	setcursorp(display_menu_x, display_menu_y+1);
	std::cout << "-d";
	setcursorp(display_menu_x+ display_command_gap, display_menu_y+1);
	std::cout << "TO MOVE DOWN";
	setcursorp(display_menu_x, display_menu_y+2);
	std::cout << "-a";
	setcursorp(display_menu_x+display_command_gap, display_menu_y+2);
	std::cout << "TO MOVE LEFT";
	setcursorp(display_menu_x, display_menu_y+3);
	std::cout << "-d";
	setcursorp(display_menu_x+ display_command_gap, display_menu_y+3);
	std::cout << "TO MOVE RIGHT";
	setcursorp(display_menu_x, display_menu_y+4);
	std::cout << "-S";
	setcursorp(display_menu_x+display_command_gap, display_menu_y+4);
	std::cout << "TO SELECT DIGIT AND CHANGE";
	setcursorp(display_menu_x, display_menu_y+5);
	std::cout << "-R";
	setcursorp(display_menu_x+ display_command_gap, display_menu_y+5);
	std::cout << "TO SOLVE THE SUDOKU";
	setcursorp(display_menu_x, display_menu_y + 6);
	std::cout << "-b";
	setcursorp(display_menu_x + display_command_gap, display_menu_y + 6);
	std::cout << "TO GO BACK";
	set_color(-1);
}
void display::display_digit_change_menu()const {
	display_clear_menu();
	set_color(FOREGROUND_GREEN);
	setcursorp(display_menu_x, display_menu_y);
	std::cout << "-w";
	setcursorp(display_menu_x + display_command_gap, display_menu_y);
	std::cout << "FOR HIGHER NUMBER";
	setcursorp(display_menu_x, display_menu_y+1);
	std::cout << "-s";
	setcursorp(display_menu_x + display_command_gap, display_menu_y+1);
	std::cout << "FOR LOWER NUMBER";
	setcursorp(display_menu_x, display_menu_y + 2);
	std::cout << "-b";
	setcursorp(display_menu_x + display_command_gap, display_menu_y + 2);
	std::cout << "TO GO BACK";
	setcursorp(display_menu_x, display_menu_y + 3);
	std::cout << "-S";
	setcursorp(display_menu_x + display_command_gap, display_menu_y + 3);
	std::cout << "TO SAVE DIGIT AND LOCK IT";
	set_color(-1);
}

void display::display_error_text(std::string error_text)const
{
	set_color(FOREGROUND_RED);
	setcursorp(display_error_x, display_error_y);
	std::cout << error_text;
	set_color(-1);
}

void display::remove_error_text()const
{
	setcursorp(display_error_x, display_error_y);
	for (int i = 0; i < 50; i++)
	{
		std::cout << " ";
	}
}

void display::display_clear_grid()const {
	for (int j = 0; j < N+4; j++)
	{
		setcursorp(display_grid_x, display_grid_y + j);
		for (int i = 0; i < 25; i++)
		{
			
			std::cout << " ";
		}
	}
}

void display::display_clear_menu()const
{
	for (int j = 0; j < 15; j++)
	{
		setcursorp(display_menu_x , display_menu_y + j);
		for (int i = 0; i < 50; i++)
		{
			std::cout << " ";
		}
	}
}

void display::setcursorp(int x, int y)const
{
	static HANDLE h = NULL;
	if (!h) {
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	}
	COORD c = { x,y };
	SetConsoleCursorPosition(h, c);
}
void display::set_color(int color)const {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	
	//sets the color to intense red on blue background
	SetConsoleTextAttribute(hStdout, color);

	//reverting back to the normal color
	if (color == -1)
	{
		SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
}

// two for loops couting the whole grid on specific place depending on the draw_box()
void display::display_game_grid(digit**&grid)const {

	int cursorx = display_grid_x + 2, cursory = display_grid_y + 1;
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
		{
			
			setcursorp(cursorx, cursory);
			if(grid[row][col].value != UNASSIGNED){  // if its not a unassinged number print the number
				if (grid[row][col].changeable)
				{
					set_color(-1);
				}
				else {
					
					set_color(FOREGROUND_RED);
				}
				std::cout << grid[row][col].value;
			}
			grid[row][col].x = cursorx; 
			grid[row][col].y = cursory;

			if ((col + 1) % 3 == 0) //if there is a line from the display grid..
			{
				cursorx += 4;
			}
			else {
				cursorx += 2;
			}
			
			
		}
		if ((row + 1) % 3 == 0) //if there is a line from the display grid..
		{
			cursory += 2;
		}
		else {
			cursory++;
		}
	
		cursorx = display_grid_x+2;
	}
	set_color(-1);
}

void display::draw_box()const
{
	int i, l;
	setcursorp(display_grid_x, display_grid_y);
	for (i = 0; i < 25; i++) //horisontela högst upp
	{
		std::cout << ch[0];
	}
	for (i = 0; i<11; i++)
	{
		std::cout << std::endl;
		setcursorp(display_grid_x, display_grid_y+1+i);//vertikala längst till vänster
		std::cout << ch[1];
	}
	setcursorp(display_grid_x, display_grid_y+12); //horisontella nedersta linjen
	for (i = 0; i < 25; i++) {
		std::cout << ch[0];
	}
	setcursorp(display_grid_x+1, display_grid_y+4);
	for (i = 0; i < 24; i++) //horisontela näst högst upp
	{
		std::cout << ch[0];
	}
	setcursorp(display_grid_x+1, display_grid_y+8);
	for (i = 0; i < 24; i++) //horisontela näst längst ner
	{
		std::cout << ch[0];
	}
	for (i = 0; i<11; i++)
	{
		std::cout << std::endl;
		setcursorp(display_grid_x+8, display_grid_y+1 + i);//vertikala näst längst till vänster
		std::cout << ch[1];
	}
	for (i = 0; i<11; i++)
	{
		std::cout << std::endl;
		setcursorp(display_grid_x+16, display_grid_y+1 + i);//vertikala näst längst till höger
		std::cout << ch[1];
	}
	for (i = 0; i<11; i++)
	{
		std::cout << std::endl;
		setcursorp(display_grid_x+24, display_grid_y+1 + i);//vertikala näst längst till höger
		std::cout << ch[1];
	}
}
