/*Given a number N. The task is to generate and print all binary numbers with decimal values from 1 to N.

Example 1:

Input:
N = 2

Output: 
1 10

Explanation: 
Binary numbers from 1 to 2 are 1 and 10.

Example 2:

Input:
N = 5

Output: 
1 10 11 100 101

Explanation: 
Binary numbers from 1 to 5 are 1 , 10 , 11 , 100 and 101.

Your Task:
You only need to complete the function generate() that takes N as parameter and returns vector of strings denoting binary numbers.

Expected Time Complexity : O(N log2N)
Expected Auxilliary Space : O(N log2N)

Constraints:
1 ≤ N ≤ 10^6*/

#include<bits/stdc++.h>
using namespace std;

vector<string> generate(int N){
	// Your code here
	vector<string> v;
    queue<string> q;
    q.push("1");
    for(int i = 0; i < N; i++){
        v.push_back(q.front());
        q.push(q.front()+"0");
        q.push(q.front()+"1");
        q.pop();
    }
    return v;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<string> res = generate(N);
        for(auto it : res){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}