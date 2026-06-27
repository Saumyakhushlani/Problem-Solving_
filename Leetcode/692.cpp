class Solution {
public:
    struct myComp {
		bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
			if (a.first == b.first)
				return a.second < b.second;
			return a.first > b.first;
		}
	};
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int, string>, vector<pair<int, string>>, myComp> pq;
        unordered_map<string, int> mpp;

        for (auto n : words) {
            mpp[n]++;
        }
        for (auto it: mpp) {
			pair<int, string> p = {it.second, it.first};
			if (pq.size()<k) {
				pq.push(p);
			} else {
				if (it.second > pq.top().first || (it.second == pq.top().first && it.first < pq.top().second)) {
					pq.pop();
					pq.push(p);
				}
			}
		}
        vector<string>res;
		while (!pq.empty()) {
			res.push_back(pq.top().second);
			pq.pop();
		}
        reverse(res.begin(), res.end());
        return res;
    }
};