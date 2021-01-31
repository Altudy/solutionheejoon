#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

vector<string> ans;
unordered_map<string, vector<string>> m;
int T_NUM;

bool dfs(string& cur, int t_num)
{
    if (t_num == T_NUM)
        return true;

    vector<string> candi = m[cur];
    for (int i=0; i<candi.size(); i++)
    {
        if (candi[i] == "") continue;
        m[cur][i] = "";
        ans.emplace_back(candi[i]);

        if (dfs(candi[i], t_num + 1)) return true;
        m[cur][i] = candi[i];
        ans.pop_back();
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    T_NUM = tickets.size();
    for (int i = 0; i < T_NUM; i++)
    {
        if (m.find(tickets[i][0]) == m.end()) {
            m[tickets[i][0]] = { tickets[i][1] };
        }
        else {
            m[tickets[i][0]].emplace_back(tickets[i][1]);
            sort(m[tickets[i][0]].begin(), m[tickets[i][0]].end());
        }
    }

    string s = "ICN";
    ans.emplace_back(s);
    dfs(s, 0);

    return ans;
}
