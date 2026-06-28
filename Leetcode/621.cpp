class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mpp;
        unordered_map<char,int>free;
        for(char ch:tasks){
            mpp[ch]++;
            free[ch]=1;
        }
        priority_queue<pair<int,char>>pq;
        for(auto it:mpp){
            pq.push({it.second,it.first});
        }
        string res;
        int seat=1;
        while(!pq.empty()){
            vector<pair<int,char>>tmp;
             bool done = false;
            while(!pq.empty()){
                pair<int,char> p = pq.top();
                pq.pop();
                if(free[p.second]<=seat){
                    if(p.first>1){
                        pq.push({p.first-1,p.second});
                        free[p.second]=seat+n+1;
                        
                        break;
                    }
                    done = true;
                    break;
                }else{
                    tmp.push_back(p);
                }
            }
            for(int i=0;i<tmp.size();i++){
                pq.push(tmp[i]);
            }
            seat++;
        }
        return seat-1;
    }
};