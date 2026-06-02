#include "carts.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include<ctime>//time
#include<thread>//sleep
#include<chrono>//seconds
using namespace std;

bool files(int option,string cards[], int &count){
  ifstream fin;
  string filename;
   if (option == 1){
    filename = "_Week13FabianaRojasAnimals.txt";
  } else if (option == 2){
    filename = "_Week13FabianaRojasFantasy.txt";
  } else if (option == 3){
    filename = "_Week13FabianaRojasGreakGods.txt";   
  } else {
    return false;
  }
  fin.open(filename);
  if(!fin){
    cout<<"Error opening file."<<endl;
    return false;
  }
  while(count < MAX_TERMS && getline(fin, cards[count])){
    count++;
  }
  fin.close();
  return true;
}

bool menu(int &option, int &size, int &waitTime, string &topic){
  cout<<"Fabiana Rojas Final Project 05/09/2026"<<endl;
  cout<<"Welcome to the Memory Matching Game!"<<endl;
  cout<<"This is a game where you will have to match pairs of cards."<<endl;
  cout<<"Select a category: 1.Animals, 2.Fantasy, 3.GeekGods"<<endl;
  cin>>option;
  if(option==1){
    topic="Animal";
    }
  else if(option==2){
    topic="Fantasy";
    }
  else if(option==3){
    topic="GeekGod";
    }
  cout<<"You selected option "<< option <<": " << topic <<"."<<endl;

  if(option != 1 && option != 2 && option != 3){
    cout<<"Invalid option."<<endl;
    return false;
  
  }

  //game setup
  char level;
  cout<<"Difficulty levels: \n";
  cout<<"Easy 4x4 (write E) \n";
  cout<<"Medium 6X6 (write M) \n";
  cout<<"Hard 8X8 (write H)"<<endl;
  cout << "Choose difficulty: ";
  cin >> level;

  if(level == 'E' || level == 'e')
  { size = 4;}
  else if(level == 'M' || level == 'm')
  {size = 6;}
  else if(level == 'H' || level == 'h')
  { size = 8;}
  else
  {
    cout << "Invalid option. Please enter 'E' for Easy, 'M' for Medium, or 'H' for Hard." << endl;
    return false;
  }

  //time

  cout << "\nSelect the wait time after a wrong match (2,4,6)seconds: ";
  cin >> waitTime;
  if(waitTime != 2 && waitTime != 4 && waitTime != 6){
    cout << "Invalid wait time." << endl;
    return false;
  }
  cout<<"Let's start the game!"<<endl;
  return true;

}

void displayBoard(string board[][MAX_SIZE], bool revealed[][MAX_SIZE], int size, string topic){
  for(int b=0; b<size; b++){
      cout << setw(12) << b;
  }
   cout << endl;
  for(int a = 0; a < size; a++){
      cout << setw(3) << a;
        for(int b = 0; b < size; b++){
            if(revealed[a][b]){
              cout << setw(12) << board[a][b];
            } else {
              cout << setw(12) << topic;
            }
        }
        cout << endl;
     }
}

bool createBoard(string cards[], int count, string boardArr[][MAX_SIZE], bool revealed[][MAX_SIZE], int size){
    int pairs = (size * size) / 2;
    int total= size * size;

    if(count < pairs){
        cout<<"Not enough cards to fill the board."<<endl;
        return false;
    }
    string selecCards[MAX_CARDS];

    //two cards of each
    int index=0;
    for(int i=0; i<pairs; i++){
        selecCards[index]=cards[i];
        index++;
        selecCards[index]=cards[i];
        index++;
    }
    //shuffle
    for(int i=0; i<total; i++){
        int random = rand() % total;
        string temp = selecCards[i];
        selecCards[i] = selecCards[random];
        selecCards[random] = temp;
    }
    //fill board
    index=0;
    for(int a=0; a<size; a++){
        for(int b=0; b<size; b++){
            boardArr[a][b]=selecCards[index];
            revealed[a][b]=false;
            index++;
        }
    }
  return true;
}

bool GameStart(int size, string boardArr[][MAX_SIZE], bool revealed[][MAX_SIZE], string topic, int waitTime){
    int totalPairs = (size * size) / 2;
    int matchedPairs=0;

    auto startTime = chrono::steady_clock::now();
    while(matchedPairs<totalPairs){
        displayBoard(boardArr, revealed, size, topic);
            //get user input for card selection
            //check for match
            //update revealed and matchedPairs accordingly
        int a1, b1, a2, b2;
        cout<<"Select first card (row and column, split by space): ";
        cin>>a1>>b1;
        cout<<"Select second card (row and column, split by space): ";
        cin>>a2>>b2;
        if(a1 < 0 || a1 >= size || b1 < 0 || b1 >= size ||
           a2 < 0 || a2 >= size || b2 < 0 || b2 >= size)
        {
        cout << "Invalid position. Try again." << endl;
        continue;
        }
        if(a1 == a2 && b1 == b2)
        {
        cout << "You cannot select the same card twice." << endl;
        continue;
        }

        revealed[a1][b1] = true;
        revealed[a2][b2] = true;
        displayBoard(boardArr, revealed, size, topic);

        if(boardArr[a1][b1]==boardArr[a2][b2]){
            cout<<"It's a match!"<<endl;
            revealed[a1][b1]=true;
            revealed[a2][b2]=true;
            matchedPairs++;
        } else {
            cout<<"Not a match. Cards will be hidden in "<<waitTime<<" seconds."<<endl;
            this_thread::sleep_for(chrono::seconds(waitTime));
            revealed[a1][b1]=false;
            revealed[a2][b2]=false;
        }
    }

    //Timme
    auto endTime = chrono::steady_clock::now();
    auto totalTime = chrono::duration_cast<chrono::seconds>(endTime - startTime).count();
    cout << "Your total time was: " << totalTime << " seconds." << endl;
    return true;
}
 

