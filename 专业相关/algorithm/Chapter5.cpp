#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#define INF 99999
using namespace std;
//1.Memoization example
int Fibonacci(int n, int memo[]) {
    if (n == 0 || n == 1) return n;

    if (memo[n] != -1) return memo[n];

    memo[n] = Fibonacci(n - 1, memo) + Fibonacci(n - 2, memo);
    return memo[n];
}
//2.assembly line scheduling problem
void assemblyLine(int n,int a[2][4],int t[2][4],int e[2],int x[2])
{
    int F1[n], F2[n];
    F1[0]= e[0]+a[0][0];
    F2[0]= e[1]+a[1][0];
    int L1[n],L2[n];
    int f,l;
    for(int j=1;j<n;j++)
    {
        if(F1[j-1]+a[0][j]<=F2[j-1]+t[1][j-1]+a[1][j])
        {
            F1[j]=F1[j-1]+a[0][j];
            L1[j]=1;
        }
        else
        {
            F1[j]=F2[j-1]+t[1][j-1]+a[0][j];
            L1[j]=2;
        }
        if(F2[j-1]+a[1][j]<=F1[j-1]+t[0][j-1]+a[1][j])
        {
            F2[j]=F2[j-1]+a[1][j];
            L2[j]=2;
        }
        else
        {
            F2[j]=F1[j-1]+t[0][j-1]+a[1][j];
            L2[j]=1;
        }
    }
    if(F1[n-1]+x[0]<= F2[n-1]+x[1])
    {
        f=F1[n-1]+x[0];
        l=1;
    }
    else
    {
        f=F2[n-1]+x[1];
        l=2;
    }
    cout << "Minimum time: " << f << endl;

    int path[10];
    path[n - 1] = l;
    for (int j = n - 1; j > 0; j--) {
        if (path[j] == 1) path[j - 1] = L1[j];
        else path[j - 1] = L2[j];
    }

    cout << "Path: ";
    for (int i = 0; i < n; i++) {
        cout << "Line " << path[i] << " Station " << i + 1 << " -> ";
    }
    cout << "End" << endl;
}
//3.LCS problem

string LCSProblem(const string& a, const string& b)
{
    int m = a.length();
    int n = b.length();
    vector<vector<int>> L(m + 1, vector<int>(n + 1));

    // 填表
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    // 回溯找字符串
    int i = m, j = n;
    string lcs;
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            lcs = a[i - 1] + lcs;
            i--;
            j--;
        }
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    return lcs;
}
//4.matrix chain multiplication problem
int matrixChainOrder(int p[], int n) {
    int m[101][101];
    for (int i = 1; i < n; i++)
        m[i][i] = 0;
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INF;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j]) m[i][j] = q;
            }
        }
    }
    return m[1][n-1];
}
//5.0-1 knapsack problem
int knapsack(int W, int wt[], int val[], int n) {
    int K[101][101] = {0};
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i==0 || w==0) K[i][w]=0;
            else if (wt[i-1] <= w)
                K[i][w] = (val[i-1] + K[i-1][w - wt[i-1]] > K[i-1][w]) ? val[i-1] + K[i-1][w - wt[i-1]] : K[i-1][w];
            else
                K[i][w] = K[i-1][w];
        }
    }
    return K[n][W];
}
//6.Floyd's Warshall algorithm
void floydWarshall(int dist[][4], int V) {
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
}
//7.optimal binary search tree
void optimalBST(float p[], float q[], int n) {
    float e[10][10];      // 期望代价
    float w[10][10];      // 概率权重
    int root[10][10];     // 最优根节点编号（下标从 1 开始）
    // 初始化 e[i][i] 和 w[i][i]
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            e[i][j] = 0;
            w[i][j] = 0;
            root[i][j] = 0;
        }
    }

    for (int i = 0; i <= n; i++) {
        e[i][i] = q[i];
        w[i][i] = q[i];
    }

    // 动态规划求解 e[i][j]
    for (int l = 1; l <= n; l++) { // 链长
        for (int i = 0; i <= n - l; i++) {
            int j = i + l;
            e[i][j] = INF;
            w[i][j] = w[i][j - 1] + p[j] + q[j];

            for (int r = i + 1; r <= j; r++) {
                float cost = e[i][r - 1] + e[r][j] + w[i][j];
                if (cost < e[i][j]) {
                    e[i][j] = cost;
                    root[i][j] = r;
                }
            }
        }
    }
    cout << "Minimum expected cost: " << e[0][4] << endl;
    cout << "\nExpected cost Table:\n";
    for (int i = 0; i <=4; i++) {
        for (int j = 0; j <= 4; j++) {
            cout << setw(3) << e[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "\nRoot Table:\n";
    for (int i = 0; i <=4; i++) {
        for (int j = 0; j <= 4; j++) {
            cout << setw(3) << root[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    //1
    int memo[10];
    for(int n=0;n<10;n++) memo[n]=-1;
    cout<<"The Fibonacci number of 5 is "<<Fibonacci(5,memo)<<endl;
    cout<<endl;
    //2
    int a[2][4] = { {4, 5, 3, 2}, {2, 10, 1, 4} };
    int t[2][4] = { { 7, 4,5,0}, { 9, 2,8,0} };
    int e[2] = {10, 12};
    int x[2] = {18, 7};
    assemblyLine(4,a,t,e,x);
    cout<<endl;
    //3
    string a3 = "bd";
    string b3 = "abcd";
    string result3 = LCSProblem(a3, b3);
    cout << "LCS Result: " << result3 << endl;
    cout<<endl;
    //4
    int p[] = {10, 30, 5, 60};
    cout << "Matrix Chain = " << matrixChainOrder(p, 4) << endl;
    cout<<endl;
    //5
    int wt[] = {2,3,4,5}, val[] = {1,2,5,6};
    cout << "Knapsack = " << knapsack(8, wt, val, 4) << endl;
    cout<<endl;
    //6
    int dist[4][4] = {
        {0, 5, -3, INF},
        {9, 0, INF, 3},
        {4, 5, 0, INF},
        {INF, INF, 1, 0}
    };
    floydWarshall(dist, 4);
    cout << "Floyd[0][3] = " << dist[0][3] << endl;
    cout<<endl;
    //7

    float p7[5] = {0,3, 3, 1, 1};     // p[1..n]
    float q7[5] = {2, 3, 1,1,1};  // q[0..n]
    optimalBST(p7, q7, 4);

    return 0;
}






