#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>

using namespace std;

int N = 0;
int ans = 0;
vector<int> col;

bool promising(int cur)
{
    for (int i = 1; i < cur; i++)
    {
        if (col[i] == col[cur]) return false;
        if (abs(col[i] - col[cur]) == abs(i - cur)) return false;
    }
    return true;
}

void backtracking(int row)
{
    if (row > N) {
        ans++; return;
    }

    for (int i = 1; i <= N; i++)
    {
        col[row] = i;
        if (promising(row)) backtracking(row + 1);
    }
}


int main()
{
    cin >> N;
    col.resize(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        col[1] = i;         // 1열에 i번째 위치
        backtracking(2);    // 2열부터 놓기 시작
    }

    cout << ans << endl;

    return 0;
}
