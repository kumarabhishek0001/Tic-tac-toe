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


// assigns X/O to certain possition
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

        if(availablePositions(position)) assigningPositions(count, position, occupiedPositions);
            
        else cout<<"invalid input!!";
        
    }

    //getting output
    for(auto it: occupiedPositions){
        cout<<it.first<<"->"<<it.second<<endl;
    }

    return 0;
}