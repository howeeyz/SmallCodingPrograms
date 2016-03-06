#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Node{
    int value;  
    struct Node* next;
};

typedef struct Node Node;


class queue{

	Node *head;
	Node *tail;
	
	public:

	queue(){
		head = NULL;
		tail = NULL;
	}

	void dequeue(){
		if(head == NULL){
			return;
		}
		else{
			Node *temp = head;
			head = head->next;
			free(temp);
		}
	}

	void enqueue(int value){
		if(tail == NULL){
			head = new Node;
			head->value = value;
			head->next = NULL;
			tail = head;
		}
		else{
			tail->next = new Node;
			tail = tail->next;
			tail->value = value;
			tail->next = NULL;
		}
	}

	int peek(){
        if(head != NULL){
		    return head->value;
        }
        return 0;
	}

};

int main(void){
	queue tester;
    tester.enqueue(1);
    cout << tester.peek() << "\n";
    tester.enqueue(2);
    cout << tester.peek() << "\n";
    tester.dequeue();
    cout << tester.peek() << "\n";
    return 0;
}