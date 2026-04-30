class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int>vec;
        for(int i = 0;i<matrix.size();i++){
            for(int j = 0; j<matrix[i].size();j++){
                vec.push_back(matrix[i][j]);
            }
        }
        int s = 0,e = vec.size() - 1;
        while(s<=e){
            int mid = (s+e)/2;
            if(vec[mid]==target){
                return true;
            }
            else if(vec[mid]>target){
                e = mid-1;
            }
            else{
                s = mid + 1;
            }
        }
        return false;
    }
};
