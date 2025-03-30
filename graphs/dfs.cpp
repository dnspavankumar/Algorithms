//maintain the list of all visited nodes
vector<bool> visited;
// the visited array is uninitialised the size is to be intialised
//the size is unknown at this point 
// so we should initialize size and array to false later in the program where the size of adjacency list is unknown
vector<int> dfsHelper(int starting_node, vector<vector<int>>& adj) {
  //mark starting node as visited
    visited[starting_node] = true;
  //we need to return the answer as a vector
    vector<int> ans;
  // starting node is added to the answer
    ans.push_back(starting_node); 
 // visit all the neighbours of starting node
    for (int i = 0; i < adj[starting_node].size(); i++) {
        int neighbor = adj[starting_node][i];
        if (!visited[neighbor]) {
            vector<int> temp = dfsHelper(neighbor, adj);
            for (int j = 0; j < temp.size(); j++) {
                ans.push_back(temp[j]); 
            }
        }
    }
    return ans; 
}

vector<int> dfs(vector<vector<int>>& adj) {
    int n = adj.size();  
    visited.resize(n, false);  
    return dfsHelper(0, adj);
}
