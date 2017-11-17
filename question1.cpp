#include <iostream>
using namespace std;
class node
{
 public:
 int data;
 node *next;
};
class linkedList
{
 private:
 node *head;
 node *tail;int n;
 public:
 linkedList()
 {
  head=NULL;
  tail=NULL;
 }
 void addNode(int data)
 {
  node *temp=new node();
  temp->data=data;
  temp->next=NULL;
  if(head==NULL)
  {
   head=temp;
   tail=temp;
   n++;
  }  
  else
  {
   tail->next=temp;
   tail=temp; 
   n++;
  }
 }
 void insertNode(int data, int n1)
 {
  node *temp=new node();
  node *t=new node();
  node *t1=new node();
  t1->data=data;
  t1->next=NULL;
  temp=head;
  for(int i=1;i<n1-1;i++)
  {
   temp=temp->next;
  }
  t=temp->next;
  temp->next=t1;
  t1->next=t;
 }
 void deleteNode(int n1)
 {

	if (n1 >= n) {
		cout << "Invalid index." << endl;
	} else if (n1 == 0) {
		head = head->next;
		--n;
	} else if (n1 == n-1) {
		node* move = head;
		for (int j=0; j<n1-1; ++j) {
			move = move->next;
		}

		tail = move;
		move->next = NULL;
		--n;
	} else {
		node* move = head;
		for (int j=0; j<n1-1; ++j) {
			move = move->next;
		}

		move->next = (move->next)->next;
		--n;
	}
 }
 void display()
 {
  if(head==NULL)
  {
   cout << "Nothing";
  }
  else
  {
   node *temp = head;
   while(temp != NULL)
   {
    cout << temp->data;
    cout<<" ";
    temp = temp->next;
   }
  }
 }
};
int main()
{
	linkedList l1;
	int n=0;
	cout << "Enter five elements to the list: " << endl;
	for (int i=0; i<5; ++i) {
		cin >> n;
		l1.addNode(n);
	}

	cout << endl;
	l1.display();
	
	l1.insertNode(8,3);
	cout<<endl;
	l1.display();

	l1.deleteNode(4);

	cout << endl;
	l1.display();
	
	

}
