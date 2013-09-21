/* It's a Binary search tree */
#include "stdio.h"
#include "stdlib.h"
struct tree{
	int data;
	struct tree *lptr;
	struct tree *rptr;
};
typedef struct tree node;
node *new(){
	return (node *)malloc(sizeof(node));
}
node *root(int value){            //call at the time of initilisation
	node *ptr = new();
	ptr-> data = value;
	ptr-> lptr = 0;
	ptr-> lptr = 0;
	return ptr;
}
void insert(int x, node *ptr){
	if(x > ptr->data){
		if( ptr-> rptr){
			insert(x,ptr-> rptr);
		}else{
			node *temp = new();
			temp-> data = x;
			temp-> lptr = 0;
			temp-> rptr = 0;
			ptr-> rptr = temp;
		}
	}else{
		if( ptr-> lptr){
			insert(x,ptr-> lptr);
		}else{
			node *temp = new();
			temp-> data = x;
			temp-> lptr = 0;
			temp-> rptr = 0;
			ptr-> lptr = temp;
		}
	}
}
void preorder(node *ptr){
	if(ptr){
		printf("%d\n",ptr-> data );
		preorder( ptr-> lptr);
		preorder( ptr-> rptr);
	}
}
void postorder(node *ptr){
	if(ptr){
		postorder( ptr-> lptr);
		postorder( ptr-> rptr);
		printf("%d\n",ptr-> data );
	}
}
void inorder(node *ptr){
	if(ptr){
		inorder( ptr-> lptr);
		printf("%d\n",ptr-> data );
		inorder( ptr-> rptr);
	}
}
node *search(int x, node *ptr){
	if(ptr){
		int y = ptr-> data;
		if(y == x) return ptr;
		else if( y < x ) return search(x,ptr->rptr);
		else return search(x,ptr->lptr);
	}else return 0;
}
node *lchild(int x, node *ptr){
	node *temp;
	if(temp = search(x,ptr)){
		return temp-> lptr;
	}else return 0;
}
node *rchild(int x, node *ptr){
	node *temp;
	if(temp = search(x,ptr)){
		return temp-> rptr;
	}else return 0;
}
int delete(int x, node *ptr){

}
int main(){
	node *rut = root(100);
	insert(95,rut);
	insert(45,rut);
	insert(195,rut);
	insert(145,rut);
	inorder(rut);
	postorder(rut);
	preorder(rut);
	printf("%d\n",search(95,rut)->data);
	printf("%d\n",lchild(100,rut)->data);
	printf("%d\n",rchild(100,rut)->data);
	return 0;
}
