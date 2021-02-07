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
 * 지난 풀이 복잡도가 신통치 않고, 함수 하나로도 풀 수 있을 거 같아서 재도전.
 */
class Solution {
public:
    // 역시 순환함수 구조
    int maxDepth(TreeNode* root) {
        if(root==NULL) { return 0; } // NULL일 경우 0을 리턴하며 순환을 끊음.
        return max(maxDepth(root->left), maxDepth(root->right))+1; // 위에서 봤듯 하위 노드가 없을경우 0을 리턴하는데, ☆★상위 노드로 한 칸씩 올라갈 때마다 +1 씩 증가★☆
		// 상향식 풀이? 가장 깊이 들어가 올라가면서 +1
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