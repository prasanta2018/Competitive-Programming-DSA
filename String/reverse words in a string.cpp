// LeetCode: https://leetcode.com/problems/reverse-words-in-a-string/

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:

    void reverseSingleWord(string &s, int start, int end) {
        int mid = (start+end)/2;
        char temp;
        for(int i=start; i<=mid; i++) {
            temp = s[i];
            s[i] = s[start+end-i];
            s[start+end-i] = temp;
        }
    }
    
    void CleanSpaces(string &s) {
        int n = s.length();
        int i=0, j=0;
        while(i < n && j < n) {
            // skip spaces
            while(j < n && s[j] == ' ')
                j++;
            // copy non-spaces
            while(j < n && s[j] != ' ')
                s[i++] = s[j++];
            // skip spaces
            while(j < n && s[j] == ' ')
                j++;
            // append only one space
            if(j < n)
                s[i++] = ' ';
        }
        s.resize(i);
     }

    string reverseWords(string s) {
        // O(n) time and O(n) space
        if(0) {
            int n = s.length();
            int i = 0;
            int j;
            string res;
            while(i < n) {
                while((i < n) && (s[i] == ' '))
                    i++;
                if(i >= n) break;
                j = i+1;
                while((j < n) && (s[j] != ' '))
                    j++;
                string sub = s.substr(i, j-i);
                if(res.length() == 0)
                    res = sub;
                else
                    res = sub + " " + res;
                i = j+1;
            }
            return res;
        }
        
        // O(n) time and O(1) space
        if(1) {
            // Clean all the spaces
            CleanSpaces(s);
            int n = s.length();
            int start = 0;
            int end = n-1;

            // leading spaces
            while((start < n) && (s.at(start) == ' '))
                start++;

            // trailing spaces
            while((end >= 0) && (s.at(end) == ' '))
                end--;

            // reverse the full string
            reverseSingleWord(s, start, end);

            start = 0;
            // reverse each word
            for(int i=0; i<n; i++) {
                if(s[i] == ' ') {
                    reverseSingleWord(s, start, i-1);
                    start = i+1;
                }
            }
            reverseSingleWord(s, start, n-1);
            return s;
        }
    }
};