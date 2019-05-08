/*
 * Author	: Prayudha Adhitia Libramawan
 * NPM		: 140810180008
 * Kelas	: B
 * Tanggal	: 08/05/2019
 * Deskripsi: Linked List - Queue
*/
#include <iostream>
using namespace std;

const int maxE=5;
struct node{
	char info;
	node *next;
};
struct queue{
	node *head;
	node *tail;
};

void createQueue(queue &Q){
	Q.head=NULL;
	Q.tail=NULL;
}
void createNode(node* &newNode){
	newNode=new node;
	cin>>newNode->info;
	newNode->next=NULL;
}
void enQueue(queue &Q, node* &newNode){
	if(Q.head==NULL){
		Q.head=newNode;
		Q.tail=newNode;
	}else{
		Q.tail->next=newNode;
		Q.tail=newNode;
	}
}
void deQueue(queue &Q){
	if(Q.head==NULL){
		cout<<"Antrian is empty."<<endl;
	}else{
		node *delNode;
		delNode=Q.head;
		Q.head=Q.head->next;
		delNode->next=NULL;
	}
}
void print(queue Q){
	if(Q.head==NULL){
		cout<<"Antrian is empty."<<endl;
	}else{
		node *travNode=Q.head;
		cout<<endl<<"Q = [";
		while(travNode!=NULL){
			cout<<travNode->info;
			if(travNode->next!=NULL){
				cout<<", ";
			}
			travNode=travNode->next;
		}
		cout<<"]"<<endl;
	}
}

int main(){
	queue Q;
	node *p;
	int banyak,pil;
	char loop;

	createQueue(Q);
	do{
		cout<<"Banyak Orang dalam Antrian(MAX 5): ";
		cin>>banyak;
	}while(banyak>maxE);
	cout<<"Input Nama(Inisial) : "<<endl;
	for(int i=0; i<banyak; i++){
		createNode(p);
		enQueue(Q,p);
	}
	do{
		system("cls");
        cout<<"\n\tMenu\n";
		cout<<"1. Push\n2. Pop\n3. View All"<<endl;
		do{
			cin>>pil;
		}while(pil<1 && pil>3);
		switch(pil){
			case 1:
				if(banyak<5){
					cout<<"Input Nama(Inisial) : ";
					createNode(p);
					enQueue(Q,p);
					banyak++;
				}else{
					cout<<"Antrian is Full";
				}
				break;
			case 2:
				deQueue(Q);
				if(banyak>0){
					banyak--;
				}
				break;
			case 3:
				print(Q);
				break;
		}
        cout<<endl<<"Back to menu? (Y/N) ";
		cin>>loop;
	}while(loop=='Y' || loop=='y');

	cout<<endl<<"Thank You!"<<endl;
}