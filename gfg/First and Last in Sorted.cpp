class Solution {
  public:
    int first(vector<int>& nums, int target){
        int l=0;
        int h=nums.size()-1;
        int ans=-1;
        while(l<=h){
        int mid = l + (h - l) / 2;
            if(nums[mid]==target){
                ans=mid;
                h=mid-1;
            }
            else if(nums[mid]>target){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
    int last(vector<int>& nums, int target){
        int l=0;
        int h=nums.size()-1;
        int ans=-1;
        while(l<=h){
        int mid = l + (h - l) / 2;
            if(nums[mid]==target){
                ans=mid;
                l = mid+1;
            }
            else if(nums[mid]>target){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
    vector<int> find(vector<int>& arr, int x) {
        // code here
        int a = first(arr,x);
        int b = last(arr,x);
        vector<int> ans;
        ans.push_back(a);
        ans.push_back(b);

        return ans;
    }
};