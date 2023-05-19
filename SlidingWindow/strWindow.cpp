#include<iostream>
#include<unordered_map>
#include<cstring>
using namespace std;

string stringWin(string big, string small){
	string result=big;
	int big_len = big.length();
	int small_len = small.length();
	
	unordered_map<char,int> small_map;
	
	for(int i =0; i<small_len ; i++){
		if(small_map.find(small[i]) != small_map.end() ){
			small_map[small[i]]++;
		}
		else{
			small_map[small[i]] = 1;
		}		
	}
	
	unordered_map<char,int> win_map;
	for(int j=0; j<big_len; j++){
		win_map[big[j]] = 0;
	}
	
	string cur_win = "";
	int is_valid = 0;
	int i=0,j=0;
	
	
	for(int j=0; j<big_len; j++){
//		expand
		cur_win +=big[j];
//		update 
		win_map[big[j]]++;		
		if(small_map.find(big[j]) != small_map.end() && win_map[big[j]] <= small_map[big[j]]){
			is_valid++;
		}		
//		contract
		if(is_valid == small_len){
			while(i<=j){
				cout<<cur_win<<endl;
				if(small_map.find(big[i]) != small_map.end() && win_map[big[i]]-1 < small_map[big[i]]){
					
//					select result
					if(result.length()> cur_win.length()){
						result = cur_win;
					}
					
					win_map[big[i]]--;
//					slide window
					is_valid--;
					cur_win = cur_win.substr(1);
//					cout<<cur_win<<endl;
					i++;
					break;
				}
				win_map[big[i]]--;
				cur_win = cur_win.substr(1);
				cout<<cur_win<<endl;
				i++;
			}
		}
//		shift window
//		select result
//		if(result.length()> cur_win.length()){
//			result = cur_win;
//		}			
	}	
	return result;
}

int main(){
	string big = "helloworld";
	string small = "lol";
	cout<<stringWin(big,small);
	
}
