bool isBST_util(Node* root, int l_value, int r_value) {
  if(!root) return true;
  
  int val = root->data;
  
  if(val < l_value or val > r_value) return false;
  
  return isBST_util(root->left, l_value, min(r_value, val)) 
    and isBST_util(root->right, max(l_value, val), r_value);
}   

bool isBST(Node* root) {
  return isBST_util(root, 0, 1001);
}
