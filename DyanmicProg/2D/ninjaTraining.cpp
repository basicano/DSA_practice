#include<iostream>
#include<vector>
using namespace std;

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector< vector<int> > memo(n, vector<int>(3,0));
    memo[0][0] = points[0][0];
    memo[0][1] = points[0][1];
    memo[0][2] = points[0][2];
    for(int i=1; i<n; i++){
        memo[i][0] = points[i][0] + max(memo[i-1][1], memo[i-1][2]);
        memo[i][1] = points[i][1] + max(memo[i-1][0], memo[i-1][2]);
        memo[i][2] = points[i][2] + max(memo[i-1][0], memo[i-1][1]);
    }

    return max(max(memo[n-1][0], memo[n-1][1]), memo[n-1][2]);;
}

int ninjaTrainingSpaceOpt(int n, vector<vector<int>> &points)
{
    vector<int> memo(3,0);
    memo[0] = points[0][0];
    memo[1] = points[0][1];
    memo[2] = points[0][2];
    for(int i=1; i<n; i++){
        int temp1 = points[i][0] + max(memo[1], memo[2]);
        int temp2 = points[i][1] + max(memo[0], memo[2]);
        int temp3 = points[i][2] + max(memo[0], memo[1]);

        memo[0] = temp1;
        memo[1] = temp2;
        memo[2] = temp3;
    }

    return max(max(memo[0], memo[1]), memo[2]);;
}


int main(){
	
}

