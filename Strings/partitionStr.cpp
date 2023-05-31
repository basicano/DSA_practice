#include<iostream>

using namespace std;

int partitionString(string s) {
    if(s.length()==0) return 0;
    unordered_map<char,int> char_map;
    int count = 1;
    int n = s.length();
    for(int idx=0; idx<n; idx++){
        if( char_map.find(s[idx]) != char_map.end()  && char_map[s[idx]] > 0 ){
            char_map.clear();
            count++;
        }
        char_map[s[idx]]++;
    }
    return count;
}

int partitionString_REC(string s, int idx=0) {		// MEMORY LIMIT EXCEEDED 
    if(s.length()==0) return 0;
    unordered_map<char,int> char_map;
    int count = 1;
    int n = s.length();
    for(; idx<n; idx++){
        if( char_map.find(s[idx]) != char_map.end()  && char_map[s[idx]] > 0 ){
            return 1+ partitionString_REC(s,idx);
        }
        char_map[s[idx]]++;
    }
    return count;
}

int main(){
	
}
