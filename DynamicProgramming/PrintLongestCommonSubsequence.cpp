class Solution {
    string LCS(string s1, string s2, int n, int m) {
        int tp[n+1][m+1];
        for (int i=0; i<=n; i++) {
            for (int j=0; j<=m; j++) {
               // Base condition
                if(i == 0 or j == 0)
                    tp[i][j] = 0;
                // If elements at current indexes of both the strings are equal
                else if(s1[i-1] == s2[j-1]) {
                    tp[i][j] = 1+tp[i-1][j-1];
                } else {
                    tp[i][j] = max(tp[i][j-1], tp[i-1][j]);
                } 
            }
        }
        // To print the longest common substring, we need to back track the matrix that we made earlier, starting 
        // from the last till one of the string reaches the end
        string s = "";
        int i = n, j = m;
        while (i>0 and j>0) {
                // if char turns out to be equal, we will add this in our result
                if(s1[i-1] == s2[j-1]) {
                    s += s1[i-1];
                    i --;
                    j --;
                } 
                // If the chars at current indices of both the strings are not equal
                else {
                    // Move to the direction where max length is present
                    if(tp[i-1][j] > tp[i][j-1]) {
                        i --;
                    } else {
                        j --;
                    }
                    
                }
        }
        reverse(s.begin(), s.end());
        return s;;
    }
public:
    string longestCommonSubsequence(string text1, string text2) {
        string ans;
        int n = text1.length();
        int m = text2.length();
        ans = LCS(text1, text2, n, m);
        return ans;
    }
};
