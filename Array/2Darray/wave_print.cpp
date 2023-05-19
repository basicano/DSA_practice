#include<iostream>
using namespace std;

int main(){
    int n = 4, m = 4;

    int arr[n][m] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}   };
    
    for(int i=m-1; i>=0; i--){
        if(i%2==1){
            for(int j=0; j<n; j++){
                cout<<arr[j][i]<<" ";
            }
        }
        else{
            for(int j=n-1; j>=0; j--){
                cout<<arr[j][i]<<" ";
            }
        }
    }
}