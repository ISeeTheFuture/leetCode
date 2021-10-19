#include <string>
#include <vector>
#include <utility>
#include <set>
#include <algorithm>

using namespace std;

const int NO_NUMBER = 1001;
const int OK = 0;
const int ERR = 1;

/*
* 정수면 0, 실수면 1을 리턴
*/
int isInteger(const double number) {
    if(number/1.00 == (int)number) {
        return OK;
    }
    return ERR;
}


/*
* 교점을 구하는 함수
*/
void transpose(pair<int, int> *transposition, const vector<int> &line_1, const vector<int> &line_2) {
    if((line_1[0]*line_2[1] - line_1[1]*line_2[0]) == 0) {
        return;
    }
    const double X = (line_1[1]*line_2[2] - line_1[2]*line_2[1]) / (line_1[0]*line_2[1] - line_1[1]*line_2[0]);
    const double Y = (line_1[2]*line_2[0] - line_1[0]*line_2[2]) / (line_1[0]*line_2[1] - line_1[1]*line_2[0]);

    if(isInteger(X) != OK || isInteger(Y) != OK) {
        return;
    }
    transposition->first = X;
    transposition->second = Y;
}

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;

    // 모든 교점을 구한다. set에 넣어 중복은 제거
    set<pair<int,int>> transposition_set;
    for(int i = 0; i < line.size()-1; i++) {
        for(int j = i + 1; j < line.size(); j++) {
            pair<int, int> transposition = {NO_NUMBER, NO_NUMBER}; // 조건상 1001은 있을 수 없으므로.
            transpose(&transposition, line[i], line[j]);
            if(transposition.first != NO_NUMBER && transposition.second != NO_NUMBER) {
                transposition_set.insert(transposition);
            }
        }
    }

    int top = -NO_NUMBER;
    int bottom = NO_NUMBER;
    int left = NO_NUMBER;
    int right = -NO_NUMBER;
    // 교점의 최대 절대값을 찾아 그릴 영역을 구한다.
    for(set<pair<int, int>>::iterator iter = transposition_set.begin(); iter != transposition_set.end(); iter++) {
        top = max(top, iter->second);
        bottom = min(bottom, iter->second);
        left = min(left, iter->first);
        right = max(right, iter->first);
    }

    // 그린다.
    for(int y = top; y >= bottom; y--) {
        string answer_line = "";
        for(int x = left; x <= right; x++) {
            // 바깥쪽 좌표가 맞는 것중 리스트에 있는 좌표라면 "*"
            if (x == left || x == right || y == top || y == bottom) {
                pair<int, int> tmp_pair = {x, y};
                if(transposition_set.find(tmp_pair) != transposition_set.end()) {
                    answer_line.append("*");
                    continue;
                }
            }
            answer_line.append(".");
        }
        answer.push_back(answer_line);
    }

    return answer;
}