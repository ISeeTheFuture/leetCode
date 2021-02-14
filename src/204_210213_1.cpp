/*
  Count Primes
https://leetcode.com/explore/interview/card/top-interview-questions-easy/102/math/744/
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


/*
 * 문제 : 양수 중 소수인 수의 개수.
 * 
 * 0 -> 0 : 
 * 1 -> 0 :
 * 2 -> 1 : 2
 * 3 -> 2 : 2, 3
 * 4 -> 2 : 2, 3
 * 5 -> 3 : 2, 3, 5
 * 6 -> 3 : 2, 3, 5
 * 7 -> 4 : 2, 3, 5, 7
 * ...
 */
class Solution {
public:
    bool isPrime(int n, vector<int> &primes) {
		for(int i = 0; i < primes.size(); i++) {
			if(n%primes[i] == 0) { return false; };
		}
		return true;
	}
    
    int countPrimes(int n) {
        if(n <= 2) { return 0; }
		int ret = 1;
		
		vector<int> primes = {2};

		for(int i = 3; i <= n; i++){
			if(isPrime(i, primes)) {
				primes.push_back(i);
                if(i != n) {
                    ret++;
                }
			}
		}
		return ret;
    }
};

// 답은 맞는데, 시간초과 뜸. "에라토스테네스의 체"란 걸 학창시절 배웠다는데 기억이 안난다.


// Driver code 
int main() {
	Solution sol;
  	
	cout << "ans = " << sol.countPrimes(10);
	
	return 0;
}