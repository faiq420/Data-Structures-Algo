#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(){
        val=0;
        left=NULL;
        right=NULL;
    }
    TreeNode(int v){
        val=v;
        left=NULL;
        right=NULL;
    }
};

class BinarySearchTree{
public:
    TreeNode* root;

    bool isEmpty(){
        if(root==NULL){
            return true;
        }
        else{
            return false;
        }
    }

    void insertNode(TreeNode* new_node)
    {
        if(root==NULL)
        {
            root=new_node;
            cout<<"Value inserted as root."<<endl;
        }
        else
        {
            TreeNode* temp=root;
            while(temp!=NULL)
            {
                if(temp->val == new_node->val)
                {
                    cout<<"Duplicate value spotted! Please enter another value."<<endl;
                }
                else if((new_node->val < temp->val) && (temp->left == NULL))
                {
                    temp->left=new_node;       //left child
                    cout<<"Value added as left child."<<endl;
                    break;
                }
                else if(new_node->val < temp->val)
                {
                    temp=temp->left;
                }
                else if((temp->val < new_node->val) && (temp->right == NULL))
                {
                    temp->right=new_node;       //right child
                    cout<<"Value added as right child."<<endl;
                    break;
                }
                else
                {
                    temp=temp->right;
                }
            }
        }
    }

    void Preorder(TreeNode* r){         //NLR
        if(r==NULL)
        {
            return;
        }
        cout<<r->val<<"  ";         
        Preorder(r->left);          //recursively printing left child
        Preorder(r->right);         //recursively printing right child
    }
    void Inorder(TreeNode* r){         //LNR
        if(r==NULL)
        {
            return;
        }
        Inorder(r->left);          //recursively printing left child
        cout<<r->val<<"  ";
        Inorder(r->right);         //recursively printing right child
    }
    void Postorder(TreeNode* r){         //LRN
        if(r==NULL)
        {
            return;
        }
        Postorder(r->left);          //recursively printing left child
        Postorder(r->right);         //recursively printing right child
        cout<<r->val<<"  ";
    }

    void print2D(TreeNode* r,int space){
    	int SPACE=10;
        if(r==NULL)
        {
            return;
        }
        space+=SPACE;
        print2D(r->right,space);        //traverses to right child
        cout<<"\n";
        for(int i=SPACE;i<space;i++)
        {
            cout<<" ";          //print spacing
        }
        cout<<r->val<<"\n";     //sends to the new line to give graphical view
        print2D(r->left,space);     //traverses to left child
    }

    TreeNode* iterativeSearch(int value){
        if(root==NULL)
        {
            return root;
        }
        else
        {
            TreeNode* temp=root;
            while(temp!=NULL)
            {
                if(value==temp->val)
                {
                    return temp;
                }
                else if(value<temp->val)
                {
                    temp=temp->left;
                }
                else
                {
                    temp=temp->right;
                }
            }
            return NULL;
        }
    }

    int height(TreeNode* r){
        if(r==NULL)
        {
            return -1;
        }
        else
        {
            int leftheight=height(r->left);         //computing height in each subtree
            int rightheight=height(r->right);

            if(leftheight>rightheight)
            {
                return (leftheight+1);
            }
            else
            {
                return (rightheight+1);
            }
        }
    }
    
    TreeNode* minValueNode(TreeNode* node){
    	TreeNode* current=node;
    	while(current->left!=NULL)
    	{
    		current=current->left;			//traverses to the leftmost node in the right subtree to replace node with 2 childs in delete operation
		}
		return current;
	}
	
	TreeNode* deleteNode(TreeNode* r,int v){
		if(r==NULL)
		{
			return r;
		}
		else if(v<r->val)
		{
			r->left=deleteNode(r->left,v);
		}
		else if(v>r->val)
		{
			r->right=deleteNode(r->right,v);
		}
		else
		{
			TreeNode* temp;
			if(r->left ==NULL)					//this node has either just a right child or no children
			{
				temp=r->right;
				delete r;
				return temp;
			}
			else if(r->right ==NULL)			//this node has only left child
			{
				temp=r->left;
				delete r;
				return temp;
			}
			else
			{
				temp=minValueNode(r->right);
				r->val=temp->val;
				r->right=deleteNode(r->right,temp->val);
			}
		}
	}
	
	
};


int main() {
  BinarySearchTree obj;
  int option, v;

  do {
    cout <<endl<< "What operation do you want to perform? " <<
      " Select Option number. Enter 0 to exit." << endl;
    cout << "1. Insert Node" << endl;
    cout << "2. Search Node" << endl;
    cout << "3. Print BST values" << endl;
    cout << "4. Print BST graphically" << endl;
    cout << "5. Height of Tree" << endl;
    cout << "6. Delete Node" <<endl;
    cout << "0. Exit Program" << endl;

    cin >> option;
    TreeNode * new_node = new TreeNode();

    switch (option) {
    case 0:
      break;
    case 1:
      	cout <<endl<<"INSERT OPERATION"<<endl;
	      cout <<"Enter VALUE of TREE NODE to INSERT in BST: ";
	      cin >> v;
	      new_node->val = v;
	      obj.insertNode(new_node);
	      cout<<endl;
    		break;
      
    case 2:
      cout <<endl<< "SEARCH" << endl;
      cout << "Enter VALUE of TREE NODE to SEARCH in BST: ";
      cin >> v;
      new_node = obj.iterativeSearch(v);
      if (new_node != NULL) {
        cout << "Value found" << endl;
      } else {
        cout << "Value NOT found" << endl;
      }
      break;
      
    case 3:
      cout<<endl<<"PRINTING BST :-"<< endl;
      	      cout <<"PRE-ORDER: ";
      	      obj.Preorder(obj.root);
      	      cout<<"(Node , Left , Right)"<<endl;
      	      cout <<"IN-ORDER: ";
      	      obj.Inorder(obj.root);
      	      cout<<"(Left , Node , Right)"<<endl;
      	      cout <<"POST-ORDER: ";
      	      obj.Postorder(obj.root);
      	      cout<<"( Left , Right , Node)"<<endl;
      break;
      
    case 4:
        cout <<endl<< "PRINT 2D: " << endl;
      obj.print2D(obj.root, 5);
      cout << endl;
      
    case 5:
      cout <<endl<< "TREE HEIGHT" << endl;
      cout << "Height : " << obj.height(obj.root) << endl;
      break;
      
    case 6:
      cout << "DELETE" << endl;
      cout << "Enter VALUE of TREE NODE to DELETE in BST: ";
      cin >> v;
      new_node = obj.iterativeSearch(v);
      if (new_node != NULL) {
        obj.deleteNode(obj.root, v);
        cout << "Value Deleted" << endl;
      } else {
        cout << "Value NOT found" << endl;
      }
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}
