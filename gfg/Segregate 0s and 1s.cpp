class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int i=0;
        int j = arr.size()-1;
        while(i<j){
            while (i < j && arr[i] == 0) i++;
            while (i < j && arr[j] == 1) j--;
            if(i<j){
                swap(arr[i],arr[j]);
                i++;
                j--;
            }
        }
    }
};