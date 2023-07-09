
#include<bits/stdc++.h>
using namespace std;

int minSetSize(vector<int>& arr) {
    // your code goes here
    
    int n = arr.size();
    unordered_map<int,int> mp;
    
    for(int X : arr){
        mp[X]++;
    }
    
    priority_queue<int> els;
    
    for(auto x : mp){
        els.push(x.second);
    }
    
    int sum = els.top(); 
    els.pop();
    int count = 1;
    
    while(sum<n/2){
        sum += els.top();
        els.pop();
        count++;
    }
    
    return count;
}
