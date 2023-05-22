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
			g[v1].push_back(v2);
			if(!directed){
				g[v2].push_back(v1);
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
		
//		improvement over bfs
		void topological(){
//			find in-degree of each vertex
			vector< int > indegree(V,0);
			for(int i=0; i<V; i++){
				for(auto v: g[i]){
					indegree[v]++;
				}
			}
			
			queue<int> q;
			for(int i=0; i<V; i++){
				if(indegree[i]==0){
					q.push(i);
				}
				
			}
			while(!q.empty()){
				int cur = q.front();
				cout<<cur<<" ";
				q.pop();				
				for(auto i: g[cur]){
					indegree[i]--;
					if(indegree[i] == 0){
						q.push(i);
					}
				}			
			}
			
			
		}
		
};
int main(){
	Graph g(5);
	g.addEdge(0,1,true);
	g.addEdge(0,2,true);
	g.addEdge(3,2,true);
	g.addEdge(1,2,true);
	g.addEdge(4,3,true);
	g.printAdjList();
	cout<<endl;
	g.topological();
}
