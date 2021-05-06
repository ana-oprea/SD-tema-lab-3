#include <fstream>
#include <unordered_set>
using namespace std;

long a, b, c, d, e, n, m, x;
int nr_melodii;
// daca pun 10001 cum cere problema imi zice time limit exceeded ????
unordered_set <long> melodii(100001);

ifstream f ("muzica.in");
ofstream g ("muzica.out");

int main(){
    f >> n >> m >> a >> b >> c >> d >> e;

    for (int i = 0; i < n; i++){
        f >> x;
        melodii.insert(x);
    }

    for (int i = 0; i < m && !melodii.empty(); i++){
        if (melodii.find(a) != melodii.end()){
            nr_melodii ++;
            melodii.erase(a);
        }
        x = (c * b + d * a) % e;
        a = b;
        b = x;
    }
    g << nr_melodii;
    return 0;
}