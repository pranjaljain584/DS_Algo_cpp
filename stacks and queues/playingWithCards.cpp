/*
You are at a casino. There are N stacked cards on pile .
Each card has a number written on it. Then there will be Q iterations. 
In ith iteration, you start picking up the cards in Ai-1th pile from the top one by one and 
check whether the number written on the card is divisible by the ith prime number. 
If the number is divisible, you stack that card on pile Bi. 
Otherwise, you stack that card on pile Ai. After Q iterations, 
cards can only be on pile B1, B2, B3, . . . BQ, AQ . 
Output numbers on these cards from top to bottom of each piles in order of B1, B2, B3, . . . BQ, AQ .
*/




#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void prime_seive(ll *p,ll N ){
    
   p[1]=p[0] = 0 ;
    p[2]=1;
    
    for(ll i=3 ;i<=N ;i+=2){
        p[i] = 1 ;
    }

    for(ll i=3 ;i<=N ; i+=2){
        if(p[i]==1){
            for(ll j=i*i ; j<=N ; j=j+2*i){
                p[j]=0;
            }
        }
    }
   
	return ;
}
void playing_with_cards (stack<int> s , int q ,int &i ,long long int*parr ){
    if(q==0){
		while(!s.empty()){
        cout<< s.top() << endl ;
        s.pop();
    }
        return ;
    }
    stack<int> a ;
    stack<int> b ;
    int prime = parr[i] ;
    while(!s.empty()){
        if(s.top()%prime ==0 ){
            b.push(s.top());
            s.pop() ;
        }else{
            a.push(s.top());
            s.pop() ;
        }
    }
    while(!b.empty()){
        cout<< b.top() << endl ;
        b.pop();
    }
    i++;
	q--;
    playing_with_cards(a,q,i,parr) ;
}
int main() {
    int N=100000;
	ll p[N] = {0} ;
    prime_seive(p,N) ;
	long long int parr[N] = {0} ;
	for(long long int i=1 ,k=1 ; i<=100000 && k<=100000 ; i++){
		if(p[i]==1){
			parr[k]=i ;
			k++ ;
		}
	}
	int n , q;
	cin >> n ;
	cin >> q ;
	stack<int> s ;
	for(int i=0 ; i<n ; i++){
        int data ;
        cin >> data ;
        s.push(data) ;
	}
	int i=1 ;
	playing_with_cards(s,q ,i, parr) ;
	return 0;
}