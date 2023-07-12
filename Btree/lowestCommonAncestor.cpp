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

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p) {
            // found first possible ancestor
            return p;
        }

        if(root==q) {
            // found first possible ancestor
            return q;
        }

        TreeNode *result1 = NULL;
        TreeNode *result2 = NULL;
        //  possible ancestor in middle of both
        if(root->left!=NULL){
            result1 = lowestCommonAncestor(root->left, p, q);
        }
        //  possible ancestor in middle of both
        if(root->right!=NULL){
            result2 = lowestCommonAncestor(root->right, p, q);
        }

        if(result1 && result2){
            return root;
        }
        else if(result1){
            return result1;
        }
        else{
            return result2;
        }
    }

};


int main() {

  TreeNode *root = new TreeNode(1);
  root -> left = new TreeNode(3);
  root -> left -> left = new TreeNode(5);
  root -> left -> left -> left = new TreeNode(7);
  root -> right = new TreeNode(2);
  root -> right -> right = new TreeNode(4);
  root -> right -> right -> right = new TreeNode(6);

  int maxWidth = lowestCommonAncestor(root,root -> left, root -> left -> left -> left);
  cout << "The maximum width of the Binary Tree is " << maxWidth;

  return 0;
}
