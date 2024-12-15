#include<iostream>
#define MAX 5
using namespace std;
class Pizza{
    int orders[MAX];
    int front, rear;
    public:
    Pizza(){
        front=rear=-1;
    }
    bool isFull(){
        return (rear+1)%MAX == front;
    }
    bool isEmpty(){
        return front == -1;
    }
    void placeOrder(int order){
        if(isFull()){
            cout << "The pizza parlour is at full capacity, cannot accept more orders!";
        }
        else{
            if(front==-1){
                front = 0;
            }
            rear = (rear+1) % MAX;
            orders[rear] = order;
            cout << " The order "<<order <<" has been placed. ";
        }
    }
    void serveOrder(){
        if(isEmpty()){
            cout<<"No orders to serve currently";
        }
        else{
            cout << "Serving order " << orders[front]<<endl;
            if(front == rear){
                front = rear = -1;
            }
            else{
                front = (front + 1)%MAX;
            }
        }
    }
    void display(){
        if(isEmpty()){
            cout<<"No orders to display currently";
        }
        else{
            int i = front;
            while(i!=rear){
                cout<<orders[i]<<" ";
                i = (i+1)%MAX;
            }
            cout<<orders[rear]<<endl;
        }
    }
};
int main(){
    Pizza p;
    int ch,x;
    do{
        cout<<"\n 1. Place order "<<"\n 2. Serve order "<<"\n 3. Display order "<<"\n 4. Exit ";
        cout<<"\nEnter your choice : ";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"Enter order number : ";
                cin>>x;
                p.placeOrder(x);
                break;
            case 2:
                p.serveOrder();
                break;
            case 3:
                p.display();
                break;
            case 4: cout<<" Thank you for visiting, have a nice day :) ";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    while(ch!=4);
    return 0;
}
