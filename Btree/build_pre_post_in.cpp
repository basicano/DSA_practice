#include<iostream>
#include<vector>
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
//			cout<<i<<" "; 
			Node *n = new Node(v[i]);
			n->left = helper(v, 2*i);
			n->right = helper(v, 2*i+1);
			return n;
		}
		
		void preorder(Node *n){
			if(n==NULL) return;
			preorder(n->left);
			preorder(n->right);
			cout<<n->val<<" ";			
		}
		
		void postorder(Node *n){
			if(n==NULL) return;
			cout<<n->val<<" ";
			preorder(n->left);
			preorder(n->right);			
		}
		
		void inorder(Node *n){
			if(n==NULL) return;
			preorder(n->left);
			cout<<n->val<<" ";
			preorder(n->right);
		}
};

int main(){
//				    1 2 3 4 5  6 7  8 9 10 11 12 13 14 15 16 17 18 19 20 21  
	vector<int> v{0,1,2,3,4,5,-1,6,-1,-1,7,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	BTree t;
	t.buildBTree(v);
	t.preorder(t.root);
	cout<<endl;
	t.postorder(t.root);
	cout<<endl;
	t.inorder(t.root);
	return 0;
}

