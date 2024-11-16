#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>

#define DELAY 30

void showTitleScreen();
void showMenuScreen(int high, int current, int low);
void gamePlayScreen(int *high, int *low);
void howToPlayScreen();

int main() {
	
	char option;
	
	int high_score = 0;
	int current_score = 0;
	int lowest_score = 0;
	
	showTitleScreen();
	showMenuScreen(high_score, current_score, lowest_score);
	
	scanf("%c", &option); fflush(stdin);
	
	switch (option) {
		case '1':
			gamePlayScreen(&high_score, &lowest_score);
			break;
		case '2':
			howToPlayScreen();
			break;
		case '3':
			break;
		default :
			showMenuScreen(high_score, current_score, lowest_score);
			break;
	}
	
	return 0;
}

void gamePlayScreen(int *high, int *low) {
	game_start:
	system("cls");
	
	int m = 17;
	int n = 31;
	char gameMap[30][100] = {
		"##############################",
		"#* #         #   ###*   #   *#",
		"#  ###   ##   #     #   ###  #",
		"#      *  #  #####       #   #",
		"#   #######    #  #          #",
		"#                 *#  ####   #",
		"#     #####  ###      # * #  #",
		"0     # * #   *#   #     #   0",
		"####  #   ######  #####  #   #",
		"#                    #   *####",
		"#   #  #####   # #####       #",
		"#          #   #   *     #   #",
		"# #######  #  ####       # * #",
		"#   #   ###    #* ####  #### #",
		"#   #    *     #             #",
		"##############################",
	};
	
	char move;
	int pos_x = 5, pos_y = 12;
	int prev_pos_x = pos_x, prev_pos_y = pos_y;

	bool gameOver = false;
	int score = 0;
	int steps = 0;
	int block_placer = 0;
	
	char gameOverScreen[30][100] = {
		"                               ",
		"           Game Over           ",
		"-------------------------------",
		" High Score    : %d            ",
		" Current Score : %d            ",
		" Lowest Score  : %d            ",
		"-------------------------------",
		"                               ",
		"       PLAY AGAIN [Y/N]        "
	};
	
	while(!gameOver) {
		for (int map_y = 0; map_y < m; map_y++) {
			for (int map_x = 0; map_x < n; map_x++) {
				
				// Walls Detection
				
				if (gameMap[pos_y][pos_x] == '#') {
					pos_x = prev_pos_x;
					pos_y = prev_pos_y;
				}
				
				// Colision Detection
				
				if (gameMap[pos_y][pos_x] == 'o') {
					gameOver = true;
				}
				
				if (gameMap[pos_y][pos_x] == '*') {
					score++;
					gameMap[pos_y][pos_x] = ' ';
				}
				
				if (block_placer > 20) {
					gameMap[prev_pos_y][prev_pos_x] = 'o';
					block_placer = 0;
				}
				
				// Portal Detection 
				
				if (gameMap[pos_y][pos_x] == '0') {
					if (pos_x == 0) {
						pos_x = 28;
					} else {
						pos_x = 1;
					}
				}
				
				// Put Char on Screen if found in for loop
				
				if (pos_y == map_y && pos_x == map_x) {
					printf("?");
				} else {
					printf("%c", gameMap[map_y][map_x]);
				}
			}
			
			if (steps == 0) {
				Sleep(DELAY);
			}
			printf("\n");
		}
		
		printf("\nScore : %d\n", score);
		printf("Steps : %d\n", steps / 2);
		printf("\nInput Movement : ");
		
		scanf("%c", &move);
		
		if (tolower(move) == 'w') {
			prev_pos_y = pos_y;
			pos_y--;
		}
		
		if (tolower(move) == 'a') {
			prev_pos_x = pos_x;
			pos_x--;
		}
		
		if (tolower(move) == 's') {
			prev_pos_y = pos_y;
			pos_y++;
		}
		
		if (tolower(move) == 'd') {
			prev_pos_x = pos_x;
			pos_x++;
		}
		
		system("cls");
		steps++;
		block_placer++;
	}
	
	if (score >= *high) {
		*high = score;
	}
	
	if (score <= *low) {
		*low = score;
	}
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < i; j++) {
			
			if (j == 3) {
				printf(" High Score    : %d            ", *high);
				printf("\n");
				continue;
			}
			
			if (j == 4) {
				printf(" Current Score : %d            ", score);
				printf("\n");
				continue;
			}
			
			if (j == 5) {
				printf(" Lowest Score  : %d            ", *low);
				printf("\n");
				continue;
			}
			printf("%s", gameOverScreen[j]);
			printf("\n");
		}
		Sleep(DELAY);
		
		if (i != 9) {
			system("cls");
		}
	}
	
	char game_continue;
	fflush(stdin);
	scanf("%c", &game_continue);
	
	if (tolower(game_continue) == 'y') {
		goto game_start;
	} 
	
	
}

void howToPlayScreen() {
	printf("How To Screen!");
}

void showMenuScreen(int high, int current, int low) {
	
	char menuScreen[30][100] = {
		"-------------------------------",
		" High Score    : %d            ",
		" Current Score : %d            ",
		" Lowest Score  : %d            ",
		"-------------------------------",
		"                               ",
		" 1. Play                       ",
		" 2. How to Play                ",
		" 3. Exit                       "
	};
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < i; j++) {
			
			if (j == 1) {
				printf(" High Score    : %d            ", high);
				printf("\n");
				continue;
			}
			
			if (j == 2) {
				printf(" Current Score : %d            ", current);
				printf("\n");
				continue;
			}
			
			if (j == 3) {
				printf(" Lowest Score  : %d            ", low);
				printf("\n");
				continue;
			}
			printf("%s", menuScreen[j]);
			printf("\n");
		}
		Sleep(DELAY);
		
		if (i != 9) {
			system("cls");
		}
	}
	
}

void showTitleScreen() {
	char titleScreen[30][100] = {
		"---------------^---------------",
		"===============================",
		"        GALAXY EXPLORER        ",
		"        <------------->        ",
		"===============================",
		"---------------^---------------",
		"                               ",
		"        ~ Press Enter ~        ",
		"                               ",
	};
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < i; j++) {
			printf("%s", titleScreen[j]);
			printf("\n");
		}
		Sleep(DELAY);
		
		if (i != 9) {
			system("cls");
		}
	}
	
	getchar();
}