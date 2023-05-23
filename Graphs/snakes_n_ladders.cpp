#include<iostream>
#include<vector>
#include<unordered_map>
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

int min_dice_throws(int n, vector<pair<int,int> > snakes, vector<pair<int,int> > ladders){
    Graph g(n+1);
    unordered_map<int,int> m_snake;
    unordered_map<int,int> m_ladder;
    
    int n_snakes = snakes.size();
    for(int i=0; i<n_snakes; i++){
    	m_snake[snakes[i].first] = snakes[i].second;
	}
	
	int n_ladders = ladders.size();
    for(int i=0; i<n_ladders; i++){
    	m_ladder[ladders[i].first] = ladders[i].second;
	}
//    add edge for all valid moves
    for(int i=1; i<=n; i++){
//    	for all vertices i
    	for(int move=1; move<=6; move++){
    		if(m_snakes.find(i+move) != m_sankes.end()){
    			g.addEdge(i,m_snakes[i+move],1);
			}
			else if(m_ladders.find(i+move) != m_ladders.end()){
				g.addEdge(i,m_ladders[i+move],1);
			}
			else{
				g.addEdge(i,i+move,1);
			}
		}
	}	
	cout<<g.dijkstra(1,n);
}

int main(){
	
}
