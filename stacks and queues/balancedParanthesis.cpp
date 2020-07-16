/*You are given a string of brackets i.e. '{', '}' , '(' , ')', '[' , ']' . 
You have to check whether the sequence of parenthesis is balanced or not.
For example, "(())", "(())()" are balanced and "())(", "(()))" are not.
*/


#include<bits/stdc++.h>
using namespace std;

bool isbalanced(string str){
	stack<char> st ;
	for(int i=0 ;i<str.length() ; i++){
		if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
			st.push(str[i]) ;
		}else if(!st.empty() && str[i] == ')' ){
			if(st.top()=='('){
				st.pop();
			}else{
				return false ;
			}
		}else if(!st.empty() && str[i] == ']'){
			if(st.top()=='['){
				st.pop();
			}else{
				return false ;
			}
		}else if(!st.empty() && str[i] == '}'){
			if(st.top()=='{'){
				st.pop();
			}else{
				return false ;
			}
		}
	}
	return st.empty() ;
}

int main() {

	string str ;
	cin >> str ;
	if(isbalanced(str)){
		cout << "Yes" << endl ;
	}else{
		cout << "No" << endl ;
	}
	return 0;
}