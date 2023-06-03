#include<iostream>

using namespace std;

class Node{
	public:
		int val;
		Node *left;
		Node *right;
		
		Node(){
			left= NULL;
			right = NULL;
		}
		
		Node(int v){
			val = v;
			left= NULL;
			right = NULL;
		}
		
};

class BST{
	public: 
		Node *root;
		
		BST(){
			root= NULL;
		}
		
		void helper(vector<int> v, int start, int end){
			if(start==end){
				return new Node(v[start]);
			}
			int mid = (start+end)/2;
			Node n = new Node(v[mid]);
			n->left = helper(v, start, mid-1);
			n->right = helper(mid+1, end);
			return n;
		}
		
		void buildFromArr(vector<int> v){
			int mid = (start+end)/2;
			root = new Node(v[mid]);
			root->left = helper(v, 0, mid-1);
			root->right = helper(mid+1, v.size()-1);
			return;
		}
		
	
};

int main(){
	
}
