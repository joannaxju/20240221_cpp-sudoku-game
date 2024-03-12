#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

#include "functions.cpp"

void display_board(char[][9]);

void initialize_display_locations(bool[][9]);

void initialize_board(char[][9], bool[][9]);

void player_turn(char[][9], bool[][9], int&, int&, char&);

bool check_win(char[][9], bool[][9]);

#endif