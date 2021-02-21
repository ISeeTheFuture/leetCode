/*
  Balanced Binary Tree
https://leetcode.com/problems/balanced-binary-tree/
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
 * 문제 : 좌우 레벨의 차이가 1 이하여야만 한다.
 * 
 * 트리 최하단부터 비교를 시작해야한다. bottom-up 방식으로 생각해보자.
 */
class Solution {
public:

	int pathFinder(TreeNode* node) {
		if(node == NULL) { return 0; } // 가장 바닥에 닿았다. 0부터 시작해서 이제 위로 올라갈 때마다 레벨 + 1

		int left = pathFinder(node->left);
		int right = pathFinder(node->right);

		if(left < 0 || right < 0) { return -1; } // 두 자식 트리 중 하나라도 차이가 1 초과했을 경우엔 이 이상 연산하지 않고 그대로 리턴.

		if(abs(left - right) > 1) { return -1; } // 좌우의 레벨 차이가 1을 초과하면 -1를 리턴

		// 여기까지 왔으면 좌우의 레벨 차이가 1 이하인 것이므로, 레벨을 1 더해서 돌려준다.
		return max(left, right)+1;
	}
    bool isBalanced(TreeNode* root) {
		if(pathFinder(root) < 0) { return false; }
		return true;
    }
};

// Driver code 
int main() {
	Solution sol;
    vector<int> v = {3,9,20,NULL,NULL,15,7};
	Tree* node = new Tree(v);

	sol.isBalanced(node->root);
	
	return 0;
}