#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class BTree;

class Node{
	public:
	int val; 
	Node *left;
	Node *right;
	Node *parent;
		Node(){
			left = NULL;
			right = NULL;
			parent = NULL;
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
			root = helper(v,1,NULL);	
		}
		
		Node* helper(vector<int> &v, int i, Node *p ){
			if(v[i]==-1) return NULL;
			
			Node *n = new Node(v[i]);
			n->parent = p;
			n->left = helper(v, 2*i , n);
			n->right = helper(v, 2*i+1, n);
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
		
		void printAtLevelK(Node* root, int k){
			if(root==NULL){
				return;
			}
			if(k==0){
				cout<<root->val<<" ";
				return;
			}
			printAtLevelK(root->left,k-1);
			printAtLevelK(root->right,k-1);
			return;
		}

		
		void nodeAtDistK(Node *target, int k, bool exp_l=true, bool exp_r=true ){
			if(target == NULL || k<0 ) return;
//			Print lower nodes at level k
			if(k==0){
				cout<<target->val;
				return;
			}
			
			if(exp_l){
				printAtLevelK(target->left,k-1);
			}
			
			if(exp_r){
				printAtLevelK(target->right,k-1);
			}
			
			if(target->parent == NULL) return;

			
//			to go up and call on other subtree
			if(target->parent->left == target){ 	// target lies in left
				cout<<target->parent->val<<" ";
				if(k>=2)nodeAtDistK(target->parent, k-1, false, true);
			}
			else{									// target lies in right
				cout<<target->parent->val<<" ";
				if(k>=2)nodeAtDistK(target->parent, k-1, true, false);				
			}
		}
		
		
};

int main(){
//				    1 2 3 4 5  6 7  8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 
	vector<int> v{0,1,2,3,4,5,-1,6,-1,-1,7,8,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 9, 10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	BTree t;
	t.buildBTree(v);
	t.levelOrder(t.root);
	
	cout<<endl<<endl;
	Node *target = t.root->left->right;		//5
//	cout<<endl<<target->val;
//	cout<<" "<<target->parent->val<<"     ";
	t.nodeAtDistK(target, 2);
	return 0;
}
