#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool checkValueInPositions(vector <int> vec, int toCheck){

    for(auto it: vec){
        if (it == toCheck) return true;
    }
    return false;
}

void gameState(int position){
    vector <int> positions;
    positions.push_back(position);

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            
            int check;
            check = (i*10)+j;

            if(checkValueInPositions(positions, check)){
                if(j==2) cout<<"X";
                else cout<<"X|";
            }
            else{
                if(j==2 || i==2){
                    cout<<"_";
                } 
                else cout<<"_|";
            }

            if(j==2) cout<<endl;
        }
    }
}
int main(){
    
    int position=0;
    cout<<"X enter position: ";
    cin>>position;

    gameState(position);

    
    
    return 0;
}