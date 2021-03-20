/*
  Maximum Subarray
https://leetcode.com/problems/maximum-subarray/
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * 문제 : 부분배열의 최대합을 구하라.
 * 
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		int maxSum = nums[0];
		int tmpSum = nums[0];
		for(int i = 1; i < nums.size(); i++) { // 1부터 시작해야 size 1짜리 nums 무시하며, idx 0은 이미 위에서 변수 초기화로 넣어주었다.
			if(tmpSum < 0) { // 임시 합이 0 보다 작으면
				tmpSum = nums[i]; // 다음 임시합은 그냥 현재 원소 하나로 초기화. 음수는 더해봐야 무조건 손해.
			} else {
				tmpSum += nums[i]; // 양수라면 더해줘서 계산을 이어 나간다.
			}
			maxSum = max(maxSum, tmpSum); // maxSum과 임시로 구한 합을 비교해서 더 큰 값 선택.
		}
		return maxSum;
    }
};

// 후기 : 알고 있던 알고리즘이었다.
// https://www.youtube.com/watch?v=86CQq3pKSUw&t=45s&ab_channel=CSDojo

// Driver code 
int main() {
	Solution sol;
	vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    sol.maxSubArray(nums);
	return 0;
}