#include <bits/stdc++.h>
#include<vector>
using namespace std;

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    int end_row = n;
    int end_col = m;
	
	int start_row = 0, start_col=0;
	
	while(start_row<end_row || start_col<end_col ){
		int temp = mat[start_row][start_row], temp2;
        // top row shift right by 1 
        for(int j=start_col; j<end_col-1; j++){
            temp2 = mat[start_row][j+1];
            mat[start_row][j+1] = temp;
            temp = temp2;
        }

        // right last col shift down by 1 
        for(int j=start_row; j<end_row-1; j++){
            temp2 =mat[j+1][end_col-1];
            mat[j+1][end_col-1] = temp;
            temp = temp2;
        }

        // bottom row shift left by 1 
        for(int j=end_col-1; j>start_col; j--){
            temp2 = mat[end_row-1][j-1];
            mat[end_row-1][j-1] = temp;
            temp = temp2;
        }

        // right first col shift up by 1 
        for(int j=end_row-1; j>start_row; j--){
            temp2 =mat[j-1][start_col];
            mat[j-1][start_col] = temp;
            temp = temp2;
        }

        start_col++;
        end_col--;
        start_row++;
        end_row--;
	}

}

int main(){
	vector<vector<int>> mat{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			cout<<setw(3)<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	rotateMatrix(mat,4,4);
	
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			cout<<setw(3)<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}
