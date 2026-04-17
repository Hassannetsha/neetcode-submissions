class Solution {
public:
    bool isPalindrome(string s) {
        int r = 0, l = s.size() - 1;
  while (l > r)
  {
    
    while (isalnum(s[l]) == false && l > r)
      l--;
    while (isalnum(s[r]) == false && l > r)
      r++;
    if (tolower(s[l]) != tolower(s[r]))
      return false;
    l--;
    r++;
  }
  return true;
    }
};
