#include "carts.h"
#include <iostream>
#include<string>//text
#include<cstdlib>//rand,srand

using namespace std;

int main(){
    srand(time(0));
    int option, size, waitTime;
    int count = 0;
    string topic;
    string cards[MAX_CARDS];
    bool revealed[MAX_SIZE][MAX_SIZE];
    string boardArr[MAX_SIZE][MAX_SIZE];

    //call menu
    if(!menu(option, size, waitTime, topic)){
        return 1;
    }
    //call files
    if(!files( option, cards, count)){
        return 1;
    }
    //board
    
    if(!createBoard(cards,count, boardArr, revealed, size)){
        return 1;
    }
    //game
    if(!GameStart(size, boardArr, revealed, topic, waitTime)){
        return 1;
    }

    cout<<"Congratulations! You've matched all pairs!"<<endl;
    system("pause");
    return 0;    
    
};
   

     

