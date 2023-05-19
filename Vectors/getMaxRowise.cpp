#include<iostream>
#include<vector>
using namespace std;


void getMaximumInEachRow(vector< vector<int> > &nums){
    int max;
	for(int i = 0; i<3; i++){
		max = nums[i][0];
		for(int j=0; j<5; j++){
			if(max < nums[i][j]){
				max = nums[i][j];
			}
		}
		cout<<max<<endl;
	}   
}  

int main(){
	vector< vector<int> > vec2d ;
	vector<int> in_vec[3];
	
	for(int i = 0; i<3; i++){
		for(int j=0; j<5; j++){
			in_vec[i].push_back((i+1)*(j+1));
		}
		vec2d.push_back(in_vec[i]);
	}
	
	getMaximumInEachRow(vec2d);
}
