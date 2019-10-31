Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"


class Solution {
public:
    string longestPalindrome(string s) {
    
    int n=s.size();
    vector<vector<int>>ISPALIN(n,vector<int>(n));
    int start=0;
    int end=0;
    int len=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j||i==j+1)
                ISPALIN[i][j]=true;
            else
                ISPALIN[i][j]=false;
        }
    }
    
    for(int k=1;k<n;k++){
        for(int i=0,j=k;j<n;i++,j++){
            if(s[i]==s[j] && ISPALIN[i+1][j-1]){
                ISPALIN[i][j]=true;
            }
            else
                ISPALIN[i][j]=false;
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(ISPALIN[i][j]){
                if(j-i+1>len){
                    start=i;
                    end=j;
                    len=j-i+1;
                }
            }
        }
    }
 
    string ans= "";
    for(int i=start;i<=end;i++){
        ans+=s[i];
    }
    return ans;
    }
