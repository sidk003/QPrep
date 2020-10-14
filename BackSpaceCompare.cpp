// https://leetcode.com/problems/backspace-string-compare/
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int skip=0;
        int i;
        string s,t;
        i=S.size()-1;
        
        while(i>=0)
        {
            if(S[i]=='#')
            {
                skip++;
                i--;
                continue;
            }
            if(skip>0)
            {
                skip--;
                i--;
                continue;
            }
            
            s=s+S[i];
            i--;
        }
        i=T.size()-1;
        skip=0;
        while(i>=0)
        {
            if(T[i]=='#')
            {
                skip++;
                i--;
                continue;
            }
            if(skip>0)
            {
                skip--;
                i--;
                continue;
            }
            
            t=t+T[i];
            i--;
        }
        
        
        if(s==t)
            return true;
        
        return false;
    }
};