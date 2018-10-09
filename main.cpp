#include <iostream>
#include<cstdlib>

using namespace std;
struct Arrayqueue
{

    int rear,front;
    int capacity;
    int *array;
};
struct Arrayqueue* createqueue(int capacity)
{
    struct Arrayqueue* q=(struct Arrayqueue*)malloc(sizeof(struct Arrayqueue));
if(!q)
    return NULL;
q->capacity=capacity;
q->front=q->rear=-1;
q->array=(int*)malloc(q->capacity*sizeof(int));
if(!q->array)
    return NULL;
return(q);
}
int isempty(struct Arrayqueue* q)
{
    return (q->front==-1);
}
int isfull(struct Arrayqueue* q)
{

    return((q->rear+1)%q->capacity==q->front);
}
int queuesize(struct Arrayqueue* q)
{
    return((q->capacity-q->front+q->rear+1)%q->capacity);
}
void enqueue(struct Arrayqueue* q,int data)
{
    if(isfull(q))
        cout<<"overflow";
    else
    {
        q->rear=(q->rear+1)%q->capacity;
        q->array[q->rear]=data;
        if(q->front==-1)
            q->front=q->rear;
    }
}
int dequeue(struct Arrayqueue* q)
{

    int data=-1;
    if(isempty(q))
    {
        cout<<"queue is empty";
        return -1;
    }
    else
    {
        data=q->array[q->front];
        if(q->front==q->rear)
            q->front=q->rear=-1;
        else
            q->front=(q->front+1)%q->capacity;
    }
    return data;
}
int main()
{struct Arrayqueue* q;
q=createqueue(4);
int choice,item;
while(1)
{
cout<<"1 foe enqueue"<<endl;
cout<<"2 for dequeue"<<endl;
cout<<"3 for exit(()"<<endl;
cout<<"enter your choixe"<<endl;
cin>>choice;
switch(choice)
{

case 1:
    {
        cout<<"enter the item"<<endl;
        cin>>item;
        enqueue(q,item);
        break;

    }
case 2:
    {
        item=dequeue(q);

        if(item==-1)
            cout<<"queue is empty"<<endl;
        else
            cout<<item;
        break;
    }
case 3:
    {
        exit(0);
    }

}
}






}
