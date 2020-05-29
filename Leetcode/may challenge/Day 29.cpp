// This problem is just basically solving if a directed graph has any cycles
// This can be done by using a recursion stack which is a list of the visited nodes
// Then if a new node points to any of the stored nodes in the stack then return false

class Solution {
public:
    list<int>* adj;
    bool isCyclicUtil(int v, bool visited[], bool recStack[]){
        if(visited[v] == false){
            visited[v] = true;
            recStack[v] = true;
            for(auto i:adj[v]){
                if(!visited[i] && isCyclicUtil(i,visited, recStack))
                    return true;
                else if(recStack[i])
                    return true;
            }
        }
        recStack[v] = false;
        return false;
    }
    bool isCyclic(int numCourses){
        bool *visited = new bool[numCourses];
        bool *recStack = new bool[numCourses];
        for(int i=0;i<numCourses;++i){
            visited[i] = false;
            recStack[i] = false;
        }
        for(int i=0;i<numCourses;++i)
            if(isCyclicUtil(i,visited,recStack))
                return true;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        adj = new list<int>[numCourses];
        for(auto i: prerequisites)
            adj[i[0]].push_back(i[1]);
        if(isCyclic(numCourses)){
            return false;
        }
        return true;
    }
};
