#include <iostream>
using namespace std;

int adj[15][15];  // 邻接矩阵
int visited[15];    // 用于 DFS 和 BFS

// 1. DFS - 深度优先搜索（递归）
void DFS(int v, int V) {
    visited[v] = 1;
    cout << char('a' + v) << " ";
    for (int u = 0; u < V; u++) {
        if (adj[v][u] && !visited[u]) {
            DFS(u, V);
        }
    }
}

// 2. BFS - 广度优先搜索（队列用数组实现）
void BFS(int start, int V) {
    int queue[15];
    int front = 0, rear = 0;

    for (int i = 0; i < V; i++) visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int v = queue[front++];
        cout << char('a' + v) << " ";
        for (int u = 0; u < V; u++) {
            if (adj[v][u] && !visited[u]) {
                visited[u] = 1;
                queue[rear++] = u;
            }
        }
    }
}

// 3. Prim's Algorithm - 最小生成树（邻接矩阵）
int prim(int V) {
    int key[15];
    bool inMST[15];
    for (int i = 0; i < V; i++) {
        key[i] = 100;
        inMST[i] = false;
    }
    key[0] = 0;
    int totalWeight = 0;

    for (int count = 0; count < V; count++) {
        int u = -1, minKey = 100;
        for (int v = 0; v < V; v++) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        inMST[u] = true;
        totalWeight += key[u];

        for (int v = 0; v < V; v++) {
            if (adj[u][v] && !inMST[v] && adj[u][v] < key[v]) {
                key[v] = adj[u][v];
            }
        }
    }
    return totalWeight;
}

// 4. Bellman-Ford - 单源最短路径
void bellmanFord(int V, int E, int edges[][3], int src) {
    int dist[15];
    for (int i = 0; i < V; i++) dist[i] = 100;
    dist[src] = 0;

    for (int i = 1; i < V; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            if (dist[u] != 100 && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    cout << "Bellman-Ford distances from " << char('a' + src) << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "To " << char('a' + i) << ": ";
        if (dist[i] == 100) cout << "INF\n";
        else cout << dist[i] << endl;
    }
}

int main() {
    int V = 7;

    // 构造邻接矩阵（无向图）
    int raw[15][15] = {
        {0, 4, 2, 9, 0, 0, 1},
        {4, 0, 0, 0, 1, 0, 0},
        {2, 0, 0, 0, 0, 8, 0},
        {9, 0, 0, 0, 3, 6, 1},
        {0, 1, 0, 3, 0, 0, 8},
        {0, 0, 8, 6, 0, 0, 5},
        {1, 0, 0, 1, 8, 5, 0}
    };
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = raw[i][j];

    // DFS
    for (int i = 0; i < V; i++) visited[i] = 0;
    cout << "DFS from a: ";
    DFS(0, V); cout << "\n";

    // BFS
    cout << "BFS from a: ";
    BFS(0, V); cout << "\n";

    // Prim
    int mstWeight = prim(V);
    cout << "Prim's MST total weight: " << mstWeight << "\n";

    // Bellman-Ford
    int E = 11;
    int edges[11][3] = {
        {0, 1, 4}, {0, 2, 2}, {0, 3, 9}, {0, 6, 1},
        {1, 4, 1}, {2, 5, 8}, {3, 4, 3}, {3, 5, 6},
        {3, 6, 1}, {4, 6, 8}, {5, 6, 5}
    };
    bellmanFord(V, E, edges, 0);

    return 0;
}


