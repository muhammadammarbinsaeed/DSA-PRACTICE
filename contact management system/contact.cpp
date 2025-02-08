#include<iostream>
#include<windows.h>
#include<string.h>
#include<fstream>
#include<iomanip> 
int main();
using namespace std;
class node{
	public:
		string name,address,email,contact;
		int id;
		node* next;
		node(){
			name = "";
			address = "";
			email = "";
			contact = "";
			next = NULL;
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
		node* nodeexist(int id){
			node* temp = NULL;
			node* ptr  = start;
			while(ptr!=NULL){
				if(ptr->id==id){
					 temp = ptr;
				}
				ptr = ptr->next;
			}
			return temp;
		}
		void appendnode(node* n){
			system("CLS");
			system("color E4");
			if(nodeexist(n->id)!=NULL){
				cout<<"\n contact id existed already.use another id! ";
			}
			else{
				if(start==NULL){
					start = n;
					cout<<"\n contact saved! ";
				}
				else{
					node* ptr = start;
					while(ptr->next!=NULL){
						ptr = ptr->next;
					}
						ptr->next = n;
						
						cout<<"\n contact saved! ";
				}
				oflinesave(n);
				system("pause");
				
			}
		}
		void prependnode(node* n){
			system("CLS");
			system("color E4");
				if(nodeexist(n->id)!=NULL){
				cout<<"\n contact id existed already.use another key! ";
			}
			else{
				n->next = start;
				start = n;
				cout<<"\n CONTACT IS SAVED AT FIRST SUCCESSFULLY! ";
		    
			system("pause");
			oflinesave(n);
		}
			
	}
		void insertanywhere(int id,node* n){
			system("CLS");
			system("color E4");
			node* ptr = nodeexist(id);
			if(ptr==NULL){
				cout<<"ID that you entered is not in linked list! ";
			}
			else{
				if(nodeexist(n->id)!=NULL){
				cout<<"\n Contact Id existed already.use another key! ";
			}
			else{
			    n->next = ptr->next;
			    ptr->next = n;
			    cout<<"\n CONTACT IS SAVED AFTER "<<id<<" SUCCESSFULLY! ";
			    oflinesave(n);
			}
			}
			
			system("pause");
		}
 void deletenodebykey(int id){
 	system("CLS");
 	system("color E4");
    	if(start == NULL){
    		cout<<"\n Contact Book  is empty";
		}
		else if(start !=NULL){
			if(start->id==id){
				start = start->next;
				cout<<"\n DELETED SUCCESSFULLY! ";
			}
			else{
				node* temp = NULL;
				node* prevnode = start;
				node* currentnode = start->next;
				while(currentnode!=NULL){
					if(currentnode->id==id){
						temp = currentnode;
						currentnode = NULL;
					}
					else{
						prevnode = prevnode->next;
						currentnode = currentnode->next; 
					}
				}
				if(temp!=NULL){
					prevnode->next = temp->next;
					cout<<"\n DELETED SUCCESSFULLY! ";
				}
				else{
					cout<<"\n Contact doesn't  exist with this key value";
				}
			}
		}
		system("pause");
	}
		void update(int id,string name,string address,string email,string contact){
			system("CLS");
			system("color E4");
			if(start==NULL){
				cout<<"\n NO DATA IN CONTACTLIST CURRENTLY! ";
			}
			else{
				node* ptr = start;
			while(ptr!=NULL){
				if(ptr->id==id){
					ptr->name = name;
					ptr->address = address;
					ptr->email = email;
					ptr->contact = contact;
					cout<<"\n UPDATED! ";
					oflinesave(ptr);
				}
				ptr = ptr->next;
			}
			
			
			}
			system("pause");
		}
		void print(){
			system("CLS");
			system("color E4");
			if(start==NULL){
				cout<<"\n YOU NOT  ENTERED ANY DATA CURRENTLY! ";
			}
			else{
			node* ptr = start;
			cout<<"\n\n\t"<<"ID"<<setw(25)<<"NAME"<<setw(20)<<"CONTACT"<<setw(20)<<"ADDRESS"<<setw(25)<<"EMAIL"<<setw(25)<<endl;
			while(ptr!=NULL){
				cout<<"\n\n\t"<<ptr->id<<setw(25)<<ptr->name<<setw(20)<<ptr->contact<<setw(25)<<ptr->address<<setw(25)<<ptr->email<<setw(25)<<endl;
				ptr= ptr->next;
			}
		}
		system("pause");
	}
		void searching(int id){
			system("CLS");
			system("color E4");
			if(start==NULL){
				cout<<"\n CURRENTLY YOU DO NOT ENTERED ANY DATA: ";
			}
			else{
				node*  ptr = start;
				while(ptr!=NULL){
					if(ptr->id==id){
						cout<<"\n Data found! ";
						cout<<"\n\n\t"<<ptr->id<<endl
						<<"NAME: "<<ptr->name<<endl
						<<"CONTACT: "<<ptr->contact<<endl
						<<"ADDRESS: "<<ptr->address<<endl
						<<"EMAIL: "<<ptr->email<<endl;
						break;
					}
					ptr = ptr->next;
				}
				
			}
			system("pause");
		}	
		void oflinesave(node* n)
    	{
    		node *temp;
    		temp = n;
    		ofstream myfile ("contact.txt",ios::app);
            if (myfile.is_open())
            {
            	
	        	    myfile<<"ID: "<<temp->id<<endl;
		        	myfile<<"NAME: "<<temp->name<<endl;
		        	myfile<<"CONTACT: "<<temp->contact<<endl;
		        	myfile<<"ADDRESS: "<<temp->address<<endl;
		        	myfile<<"EMAIL: "<<temp->email<<endl;
		        	myfile<<"------------------------"<<endl;		
                myfile.close();
            }
            else
            {
            	cout<<"  Thanks file is empty."<<endl;
			}
			system("pause");
		}
		void saved(){
			system("CLS");
			system("color E4");
           char buffer[80];
           ifstream myfile("contact.txt");
           while(!myfile.eof()){
           	myfile.getline(buffer,80);
           	cout<<buffer<<endl;
		   }
          system("pause");
}
};
int main(){
	system("color E4");
		int id,id1;
	string name,address,email,contact;
	linkedlist obj;
	int option;
	do{
		system("CLS");
	cout<<"\n\t\t\t\t WELCOME TO CONTACT BOOK \n\n";
	cout<<"\n\n\t\t\t ___________________________________________";
	cout<<"\n\n\t\t\t| 1 for ADD CONTACT                         |";
	cout<<"\n\n\t\t\t| 2 for ADD CONTACT AT FIRST                |";
	cout<<"\n\n\t\t\t| 3 for ADD CONTACT ANYWHERE IN CONTACTBOOK |";
	cout<<"\n\n\t\t\t| 4 for UPDATING CONTACT                    |";
	cout<<"\n\n\t\t\t| 5 for DELETING CONTACT                    |";
	cout<<"\n\n\t\t\t| 6 for SEARCHING CONTACT                   |";
	cout<<"\n\n\t\t\t| 7 for PRINTING CONTACT                    |";
	cout<<"\n\n\t\t\t| 8 for PRINTING HISTORY OF CONTACTBOOK     |";
	cout<<"\n\n\t\t\t| 0 for EXIT CONTACTBOOK                    |";
	cout<<"\n\n\t\t\t|___________________________________________|";
	cout<<"\n\n\t\t\t ENTER YOUR CHOICE: ";
	cin>>option;
	node* n1 = new node();
	switch(option){
		case 0:
			break;
		case 1:
			system("CLS");
			cout<<"\n Enter ID : ";
			while(!(cin>>id)){
				cout<<"\n ERROR:";
				cout<<"\n Enter ID: ";
				cin.clear();
				cin.ignore(22,'\n');
			}
			cout<<"\n Enter Name : ";
			cin>>name;
			cout<<"\n Enter Contact Number : ";
			cin>>contact;
			cout<<"\n Enter Address: ";
			cin>>address;
			cout<<"\n enter Email : ";
			cin>>email;
			n1->id = id;
			n1->address = address;
			n1->contact = contact;
			n1->email = email;
			n1->name = name;
			obj.appendnode(n1);
			break;
		case 2:
			system("CLS");
			cout<<"\n Enter ID : ";
			while(!(cin>>id)){
				cout<<"\n ERROR:";
				cout<<"\n Enter ID: ";
				cin.clear();
				cin.ignore(22,'\n');
			}
			cout<<"\n Enter Name : ";
			cin>>name;
			cout<<"\n Enter Contact Number : ";
			cin>>contact;
			cout<<"\n Enter Address: ";
			cin>>address;
			cout<<"\n enter Email : ";
			cin>>email;
			n1->id = id;
			n1->address = address;
			n1->contact = contact;
			n1->email = email;
			n1->name = name;
			obj.prependnode(n1);
			break;
			case 3:
			   system("CLS");
				cout<<"\n enter after which id you want to append: ";
				while(!(cin>>id1)){
				cout<<"\n ERROR:";
				cout<<"\n Enter ID: ";
				cin.clear();
				cin.ignore(22,'\n');
			}
			cout<<"\n Enter ID : ";
			while(!(cin>>id)){
				cout<<"\n ERROR:";
				cout<<"\n Enter ID: ";
				cin.clear();
				cin.ignore(22,'\n');
			}
			cout<<"\n Enter Name : ";
			cin>>name;
			cout<<"\n Enter Contact Number : ";
			cin>>contact;
			cout<<"\n Enter Address: ";
			cin>>address;
			cout<<"\n enter Email : ";
			cin>>email;
			n1->id = id;
			n1->address = address;
			n1->contact = contact;
			n1->email = email;
			n1->name = name;
			obj.insertanywhere(id1,n1);	
			break;
			case 4:
		        system("CLS");
				cout<<"\n enter  which id you want to update: ";
				while(!(cin>>id1)){
				cout<<"\n ERROR:";
				cout<<"\n Enter ID: ";
				cin.clear();
				cin.ignore(22,'\n');
			}
			cout<<"\n Enter Name : ";
			cin>>name;
			cout<<"\n Enter Contact Number : ";
			cin>>contact;
			cout<<"\n Enter Address: ";
			cin>>address;
			cout<<"\n enter Email : ";
			cin>>email;
			n1->address = address;
			n1->contact = contact;
			n1->email = email;
			n1->name = name;
				obj.update(id1,name,address,email,contact);
			break;
			case 5:
				system("CLS");
				cout<<"\n PRESS 1 FOR DELETING ENTIRE CONTACT LIST! ";
				cout<<"\n PRESS 2 FOR DELETING SPECIFIC ID! ";
				int cdelete;
				while(!(cin>>cdelete)){
				cout<<"\n ERROR:";
				cout<<"\n Enter AGAIN: ";
				cin.clear();
				cin.ignore(22,'\n');
			}
				if(cdelete==2){
					cout<<"\n enter ID: ";
		    while(!(cin>>id1)){
				cout<<"\n ERROR:";
				cout<<"\n Enter ID: ";
				cin.clear();
				cin.ignore(22,'\n');
			}
		    cin.ignore();
			obj.deletenodebykey(id1);
				}
				else if(cdelete==1){
					obj.start =NULL;
					cout<<"\n deleted! ";
					system("pause");
				}
			
			break;
			case 6:
				 system("CLS");
				 cout<<"\n ENTER WHICH ID YOU WANT TO SEARCH: ";
				 while(!(cin>>id)){
				cout<<"\n ERROR:";
				cout<<"\n Enter ID: ";
				cin.clear();
				cin.ignore(22,'\n');
			}
				obj.searching(id);
				 break;
			case 7:
			obj.print();
			break;
			case 8:
				obj.saved();
				break;
			default:
			cout<<"\n invalid";
			system("pause");
			break;	 	 
		}
			
	}
	
while(option!=0);

}