/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    int helper(TreeNode* node, int* current, int k){
        
        int found = 0;
        
        if(node == NULL){
            return NULL;
        }

        if(node->left != NULL){
            found = helper(node->left, current, k);
            (*current)++;
        }
        
        if((*current) > k)
            return found;
        
        //FOUND IT
        if((*current) == k){
            return node->val;
        }
        
        if(node->right != NULL){
            (*current)++;
            found = helper(node->right, current, k);
            if(*current == k)
                return found;
        }
        
        return found;
    }

    int kthSmallest(TreeNode* root, int k) {
        int* current = (int*)malloc(sizeof(int));
        *current = 1;
        
        int i = helper(root, current, k);

        return i;
    }
};