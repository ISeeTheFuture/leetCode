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
 */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ret = 0;
		if(nums[ret] >= target) {
			return ret;
		}
		ret++;

		for(; ret < nums.size(); ret++) {
			if(target <= nums[ret]&&target > nums[ret-1]) {
				break;
			}
		}
		return ret;
    }
};

// 후기 : 이제 이분탐색(이진탐색)으로 풀어보자. 최고 성능 답안은 오히려 아래 처럼 함수 활용이므로 참고할 것 없을듯. 표준도 아닌듯.
// int searchInsert(vector<int>& nums, int target) {
// 	int idx=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
// 	return idx;
// }

// Driver code 
int main() {
	Solution sol;
	vector<int> nums;
	int target;

    sol.searchInsert(nums, target);
	return 0;
}