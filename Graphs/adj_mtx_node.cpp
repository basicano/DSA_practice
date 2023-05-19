#include<iostream>
#include<string>
#include<list>
#include<unordered_map>
using namespace std;

class Node{
    private:
        string name;
        list<string> nbrs;
    public:
        Node(string name){
            this->name = name;
        }
};

class Graph{
    unordered_map<string,Node*> g;


    public:
        Graph(vector<string> str){
            int n = str.size();
            for(int i=0; i<n; i++){
                m[str[i]] = new Node(str[i]);
            }
        }

        void addEdge(string x, string y, bool undir=false){
            g[x]->nbrs.push_back(y);
            if(undir){
                g[y]->nbrs.push_back(x);
            }
        }

        void printGraph(){
            pair<string, Node*> p;
            for(p = g.begin(); p != g.end(); p++){
                cout<<p.first<<" --> ";
                std::list<string>::iterator j;
                for(j=p.second.begin(); j != p.second.end(); j++){
                    cout<<*j<<" ";
                }
            }
        }
};

int main(){
    vector<string> str{"Delhi","London","Mumbai"};
    Graph g();
    g.addEdge("Delhi","London");
    g.addEdge("London","Mumbai");
    // g.addEdge(2,3);
    // g.addEdge(3,4);
    // g.addEdge(0,5);
    // g.addEdge(4,1);
    // g.addEdge(5,3);

    g.printGraph();

    return 0;
}
