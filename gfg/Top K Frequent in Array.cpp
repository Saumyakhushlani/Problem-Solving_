class Solution {
	public:
	struct myComp {
		bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
			if (a.first == b.first)
				return a.second > b.second;
			return a.first > b.first;
		}
	};
	vector<int> topKFreq(vector<int> &nums, int k) {
		// Code here
		priority_queue<pair<int, int>, vector<pair<int, int>>, myComp> pq;
		unordered_map<int, int> mpp;
		
		for (int n : nums) {
			mpp[n]++;
		}
		for (auto it: mpp) {
			pair<int, int> p = {it.second, it.first};
			if (pq.size()<k) {
				pq.push(p);
			} else {
				if (it.second > pq.top().first ||
				(it.second == pq.top().first && it.first > pq.top().second)) {
					pq.pop();
					pq.push(p);
				}
			}
		}
		vector<int>res;
		while (!pq.empty()) {
			res.push_back(pq.top().second);
			pq.pop();
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
