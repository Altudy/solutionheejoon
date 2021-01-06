#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> edge(200001);
vector<int> need(200001);
vector<int> save(200001);
vector<bool> visited(200001, false);

void bfs()
{
    queue<int> q;
    q.push(0);

    if (need[0]) return;

    int num;

    while (!q.empty())
    {
        num = q.front(); q.pop();

        if (visited[num]) continue;
        visited[0] = true;

        if (!visited[need[num]]) {
            save[need[num]] = num;
            continue;
        }

        visited[num] = true;

        if (save[num]) q.push(save[num]);

        for (auto n : edge[num]) q.push(n);
    }
    
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    for (auto p : path) {
        edge[p[0]].emplace_back(p[1]);
        edge[p[1]].emplace_back(p[0]);
    }

    for (auto o : order)
        need[o[1]] = o[0];

    bfs();

    for (int i = 0; i < n; i++)
        if (!visited[i]) return false;

    return true;
}
