#include<iostream>
#include <list>
using namespace std;
class Graph{
    int v;
    //Array of list
    list<int>*l;
    public:
    Graph(int v)
    {
        this->v=v;
        l=new list<int>[v];
    }
    void addEdge(int x,int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void print(){
        for(int i=0;i<v;i++)
        {
            cout<<i<<"->";
            for(int nbr:l[i])
            cout<<nbr<<" ";
            cout<<endl;
        }
    }

};
int main()
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(1,2);

    g.print();
    return 0;
}