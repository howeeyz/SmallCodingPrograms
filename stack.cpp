#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Node{
    int value;  
    struct Node* next;
};

typedef struct Node Node;

class stack{
    
    Node* head;
    
    public:
    
    stack(){
        head = NULL;
    }
    
    int peek(){
        if(head == NULL)
            return 0;
        else
            return head->value;
    }
    
    void pop(){
        if(head == NULL)
            ;
        else{
            Node* toPop = head;
            head = head->next;
            free(toPop);
        }
    }
    
    void push(int val){
        if(head == NULL){
            head = (Node*)malloc(sizeof(Node));
            head->value = val;
            head->next = NULL;
        }
        else{
            Node* newHead = (Node*)malloc(sizeof(Node));
            newHead->value = val;
            newHead->next = head;
            head = newHead;
        }
    }
        
    int min(){
        int min;
        if(head == NULL)
            return 0;
        else{
            min = head->value;
            Node* traverse = head->next;
            
            while(traverse != NULL){
                if(traverse->value < min)
                    min = traverse->value;
                traverse = traverse->next;
            }
        }
        return min;
    }  

};


int main(void){
    
    stack tester;
    tester.push(1);
    cout << tester.peek() << "\n";
    tester.push(2);
    cout << tester.peek() << "\n";
    cout << tester.min() << "\n";
    tester.pop();
    cout << tester.peek() << "\n";
    return 0;
}