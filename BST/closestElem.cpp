#include<iostream>
#include<vector>
#include<queue>
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
		
		Node* helper(vector<int> v, int start, int end){
			if(start==end){
				return new Node(v[start]);
			}
			int mid = (start+end)/2;
			Node *n = new Node(v[mid]);
			n->left = helper(v, start, mid-1);
			n->right = helper(v, mid+1, end);
			return n;
		}
		
		void buildFromArr(vector<int> v){
			int mid = (v.size())/2;
			root = new Node(v[mid]);
			root->left = helper(v, 0, mid-1);
			root->right = helper(v, mid+1, v.size()-1);
			return;
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
		
		int closestElem(int key){
			if(root== NULL) return -1;
			int min_diff = INT_MAX;
			int closest = root->val;
			Node *temp = root;
			while(temp!=NULL){
				if(temp->val == key){
					return closest;
				}
				
				if(abs(temp->val-key)<min_diff){
					closest = temp->val;
					min_diff = abs(temp->val-key);
				}
				
				
				
				if(temp->val < key){
					temp = temp->right;
				}
				else{
					temp = temp->left;
				}
			}
			
			return closest;
		}
};

int main(){
	vector<int> v{1,2,3,4,5,6,7};
	BST t;
	t.buildFromArr(v);
	t.levelOrder(t.root);
	cout<<t.closestElem(8);
}
