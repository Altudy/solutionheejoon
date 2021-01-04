class RandomizedSet {
public:
    unordered_map<int, int> m;
    vector<int> vec;

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
    }
    
    int getRandom() {
        return vec[rand() % vec.size()];
    }
};
