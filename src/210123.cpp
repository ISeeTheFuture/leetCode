/*
  Best Time to Buy and Sell Stock II
https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/564/
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int stock = -1;
        int ret = 0;

        for(int i = 0; i < prices.size(); i++) {
            if(stock == -1 && i + 1 < prices.size() && prices[i]<prices[i+1]) {
                stock = prices[i];
            } else if(stock != -1 && stock<prices[i]){
                ret += prices[i] - stock;
                stock = -1;
                i--;
            }
        }
    return ret;
    }
};

// Driver code 
int main() {
	Solution sol;
	vector<int> v = { 7, 6, 4, 1, 3, 5};

    cout << "ans=" << sol.maxProfit(v);
	return 0;
}