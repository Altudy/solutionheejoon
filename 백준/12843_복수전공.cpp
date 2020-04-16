#include <iostream>		  // 백준 12843
#include <vector>
using namespace std;

vector<int> node;			    // 컴공 수업들
vector<int> edge[2001];		// 각 수업 별 연결 되어 있는 선
int match[2001];			    // 어떤 노드랑 매치 됐는지
bool visited[2001];			  // 방문했는지


bool dfs(int x)
{
	for (int i = 0; i < edge[x].size(); i++)
	{
		int t = edge[x][i];

		if (visited[t]) continue;
		visited[t] = true;

		if (match[t] == 0 || dfs(match[t]))
		{
			match[t] = x;

			return true;
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	int a, b;
	char c;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> c;
		if (c == 'c')
			node.push_back(a);
	}

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	int count = 0;
	for (int i = 0; i < node.size(); i++)
	{
		fill(visited, visited + 2001, false);
		n -= dfs(node[i]);
	}

	cout << n;

	return 0;
}
