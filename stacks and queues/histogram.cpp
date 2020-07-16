/*

Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars.


Input Format
First line contains a single integer N, denoting the number of bars in th histogram.
Next line contains N integers, ith of which, denotes the height of ith bar in the histogram.

Constraints
1<=N<=10^6
Height of each bar in histogram <= 10^9

Output Format
Output a single integer denoting the area of the required rectangle.

Sample Input
5
1 2 3 4 5
Sample Output
9
Explanation
The largest rectangle can be obtained of breadth=3 and length=3. Its starting index is 2 and ending index is 4 and it has a height of 3. Hence area = 3*3 = 9

*/



#include<bits/stdc++.h>
using namespace std ;

long long int histogram(long long int*arr , long long int n ){
    long long int ansarr[1000000] ={0} ;
	stack<int> s;
	s.push(0) ;
	long long int i ,j ;
	for(i=1, j=0 ; i<=n ; i++){
		if( arr[s.top()] < arr[i] ){
			s.push(i) ;
		}else{
			while( !s.empty() && arr[s.top()] > arr[i] ){
				long long int currtop = arr[s.top()] ;
				s.pop() ;
				if(s.empty()){
					ansarr[j] = currtop*i ;
					j++;
				}else{
					ansarr[j] = currtop*(i-s.top()-1) ;
					j++;
				}
			}
			s.push(i) ;
		}
	}
	while(s.empty()== false){
            long long int currtop = arr[s.top()] ;
				s.pop() ;
				if(s.empty()){
					ansarr[j] = currtop*i ;
					j++;
				}else{
					ansarr[j] = currtop*(i-s.top()-1) ;
					j++;
				}
	}
	long long int maxel= INT_MIN ;
	for(long long int i=0 ; i<n ;i++){
		if(ansarr[i] > maxel){
			maxel=ansarr[i] ;
		}
	}
	return maxel ;
}

int main(){
	long long int n ;
	cin >> n ;
	long long int arr[1000000];
	for(long long int i=0 ; i<n  ; i++){
		cin >> arr[i] ;
	}
	long long int maxel = histogram(arr,n) ;
	cout << maxel << endl ;
	return 0;
}