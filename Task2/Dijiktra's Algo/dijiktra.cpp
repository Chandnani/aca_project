#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long double ld; 

typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;

#define _  %  MOD
#define __ %= MOD

#define      each(it,s)        for(auto it = s.begin(); it != s.end(); ++it)
#define      sortA(v)          sort(v.begin(), v.end())
#define      sortD(v)          sort(v.begin(), v.end(), greater<auto>())
#define      fill(a)           memset(a, 0, sizeof (a))

#define      rep(i, n)         for(int i = 0; i < (n); ++i)
#define      repA(i, a, n)     for(int i = a; i <= (n); ++i)
#define      repD(i, a, n)     for(int i = a; i >= (n); --i)

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define fbo find_by_order
#define ook order_of_key

std::vector<ii> v[1000];
int ans[1000][1000];
struct comp{
bool operator()(pair<ii,int> a, pair<ii,int> b) {
	return (a.fi.fi>b.fi.fi) ;
	} 
};
void Dijiktras(int s){
	priority_queue<pair<ii,int>,vector<pair<ii,int> > ,comp   > q;
	rep(i,v[s].size()){
		q.push(mp(v[s][i],s));
	}
	bool visited[1000] = {false};
	visited[s] = true;
	while(!q.empty()){
		pair<ii,int> dest = q.top();
		q.pop();
		ii d = dest.fi;
		if (visited[d.se]==true)
		{
			continue;
		}
		visited[d.se] = true;
		ans[s][d.se] = d.fi+ ans[s][dest.se];
		rep(i,v[d.se].size()){
			if (visited[v[d.se][i].se]==false)
			{
				q.push(mp(v[d.se][i],d.se));
			}
		}

	}
}

int main()
{
	cout<<"Enter 3 inetgers n,m and q where n is no vertices in map, m is no of edges and q is no of queries."<<endl;
	int n,m,q;
	cin>>n>>m>>q;
	string s[n];
	int size =0;
	cout<<"Enter m lines of  ai(string), bi(string) ,wi(integer) where each line denotes an edge between ai and bi of lenth wi"<<endl;
	rep(i,m){
		string a,b;
		cin>>a>>b;
		int c=-1,d=-1,w;cin>>w;
		rep(i,size){
			if (s[i]==a)
			{
				c=i;
			}
			else if (s[i]==b)
			{
				d=i;
			}
		}
		if (c==-1)
		{
			c = size;
			s[size] = a;
			size++;
		}
		if (d==-1)
		{
			d=size;
			s[size]=b;
			size++;
		}
		v[c].pb(mp(w,d));
		v[d].pb(mp(w,c));

	}
	rep(i,n){
		if (!v[i].empty())
		{
			sortA(v[i]);
		}
	}
	rep(i,n){
		Dijiktras(i);
	}

	rep(i,q){
		cout<<"Enter 2 strings to query shortest path between 2 locations "<<endl;
		string sour,dest;
		cin>>sour>>dest;
		int c=-1,d=-1;
		rep(j,size){
			if (s[j]==sour)
			{
				c=j;
			}
			else if (s[j]==dest)
			{
				d=j;
			}
		}
		cout<<"Smallest path from "<<sour<<" to "<<dest<<" is: "<<endl;
		while(c!=d){
			cout<<s[c]<<"---->";
			rep(j,v[c].size()){
				if (ans[c][d]==ans[c][v[c][j].se]+ans[v[c][j].se][d]||v[c][j].se==d)
				{
					c=v[c][j].se;
					break;
				}
			}
		}
		cout<<s[d]<<endl<<endl;

	}
	
	return 0;
}
