#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;


vector<vector<string>> groupAnagrams(vector<string> strs){
    //Write your code here. Do not modify the function or the parameters. 
    unordered_map<string, vector<string> > m;
    for (auto i : strs) {
    	string temp =i;
//    	STRING can also be sorted just like vector
        sort(temp.begin(), temp.end());
//        cout<<temp<<" ";
        vector<string> v;
        if(m.find(temp) != m.end()){
            v = m[temp];
        }
        v.push_back(i);
        m[temp] = v;
    }
    
    vector<vector<string>> result;
     for (auto i : m) {
         /* code */
         result.push_back(i.second);
     }
    
    return result;
}

int main(){
	vector<string> strs{"eat","tea","tan","ate","nat","bat"};
	vector<vector<string>> result = groupAnagrams(strs);
	for(auto i: result ){
		cout<<endl;
		for(auto j: i){
			cout<<j<<" ";
		}
	}
}
