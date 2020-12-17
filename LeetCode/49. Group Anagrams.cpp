class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> map;
        string origin;
        vector<string> temp{""};
        vector<vector<string>> ans;

        for (auto str : strs)
        {
            origin = str;
            sort(str.begin(), str.end());
            if (map.find(str) == map.end()) {
                temp[0] = origin;
                map[str] = temp;
            }
            else {
                map.find(str)->second.emplace_back(origin);
            }
        }

        for (auto m : map)
        {
            ans.emplace_back(m.second);
        }
        return ans;
    }
};
////////////////////////////////////////////////////////////////////
/* best solution

class Solution {
public:
    string Sort(string a)
    {
        
        for(int i=0;i<a.size();i++)
        {
            for(int j=i+1;j<a.size();j++)
            {
                if(a[i]>a[j])
                {
                    char temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                }
            }
        }
        
            return a;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {        
        vector<vector<string>> re;
        int n=strs.size();
        unordered_map<string,vector<string>> values;

        for(int i=0;i<n;i++)
        {
            string temp=Sort(strs[i]);
            values[temp].push_back(strs[i]);
        }

        for(auto iter=values.begin();iter!=values.end();iter++)
        {
            re.push_back(iter->second);
        }
        return re;
    }
};

*/
