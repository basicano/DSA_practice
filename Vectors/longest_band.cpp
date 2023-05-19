#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std; 

int longestBand(vector<int> v){
	unordered_map<int,int> m;
	int n = v.size();
	for(int i=0; i<n; i++){
		m[v[i]] = i;
	}
	int len = INT_MIN;
	for(int i=0; i<n; i++){
		if(m.find(v[i]-1)==m.end()){
			// this is the smallest element of band
			int band_it = v[i];
			int temp = 1;
			while(m.find(band_it+1)!=m.end()){
				temp++;
//				donot forget to increamnet iterators used :: INFINTE LOOP!!!
				band_it++;
			}	
			len = max(len, temp);		
		}
	}
	cout<<len;
	return len;
}

int main(){
	vector<int> v{10,1,2,3,5,7,8,9,6};
	longestBand(v);
}
