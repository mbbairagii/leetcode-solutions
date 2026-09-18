/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr){
            return "#,";
        }

        return to_string(root->val) + "," +serialize(root->left)+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* build(stringstream& ss){
        string value;
        getline(ss, value,',');
        if(value=="#"){
            return nullptr;
        }

        TreeNode* root=new TreeNode(stoi(value));
        root->left=build(ss);
        root->right=build(ss);
        return root;
    }
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return build(ss);

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));