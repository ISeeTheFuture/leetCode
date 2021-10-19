#include <string>
#include <vector>
#include <set>

using namespace std;

/**
 * @param num, 기준 송전탑 번호
 * @param adjList, 전선 정보 인접 리스트
 * @param visited, 방문한 송전탑
 */
void dfs(int num, vector<set<int> > &adjList, set<int> &visited) {
    for(set<int>::iterator it = adjList[num].begin(); it != adjList[num].end(); it++) {
        if (visited.find(*it) == visited.end()) {
            visited.insert(*it);
            dfs(*it, adjList, visited);
        }
    }
}

/**
 * @param adjList, 전선 정보 인접 리스트
 * @param wire, 대상 송전탑
 */
int divide(vector<set<int>> &adjList, vector<int> &wire) {
        // 송전탑 전선 끊기
        adjList[wire[0]].erase(wire[1]);
        adjList[wire[1]].erase(wire[0]);

        // 끊은 전선 왼쪽 기준 dfs
        set<int> left;
        left.insert(wire[0]);
        dfs(wire[0], adjList, left); // 첫 left, right는 이미 방문한 것으로 간주해서 visited로 넣어준다.

        // 끊은 전선 오른쪽 기준 dfs
        set<int> right;
        right.insert(wire[1]);
        dfs(wire[1], adjList, right);

        // 송전탑 전선 복구
        adjList[wire[0]].insert(wire[1]);
        adjList[wire[1]].insert(wire[0]);

        return abs((int)left.size() - (int)right.size());
}

/**
 * @param n, 송전탑의 개수
 * @param wires, 전선 정보
 * @return 송전탑 개수의 차이의 최소값
 */
int solution(int n, vector<vector<int>> wires) {
    int answer = INT32_MAX;

    // 전선정보의 인접 리스트화.
    vector<set<int>> adjList(n+1);

    // 인접 리스트 초기화
    for(int i = 0; i < n - 1 ; i ++) {
        adjList[wires[i][0]].insert(wires[i][1]);
        adjList[wires[i][1]].insert(wires[i][0]);
    }

    for(int i = 0; i < n - 1 ; i ++) {
        answer = min(answer, divide(adjList, wires[i]));
    }

    return answer;
}