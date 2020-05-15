#include <iostream>
#include <cstring>

using namespace std;
class node{
  public :
    int key;
    string value;
    node *left;
    node *right;
    node(){
      key=0;
      value= " ";
      left=NULL;
      right=NULL;
    }
    node(int n, string contentvalue){
      key=n; //입력받은 key 값 저장
      value = contentvalue; //입력받은 value 값 저장
      left=NULL;
      right=NULL;
    }
};

class tree{
  public:
    node *root; //최초 노드 설정
    node *current, *parent;
    int subnodeNum;
    int allcount; //전체 노드 개수
    tree(){
      root=parent=current=NULL;
      allcount=0;
    };
    void insert(node *target){
      current=parent=root;
      if(root==NULL){
        root=target;
        return;
      }
      else{//root가 NULL이 아니라면
        if(!search(target->key)){
          if(target->key<parent->key) parent->left=target; //입력 한 받은 key 값이 더 작다면 parent의 왼족으로 간다
          else parent->right = target; //값이 크다면 오른쪽으로 간다
        }
        else cout<<target->key<<" is already in the tree."<<endl; //혹시 같은 것 즉 먼저 key 값이 들어가 있는 것이라면 원래 있는 것이라고 말해주는 것.
      }
      allcount++; 
      return;
    };

    node *search(int inputKey){
      parent=current=root;
      while(current){
        if(inputKey==current->key) return current;
        parent=current;
        if(inputKey<current->key) {current=current->left;}
        else current=current->right;
      }
      return NULL;
    };

    node *del(int key){//삭제가 되었을 때 왼쪽에 있는 것과 연결
      node *temp;
      temp=search(key);
      int nodeEdgeNum=0;
      if(temp==NULL){
        cout<<key <<" is not in the tree."<<endl;
        return NULL;
      }
      else if(temp->left==NULL&temp->right==NULL){
        if(temp == parent & parent ==current) root=NULL;
        else if(parent->left==temp) parent->left=NULL;
        else parent->right=NULL;
      }
      else if(temp->left!=NULL & temp->right !=NULL){
        node *chnode=temp->left;
        node *chnodeParent=temp;
        while(chnode->right){
          chnodeParent=chnode;
          chnode=chnode->right;
        }
        int token=chnode->key;
        chnode->key=temp->key;
        temp->key=token;
        //삭제 할 때 다시 연결 시켜주는 부분 (key)
        string strtoken=chnode->value;
        chnode->value=temp->value;
        temp->value=strtoken;
        //삭제 할 때 다시 연결 시켜주는 부분 (value)
        if(chnode->left){
          if(chnodeParent==temp) chnodeParent->left=chnode->left;
          else chnodeParent->right=chnode->left;
        }
        else{
          if(chnodeParent==temp) chnodeParent->left=NULL;
          else chnodeParent->right=NULL;
        }
        allcount--;
        return chnode;
      }
      else{
        if(temp->left){
          if(parent==current && temp == root) root=temp->left;
          else if(parent->left==temp) parent->left=temp->left;
          else parent->right=temp->left;
        }
        else{
          if(parent==current && temp==root) root=temp->right;
          else if(parent->left==temp) parent->left=temp->right;
          else parent->right=temp->right;
        }
      }
      allcount--;
      return temp;
    };

    void printTree(){
      printTree(root);
      //cout<<endl;
      if(!root) cout<<"Empty Tree"<<endl<<endl;
    };

    void printTree(node *point){
      if(point){//inoreder traversal로 출력
        printTree(point->left);
        cout<<"("<<point->key<<","<<point-> value<<")"<<endl;
        printTree(point->right);
      }
    };
};
