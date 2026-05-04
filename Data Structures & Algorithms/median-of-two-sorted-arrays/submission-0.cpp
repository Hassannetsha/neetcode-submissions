class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>vec(nums1.size()+nums2.size(),0);
        int l = 0,r = 0,k = 0;
        while(l<nums1.size()&&r<nums2.size()){
            if(nums1[l]<nums2[r]){
                vec[k] = nums1[l];
                l++;
            }
            else{
                vec[k] = nums2[r];
                r++;
            }
            k++;
        }
        while(l<nums1.size()){
            vec[k++] = nums1[l++];
        }
        while(r<nums2.size()){
            vec[k++] = nums2[r++];
        }
        if(vec.size()%2){
            return vec[int(vec.size()/2)];
        }
        else{
            double num = vec[int(vec.size()/2)] +vec[int(vec.size()/2)-1] ;
            num/=2.0;
            return num;
        }
    }
};
