class Fancy {
private:
    const long long MOD = 1e9 + 7;
    vector<pair<long long, long long>> nums;
    vector<pair<char, long long>> op;

public:
    Fancy() {}

    void append(int val) {
        nums.push_back({val % MOD, op.size()});

        if(op.empty()){
            op.push_back({'*',1});
            return;
        }

        if(op.back().first=='*'){
            op.push_back({'+', 0});
        }
        else{
            op.push_back({'*', 1});
        }
    }

    void addAll(int inc) {
        if(op.empty()){
            op.push_back({'+',inc});
            return;
        }

        if (op.back().first == '+') {
            op.back().second = (op.back().second + inc) % MOD;
        } else {
            op.push_back({'+', inc});
        }
    }

    void multAll(int m) {
        if (m == 0) {
            for (auto& x : nums) {
                x.first = 0;
                x.second = 0;
            }
            op.clear();
            return;
        }

        if(op.empty()){
            op.push_back({'*',m});
            return;
        }

        if (op.back().first == '*') {
            op.back().second = (op.back().second * m) % MOD;
        } else {
            op.push_back({'*', m});
        }
    }

    int getIndex(int idx) {
        if (idx >= nums.size())
            return -1;

        long long n = nums[idx].first;
        long long i = nums[idx].second;

        for (long long k = i; k < op.size(); k++) {
            if (op[k].first == '+') {
                n = (n + op[k].second) % MOD;
            } 
            else {
                n = (n * op[k].second) % MOD;
            }
        }

        return n;
    }
};