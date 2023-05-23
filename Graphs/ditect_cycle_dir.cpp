#include<iostream>
#include<list>
#include<unordered_map>
#include<stack>
#include<vector>
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
		
		bool ditect_cycle_dir(){
			unordered_map<int,bool> in_stack;
			vector<bool> visited(V,false);
			
			for(int i=0; i<V; i++){
				in_stack[i] = false;
			}
			
			int cur_node;
			stack<int> s;
			s.push(0);
			in_stack[0] = true;
			visited[0] = true;
			while(!s.empty()){
				cur_node = s.top();
				bool all_explored = true;
				for(auto i: g[cur_node]){
//					cout<<cur_node<<" "<<i<<" "<<visited[i]<<endl;
					if(!visited[i]){
						s.push(i);
						visited[i] = true;
						in_stack[i] = true;
						all_explored = false;
						break;
					}
					else if(in_stack[i]){
//						cout<<cur_node<<" "<<i<<endl;
						return true;
					}
				}
				if(all_explored){
//				FORGOT to check if all nodes have been explored, only then pop
					s.pop();
					in_stack[cur_node] = false;	
				}						
			}			
			return false;
		}
};

int main(){
	Graph g(5);
	g.addEdge(0,1,true);
	g.addEdge(1,2,true);
	g.addEdge(2,3,true);
	g.addEdge(2,4,true);
	g.addEdge(4,0,true);
	g.printAdjList();
	if(g.ditect_cycle_dir()){
		cout<<" grapg has cycle"<<endl;
	}
	else{
		cout<<" graph has no cycle"<<endl;
	}
	
	Graph g2(5);
	g2.addEdge(0,1,true);
	g2.addEdge(1,2,true);
	g2.addEdge(2,3,true);
	g2.addEdge(3,4,true);
	g2.printAdjList();
	if(g2.ditect_cycle_dir()){
		cout<<" graph has cycle"<<endl;
	}
	else{
		cout<<" graph has no cycle"<<endl;
	}
}
