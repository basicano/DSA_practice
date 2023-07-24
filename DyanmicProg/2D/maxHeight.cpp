#include<iostream>
#include<vector>
using namespace std;

int MaxHeightRecursive(char last_sel_row, int i, int j, int n, vector<int> a, vector<int> b){
	if(last_sel_row == 'a'){
		if(j>=n) return 0;
		
		int sub_problem1 = MaxHeightRecursive('b', i+1, j+1, n, a, b) + b[j];
		int sub_problem2 = MaxHeightRecursive('a', i+1, j+1, n, a, b);
		return max(sub_problem1, sub_problem2);
	}
	else{
		if( i>=n) return 0;
		
		int sub_problem1 = MaxHeightRecursive('a', i+1, j+1, n, a, b) + a[i];
		int sub_problem2 = MaxHeightRecursive('b', i+1, j+1, n, a, b);
		return max(sub_problem1, sub_problem2);
	}
	
}

int maxHeightTopDown(char last_sel_row, int i, int j, int n, vector<int> a, vector<int> b,  vector< pair<int, int> >  memo){
	if(last_sel_row == 'a'){
		if(j>=n) return 0;
		
		int sub_problem1, sub_problem2;
		if(memo[i+1].second == -1){
			sub_problem1 = MaxHeightRecursive('b', i+1, j+1, n, a, b);
		}
		else{
			sub_problem1 = memo[i+1].second;
		}
		
		if(memo[i+1].first == -1){
			sub_problem2 = MaxHeightRecursive('a', i+1, j+1, n, a, b);
		}
		else{
			sub_problem2 = memo[i+1].first;
		}
		
		memo[i].first = max(sub_problem1 + b[j], sub_problem2);
		return memo[i].first;
	}
	else{
		if( i>=n) return 0;
		
		int sub_problem1, sub_problem2;	
		if(memo[i+1].first==-1){
			sub_problem1 = MaxHeightRecursive('a', i+1, j+1, n, a, b);
		}
		else{
			sub_problem1 = memo[i+1].first;
		}   
		
		if(memo[i+1].second == -1){
			sub_problem2 = MaxHeightRecursive('b', i+1, j+1, n, a, b);
		}
		else{
			sub_problem2 = memo[i+1].second;
		}
		
		
		memo[i].second = max(sub_problem1+a[i], sub_problem2);
		return memo[i].second;
	}
}

int maxHeightBottomUp(int n, vector<int> a, vector<int> b){
	vector< pair<int,int> > memo(n,{-1,-1});
	
	memo[n-1].first = b[n-1];
	memo[n-1].second = a[n-1];
	for(int i = n-2; i>=0; i-- ){
		memo[i].first = max( memo[i+1].second + b[i], memo[i+1].first );
		memo[i].second = max( memo[i+1].first + a[i], memo[i+1].second );
	}
	
	return max(memo[0].first, memo[0].second);
}

int main(){
	vector<int> a{3,2,1};
	vector<int> b{2,5,9};
	
	cout<<max(MaxHeightRecursive('b',0,0,3,a,b), MaxHeightRecursive('a',0,0,3,a,b))<<endl;
	
	vector< pair<int,int> >  memo(3,{-1,-1});
	cout<<max(maxHeightTopDown('b',0,0,3,a,b, memo), maxHeightTopDown('a',0,0,3,a,b, memo))<<endl;
	
	cout<<maxHeightBottomUp(3,a,b);
}
