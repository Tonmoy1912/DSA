/*For a given expression in the form of a string, find if there exist any redundant brackets or not.
 It is given that the expression contains only rounded brackets or parenthesis and the input expression will always be balanced.
A pair of the bracket is said to be redundant when a sub-expression is surrounded by unnecessary or needless brackets.*/

/*
Example:
Expression: (a+b)+c
Since there are no needless brackets, hence, the output must be 'false'.

Expression: ((a+b))
The expression can be reduced to (a+b). Hence the expression has redundant brackets and the output will be 'true'.*/

#include<stack>
#include<iostream>
using namespace std;

bool checkRedundantBrackets(string expression) {
	// Write your code here
    stack<char> s;
    int add=0,del=0,l=expression.size();
    char c;
    int i=0;
    while(i<l){
        c=expression[i];
        if(c==')'){
            if(add==1){  //if(add=1)---->this mistake causes waste of infinite time
                return true;
            }
            else{
                while(s.top()!='('){
                    s.pop();
                    del++;
                }
                if(del==0){
                    return true;
                }
                s.pop();
                del=0;
                add=0;
            }
            i++;
        }
        else if(c=='('){
            add=0;
            s.push(c);
            c=expression[++i];
            while(c!='('&&c!=')'&&c!='\0'){
                s.push(c);
                c=expression[++i];
                add++;
            }
        }
        else{
            add=0;
            while(c!='('&&c!=')'&&c!='\0'){
                s.push(c);
                c=expression[++i];
            }
        }
    }
    return false;
}