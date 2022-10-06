#include <bits/stdc++.h>

using namespace std;

class TimeMap {
  map<string, vector<pair<int, string>>> m;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = lower_bound(m[key].begin(), m[key].end(), make_pair(timestamp, string()));
        if (it == m[key].end() || it->first > timestamp) {
            if (it == m[key].begin()) return "";
            --it;
        }
        return it->second;
    }
};

int main()
{
  
  return 0;
}