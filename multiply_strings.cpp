// https://www.interviewbit.com/problems/multiply-strings/

string sum(string A, string B){
    int carry = 0;
    int sum = 0;
    string ans = "";
    for(int i=0; i<max(A.size(), B.size()); i++){
        sum += carry;
        if(i<A.size()){
            sum += A[i]-'0';
        }
        if(i<B.size()){
            sum += B[i]-'0';
        }
        carry = sum/10;
        sum %= 10;
        ans += '0' + sum;
        sum = 0;
    }
    if(carry>0) ans+="1";
    return ans;
}
string Solution::multiply(string A, string B) {
    string ans;
    int tmp;
    string zeros = "";
    for(int i=A.size()-1; i>=0; i--){
        string c = zeros;
        int val = A[i]-'0';
        // cout << val;
        int carry = 0;
        for(int j=B.size()-1; j>=0; j--){
            tmp = (B[j]-'0')*val;
            tmp += carry;
            // cout << tmp << endl;
            carry = tmp/10;
            tmp %= 10;
            c += '0' + tmp;
        }
        if(carry>0) c+='0'+carry;
        // cout << c << endl;
        ans = sum(ans, c);
        zeros += "0";
    }
    // cout << "ANS" << endl;
    reverse(ans.begin(), ans.end());
    int i;
    for(i=0; i<ans.size(); i++){
        if(ans[i]!='0')   break;   
    }
    if(i!=ans.size())   ans = ans.substr(i);
    else    ans = "0";
    return ans;
}