#include <bits/stdc++.h>
#inlcude<stack>
using namespace std;

vector<int> stockSpanner(vector<int> &stocks){
	vector< pair<int,int> > span;
	int n = stocks.size();
    stack<int> s;
	int count;
    s.push(stocks[0], 1);
    span.push_back(1);
	for(int i=1; i<n; i++){
        count = 1;
	    while(!s.empty() && s.top().first<stocks[i]){
            s.pop();
            count++;
        }
        s.push({stocks[i],i});
        span.push_back(count);
	}
	return span;
}