#include<iostream>
using namespace std;

vector<vector<int>> generate(int numRows) {
    if (numRows == 0) return {};
    if (numRows == 1) return {{1}};
    if (numRows == 2) return {{1},{1,1}};
    vector<vector<int>> triangle {{1},{1,1}};
    
    for (int i = 2; i <= numRows - 1; i++){
        vector<int> row = {1};
        for (int j = 0; j < triangle[i-1].size() - 1; j++){
            row.push_back(triangle[i-1][j] + triangle[i-1][j + 1]);
        }
        row.push_back(1);
        triangle.push_back(row);
    }
    return triangle;
}
