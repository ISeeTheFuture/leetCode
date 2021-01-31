/*
  Rotate Array
https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/646/

이번엔 메모리 덜쓰고....? vector를 공부해봐야겠다.
이렇게 제출해도 딱히 성능 향상 없던데 왜지? 분명 두 배는 빨라져야 하는데;
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        vector<int>::iterator iter;
        vector<int> newNums(nums.end() - k, nums.end());

        for(iter = nums.begin(); iter != nums.end() - k; iter++){
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