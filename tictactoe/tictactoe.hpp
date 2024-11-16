#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <string>

void clearconsole();
void drawboard(char *board[]);
void greet();
// char askxo();
void aimode(char *board[]);
void check(char *argcheck[]);
void checkwinner(char *board[]);
void twoplayermode(char *board[]);
void askmode(char *xoxo[]);

#endif