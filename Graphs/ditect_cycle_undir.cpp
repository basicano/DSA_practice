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
				for (auto i : g[v]) {
			        cout << i << " ";
			    }
				cout<<endl;
			}
		}
		
		bool ditect_cycle(){
//			assuming graph has a single component
			vector<int> parent(V,-1);
			int cur_node;
			parent[0] = 0;
			queue<int> q;
			q.push(0);
			while(!q.empty()){
				int n = q.size();
				for(int j=0; j<n; j++){
					cur_node = q.front();
					q.pop();
					for(auto i: g[cur_node]){
						
//						cout<<cur_node<<" "<<i<<" "<<parent[i]<<endl;
						if(parent[i]!=-1 && i!=parent[cur_node]){
//							nbr node is already visited and is not the parent node of cur_node
//							cout<<cur_node<<" "<<i<<endl;
							return true;
						}
						else if(parent[i]==-1){
//							nbr node is unvisited
							q.push(i);
							parent[i] = cur_node;
						}
					}
				}
			}
			
			return false;
		}
};

int main(){
	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(3,2);
	g.addEdge(1,2);
	g.addEdge(4,0);
	g.addEdge(4,2);
	g.printAdjList();
	if(g.ditect_cycle()){
		cout<<"graph has cycle"<<endl;
	}
	else{
		cout<<"graph has no cycle"<<endl;
	}
	
	Graph g2(5);
	g2.addEdge(0,1);
	g2.addEdge(1,2);
	g2.addEdge(3,4);
	g2.printAdjList();
	if(g.ditect_cycle()){
		cout<<"graph has cycle"<<endl;
	}
	else{
		cout<<"graph has no cycle"<<endl;
	}
}
