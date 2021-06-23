// 문제 : https://www.synapsoft.co.kr/recruit-developer

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define SN3OK 1
#define ERROR_YOU_FAIL 0

class Solution {

enum Direction {
    DIRECTION_RIGHT = 0,
    DIRECTION_DOWN = 1
};

private:
    void checkRoom(const int I, const int J, const int N, const int S, const int *arr, vector<string>& routes_list, string temp_route, int temp_sum,  Direction start_direction, Direction cur_direction) {
        if(temp_sum == S) {
            routes_list.push_back(temp_route);
            return;
        } else if(temp_sum > S || I >= N || J >= N) {
            return;
        }
        
        int room_number = *(arr+(I+N*J));
        temp_sum += room_number;
        if(start_direction == cur_direction) { // 방향이 바뀌지 않은 경우
            string temp_route1 = temp_route + to_string(room_number) + " ";
            string temp_route2 = temp_route + to_string(room_number) + " ";
            if(start_direction == DIRECTION_DOWN) {
                checkRoom(I+1, J, N, S, arr, routes_list, temp_route1, temp_sum, DIRECTION_DOWN, DIRECTION_DOWN);
                checkRoom(I, J+1, N, S, arr, routes_list, temp_route2, temp_sum, DIRECTION_DOWN, DIRECTION_RIGHT);
            } else {
                checkRoom(I, J+1, N, S, arr, routes_list, temp_route1, temp_sum, DIRECTION_RIGHT, DIRECTION_RIGHT);
                checkRoom(I+1, J, N, S, arr, routes_list, temp_route2, temp_sum, DIRECTION_RIGHT, DIRECTION_DOWN);
            }
        } else { // 방향이 바뀐 경우
            string temp_route1 = temp_route + to_string(room_number) + " ";
            if(start_direction == DIRECTION_DOWN) {
                checkRoom(I, J+1, N, S, arr, routes_list, temp_route1, temp_sum, DIRECTION_DOWN, DIRECTION_RIGHT);
            } else {
                checkRoom(I+1, J, N, S, arr, routes_list, temp_route1, temp_sum, DIRECTION_RIGHT, DIRECTION_DOWN);
            }
        }
    }
    void printRoute(vector<string> routes_list) {
        for(auto it = routes_list.begin(); it != routes_list.end(); it++) {
            cout << *it << endl;
        }
    }

public:

    int findRoute(const int N, const int S, const int* arr) {
        vector<string> routes_list;
        
        for(int i = 0; i < N; i++) { // vert
            for(int j = 0; j < N; j++) { // horizon
                string right_str = "";
                checkRoom(i, j, N, S, arr, routes_list, right_str, 0, DIRECTION_RIGHT, DIRECTION_RIGHT);
                string down_str = "";
                checkRoom(i, j, N, S, arr, routes_list, down_str, 0, DIRECTION_DOWN, DIRECTION_DOWN);
            }
        }
        // 혹시나 중복 제거가 필요할까 싶었지만, 필요 없었다.
        // sort(routes_list.begin(), routes_list.end());
        // routes_list.erase(unique(routes_list.begin(), routes_list.end()), routes_list.end());

        if(!routes_list.empty()) {
            printRoute(routes_list);
        }
        return SN3OK;
    }

};

// Driver code 
int main() {
    Solution sol;

    const int N = 4; // N X N
    const int S = 11; // 경로의 총 합 한계
    const int arr[N][N] = {{2,4,2,6}, {6,6,4,2}, {2,2,1,2}, {4,4,5,3}};
    const int* pArr = *arr;

    int ret = sol.findRoute(N, S, pArr);
    if(ret != SN3OK) {
        return ERROR_YOU_FAIL;
    }

    return SN3OK;
}