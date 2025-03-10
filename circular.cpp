#include<iostream>
using namespace std;
class node{
	public:
		int key,info;
		node* next;
		node(){
			key =0;
			info = 0;
			next = NULL;
		}
		node(int key,int info){
			this->key = key;
			this->info = info;
		}
};
class linkedlist{
	public:
		node* start;
		linkedlist(){
			start = NULL;
		}
		linkedlist(node* n){
			start = n;
		}
		node* nodeexist(int key){
			node* temp = NULL;
			node* ptr  = start;
		if(ptr==NULL){
			return temp;
		}
		else{
			do{
				if(ptr->key==key){
					temp = ptr;
				}
				ptr = ptr->next;
			}
			while(ptr!=start);
			return temp;
		}
	
		}
		void appendnode(node* n){
			if(nodeexist(n->key)!=NULL){
				cout<<"\n node existed already.use another key! ";
			}
			else{
				if(start==NULL){
					start = n;
					n->next= start;
					cout<<"\n node inserted! ";
				}
				else{
					node* ptr = start;
					while(ptr->next!=start){
						ptr = ptr->next;
					}
						ptr->next = n;
						n->next = start;
						cout<<"\n node appended! ";
					}
				}
			}
		void prependnode(node* n){
				if(nodeexist(n->key)!=NULL){
				cout<<"\n node existed already.use another key! ";
			}
			else{
				if(start==NULL){
					start = n;
					n->next= start;
					cout<<"\n node prepended! ";
				}
				else{
					node* ptr= start;
				while(ptr->next!=start){
					ptr = ptr->next;
				}
				ptr->next = n;
				n->next = start;
				start = n;
				cout<<"\n NODE APPENDED! ";
				}
			}
		}
		void insertanywhere(int key,node* n){
			node* ptr = nodeexist(key);
			if(ptr==NULL){
				cout<<"key is not in linked list! ";
			}
			else{
				if(nodeexist(n->key)!=NULL){
				cout<<"\n node existed already.use another key! ";
			}
			else{
			    if(ptr->next==start){
			    	n->next= start;
			    	ptr->next = n;
			    	cout<<"\n node inserted! ";
				}
				else{
					n->next= ptr->next;
					ptr->next = n;
					cout<<"\n node inserted! ";
				}
			}
			}
		}
 void deletenodebykey(int key){
    node* ptr = nodeexist(key);
    if(ptr==NULL){
    	cout<<"\n node doesnot exist! ";
	}
	else{
		if(ptr==start){
			if(start->next==start){
				start=NULL;
				cout<<"\n deleted! ";
			}
			else{
				node* ptr1 = start;
				while(ptr1->next!=start){
					ptr1 = ptr1->next;
				}
				ptr1->next = start->next;
				start = start->next;
				cout<<"\n deleted! ";
			}
		}
		else{
			node* temp = NULL;
			node* previousptr = start;
			node* currentptr = start->next;
			while(currentptr!=NULL){
				if(currentptr->key==key){
					temp = currentptr ;
					currentptr = NULL;
				}
				else{
					previousptr = previousptr->next;
					currentptr = currentptr->next;
				}
				
			}
			previousptr->next = temp->next;
			cout<<"\n deleted! ";
		}
	}
	}
		void update(int key,int info){
			node* ptr =  nodeexist(key);
			if(ptr!=NULL){
				ptr->info = info;
				cout<<"\n UPDATED! ";
			}
			else{
				cout<<"\n node not found! ";
			}
		}
		void print(){
			if(start==NULL){
				cout<<"\n no nodes! ";
			}
			else{
				node* temp = start;
				do{
					cout<<temp->key<<"    ,    "<<temp->info<<endl;
					temp = temp->next;
				}
				while(temp!= start );
			}
		}
		void deleteafternode(int key){
    	if(start == NULL){
    		cout<<"\n linked list is empty";
		}
		else if(start !=NULL){
				node* temp = NULL;
				node* prevnode = start;
				node* currentnode = start->next;
				while(currentnode->next!=NULL){
					if(currentnode->key==key){
						temp = currentnode->next;
						currentnode->next = NULL;
					}
					else{
						prevnode = prevnode->next;
						currentnode = currentnode->next; 
					}
				}
				if(temp!=NULL){
					currentnode->next = temp->next;
					cout<<"\n deleted";
				}
				else{
					cout<<"\n node doesnot exist with this key value";
				}
		}
	}
};
int main(){
	linkedlist obj;
	int key,info,k1;
	int option;
	do{
	cout<<"\n press following for operations! ";
	cout<<"\n 1 for append";
	cout<<"\n 2 for prepend";
	cout<<"\n 3 for insert after key";
	cout<<"\n 4 for update";
	cout<<"\n 5 for delete";
	cout<<"\n 6 for print";
	cout<<"\n 7 for delete after node";
	cin>>option;
	node* n1 = new node();
	switch(option){
		case 1:
			cout<<"\n enter key and info: ";
			cin>>key>>info;
			n1->info = info;
			n1->key = key;
			obj.appendnode(n1);
			break;
		case 2:
				cout<<"\n enter key and info: ";
				cin>>key>>info;
				n1->key = key;
				n1->info= info;
			obj.prependnode(n1);
			break;
			case 3:
			cout<<"\n enter key and info: ";
				cin>>key>>info;
				cout<<"\n enter after which key you want to append: ";
				cin>>k1;
				n1->key = key;
				n1->info= info;
			obj.insertanywhere(k1,n1);	
			break;
			case 4:
			cout<<"\n enter key and info: ";
				cin>>k1>>info;
				
			obj.update(k1,info)	  ;
			break;
			case 5:
			cout<<"\n enter key: ";
		    cin>>k1;
				
			obj.deletenodebykey(k1);
			break;
			case 6:
			obj.print();
			break;
			case 7:
				cout<<"\n enter key: ";
				cin>>k1;
				obj.deleteafternode(k1);
				break;
			default:
			cout<<"\n invalid";
			break;	 	 
		}
			
	}
	
while(option!=0);

}