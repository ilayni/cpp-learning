
#include <map>
#include <set>
#include<iostream>


using namespace std; 

class myGraph
{
    map<int,set<int>> connections;
    set<int> visited;
    set<int> toVisit;

    public:
    void connect(int a, int b)
    {
        connections[a].insert(b);
         connections[b].insert(a);
    }

    bool isConnected(int a, int b)
    {
        bool ret = false;
        set<int>::iterator it;
        toVisit.insert(a);
        while(!toVisit.empty())
        {
            it = toVisit.begin();
            int cur = *it;
            toVisit.erase(*it); 
            visited.insert(cur);
            set<int> curConns = connections[cur];
            for(auto i: curConns)
            {
                if(i==b)
                {
                    ret = true;
                    cout<<"connected\n";
                    break;
                }
                else
                {
                    visited.insert(i);
                    set<int> curConns1 = connections[i];
                    for(auto i: curConns1)
                    {
                        if(!visited.count(i))
                            toVisit.insert(i);
                    }

                }
            }
            for(int i:visited)
                cout<<" visited: "<< i;
            cout<<endl;
            for(int i:toVisit)
            {
                cout<<" toVisit: "<<i;
            }
            cout<<endl;
        }
        if(visited.count(b))
            ret= true;
        return ret;

    }
    
};



int main()
{
    myGraph g;
    bool isConnected;
    g.connect(1,2);
    g.connect(3,4);
    g.connect(1,4);
    //g.connect(3,4);
    //g.connect(1,4);
    isConnected = g.isConnected(1,3);
    if(isConnected)
        cout<<"connected\n";
    else   
        cout<<"not connectd\n";
}

