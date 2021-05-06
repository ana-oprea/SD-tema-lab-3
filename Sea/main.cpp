#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <vector>
using namespace std;
 
ifstream f("sea.in");
ofstream g("sea.out");
 
struct vapor
{
    double x, y, dist;
};
 
bool cmp (vapor a, vapor b)
{
    return a.x < b.x;
}
 
int main()
{
    int n, m, fni;
    double fxi, vxi, vyi;
    vector <vapor> vapoare;
 
    f >> n >> m;
 
    for(int i = 0; i < n; i++){
        f >> vxi >> vyi;
        vapoare.push_back({vxi, vyi, 0});
    }
 
    sort(vapoare.begin(), vapoare.end(), cmp);
 
 
    for(int i = 0; i < m; i++){
        f >> fxi >> fni;
 
        int j;
 
        for(j = 0; j < n && vapoare[j].x < fxi; j++)
            vapoare[j].dist = (vapoare[j].x - fxi) * (vapoare[j].x - fxi) + (vapoare[j].y) * (vapoare[j].y);
 
        int ok = 1;
 
        while(ok){
            ok = 0;
 
            for(int k = 0; k < j-1; k++)
                if(vapoare[k].dist > vapoare[k+1].dist){
                swap(vapoare[k], vapoare[k+1]);
                ok = 1;
            }
        }
 
        g << fixed << setprecision(4) << sqrt(vapoare[fni-1].dist) << "\n";
    }
    f.close();
    g.close();
    return 0;
}