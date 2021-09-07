#include<iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;
class Graph{
    vector<vector<int>>v;
    public:
    Graph(int x)
    {
        vector<vector<int>>temp(x);
        v=temp;
    }
    void addEdge(int x,int y){
        v[x].push_back(y);
    }
    bool cheak(int i,vector<bool>visited)
    {
        if(visited[i]==true)
        return true;
        visited[i]=true;
        for(int j=0;j<v[i].size();j++)
        {
            if(cheak(v[i][j],visited))
                return true;
        }
        return false;
    }
    string is_cycle()
    {
        vector<bool>visited(v.size(),false);
        bool flag=false;
        for(int i=0;i<v.size();i++)
        {
            visited[i]=true;
            for(int j=0;j<v[i].size();j++)
            {
                if(cheak(v[i][j],visited))
                {
                    return "Yes";
                }
            }
            visited[i]=false;
        }
        return "No";
    }
    void print()
    {
        for(int i=0;i<v.size();i++)
        {
            cout<<i<<" -> ";
            for(int j=0;j<v[i].size();j++)
            cout<<v[i][j]<<" ";
            cout<<endl;
        }
    }
};
int main()
{
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,1);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,0);

    g.print();
    cout<<g.is_cycle();
    return 0;
}