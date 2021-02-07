/*
  Symmetric Tree
https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/627/
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
 * 문제 : 트리의 정 가운데를 중심으로 두고 좌우가 거울처럼 대칭되는 모양인지 확인.
 * 바깥쪽 노드끼리 비교, 안쪽 노드끼리 비교해야 한다.
 *
 */
class Solution {
public:
	bool isMirror(TreeNode* nodeLeft, TreeNode* nodeRight) {
		if(nodeLeft == NULL && nodeRight == NULL) { return true; } // 둘 다 NULL이면 true;
		if(nodeLeft == NULL || nodeRight == NULL) { return false; } // 둘 중 하나만 NULL? false;
		
		// case 1 : 현재 좌우 노드의 값 비교.
		// case 2 : 왼쪽의 왼쪽 노드, 오른쪽의 오른쪽 노드 비교(바깥쪽 비교)
		// case 3 : 왼쪽의 오른쪽 노드, 오른쪽의 왼쪽 노드 비교(안쪽 비교)
		return (nodeLeft->val == nodeRight->val)&&isMirror(nodeLeft->left, nodeRight->right)&&isMirror(nodeLeft->right, nodeRight->left);		
	}

    bool isSymmetric(TreeNode* root) {
        if(root == NULL) { return true; }
		return isMirror(root->left, root->right);
    }
	// 후기 : 자신있게 제출하고 보니 생각보다 복잡도가 낮지 않은데, 어떻게 복잡도를 더 내려야 할 지 감도 안잡힌다. 아니... 평균이 안된다고?
};
// Driver code 
int main() {
	Solution sol;
    vector<int> v = {1,2,2,3,4,4,3};
    Tree* tree = new Tree(v);

    cout << "ans=" << sol.isSymmetric(tree->root);
	return 0;
}