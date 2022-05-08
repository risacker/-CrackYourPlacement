/*Find the number of unique words consisting of lowercase alphabets only of length N that can be formed with at-most K contiguous vowels. 

Example 1:

Input:
N = 2
K = 0

Output:
441

Explanation:
Total of 441 unique words are possible of length 2 that will have K( = 0) vowels together, e.g. "bc", "cd", "df", etc are valid words while "ab" (with 1 vowel) is not a valid word.

Example 2:

Input:
N = 1
K = 1

Output:
26

Explanation:
All the english alphabets including vowels and consonants; as atmost K( = 1) vowel can be taken.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function kvowelwords() which takes an Integer N, an intege K and returns the total number of words of size N with atmost K vowels. As the answer maybe to large please return answer modulo 1000000007.

Expected Time Complexity: O(N*K)
Expected Auxiliary Space: O(N*K)

Constraints:
1 ≤ N ≤ 1000
0 ≤ K ≤ N
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    long long t[1001][1001];
    long long solve(int n , int k , int cnt){
        if(n == 0)
          return 1;
        if(t[n][cnt] != -1)
          return t[n][cnt];
        if(cnt < k)
          return t[n][cnt] = (21*solve(n-1, k, 0) + 5*solve(n-1, k , cnt+1)) % 1000000007;
        if(cnt == k)
          return t[n][cnt] = (21*solve(n-1, k, 0)) % 1000000007;
    }
  
    int kvowelwords(int n, int k) {
        // Write Your Code here
        memset(t, -1, sizeof(t)) ;
        return solve(n, k, 0) % 1000000007;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        Solution s;
        cout<<s.kvowelwords(N, K)<<endl;
    }
}