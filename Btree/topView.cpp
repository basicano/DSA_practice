#include<iostream>

using namespace std;

// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

vector<int> topView(Node *root){
        // Your code here
        vector<int> result;
        if(root==NULL) {
            return result;
        }
        
        map<int,int> m;
        queue< pair<Node*,int> > q;
        
        q.push(make_pair(root,0));
        while(!q.empty()){
            pair<Node*, int> p = q.front();
            q.pop();
            Node *cur = p.first;
            int ver_level = p.second;
            if( m.find(ver_level) == m.end() ){
                m[ver_level] = cur->data;
            }
            
            if(cur->left){
                q.push(make_pair(cur->left, ver_level-1));
            }
            if(cur->right){
                q.push(make_pair(cur->right, ver_level+1));
            }
        }
        
        for(auto i: m){
            result.push_back(i.second);
        }
        
        return result;
        
    }
