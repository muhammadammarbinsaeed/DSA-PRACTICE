#include<iostream>
#include<windows.h>
using namespace std;
class node{
	public:
		 int key;
		 int data;
		 node* next;
		 node(){
		 	key = 0;
		 	data = 0;
		 	next = NULL;
		 }
};
class stack{
	public:
		node* top;
		stack(){
			top = NULL;
		}
		stack(node* n){
			top = n;
		}
		bool isempty(){
			if(top==NULL)
			return true;
			else
			return false;
		}
		bool nodeexist(node* n){
			bool exist = false;
			if(isempty()){
				cout<<"\n stack is empty! ";
				return exist;
			}
			else{
				node* temp = top;
				while(temp!=NULL){
					if(temp->key==n->key){
						exist = true;
					}
					temp = temp->next;
				}
				return exist;
			}
		}
		void push(node* n){
			if(top==NULL){
				top = n;
			}
			else{
				if(nodeexist(n)){
					cout<<"\n node already existed with key. try using another key value! ";
				}
				else{
					node* temp = top;
					top = n;
					n->next = temp;
					cout<<"\n NODE PUSHED SUCCESSFULLY! ";
				}
			}
		}
		node* pop(){
			node* temp = NULL;
			if(isempty()){
				cout<<"\n STACK UNDERFLOW! ";
				return temp;
			}
			else{
			     temp = top;
			     top= top->next;
			     return temp;
		}
		}
		node* peek(){
			node* temp = NULL;
			if(isempty()){
				cout<<"\n stack underflow! ";
				return temp;
			}
			else{
				return top;
			}
		}
		int count(){
			if(isempty()){
				cout<<"\n stack underflow! ";
				return 0;
			}
			else{
				int count = 0;
				node* temp = top;
				while(temp!=NULL){
					count++;
					temp = temp->next;
				}
				return count;
			}
		}
		void display(){
			if(isempty()){
				cout<<"\n stack is empty! ";
			}
			else{
				cout<<"\n elements in stack are: ";
				cout<<endl;
				node* temp = top;
				while(temp!=NULL){
					cout<<"   "<<temp->key<<"   ,   "<<temp->data<<"   "<<endl;
					temp  = temp->next;
				}
				cout<<"\n total number of nodes in stack are: "<<count()<<endl;
			}
		}
};
void clearscreen(){
	system("CLS");
}
int main(){
	stack obj;
	int key,option,value;
    do{
    	cout<<"\n following operations! ";
		cout<<"\n 1 for push! ";
		cout<<"\n 2 for pop! ";
		cout<<"\n 3 for check empty!  ";
		cout<<"\n 4 for peek ";
		cout<<"\n 5 for count  ";
		cout<<"\n 6 for display ";
		cout<<"\n 7 for clear screen  ";
	   cout<<"\n 0 for exit  ";
		cout<<"\n enter your choice: ";
		cin>>option;
		node* n1  = new node();
		switch(option){
			case 0:
				break;
			case 1:
			   cout<<"\n enter key and value to push: ";
			   cin>>key>>value;
			   n1->key = key;
			   n1->data = value;
			   obj.push(n1);
			   break;
			case 2:
		       cout<<"\n POP function called! ";
			   n1  = obj.pop();
			   if(n1!=NULL){
			   cout<<"\n top of stack is "<<n1->data<<" and it is poped! ";
			   delete n1;
			   }
			   break;
			case 3:
			   if(obj.isempty()){
			   	cout<<"\n stack is empty! ";
			   }   
			   else{
			   	cout<<"\n stack is not empty! ";
			   }
			   break;
			case 4:
			    cout<<"\n peek function called! ";
				n1 = obj.peek();
				if(n1!=NULL){
						cout<<"\n PEEK OF STACK IS  "<<n1->data<<endl;  
				}
			    break;
			case 5:
				cout<<"\n number of nodes in stack are: "<<obj.count()<<endl;
				break;
			case 6:
			    obj.display();
				break;
			case 7:
			    clearscreen();
				break;		  
		}
	}
	while(option!=0);
}