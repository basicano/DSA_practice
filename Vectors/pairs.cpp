#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

void findpair(vector<int> v, int sum){
    unordered_map<int,int> m;
    int n = v.size();
    for(int i=0; i<n ; i++){
        if(m.find(sum-v[i])!=m.end()){
            cout<<v[i]<<" "<<sum-v[i];
            return;
        }
        else{
            m[v[i]] = 1;
        }
    }
    return;
}

int main(){
	vector<int> arr={10,5,2,3,-6,9,11,-1,-5,1,-7};
	int sum=4;
	findpair(arr,sum);
}
