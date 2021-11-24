#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class tree {
private:
    TreeNode* helper(vector<int>& preorder, vector<int>& postorder,int& num,int& cnt){
        TreeNode* node = new TreeNode(preorder[num++]);
        if(postorder[cnt]!=node->val){
            node->left = helper(preorder,postorder,num,cnt);
        }
        if(postorder[cnt]!=node->val){
            node->right = helper(preorder,postorder,num,cnt);
        }
        cnt++;
        return node;
    }
    void traversal(TreeNode* root,vector<int>& ans){
        if(root==nullptr) return;
        traversal(root->left,ans);
        ans.push_back(root->val);
        traversal(root->right,ans);
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int num=0,cnt=0;
        return helper(preorder,postorder,num,cnt);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) return ans;
        traversal(root,ans);
        return ans;
    }
};
int main(){
    vector<int> preorder{1,2,4,5,3,6,7},postorder{4,5,2,6,7,3,1};
    tree T;
    TreeNode* t = T.constructFromPrePost(preorder,postorder);
    vector<int> a = T.inorderTraversal(t);
    for (auto i : a) cout << i;
    return 0;
}