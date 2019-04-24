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
