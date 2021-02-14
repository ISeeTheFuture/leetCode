/*
  Count Primes
https://leetcode.com/explore/interview/card/top-interview-questions-easy/102/math/744/
*/

#include <iostream>

using namespace std;


/*
 * 문제 : 양수 중 소수인 수의 개수.
 * 이번에는 에라토스테네스의 체를 사용해 풀 것.
 * 0 : 0
 * 1 : 1*1
 * 2 : 1*2, (2*1)
 * 3 : 1*3, (3*1)
 * 4 : 1*4, 2*2, (4*1)
 * 5 : 1*5, (5*1)
 * 6 : 1*6, 2*3, (3*2, 6*1)
 * 7 : 1*7, (7*1)
 * 8 : 1*8, 2*4, (4*2, 8*1)
 * 9 : 1*9, 3*3, (9*1)
 * 10 : 1*10, 2*5, (5*2, 10*1)
 * 11 : 1*11, (11*1)
 * 12 : 1*12, 2*6, 3*4, (4*3, 6*2, 12*1)
 * ...
 * 16 : 1*16, 2*8, 4*4, (8*2, 16*1)
 * ....
 * 24 : 1*24, 2*12, 3*8, 4*6, (6*4, 8*3, 12*2, 24*1)
 * 25 : 1*25, 5*5, (25*1)
 * 
 * 괄호친 부분을 보면, 중간 어딘가부터는 중복된다.
 * 16이나 25를 보면 i^2가 n을 넘어서면 그 다음부터는 중복되는 것을 알 수 있다.
 * 즉 => for문 돌릴떄 끝까지 돌릴 필요없이 i^2 까지만 해도 해당 수가 소수인지 아닌지 알 수 있다는 의미다.
 * 
 * 
 */
class Solution {
public:
    bool isPrime(int n) {
		for(int i = 2; i*i <= n; i++) {
			if(n%i == 0) { return false; };
		}
		return true;
	}
    
    int countPrimes(int n) {
        if(n <= 2) { return 0; }
		int ret = 1;

		for(int i = 3; i <= n; i++) {
			if(isPrime(i)) {
                if(i != n) { ret++; }
			}
		}
		return ret;
    }
};


// Driver code 
int main() {
	Solution sol;
  	
	cout << "ans = " << sol.countPrimes(10);
	
	return 0;
}