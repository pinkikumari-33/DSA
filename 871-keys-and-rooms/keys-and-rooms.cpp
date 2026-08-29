class Solution {
public:
    void dfs(vector<vector<int>> &rooms,vector<bool> &vis,int s) {
        vis[s] = true;

        for(int i : rooms[s]) {
            if(vis[i] == 0) {
                dfs(rooms,vis,i);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> vis(rooms.size(),0);

        dfs(rooms,vis,0);

        for(bool i : vis) {
            if(i == 0) return false;
        }

        return true;
    }
};