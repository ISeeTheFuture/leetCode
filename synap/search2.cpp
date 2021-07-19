#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>


struct edge {
    int start_node;
    int end_node;
    int weight;
    
    edge(int start_node, int end_node, int weight) {
        this->start_node = start_node;
        this->end_node = end_node;
        this->weight = weight;
    }

    bool operator < (edge &node) {
        return this->weight < node.weight;
    }
};

class testSearch {
public:
    // dfs
    void dfs(int idx, std::vector<int> map[], bool visited[]) {
        visited[idx] = true;
        printf("%d ", idx);

        for(int i = 0; i < map[idx].size(); i++) {
            int next_idx = map[idx][i];
            if(!visited[next_idx]) {
                dfs(next_idx, map, visited);
            }
        }
    }

    // bfs
    void bfs(int idx, std::vector<int> map[], bool visited[]) {
        std::queue<int> q;

        q.push(idx);
        visited[idx] = true;

        while(!q.empty()) {
            int next_idx = q.front();
            q.pop(); // 방문.
            printf("%d ", next_idx);

            for(int i = 0; i < map[next_idx].size(); i++) {
                if(!visited[map[next_idx][i]]) {
                    q.push(map[next_idx][i]);
                    visited[map[next_idx][i]] = true;
                }
            }
        }
    }

    // kruskal
private:
    int find_kruskal(int* mst, int node) {
        if (mst[node]  == node) {
            return node;
        } else {
            return find_kruskal(mst, mst[node]);
        }
    }
    void union_kruskal(int* mst, int node_x, int node_y) {
        node_x = find_kruskal(mst, node_x);
        node_y = find_kruskal(mst, node_y);

        if(node_x > node_y) {
            mst[node_x] = node_y;
        } else {
            mst[node_y] = node_x;
        }
    }
    bool hasSameParent(int* mst, int node_x, int node_y) {
        node_x = find_kruskal(mst, node_x);
        node_y = find_kruskal(mst, node_y);

        if(node_x == node_y) {
            return true;
        } else {
            return false;
        }
    }
public:
    void print_mst(int mst[], const int NODE_COUNT) {
        for(int i = 0; i < NODE_COUNT; i++) {
            printf("node x = %d, node y = %d \n", i, mst[i]);
        }
        printf("\n");
    }
    void kruskal(std::vector<edge>* graph, const int NODE_COUNT) {
        int mst[NODE_COUNT];
        for(int i = 0; i < NODE_COUNT; i++) {
            mst[i] = i;
        }
        print_mst(mst, NODE_COUNT);
        std::sort(graph->begin(), graph->end());

        for(int i = 0; i < graph->size(); i++) {
            if(!hasSameParent(mst, graph->at(i).start_node, graph->at(i).end_node)) {
                union_kruskal(mst, graph->at(i).start_node, graph->at(i).end_node);
            }
        }
        printf("asdasdasd %d asdasd", mst[2]);
        print_mst(mst, NODE_COUNT);
    }
};


// Driver code 
int main() {
    testSearch ts;

    const int N = 5;
    std::vector<int> map[N];
    bool visited[N+1];

    map[0].push_back(1);
    map[1].push_back(0);

    map[0].push_back(2);
    map[2].push_back(0);

    map[0].push_back(1);
    map[1].push_back(0);

    map[0].push_back(3);
    map[3].push_back(0);

    map[1].push_back(3);
    map[3].push_back(1);

    map[2].push_back(3);
    map[3].push_back(2);

    printf("-----------DFS----------\n");
    std::fill(visited, visited+N+1, false);
    ts.dfs(0, map,visited);
    printf("\n");

    printf("-----------BFS----------\n");
    std::fill(visited, visited+N+1, false);
    ts.bfs(0, map,visited);
    printf("\n");


    std::vector<edge> graph;
    graph.push_back(edge(0,1,6));
    graph.push_back(edge(0,2,9));
    graph.push_back(edge(0,3,2));
    graph.push_back(edge(0,4,32));
    graph.push_back(edge(1,3,11));
    graph.push_back(edge(1,4,14));
    graph.push_back(edge(2,3,7));
    graph.push_back(edge(2,5,20));
    graph.push_back(edge(2,6,50));
    graph.push_back(edge(3,4,17));
    graph.push_back(edge(3,5,16));
    graph.push_back(edge(4,5,44));
    graph.push_back(edge(4,6,29));
    graph.push_back(edge(5,6,34));

    printf("-----------Kruskal----------\n");
    
    const int NODE_COUNT = 7;
    // int* mst = (int*)malloc(sizeof(int)*NODE_COUNT);
    ts.kruskal(&graph, NODE_COUNT);
    // ts.print_mst(mst, NODE_COUNT);
    // free(mst);
    printf("\n");

    return 0;
}
