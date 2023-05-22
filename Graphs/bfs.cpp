#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;

class Graph{
	int V;
	list<int> *g;
	
	public:
		Graph(int n){
			this->V = n;
			g = new list<int>[n];
		}
		
		void addEdge(int v1, int v2, bool directed=false){
			g[v1].push_front(v2);
			if(!directed){
				g[v2].push_front(v1);
			}
		}
		
		void removeEdge(int v1, int v2, bool directed=false){
			g[v1].remove(v2);
			if(!directed){
				g[v2].remove(v1);
			}
		}
		
		void printAdjList(){
			for(int v=0; v<V; v++){	
			cout<<v<<" -> ";
				for(auto it=g[v].begin(); it != g[v].end(); it++){
					cout<<*it<<"  ";
				}
//				for (auto i : g[v]) {
//			        cout << i << " ";
//			    }
				cout<<endl;
			}
		}
		
		void bfs(int root){
			vector<bool> visited(V,0);
			queue<int> q;
			q.push(root);
			visited[root] = 1;
			while(!q.empty()){
				int cur = q.front();
				q.pop();
				cout<<cur<<" ";
				
				for(auto i: g[cur]){
					if(!visited[i]){
						q.push(i);
						visited[i] = 1;
					}
				}			
			}
		}
		
};


int main(){
	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(3,2);
	g.addEdge(1,2);
	g.addEdge(3,4);
	g.bfs(3);
}
