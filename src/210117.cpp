/*
  Remove Duplicates from Sorted Array
https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/727/
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		const int numsSize = nums.size();
		int ret = 1;

		if (numsSize < 2) return numsSize;

		for (int i = 1; i < numsSize; i++) {
			if (nums[i] != nums[i - 1]) {
				nums[ret++] = nums[i];
			}
		}

		return ret;
	}
};

// Driver code 
int main() {
	Solution sol;
	
	vector<int> v = { 0,0,0,0,0,0,0,4,4,7,7,7,7,9 };

	cout << "ans=" << sol.removeDuplicates(v);
	return 0;
}