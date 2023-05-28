#include<iostream>
#include<string>

using namespace std;
class suffixTrie;

class Node{
	char ch;
	Node **char_node;
	bool is_terminal;
	public:
		Node(char c){
			this->ch = c;
			this->char_node = new Node*[26];
			for(int i=0;i<26; i++){
				char_node[i] = NULL;
			}
			this->is_terminal = false;
		}
		
	friend class suffixTrie;
};

class suffixTrie{
	Node *root;
	public:
		suffixTrie(){
			root = new Node('\0');
		}
		
		void add_suffix(string s){
			int n = s.length();
			for(int i=0; i<n; i++){
				Node *temp = root;
				for(int j=i; j<n; j++){
					cout<<s[j];
					if(temp->char_node[s[j]-97] == NULL)
						temp->char_node[s[j]-97] = new Node(s[j]);
					
					temp = temp->char_node[s[j]-97];
				}
				temp->is_terminal = true;
				cout<<endl;
			}			
			return;
		}
		
		bool search_suffix(string s){
			int n = s.length();
			Node *temp = root;
			for(int i=0; i<n; i++){
				if(temp->char_node[s[i]-97] == NULL) 
					return false;
				temp = temp->char_node[s[i]-97];
			}
			if(temp->is_terminal) return true;
			return false;
		}	
};

int main(){
	suffixTrie t;
	t.add_suffix("apple");
	
	string s = "ple";
	if(t.search_suffix(s)){
		cout<<" Prefix "<<s<<" found"<<endl;
	}
	else{
		cout<<" Prefix "<<s<<" not found"<<endl;
	}
}

