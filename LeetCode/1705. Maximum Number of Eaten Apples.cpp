typedef pair<int, int> pii;

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        int ans(0), i(0);

        do
        {
            if (i < apples.size())
            {
                pq.push({ days[i] + i - 1, apples[i] });
            }

            while (!pq.empty())
            {
                if (pq.top().first >= i)
                {
                    pii top = pq.top(); pq.pop();
                    top.second--;
                    if (top.second > 0) pq.push(top);
                    ans++;
                    break;
                }
                else pq.pop();
            }
        } while (i++ < apples.size() || !pq.empty());
        return ans;
    }
};
///////////////////////////////////////////////////////////
/*

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& expire) {
        int N = apples.size();
        vector<int> dp(N + 20001, 0);
        int cnt = 0;
        int last = N;
        int p = 0;
        
        for (int d = 0; d < last; ++d) {
            if (d < N) {
                int ne = expire[d] + d;
                dp[ne] += apples[d];
                if (ne < p) p = ne;
                if (ne > last) last = ne;
            }
            while ((p <= d || dp[p] == 0) && p < last) ++ p;
            if (dp[p]) {
                dp[p] --;
                cnt ++;
            }
        }
        return cnt;
    }
};

*/
