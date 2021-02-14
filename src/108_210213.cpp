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
 * 문제
 * 오름차순으로 정렬된 배열이 있다.
 * 일단 배열의 중앙값을 root로 한다.
 * 왼쪽이 작은값, 오른쪽이 큰값.
 * root의 자식 노드는 남은 배열의 중앙값이다.
 * 그 자식의 자식 노드는 남은 배열의 중앙값....
 * 모든 노드는 하위 노드들의 중앙값이다.
 * 
 * 문제 이해가 안되서 테스트 케이스 많이 돌려봄.
 * [-10,-3,0,5,9] => [0,-3,9,-10,null,5]
 * [-10,-3,0,5,9, 10] => [5,-3,10,-10,0,9]
 * [-10,0,5,9] => [5,0,9,-10]
 * [-10,-3,0,5,6,7,8,9] => [6,0,8,-3,5,7,9,-10]
 * [1,2,3,4,5,6,7,8,9] => [5,3,8,2,4,7,9,1,null,null,null,6]
 * [2,4,6,8,10,12,14,16,18] => [10,6,16,4,8,14,18,2,null,null,null,12]
 * 
 * 
 * 받은 배열을 반복해서 반으로 나눈다는 개념으로 생각해보자.
 * ㅇㅇ? 이제보니 이분탐색이랑 좀 비슷한거 같은데...?
 *
 */
class Solution {
public:
	TreeNode* subArrayToBST(vector<int>& nums, int left, int right) {
		// left 0, right 2 -> 중앙은 1, if(left) true, if(right) true
		// left 0, right 1 -> 중앙은 0, if(left) true, if(right) false
		// left 0, right 0 -> 중앙은 0, left right 둘 다 false
		
		// 하위 노드 돌입.
		int midIndex = (right + left)/2; // 새로운 중앙값.
		
		TreeNode* node = new TreeNode(nums[midIndex]);
		if(midIndex - left >= 1) {
			node->left = subArrayToBST(nums, left, midIndex - 1);
		}
		if(right - midIndex >= 1) {
			node->right = subArrayToBST(nums, midIndex + 1, right);
		}
	}

	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if(nums.size() == 0) { return NULL; }
		
		return subArrayToBST(nums, 0, nums.size() - 1);
    }
};

// 후기 : 이분탐색 맞나? 다시 공부해봐야할듯.

// Driver code 
int main() {
	Solution sol;
    vector<int> v = {3,9,20,NULL,NULL,15,7};
	
	sol.sortedArrayToBST(v);
	
	return 0;
}