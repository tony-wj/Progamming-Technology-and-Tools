#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    int key;
    Node *next;
};

void headInsert(Node *&head, int k); // Given
void printList(Node *head); // Given
void insertInOrder(Node *&head, int k); // Implemented by you

int main()
{
    Node *head = NULL;

    int n;
    cin >> n;
    int inputK;
    for (int i=0 ; i< n ; i++)
    {
        cin >> inputK ;
        headInsert(head, inputK);
    }

    cin >> inputK;
    insertInOrder(head, inputK);

    printList(head);
}

void headInsert(Node *&head, int k)
{
    Node *newNode = new Node;
    newNode -> key = k;
    newNode -> next = head;
    head = newNode;
}

void printList(Node *head)
{
    Node *current = head;
    while (current!=NULL)
    {
        cout << "Key:" << current->key << endl;
        current = current->next;
    }
}

// Please implement void insertInOrder(Node *&head, int k) here.
void insertInOrder(Node *&head, int k){
	Node *current = head;
	if (current == NULL || current->key > k){
		headInsert(head, k);//insert head
	}else{
		Node *next = current->next;
		while(next!=NULL){
			if(next->key > k){
				Node *newNode = new Node;
				newNode ->key = k;
				newNode ->next = current->next;
				current->next = newNode;
				return;
			}
			current = current ->next;
			next = current ->next;
		}
		Node *newNode = new Node;
		newNode ->key = k;
		newNode ->next = current->next;
		current->next = newNode;//insert tail
	}

}