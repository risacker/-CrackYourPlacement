/*Given an array of names (consisting of lowercase characters) of candidates in an election. A candidate name in array represents a vote casted to the candidate. 
Print the name of candidate that received Max votes. If there is tie, print lexicographically smaller name.

Example 1:

Input:
n = 13
Votes[] = {john,johnny,jackie,johnny,john 
jackie,jamie,jamie,john,johnny,jamie,
johnny,john}

Output: john 4

Explanation: john has 4 votes casted for him, but so does johny. john is lexicographically smaller, so we print john and the votes he received.

Example 2:

Input:
n = 3
Votes[] = {andy,blake,clark}

Output: andy 1

Explanation: All the candidates get 1 votes each. We print andy as it is lexicographically smaller.

Your Task:
You only need to complete the function winner() that takes an array of strings arr, and n as parameters and returns the name of the candiate with maximum votes and the number of votes the candidate got as an array of size 2.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 <= n <= 105
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        unordered_map<string , int>umap;
        for(int i=0;i<n;i++){
           umap[arr[i]]++;
        }
        string name = "";
        int max_vote = 0;
        for(auto itr = umap.begin(); itr!=umap.end(); itr++){
           string key = itr->first;
           int val = itr->second;
           if(val>max_vote){
               max_vote = val;
               name = key;
           }
           else if(val == max_vote){
               if(key<name)
                   name = key;
           }
       }
       vector<string> ans;
       ans.push_back(name);
       string temp = to_string(max_vote);
       ans.push_back(temp);
       return ans;
    }
};

int main(){
    int t;
    cin>>t;
        for(int i = 0; i < t; i++){
            int n;
            cin>>n;
            string arr[n];   
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        Solution s;
        vector<string> res = s.winner(arr, n);
            cout<<res[0]<<" "<<res[1]<<endl;
    }
    return 0;
}