#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef pair<int, int> pii;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    unordered_map<int, pii> loc;
    loc[1] = { 1, 1 }; loc[2] = { 1, 2 }; loc[3] = { 1, 3 };
    loc[4] = { 2, 1 }; loc[5] = { 2, 2 }; loc[6] = { 2, 3 };
    loc[7] = { 3, 1 }; loc[8] = { 3, 2 }; loc[9] = { 3, 3 }; loc[0] = { 4, 2 };

    pii ll(4, 1), rr(4, 3);
    int llen(0), rlen(0);
    
    for (auto num : numbers)
    {
        if (num % 3 == 1) {
            answer.push_back('L');
            ll = loc[num];
        }
        else if (num % 3 == 0 && num != 0) {
            answer.push_back('R');
            rr = loc[num];
        }
        else {
            llen = abs(loc[num].first - ll.first) + abs(loc[num].second - ll.second);
            rlen = abs(loc[num].first - rr.first) + abs(loc[num].second - rr.second);

            if (llen < rlen || (llen == rlen && hand == "left"))
            {
                answer.push_back('L');
                ll = loc[num];
            }
            else
            {
                answer.push_back('R');
                rr = loc[num];
            }
        }
    }
    return answer;
}
