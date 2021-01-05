#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
 
using namespace std;
 
const int go_max = 26;
 
struct trie {
    bool output;
    trie* go[go_max];
    unordered_map<int,int> mp;
 
    trie() {
        fill(go, go + go_max, nullptr);
        output = false;
    }
 
    ~trie() {
        for(int i = 0; i < go_max; i++)
            if(go[i]) delete go[i];
    }
 
    void insert(const char *key, int l) {
        if(*key == '\0') {
            output = true;
            return;
        }
        int idx = *key - 'a';
        mp[l] += 1;
        if(!go[idx]) {
            go[idx] = new trie;
        }
        go[idx]->insert(key + 1, l);
    }
 
    int find(const char *key, int l) {
        if(*key == '\0') return output;
        int ret = 0;
        int idx = *key - 'a';
        if(*key == '?') {
            ret += mp[l];
        }
        else {
            if(!go[idx]) return 0;
            ret = go[idx]->find(key + 1, l);
        }
        return ret;
    }
};
 
vector<int> solution(vector<string> w, vector<string> q) {
    trie* root_f = new trie;
    trie* root_r = new trie;
 
    int wl = w.size(), ql = q.size();
    for(int i = 0; i < wl; i++) {
        string s = w[i];
        root_f->insert(&s[0], s.size());
        reverse(s.begin(), s.end());
        root_r->insert(&s[0], s.size());
    }
 
    vector<int> ans(ql);
    for(int i = 0; i < ql; i++){
        string query = q[i];
        if(query[0] != '?'){
            ans[i] = root_f->find(&query[0], query.size());
        }
        else {
            reverse(query.begin(), query.end());
            ans[i] = root_r->find(&query[0], query.size());
        }
    }
    return ans;
}
