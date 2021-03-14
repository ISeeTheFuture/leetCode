/*
  Search Insert Position
https://leetcode.com/problems/search-insert-position/
*/

#include <iostream>
#include <vector>

using namespace std;

/*
 * 문제 : 오름차순으로 정렬된 nums에 target이 들어갈 위치 index를 구하라.
 * 
 * 이번에는 이분탐색으로.
 */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;

		while(left <= right) {
			int mid = left + (right - left)/2;

			if(target == nums[mid]) {
				return mid;
			} else if(target > nums[mid]) { // mid 보다 크면 우측 배열 어딘가에 있으므로, focus를 우측으로
				left = mid + 1;
			} else if(target < nums[mid]) { // mid 보다 작으면 좌측 배열 어딘가에 있으므로, focus를 좌측으로
				right = mid - 1;
			}
		}

		return left; // 같을 경우 왼쪽 index를 취한다.
    }
};

// 후기 : 이분탐색이 왜이렇게 기억이 안나지

// Driver code 
int main() {
	Solution sol;
	vector<int> nums;
	int target;

    sol.searchInsert(nums, target);
	return 0;
}