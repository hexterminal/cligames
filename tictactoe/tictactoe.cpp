#include <cstdio>
#include "tictactoe.hpp"
#include <iostream>
#include <string>
#include <random>

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

/*char askxo(char *somearg)
{
	static char *playerone = new char;
	static char *playertwo = new char;
	switch (*somearg)
	{
	case 'X':
	case 'x':
		return 'x'
	case 'O':
	case 'o':
		return 'o'
	default:
		printf("Invalid Value, Player One will be assigned with \"x\"\n
			Player Two will be assigned with \"o\"\n");
		*playerone = 'x';
		*playertwo = 'o';
	}
	return value
}*/

void aimode(char *board[])
{
	clearconsole();

	static char *playerone = new char;
	static char *playertwo = new char;
	static char*playerturn = new char;

	*playerone = 'x';
	*playertwo = 'o';

	std::random_device rd;

	while (true)
	{
		std::uniform_int_distribution<int>random(1,2);
		int location = 10;

		drawboard(board);
		checkwinner(board);
		std::cout << "Player One enter your choice: ";
		std::cin >> location;
		*board[location] = *playerone;

		drawboard(board);
		checkwinner(board);
		std::cout << "Ai is thinking...\n";

		// THE MAIN AI PART IS HERE
		if (*board[1] == *playerone)
		{
			*board[location] = random(rd);
		}
		else if (*board[2] == *playerone)
		{
			*board[location] = random(rd);
		}
		else if (*board[3] == *playerone)
		{
			*board[location] = random(rd);
		}
		else if (*board[4] == *playerone)
		{
			*board[location] = random(rd);
		}
	}
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

void twoplayermode(char *board[])
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

		drawboard(board);
		checkwinner(board);
		std::cout << "Player One enter your choice: ";
		std::cin >> location;
		*board[location] = *playerone;

		drawboard(board);
		checkwinner(board);
		std::cout << "Player Two enter your choice: ";
		std::cin >> location;
		*board[location] = *playertwo;
	}
}

void askmode(char *xoxo[])
{
	char mode2;
	std::cout << "(P)VP or (A)I?: ";
	std::cin >> mode2;
	std::cout << "You chose: " << mode2 << "\n";
	if (mode2 == 'a' | mode2 == 'A')
	{
		std::printf("Ai Mode...\n");
		// aimode(xoxo);
		std::printf("Not yet implemented completely, Exiting...\n");
		exit(-1);
	}
	else if (mode2 == '2' | mode2 == 't' | mode2 == 'T' | mode2 == 'p' | mode2 == 'P')
	{
		std::printf("2 Player Mode...\n");
		twoplayermode(xoxo);
	}
}