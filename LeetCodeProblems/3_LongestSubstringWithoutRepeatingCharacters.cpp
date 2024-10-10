/*
Longest Substring Without Repeating Characters:
Given a string s, find the length of the longest substring without repeating characters.
*/
class Solution {
public:
   int lengthOfLongestSubstring(std::string s)
    {
        std::unordered_set<char> charSet;       //no need to use std::set, since we don't care about storing elements in order
        int length = s.size();
        int left = 0;
        int right;
        int longest = 0;      

        //for loop for the right pointer to traverse the whole string
        for(right = 0; right < length; right++) 
        {
            char c = s[right];  //get each element of the string

            //if character already exist in the set
            while (charSet.count(c)) //while we found a character that is a duplicate, we'll contract the window by increase the left pointer + 1
            {
                charSet.erase(s[left]);      //removing the element where left pointer is pointing at
                left += 1;                      //increase the left pointer
            }
            charSet.insert(c); //store the current element into the set
            int w = right - left + 1;           //calculate window length
            longest = std::max(longest, w);     //update longest with longest current window length
        }

        return longest;

    }
};
