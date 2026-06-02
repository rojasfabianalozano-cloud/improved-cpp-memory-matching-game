#ifndef CARTS_H
#define CARTS_H
#include <string>
using namespace std;

const int MAX_SIZE = 8;
const int MAX_CARDS = 64;
const int MAX_TERMS = 50;

bool files(int option,string cards[], int &count);
bool menu(int &option, int &size, int &waitTime, string &topic);
void displayBoard(string board[][MAX_SIZE], bool revealed[][MAX_SIZE], int size, string topic);
bool createBoard(string cards[], int count, string boardArr[][MAX_SIZE], bool revealed[][MAX_SIZE], int size);
bool GameStart(int size, string boardArr[][MAX_SIZE], bool revealed[][MAX_SIZE], string topic, int waitTime);

#endif


    