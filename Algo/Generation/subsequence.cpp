#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	
	string s;
	cin>>s;
	
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				cout<<s[j];
			}
		}
		cout<<endl;
	}
	
	return 0;

}
/*
5
abcde
*/
