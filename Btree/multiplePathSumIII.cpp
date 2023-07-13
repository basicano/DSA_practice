int pathSum(TreeNode* root, int targetSum, long path_sum = 0, bool prev_inc=false) {
        // no tree 
        if(root==NULL) return 0;
        
        int result = 0;
        if(targetSum-path_sum-root->val==0){
            result = 1;
        }

        if(root->left != NULL){
            //   start a new path including itself
            result += pathSum(root->left, targetSum, path_sum+ root->val, true);
            
            //   exclude itself and allow left child to start path
            if(!prev_inc) result += pathSum(root->left, targetSum, 0, false);
        }

        if(root->right != NULL){ 
            //   start a new path including itself
            result += pathSum(root->right, targetSum, path_sum+root->val, true);
            //   exclude itself and allow right child to start path
            if(!prev_inc) result += pathSum(root->right, targetSum, 0, false);
        }

        return result;
        
    }
