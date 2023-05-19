#include<iostream>
using namespace std;

// class minHeap{
//     vector<int> h;
//     public:
//         Heap(){

//         }

//         void construct_heap(vector<int> v){
            
//         }

//         void insert_key(int key){
//             h.push_back(key);
//             int child_idx = h.size()-1;
//             int parent_idx = child_idx/2;
//             while(parent_idx>=0 && h[parent_idx] > h[child_idx]){
//                 swap(v[parent_idx], v[child_idx]);
//                 child_idx = parent_idx;
//                 parent_idx = child_idx/2;
//             }
//         }

//         void heapify(int parent_idx){
//             int child_idx1 = parent*2;
//             int child_idx2 = child_idx1 +1;
//             int min_idx = child_idx1;
//             if(v[min_idx] > v[child_idx2]){
//                 min_idx = child_idx2;
//             }
//             if(v[parent_idx] > v[child_idx2]){
//                 swap( v[parent_idx], v[min_idx]);
//                 heapify(min_idx);
//             } 
//         }

//         void update_key(int key){

//         }

// };

class Graph{
    list< pair<int,int> > *l;
    int V;
    public:
        Graph(int v){
            V=v;
            l = new list< pair<int,int> >[v];
        }

        void addEdge(int i, int j, int weight){
            l[i].push_back({j,weight});
            // if(!is_dir) return;
            // l[j].push_back(i);
        }

        int dijkstra_ssp(int source, int dest){
            vector<int> dist(V,INT_MAX);
            vector<bool> explored(V,false);
            vector<int> parent(V,0);
            // priority_queue<int> q;
            
            int curr = source;
            // vector<int> v;
            // v.insert(v.end(),source);
            dist[curr]  = 0;
            explored[curr] = true;
            parent[curr] = 0;
            while(true){
                bool find = true;;
                for(int i=0; i<V; i++){
                    if(find && !explored[i] ){
                        // first unexplored
                        find = false;
                        curr = i;
                    }
                    else if(!expolred[i] && dist[curr] > dist[i]){
                        //  min dist unexplored
                        curr =i;
                    }

                }

                explored[curr] = true;
                if(curr == dest){
                    return dist[curr];
                }

                std::list< pair<int,int> >::iterator i;
                for(int i=l[curr].begin(); i != l[curr].end(); i++){
                    int n_node = *i.first, n_w = *i.second;

                    if( dist[n_node] > dist[curr] +n_w ){
                        // update shortest distance and parent 
                        dist[n_node] = dist[curr] +n_w;
                        parent[n_node] = curr;
                    }
                }
            }
        }

};

int main(){

}