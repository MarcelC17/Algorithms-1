#include <bits/stdc++.h>
using namespace std;

//dimensiunea permutatiei
int n;

//lungimea maxima a permutatiei
const int MAX = 101;
vector<int> v(MAX), ans(MAX);
 
 
void find_depth(int l, int r, int cur){

    //cazul de baza 1 element
    if(l == r){
        ans[l] = cur;
        return;
    }

    //gaseste elementul maxim
    pair<int, int> index_elem = {-1, 0};
    for(int i = l; i<=r; i++)
        if(v[i] > index_elem.second) index_elem = {i, v[i]};
    
    ans[index_elem.first] = cur;

    //parcurge elementele la stanga
    if(index_elem.first > 0 && v[index_elem.first-1] < v[index_elem.first])
        find_depth(l, index_elem.first-1, cur+1);
    
    //parcurge elementele la dreapta
    if(index_elem.first < n-1 && v[index_elem.first] > v[index_elem.first+1])
        find_depth(index_elem.first+1, r, cur+1);
}
 
 
int main()
{
    //nr. de cazuri testate
    int nr_test;
    cin >> nr_test;

    //citeste pentru fiecare caz si afiseaza raspunsul
    while(nr_test--){
        //citeste dimensiunea permutarii si elementele acesteia
        cin >> n;
        for(int i = 0; i<n; i++)
            cin >> v[i];

        find_depth(0, n-1, 0);

        //afiseaza raspunsul
        cout << ans[0];
        for(int i = 1; i<n; i++)
            cout << " " << ans[i];
        cout << '\n';
    }

    return 0;
}