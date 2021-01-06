#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Car {
    int row, col, cost;
    bool dir; // 0:가로, 1:세로
};

int solution(vector<vector<int>> board) {
    int ans = 2e9;
    int N = board.size();

    // {up, right, down, left}
    int R[4] = { 1, 0, -1, 0 };
    int C[4] = { 0, 1, 0, -1 };

    queue<Car> q;
    q.push({ 0,0,0,0 });
    q.push({ 0,0,0,1 });

    Car car;
    int rr, cc, cost;
    bool dd;

    while (!q.empty())
    {
        car = q.front(); q.pop();

        if (car.row == N - 1 && car.col == N - 1) {
            ans = min(ans, car.cost); continue;
        }

        // 4곳으로 이동시킨다.
        for (int i = 0; i < 4; i++)
        {
            // 좌표 이동
            rr = car.row + R[i];
            cc = car.col + C[i];

            if (rr < 0 || rr >= N || cc < 0 || cc >= N || board[rr][cc] == 1)
                continue;

            // cost 계산과 방향 결정
            if ((i % 2 == 0 && !car.dir) || (i % 2 == 1 && car.dir)) {
                cost = car.cost + 100;
                dd = car.dir;
            }
            else {
                cost = car.cost + 600;
                dd = !car.dir;
            }

            // push
            if (board[rr][cc] == 0 || cost <= board[rr][cc]) {
                q.push({ rr, cc, cost, dd });
                board[rr][cc] = cost;
            }
        }
    }
    return ans;
}
