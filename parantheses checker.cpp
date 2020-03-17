#include<bits/stdc++.h> 
//#include<string>
using namespace std; 
#define MAX 100
int stk[MAX];
int top=-1;
void push(char ch)
{
	stk[++top]=ch;
}
int pop()
{
	return (stk[top--]);
}

int main()
{
int flag=1;
int cpush=0,cpop=0;
char c;
	string str;
	cout<<"Enter the String : ";
	cin>>str;
	int len=str.size();
	for(int i=0;i<len;i++)
	{
		if(str[i]=='(' || str[i]=='{' || str[i]=='[')
		{
			cpush++;
			push(str[i]);
		}
		if(str[i]==')' || str[i]=='}' || str[i]==']')
		{
			if(top==-1)
			{
				cout<<" \n Bracket missings are : ";
				if(str[i]==')')
				{
					cout<<"(";
				}
				if(str[i]=='}')
				{
					cout<<"{";
				}
				if(str[i]==']')
				{
					cout<<"[";
				}
				cpop++;
			}
			else
			{
				c=pop();
				if(str[i]==')'&&(c=='{' || c=='['))
				{
					flag=0;
				}
				if(str[i]=='}'&&(c=='(' || c=='['))
				{
					flag=0;
				}
				if(str[i]==']'&&(c=='(' || c=='{'))
				{
					flag=0;
				}
				cpop++;
			}	
		}

	}
	if(flag==0)
	{
		cout<<" \n Wrong order of Brackets"	;
	}
	else
	while(top>=0)
	{
		c=pop();
		cout<<" \n Bracket missings are : ";
				if(c=='(')
				{
					cout<<")";
				}
				if(c=='{')
				{
					cout<<"}";
				}
				if(c=='[')
				{
					cout<<"]";
				}
	}	
	cout<<"\n total opening brackets are :"<<cpush;
	cout<<"\n total closing brackets are :"<<cpop;
return 0;
}

