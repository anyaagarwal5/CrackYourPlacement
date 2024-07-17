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
    void combo(TreeNode* root, int val,vector<TreeNode*>&ans)
    {
        if(root==NULL) return;

        if(root->val==val)
        {
            if(root->left!=NULL)
                ans.push_back(root->left);
             if(root->right!=NULL)
                ans.push_back(root->right);
            return;
             
            
        }
        combo(root->left,val,ans);
        combo(root->right,val,ans);
    }
    TreeNode* combodel(TreeNode* root, int val,int &c,vector<TreeNode*>&ans)
    {
        if(root==NULL) return NULL;

        if(root->val==val)
        {
            if(root->left!=NULL)
                ans.push_back(root->left);
            if(root->right!=NULL)
                ans.push_back(root->right);
            delete root;
            c=1;
            return NULL;
             
            
        }
        root->left=combodel(root->left,val,c,ans);
        root->right= combodel(root->right,val,c,ans);
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& del) {
        vector<TreeNode*>ans;
        ans.push_back(root);
        // for(int i=0;i<del.size();i++)
        // {

        //     combo(root,del[i],ans);
        // }
        
        for(int i=0;i<del.size();i++)
        {
            for(int j=0;j<ans.size();j++)
            {
                int c=0;
                TreeNode* t= combodel(ans[j],del[i],c,ans);
                if(t==NULL) 
                    ans.erase(ans.begin()+j);

                if(c) break;

            }
        }
        return ans;

    }
};