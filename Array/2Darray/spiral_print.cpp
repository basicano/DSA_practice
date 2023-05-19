#include<iostream>
using namespace std;

int main(){
    int n = 4, m =4;
    int arr[n][m] ={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

    int start_row = 0;
    int end_col = n-1;
    int end_row = m-1;
    int start_col = 0;

    while(start_row<end_row || start_col<end_col){
        //start row 
        for(int i=start_col; i<=end_col; i++){
            cout<<arr[start_row][i]<<" ";
        }

        //end col
        for(int i=start_row+1; i<=end_row; i++){
            cout<<arr[i][end_col]<<" "  ;
        }

        //end row
        for(int i=end_col-1; i>=start_col; i--){
            cout<<arr[end_row][i]<<" ";
        }

        //start col
        for(int i=end_row-1; i>=start_row+1; i--){
            cout<<arr[i][start_col]<<" ";
        }

        start_row++;
        end_row--;
        start_col++;
        end_col--;
    }

    
}