#include<iostream>
using namespace std;
class queue{
	private:
		 int front ;
		 int rear ;
		 int array[5];
	public:
	     queue(){
	     	front = -1;
	     	rear = -1;
	     	for(int i=0;i<5;i++){
	     		array[i] = 0;
			 }
		 }	 
		 bool isempty(){
		 	if(front==-1&&rear==-1){
		 		return true;
			 }
			 else{
			 	return false;
			 }
		 }
		 bool isfull(){
		 	if(rear==4){
		 		return true;
			 }
			 else{
			 	return false;
			 }
		 }
		 void enqueue(int value){
		 	if(isfull()){
		 		cout<<"\n queue is full ! ";
			 }
			 else if(front==-1&&rear==-1){
			 	front = 0;
			 	rear = 0;
			 	array[front] = value;
			 	cout<<"\n VALUE ENQUEUED! ";
			 }
			 else{
			 	rear++;
			 	array[rear] = value;
			 	cout<<"\n VALUE ENQUEUED! ";
			 }
		 }
		 int dequeue(){
		 	int x;
		 	if(isempty()){
		 		cout<<"\n queue is empty ! ";
		 		return 0;
			 }
			 else if(front==rear){
			 	x = array[front];
			 	array[front] = 0;
			   front =rear =  -1;
			   return x;
			 }
			 else{
			 	x = array[front];
			 	array[front] = 0;
			 	front++;
			 	return x;
			 }
		 }
		 int count(){
		 	return (rear-front+1);
		 }
		 void change(int index){
		 	for(int i=0;i<5;i++){
		 		if(i==index){
		 			cout<<"\n enter value to change: ";
		 			int value;
		 			cin>>value;
		 			array[i]=value;
				 }
			 }
		 }
		 void display(){
		 	cout<<"\n values in queue are: ";
		 	cout<<endl;
		 	for(int i=0;i<5;i++){
		 		cout<<array[i]<<"     ";
			 }
		 }
};
 int main(){
 	queue obj;
	int  option,position,value,val,count;
	do{
		cout<<"\n following operations! ";
		cout<<"\n 1 for enqueue! ";
		cout<<"\n 2 for dequeue ";
		cout<<"\n 3 for check empty!  ";
		cout<<"\n 4 for check full!  ";
		cout<<"\n 5 for display!  ";
		cout<<"\n 6 for count";
		cout<<"\n 7 for change!  ";
		cout<<"\n 8 for clear screen  ";
		cout<<"\n 0 for exit  ";
		cout<<"\n enter choice: ";
		cin>>option;
		switch(option){
			case 0:
				break;
			case 1:
			   cout<<"\n enter value to enqueue: ";
			   cin>>value;
			   obj.enqueue(value);
			   break;
			case 2:
			    val = obj.dequeue();
			   cout<<"\n value "<<val<<"  is dequeued from the queue! ";
				break;
			case 3:
			    if(obj.isempty()){
			    	cout<<"\n queue is empty! ";
				}	  	
				else{
					cout<<"\n queue is not empty! ";
				}
				break;
			case 4:
			     if(obj.isfull()){
			    	cout<<"\n queue is  full ";
				}	  	
				else{
					cout<<"\n queue is not full! ";
				}	
				break;
			case 5:
			     obj.display();
				 break;
			case 6:
			      count = obj.count();
			     cout<<"\n number of elements in queue are: "<<count;
				 break;
			case 7:
			     	 cout<<"\n enter position to change the element: ";
				 cin>>position;
				 obj.change(position);
				 break;	 	
			case 8:
			     system("CLS");
			   break;
		 	 
		}
		
	}
	while(option!=0);
 }