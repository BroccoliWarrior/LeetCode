class Solution {
    bool match(string a, string b) {
        if (a.size() == 0 && b.size() == 0) {
            return true;
        }
        if (a.size() != b.size())
            return false;
        int arr[26], brr[26];
        // for (auto c : a) {
        //     arr[c % 26]++;
        // }
        // for (auto c : b) {
        //     brr[c % 26]++;
        // }
        for (auto c : a) {
            arr[c - 'a']++; // 改成 'a' 的 ASCII 值来计数
        }
        for (auto c : b) {
            brr[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (arr[i] != brr[i]) {
                return false;
            }
        }
        return true;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // unordered_map<string, int> unmap;
        unordered_map<string, bool> unmap; // 改为 bool 记录是否已处理过

        vector<vector<string>> res;

        int len = strs.size();
        for (int i = 0; i < len; i++) {
            // sub.clear();
            //  auto it = unmap.find(strs[i]);
            //  if (it != unmap.end())
            //      continue;
            if (unmap[strs[i]]) { // 如果已处理，跳过
                continue;
            }
            vector<string> sub;

            sub.push_back(strs[i]);
            unmap[strs[i]] = true; // 标记已处理

            for (int j = len - 1; j > i; j--) {

                // auto it = unmap.find(strs[j]);
                // if (it != unmap.end() && strs[j] != strs[j - 1])
                //     continue;
                // if (match(strs[i], strs[j])) {
                //     unmap[strs[j]] = i;
                //     sub.push_back(strs[j]);
                // }
                auto it = unmap.find(strs[j]);
                if (it == unmap.end()) {
                    if (match(strs[i], strs[j])) {
                        sub.push_back(strs[j]);
                        unmap[strs[j]] = true; // 标记
                    }
                } else if (it != unmap.end()) {
                    if (it->first == strs[j]) {
                        if (match(strs[i], strs[j])) {
                            sub.push_back(strs[j]);
                            unmap[strs[j]] = true; // 标记
                        }
                    }
                }
                
            }
            res.push_back(sub);
        }
        return res;
    }
};
