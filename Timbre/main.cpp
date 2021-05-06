#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair<int,int>> timbre;
priority_queue <int> optiuni;
int n, m, k, mini, cheie, margine, cost;
long long suma;
int interval;
ifstream f("timbre.in");
ofstream g("timbre.out");

int main(){
    f >> n >> m >> k;
    for (int i = 0; i < m; i++){
        f >> margine >> cost;
        timbre.push_back({margine, cost});
    }

    sort(timbre.begin(), timbre.end()); // lesortez crescator dupa margine
    interval = m - 1;
    
    while (n > 0){
        
        while(interval >= 0 && n <= timbre[interval].first){
            optiuni.push(-timbre[interval].second);
            interval--;
        }
        n -= k;
        suma = suma + (-1)*optiuni.top();
        optiuni.pop();
    }
    
    g << suma;

    return 0;    
}