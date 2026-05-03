class TimeMap {
public:
    map<string,map<int,string>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].insert({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        map<int,string>search = mp[key];
        auto it = search.upper_bound(timestamp);
        if(it==search.begin()){
            return "";
        }
        it--;
        
        return it->second;
    }
};