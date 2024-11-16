#include <cstdio>
#include "tictactoe.hpp"
#include <iostream>

void clearconsole()
{
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}

void drawboard(char *board[])
{
	clearconsole();

	std::printf("\n     |     |     \n");
	std::printf("  %c  |  %c  |  %c  \n", *board[1], *board[2], *board[3]);
	std::printf("-----|-----|-----\n");
	std::printf("  %c  |  %c  |  %c  \n", *board[4], *board[5], *board[6]);
	std::printf("-----|-----|-----\n");
	std::printf("  %c  |  %c  |  %c  \n", *board[7], *board[8], *board[9]);
	std::printf("     |     |     \n");
}

void greet()
{
	std::printf("Welcome!");
}

void check(char *argcheck[])
{
	for (int i; i < 3; i++)
	{
		if (*argcheck[i] == 'x' || *argcheck[i] == 'X')
		{
			std::cout << "---------------\n";
			std::cout << "Player One won!\n";
			std::cout << "---------------\n";
			exit(-1);
		}
		else if (*argcheck[i] == 'o' || *argcheck[i] == 'O')
		{
			std::cout << "---------------\n";
			std::cout << "Player Two won!\n";
			std::cout << "---------------\n";
			exit(-1);
		}
	}
	/*else{
		std::cout << "Null pointer found!";
	}*/
}

void checkwinner(char *board[])
{
	// ONE, TWO, THREE
	if (*board[1] == *board[2] && *board[2] == *board[3]) 
	{
		check(&board[1]);
	}
	// FOUR, FIVE, SIX
	else if (*board[4] == *board[5] && *board[5] == *board[6])
	{
		check(&board[4]);
	}
	// SEVEN, EIGHT, NINE
	else if (*board[7] == *board[8] && *board[8] == *board[9])
	{
		check(&board[7]);
	}
	// ONE, FIVE, NINE
	else if (*board[1] == *board[5] && *board[5] == *board[9])
	{
		check(&board[1]);
	}
	// THREE, FIVE, SEVEN
	else if (*board[3] == *board[5] && *board[5] == *board[7])
	{
		check(&board[3]);
	}
	// ONE, FOUR, SEVEN
	else if (*board[1] == *board[4] && *board[4] == *board[7])
	{
		check(&board[1]);
	}
	// TWO, FIVE, EIGHT
	else if (*board[2] == *board[5] && *board[5] == *board[8])
	{
		check(&board[2]);
	}
	// THREE, SIX, NINE
	else if (*board[3] == *board[6] && *board[6] == *board[9])
	{
		check(&board[3]);
	}
}

void twoplayermode(char *board[], bool *lock[])
{
	clearconsole();

	static char *playerone = new char;
	static char *playertwo = new char;
	static char*playerturn = new char;

	*playerone = 'x';
	*playertwo = 'o';

	while (true)
	{
		int location = 10;

		while (true)
		{
			drawboard(board);
			checkwinner(board);
			std::cout << "Player One enter your choice: ";
			std::cin >> location;
			if (!*lock[location])
			{
				*board[location] = *playerone;
				*lock [location] = true;
				break;
			}
			else
			{
				std::cout << "You cannot overwrite " << location << "." << std::endl;
				continue;
			}
		}

		while (true)
		{
			drawboard(board);
			checkwinner(board);
			std::cout << "Player Two enter your choice: ";
			std::cin >> location;
			if (!*lock[location])
			{
				*board[location] = *playertwo;
				*lock [location] = true;
				break;
			}
			else
			{
				std::cout << "You cannot overwrite " << location << "." << std::endl;
				continue;
			}
		}
	}
}

void askmode(char *xoxo[], bool *lock[])
{
	char mode2;
	std::cout << "(P)VP or (A)I?: ";
	std::cin >> mode2;
	std::cout << "You chose: " << mode2 << "\n";
	if (mode2 == 'a' | mode2 == 'A')
	{
		std::printf("Ai Mode...\n");
		// aimode(xoxo);
		std::printf("Not yet implemented yet, exiting...\n");
		exit(-1);
	}
	else if (mode2 == '2' | mode2 == 't' | mode2 == 'T' | mode2 == 'p' | mode2 == 'P')
	{
		std::printf("2 Player Mode...\n");
		twoplayermode(xoxo, lock);
	}
	else
	{
		std::printf("Invalid Option...\n");
		exit(-1);
	}
}