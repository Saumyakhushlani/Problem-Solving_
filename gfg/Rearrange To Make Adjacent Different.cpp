class Solution {
  public:
    string rearrangeString(string &s) {
        // code here
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> mpp;
        for (char c : s) {
            mpp[c]++;
        }
        for (auto it : mpp) {
            pair<int, char> p = {it.second, it.first};
            pq.push(p);
        }
        string res;
        while (!pq.empty()) {
            if (res.empty() || res.back() != pq.top().second) {
                auto p = pq.top();
                pq.pop();

                res.push_back(p.second);

                if (--p.first)
                    pq.push(p);
            } else {
                auto p = pq.top();
                pq.pop();

                if (pq.empty())
                    return "";

                auto q = pq.top();
                pq.pop();

                res.push_back(q.second);

                if (--q.first)
                    pq.push(q);

                pq.push(p);
            }
        }
        return res;
    }
};