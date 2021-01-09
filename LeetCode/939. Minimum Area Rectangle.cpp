class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int area(2e9);
        unordered_map<int, unordered_set<int>> map;
        
        for(auto p : points)
            map[p[0]].insert(p[1]);
        
        for(int i=0; i<points.size()-1; i++)
        {
            for(int j=i+1; j<points.size(); j++)
            {
                if(points[i][0]!=points[j][0] && points[i][1]!=points[j][1])
                {
                    int x1 = points[i][0];
                    int y1 = points[i][1];
                    int x2 = points[j][0];
                    int y2 = points[j][1];
                    
                    if(map[x1].find(y2)!=map[x1].end() && map[x2].find(y1)!=map[x2].end()){
                        area = min(area, abs((x1-x2)*(y1-y2)));
                    }
                }
            }
        }
        if(area==2e9) return 0;
        return area;
    }
};
