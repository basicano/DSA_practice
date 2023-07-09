#include<bits/stdc++.h>
using namespace std;


int maxProduct(vector<int>& nums) {
    // your code goes here
    priority_queue<int> num_heap;
    
    for(int x: nums){
        num_heap.push(x);
    }
    int num1 = num_heap.top()-1;
    num_heap.pop();
    int num2 = num_heap.top()-1;
    
    return num1*num2;
}




