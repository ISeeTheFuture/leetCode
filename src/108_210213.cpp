/*
  Convert Sorted Array to Binary Search Tree
https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/631/
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
 * 문제 : 
 * 
 * 
 *
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
    }
};


// Driver code 
int main() {
	Solution sol;
    vector<int> v = {3,9,20,NULL,NULL,15,7};
    Tree* tree = new Tree(v);
	
	sol.sortedArrayToBST(v);
	
	return 0;
}