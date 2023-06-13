#include <bits/stdc++.h> 
void sortStack(stack<int> &s)
{
	//base case
   if(s.size() == 1){
       return;
   }
   //recursive case
   int y = s.top();
   s.pop();
   sortStack(s);
   stack<int> st;
   while(!s.empty() && s.top() > y){
       st.push(s.top());
       s.pop();
   }
   s.push(y);
   while(!st.empty()){
       s.push(st.top());
       st.pop();
   }
}