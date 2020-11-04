#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Tree
{
    char value;
    struct Tree *left, *right;
};

bool isOperator(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/')
        return true;
    return false;
}

int applyOp(int a, int b, char op)
{
	switch(op)
	{
		case '+': return a + b; break;
		case '-': return a - b; break;
		case '*': return a * b; break;
		case '/': return a / b; break;
	}
    return 0;
}

int evaluate(string tokens){
	int i;
	stack <int> values;
	stack <char> ops;
	
	for(i = 0; i < tokens.length(); i++){
		if(tokens[i] == ' ')
			continue;

		else if(tokens[i] == '('){
			ops.push(tokens[i]);
		}

		else if(isdigit(tokens[i])){
			int val = 0;
			
			while(i < tokens.length() && isdigit(tokens[i]))
			{
				val = (val*10) + (tokens[i]-'0');
				i++;
			}
			
			values.push(val);
			i--;
		}
		else if(tokens[i] == ')')
		{
			while(!ops.empty() && ops.top() != '(')
			{
				int val2 = values.top();
				values.pop();
				
				int val1 = values.top();
				values.pop();
				
				char op = ops.top();
				ops.pop();
				
				values.push(applyOp(val1, val2, op));
			}
			
			if(!ops.empty())
				ops.pop();
		}
		else
		{
			// while(!ops.empty() && isOperator(ops.top()) >= isOperator(tokens[i])){
			// 	int val2 = values.top();
			// 	values.pop();
				
			// 	int val1 = values.top();
			// 	values.pop();
				
			// 	char op = ops.top();
			// 	ops.pop();
				
			// 	values.push(applyOp(val1, val2, op));
			// }
			ops.push(tokens[i]);
		}
	}
	// while(!ops.empty()){
	// 	int val2 = values.top();
	// 	values.pop();
				
	// 	int val1 = values.top();
	// 	values.pop();
				
	// 	char op = ops.top();
	// 	ops.pop();
				
	// 	values.push(applyOp(val1, val2, op));
	// }
	
	return values.top();
}

void inorder(Tree *start,string &temp)
{
    if(!(start->left==NULL && start->right==NULL)){
        cout<<"(";
        char a = '(';
        temp=temp+a;
    }

    if(start->left!=NULL)
        inorder(start->left,temp);

    cout<<start->value;

    char c = start->value;
    temp = temp + c;

    if(start->right!=NULL)
        inorder(start->right,temp);

    if(!(start->left==NULL && start->right==NULL)){
        cout<<")";
        char b = ')';
        temp = temp + b;
    }

}
Tree *newNode(char v)
{
    Tree *temp = new Tree;
    temp->left = NULL;
    temp->right = NULL;
    temp->value = v;
    return temp;
}
Tree* constructTree(char postfix[])
{
    stack <Tree *> st;
    Tree *t,*t1,*t2;
    for(int i=0; i<strlen(postfix); i++)
    {
        if(!isOperator(postfix[i])){
            t = newNode(postfix[i]);
            st.push(t);
        }
        else{
            t = newNode(postfix[i]);
            t1 = st.top();
            st.pop();
            t2 = st.top();
            st.pop();

            t->right = t1;
            t->left = t2;

            st.push(t);
        }
    }
    t = st.top();
    st.pop();
    return t;
}

int main()
{
    char postfix[50];
    string t;
    cout<<"Insert postfix expression : ";
    cin>>postfix;
    Tree *r = constructTree(postfix);
    printf("infix expression is : ");
    inorder(r,t);
    if(postfix[0]>='0' && postfix[0]<='9')
        cout << "\nValue is : "<< evaluate(t) << "\n";
}
