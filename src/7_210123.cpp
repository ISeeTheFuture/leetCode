/*
  Best Time to Buy and Sell Stock II
https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/564/
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ret = 0;

        while(x >= 10 || x <= -10){
            ret += x % 10;
            if((long)ret * 10 > INT_MAX||(long)ret * 10 < -INT_MAX){
                return 0;
            }
            ret *= 10;
            x /= 10;
        }
         ret += x;

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