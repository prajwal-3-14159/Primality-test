#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <cmath>


using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef unsigned long ul;

typedef vector<ll> vec;
typedef vector<char> vec_c;
typedef vector<ld> vecd;

map<ul, char> Primes;

bool is_prime(ul p)
{
    if (Primes[p] ==  'y'){
        return true;
    }
    if (Primes[p] == 'n'){
        return false;
    }

    else{
    if (p <= 1){
        Primes[p] = 'n';
        return false;
    }
    if (p <= 3){
        Primes[p] = 'y';
        return true;
    }
    if (p % 2 == 0 || p % 3 == 0)
    {
        Primes[p] = 'n';
        return false;
    }
    ul root_p = sqrt(p);
    for (int i = 5; i <= root_p; i = i + 6)
    {
        if (p % i == 0 || p % (i + 2) == 0)
        {
            Primes[p] = 'n';
            return false;
        }
    }
    Primes[p] = 'y';
    return true;
    }
}

int main()
{
    for (int i=0; i<100; i++){
        if (is_prime(i) == true){
            cout << i << "\n";
        }
        if (is_prime(100-i) == true){
            cout << 100-i << "\n";
        }

    }  
    cout << 97 << "->" << Primes[97] <<"\n";
    cout << 21 << "->" << Primes[21] << "\n";
    return 0;
}
