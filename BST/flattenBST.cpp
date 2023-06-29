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

class LNode{
	public:
		int val;
		Node *next;
		
		LNode(int v){
			val = v;
			next = NULL;
		}
};

class LL{
	public:
	LNode *head;
	LNode *tail;
	LL(){
		head = NULL;
		tail = NULL;
	}
};

LL flattenBST(Node *root){
	if(root = NULL){
		LL l = new LL();
		return l;	
	}
	LNode *cur = new LNode(root->val);
	
	if(root->left != NULL && root->right!= NULL){
		LL leftLL = flattenBST(root->left);
		LL rightLL = flattenBST(root->right);
		leftLL.tail->next = cur;
		cur->next = rightLL.head;
		
		LL joined = new LL();
		joined.head = leftLL.head;
		joined.tail = right.tail;
		return joined;
	}
	if(root->left != NULL){
		LL leftLL = flattenBST(root->left);
		leftLL.tail->next = cur;
		
		LL joined = new LL();
		joined.head = leftLL.head;
		joined.tail = cur;
		return joined;
	}
	if(root->right != NULL){
		LL rightLL = flattenBST(root->right);
		cur->next = rightLL.head;
		
		LL joined = new LL();
		joined.head = cur;
		joined.tail = right.tail;
		return joined;		
	}
	else{
		LL l = new LL();
		l.head = l.tail = cur;
		return l;
	}
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





