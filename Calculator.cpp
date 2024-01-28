#include<iostream>
using namespace std;
int main()
{
	int a,b,choice;
	cout<<"Enter the number 1:"<<endl;
	cin>>a;
	cout<<"Enter the number 2:"<<endl;
	cin>>b;
	cout<<"Enter your choice:"<<endl;
	cin>>choice;
	switch(choice)
	{
		case 1:
		cout<<"The addition of two numbers is "<<a+b;
		break;
		case 2:
		cout<<"The subtraction of number 1 from number 2 is "<<a-b;
		break;
		case 3:
		cout<<"The multiplication of two numbers is "<<a*b;
		break;
		case 4:
		cout<<"The division of number 1 by number 2 is "<<a/b; 
		break;
		default:
			cout<<"Enter a valid choice"<<endl;
	}
	return 0;
}
