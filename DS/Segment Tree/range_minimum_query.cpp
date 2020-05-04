//https://www.hackerrank.com/contests/vnr-coding-contest-final/challenges/help-harshita/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 2 * 1e6;

int n,q;
int a[maxn],st[maxn];

void build(int si,int se,int curr){
    if(si==se){
        st[curr] = a[si];
        return;
    }
    
    int left = 2*curr+1, right = 2*curr+2, mid = (si+se)/2;
    
    build(si,mid,left);
    build(mid+1,se,right);
    
    st[curr] = min(st[left],st[right]);
}

int qry(int si,int se,int curr,int l,int r){
    if(se<l or si>r){
        return INT_MAX;
    }
    if(si>=l and se<=r){
        return st[curr];
    }
    int left = 2*curr+1, right = 2*curr+2, mid = (si+se)/2;
    return min(qry(si,mid,left,l,r),qry(mid+1,se,right,l,r));
}

void upd(int si,int se,int curr,int pos,int val){
    if(si>pos or se<pos) return;
    if(si==se){
        st[curr] = val;
        return;
    }
    int left = 2*curr+1, right = 2*curr+2, mid = (si+se)/2;
    upd(si,mid,left,pos,val);
    upd(mid+1,se,right,pos,val);
    st[curr] = min(st[left],st[right]);
}

int main() {
    cin>>n>>q;
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    build(0,n-1,0);
    
    while(q--){
        int x,l,r;
        cin>>x>>l>>r;
        if(x==1){
            //a[l-1]=r;
            upd(0,n-1,0,l-1,r);
        } else cout<<qry(0,n-1,0,l-1,r-1)<<endl;
    }
    return 0;
}
/*
n q (size, queries)
array (n elements)
type left right (repeats q times)

type 1 update a[l]=r;
type 2 minimum in range [l,r]

1 based indexing

Input-
10 5
-2 3 5 1 -4 3 2 6 3 12
2 3 7
1 5 6
2 1 10
1 10 1
2 6 10

Output-
-4
-2
1

*/