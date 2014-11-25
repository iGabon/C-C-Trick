#include<iostream>
#include<stdlib.h>

using namespace std;

class Node
{
				public:
							int key;
							Node* next;
};

void insert(Node* &L,int k)
{
			Node* newNode = (Node*)malloc(sizeof(Node));
			if(!newNode)
							return;
			newNode->key = k;
			newNode->next = L;
			L = newNode;
}

void reverse(Node* &L)
{
				int i = 0;
				Node* pre;
				Node* temp;
				while(L->next)
				{
								temp = L->next;
								if(!i)
								{
												L->next = NULL;
												i++;
								}
								else
												L->next = pre;
								pre = L;
								L = temp;
				}
				L->next = pre;
}

int main(void)
{
				Node* L = NULL;
				insert(L,1);
				insert(L,2);
				insert(L,3);
				insert(L,14);
				insert(L,15);
				insert(L,16);
				insert(L,17);
				Node* x = L;
				cout<<"before reverse : ";
				while(x)
				{
								cout<<x->key<<" ";
								x=x->next;
				}
				cout<<endl;
				reverse(L);
				x = L;
				cout<<"after reverse : ";
				while(x)
				{
								cout<<x->key<<" ";
								x=x->next;
				}
				cout<<endl;

		return 0;
}
