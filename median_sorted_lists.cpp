class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if(n1 > n2){
            swap(nums1, nums2);
            swap(n1, n2);
        }
        int imin = 0, imax = n1, mid = (n1 + n2 + 1)/2;
        while(imin <= imax){
            int i = (imin + imax)/2;
            int j = mid - i;
            if(i < n1 && nums2[j-1] > nums1[i]) imin = i + 1;
            else if(i > 0 && nums1[i-1] > nums2[j]) imax = i - 1;
            else{
                int maxLeft;
                if(i == 0) maxLeft = nums2[j-1];
                else if(j == 0) maxLeft = nums1[i-1];
                else maxLeft = max(nums1[i-1], nums2[j-1]);
                
                if((n1+n2)%2==1) return maxLeft;
                
                int minRight;
                if(i == n1) minRight = nums2[j];
                else if(j == n2) minRight = nums1[i];
                else minRight = min(nums1[i], nums2[j]);
                
                return (minRight + maxLeft)/2.0;
            }
        }
        //cout<<nums1[m1]<<" "<<nums2[m2]<<endl;
        return 0;
    }
};
