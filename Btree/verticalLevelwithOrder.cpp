#include<iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, priority_queue<int, vector<int>, greater<int>> > > vertical_store;;
        helper(root, 0, 0, vertical_store);
        vector< vector<int> > result;

        for(auto el: vertical_store){
            map<int, priority_queue<int, vector<int>, greater<int> > > temp = el.second;

            vector<int> temp_result;
            for(auto i : temp){
                while(!i.second.empty()){
                    temp_result.push_back(i.second.top());
                    i.second.pop();
                }
            }
            
            result.push_back(temp_result);
        }

        return result;
    }

    void helper(TreeNode *root, int ver_level, int hor_level, map<int, map<int, priority_queue<int, vector<int>, greater<int>> > > &vertical_store){
        if(root == NULL) return;
        cout<<root->val<<" ";
        vertical_store[ver_level][hor_level].push(root->val);

        helper(root->left, ver_level-1, hor_level+1, vertical_store);
        helper(root->right, ver_level+1, hor_level+1, vertical_store);

        return; 
    }
};
