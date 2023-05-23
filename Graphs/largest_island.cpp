#include<iostream>
#include<list>
#include<vector>
#include<set>
#include<queue>
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

int largest_island(vector<vector<int> > grid){
    //return the size of largest island in grid  
	
	int n = grid.size();
    int m = grid[0].size();
    int max_land = INT_MIN;
    
    for(int i=0; i<n; i++){
    	for(int j=0; j<m; j++){
    		if(grid[i][j]==1){
    			cout<<i<<","<<j<<endl;
//    			make_graph
				int result=1;
//				Graph g(m*n);
				queue<int> add_nodes_for;
				grid[i][j] = 2;
				add_nodes_for.push(i*5+j);
				while(!add_nodes_for.empty()){
					int node = add_nodes_for.front();
					add_nodes_for.pop();
					int a = node/5;
					int b = node%5;
					if(b+1<m && grid[a][b+1]==1){ 
						// right move is possible
//						g.addEdge(node, i*5+j+1);
						add_nodes_for.push(a*5+b+1);
						result++;
						grid[a][b+1] = 2;
					}
		    		if((a+1)<n && grid[a+1][b]==1){ 
						// down move is possible
//		    			g.addEdge(node, (i+1)*5+j);
						add_nodes_for.push((a+1)*5+b);
						result++;
						grid[a+1][b] = 2;
					}
					if((a-1)>=0 && grid[a-1][b]==1){ 
						// up move is possible
//						g.addEdge(node, (i-1)*5+j);
						add_nodes_for.push((a-1)*5+b);
						result++;
						grid[a-1][b] = 2;
					}
		    		if((b-1)>=0 && grid[a][b-1]==1){ 
						// left move is possible
//		    			g.addEdge(node, i*5+j-1);
						add_nodes_for.push(a*5+b-1);
						result++;
						grid[a][b-1] = 2;
					}
				}
				max_land = max(max_land, result);
			}
		}
	}
	
    return  max_land;  
}

int main(){
	vector<vector<int> > grid {
		{1, 0, 0, 1, 0},
		{1, 0, 1, 0, 0},
		{0, 0, 1, 0, 1},
		{1, 0, 1, 1, 1},
		{1, 0, 1, 1, 0}
	};
	cout<<largest_island(grid);
}
