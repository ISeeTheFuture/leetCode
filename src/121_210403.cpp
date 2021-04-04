/*
  Best Time to Buy and Sell Stock
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/

#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

/*
 * 문제 : 주식 사고 팔아서 낼 수 있는 최대이익을 구하라! 단, 기회는 한 번.
 * 
 * 7, 1, 5, 3, 6, 4
 * 면,
 * 1원 -> 6원에 판다 : 5원
 * 
 * 
 * 1,3,1,10,1,3,2,20
 * 1에 사서 20에 파는게 최고인데....
 * 
 * 일일히 하나하나 해보는 수밖에 없는듯.
 * 단, 뒤돌아볼 필요 없다는 것에 주목.
 * 
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
		int minValue = INT_MAX;
        
        for(int i = 0; i < prices.size(); i++) {
			if(prices[i] < minValue) { // 현재 가격이 최소값이면, 구입하면서 최소값으로 설정
				minValue = prices[i];
			} else if(prices[i] >= minValue){ // 최소값이 아니라면,
				int profit = prices[i] - minValue; // 당장 이익 산출.
				ret = max(ret, profit); // 지금 파는 것이 더 이익인지 판단.
			}
        }
		return ret;
    }
};

// Driver code 
int main() {
	Solution sol;
	vector<int> v = {7, 6, 4, 1, 3, 5};

    cout << "ans=" << sol.maxProfit(v);
	return 0;
}