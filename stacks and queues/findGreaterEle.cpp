/*
We are given a circular array, print the next greater number for every element. 
If it is not found print -1 for that number. 
To find the next greater number for element Ai , 
start from index i + 1 and go uptil the last index after which we start looking for the 
greater number from the starting index of the array since array is circular
*/



#include<bits/stdc++.h>
using namespace std ;

int main() {
	int n ;
	cin >> n ;
	deque<int> dq ;
	for(int i=0 ; i<n ;i++){
		int d ;
		cin >> d;
		dq.push_back(d) ;
	}
	queue<int> ansq ;
	for(int i=0 ;i<n ;){
		int curr = dq.front() ;
		dq.push_back(curr) ;
		dq.pop_front() ;
		int count=1 ;
		if(dq.front() > curr){
			ansq.push(dq.front()) ;
			i++;
		}else{
			bool isequal = false ;
			while(dq.front() <= curr){
				if(dq.front()==curr){
					ansq.push(-1) ;
					i++ ;
					isequal = true ;
					dq.pop_front() ;
					break ;
				}
				count++ ;
				dq.push_back(dq.front()) ;
				dq.pop_front();
			}
			//cout << "front of " << i << " " << dq.front() <<endl ;
			while(isequal==false && count>=1){
				ansq.push(dq.front());
				i++;
				count-- ;
			}
		}
	}
	while(!ansq.empty()){
		cout<< ansq.front() <<" " ;
		ansq.pop() ;
	}
	/*for(int i=0 ; i<n ;i++){
		int curr = dq.front() ;
		dq.push_back(curr) ;
		dq.pop_front() ;
		int count=1 ;
		if(dq.front() > curr){
			cout << dq.front() <<" ";
		}else if((i==0 || i==n-1) && dq.front() < curr){
			cout << "-1" <<" " ;
			i++;
		}
		else{
			while(dq.front() < curr){
				count++ ;
				i++;
				dq.push_back(dq.front()) ;
				dq.pop_front();
			}
			while(co+unt>=1){
				cout << dq.front() <<" ";
				count-- ;
			}
		}
	}*/
	return 0;
}