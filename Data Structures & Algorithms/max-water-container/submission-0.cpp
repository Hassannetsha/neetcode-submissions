class Solution {
public:
    int maxArea(vector<int> &heights)
{
  int l = 0, r = heights.size() - 1, mxArea = INT_MIN;
  while (l<r)
  {
    int tempArea = (r-l) * min(heights[l],heights[r]);
    mxArea = max(tempArea,mxArea);
    if (heights[r]<heights[l])
    {
      r--;
    }
    else{
      l++;
    }
  }
  
  return mxArea;
}
};
