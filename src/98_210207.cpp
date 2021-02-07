/*
  Validate Binary Search Tree
https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/625/
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
 * 문제 : 왼쪽 노드는 "모든" 직계 부모 노드보다 값이 작아야 한다. 오른쪽 노드는 "모든" 직계 부모 노드보다 값이 커야 한다. 트리가 이 규칙에 부합하면 true, 아니면 false를 리턴.
 * 하..."모든" 직계 노드 인 걸 모르고 풀었었는데, 다시 문제를 읽어보니...
 * 104번과는 다르게 하향식으로 풀어야 할 듯.
 *
 */
class Solution {
public:
	bool chkBST(TreeNode* node, long min, long max) {
		if(node == NULL) { return true; } // 노드가 비었으면 즉시 true 리턴해 위로 올라간다.
		/*
		 * 만약 트리를 왼쪽으로만 내려간다고 하면, max의 값은 LONG_MAX에서 변함이 없을 것이다. 반대도 마찬가지.
		 * 만약 트리를 왼쪽으로 타다 오른쪽으로 탄다면?
		 * 방금 갖고온 오른쪽 부모값 < node->val < 이제까지 갖고 내려온 왼쪽 최대값
		 * 지금은 이해되는것 같은데, 나중에 다시보면 이해가 될까 싶다..
		 */
		if(min >= node->val || node->val >= max) { return false; } // 노드의 값이 이제껏 갖고 내려온 최대값보다 크거나 최소값보다 작으면 즉시 false 리턴.
		return chkBST(node->left, min, node->val)&&chkBST(node->right, node->val, max); // 이제 하위 노드로 다시 잠수.
	}
	bool isValidBST(TreeNode* root) {
		return chkBST(root, LONG_MIN, LONG_MAX);
    }
	// 후기 : 더이상 생각하면 머리에 쥐나겠다. 이것만 네시간 푼듯.
};
// Driver code 
int main() {
	Solution sol;
    vector<int> v = {5,4,6,NULL,NULL,3,7};
    Tree* tree = new Tree(v);

    cout << "ans=" << sol.isValidBST(tree->root);
	return 0;
}