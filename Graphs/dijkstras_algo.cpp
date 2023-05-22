#include<iostream>
#include<list>
#include<vector>
#include<set>
using namespace std;

class Graph{
	int V;
	list< pair<int,int> > *g;
	
	public:
		Graph(int n){
			this->V = n;
			g = new list< pair<int,int> >[n];
		}
		
		void addEdge(int v1, int v2, int weight, bool directed=false){
			g[v1].push_back({v2,weight});
			if(!directed){
				g[v2].push_back({v1,weight});
			}
		}
		
//		void removeEdge(int v1, int v2, bool directed=false){
//			g[v1].remove(v2);
//			if(!directed){
//				g[v2].remove(v1);
//			}
//		}
		
		void printAdjList(){
			for(int v=0; v<V; v++){	
			cout<<v<<" -> ";
				for (auto i : g[v]) {
			        cout << i.first <<"("<<i.second<<") ";
			    }
				cout<<endl;
			}
		}
		
		int dijkstra(int source, int dest){
			vector<int> dist(V,INT_MAX);
			vector<int> parent(V,-1);
			dist[0] = 0;
			parent[source] = 0;
			
//			using SET (not map as ot is ordered by key) to order by first element of pair
			set<pair<int,int> > s;
			
			s.insert({0,source});
					
			while(!s.empty()){
				auto cur = s.begin();
				int cur_node = cur->second;
				int dist_till_now = cur->first;
				s.erase(cur);
				
				for(auto i: g[cur_node]){
					int nbr = i.first;
					int nbr_e = i.second;
					if(dist_till_now + nbr_e < dist[nbr]){	
						auto it = s.find({dist[nbr], nbr});
						if(it!=s.end()) s.erase(it);
						
						dist[nbr] = dist_till_now + nbr_e ;
						parent[nbr] = cur_node;
						s.insert({dist[nbr], nbr});
					}
				}
			}
			cout<<"distances"<<endl;
			for(int i=0; i<V; i++){
				cout<<source<<" to "<<i<<": "<<dist[i]<<endl;
			}
			
			return dist[dest];
		}
		
};
int main(){
	Graph g(5);
	g.addEdge(0,1,1);
	g.addEdge(1,2,1);
	g.addEdge(0,2,4);
	g.addEdge(0,3,7);
	g.addEdge(3,2,2);
	g.addEdge(3,4,3);
	g.printAdjList();
	cout<<endl<<g.dijkstra(0,4)<<endl;
}
