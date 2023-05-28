#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

void helper(string input, string output, int i, int n, unordered_map<vector<int>, vector<string> > &result){
	if(i==n){
//		reached the end of the input string 
//		make anagram map
		int len = output.length();
		if(n==1) return;
		cout<<output<<endl;
		vector<int> char_map(26,0);
		for(int i=0; i<len; i++){
			char_map[output[i-97]]  = char_map[output[i-97]]+1;
		}
		
//		string temp = output;
//		sort(temp.begin(), temp.end());
		vector<string> v;
		if(result.find(char_map) !=  result.end())	v = result[temp];
		v.push_back(output);
		result[char_map] = v;
		return;
	}
	else{
//		include current letter
		helper(input, output+input[i], i+1, n, result);
//		exclude current letter
		helper(input, output, i+1, n, result);
		
		return;
	}
}

void anagramSubstring(string str){
	int n = str.length();
	unordered_map<vector<int>, vector<string> > result;
	helper(str, "", 0, n, result);
	
	for(auto p: result){
//		cout<<p.first<<"->";
		for(auto i: p.second){
			cout<<i<<" ";
		}
		cout<<endl;
	}
	
}

int main(){
	string s = "abba";
	anagramSubstring(s);
}
