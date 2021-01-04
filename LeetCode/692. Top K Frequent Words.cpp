typedef pair<string, int> psi;

bool cmp(const psi& a, const psi& b) {
	if (a.second == b.second)
    return a.first < b.first;
	return a.second > b.second;
}

class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		unordered_map<string, int> m;

		for (auto i = 0; i < words.size(); i++)
      m[words[i]] ++;

		vector<psi> vec(m.begin(), m.end());
		sort(vec.begin(), vec.end(), cmp);

		vector<string> ans;
		for (int i = 0; i < k; i++)
			ans.push_back(vec[i].first);

		return ans;
	}
};
