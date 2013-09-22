/* It's a Binary search tree */
#include "stdio.h"
#include "stdlib.h"
struct tree{
	int data;
	struct tree *father;
	struct tree *lptr;
	struct tree *rptr;
};
typedef struct tree node;
node *rut;
node *new(){
	return (node *)malloc(sizeof(node));
}
node *root(int value){            //call at the time of initilisation
	node *ptr = new();
	ptr-> data = value;
	ptr-> father = 0;
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
			temp-> father = ptr;
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
			temp-> father = ptr;
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
node *parent(int x, node *ptr){
	node *temp;
	if(temp = search(x,ptr)){
		return temp-> father;
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
	node *temp;
	if(temp = search(x,ptr)){
		if(temp == ptr){						   /// ROOT
			node *z = ptr-> rptr;
			ptr-> rptr-> father = 0;
			while( z-> lptr) z = z-> lptr;
			z-> lptr = ptr-> lptr;
			rut = ptr-> rptr;
			free(ptr);
		}else if(ptr-> lptr && ptr-> rptr){		   /// Both child
			node *z,*temp = ptr-> father;
			temp-> rptr = ptr-> rptr;
			ptr-> rptr-> father = temp;
			z = temp-> rptr;
			while( z-> lptr) z = z-> lptr;
			z-> lptr = ptr-> lptr;
			free(ptr);
		}else if(ptr-> lptr && !ptr-> rptr){       /// Left child only
			node *temp = ptr-> father;
			temp-> lptr = ptr-> lptr;
			ptr-> lptr-> father = temp;
			free(ptr);
		}else if(!ptr-> lptr && ptr-> rptr){	   /// Right child only
			node *temp = ptr-> father;
			temp-> rptr = ptr-> rptr;
			ptr-> rptr-> father = temp;
			free(ptr);
		}else{                                     /// No child
			node *temp = ptr-> father;
			int k = temp->data;
			if(k < x) temp-> rptr = 0;
			else temp-> lptr = 0;
			free(ptr);
		}
		return(x);
	}else{
		printf("NOT FOUND\n");
		return 0;
	}
}
int main(){
	rut = root(100);
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
	printf("%d\n",delete(100,rut));
	preorder(rut);
	return 0;
}
