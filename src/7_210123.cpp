/*
  Reverse Integer
https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/880/
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ret = 0;
        while(x >= 10 || x <= -10){
            ret += x % 10; // x의 1의 자리를 ret에 더해줌.
            if((long)ret * 10 > INT_MAX||(long)ret * 10 < -INT_MAX) { return 0; } // 만약 ret가 integer 범위를 초과하면 0 리턴
            ret *= 10; // ret의 자리를 하나 올려줌.
            x /= 10; // x의 자리를 하나 내려줌.
        }
        ret += x; // 마지막 남은 한 자리 추가
        
        return ret;
    }
};

// Driver code 
int main() {
	Solution sol;
	int v = 1534236469;
    cout << "ans=" << sol.reverse(v);
	return 0;
}