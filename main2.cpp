#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//before assigning check whether position exists or not
bool availablePositions(int position){
    const int arr[9] = {0, 1, 2, 11, 12, 13, 21, 22, 23};

    for(int i=0; i<9; i++){
        if(arr[i] == position) return true;
    }

    return false;
}

//if the position exists check if position taken or not
bool positionTaken(int position, map <int, char> occupiedPositions){

    if(occupiedPositions[position] == 0){//this means it is not taken
        return false;
    }

    else return true;
    
}


// assigns X/O to certain possition
void assigningPositions(int &count, int currentPosition, map <int, char> &mpp){

    char value = 'X';
    if(count%2==0) value = 'O';

    mpp[currentPosition] = value;

    count++;
}


//getting output after every new entry
void printingGameState(map <int, char> occupiedPositions){

    const int arr[9] = {0, 1, 2, 11, 12, 13, 21, 22, 23};

    for(int i=0; i<9; i++){
        if(occupiedPositions[arr[i]] != 0){
            cout<<occupiedPositions[arr[i]]<<"|";
        }

        else cout<<"_|";

        if(i%3 == 2 ) cout<<endl;
    }
}

int main(){
    int count = 0; // which user will take the move (count%2==0)-> O's move if not then X's move 
    char user = 'X';
    int position; //contains the most recent position entered by user

    map <int, char> occupiedPositions;

    for(int i=0; i<3; i++){

        if(count%2==0) user='O';
        else user='X';  // to print in console whose turn is it
        cout<<user<<" enter the position: ";
        cin>>position;

        //positions checked assigned in map
        if(availablePositions(position)){

            if(!positionTaken(position, occupiedPositions)) assigningPositions(count, position, occupiedPositions);
            else cout<<"Position is already taken!! Please enter the postion again"<<endl;                   
        } 
            
        else {
            cout<<"invalid input!! Please enter the value again: "<<endl;
        }

        //getting the state of game after value is assigned
        printingGameState(occupiedPositions);

    }

    //getting output
    cout<<"--------mapvalue--------"<<endl;
    for(auto it: occupiedPositions){
        cout<<it.first<<"->"<<it.second<<endl;
    }

    return 0;
}