class Solution {
  public:
    int wordLadder(vector<string> &wordList, string &beginWord, string &endWord) {
        // code here
        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>>pq;
        unordered_map<string,int>mpp;
        for(auto word: wordList){
            mpp[word]=1;
        }
        if(mpp.find(beginWord)==mpp.end()){
            mpp[beginWord]=1;
        }
        if(mpp.find(endWord)==mpp.end())return 0;
        pq.push({1,beginWord});
        while(!pq.empty()){
            string word = pq.top().second;
            int val = pq.top().first;
            pq.pop();
            for (int i = 0; i < word.size(); i++) {
                string temp = word;

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    temp[i] = ch;

                    if (temp == endWord)
                        return val+1;

                    if (mpp.find(temp) != mpp.end()) {
                        pq.push({val+1,temp });
                        mpp.erase(temp);
                    }
                }
            }
        }


        return 0;
    }
};