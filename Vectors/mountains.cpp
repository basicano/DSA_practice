#include<iostream>
#include<vector>
using namespace std;

bool is_peak(vector<int> v, int idx){
	if(idx == 0){
		return false;
	}
//	int n = v.size();
	if(v.size()-1 == idx){
		return false;
	}
	return v[idx-1] < v[idx] && v[idx] > v[idx+1];
}

int mountains(vector<int> v){
	int n = v.size();
	int peak_start=0, peak_end;
	int len = INT_MIN;
	for(int i=1; i<n; i++){
		if(is_peak(v,i)){
//			calculate peak end
			peak_end = i+1;
			while(peak_end<n && v[peak_end-1] > v[peak_end]){
				peak_end++;
			}
//			cout<<peak_end<<endl;
			len = max(len, peak_end-peak_start);
			
			i = peak_end;
//			update peak start for next peak
			peak_start = peak_end;
		}
		
	}
	cout<<len;
	return len;
}

int main(){
//				  0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 
	vector<int> v{1,2,3,4,3,2,3,4,5,6,7, 6, 5, 4,  1,2};
	mountains(v);
	return 0;
}
