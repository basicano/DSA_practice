#include<iostream>
using namespace std;

bool isValid(int mat[][9], int i, int j, int n, int no){
    //  for row
    for(int c=0; c<j; c++){
        if(mat[i][c] == no) return false;
    }
    //  for col
    for(int c=0; c<i; c++){
        if(mat[c][j] == no) return false;
    }
    // for subgrid
    int ci=3*(i/3), cj =3*(j/3);
    for(int ti= ci; ti<ci+3; ti++){
        for(int tj=cj; tj<cj+3; tj++){
            if(mat[ti][tj] == no) return false;
        }
    }
    return true;
}


bool solveSudoku(int mat[][9], int i, int j, int n){
    
    //  base case
    if(i==n && j==n){
        //  print solution and return
        for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		}

		return true;
        return true;
    }


    //  recursive case

    if(j==n){
        // i = i+1; next row
        // j = 0; first col
        return solveSudoku(mat, i+1, 0,n);
    }

    // skip prefilled cell
    if(mat[i][j] !=0 ){
        return solveSudoku(mat, i, j+1, n);
    }

    //  cell to be filled
    for(int no=1; no<=n; no++){
        //  check for valid fill
        if(isValid(mat,i,j,n, no)){
            mat[i][j] = no;
            if(solveSudoku(mat,i,j+1,n)){
                return true;
            }
        }
    }

    // nothing worked, change previous values and try again 
    // backtrack;
    mat[i][j] = 0;
    return false;

}

int main(){
    int n = 9;
    int mat[9][9]  = {{5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}};


        if(!solveSudoku(mat,0,0,n) ){
        	cout<<"No solution exists!";
        }
}