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
class queue{
	public:
		node* front;
		node* rear;
		queue(){
			front  = NULL;
			rear = NULL;
		}
		bool isempty(){
			if(front==NULL&&rear==NULL)
			return true;
			else
			return false;
		}
		bool nodeexist(node* n){
			bool exist = false;
			if(isempty()){
				cout<<"\n queue is empty! ";
				return exist;
			}
			else{
				node* temp = front;
				do {
					if(temp->key==n->key){
						exist = true;
						break;
					}
					temp = temp->next;
				}while(temp!=front);
				return exist;
			}
		}
		void enqueue(node* n){
			 if(isempty()){
			 	front = n;
			 	rear = n;
			 	n->next = front;
			 	cout<<"\n VALUE ENQUEUED! ";
			 }
			 else if(nodeexist(n)){
			 	cout<<"\n try with another key! ";
			 }
			 else{
			 	rear->next = n;
			 	rear = n;
			 	n->next = front;
			 	cout<<"\n VALUE ENQUEUED! ";
			 }
		 }
		node* dequeue(){
		 	node* temp= NULL;
		 	if(isempty()){
		 		cout<<"\n queue is empty ! ";
		 		return temp;
			 }
			 else{
			 	if(front==rear){
			 		 temp = front;
			 		front = NULL;
			 		rear = NULL;
			 		cout<<"\n dequeued! ";
			 		return temp;
				 }
				 else {
				 	temp = front;
				 	front = front->next;
				 	rear->next = front;
				 	cout<<"\n dequeued! ";
				 	return temp;
				 }
			 }
		 }
		int count(){
		int count =0;
		node* temp1 = front;
		do{
			count++;
			temp1 = temp1->next;
		}
		while(temp1!=front);
		return count;
		}
		void display(){
			if(isempty()){
				cout<<"\n queue is empty! ";
			}
			else{
				cout<<"\n elements in queue are: ";
				cout<<endl;
				node* temp2 = front;
				do{
					cout<<"   "<<temp2->key<<"   ,   "<<temp2->data<<"   "<<endl;
					temp2  = temp2->next;
				}
				while(temp2!=front);
				cout<<"   "<<temp2->key<<"   ,   "<<temp2->data<<"   "<<endl;
				cout<<"\n total number of nodes in queue are: "<<count()<<endl;
			}
		}
};
int main(){
	 queue obj;
	int  option,key,data,count;
	do{
		cout<<"\n following operations! ";
		cout<<"\n 1 for enqueue! ";
		cout<<"\n 2 for dequeue ";
		cout<<"\n 3 for check empty!  ";
		cout<<"\n 5 for display!  ";
		cout<<"\n 6 for count";
		cout<<"\n 8 for clear screen  ";
		cout<<"\n 0 for exit  ";
		cout<<"\n enter choice: ";
		cin>>option;
		node *n1 = new node();
		switch(option){
			case 0:
				break;
			case 1:
			   cout<<"\n enter key and value to enqueue: ";
			   cin>>key>>data;
			   n1->key = key;
			   n1->data = data;
			   obj.enqueue(n1);
			   break;
			case 2:
			    n1 = obj.dequeue();
			   cout<<"\n value "<<n1->data<<"  is dequeued from the queue! ";
			   delete n1;
				break;
			case 3:
			    if(obj.isempty()){
			    	cout<<"\n queue is empty! ";
				}	  	
				else{
					cout<<"\n queue is not empty! ";
				}
				break;
			case 5:
			     obj.display();
				 break;
			case 6:
			      count = obj.count();
			     cout<<"\n number of elements in queue are: "<<count;
				 break;	
			case 8:
			     system("CLS");
			   break;
		 	 
		}
		
	}
	while(option!=0);
}