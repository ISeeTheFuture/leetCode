/*
  Binary Tree Level Order Traversal
https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/628/
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
 * 문제 : [3,9,20,null,null,15,7]의 값을 가진 트리를 [[3],[9,20],[15,7]]의 벡터 자료구조화 시키자.
 * 
 * 음...bottom-up 방식의 순환 함수로 풀어야 할 듯.
 *
 */
class Solution {
public:
    int depthTree(TreeNode * root) { // 깊이를 탐색하기 위한 함수.
        if(!root) return 0;
        int left = depthTree(root->left);
        int right = depthTree(root->right);
        return 1+max(left,right);
    }

    bool recorder(vector<vector<int>> &ret, int& nodeVal, TreeNode* node, int level) {
        if(node==NULL) { return false; }

        int input = 0;
        if(recorder(ret, input, node->left, level+1)) { // 만약 node->left 값이 있다면,
            ret[level].push_back(input); // 현재 층의 가장 뒤에 값을 추가.
        }
        if(recorder(ret, input, node->right, level+1)) {
            ret.at(level).push_back(input);
        }
        nodeVal = node->val;

        return true;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
		if(root==NULL) {return {};}
        vector<vector<int>> ret = {{root->val}};

        int deep = depthTree(root);

        for(int i = 1; i < deep; i++){ // 깊이를 미리 계산해 그만큼의 공간확보를 해둔다.
            vector<int> tmp = {};
            ret.push_back(tmp);
        }

        recorder(ret, deep, root, 1); // 여기서 deep을 넣는건 아무 의미없다. 그냥 메모리 아끼기 위해서.

        return ret;
    }
};
// 후기 : 답은 맞췄는데, 너무 비효율 적이다. 뭔가 잘못 생각하고 있다. 보완할 것이 많은데, 고칠 필요는 없다. 어차피 처음부터 다시 풀어야 된다.
// 탐색을 두 번 한다는게 말이 안된다.
// 제출 후 다른 사람 풀이를 보니, 큐를 활용해서 푼다.. vector만 써야하는줄 알았는데....


// Driver code 
int main() {
	Solution sol;
    vector<int> v = {3,9,20,NULL,NULL,15,7};
    Tree* tree = new Tree(v);
	
	sol.levelOrder(tree->root);
	
	return 0;
}