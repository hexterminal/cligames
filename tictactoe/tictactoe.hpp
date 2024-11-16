#ifndef TICTACTOE_H
#define TICTACTOE_H

void clearconsole();
void drawboard(char *board[]);
void greet();
void check(char *argcheck[]);
void checkwinner(char *board[]);
void twoplayermode(char *board[], bool *lock[]);
void askmode(char *xoxo[], bool *lock[]);

#endif