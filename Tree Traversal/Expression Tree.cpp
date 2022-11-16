 #include <iostream>

using namespace std;

bool isOperator(char x)
{
    char operators[7] = {'+', '-', '*', '/', '^', '(', ')'};

    for (int i = 0; i < sizeof(operators); i++)
    {
        if (operators[i] == x)
        {
            return true;
        }
        
    }
    return false;
}

struct node{
    char data;
    struct node *left;
    struct node *right;
};
string postfix= "ab+cd-*";
node *stack[5];
int top=-1;
struct node *root = NULL;

void expTree(){
	for(int i=0;i<postfix.length();i++)
	{
    struct node *temp = new node;
    temp->data = postfix[i];
    temp->left = temp->right = NULL;
    
    if (!isOperator(postfix[i]))
	{
		top++;
        stack[top]=temp;			//pushing operands in the stack
    }
    else
	{
        temp->right=stack[top];		//right child of operator
        top--;
        
        temp->left=stack[top];		//left child of operator
        top--;
        
        top++;
        stack[top]=temp;			//pushing the operator in stack for further tree
    }     
    root=stack[top];
    }
}



void InOrder(struct node *ptr){
    if (ptr == NULL)
    {
        return;
    }
    InOrder(ptr->left);
    cout<<ptr->data << " ";
    InOrder(ptr->right);
}
void PreOrder(struct node *ptr){
    if (ptr == NULL)
    {
        return;
    }
    cout<<ptr->data << " ";
    PreOrder(ptr->left);
    PreOrder(ptr->right);
}
void PostOrder(struct node *ptr){
    if (ptr == NULL)
    {
        return;
    }
    PostOrder(ptr->left);
    PostOrder(ptr->right);
    cout<<ptr->data << " ";
}


int main(){
    expTree();
    InOrder(root);
};
