/*
  Maximum Depth of Binary Tree
https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/555/
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
 * 문제 : 주어진 이진트리의 최대 깊이를 구하라
 * 순환함수 방식의 깊이 탐색 알고리즘 필요할 듯
 */
class Solution {
public:
    // 순환함수
    int findDepth(TreeNode* node, int depth) {
        if(node==NULL) { return depth; } // NULL이면 순환을 끊고 현재값 리턴.
        depth++; // 순환이 끊기지 않았으면 깊이 증가

        return max(findDepth(node->left, depth), findDepth(node->right, depth)); // 왼쪽으로 순환해 들어간 값과 오른쪽으로 순환해 들어간 값을 비교해 더 큰 값을 돌려줌.
    }
    int maxDepth(TreeNode* root) {
        int ret = 0;
        return findDepth(root, ret);
    }
};

// Driver code 
int main() {
	Solution sol;
    vector<int> v = {3,9,20,NULL,NULL,15,7};
    Tree* tree = new Tree(v);

    cout << "ans=" << sol.maxDepth(tree->root);
	return 0;
}