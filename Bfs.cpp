#include<iostream>
#include <list>
#include <queue>
#include <map>
using namespace std;
template<typename T>
class Graph{
    map<T,list<T> >l;
    public:
    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void bfs(T src)
    {
        cout<<"Bfs : ";
        map<T,bool>visited;
        queue<T>q;

        q.push(src);
        visited[src]=true;
        while(!q.empty()){
            T node=q.front();
            q.pop();
            cout<<node<<" ";
            for(auto nbr:l[node]){
                if(visited[nbr]==false){
                    q.push(nbr);
                    visited[nbr]=true;
                }
                
            }
        }
    }
    void print(){
        cout<<"Graph : "<<endl;
        for(auto p =l.begin();p!=l.end();p++){
            cout<<p->first<<"->";
            for(auto nbr:p->second)
                cout<<nbr<<" ";
            cout<<endl;
        }
    }
};
int main()
{
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.print();
    g.bfs(0);
    return 0;
}