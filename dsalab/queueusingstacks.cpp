#include <iostream>
#define MAXSIZE 10
using namespace std;

class Stack {
    public:
    int top = -1;
    int st[MAXSIZE];
    
    int isempty()
    {
    	if(top==-1)
    	return 1;
    	else
    	return 0;
    }
    int isfull()
    {
    	if(top==MAXSIZE)
    	return 1;
    	else
    	return 0;
    }
    void create(int n)
    {
    	if(isfull() || n>MAXSIZE)
    	{
    		cout<<"Cant create stack";
    		return;
    	}
    	else
    	{
    		for(int i=0;i<n;i++)
    		{
    			cout<<"Enter "<<i+1<<" element:";
    			top++;
    			cin>>st[top];
    		}
    	}
    }
    void display()
    {
    	if(isempty())
    	{
    		cout<<"Empty stack.";
    	}
    	else
    	{
    		for(int i=top;i>=0;i--)
    		{
    			cout<<st[i]<< " ";
    		}
    		cout << endl;
    	}
    }
    void push(int x)
    {
    	if(isfull())
    	{
    		cout<<"Cant push element";
    	}
    	else if(top==-1)
    	{
    		top++;
    		st[top]=x;
    	}
    	else
    	{
    		top++;
    		st[top]=x;
    	}
    }
    int pop()
    {
    	int x=st[top];
    	top--;
    	return x;
    }
    void peek(int &x)
    {
    	x=st[top];
    }
};

class Queue {
    Stack s1, s2;
    public:
    
    void enqueue(int x) {
        while(s1.top != -1) {
            s2.push(s1.pop());
        }
        s2.push(x);
        while(s2.top != -1) {
            s1.push(s2.pop());
        }
    }
    
    void dequeue() {
        s1.pop();
    }
    
    void output() {
        s1.display();
    }
};

// int main() {
//     Queue q1;
//     q1.enqueue(1);
//     q1.enqueue(2);
//     q1.enqueue(3);
//     q1.dequeue();
//     q1.output();
// }
