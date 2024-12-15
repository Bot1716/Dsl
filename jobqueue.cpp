#include<iostream>
#define MAX 10
using namespace std;
struct queue{
    int data[MAX];
    int front,rear;
};
class Queue{
    struct queue q;
    public:
        Queue(){
            q.front=-1;
            q.rear=-1;
        }
        int isEmpty();
        int isFull();
        void enqueue(int);
        int delqueue();
        void display();
};
int Queue :: isEmpty(){
    return(q.front==q.rear)?1:0;
}
int Queue :: isFull(){
    return(q.rear==MAX-1)?1:0;
}
void Queue :: enqueue(int x){
    q.data[++q.rear] = x;
}
int Queue :: delqueue(){
    return(q.data[++q.front]);
}
void Queue :: display(){
    for(int i = q.front + 1 ; i<=q.rear ; i++){
        cout << q.data[i]<<" ";
    }
}
int main(){
    Queue obj;
    int ch, x;
    do{
        cout<<"\n 1. Add job "<<"\n 2. Delete job "<<"\n 3. Display job "<<"\n 4. Exit ";
        cout<<"\nEnter your choice : ";
        cin>>ch;
        switch(ch){
            case 1:
                if(!obj.isFull()){
                    cout<<"Enter the data : ";
                    cin>>x;
                    obj.enqueue(x);
                }
                else{
                    cout<<"Queue overflow";
                }
                break;
            case 2:
                if(!obj.isEmpty()){
                    cout<<"Deleted job : "<<obj.delqueue()<<endl;
                }
                else{
                    cout<<"Queue underflow !";
                }
                cout<<"Remaining jobs : ";
                obj.display();
                break;
            case 3:
                if(!obj.isEmpty()){
                    cout<<"Queue contains : ";
                    obj.display();
                }
                else{
                    cout<<"No jobs to display : ";
                }
                break;
            case 4:
                cout<<"Exited successfully ";
                break;
        }
    }while(ch!=4);
    return 0;
}
