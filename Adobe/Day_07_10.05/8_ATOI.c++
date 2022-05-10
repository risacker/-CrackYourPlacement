/*Your task  is to implement the function atoi. The function takes a string(str) as argument and converts it to an integer and returns it.

Note: You are not allowed to use inbuilt function.

Example 1:

Input:
str = 123

Output: 123

Example 2:

Input:
str = 21a

Output: -1

Explanation: Output is -1 as all characters are not digit only.

Your Task:
Complete the function atoi() which takes a string as input parameter and returns integer value of it. if the input string is not a numerical string then returns -1.
Note: Numerical strings are the string where either every character is in between 0-9 or where the first character is '-' and the rest all characters are in between 0-9.

Expected Time Complexity: O(|S|), |S| = length of string str.
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ length of S ≤ 10

Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. 
As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int ans = 0, factor = 1;
        if(str[0] == '-'){
            factor = -1;
            str[0] = '0';
        }
        for(auto c : str){
            if(c > '9' || c < '0'){
                return -1;
            }
            ans *= 10;
            ans += c - '0';
        }
        return factor*ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution s;
        cout<<s.atoi(str)<<endl;
    }
}