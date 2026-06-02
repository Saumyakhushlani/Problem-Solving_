class Solution {
  public:
    int countTriplets(int sum, vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end());
        int res=0;
        for(int i=0;i<arr.size()-2;i++){
            int left=i+1;
            int right = arr.size()-1;
            while(left<right){
                int s = arr[i]+arr[left]+arr[right];
                if(s<sum){
                    res+=(right-left);
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return res;
    }
};