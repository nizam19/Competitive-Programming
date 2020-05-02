#include<bits/stdc++.h>
using namespace std;

int n;
int a[1000],st[2000];

void buildST(int si,int se,int curr){
    if(si==se){
        st[curr]=a[si];
        return;
    }

    int left = 2*curr+1;
    int right = 2*curr+2;
    
    int mid = (si+se)/2;

    buildST(si,mid,left);
    buildST(mid+1,se,right);

    st[curr] = st[left]+st[right]; 
}

int qry(int si,int se,int curr,int l,int r){
    int left = 2*curr+1;
    int right = 2*curr+2;

    int mid = (si+se)/2;

    if(si>=l and se<=r)     //fully inside
        return st[curr];
    else if(se<l or si>r)   //outside
        return 0;
    else                    //partially inside
        return qry(si,mid,left,l,r) + qry(mid+1,se,right,l,r);
}

void upd(int si,int se,int curr,int pos,int diff){
    if(si>pos or se<pos) return;

    st[curr]+=diff;
    
    if(si!=se){
        int left = 2*curr+1;
        int right = 2*curr+2;

        int mid = (si+se)/2;
        
        upd(si,mid,left,pos,diff);
        upd(mid+1,se,right,pos,diff);
    }
}

int main(){
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }


    buildST(0,n-1,0);

    cout<<"Segment tree:-"<<endl;
    for(int i=0;i<2*n;i++) cout<<i<<" "<<st[i]<<endl;

    cout<<endl;

    cout<<"Query 1 3 = "<<qry(0,n-1,0,1,3)<<endl;

    cout<<"Update a[2] = 10"<<endl;

    upd(0,n-1,0,2,10-a[2]);
    a[2] = 10;
    

    cout<<"Query 1 3 = "<<qry(0,n-1,0,1,3)<<endl;

    return 0;
}

/*

8
1 2 3 4 5 6 7 8

*/