/*
  Minimum Depth of Binary Tree
https://leetcode.com/problems/minimum-depth-of-binary-tree/
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
 * TreeNode, Tree 클래스는 driver Code를 수월하게 굴리기 위함.
 * 문제 풀이와는 무관. 
 */
class TreeNode {
public:
	int val;
	TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Tree {
public:
	TreeNode* root = NULL;
	Tree(vector<int> a) {
		root = bst(a, 0, a.size()-1);
	}
	TreeNode* bst(vector<int> a, int start, int end) {
		if (start <= end) {
			int mid = (start + end) / 2;
			TreeNode* newNode = new TreeNode(a[mid]);
			newNode->left = bst(a, start, mid - 1);
			newNode->right = bst(a, mid + 1, end);
			return newNode;
		}
		return NULL;
	}
};

/*
 * 문제 : 최소 깊이 구하기
 * 
 */
class Solution {
public:
	int findDepth(TreeNode* node, int depth){
		if(node == NULL){
			return depth-1;
		} else if(node->left==NULL&&node->right==NULL){
			return depth;
		} else if(node->left==NULL) {
			return findDepth(node->right, depth+1);
		} else if(node->right==NULL) {
			return findDepth(node->left, depth+1);
		}
		return min(findDepth(node->left, depth+1), findDepth(node->right, depth+1));
	}
    int minDepth(TreeNode* root) {
		if(root == NULL){
			return 0;
		} else if(root->left==NULL&&root->right==NULL){
			return 1;
		} else if(root->left==NULL) {
			return findDepth(root->right, 2);
		} else if(root->right==NULL) {
			return findDepth(root->left, 2);
		}
		return min(findDepth(root->left, 2), findDepth(root->right, 2));
    }
};
// 후기 : 코드를 줄일 수 있을 것 같은데..

// Driver code 
int main() {
	Solution sol;
    vector<int> v = {3,9,20,NULL,NULL,15,7};
	Tree* node = new Tree(v);

	sol.minDepth(node->root);
	
	return 0;
}