#include<iostream>
#include<queue>
#include<map>
using namespace std;

struct Node {
     int data;
     Node *left;
     Node *right;

     Node(int data){
          this->data = data;
          this->left = NULL;
          this->right = NULL;
     }
};

Node *insert(Node *root, int data){
     if(!root)
          return new Node(data);

     if(root->data > data)
          root->left = insert(root->left,data);
     if(root->data < data)
          root->right = insert(root->right,data);
     return root;
}

void display(Node *root){
     if(!root)
          return;

     display(root->left);
     std::cout << root->data << ' ';
     display(root->right);
}

int height(Node *root){
     if(!root)
          return 0;
     int left = height(root->left);
     int right = height(root->right);
     return (left > right ? left : right) + 1;
}

void print(Node *root, int height, int &max){tive integers from
    if(!root)
        return;

    if(height > max){
        cout << root->data << " ";
        max = height;
    }
    print(root->left,height+1,max);
    print(root->right,height+1,max);
}

void leftView(Node *root)
{
    if(!root)
        return ;
   int max = -1;
   print(root,0,max);

}


void topView(Node *root){

     map<int,int> m;
     queue<pair<int,Node *>> q;

     pair<int,Node *> p = make_pair(0,root);
     q.push(p);

     while(!q.empty()){
          pair<int, Node *> p = q.front();
          q.pop();

          int hd = p.first;
          Node *node = p.second;

          if(m.count(hd) == 0)
               m[hd] = node->data;

          if(node->left){
               pair<int, Node *> t = make_pair(hd-1,node->left);
               q.push(t);
          }

          if(node->right){
               pair<int, Node *> t = make_pair(hd+1,node->right);
               q.push(t);
          }
     }


     map<int,int> :: iterator it;
     for(it = m.begin(); it != m.end(); it++)
          std::cout << it->second << ' ';
     std::cout << '\n';
}

void bottomView(Node *root){
     map<int,int> m;
     queue<pair<int,Node*>> q;

     pair<int,Node *> p = make_pair(0,root);
     q.push(p);

     while(!q.empty()){
          pair<int,Node*> p = q.front();
          q.pop();

          int hd = p.first;
          Node *node = p.second;

          m[hd] = node->data;

          if(node->left){
               pair<int,Node*> t = make_pair(hd-1,node->left);
               q.push(t);
          }

          if(node->right){
               pair<int,Node *> t = make_pair(hd+1,node->right);
               q.push(t);
          }
     }


     map<int,int> :: iterator it;
     for(it = m.begin(); it != m.end(); it++)
          std::cout << it->second << ' ';
     std::cout << '\n';
}

int main(){
     Node *root = NULL;
     while(true){
          int n;
          cin >> n;

          if(n == -1)
               break;
          root = insert(root,n);
     }

     //display(root);
     //leftView(root);
     //std::cout << '\n';
     //topView(root);
     bottomView(root);
}

/*
4 3 8 6 5 7 9 -1
5 1 2 3 4 8 -1
5 3 1 4 7 6 8 -1
*/
