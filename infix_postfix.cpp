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

bool isOperand(char input){
	int c = (int)input;
	if(c >= 48 && c <= 57 || c >= 65 && c <= 90 || c >= 97 && c <= 122)
		return true;
	else
		return false;
}

bool isOperator(char input){
	int c = (int)input;
	if(c == 94 || c >= 42 && c <= 43 || c == 45 || c == 47)
		return true;
	else
		return false;
}

string postfix(string input){
	stck.init();
	int i=0;
	string P = "";
	while(input[i] != '\0'){
		if(isOperand(input[i])){
			P += input[i];
		}
		if(input[i] == '('){
			stck.push(input[i]);
		}
		if(input[i] == ')'){
			while(!stck.isEmpty() && stck.Top() != '('){
				P = P + " " + stck.Top(); stck.pop();
			}
			stck.pop();
		}
		if(isOperator(input[i])){
			if(stck.isEmpty() || stck.Top() == '('){
				stck.push(input[i]);
			}else{
				while(!stck.isEmpty() && stck.Top() != '(' && banding(input[i], stck.Top())){
					P = P + " " + stck.Top(); stck.pop();
				}
				stck.push(input[i]);
			}
