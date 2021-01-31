/*
  Best Time to Buy and Sell Stock II
https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/564/

다음 참고해서 개선
https://github.com/Minhee-Jeon/TIL/blob/master/algorithms/leetCode/%5BEasy%5D%20122.%20Best%20Time%20to%20Buy%20and%20Sell%20Stock%20II.md

제출하고 보니, 성능의 차이는 딱히 없다. 그래도 코드가 훨씬 심플해졌다.
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        std::vector<int>::size_type sz = prices.size();

        for (int i=0; i<sz-1; ++i) {
            if(prices[i] < prices[i+1]) {
                profit += prices[i+1] - prices[i];
            } 
        }
        return profit;    
    }
};

// Driver code 
int main() {
	Solution sol;
	vector<int> v = { 7, 6, 4, 1, 3, 5};

    cout << "ans=" << sol.maxProfit(v);
	return 0;
}