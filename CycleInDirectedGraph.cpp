#include<iostream>
#include<vector>
#include<list>

using namespace std;

class Graph {

int V;
list<int> *l;

public : Graph(int V) {

this->V = V;
l = new list<int> [V];

}

void addEdge(int u ,int v) {

l[u].push_back(v);

    
}

bool dfsDirectDetect(int u, vector<bool>&vis, vector<bool>&recPath) {

vis[u] = true;
recPath[u] = true;

for(int v : l[u]) {

if(!vis[v]) {

if(dfsDirectDetect(v, vis, recPath)) {
   return true;
}

}
else if(recPath[v]) {

return true;

}
   }

recPath[u] = false;
return false;
}

bool isCycle() {

vector<bool>vis(V, false);
vector<bool>recPath(V, false);

for(int i=0;i<V;i++) {

if(!vis[i]) {

if(dfsDirectDetect(i, vis, recPath)) {
    return true;
}
   }

}
   
return false;
}


   };





int main() {

Graph g(4);

g.addEdge(1,0);
g.addEdge(0,2);
g.addEdge(2,3);
// g.addEdge(3, 0);

cout<<g.isCycle()<<endl;


}