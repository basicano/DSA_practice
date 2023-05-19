#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<stack>

using namespace std;

class Graph{
    list<int> *l;
    int V;

    public:
        Graph(int v){
            V = v;
            l = new list<int>[V];   // array of V linked lists
        }

        void addEdge(int i, int j, bool is_dir = false){
            l[i].push_back(j);
            if(is_dir) return;
            l[j].push_back(i);
        }

        void printAdjList(){
            for(int i=0; i<V; i++){
                cout<<" "<<i<<"--> "; 
                std::list<int>::iterator j;
                for( j=l[i].begin(); j!=l[i].end(); ++j){
                    cout<<*j<<" ";
                }
                cout<<endl;
            }
        }

        void bfs(int source){
            queue<int> q;
            q.push(source);

            vector<int> visited(V,0);
            visited[source] = 1;
            while(!q.empty()){
                int node = q.front();
                cout<<node<<" ";
                q.pop();
                std::list<int>::iterator j;
                for( j=l[node].begin(); j!=l[node].end(); ++j){
                    if(!visited[*j]){
                        q.push(*j);
                        visited[*j] = 1;
                    }
                }
            }

            return;
        }

        void dfs(int source){
            stack<int> s;
            int node;
            vector<int> v(V,0), e(V,0);
            s.push(source);
            v[source] = 1;

            while(!s.empty()){
                node = s.top();
                if(!e[node]){
                    cout<<node<<" ";
                    e[node] = 1;
                }
                
                std::list<int>::iterator j =l[node].begin();
                while(j!=l[node].end()){
                    if(!v[*j]){
                        s.push(*j);
                        v[*j] = 1;
                        break;
                    }
                    ++j;
                }
                if(j==l[node].end()){
                    s.pop();
                }

            }
        }

        void topological_ord(){
            // calculate the indegrees of all the vertices 
            vector<int> in_deg(V,0);
            for(int i =0; i< V; i++){
                std::list<int>::iterator j;
                for (j = l[i].begin(); j!=l[i].end(); ++j)
                {
                    in_deg[*j]++;
                }
                
            }

            queue<int> q;
            for(int i=0; i<V; i++){
                if(in_deg[i] == 0){
                    q.push(i);
                }
                cout<<"hi";
            }

            while(!q.empty()){
                int node = q.front();
                cout<<node<<" ";
                q.pop();
                std::list<int>::iterator i;
                for(i = l[node].begin(); i!=l[node].end(); i++){
                    in_deg[*i]--;
                }
                for(int i=0; i<V; i++){
                    if(in_deg[i] == 0){
                        q.push(i);
                    }
                }

            }

            
        }
};

int main(){
    Graph g(6);
    g.addEdge(0,1,true);
    g.addEdge(1,2,true);
    g.addEdge(2,3,true);
    g.addEdge(3,4,true);
    g.addEdge(0,5,true);
    g.addEdge(4,1,true);
    g.addEdge(5,3,true);

    // g.printAdjList();

    // cout<<endl;
    // g.bfs(0);
    // cout<<endl;
    // g.dfs(0);
    // cout<<endl;
    g.topological_ord();


    return 0;
}