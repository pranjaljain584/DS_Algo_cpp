/*
You are given an balanced expression. 
You have to find if it contains duplicate parentheses or not. 
A set of parentheses are duplicate if same subexpression is surrounded by multiple parenthesis.
*/


#include<bits/stdc++.h>
using namespace std ;
int main() {
	int t;
	cin >> t ;
	while(t>0){
		string str ;
		cin >> str ;
		int l=str.length() ;
		bool isdup ;
		stack<char> s;
		for(int i=0 ; i<l;i++){
			s.push(str[i]) ;
			isdup = true;
			if(s.top() ==')'){
				s.pop() ;
				while(s.top() !='('){
					s.pop() ;
					isdup=false ;
				}
				if(isdup==true){
					cout << "Duplicate" << endl ;
					break;
				}
				s.pop();
			}
		}
		if(isdup==false){
			cout<< "Not Duplicates" << endl ;
		}
		t--;
	}
	return 0;
}