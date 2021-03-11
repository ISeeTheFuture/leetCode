/*
  Longest Common Prefix
https://leetcode.com/problems/longest-common-prefix/
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
 * 문제 : 가장긴 prefix 구하기!
 */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) {
            return "";
        }

        string ret = strs[0];

        for(int i = 1; i < strs.size(); i++) {
            for(int j = 0; j <= min(ret.length(), strs[i].length()); j++) {
                if(j == strs[i].length()) {
                    ret = strs[i];
                    break; 
                }
                if(ret[j] != strs[i][j]) {
                    ret = ret.substr(0, j);
                    break;
                }
            }
        }
        return ret;
    }
};

// 후기 : 풀이가 굉장히 다양하다. 
// https://lessbutbetter.tistory.com/entry/LeetCodeEasy-14-Longest-Common-Prefix
// 위 블로그를 참고해서 다른 풀이법도 시도해보는게 좋을듯

// Driver code 
int main() {
	Solution sol;
	vector<string> strs = {"flower","flow","flight"};
    sol.longestCommonPrefix(strs);
	return 0;
}