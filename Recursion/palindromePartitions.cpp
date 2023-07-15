#include<iostream
#include<vector>
#include<string>
using namespace std;

int palindromePartition(string s){
	if( s.lenght() == 0 ) {
		return 1;
	}
		
	int n = s.length();
	int result = 0;
	for(int i=idx; i<n; i++){
		for(int j= i ; j<n; j++){
			bool flag = true;
			for(int k = 0; k<(j-i+1)/2; k++){
				if(s[i+k] != s[j-k]){
					flag = false;
					break;
				}
			}
			if(flag){
				result += palindromePartition( s.substr(j+1) );
			}
		}
	}
	
	return result;
}

int main(){
	
}
