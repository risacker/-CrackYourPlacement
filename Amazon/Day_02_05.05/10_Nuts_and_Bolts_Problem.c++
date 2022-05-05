/*Given a set of N nuts of different sizes and N bolts of different sizes. There is a one-one mapping between nuts and bolts. Match nuts and bolts efficiently.
Comparison of a nut to another nut or a bolt to another bolt is not allowed. It means nut can only be compared with bolt and bolt can only be compared with nut to see which one is bigger/smaller.
The elements should follow the following order ! # $ % & * @ ^ ~ .

Example 1:

Input: 
N = 5
nuts[] = {@, %, $, #, ^}
bolts[] = {%, @, #, $ ^}

Output: 
# $ % @ ^
# $ % @ ^

Example 2:

Input: 
N = 9
nuts[] = {^, &, %, @, #, *, $, ~, !}
bolts[] = {~, #, @, %, &, *, $ ,^, !}

Output: 
! # $ % & * @ ^ ~
! # $ % & * @ ^ ~

Your Task:  
You don't need to read input or print anything. Your task is to complete the function matchPairs() which takes an array of characters nuts[], bolts[] and n as parameters and returns void. 
You need to change the array itself.

Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 9
Array of Nuts/Bolts can only consist of the following elements:{'@', '#', '$', '%', '^', '&', '~', '*', '!'}.*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:	
	void matchPairs(char nuts[], char bolts[], int n) {
	    // code here
	    sort(nuts, nuts+n); 
	    sort(bolts, bolts+n);
	}

};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char nuts[n], bolts[n];
        for(int i = 0; i < n; i++){
            cin>>nuts[i];
        }
        for(int i = 0; i < n; i++){
            cin>>bolts[i];
        }
        Solution ob;
        ob.matchPairs(nuts,bolts,n);
        for(int i = 0; i <n; i++){
               cout<<nuts[i]<<" ";
        }
        cout<<endl;
        for(int i = 0; i <n; i++){
               cout<<bolts[i]<<" ";
        }
        cout<<endl;
    }
}