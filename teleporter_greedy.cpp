#include <iostream>
#include <algorithm>
using namespace std;
const int N=2e5+10;
int tp[N],total_costs[N];
long long s[N];
void solve()
{
    //lungime vector si nr banuti
	int nr_teleport,money;
	cin>>nr_teleport>>money;

    //citeste costurile de teleport
	for(int i=1;i<=nr_teleport;i++)
	{
		cin>>tp[i];
        //calculeaza costul total al teleportarii
		total_costs[i]=min(i,nr_teleport+1-i)+tp[i];
	}
    
    //sorteaza masinile dupa cost
	sort(total_costs+1,total_costs+nr_teleport+1);

    //calculeaza costul teleportarii din i elemente(suma prefix)
	for(int i=1;i<=nr_teleport;i++)
	    s[i]=s[i-1]+total_costs[i];

	int ans=0;

	for(int i=1;i<=nr_teleport;i++)
	{
		if(tp[i]+i>money)
		    continue;
        //cost total i
		int t = min(i,nr_teleport+1-i)+tp[i];

        //gaseste nr maxim de tp posibile daca elementul curent e primul
		int k = upper_bound(s+1,s+nr_teleport+1,money-tp[i]-i)-s-1;

		//portalul nu este inclus in suma prefix (s[k])
		if(total_costs[k] < t)
		    ans=max(ans,k+1);
		else
        //portalul este inclus in suma
		k=upper_bound(s+1, s+nr_teleport+1, money-tp[i]-i+t)-s-1;
		ans=max(ans,k);
	}

	cout<<ans<<endl;
	return;
}
 
int main()
{
    //nr. teste
	int t;
	cin>>t;
	while(t--)
	solve();
	return 0;
}