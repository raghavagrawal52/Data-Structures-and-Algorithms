class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<vector<int>>> adj(101);
        
        for(auto f: flights) {
            int from = f[0];
            int to = f[1];
            int cost = f[2];
            
            adj[from].push_back({to, cost, 0});
        }
            
        queue<vector<int>> qu;

        qu.push({src,0,-1});
        
        int minCost = INT_MAX;

        while(!qu.empty()){
            vector<int> curr = qu.front();
            qu.pop();

            int currCity = curr[0];
            int currCost = curr[1];
            int currK = curr[2];

            if(currCity == dst){
                minCost = min(minCost, currCost);
                continue;
            }

            for(auto i: adj[currCity]){
                if(currK+1 <= K and currCost + i[1] < minCost)
                qu.push({i[0], i[1] + currCost, currK+1});
            }
                
        }
        
        return minCost == INT_MAX? -1: minCost;
    }
};
