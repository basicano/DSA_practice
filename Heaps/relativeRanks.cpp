#include<bits/stdc++.h>
#include<string>
using namespace std;

vector<string> findRelativeRanks(vector<int>& score) {
    
    priority_queue< pair<int,int> > pq;
    int n =  score.size();
    for(int i=0; i<n; i++){
        pair<int,int> p(score[i],i);
        pq.push(p);
    }
    
    vector<string> result(n);
    
    pair<int,int> temp;
    temp = pq.top();
    result[temp.second] = "Gold Medal";
    pq.pop();
    
    temp = pq.top();
    result[temp.second] = "Silver Medal";
    pq.pop();
    
    temp = pq.top();
    result[temp.second] = "Bronze Medal";
    pq.pop();
    
    int count =4;
    while(!pq.empty()){
        string str = to_string(count++);
        temp = pq.top();
        result[temp.second] = str;
        pq.pop();
    }
    
    return result;
    
    // priority_queue<pair<int,int>> pq;
    //     for(int i=0; i<score.size(); i++){
    //         pq.push({score[i],i});
    //     }
       
    // int n= score.size();
    
    // vector<string> vec(n);
   
    
    // int cnt=0;
    
    
    // while(!pq.empty()){
    //     cnt++;
        
    //     if(cnt==1){
    //         cout<<"hey"<<endl;
    //         vec[pq.top().second].append("Gold Medal");
    //     }
    //     else if(cnt==2){
    //         vec[pq.top().second].append("Silver Medal");
    //     }
    //     else if(cnt==3){
    //         vec[pq.top().second].append("Bronze Medal");
    //     }
    //     else {
    //         vec[pq.top().second].append(to_string(cnt));
    //     }
    //     pq.pop();
    // }
    // return vec;
}


