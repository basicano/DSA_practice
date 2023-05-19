#include<iostream>
#include<cmath>
using namespace std;

bool isAttack(int **chess_board, int i_check, int j_check, int n){
    for(int i=0; i<i_check; i++){
        for(int j=0; j<n; j++){
            if(chess_board[i][j] == 1 && j==j_check){
                return true;
            }
            if(chess_board[i][j] == 1 && abs(j-j_check)==abs(i-i_check)){
                return true;
            }
        }
    }
    return false;
}

void print(int **chess_board, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<chess_board[i][j];
        }
        cout<<endl;
    }
    cout<<"hello this is one answer"<<endl;
}

void nQueens(int **chess_board, int i, int n){
    if(i==n){
        print(chess_board,n);
        return;
    }

    for(int j=0; j<n; j++){
        if(!isAttack(chess_board, i, j, n)){
            chess_board[i][j] = 1;
            nQueens(chess_board, i+1, n);
            chess_board[i][j] = 0;
        }
    }
    
    
}

bool isnQueen(int **chess_board, int i, int n){
    if(i==n){
        return true;
    }

    for(int j=0; j<n; j++){
        if(!isAttack(chess_board, i, j, n)){
            chess_board[i][j] = 1;
            if( isnQueen(chess_board, i+1, n) ){
                return true;
            }
            chess_board[i][j] = 0;
        }
    }
    return false;
}

int main(){
    int n=4; 
    // cin>>n;
    int **arr = new int*[n];
    for(int i=0; i<n; i++){
        arr[i] = new int[n];
        for(int j=0; j<n; j++){
            arr[i][j] = 0;
        }
    }

    if(isnQueen(arr, 0, n)) cout<<"solvable";
    else cout<<"unsolvable";


}