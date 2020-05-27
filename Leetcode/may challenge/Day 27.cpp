// This problem is based on a bipartite graph
// we assign colors to each of the nodes in the graph
// if all the neighbors of a node had the other color than the node
// then we can say that it is a bipartite graph

class Solution
{
public:
    bool possibleBipartition(int N, vector<vector<int>> &dislikes)
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<int> adj[N + 1];

        for (auto dislike : dislikes)
        {
            adj[dislike[0]].push_back(dislike[1]);
            adj[dislike[1]].push_back(dislike[0]);
        }

        vector<int> color(N + 1, 0);

        function<bool(int, int)> dfs = [&](int cur, int col) {
            if (color[cur] != 0)
                return color[cur] == col;
            color[cur] = col;
            for (auto next : adj[cur])
                if (!dfs(next, -col))
                    return false;
            return true;
        };

        for (int i = 0; i < N; ++i)
        {
            if (color[i] == 0 && !dfs(i, 1))
                return false;
        }
        return true;
    }
};