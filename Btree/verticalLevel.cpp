#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

class BTree;

class Node{
	int val; 
	Node *left;
	Node *right;
	public:
		Node(){
			
		}
		
		Node(int v){
			val = v;
			left = NULL;
			right = NULL;	
		}
		
		Node(int v, Node *lptr, Node *rptr){
			val = v;
			left = lptr;
			right = rptr;	
		}		
	friend class BTree;
};

class BTree{
		
	public:
		Node* root;
		BTree(){
			root = NULL;	
		}
		
		void buildBTree(vector<int> v){
			root = helper(v,1);	
		}
		
		Node* helper(vector<int> &v, int i ){
			if(v[i]==-1) return NULL;
			
			Node *n = new Node(v[i]);
			n->left = helper(v, 2*i);
			n->right = helper(v, 2*i+1);
			return n;
		}
		
		void levelOrder(Node *root){
			queue<Node*> q;
			q.push(root);
			q.push(NULL);
			while(!q.empty()){
				Node *temp = q.front();
				q.pop();
				if(temp == NULL){
					cout<<endl;
					if(q.empty()) return;
					q.push(NULL);
				}
				else{
					cout<<temp->val<<" ";
					if(temp->left) q.push(temp->left);
					if(temp->right) q.push(temp->right);						
				}
			}			
		}
		
		void helper(Node *n, int level, map<int,vector<int>> &m){
			if(n == NULL) return;
			m[level].push_back(n->val);
			helper(n->left, level-1, m);
			helper(n->right, level+1, m);
			return;
		}
		
		void verticalOrder(){
			if(root == NULL) return;
			map<int,vector<int> > m;
			m[0].push_back(root->val);
			helper(root->left, -1, m);
			helper(root->right, 1, m);
			
			for(pair<int, vector<int>> p: m){
				cout<<"Level "<<p.first<<" --> ";
				for(int el: p.second){
					cout<<el<<" ";
				}
				cout<<endl;
			}
		}
};

int main(){
//				    1 2 3 4 5  6 7  8 9 10 11 12 13 14 15 16 17 18 19 20 21  
	vector<int> v{0,1,2,3,4,5,-1,6,-1,-1,7,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	BTree t;
	t.buildBTree(v);
	t.levelOrder(t.root);
	t.verticalOrder();
	return 0;
}
