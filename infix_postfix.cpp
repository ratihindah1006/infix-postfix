/*
ratih indah wardani 	1817051006
intania rahmadhilla	1817051025
rahmadila nurjannah	1817051038
dewi lestari		1817051041
*/
#include <iostream>
using namespace std;

struct stack{
	int STACK[10000];
	char Stack[10000];
	int top;
};

class convert{
private:
	stack tumpukkan;

public:
	void init(){
		tumpukkan.top = -1;
	}

	void push(char input){
		tumpukkan.top++;
		tumpukkan.STACK[tumpukkan.top] = input;
	}

	void pop(){
		tumpukkan.top--;
	}

	char Top(){
		return tumpukkan.STACK[tumpukkan.top];
	}

	bool isEmpty(){
		if(tumpukkan.top <= -1)
			return true;
		else
			return false;
	}
}; convert stck;

int oprt(char input){
	if(input == '^')
		return 1;
	else if(input == '*' || input == '/')
		return 2;
	else if(input == '+' || input == '-')
		return 3;
	else if(input == '(' || input == ')')
		return 0;
	else
		return -1;
}

bool isOperand(char input);
bool isOperator(char input);
int oprt(char input);
bool banding(char input1, char input2);
string postfix(string input);

bool banding(char input1, char input2){
	int c1 = oprt(input1);
	int c2 = oprt(input2);

	if(c1 <= c2)
		return true;
	else
		return false;
}
