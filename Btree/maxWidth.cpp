#include <bits/stdc++.h>

using namespace std;

class TreeNode {
	public:
	  int data;
	  TreeNode * left, * right;
	  
	  TreeNode(int d) {
		  data = d;
		  left = NULL;
		  right = NULL;
	}
};

int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode*> q;
        int max_width = 0;
        q.push(root);
        while(!q.empty()){
            int q_size = q.size();
            int cur_width = 0;
            int i;
            for(i=0; i<q_size && q.front()==NULL; i++){
                q.pop();                            
            }
            for(; i<q_size; i++){
                // first not null node encountered
                TreeNode *temp = q.front();
                q.pop();
                cur_width++;
                if(temp!=NULL){
                	cout<<temp->data;
                    q.push(temp->left);
                    q.push(temp->right);
                    // also possibly last not null node
                    if(max_width<cur_width){
                        max_width = cur_width;
                    }
                }  
				else{
                    q.push(NULL);
                    q.push(NULL);
                }                 
            }
        }
        return max_width;
    }

int main() {

  TreeNode *root = new TreeNode(1);
  root -> left = new TreeNode(3);
  root -> left -> left = new TreeNode(5);
  root -> left -> left -> left = new TreeNode(7);
  root -> right = new TreeNode(2);
  root -> right -> right = new TreeNode(4);
  root -> right -> right -> right = new TreeNode(6);

  int maxWidth = widthOfBinaryTree(root);
  cout << "The maximum width of the Binary Tree is " << maxWidth;

  return 0;
}
