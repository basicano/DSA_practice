#include<iostream>
#include<vector>
using namespace std;
 
int gameOfGreed (vector<int> vec, int start, int end){
//	if(start==end) return vec[start];
//	base case
	if(start>end) return 0;
	
//	donot forget to add the profit of the picked value
	int result1 = vec[start] + min(gameOfGreed(vec, start+1, end-1), gameOfGreed(vec, start+2, end));
	int result2 = vec[end] + min(gameOfGreed(vec, start+1, end-1), gameOfGreed(vec, start, end-2));
	
	return max(result1,result2);	
}
 
int maxProfit(vector<int> v){
	return gameOfGreed(v,0,v.size()-1);
}
int main(){
	vector<int> v{1,2,3,4};
	cout<<maxProfit(v);
}
