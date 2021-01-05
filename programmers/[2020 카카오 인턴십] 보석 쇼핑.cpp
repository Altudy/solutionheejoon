#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
    int SIZE = gems.size();
    vector<int> answer = {0, SIZE - 1};
    unordered_map<string, int> m;
    int start(0), end(0), len(INT_MAX), KINDS(0), k(0);
    
    for(auto g : gems)
    {
        if(m.find(g) == m.end()){
            m[g] = 0; KINDS++;
        }
    }
    
    while(end < SIZE)
    {
        if(m[gems[end]]==0){
            k++;
        }
        m[gems[end]]++;
        
        if(k==KINDS)
        {
            while(m[gems[start]] > 1)
            {
                m[gems[start]]--;
                start++;
            }
            if(end-start+1 < len) {
                answer[0] = start + 1;
                answer[1] = end + 1;
                len = end-start+1;
            }
            m[gems[start]]--;
            k--;
            start++;
        }
        end++;
    }
    return answer;
}
