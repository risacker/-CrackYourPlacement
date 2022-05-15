/*Given a keypad as shown in the diagram, and an N digit number which is represented by array a[ ], the task is to list all words which are possible by pressing these numbers.

Example 1:

Input: N = 3, a[] = {2, 3, 4}

Output:
adg adh adi aeg aeh aei afg afh afi 
bdg bdh bdi beg beh bei bfg bfh bfi 
cdg cdh cdi ceg ceh cei cfg cfh cfi 
Explanation: When we press 2,3,4 then 
adg, adh, adi, ... cfi are the list of 
possible words.

Example 2:

Input: N = 3, a[] = {3, 4, 5}

Output:
dgj dgk dgl dhj dhk dhl dij dik dil 
egj egk egl ehj ehk ehl eij eik eil 
fgj fgk fgl fhj fhk fhl fij fik fil
Explanation: When we press 3,4,5 then 
dgj, dgk, dgl, ... fil are the list of 
possible words.

Your Task:
You don't need to read input or print anything. You just need to complete the function possibleWords() that takes an array a[ ] and N as input parameters and returns an array of all the possible words in lexicographical increasing order. 

Expected Time Complexity: O(4N * N).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 10
2 ≤ a[i] ≤ 9*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N){
        //Your code here
        vector<string> m{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, ans{""};
	    for(int i = 0; i < N; i++){
	    	vector<string> e;
		    for(auto& c : ans)
			    for(auto n : m[a[i]-2])
				    e.push_back(c + n);             
		        ans = move(e); 
	    }
	    return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin>>arr[i];
        }
        Solution s;
        vector<string> res = s.possibleWords(arr, N);
        for(string i : res){
            cout<<i<<endl;
        }
    }
}