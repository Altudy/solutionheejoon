#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

int ans = 51;
unordered_map<string, bool> visit;
unordered_map<string, vector<string>> graph;

void dfs(string& now, string& target, int depth)
{
    if (visit[now]) return;
    if (now == target) {
        ans = min(ans, depth);
        return;
    }

    vector<string> candidates = graph[now];
    visit[now] = true;
    for (auto candi : candidates)
        dfs(candi, target, depth + 1);
    visit[now] = false;
}

int solution(string begin, string target, vector<string> words) {
    int depth = 1;

    bool possible(0);
    for (auto w : words)
        if (w == target) possible = true;
    if (!possible) return 0;

    // graph
    words.push_back(begin);
    int len = words[0].length();
    int num = words.size();
    int chk(0);
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            chk = 0;
            for (int k = 0; k < len; k++)
            {
                if (words[i][k] != words[j][k]) chk++;
                if (chk > 1) break;
            }
            if (chk < 2) {
                graph[words[i]].push_back(words[j]);
                graph[words[j]].push_back(words[i]);
            }
        }
    }

    dfs(begin, target, 0);

    if (ans == 51) return 0;

    return ans;
}
