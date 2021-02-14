/*
  Power of Three
https://leetcode.com/explore/interview/card/top-interview-questions-easy/102/math/745/
*/

#include <iostream>

using namespace std;


/*
 * 문제 : 3의 제곱수면 true, 아니면 false 리턴
 * 조건 : 순환,재귀 없이 풀 것.
 * while 문은 순환, 재귀가 아닌건가...
 * 
 */
class Solution {
public:
    bool isPowerOfThree(int n) {
		if(n < 1) { return false; }
		while(n > 1) {
			if(n%3 != 0) { return false; }
			n = n/3;
		}
		return true;
    }
};
// 후기 : 성능이 더 느리긴 하지만, "return fmod(log10(n) / log10(3), 1)==0;" 이게 더 의도에 맞는 답 같은데..


// Driver code 
int main() {
	Solution sol;
  	
	cout << "ans = " << sol.isPowerOfThree(10);
	
	return 0;
}