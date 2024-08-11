#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>
#include<vector>

using namespace std;

class Graph{
    private:
    unordered_map<int,list<int>> adjList;
    bool is_directed; //to manage if graph is undirected or directed

    void dfs(int v,vector<bool> &visited){
        // this is a helper method
        cout<<v<<" ";
        // beacuse we not set visited v to true thats wy 2 is printing 2 times
        visited[v]=true;
        // first print the value then go for next neighbour 
        for(int i:adjList[v]){
            if(!visited[i]){
                visited[i]=true; //set the value to visited
                // also now recursively do DFS traversal of that node or vertex
                dfs(i,visited);
            }
        }
    }
    
    public:

    void addEdge(int u,int v){
        adjList[u].push_back(v);
        // but if graph is undirected so make reverse link also
        if(!is_directed){
            adjList[v].push_back(u);
        }
    }
    // now lets make a remove edge method

    void removeEdge(int u,int v){
        adjList[u].remove(v);
        if(!is_directed){
            // if graph is undirected remove reverse link also
            adjList[v].remove(u);
        }
    }

    // now lets make a vertexCount method

    int vertexCount(){
        // this method will return how many vertex are there 
        return adjList.size();
    }

    // also make a neighbors method which will return all the neighbour of a particular vertex
    list<int> neighbors(int vertex){
        return adjList[vertex]; //so it will return the list associated with the vertex
    }

    // now make a bfs traversal method
    void bfs(int start){
        // we need queue for BFS traversal 
        // also need a vector or array to store visited nodes status
        vector<bool> visited(vertexCount(),false); //initially set all the visited nodes to false
        queue<int> Q;
        Q.push(start);
        visited[start]=true; 

        // now until queue is empty run a loop
        while(!Q.empty()){
            // first dequeue and print
            int v=Q.front();
            cout<<v<<" ";
            Q.pop(); //remove front element from the queue

            // now we need to enque all the neighbour node or values
            for(auto i:adjList[v]){
                if(!visited[i]){
                    // if i node is not visited already
                    visited[i]=true;
                    Q.push(i);
                }
                // now this will fill the queuewith all the neighbors
            }

        }

    }

    // lets make a public method that user will call
    void dfs(int start){
        vector<bool> visited(vertexCount(),false); 

        dfs(start,visited); //refrence will be passed so only one vector is used for whole dfs 
    }
};

int main(){
    Graph g;
    g.addEdge(2,0);
    g.addEdge(2,4);
    g.addEdge(2,5);
    g.addEdge(2,5);
    g.addEdge(3,5);
    g.addEdge(3,6);
    g.addEdge(6,8);
    g.addEdge(8,0);


    // now lets  traverse
    g.bfs(2);
    cout<<endl;
    for(int i:g.neighbors(2)){
        cout<<i<<" ";
    }
    // now also make a DFS method
    cout<<endl;
    
    g.dfs(2);
    return 0;
    //thanks for watching full code link in description
}