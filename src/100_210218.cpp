/*
  Same Tree
https://leetcode.com/problems/same-tree/
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
 * 문제 : 두 트리를 비교해 같으면 true, 다르면 false 리턴.
 *
 * 재귀함수를 사용해 간단히 풀 수 있다.
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) { return true; } // 둘 다 NULL이면 같으므로 true 리턴.
		else if(p == NULL || q == NULL) { return false; } // 둘 중 하나만 NULL이면 false 리턴.
		if(p->val != q->val) { return false; } // 값을 비교해 다르면 false 리턴.
		return isSameTree(p->left, q->left)&&isSameTree(p->right, q->right);
    }
};
// Driver code 
int main() {
	Solution sol;
    vector<int> v = {1,2,2,3,4,4,3};
    Tree* p = new Tree(v);
	Tree* q = new Tree(v);

    cout << "ans=" << sol.isSameTree(p->root, q->root);

	delete p, q;

	return 0;
}