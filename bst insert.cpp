#include<iostream>
#define SPACE 10
using namespace std;
class treenode{
	public:
		treenode* left;
		int value;
		treenode* right;
		treenode(){
			value = 0;
			left = NULL;
			right = NULL;
	}
};
class BST{
	public:
		treenode* root;
		BST(){
			root = NULL;
		}
		bool isempty(){
			if(root==NULL){
				return true;
			}
			else{
				return false;
			}
		}
		void insertnode(treenode* new_node){
			if(root==NULL){
				root = new_node;
				cout<<"\n value inserted! ";
			}
			else{
				treenode* temp = root;
				while(temp!=NULL){
					if(new_node->value == temp->value){
						cout<<"\n value already existed! ";
						cout<<"\n add another value! ";
						return;
					}
					else if((new_node->value<temp->value)&&(temp->left==NULL)){
						temp->left = new_node;
						cout<<"\n value inserted at left ";
						break;
					}
					else if((new_node->value<temp->value)){
						temp = temp->left;
					}
					else if((new_node->value>temp->value)&&(temp->right==NULL)){
						temp->right = new_node;
						cout<<"\n value inserted at right ";
						break;
					}
					else{
						temp = temp->right;
					}
				}
			}
		}
		treenode* iterativesearch(int val){
			if(root==NULL){
				return root;
			}
			else{
				treenode* temp = root;
				while(temp!=NULL){
					if(val==temp->value){
						return temp;
					}
					if(val>temp->value){
						temp = temp->right;
					}
					else{
						temp = temp->left;
					}
				}
				return NULL;
			}
		}
		int treeheight(treenode* r){
			int lheight,rheight;
			if(r==NULL){
				return -1;
			}
			else{
				lheight = treeheight(r->left);
				rheight = treeheight(r->right);
				if(lheight>rheight){
					return (lheight+1);
				}
				else{
					return (rheight+1);
				}
			}
		}
		void printpreorder(treenode* r) // node-left-right
		{
			if(r==NULL)
			return;
			cout<<r->value<<"  ";   //node
			printpreorder(r->left);
			printpreorder(r->right);	
		}
			void printinorder(treenode* r) // left-node-right
		{
			if(r==NULL)
			return;
			printinorder(r->left);
			cout<<r->value<<"  ";   //node
			printinorder(r->right);	
		}
		void printpostorder(treenode* r) // left-right-node
		{
			if(r==NULL)
			return;
			printpostorder(r->left);
			printpostorder(r->right);
			cout<<r->value<<"  ";   //node	
		}
		void print2D(treenode * r, int space) {
    if (r == NULL) // Base case  1
      return;      
      // SPACE = 10
    space += SPACE; // Increase distance between levels   2
    print2D(r -> right, space); // Process right child first 3 
    cout << endl;
    for (int i = SPACE; i < space; i++) // 5 
      cout << " "; // 5.1  
    cout << r -> value << "\n"; // 6
    print2D(r -> left, space); // Process left child  7
  }
   void printbreadthsearchtraverse(treenode* r){
   	int height = treeheight(r);
   	for(int i=0;i<=height;i++){
   		printgivenlevel(r,i);
	   }
   }		 
   void printgivenlevel(treenode* r, int level){
   	if(r==NULL){
   		return;
	   }
	   else if(level==0){
	   	cout<<r->value<<"  ";
	   }
	   else{
	   	 printgivenlevel(r->left,level-1);
	   	 printgivenlevel(r->right,level-1);
	   }
   }
   treenode* deletenode(treenode* r,int v){
   	if(r==NULL){
   		return NULL;
	   }
	   else if(v<r->value){
	   	r->left = deletenode(r->left,v);
	   }
	   else if(v>r->value){
	   	r->right = deletenode(r->right,v);
	   }
	   else {
	   	  if(r->left==NULL){
	   	  treenode*	temp = r->right;
			 delete r;
			 return temp; 
			 }
			 else if(r->right==NULL){
			 	treenode*  temp = r->left;
			 	delete r;
			 	return temp;
			 }
			 else{
			 	treenode* temp = minValueNode(r->right);
			 	r->value= temp->value;
			 	r->right = deletenode(r->right,temp->value);
			 }
	   }
	   return r;
   }
   treenode* minValueNode(treenode* node){
   	treenode* current = node;
   	while(current->left!=NULL){
   		current = current->left;
	   }
	   return current;
   }
};
int main(){
	int option;
	int val,svalue,height,dvalue;
	BST obj;
	do{
		cout<<"\n which operation do you want to perform: ";
		cout<<"\n 1. Insert Node";
		cout<<"\n 2. Search Node";
		cout<<"\n 3. Delete Node";
		cout<<"\n 4. Print BST values";
		cout<<"\n 5. Clear screen";
		cout<<"\n 6. Height of tree";
		cout<<"\n 0. Exit program";
		cout<<"\n ENTER CHOICE: ";
		cin>>option;
		treenode *newnode = new treenode();
		switch(option){
			case 0:
				break;
			case 1:
			    cout<<"\nenter value: ";
			    cin>>val;
			    newnode->value = val;
			    obj.insertnode(newnode);
			    cout<<endl;
				break;
			case 2:
			    cout<<"\n Search"<<endl;
			    cout<<"\n Enter value to search : ";
			    cin>>svalue;
			    newnode = obj.iterativesearch(svalue);
			    if(newnode!=NULL){
			    	cout<<"\n VALUE FOUND! ";
			    	cout<<newnode->value;
				}
			    else{
			    	cout<<"\n VALUE NOT FOUND! ";
				}
				break;
			case 3:
			    cout<<"\n Delete"<<endl;
			    cout<<"\n Enter value to delete : ";
			    cin>>dvalue;
			    obj.deletenode(obj.root,dvalue);
				break;
			case 4:
			    obj.print2D(obj.root,5);
			    cout<<endl;
			    cout<<"\npreorder traversal technique"<<endl;
			    obj.printpreorder(obj.root);
			    cout<<"\ninorder traversal technique"<<endl;
			    obj.printinorder(obj.root);
			    cout<<"\npostorder traversal technique"<<endl;
			    obj.printpostorder(obj.root);
			    cout<<"\nbst traversal technique"<<endl;
			    obj.printbreadthsearchtraverse(obj.root);
				break;	
			case 5:
			    cout<<"\n clear"<<endl;
				break;
			case 6:
			    height = obj.treeheight(obj.root);
			   cout<<"\n height of tree is : "<<height<<endl;
			   break;	
				default:
				cout<<"\n INVALID! ";
				break;		
		}
	}while(option!=0);
	return 0;
}