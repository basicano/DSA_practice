#include<iostream>
#include<>
#include<unordered_map>
using namespace std;

class Trie;
class Graph;

class Node{
	char ch;
	unordered_map **char_node;
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
	friend class Graph;
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
	friend class Graph;
};

class Graph{
	int V;
	list<int> *g;
	
	public:
		Graph(int n){
			this->V = n;
			g = new list<int>[n];
		}
		
		void addEdge(int v1, int v2, bool directed=false){
			g[v1].push_front(v2);
			if(!directed){
				g[v2].push_front(v1);
			}
		}
		
		void removeEdge(int v1, int v2, bool directed=false){
			g[v1].remove(v2);
			if(!directed){
				g[v2].remove(v1);
			}
		}
		
		void printAdjList(){
			for(int v=0; v<V; v++){	
				cout<<v<<" -> ";
				for (auto i : g[v]) {
			        cout << i << " ";
			    }
				cout<<endl;
			}
		}
		
		int find_words(Trie t){
			
			for(int i=0; i<n; i++){
    			for(int j=0; j<m; j++){
    				
				}
			}
		}
};

int main(){
	vector<vector<char>> board{
		{'S','E','R','T'},
		{'U','N','K','S'},
		{'T','C','A','T'}
	};
	
	vector<string>> words{"SNAKE", "FOR","QUEZ", "SNACK", "SNACKS", "SENS", "TUNES", "CAT"};
	
//	 forming trie of words
	Trie t_words;
	t_words.add_word("SNAKE");
	t_words.add_word("FOR");
	t_words.add_word("QUEZ");
	t_words.add_word("SNACK");
	t_words.add_word("SENS");
	t_words.add_word("TUNES");
	t_words.add_word("CAT");
	
	int n = board.size();
    int m = board[0].size();
    int max_land = INT_MIN;
    
    for(int i=0; i<n; i++){
    	for(int j=0; j<m; j++){
    		int node = i*m+j;
    		g.node_weights[node] = grid[i][j];
    		if(j+1<m){ 
				// right move is possible
				g.addEdge(node, i*m+j+1);
			}
    		if((i+1)<n){ 
				// down move is possible
    			g.addEdge(node, (i+1)*m+j);
			}
			
		}
	}
	
	cout<<g.find_words(t_words); 
    
   
    
}
