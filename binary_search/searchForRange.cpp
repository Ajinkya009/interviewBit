class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1, mid;
        int flag = 0;
        vector<int> a;
        while(start<=end){
            mid = start+ (end-start)/2;
            if(target==nums[mid]){
                flag=mid;
                break;
            }
            else if(target<nums[mid]){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        if(flag==mid){
            a.push_back(flag);
            while(nums[mid]==target){
                mid++;
            }
            --mid;
            a.push_back(mid);
            return a;
        }
        else{
            a.push_back(-1);
            a.push_back(-1);
            return a;
        }
    }
};
