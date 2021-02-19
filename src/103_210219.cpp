/*
  Binary Tree Zigzag Level Order Traversal
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

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
 * 문제 : [3,9,20,null,null,15,7]의 값을 가진 트리를 [[3],[20,8],[15,7]]의 벡터 자료구조화 시키자. 레벨 하나씩 내려갈 때마다 노드의 순서가 바뀐다.
 *
 */
class Solution {
public:
    void qLevelOrder(map<int, vector<int>>& map, TreeNode* node, int level) {
        if(node == NULL) { return; }
        if(level%2==0) {
            map[level].insert(map[level].begin(), node->val);
        } else if(level%2!=0) {
            map[level].push_back(node->val);
        }
        qLevelOrder(map, node->right, level+1);
        qLevelOrder(map, node->left, level+1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        map<int, vector<int>> map;

        qLevelOrder(map, root, 0);
        for(int i = 0; i < map.size(); i++) {
            ret.push_back(map[i]);
        }
        return ret;
    }
};
// insert 때문에 성능 나빠지는데... 일단 어거지로 풀었다. 102번이랑 같이 좀 더 고민해봐야겠다.


// Driver code 
int main() {
	Solution sol;
    vector<int> v = {3,9,20,NULL,NULL,15,7};
    Tree* tree = new Tree(v);
	
	sol.zigzagLevelOrder(tree->root);
	
	return 0;
}