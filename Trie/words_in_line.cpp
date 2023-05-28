#include<iostream>
#include<string>
#include<vector>

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
		
		vector<string> search_doc(string doc, vector<string> words){
			vector<string> result;
			for(int i=0; i<doc.length(); i++){
		
				if(root->char_node[doc[i]-97] != NULL){
					string res = "";
//					cout<<"here"<<doc[i]<<" ";
					Node *temp = root;
					bool not_found = false;
					for(int j=i; j<doc.length(); j++){
						if(temp->char_node[doc[j]-97] == NULL) {
							break;						
						}
						res+=doc[j];						
//						cout<<res<<" ";
						temp = temp->char_node[doc[j]-97];
					}
					if(temp->is_terminal){
						result.push_back(res);
					}
					cout<<endl;
				}
									
			}
			return result;
		}
};

int main(){
	vector<string> words{"cutecat","ttle","cat","quick","big"};
	string doc = "littlecutecatlovestocode";
	Trie t;
	for(int i=0; i<words.size(); i++){
		t.add_word(words[i]);
	}
	
	vector<string> result = t.search_doc(doc, words);
	cout<<"Words found are: ";
	for(int i=0; i<result.size(); i++){
		cout<<result[i]<<" ";
	}
	
}
