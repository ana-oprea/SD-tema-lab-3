#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

ifstream f("proc2.in");
ofstream g("proc2.out");

int s,d;
int n, m;
// in procesoare o sa retin procesoarele (in ordine crescatoare)
priority_queue<int, vector<int>, greater<int>> procesoare;
// in taskuri o sa retin pe prima pozitie s+d (crescator) si pe a doua procesorul unde am pus taskul
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> taskuri;

int main(){
    f >> n >> m;

    for (int i = 1; i <= n; i++)
        procesoare.push(i);

    for (int i = 1 ; i <= m ; i++){
        f >> s >> d;
        while (taskuri.empty() == 0 && s >= taskuri.top().first){
            procesoare.push(taskuri.top().second);
            taskuri.pop();
        }
        g << procesoare.top() << "\n";
        taskuri.push({s + d, procesoare.top()});
        procesoare.pop();
    }
    return 0;
}