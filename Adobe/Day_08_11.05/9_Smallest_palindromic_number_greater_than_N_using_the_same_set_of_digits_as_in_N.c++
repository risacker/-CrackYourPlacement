#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    string nextPalin(string N) { 
        //complete the function here
        int n = N.size();
        string s = N.substr(0, n/2);
        if(!next_permutation(s.begin(), s.end()))
            return "-1";
        string str = s;
        reverse(str.begin(), str.end());
        if(n%2 == 1)
            s += N[n/2];
        return s+str;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution s;
        cout<<s.nextPalin(str)<<endl;
    }
}