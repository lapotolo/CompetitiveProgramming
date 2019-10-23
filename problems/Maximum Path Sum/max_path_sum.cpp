#include <algorithm>
#include <climits>

// struct Node { // given by the judge
//     int data;
//     Node* left, * right;  
// };

int visit_and_sum(struct Node *root, int& max) {
  if(!root) return 0;
  int max_left  = visit_and_sum(root->left, max);
  int max_right = visit_and_sum(root->right, max);
  int path_sum  = max_left + root->data + max_right;
  if(path_sum > max) max = path_sum;
  if(max_right > max_left) return max_right + root->data;
  return max_left + root->data;
}

int maxPathSum(struct Node *root) {
  int max = INT_MIN;
  visit_and_sum(root, max);
  return max;
}
