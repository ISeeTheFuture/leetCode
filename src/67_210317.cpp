/*
  Add Binary
https://leetcode.com/problems/add-binary/
*/

#include <iostream>
#include <string>

using namespace std;

/*
 * 문제 : 이진 계산기
 * 
 * 예전에 풀었던 것 같은데...
 * 십진으로 바꾸는건 비효율적일테니, 이진 상태에서 계산해보자.
 */

class Solution {
public:
    string addBinary(string a, string b) {
		string newA;
		string newB;

		// 편의상 더 긴걸 a로 하자. 이렇게 안하면 머리가 복잡해지고 아래 코드도 겉잡을 수 없이 복잡해질듯.
        if(a.size() >= b.size()) {
			newA = a;
			newB = b;
		} else {
			newA = b;
			newB = a;
		}
		int aSize = newA.size();
		int bSize = newB.size();
		
		for(int i = bSize-1; i >= 0; i--){
			if(newB[i]=='1') {
				for(int j = aSize-1; j >= 0; j--) {
					if(newA[j]=='0') { // 해당 자리가 0이라 바로 1 더하고 다음 자릿수 계산을 할 수 있는 경우
						newA[j] = '1';
						break;
					}
					if(j == 0 && newA[j] == '1') { // 끝까지 갔는데 마지막도 1일 경우, 한자리 더 올려준다.
						newA[j] = '0'; // 현재 자리는 0으로 치환
						newA.insert(0, "1"); // 맨 앞에 1 추가
						aSize++; // 자릿수가 올라가니 사이즈도 커진다.
						break;
					}
					newA[j] = '0'; // 더할 수 없는 경우 해당 자리를 0으로 바꾸로 다음 자릿수 계산. 한자리 올린거라 보면 된다.
				}
			}
			aSize--;
		}
		return newA;
    }
};

// 후기 : 이렇게 푸는게 맞다니 어이가 좀 없네. 효율도 괜찮다. 풀면서 아 이건 아니다 생각했는데...

// Driver code 
int main() {
	Solution sol;
	string a = "11";
	string b = "1";

    sol.addBinary(a, b);
	return 0;
}