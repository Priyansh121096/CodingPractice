// https://www.interviewbit.com/problems/longest-palindromic-substring/

int expand(string s, int st, int en){
    while(st>=0 && en<s.size() && s[st]==s[en]){
        st--;
        en++;
    }
    return en-st-1;
}

string Solution::longestPalindrome(string A) {
    if(A.size()<2)  return A;
    int len = 1;
    int st = 0;
        for(int i=1; i<A.size(); i++){
            int ll = max(expand(A, i-1, i+1), expand(A, i-1, i));
            if(ll>len)
            {
                len = ll;
                st = i - len/2;
            }
        }

    return A.substr(st, len);
}
