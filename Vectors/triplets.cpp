#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int> > triplets(vector<int> v, int sum){
	int n = v.size();
	sort(v.begin(), v.end());
	int target;
	vector< vector<int> > result;
	for(int i=0; i<n; i++){
		target = sum-v[i];
		int j = i+1, k=n-1;
		while(j<k){
			if(v[j]+ v[k]==target){
				vector<int> temp ; 
				cout<<v[i]<<" "<<v[j]<<" "<<v[k]<<endl;
				temp.push_back(v[i]);
				temp.push_back(v[j]);
				temp.push_back(v[k]);				
				j++; 
				k--;
			}
			else if(v[j]+ v[k] < target){
				j++;
			}
			else{
				k--;
			}
		}
	}
	return result;
}

int main(){
	vector<int> arr{1,2,3,4,5,6,7,8,9,15};
	int sum=18 ;
	triplets(arr,sum);
	
}
