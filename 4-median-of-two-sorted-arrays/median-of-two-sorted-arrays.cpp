class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int n1 =nums1.size();
    int n2 = nums2.size();
    if(n1 > n2)return findMedianSortedArrays(nums2,nums1);
    int n = n1+n2;

    int partition = (n+1)/2;
    // edge cases
    if(n1==0)
         return n2%2?nums2[n2/2]:(nums2[n2/2]+nums2[n2/2-1])/2.0;  
    if(n2==0)
        return n1%2?nums1[n1/2]:(nums1[n1/2]+nums1[n1/2-1])/2.0;
    int left =0;
    int right = n1;
    int cut1 =0,cut2 =0;
    while(left <= right)
    {
        cut1 = (left+right)/2;
        cut2 = partition-cut1;
        int l1  = cut1 ==0 ? INT_MIN : nums1[cut1-1];
        int l2 = cut2 ==0 ? INT_MIN : nums2[cut2-1];
        int r1 = cut1 >=n1 ? INT_MAX : nums1[cut1];
        int r2 = cut2 >=n2 ? INT_MAX : nums2[cut2];

        if(l1 <=r2 && l2 <= r1)
        {
            return n%2==1?max(l1,l2) : (max(l1,l2)+min(r1,r2))/2.0;
        }
        else if(l1 > r2)
            right = cut1-1;
        else
            left  =cut1+1;
    }
    return 0.0;
      
    }
};