#include<bits/stdc++.h>
using namespace std;

vector<long long> tree;

long long f(int node,int node_low,int node_high,int query_low,int query_high){


    if(query_low<=node_low and query_high>= node_high)
{return tree[node];
    }


    if(node_high <query_low or query_high<node_low)
    {
        return 0;    }

int last_in_left =  (node_low+node_high)/2;


return f( 2*node, node_low,last_in_left,query_low,query_high)+f(2*node+1,last_in_left+1,node_high,query_low,query_high);
}

int main(){
int n,q;
cin>>n>>q;
vector<int > a(n);
for (int  i = 0; i < n; i++)
{
    cin>>a[i];
}

// pad a[] with  0 to make it
while (__builtin_popcount(n)!=1)
{
    a.push_back(0);
    n++;
}

tree.resize(2*n);

// build a tree

for ( int  i = 0; i < n ; i++)
{
    tree[n+i]=a[i];

}

for (int i = n-1; i>=1; i--)
    {
    tree[i]=tree[2*i]+tree[2*i+1];

        }

for (int  i = 0; i < q; i++)
{
    int low;
    int high;
cin>>low>>high;
low--;
high--;
cout<<f(1,0,n-1,low,high)<<"\n";

}

return 0;
}