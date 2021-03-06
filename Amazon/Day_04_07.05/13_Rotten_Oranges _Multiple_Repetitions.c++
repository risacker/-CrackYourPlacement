/*You are given an m x n grid where each cell can have one of three values:

   0 representing an empty cell,
   1 representing a fresh orange, or
   2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Example 1:

Input: grid = [[2,1,1],[1,1,0],[0,1,1]]

Output: 4

Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]

Output: -1

Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

Example 3:

Input: grid = [[0,2]]

Output: 0

Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 
Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<int> q;
        int fresh = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 2) 
                    q.push(i*100 + j);
                else if(grid[i][j] == 1)
                    fresh++;
            }   
        } 
        int time = 0;
        vector<int> dir = {-1,0,1,0,-1};
        while(q.size() && fresh){
            int size = q.size();
            time++;
            while(size--){
                int index = q.front();
                q.pop();
                int x = index/100, y = index%100;
                for(int k = 0;k < 4;k++){
                    int i = x + dir[k], j = y + dir[k+1];
                    if(i < 0 || j < 0 || i == m || j == n || grid[i][j] != 1) 
                        continue;
                    grid[i][j] = 2;
                    q.push(i*100 + j);
                    fresh--;
                }
            }
        }
        if(fresh) return -1;
        return time;
    }
};