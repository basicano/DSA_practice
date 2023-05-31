#include<iostream>
#include<vector>
#include<queue>
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
		
		pair<int,int> maxSubsetSum(Node *n){
			if(n==NULL) return {0,0};
			int inc_sum = n->val, exc_sum =0;
			
			pair<int,int> left_r = maxSubsetSum(n->left);
			pair<int,int> right_r = maxSubsetSum(n->right);
			
			inc_sum += left_r.second + right_r.second;
			exc_sum += left_r.first + right_r.first;
			return {inc_sum, exc_sum};
		}
};

int main(){
//				    1 2 3 4 5  6 7  8 9 10 11 12 13 14 15 16 17 18 19 20 21  
	vector<int> v{0,1,2,3,4,5,-1,6,-1,-1,7,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	BTree t;
	t.buildBTree(v);
	t.levelOrder(t.root);
	pair<int,int> p = t.maxSubsetSum(t.root);
	cout<<p.first<<" "<<p.second;
	return 0;
}
