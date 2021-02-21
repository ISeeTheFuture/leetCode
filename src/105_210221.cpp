/*
  Construct Binary Tree from Preorder and Inorder Traversal
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
 * 문제 : 위, 왼쪽부터 순서대로 탐색한 preorder값과, 왼쪽, 아래에서부터 순서대로 탐색한 inorder 값을 조합해 트리를 완성하라.
 * [3,9,20,15,7] [9,3,15,20,7]
 * => [3,9,20,null,null,15,7]
 * 
 * 위 예시가 도저히 이해가 안되서 삽질 끝에 아래 테스트 케이스가 성립한다는 것을 알아냈다.. 이 테스트 케이스 보면 이해가 될 듯.
 * [1,2,4,5,3,6,7] [4,2,5,1,6,3,7]
 * => [1,2,3,4,5,6,7]
 * 
 * 더 규모를 키워보면
 * [1,2,4,8,9,5,10,11,3,6,12,13,7,14,15] [8,4,9,2,10,5,11,1,12,6,13,3,14,7,15]
 * =>[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
 * 
 * 같은 숫자 하나씩 지우고 테스트 해보자. 결과에선 그 숫자가 null이 된다.
 * 
 * 이제 풀이를 생각해보면,
 * 1. 레벨 당 1,2,4,8,16 순으로 노드가 많아진다.
 * 2. 해당 레벨에 맞는 개수의 노드가 있는지 확인하고, 아니라면 null을 넣는다.
 * 3. preorder는 기준점으로 삼자.
 * 4. inorder를 어떻게 parsing 하느냐가 관건...계속 반으로 나뉜다는 것을 염두에 두고 생각해보자.
 */
class Solution {
private:
// 전역변수로 쓰며 무조건 뒤로 한 칸씩 이동하지 절대 되돌아 가는 일 없다.
    int preorderPosition = 0;
    int inorderPosition = 0;
public:
    TreeNode* builder(vector<int>& preorder, vector<int>& inorder, int refNode) {
        if(preorderPosition >= preorder.size()) { return NULL; } // 종료조건 : preorder 다 읽으면 종료.
        
        // inorder는 가장 바닥까지 내려갔을 때 올라오면서 index를 올린다. preorder가 node를 1,2,3 순으로 만들면, inorder는 2,1,3 순으로 index가 올라간다는걸 이해할 것.
        if(inorder[inorderPosition] == refNode) {
            inorderPosition++;
            return NULL;
        }

        TreeNode* node = new TreeNode(preorder[preorderPosition]); // 노드는 무조건 preoder만 보고 만든다.
        preorderPosition++; // preorder는 node 만들면서 index를 올린다.

        node->left = builder(preorder, inorder, node->val);
        node->right = builder(preorder, inorder, refNode);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return builder(preorder, inorder, -3001); // -3000~3000 범위 외의 숫자면 아무거나 상관없다. 문제 조건이 그렇기 때문.
    }
};
// 후기 : 이거 hard 여야 되는거 아닌가? 문제부터 이해하기 어렵게 불친절하고..
// 내가 공간감이 떨어져서 그런가 풀이 과정 중에 함수 실행 과정을 상상하면서도 자꾸 헷갈려서 노트를 3장 넘게 써가면서 풀었다.
// 성능은 딱히 좋지도 나쁘지도 않고 중상 정도?


// Driver code 
int main() {
	Solution sol;
    
    vector<int> vPreorder = {3,9,20,15,7};
    vector<int> vInorder = {9,3,15,20,7};
	
	sol.buildTree(vPreorder, vInorder);
	
	return 0;
}