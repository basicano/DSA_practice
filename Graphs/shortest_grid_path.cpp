#include<iostream>
#include<list>
#include<vector>
#include<set>
using namespace std;

class Graph{
	int V;
	
	list< int > *g;
	
	public:
		int *node_weights;
		Graph(int n){
			this->V = n;
			node_weights = new int[n];
			g = new list<int>[n];
		}
		
		void addEdge(int v1, int v2, bool directed=false){
			g[v1].push_back(v2);
			if(!directed){
				g[v2].push_back(v1);
			}
		}
		
		void printAdjList(){
			for(int v=0; v<V; v++){	
				cout<<v<<"("<<node_weights[v]<<") -> ";
				for (auto i : g[v]) {
			        cout << i <<" ";
			    }
				cout<<endl;
			}
		}
		
		int dijkstra(int source, int dest){
			vector<int> dist(V,INT_MAX);
			vector<int> parent(V,-1);
			
			dist[0] = node_weights[0];
			parent[source] = 0;			
//			using SET (not map as ot is ordered by key) to order by first element of pair
			set<pair<int,int> > s;
			s.insert( {node_weights[0],source} );
					
			while( !s.empty() ){
				auto cur = s.begin();
				int cur_node = cur->second;
				int dist_till_now = cur->first;
				s.erase(cur);
				
				for(auto i: g[cur_node]){
					int nbr = i;
					if(dist_till_now + node_weights[nbr] < dist[nbr]){	
						auto it = s.find({dist[nbr], nbr});
						if(it!=s.end()) s.erase(it);
						
						dist[nbr] = dist_till_now + node_weights[nbr];
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


int shortest_path(vector<vector<int> > grid){
    int n = grid.size();
    int m = grid[0].size();
    Graph g(m*n);
    
    for(int i=0; i<n; i++){
    	for(int j=0; j<m; j++){
    		int node = i*5+j;
    		g.node_weights[node] = grid[i][j];
    		if(j+1<m){ 
				// right move is possible
				g.addEdge(node, i*5+j+1);
			}
    		if((i+1)<n){ 
				// down move is possible
    			g.addEdge(node, (i+1)*5+j);
			}
			
		}
	}
	
//	g.printAdjList();
//    return 0;
    return  g.dijkstra(0,m*n-1);
    
}

int main(){
						
	vector<vector<int> > grid_vec{  {31,  100,  64, 12, 18},
									{10,   13,  47, 157, 6},
									{100, 113, 174, 11, 33},
									{88,  124,  41, 20, 140},	
									{99,  32,  111, 41, 20}   };
	
	cout<<shortest_path(grid_vec);

}
