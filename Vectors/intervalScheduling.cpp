#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
	return a.second<b.second;
}

int intervalScheduling(vector<pair<int,int>> v){
	int n = v.size();
	int result=1;
	sort(v.begin(), v.end(), compare);
	int cur = 0;
	for(int i=1; i<n; i++){
		if(v[i].first >=v[cur].second){
			cur = i;
			result++;
		}
	}
	return result;
}

int main(){
	vector< pair<int,int> > v{{7,9}, {0,10} ,{4,5},{8,9},{4,10},{5,7}};
	cout<<intervalScheduling(v);
	return 0;
}
