#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool checkValueInPositions(vector <int> vec, int toCheck){

    for(auto it: vec){
        if (it == toCheck) return true;
    }
    return false;
}

void gameState(int position, vector <int> &positions, int &count){
    
    char value;
    positions.push_back(position);

    if(count%2 == 0){
        value = 'O';
    }
    else value = 'X';

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            
            int check;
            check = (i*10)+j;

            if(checkValueInPositions(positions, check)){
                if(j==2) cout<<value;

                else cout<<value<<"|";
            }
            else{
                if(j==2 || i==2){
                    cout<<"_|";
                } 
                else cout<<"_|";
            }

            if(j==2) cout<<endl;
        }
    }

    count++;
}
int main(){
    
    int position=0;
    vector <int> positions;
    
    int count = 0;
    char user;

    for(int i=0; i<3; i++){

        if(count%2 == 0) user = 'O';
        else user = 'X';

        cout<<user<<" enter position: ";
        cin>>position;
        gameState(position, positions, count);
    }


    return 0;
}