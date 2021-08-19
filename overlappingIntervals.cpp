#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>

using namespace std;

int main()
{
    vector<pair<int,int>> start;
    vector<pair<int,int>> end;
    stack<pair<int,int>> curIntervals;

    int startTime = 0;
    int maxEmployee = 0;

    //the time intervals are: 1-5 with 3 empolyess, 3-7 with 4, 11-17 with 3, 15-20 with 2 and 35-40 with 7
    // it is needed to calculate the maximum amount of employess needed in any interval
    // 3-5 would need 7 employees
    // 15-17 4 employees 
    //35- 40 7 employees
    start.push_back({1,3});
    start.push_back({3,4});
    start.push_back({15,2});
    start.push_back({11,3});
    start.push_back({35,7});

    end.push_back({5,3});
    end.push_back({7,4});
    end.push_back({20,2});
    end.push_back({17,3});
    end.push_back({40,7});
    //sort start and end times 
    sort(start.begin(),start.end());
    sort(end.begin(),end.end());

    for(auto i: start)
    {
        //cout<< i.first << i.second << endl;
    }

    int i,j=0;
    for(i=0;i<end.size();i++)
    {
        cout<<"end[i].first " << end[i].first << endl;
        //go over according to ending times
        while(start[j].first<end[i].first && j<end.size() )
        {
            cout<<"start[i].first " << start[j].first << endl;
            startTime = start[j].first;
            maxEmployee+=start[j].second;
            curIntervals.push(start[i]) ;
            j++;
        }
       // else // closing an interval,
        {
            pair<int,int> temp;
            cout<<"strat time " << startTime <<endl;
            cout<<"max before " << maxEmployee << endl;
            temp = curIntervals.top();
            curIntervals.pop();
            maxEmployee-=end[i].second;
         /*    for(int l=0;l<=i;l++) 
            {          
               if(end[j].first>end[l].first)
               {
                    cout<< "end[j].first" << end[j].first <<"end[l].first" <<end[l].first << endl;
                    maxEmployee-=start[l].second;
               }
            } */
            cout<<"max after " << maxEmployee << endl;
            
        }
    }



}