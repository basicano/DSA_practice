#include<iostream>
#include<algorithm>
#include "lowerBound.h"
#include "upperBound.h"
using namespace std;

pair<int,int> minDiff(vector<int> a, vector<int> b){
	int n = a.size(), m = b.size();
	sort(b.begin(),b.end());
	int min_dif = INT_MAX;
	pair<int,int> result;
	for(int i =0; i<n; i++){
//		for a[i] fin an upper bound and lower bound if exists
		if(a[i]>b[0]){
			int lb = lowerBound(b,a[i]);
			if(a[i]-lb<min_dif){
				min_dif = a[i]-lb;
				result.first =lb;
				result.second = a[i];
			}
		}
		if(a[i]<b[m-1]){
			int ub = upperBound(b,a[i]);
			if(ub-a[i]<min_dif){
				min_dif = ub - a[i];
				result.first = a[i];
				result.second = ub;
			}
		}
		
	
	}
	return result;
}

int main(){
	vector<int> a = {23,5,10,17,30};
	vector<int> b = {26,134,135,14,19};
	pair<int,int> result  = minDiff(a,b);
	cout<<result.first<<","<<result.second;
}
