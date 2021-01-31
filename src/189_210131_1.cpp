/*
  Rotate Array
https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/646/
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int k_ = k%nums.size();
        vector<int>::iterator iter = nums.end() - k_;
        vector<int> newNums;

        for(; iter != nums.end(); iter++){
            newNums.push_back(*iter);
        }
        for(iter = nums.begin(); iter != nums.end() - k_; iter++){
            newNums.push_back(*iter);
        }
        nums = newNums;
    }
};

// Driver code 
int main() {
	Solution sol;
	vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;
    sol.rotate(nums, k);
	return 0;
}