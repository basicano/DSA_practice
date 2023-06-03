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
		
		void insert(int key){
			if(root == NULL){
				root = new Node(key);
				return;
			}
			Node *temp = root;
			Node *parent = temp;
			
			while(temp!=NULL){
				parent = temp;
				if( temp->val>key){
//					insert in left
					temp = temp->left;
				}
				else{
//					insert in right
					temp = temp->right;
				}
			}
			
			if( parent->val > key ){
				parent->left = new Node(key);
			}
			else{
				parent->right = new Node(key);
			}
		}
		
		bool search(int key){
			if(root == NULL) return 0;
			
			Node *temp = root;
			while(temp!=NULL){
				if(temp->val == key){
					return 1;
				}
				if( temp->val>key){
//					insert in left
					temp = temp->left;
				}
				else {
//					insert in right
					temp = temp->right;
				}
			}
			return 0;
		}
		
		void deleteKey(int key){
			if(root == NULL){
				root = new Node(key);
				return;
			}
			Node *temp = root;
			Node *parent = temp;
			
			while(temp!=NULL){
				parent = temp;
				if(temp->val == key){
					break;
				}
				if( temp->val>key){
					temp = temp->left;
				}
				else{
					temp = temp->right;
				}
			}
			
			if( temp == NULL ) return;
			
			if( temp->left == NULL and temp->right == NULL ) {
				if( parent->val > key ){
					parent->left = NULL;
				}
				else{
					parent->right = NULL;
				}
				delete(temp);
				return;
			}
			
			if(temp->left == NULL){
				if( parent->val > key ){
					parent->left = temp->right;
				}
				else{
					parent->right = temp->right;
				}
				delete temp;
				return;
			}
			
			if( temp->right == NULL){
				if( parent->val > key ){
					parent->left = temp->left;
				}
				else{
					parent->right = temp->left;
				}
				delete temp;
				return;
			}
			
			parent = temp;
			temp=temp->right;
			
			while(temp->left != NULL){
				temp = temp->left;
			}
			
			int temp_val = temp->val;
			deleteKey(temp->val);
			parent->val = temp->val;
			return;
			
		}
};

int main(){
	
}
