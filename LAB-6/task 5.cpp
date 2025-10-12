#include <iostream>
#include <string>
using namespace std;

class Stack{
	public:
		int top;
		int size;
		char *arr;
		
		Stack(int s){
			size=s;
			arr=new char[size];
			top=-1;
		}
		
		bool isEmpty(){
			return top==-1;
		}
		
		bool isFull(){
			return top==size-1;
		}
		
		void push(char val){
			if(isFull()){
				cout<<"Stack Overflow!"<<endl;
				return;
			}
			arr[++top]=val;
		}
		
		char pop(){
			if(isEmpty()){
				cout<<"Stack Underflow!"<<endl;
				return '\0';
			}
			return arr[top--];
		}
		
		char peek(){
			if(isEmpty())
				return '\0';
			return arr[top];
		}
};

int precedence(char op){
	if(op=='+' || op=='-')
		return 1;
	if(op=='*' || op=='/')
		return 2;
	return 0;
}

bool isOperator(char c){
	return (c=='+' || c=='-' || c=='*' || c=='/');
}

bool isOperand(char c){
	return (c>='0' && c<='9') || (c>='A' && c<='Z') || (c>='a' && c<='z');
}

string infixToPostfix(string infix){
	Stack st(infix.length());
	string postfix="";
	
	for(int i=0;i<infix.length();i++){
		char ch=infix[i];
		
		if(isOperand(ch))
			postfix+=ch;
			
		else if(ch=='(')
			st.push(ch);
			
		else if(ch==')'){
			while(!st.isEmpty() && st.peek()!='('){
				postfix+=st.pop();
			}
			st.pop(); 
		}
		
		else if(isOperator(ch)){
			while(!st.isEmpty() && precedence(st.peek())>=precedence(ch)){
				postfix+=st.pop();
			}
			st.push(ch);
		}
	}
	
	while(!st.isEmpty()){
		postfix+=st.pop();
	}
	
	return postfix;
}

class IntStack{
	public:
		int top;
		int size;
		int *arr;
		
		IntStack(int s){
			size=s;
			arr=new int[size];
			top=-1;
		}
		
		bool isEmpty(){
			return top==-1;
		}
		
		void push(int val){
			arr[++top]=val;
		}
		
		int pop(){
			return arr[top--];
		}
};

int evaluatePostfix(string postfix){
	IntStack st(postfix.length());
	
	for(int i=0;i<postfix.length();i++){
		char ch=postfix[i];
		
		if(ch>='0' && ch<='9')
			st.push(ch-'0');
			
		else if(isOperator(ch)){
			int val2=st.pop();
			int val1=st.pop();
			int result;
			
			switch(ch){
				case '+': result=val1+val2; break;
				case '-': result=val1-val2; break;
				case '*': result=val1*val2; break;
				case '/': result=val1/val2; break;
			}
			
			st.push(result);
		}
	}
	return st.pop();
}

int main(){
	string infix;
	cout<<"Enter infix expression: ";
	cin>>infix;
	
	string postfix=infixToPostfix(infix);
	cout<<"Postfix expression: "<<postfix<<endl;
	
	int result=evaluatePostfix(postfix);
	cout<<"Evaluation result: "<<result<<endl;
	
	return 0;
}
