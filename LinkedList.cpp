#include <iostream>
#include<conio.h>
#include<math.h>
using namespace std;
class LinkedList
{

public:
class Node
{
    private:
    int data;
    Node *next;
public:
    Node(){
data=0;
next=NULL;
    }
    Node (int data)
    {
        this->data = data;
        this->next = NULL;
    }
    //Used Getters and Setters//
    int getData ()
    {
        return this->data;
    }
    void setData(int data)
    {
       this->data=data;
    }

  Node *getNext(){

  return next;
  }
  void setNext(Node *node)
  {
  this->next=node;
  }
};

    LinkedList()
    {
        head = NULL;
    }

    bool isEmpty()
    {
        return head == NULL;
    }
       void insert(int val)
    {
        insertAtLast(val);
    }

    Node *getFirstElement()
    {

        if (!isEmpty())
        {
            return head;
        }
    }

    Node *getLastElement()
    {
        return getNode(getLength());
    }

    void insertAtBegin(int val)
    {
        Node *node = new Node(val);
        if (isEmpty())
            head = node;
        else
        {
            node->setNext(head);
            head = node;
        }
    }

    void insertAtLast(int val)
    {
        Node *node = new Node(val);

        if (isEmpty())
            head = node;
        else
        {
            Node *temp = head;
            while (temp->getNext() != NULL)
            {
                temp = temp->getNext();
            }
            temp->setNext(node);
        }
    }

    void removeFromBegin()
    {
        if (!isEmpty())
        {
            Node *temp = head;
            head = head->getNext();

            delete temp;
        }
    }
    void removeFromLast()
    {
        if (!isEmpty())
        {
            int lastpos = getLength();
            int seclastpos = lastpos - 1;
            Node *last = getNode(lastpos);
            Node *seclast = getNode(seclastpos);
            delete last;
            seclast->setNext(NULL);
        }
    }

    int getLength()
    {
        int count = 0;
        if (!isEmpty())
        {
            Node *temp = head;
            while (temp != NULL)
            {
                temp = temp->getNext();
                count++;
            }
        }
        return count;
    }
    Node *getNode(int position)
    {
        if (!isEmpty())
        {
            Node *temp = head;
            for (int i = 0; i < position - 1; i++)
            {
                temp = temp->getNext();
            }
            return temp;
        }
        return head;
    }

       void display()
    {

        Node *temp = head;
        while (temp != NULL)
        {
            cout <<" "<< temp->getData();
            temp = temp->getNext();
        }
        cout << endl;
    }

private:
    Node *head;
};

int main()
{

    LinkedList Li;
    Li.insertAtBegin(10);
    Li.insertAtLast(15);
    Li.insertAtLast(20);
    Li.insertAtLast(25);
    Li.insertAtLast(30);
    cout<<"First Element is->"<<Li.getFirstElement()->getData()<<endl;
   cout<<"Last Element is->"<<Li.getLastElement()->getData()<<endl;
   cout <<"Total size is->"<< Li.getLength() << endl;
cout<<"LIst the Elements that stored in linkedlist"<<endl;
Li.display();
    cout<<"list After removed first element"<<endl;
Li.removeFromBegin();
    Li.display();
       cout<<"list After removed Last element"<<endl;
       Li.insertAtBegin(10);
Li.removeFromLast();
    Li.display();
    return 0;
}
