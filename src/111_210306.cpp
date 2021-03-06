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
    int minDepth(TreeNode* root) {
		if(root == NULL) {
			return 0;
		} else if(root->left == NULL) {
			return minDepth(root->right)+1;
		} else if(root->right == NULL) {
			return minDepth(root->left)+1;
		}
		int ret = min(minDepth(root->left), minDepth(root->right)) + 1;

		root->left == NULL; // 없어도 되지만, 속도를 더 빠르게 하기 위한 중간 종료용 코드
		root->right == NULL;
		return ret;
    }
};
// 후기 : 코드는 줄였는데... 속도는 딱히 별 차이 없다. 허탈하구만.

// Driver code 
int main() {
	Solution sol;
    vector<int> v = {3,9,20,NULL,NULL,15,7};
	Tree* node = new Tree(v);

	sol.minDepth(node->root);
	
	return 0;
}