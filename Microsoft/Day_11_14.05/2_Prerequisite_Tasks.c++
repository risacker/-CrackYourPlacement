/*There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, for example to do task 0 you have to first complete task 1, which is expressed as a pair: [0, 1]
Given the total number of tasks N and a list of prerequisite pairs P, find if it is possible to finish all tasks.

Example 1:

Input: 
N = 4, P = 3
prerequisites = {{1,0},{2,1},{3,2}}

Output:
Yes

Explanation:
To do task 1 you should have completed task 0, and to do task 2 you should have finished task 1, and to do task 3 you should have finished task 2. So it is possible.

Example 2:

Input:
N = 2, P = 2
prerequisites = {{1,0},{0,1}}

Output:
No

Explanation:
To do task 1 you should have completed task 0, and to do task 0 you should have finished task 1. So it is impossible.

Your task:
You don’t need to read input or print anything. 
Your task is to complete the function isPossible() which takes the integer N denoting the number of tasks, P denoting the number of prerequisite pairs and prerequisite as input parameters and returns true if it is possible to finish all tasks otherwise returns false. 

Expected Time Complexity: O(N + P)
Expected Auxiliary Space: O(N + P)

Constraints:
1 ≤ N ≤ 10^4
1 ≤ P ≤ 10^5
*/

#include <bits/stdc++.h>
using namespace std;

// Returns adjacency list representation from a list
// of pairs.
vector<unordered_set<int> > make_graph(int numTasks, vector<pair<int, int> >& prerequisites){
    vector<unordered_set<int> > graph(numTasks);
    for (auto pre : prerequisites)
        graph[pre.second].insert(pre.first);
    return graph;
}

// Finds in-degree of every vertex
vector<int> compute_indegree(vector<unordered_set<int> >& graph){
    vector<int> degrees(graph.size(), 0);
    for (auto neighbors : graph)
        for (int neigh : neighbors)
            degrees[neigh]++;
    return degrees;
}

bool canFinish(int numTasks, vector<pair<int, int> >& prerequisites){
    vector<unordered_set<int> > graph = make_graph(numTasks, prerequisites);
    vector<int> degrees = compute_indegree(graph);
    for (int i = 0; i < numTasks; i++) {
        int j = 0;
        for (; j < numTasks; j++)
            if (!degrees[j])
                break;
        if (j == numTasks)
            return false;
        degrees[j] = -1;
        for (int neigh : graph[j])
            degrees[neigh]--;
    }
    return true;
}

int main(){
    int numTasks = 4;
    vector<pair<int, int> > prerequisites;
    prerequisites.push_back(make_pair(1, 0));
    prerequisites.push_back(make_pair(2, 1));
    prerequisites.push_back(make_pair(3, 2));
    if (canFinish(numTasks, prerequisites)) {
        cout << "Possible to finish all tasks";
    }
    else {
        cout << "Impossible to finish all tasks";
    }
    return 0;
}