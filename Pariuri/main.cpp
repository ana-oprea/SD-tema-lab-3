#include <fstream>
#include <unordered_map>
using namespace std;

int n, m;
unordered_map <int, int> h;

ifstream f("pariuri.in");
ofstream g("pariuri.out");


int main(){
    f >> n;
    for (int i = 0; i < n; i++){
        f >> m;
        for (int j = 0; j < m; j++){
            int zi, suma;
            f >> zi >> suma;
            if (h.find(zi) == h.end()) // daca zi nu se gaseste in h
                h[zi] = suma;
            else
                h[zi] += suma;
        }
    }
    g << h.size() << endl;
    for (pair<int, int> elem : h) // sau cu auto
        g << elem.first << " " << elem.second << " ";
    return 0;
}