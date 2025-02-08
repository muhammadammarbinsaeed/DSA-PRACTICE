#include<iostream>
#include<windows.h>
using namespace std;
class stack{
	private:
		 int top ;
		 int array[5];
	public:
	    stack(){
	    	top= -1;
	    	for(int i=0;i<5;i++){
	    		array[i]=0;
			}
		}	 
//		stack works on first in last out(filo) or last in fast out(lifo)
//		isfull to check wheter stack is full or not
      bool isfull(){
      	if(top>=4)
      	return true;
      	else
      	return false;
	  }
//	 isempty to check whether the stack is empty or not.
     bool isempty(){
     	if(top==-1)
     	return true;
     	else
     	return false;
	 } 
//	 push to enter some values.
    void push(int value){
    	if(isfull()){
    		cout<<"\n stack overflow! ";
		}
		else{
			top++;
			array[top] = value;
		}
	}
//	 pop to access and remove the  value.
//   it will remove and also return that pop value.
   int pop(){
   	if(isempty()){
   		cout<<"\n stack underflow! ";
   		return 0;
	   }
	   else{
	   	  int popvalue = array[top];
	   	  array[top] = 0;
	   	  top--;
	   	  return popvalue;
	   }
   }
//   count operation
int count(){
	return (top+1);
}
// peek operation to access value on some index(position).
   int peek(int position){
   	if(isempty()){
   		cout<<"\n stack underflow! ";
   		return 0;
	   }
	   else{
	   	return array[position];
	   }
   }
//   change
  void change(int position,int value){
  	if(isempty()){
   		cout<<"\n stack underflow! ";
	   }
	   else{
	   	array[position] = value;
	   	cout<<"\n value is changed at given index! ";
	   }
  }
//  print from top to bottom so that it will show as stack.
  void print(){
  	cout<<"\n values of stack are: ";
  	cout<<endl;
  	for(int  i=4;i>=0;i--){
  		cout<<"\n"<<array[i];
	  }
  }
};
void clearscreen(){
	system("CLS");
}
int main(){
	stack obj;
	int  option,position,value;
	do{
		cout<<"\n following operations! ";
		cout<<"\n 1 for push! ";
		cout<<"\n 2 for pop! ";
		cout<<"\n 3 for check empty!  ";
		cout<<"\n 4 for check full!  ";
		cout<<"\n 5 for display!  ";
		cout<<"\n 6 for peek! ";
		cout<<"\n 7 for change!  ";
		cout<<"\n 8 for count number of stack!  ";
		cout<<"\n 9 for clear screen!  ";
		cout<<"\n 0 to exit! ";
		cin>>option;
		switch(option){
			case 0:
				break;
			case 1:
			   cout<<"\n enter value to push: ";
			   cin>>value;
			   obj.push(value);
			   break;
			case 2:
			    cout<<"\n pop function is called: ";
			    cout<<"\n the value "<<obj.pop()<<" is poped from stack! ";
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
			     if(obj.isfull()){
			    	cout<<"\n stack is full! ";
				}	  	
				else{
					cout<<"\n stack is not full! ";
				}	
				break;
			case 5:
			     obj.print();
				 break;
			case 6:
			     cout<<"\n enter position to peek the element: ";
				 cin>>position;
				 cout<<"\n the element at this position is "<<obj.peek(position)<<" ! ";
				 break;
			case 7:
			     	 cout<<"\n enter position to change the element: ";
				 cin>>position;
				 cout<<"\n enter new value: ";
				 cin>>value;
				 obj.change(position,value);
				 break;	 	
			case 8:
			     cout<<"\n number of elements in stack are "<<obj.count();
				 break;
			case 9:
			   clearscreen();
			   break;	 	 
		}
		
	}
	while(option!=0);
}
