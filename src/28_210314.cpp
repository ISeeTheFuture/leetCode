/*
  Implement strStr()
https://leetcode.com/problems/implement-strstr/
*/

#include <iostream>
#include <string>

using namespace std;

/*
 * 문제 : haystack에 needle이 있으면 index 리턴, 없으면 -1리턴, needle이 비어있다면 0 리턴
 * 
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
		int ret = 0;
		if(needle == "") {
			return ret;
		} else if(haystack.size() < needle.size()) {
            return -1;
        }

		string::iterator iterHaystack = haystack.begin();
		string::iterator iterNeedle = needle.begin();

		while(iterHaystack != haystack.end()) {
			if(*iterHaystack == *iterNeedle) {
				string::iterator iterTmp = iterHaystack;
				while(iterNeedle != needle.end() && iterTmp != haystack.end()) {
					if(*iterNeedle != *iterTmp) {
						break;
					}
					iterNeedle++;
					iterTmp++;
				}
				if(iterNeedle == needle.end()) {
					return ret;
				}
			}
			iterNeedle = needle.begin();
			iterHaystack++;
			ret++;
		}

		ret = -1;
		return ret;
    }
};

// 후기 : 빡친다. 기껏 풀어놨더니 모범 풀이가 find() 함수 쓰는거다. 성능까지 압도적이라 기분 묘하네.

// Driver code 
int main() {
	Solution sol;
	string haystack = "helloo";
	string needle = "ll";

    sol.strStr(haystack, needle);
	return 0;
}