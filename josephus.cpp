#include<iostream>
using namespace std;

struct node{
     int data;
     node *next;

     node(int data){
          this->data = data;
          this->next = NULL;
     }
};

node *insert(node *head, int data){
     if(!head){
          node *temp = new node(data);
          temp->next = temp;
          return temp;
     }

     node *ptr = head;

     while(ptr->next != head)
          ptr = ptr->next;

     ptr->next = new node(data);
     ptr = ptr->next;
     ptr->next = head;
     return head;
}

int survival(node *head, int k){


     while(head->next != head){
          int count = 1;
          node *prev = head;
          while(count < k){
               prev = head;
               head = head->next;
               count += 1;
          }

          prev->next = head->next;
          head = prev->next;
     }
     return head->data;
}

int main(){
     int t = 1;
     //cin >> t;

     while(t--){
          int n,k;
          cin >> n >> k;

          node *head = NULL;
          for(int i = 1; i <= n; i++)
               head = insert(head,i);

          std::cout << survival(head,k) << '\n';
     }
}
