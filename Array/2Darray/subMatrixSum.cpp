#include<bits/stdc++.h>
using namespace std;

int sum(vector<vector<int>> v, int sr, int sc, int er, int ec){
    // your code goes here
    int sum = 0;
    for(int i=sr; i<=er; i++){
        for(int j=sc; j<=ec; j++){
            sum+=v[i][j];
        }
    }
    return sum;
}

