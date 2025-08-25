#include<iostream>
#include<string>

using namespace std;

class Bankaccount{	
	public:
		float balance;
	Bankaccount():balance(0){
	}
	
	Bankaccount(int b):balance(b){
	}
	
	Bankaccount(Bankaccount& b){
		balance = b.balance;
	}
	
	void print(){
		cout<<"balance: $"<<balance<<endl;
	}
};

int main(){
	
	Bankaccount account1;
	cout<<"account1 ";
	account1.print();
	
	Bankaccount account2(1000);
	cout<<"account2 ";
	account2.print();
	
	Bankaccount account3(account2);
	cout<<"account3 ";
	account3.balance -= 200;
	
	account3.print();
}


