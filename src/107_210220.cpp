/*
  Binary Tree Level Order Traversal II
https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
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
 * 문제 : [3,9,20,null,null,15,7]의 값을 가진 트리를 [[15,7],[9,20],[3]]의 벡터 자료구조화 시키자.
 * 지난번 102번 문제를 단순히 뒤집은 것.
 * 103번 문제 방식으로 풀면 될 듯.
 *
 */
class Solution {
public:
    void mapLevelOrder(map<int, vector<int>>& map, TreeNode* node, int level) {
        if(node == NULL) { return; }
        map[level].push_back(node->val); // 현재 층의 map의 가장 뒤에 값 추가.

        mapLevelOrder(map, node->left, level+1); // 순서는 왼쪽 -> 오른쪽 순으로.
        mapLevelOrder(map, node->right, level+1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        map<int, vector<int>> map;

        mapLevelOrder(map, root, 0);
        int mapSize = map.size();
        for(int i = 1; i <= mapSize; i++) {
            ret.push_back(map[mapSize - i]); // map을 뒤에서부터 읽어 값을 추가해준다.
        }
        return ret;
    }
};
// 후기 : 역시 성능이 조금 안나온다. map 때문인듯. 제출하면 다른 사람의 코드를 볼 수 있는데, queue를 사용한게 도통 이해가 안된다. 그리고 그게 왜 더 효율적이지?

// Driver code 
int main() {
	Solution sol;
    vector<int> v = {3,9,20,NULL,NULL,15,7};
    Tree* tree = new Tree(v);
	
	sol.levelOrderBottom(tree->root);
	
	return 0;
}