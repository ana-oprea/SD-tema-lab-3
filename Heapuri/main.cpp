#include <fstream>
#include <set>
using namespace std;

ifstream f("heapuri.in");
ofstream g("heapuri.out");
int pos[200001];
int main(){
    set <int> heap;
    int n, cod, x, count = 0;
    f >> n;
    for (int i = 0 ; i < n; i++){
        f >> cod;
        switch(cod){
            case 1:
                f >> x;
                heap.insert(x);
                pos[++count] = x;
                break;
            case 2:
                f >> x;
                heap.erase(pos[x]);
                break;
            case 3:
                g << *heap.begin() << "\n";
        }
    }
    return 0;
}