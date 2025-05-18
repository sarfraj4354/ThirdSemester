//Source code
#include<iostream>
using namespace std;
class queue{
	
 int* arr;
 int front;
 int rear;
 int n;

 public:
 queue(int size)    //construct || initialize of queue
 {
  cout<<"Queue is Created"<<endl;
  arr=new int[size];
  front=-1;
  rear=-1;
  n=size;
 }
void enqueue(int x){
  if(rear == n-1){    //could have compare with n only but as rear start with 1 so we had to compare with n-1
    cout<<"The Queue is full"<<endl;
  }
  else{
    rear++;
    arr[rear]=x;
    if (front==-1)
    {
       front++;
    }
  }
}
void dequeue(){
  if(front==-1 || front>rear) {
    cout<<"The Queue is Empty"<<endl;
  }
  else{
    front++;
  }
}
void Display(){
  if(front==-1 || front>rear) {
    cout<<"The Queue is Empty"<<endl;
  }
  else{
    cout<<"Here are the entered data:"<<endl;
    for (int i=front; i < rear+1; i++)
    {
      cout<<"=>"<<arr[i]<<endl;
    }
  }
}
};

int main(){
int size;
int in,n;
  cout<<"Programmer -Sarfraj Alam"<<endl;
  cout << "Basic Operation of Stack" << endl;
  cout << "Enter the size of stack\n=>";
  cin >> size;
  queue q(size);
  while (true)
  {
    cout<<"Programmer -Sarfraj Alam"<<endl;
    cout << "\nEnter your choice\n 1 for enqueue\n 2 for dequeue\n 3 for display\n 4 for exit\n\n=>"; //Menu for the operation
    cin >> n;
    switch (n)
	{
      case 1:
       cout<<"Enter the value to set in queue: ";    //For enqeue operation
       cin>>in;
       q.enqueue(in);
       break;
      case 2:    //For dequeue Operation
       q.dequeue();
       break;
      case 3:    //For Display Operation
       q.Display();
       break;
      case 4:
	   exit(0);
	  default:
	   cout<<"Inavalid choice. Please try again."<<endl;
	}
  }
  return 0;
}
