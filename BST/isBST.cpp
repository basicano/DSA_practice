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

bool is_bst(Node *root){
	if(root == NULL) return true;
	
	bool r_ans = is_bst(root->right);
	bool l_ans = is_bst(root->left);
	
	if(root->right && root->right->val < root->val) return false;
	if(root->left && root->left->val > root->val) return false;
	
	return r_ans && l_ans;
}

int main(){
	Node *root = new Node(4);
	root->left = new Node(2);
	root->right = new Node(6);
	
	root->left->left = new Node(1);
	root->left->right = new Node(2);
	root->right->left = new Node(5);
	root->right->right = new Node(7);
	
	flattenBST(root);
}
