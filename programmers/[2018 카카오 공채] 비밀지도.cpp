#include <string>       //programmers [1차] 비밀지도
#include <vector>
#include <bitset>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    answer.resize(n);

    for (int i = 0; i < n; i++)
    {
        answer[i] = bitset<16>(arr1[i] | arr2[i]).to_string();
        for (int j = 0; j < n; j++)
        {
            if (answer[i][16-n+j] == '1') answer[i][j] = '#';
            else answer[i][j] = ' ';
        }
        answer[i] = answer[i].substr(0, n);
    }
    return answer;
}
