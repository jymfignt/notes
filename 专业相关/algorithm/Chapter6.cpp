#include <iostream>
#include <string>
using namespace std;

//1.activity selection problem
void activitySelection(int start[], int ending[], int n)
{
    int last = 0;
    cout<<"\nThe selected:\n";
    cout<<1<<" ";
    for (int i = 0; i < n; i++) {
        if (start[i] >= ending[last]) {
            last = i;
            cout<<i+1<<" ";
        }
    }
    cout<<endl;
    //return counts;
}
//2.knapsack problem - greedy
void fractionalKnapsack(int p[],int w[],int c,int n)
{
    float ratio[100]; // 单位价值
    for (int i = 0; i < n; i++) {
        ratio[i] = (float)p[i] / w[i];
    }

    // 冒泡排序：按 ratio 降序，并同步调整 p 和 w
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ratio[j] < ratio[j + 1]) {
                // 交换 ratio
                swap(ratio[j],ratio[j+1]);
                // 交换 p
                swap(p[j],p[j+1]);
                // 交换 w
               swap(w[j],w[j+1]);
            }
        }
    }

    float x[n]={0};
    int totalWeight = 0;
    float totalValue = 0;

    for(int i=0;i<n;i++)
    {
       if (totalWeight + w[i] <= c) {
            x[i] = 1;
            totalWeight += w[i];
            totalValue += p[i];
        } else {
            x[i] = (float)(c - totalWeight) / w[i];
            totalValue += x[i] * p[i];
            totalWeight = c;
            break;
        }
    }
    cout << "Selected fractions:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << "(after sorting): " << x[i] << endl;
    }
    cout << "Total value: " << totalValue << endl;
}
//3.Huffman coding
void Huffman(string a)
{
    int n=a.length();
    char letters[15]={0};  //记录不同字母
    int counts=0;
    int freq[15]={0};
    int left[15], right[15], parent[15];
    char code[15][15]; // 编码结果
    char path[15];      // 临时路径

    for(int i=0;i<n;i++)
    {
        char ch=a[i];
        int found=-1;

        for(int j=0;j<counts;j++)
        {
            if(letters[j]==ch)
            {
                found=j;
                break;
            }
        }
        if(found==-1)
        {
            letters[counts] = ch;
            freq[counts] = 1;
            counts++;
        }
        else
            freq[found]++;
    }

    for (int i = 0; i < counts - 1; i++) {
        for (int j = 0; j < counts - i - 1; j++) {
            if (freq[j] > freq[j + 1]) {
                // 交换频率
                swap(freq[j],freq[j+1]);
                // 同步交换字母
                swap(letters[j],letters[j+1]);
            }
        }
    }

    // ---------------- 3. 初始化数组 ----------------
    for (int i = 0; i < 15; i++) {
        left[i] = -1;
        right[i] = -1;
        parent[i] = -1;
    }

    int size = counts;

    // ---------------- 4. 构造 Huffman 树 ----------------
for (int i = 0; i < counts - 1; i++) {
        int min1 = -1, min2 = -1;
        for (int j = 0; j < size; j++) {
            if (parent[j] == -1) {
                if (min1 == -1 || freq[j] < freq[min1]) {
                    min2 = min1;
                    min1 = j;
                } else if (min2 == -1 || freq[j] < freq[min2]) {
                    min2 = j;
                }
            }
        }
        freq[size] = freq[min1] + freq[min2];
        left[size] = min1;
        right[size] = min2;
        parent[min1] = size;
        parent[min2] = size;
        size++;
    }

    int root = size - 1;

    // ---------- 5. 从 root 开始生成编码 ----------
    for (int i = 0; i < counts; i++) {
        int cur = i;
        int pathIndex = 0;
        char temp[15];
        while (parent[cur] != -1) {
            int p = parent[cur];
            if (left[p] == cur)
                temp[pathIndex++] = '0';
            else
                temp[pathIndex++] = '1';
            cur = p;
        }

        // 反转路径
        for (int j = 0; j < pathIndex; j++) {
            code[i][j] = temp[pathIndex - j - 1];
        }
        code[i][pathIndex] = '\0';
    }

    // ---------- 6. 输出 ----------
    cout << "Huffman Codes:\n";
    for (int i = counts-1; i >= 0; i--) {
        cout << letters[i] << ": " << code[i] << endl;
    }
}
//4.Dijkstra's algorithm
void dijkstra(int graph[15][15], int V, int src, int dist[]) {
    bool visited[15];
    const int INF = 99999;  // ✅ 用更大的数表示“不可达”

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = -1, minDist = INF;
        for (int v = 0; v < V; v++) {
            if (!visited[v] && dist[v] < minDist) {
                minDist = dist[v];
                u = v;
            }
        }

        if (u == -1) break; // 所有剩余节点都不可达

        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
}
//Kruskal's Algorithm
void kruskal(int u[], int v[], int w[], int V, int E) {
    int parent[15];
    // 初始化并查集
    for (int i = 0; i < V; i++)
        parent[i] = i;

    // 按权重对边排序（冒泡排序）
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (w[j] > w[j + 1]) {
                // 交换边的三个属性
                int temp;
                swap(w[j], w[j + 1]);
                swap(u[j], u[j + 1]);
                swap(v[j], v[j + 1]);
            }
        }
    }

    int totalWeight = 0;
    cout << "Kruskal's MST edges:\n";
    for (int i = 0; i < E; i++) {
       int x = u[i];
        int y = v[i];

        // 并查集（内联写法）
        while (x != parent[x]) x = parent[x];
        while (y != parent[y]) y = parent[y];

        if (x != y) {
            parent[x] = y;
            cout << "Edge " << char('a' + u[i]) << " - " << char('a' + v[i])
                 << ", weight = " << w[i] << endl;
            totalWeight += w[i];
        }
    }
    cout << "Total MST weight: " << totalWeight << endl;
}

int main()
{
    //1
    int s[11] = {1, 3, 0, 5, 3, 5,6,8,8,2,12};
    int f[11] = { 4,5, 6, 7, 9, 9,10,11,12,14,16};
    activitySelection(s, f, 11);
    cout<<endl;
    //2
    int p[3]={330,225,500};
    int w[3]={30,25,40};
    fractionalKnapsack(p,w,55,3);
    cout<<endl;
    //3
    string a ="BCAADDDCCACACAC";
    Huffman(a);
    cout<<endl;
    //4
    int V1 = 7;
    int graph[15][15] = {
        {0, 4, 2, 9, 0, 0, 0},
        {4, 0, 0, 0, 1, 0, 0},
        {2, 0, 0, 0, 0, 8, 0},
        {9, 0, 0, 0, 3, 6, 1},
        {0, 1, 0, 3, 0, 0, 8},
        {0, 0, 8, 6, 0, 0, 5},
        {0, 0, 0, 1, 8, 5, 0}
    };
    int dist[15];
    dijkstra(graph, V1, 0, dist);
    cout << "Dijkstra shortest distances from node 0:\n";
    for (int i = 0; i < V1; i++) {
        cout << "To " << i << ": " << dist[i] << endl;
    }
    cout<<endl;
    //5
    int u[15] = {0, 0, 0, 0, 1, 2, 3, 3, 3, 4, 5};
    int v[15] = {1, 2, 3, 6, 4, 5, 4, 5, 6, 6, 6};
    int w5[15] = {4, 2, 9, 1, 1, 8, 3, 6, 1, 8, 5};

    kruskal(u, v, w5, 7, 11);

    return 0;
}








