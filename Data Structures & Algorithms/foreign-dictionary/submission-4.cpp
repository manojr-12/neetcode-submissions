class Solution {
   public:
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        unordered_map<char, unordered_set<char>> adj;
        vector<int> indegree(26, 0);
        unordered_set<char> st;
        for (string word : words) {
            for (char ch : word) {
                st.insert(ch);
            }
        }
        for (int i = 0; i < n - 1; i++) {
            bool match = false;
            int ind = 0, len = min(words[i].size(), words[i + 1].size());
            while (ind < len) {
                if (words[i][ind] != words[i + 1][ind]) {
                    match = true;
                    char u = words[i][ind];
                    char v = words[i + 1][ind];
                    if (!adj[u].count(v)) {
                        adj[u].insert(v);
                        indegree[v - 'a']++;
                    }
                    break;
                }
                ind++;
            }
            if (!match && words[i].size() > words[i + 1].size()) {
                return "";
            }
        }
        queue<char> q;
        for (int i = 0; i < 26; i++) {
            if (st.count(i + 'a') && indegree[i] == 0) {
                q.push(i + 'a');
            }
        }
        string res;
        while (!q.empty()) {
            char curr = q.front();
            q.pop();
            res.push_back(curr);
            for (auto v : adj[curr]) {
                indegree[v - 'a']--;
                if (indegree[v - 'a'] == 0) {
                    q.push(v);
                }
            }
        }
        return res.size() == st.size() ? res : "";
    }
};
