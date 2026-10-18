#include <iostream>
using namespace std;

int main() {
    const int N = 4;
    int cost[N][N] = {
        {0, 10, 6, 5},
        {10, 0, 999, 15},
        {6, 999, 0, 4},
        {5, 15, 4, 0}
    };

    bool visited[N] = {true, false, false, false};
    int edges = 0, total = 0;

    cout << "Selected roads:\n";

    while (edges < N - 1) {
        int minCost = 999, u = -1, v = -1;

        for (int i = 0; i < N; i++) {
            if (visited[i]) {
                for (int j = 0; j < N; j++) {
                    if (!visited[j] && cost[i][j] < minCost) {
                        minCost = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u == -1) {
            cout << "All cities cannot be connected\n";
            return 0;
        }

        cout << u + 1 << " - " << v + 1
             << " : " << minCost << endl;

        visited[v] = true;
        total += minCost;
        edges++;
    }

    cout << "Minimum cost: " << total << endl;
    return 0;
}
