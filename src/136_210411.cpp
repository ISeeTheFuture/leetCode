/*
  Single Number
https://leetcode.com/problems/single-number/
*/

#include <vector>
#include <iostream>

using namespace std;

/*
 * 문제 : 벡터 배열에서 듀오가 아닌 솔로인 숫자를 찾아 리턴. 싱글 넘버는 단 하나다.
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() % 2 == 0) { // 배열이 짝수개면 싱글 넘버가 없다.
            return 0;
        }
        int ret = 0;
        for(int i = 0; i < nums.size(); i++) {
            ret ^= nums[i]; // 비트연산자 ^, XOR은 같은 숫자를 두번 연산하면 다시 본래 숫자로 돌아가는 특성이 있다. 따라서 마지막엔 싱글 넘버가 남는다.
        }
        return ret;
    }
};

// 후기 : 이건 좀 생각 못했네..

// Driver code 
int main() {
	Solution sol;
	vector<int> nums = {2,2,1};
    sol.singleNumber(nums);
	return 0;
}