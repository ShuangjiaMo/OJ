#include <iostream>
#include <stack>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;
struct Token
{
    enum token_type
    {
        NUMBER = 1, OP=2
    }type;
    long long number;
    string op;
    int priority;
};

vector<Token> tokens;
stack<long long> number_stack;
stack<Token> op_stack; 

bool init(){
    
}

bool calc(Token op){
    long long a , b;
    if((op.op=="$" and number_stack.empty()) or (op.op!="$" and number_stack.size()<2))
        return false;
    if(op.op == "$"){
        a = number_stack.top();number_stack.pop();
        number_stack.push(-1*a);
    }else if(op.op=="+"){
        a = number_stack.top();number_stack.pop();
        b = number_stack.top();number_stack.pop();
        number_stack.push(b+a);
    }else if(op.op=="-"){
        a = number_stack.top();number_stack.pop();
        b = number_stack.top();number_stack.pop();
        number_stack.push(b-a);
    }else if(op.op=="*"){
        a = number_stack.top();number_stack.pop();
        b = number_stack.top();number_stack.pop();
        number_stack.push(b*a);
    }else if(op.op=="/"){
        a = number_stack.top();number_stack.pop();
        b = number_stack.top();number_stack.pop();
        if(a==0) 
            return false;
        number_stack.push(b/a);
    }else if(op.op=="^"){
        a = number_stack.top();number_stack.pop();
        b = number_stack.top();number_stack.pop();
        number_stack.push((long long)pow(b, a));
    }
    return true;
}

void print(){
    for (int i = 0; i<tokens.size(); ++i) {
        if(tokens[i].type==Token::NUMBER){
            cout<<"number:"<<tokens[i].number<<endl;
        }else{
            cout<<"op:"<<tokens[i].op<<"   pri:"<<tokens[i].priority<<endl;
        }
    }
}
int main()
{
    string input;
    
    getline(cin,input);
    string xpr = "";
    for (int i = 0; i < input.length(); ++i) {
        if(input[i]!=' ')
            xpr+=input[i];
    }
    Token tmp;
    for (int i = 0; i < xpr.length(); ++i)
    {
        switch(xpr[i]){
            case ' ':
                continue;
                break;
            case '+':
                tmp.type = Token::OP;
                tmp.op = "+";
                tmp.priority = 1;
                break;
            case '-': 
                if(i>=1 and (xpr[i-1]==')' or isdigit(xpr[i-1])))
                {
                    tmp.type = Token::OP;
                    tmp.op = "-";
                    tmp.priority = 1;
                }else{ 
                    tmp.type = Token::OP;
                    tmp.op = "$";
                    tmp.priority = 10;
                }
                break;
            case '*':
                tmp.type = Token::OP;
                tmp.op = "*";
                tmp.priority = 2;
                break;
            case '/':
                tmp.type = Token::OP;
                tmp.op = "/";
                tmp.priority = 2;
                break;
            case '^'://
                tmp.type = Token::OP;
                tmp.op = "^";
                tmp.priority = 3;
                break;
            case '(':
                tmp.type = Token::OP;
                tmp.op = "(";
                tmp.priority = 0;
                break;
            case ')':
                tmp.type = Token::OP;
                tmp.op = ")";
                tmp.priority = 4;
                break;
            default: 
                string num = "";
                while( i < xpr.length() and isdigit(xpr[i]))
                    num += xpr[i++];
                --i;
                stringstream ss;
                ss<<num;
                ss>>tmp.number;
                tmp.type = Token::NUMBER;
                tmp.op = "";
                break;
        }
        tokens.push_back(tmp);
    }
	
	for (int i = 0; i < tokens.size() ; ++i) {
        if(tokens[i].type == Token::OP){
            if(tokens[i].op=="("){
                op_stack.push(tokens[i]);
                
            }else if(tokens[i].op==")"){
                
                while( !op_stack.empty() and op_stack.top().op != "("){
                    if(!calc(op_stack.top())){
			        	cout<<"Error"<<endl;
			        	return 0;
					}
                    op_stack.pop();
                }
                if(op_stack.empty()){
		        	cout<<"Error"<<endl;
		        	return 0;
				}
                if(op_stack.top().op == "(")
                    op_stack.pop();
            }else{ 
                
                if(op_stack.empty())
                    op_stack.push(tokens[i]);
                else{
                    int top_pr = op_stack.top().priority;
                    int cur_pr = tokens[i].priority;
                    if( cur_pr > top_pr or (tokens[i].op =="^" and op_stack.top().op=="^")){
                        op_stack.push(tokens[i]);
                    }else{
                        while(cur_pr <= top_pr){ 
                            if(!calc(op_stack.top())){
					        	cout<<"Error"<<endl;
					        	return 0;
							}
                            op_stack.pop();
                            if(op_stack.empty())
                                break;
                            top_pr = op_stack.top().priority;
                        }
                        op_stack.push(tokens[i]);
                    }
                }
                
            }
        }else if(tokens[i].type==Token::NUMBER){
            number_stack.push(tokens[i].number);
        }
    }
    while (!op_stack.empty()){
        if(op_stack.top().op=="("){
        	cout<<"Error"<<endl;
        	return 0;
		}
        if(!calc(op_stack.top())){
        	cout<<"Error"<<endl;
        	return 0;
		}
        op_stack.pop();
    }
    if (number_stack.size()!=1){
    	cout<<"Error"<<endl;
    	return 0;
	}
	
	cout<<number_stack.top()<<endl;
    return 0;
}
