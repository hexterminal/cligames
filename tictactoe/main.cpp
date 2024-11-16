#include <iostream>
#include "tictactoe.hpp"


/*
============= MAIN FILE =============
*/

int main(void)
{
    // char xo[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char loc0 = '0';
    char loc1 = '1';
    char loc2 = '2';
    char loc3 = '3';
    char loc4 = '4';
    char loc5 = '5';
    char loc6 = '6';
    char loc7 = '7';
    char loc8 = '8';
    char loc9 = '9';
    char *xo[10] = {&loc0, &loc1, &loc2, &loc3, &loc4, &loc5, &loc6, &loc7, &loc8, &loc9};

    bool loc0lock = false;
    bool loc1lock = false;
    bool loc2lock = false;
    bool loc3lock = false;
    bool loc4lock = false;
    bool loc5lock = false;
    bool loc6lock = false;
    bool loc7lock = false;
    bool loc8lock = false;
    bool loc9lock = false;
    bool *xolock[10] = {&loc0lock,
                        &loc1lock,
                        &loc2lock,
                        &loc3lock,
                        &loc4lock,
                        &loc5lock,
                        &loc6lock,
                        &loc7lock,
                        &loc8lock,
                        &loc9lock};
    
    drawboard(xo);
    askmode(xo, xolock);
    twoplayermode(xo, xolock);

    return EXIT_SUCCESS;
}
