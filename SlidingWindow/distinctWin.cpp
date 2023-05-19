#include<iostream>
#include<unordered_map>
#include<cstring>
using namespace std;

string stringWin(string s){
	string result=s;
	int n = s.length();
	
	unordered_map<char,int> distinct_map;
	int dis_len = 0;
	for(int i =0; i<n ; i++){
		if(distinct_map.find(s[i]) == distinct_map.end() ){
			distinct_map[s[i]] = 1;
			dis_len++;
		}		
	}
	unordered_map<char,int> win_map;
	for(int j=0; j<n; j++){
		win_map[s[j]] = 0;
	}
	
	string cur_win = "";
	int is_valid = 0;
	int i=0,j=0;
	
	
	for(j=0; j<n; j++){
//		expand
		cur_win +=s[j];
//		cout<<cur_win<<endl;
//		update 
		win_map[s[j]]++;		
		if(win_map[s[j]] == 1){
			is_valid++;
		}		
//		contract
		if(is_valid == dis_len){
			while(i<=j && win_map[s[i]]-1 >= 1){
				win_map[s[i]]--;
				cur_win = cur_win.substr(1);
//				cout<<cur_win<<endl;
				i++;
			}
			
//			select result
			if(result.length()> cur_win.length()){
				result = cur_win;
			}
			
			win_map[s[i]]--;
//					slide window
			is_valid--;
			cur_win = cur_win.substr(1);
			i++;
		}			
	}	
	return result;
}

int main(){
	string s = "aabcbcdbcaaad";
	cout<<stringWin(s);
	
}
