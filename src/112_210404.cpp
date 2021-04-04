/*
  Construct Binary Tree from Preorder and Inorder Traversal
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

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
 * 문제 : 루트~최하위노드까지의 합 중에서 타겟값이 존재하는지 여부.
 * 
 * dfs지 뭐..
 * 
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
		if(root == NULL) { // 시작부터 NULL이면 즉시 false. 일회용.
			return false;
		}
		if(root->left == NULL && root->right == NULL) { // 최하위 노드라 갈 곳이 없을 경우.
			if(targetSum - root->val == 0) { // target 값이 맞다면, 참.
				return true;
			}
			return false;
		}
		return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val); //둘 중 하나라도 참이면 참. 
    }
};


// Driver code 
int main() {
	Solution sol;
    
    Tree tree = {5,4,8,11,NULL,13,4,7,2,NULL,NULL,NULL,1};
    int targetSum = 22;
	
	sol.hasPathSum(tree.root, targetSum);
	
	return 0;
}