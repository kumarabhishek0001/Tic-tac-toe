#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void assigningPositions(int &count, int currentPosition, map <int, char> &mpp){

    char value = 'X';
    if(count%2==0) value = 'O';

    mpp[currentPosition] = value;

    count++;
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

        assigningPositions(count, position, occupiedPositions);
    }

    for(auto it: occupiedPositions){
        cout<<it.first<<"->"<<it.second<<endl;
    }

    return 0;
}