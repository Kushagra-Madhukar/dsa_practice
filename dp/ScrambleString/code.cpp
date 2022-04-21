class Solution {
public:
    unordered_map<string, bool> mp;
    bool scrambleMain(string s1, string s2) {
        string key = s1 + " " + s2;
        if(mp.find(key) != mp.end()) return mp[key];
        if(s1 == s2) return true;
        int n = s1.size(), m = s2.size();
        if(n != m) return false;
        if(n <= 1) return false;
        bool flag = false;
        for(int k=1;k<=n-1;k++){
            bool swap_cond = scrambleMain(s1.substr(0, k), s2.substr(n-k, k)) && scrambleMain(s1.substr(k, n-k), s2.substr(0, n-k));
            bool no_swap_cond = scrambleMain(s1.substr(0, k), s2.substr(0, k)) && scrambleMain(s1.substr(k, n-k), s2.substr(k, n-k));
            if(swap_cond || no_swap_cond) {
                flag = true;
                break;
            }
        }
        return mp[key] = flag;
    }
    bool isScramble(string s1, string s2) {
        mp.clear();
        return scrambleMain(s1, s2);
    }
};
