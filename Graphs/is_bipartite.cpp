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
		
		bool is_bipartite(){
			vector<char> color(V,'n');
			queue<int> q;
			q.push(0);
			char col = 'b';
			color[0] = col;
//			cout<<0<<" "<<col<<endl;
			
			while(!q.empty()){							
				if(col=='b') col = 'r';
				else col = 'b';	
				int n = q.size();			
				for(int j=0; j<n; j++){		
					int cur = q.front();
					q.pop();
					for(auto i: g[cur]){
						if(color[i] != color[cur]){
							if(color[i] =='n'){
								q.push(i);
								color[i] = col;	
//								cout<<i<<" "<<col<<endl;						
							}
						}
						else{
//							cout<<endl<<cur<<" "<<i<<endl;
							return false;
						}
					}
				}
			}
			return true;
		}
		
		void dfs_iter(int root){
			
		}
};


int main(){
	Graph g1(5);
	g1.addEdge(0,1);
	g1.addEdge(0,2);
	g1.addEdge(2,3);
	g1.addEdge(1,4);
	
	g1.printAdjList();
	
	if(g1.is_bipartite() ){
		cout<<"Graph g1 is bipartite"<<endl;
	}
	else{
		cout<<"Graph g1 is not bipartite"<<endl;
	}
	
	Graph g2(5);
	g2.addEdge(0,1);
	g2.addEdge(3,2);
	g2.addEdge(1,2);
	g2.addEdge(3,4);
	g2.addEdge(1,3);
	
	g2.printAdjList();
	
	if(g2.is_bipartite()){
		cout<<"Graph g is bipartite"<<endl;
	}
	else{
		cout<<"Graph g is not bipartite"<<endl;
	}
}
