/*
  Rotate Array
https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/646/

이번엔 새로운 vector 안만들고 풀이
vector에 내장된 함수가 많네... insert와 pop_back도 공부
다만 제출해보니 속도는 좀 느리네. insert() 함수가 리소스를 많이 먹는듯.
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        for (int i=0; i<k; ++i) {
            nums.insert(nums.begin(), nums.back()); // 맨 뒤의 원소(nums.back())를 맨 앞(nums.begin())에 삽입.
            nums.pop_back(); // 맨뒤의 원소를 삭제
        }
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