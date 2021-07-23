#include<iostream>
#include <list>
#include <stack>
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

    void dfs_helper(T src , map<T,bool> &visited)
    {
        cout<<src<<" ";
        visited[src]=true;
        for(auto nbr : l[src]){
            if(!visited[nbr]){
                dfs_helper(nbr,visited);
            }
        }
    }
    void dfs(T src)
    {
        cout<<"Dfs : ";
        map<T,bool>visited;
         for(auto p:l){
            visited[p.first]=false;
         }
            dfs_helper(src,visited);
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
    g.dfs(0);
    return 0;
}