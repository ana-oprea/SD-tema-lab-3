#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream f ("hashuri.in");
ofstream g ("hashuri.out");

const int p = 666013;
vector <int> h[p];

int hashCode(int key){
    return key % p;
}

void add(int x){
    int hashIndex = hashCode(x);
    bool ok= 1;
    for (int i = 0 ; i < h[hashIndex].size(); i++){
        if (h[hashIndex][i] == x){
            ok = 0;
            break;
        }
    }
    if (ok == 1)
        h[hashIndex].push_back(x);
}

void remove(int x){
    int hashIndex = hashCode(x);
    for (int i = 0 ; i < h[hashIndex].size(); i++){
        if (h[hashIndex][i] == x){
            h[hashIndex][i] = h[hashIndex][h[hashIndex].size() - 1];
            h[hashIndex].pop_back();
            break;
        }
    }
}

bool search(int x){
    int hashIndex = hashCode(x);
    for (int i = 0 ; i < h[hashIndex].size(); i++){
        if (h[hashIndex][i] == x)
            return 1;
    }
    return 0;
}

int main(){
    int n;
    f >> n; // nr de operatii
    int op, x;

    for (int i = 0; i < n; i++){
        f >> op;
        f >> x;
        switch (op){
            case 1: add(x); break;
            case 2: remove(x); break;
            case 3: g << search(x) << '\n'; break;
        }
        
    }


    return 0;
}
