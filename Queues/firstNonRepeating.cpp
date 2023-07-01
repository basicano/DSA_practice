#include<iostream>
#include<queue>
using namespace std;

vector<char> firstnonrepeating(vector<char> str){
	if(str.size() == 1) return str;
	
	queue<int> q;
	int map[26] = {0};
	for(int i=0 ; i<str.size()); i++){
		if( map[str[i]] == 0 ){ // letter encountered first time
			map[str[i]]++;
			q.push(str[i]);
			
			while(!q.empty() && map[q.front()]>1){
				q.pop();
			}
		}
		else{
			
		}
	}
	
	
}

int main(){
	
	
}
