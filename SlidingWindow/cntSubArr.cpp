#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int cntSubArr(vector<int> v, int sum){
//	 calculate prefix
	int n = v.size();
	int prefix =0;
	
	int cnt = 0;
	unordered_map<int,int> m;
	m[0]=1;
	for(int i=0; i<n; i++){

		prefix += v[i];
		if(m.find(prefix-sum) != m.end()){
			cnt+= m[prefix-sum]; 
		}
		if(m.find(prefix) == m.end()){
			m[prefix] = 1;
		}
		else{
			m[prefix]++;
		}
		
		
		
	}
	return cnt;
}

int main(){
	vector<int> v{10, 2, -2, -20, 10};
	cout<<cntSubArr(v,-10);
}
