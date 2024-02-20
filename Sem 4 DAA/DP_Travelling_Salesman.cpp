#include <iostream>
using namespace std;

const int MAX = 1000000;
int n;
int dist[11][11];
int memo[11][1 << 12];

int TSP(int i, int mask) {
    if (mask == ((1 << i) | 1))
        return dist[1][i];
    // memoization
    if (memo[i][mask] != 0)
        return memo[i][mask];

    int res = MAX; 
    for (int j = 1; j <= n; j++)
        if ((mask & (1 << j)) && j != i && j != 1)
            res = min(res, TSP(j, mask & (~(1 << i))) + dist[j][i]);
    return memo[i][mask] = res;
}

int main() {
    cout << "Enter the number of nodes: ";
    cin >> n;

    if (n < 2 || n > 10) {
        cout << "Invalid number of nodes. Please enter a value between 2 and 10." << endl;
        return 1;
    }

    cout << "Enter the distance matrix:" << endl;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> dist[i][j];

    int ans = MAX;
    for (int i = 1; i <= n; i++)
        ans = min(ans, TSP(i, (1 << (n + 1)) - 1) + dist[i][1]);

    cout << "The cost of the most efficient tour = " << ans << endl;

    return 0;
}
