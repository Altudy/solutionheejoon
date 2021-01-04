class RandomizedSet {
public:
    unordered_map<int, int> m;
    vector<int> vec;
//    srand((unsigned int)time(0));

    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(m.find(val) == m.end()) {
            vec.emplace_back(val);
            m[val] = vec.size()-1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(m.find(val) ==  m.end())
            return false;

        int last = vec.back();
        m[last] = m[val];
        vec[m[last]] = last;
        vec.pop_back();
        m.erase(val);
        return true;
        
        
        int idx = m[val];
        vec[idx] = vec.back();
        vec.pop_back();
        m.erase(val);
        m[vec[idx]] = idx;
        return true;
    }
    
    int getRandom() {
        return vec[rand() % vec.size()];
    }
};
