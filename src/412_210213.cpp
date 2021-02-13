/*
  Fizz Buzz
https://leetcode.com/explore/interview/card/top-interview-questions-easy/102/math/743/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


/*
 * 문제 : 3과 5의 배수면 FizzBuzz를 리턴, 5의 배수면 Buzz를 리턴, 3의 배수면 Fizz를 리턴.
 * 
 */
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ret;
		if(n==0) {return ret;}
        for(int i = 1; i <= n; i++) {
			if(i%15==0){ ret.push_back("FizzBuzz"); }
			else if(i%5==0){ ret.push_back("Buzz"); }
			else if(i%3==0){ ret.push_back("Fizz"); }
			else { ret.push_back(to_string(i)); }
        }
		return ret;
    }
};

// Driver code 
int main() {
	Solution sol;
  	
	sol.fizzBuzz(15);
	
	return 0;
}