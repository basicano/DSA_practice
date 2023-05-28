#include<iostream>
#include<string>

using namespace std;
class Trie;

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
		
	friend class Trie;
};

class Trie{
	Node *root;
	public:
		Trie(){
			root = new Node('\0');
		}
		
		void add_word(string s){
			int n = s.length();
			Node *temp = root;
			for(int i=0; i<n; i++){
//				cout<<s[i]-97<<" ";
				if(temp->char_node[s[i]-97] == NULL)
					temp->char_node[s[i]-97] = new Node(s[i]);
				temp = temp->char_node[s[i]-97];
			}
			temp->is_terminal = true;
			return;
		}
		
		bool search(string s){
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
	Trie t;
	t.add_word("hello");
	t.add_word("world");
	t.add_word("apple");
	
	string s = "app";
	if(t.search(s)){
		cout<<" Word "<<s<<" found"<<endl;
	}
	else{
		cout<<" Word "<<s<<" not found"<<endl;
	}
	
	s = "apple";
	if(t.search(s)){
		cout<<" Word "<<s<<" found"<<endl;
	}
	else{
		cout<<" Word "<<s<<" not found"<<endl;
	}
	
	s = "world";
	if(t.search(s)){
		cout<<" Word "<<s<<" found"<<endl;
	}
	else{
		cout<<" Word "<<s<<" not found"<<endl;
	}
}
