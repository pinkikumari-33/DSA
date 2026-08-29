class Solution {
public:
    void bfs(vector<vector<int>> &graph,vector<int> &vis,int src) {
        queue<int> q;

        q.push(src);
        vis[src] = 1;

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(int v = 0; v < graph[u].size(); v++) {
                if(graph[u][v] == 1 && vis[v] == 0) {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;

        int n = isConnected.size();
        vector<int> vis(n,0);

        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                count++;
                bfs(isConnected,vis,i);
                
            }
        }

        return count;
    }
};