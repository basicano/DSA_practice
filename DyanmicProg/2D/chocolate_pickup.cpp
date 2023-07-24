#include<iostream>
#include<vector>

using namespace std;

int helper(int i, int a_j, int b_j, int r, int c, vector<vector<int>> &grid){
    if(i>r || (a_j>c && b_j<0) ) return {0,0};

    if(i == r-1){
        if(j1 == j2) return grid[i][a_j];
        else return grid[i][a_j] + grid[i][b_j];
    }

    int max_choc = INT_MIN;
    for(int dj1 = -1; dj1<=1; dj1++){
      for (int dj2 = -1; dj2<=1; dj2++) {

        int value = 0;
        if (a_j == b_j) {
            value = grid[i][j1];
        } else {
            value = grid[i][j1] + grid[i][j2];
        }

        value += findMax(i+1, j1+dj1, j2+dj2, r, c, grid);
        max_choc = max(max_choc, value);
      }
    }
    return max_choc;

}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    return result = helper(0, 0, c-1, r, c, grid);
}

int main(){
	
}
