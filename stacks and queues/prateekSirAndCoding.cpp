#include<bits/stdc++.h>
using namespace std ;
int main () {
	int q;
	cin >> q ;
	stack<pair<int, int> > s; 
	for(int i=0 ; i<q ;i++){
		int d ,price;
		cin >> d ;
		if(d==2){
			cin >> price ;
			s.push(make_pair(d,price)) ;
		}else if(d==1){
			if(s.empty()){
				cout << "No Code" <<endl;
			}else{
				cout << s.top().second << endl ;
				s.pop() ;
			}
		}
	}

	return 0;
}