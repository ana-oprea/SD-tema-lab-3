#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

struct nr{
    int a, b, c;
};

int n, s, k = 6, ok;
int numere[101];
unordered_map <int, nr> sume;

ifstream f("loto.in");
ofstream g("loto.out");

int main(){
    f >> n >> s;
    for (int i = 0; i < n; i++)
        f >> numere[i];
    
    // fac toate sumele de 3 cifre
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            for (int k = j; k < n; k++)
                sume[numere[i] + numere[j] + numere[k]] = {numere[i], numere[j], numere[k]};

    // caut complementul de 3 cifre al sumei
    for (auto x: sume){
        // daca complementul exista in map
        if (sume.find(s-x.first) != sume.end()){
            g << sume[x.first].a << " " << sume[x.first].b << " " << sume[x.first].c << " " << sume[s-x.first].a << " " << sume[s-x.first].b << " " << sume[s-x.first].c;
            ok = 1;
            break; // iesim daca am gasit o suma
        }
    }
    if (ok == 0) g << -1;
    return 0;
}