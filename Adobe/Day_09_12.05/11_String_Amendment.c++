/*Given a string which is basically a sentence without spaces between words. However the first letter of every word is in uppercase. You need to print this sentence after following amendments:
   (i)  Put a single space between these words
   (ii) Convert the uppercase letters to lowercase.
Note: The first character of the string can be both uppercase/lowercase.

Example 1:

Input:
s = "BruceWayneIsBatman"

Output: bruce wayne is batman

Explanation: The words in the string are "Bruce", "Wayne", "Is", "Batman".

Example 2:

Input: 
s = "You"

Output: you

Explanation: The only word in the string is "You".

Your Task: 
You don't need to read input or print anything. Your task is to complete the function amendSentence() which takes the string s as input and returns a string with the stated amendments.


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N) (for output string).


Constraints:
1 <= Size of String <= 10^6
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string amendSentence (string s){
        // your code here
        string ans;
        int n = s.size(), start = 0, end = 1;
        while(end <= n){
            if((isupper(s[end])) || end == n){
                string st = s.substr(start, end - start);
                st[0] = tolower(st[0]);
                ans += st;
                ans.push_back(' ');
                start = end;
            }
            end++;
        }
        ans.pop_back();
        return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution s;
        cout<<s.amendSentence(str)<<endl;
    }
}