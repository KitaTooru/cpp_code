#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main() {
    int N;
    while (cin >> N) {
        vector<vector<int>> dist(N, vector<int>(N));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> dist[i][j];
            }
        }

        vector<int> minDist(N, INT_MAX);
        vector<bool> inMST(N, false);
        minDist[0] = 0;
        int totalWeight = 0;

        for (int i = 0; i < N; i++) {
            int u = -1;
            for (int j = 0; j < N; j++) {
                if (!inMST[j] && (u == -1 || minDist[j] < minDist[u])) {
                    u = j;
                }
            }

            if (minDist[u] == INT_MAX) {
                break;
            }

            inMST[u] = true;
            totalWeight += minDist[u];

            for (int v = 0; v < N; v++) {
                if (!inMST[v] && dist[u][v] < minDist[v]) {
                    minDist[v] = dist[u][v];
                }
            }
        }

        cout << totalWeight << endl;
    }
    return 0;
}
