#include <iostream>
#include <cstring>
#include "tree.h"
using namespace std;

int main(){
  int select,num;
  node *delNode;
  
  tree *bst=new tree();
  //cout<<"<Binary Search Tree>"<<endl;

  int count=0;
  char Filename[128]; //파일 이름
  char command[2];
  int key;
  char value[128];
  string add = "a";
  string print = "p";
  string quit = "q";
  string del = "d"; //각 커맨드를 구분 하기 위해 만든 string
  FILE *fp;
  //cout<<"Input : ";
  cin>>Filename;

  fp=fopen(Filename,"rt");
	if(fp==NULL){
	printf("=>파일 없음\n");
	return 0;
	}



	for(; ; count++){
    fscanf(fp,"%s",command);
    string confirm(command);
    if(0==confirm.compare(add)){
      fscanf(fp,"%d %s",&key,value); //a라면 그 뒤에 두 개의 값이 더 있을 테니 이어서 fscanf를 하는 것
      string contentvalue(value);
      node *temp= new node(key, contentvalue);
      bst->insert(temp);
    }
    if(0==confirm.compare(del)){
      fscanf(fp,"%d",&key); //d라면 뒤에 1개의 값 즉 key값을 fscanf를 한다.
      delNode=bst->del(key);
      if(delNode!= NULL) delete delNode;
    }
    if(0==confirm.compare(print)){
      bst->printTree(); 
    }
    if(0==confirm.compare(quit)){
      break;
    }
  
  //printf("%s %d %s\n",command,key,value);
	if(feof(fp)) break;
	
  }
	
	fclose(fp);
	//printf("=> 로딩 성공!\n");
  free(bst);
  return 0;
}
 
