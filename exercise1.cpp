/*
 * Author	: Prayudha Adhitia Libramawan
 * NPM		: 140810180008
 * Kelas	: B
 * Tanggal	: 08/05/2019
 * Deskripsi: Circular Queue Array
*/
#include<iostream>
using namespace std;

const int maxE=5;
struct Queue{
    char nama[maxE];
    int head;
    int tail;
};

void createQueue(Queue& Q){
    Q.head = -1;
    Q.tail = -1;
}

void enQueue(Queue &Q){
    if(Q.head==-1){
		Q.head++;
		Q.tail++;
		cin>>Q.nama[Q.head];
	}else{
		if(Q.tail<maxE-1){
			Q.tail++;
			cin>>Q.nama[Q.tail];
		}else{
			if(Q.head==0){
				cout<<"Antrian is Full!"<<endl;
			}else{
				Q.tail=0;
				cin>>Q.nama[Q.tail];
        	}
	    }
    }
}

void deQueue(Queue& Q){
     cout<<"Delete Queue (Antrian) "<<endl; 
    if (Q.head==-1 ) {
        cout<<"Antrian is Empty"<<endl; 
    } else if (Q.head==Q.tail){
		Q.head=-1;
		Q.tail=-1;
	}else{
		if(Q.head<maxE-1){
			Q.head++;
		}else{
			Q.head=0;
		}
	}
}

void print(Queue Q){
	if(Q.head==-1){
		cout<<"Antrian is Empty."<<endl;
	}else{
		int i=Q.head;
		cout<<endl<<"Antrian = [";
		if(Q.head>Q.tail){
			while(i<maxE){
				cout<<Q.nama[i];
				if(i!=Q.tail){
					cout<<", ";
				}
				i++;
			}
			i=0;
			while(i<=Q.tail){
				cout<<Q.nama[i];
				if(i!=Q.tail){
					cout<<", ";
				}
				i++;
			}
		}
		else{
			while(i<=Q.tail){
				cout<<Q.nama[i];
				if(i!=Q.tail){
					cout<<", ";
				}
				i++;
			}
		}
		cout<<"]"<<endl;
	}
}

int main(){
    Queue Q;
	int opt,n;
	char loop;
	createQueue(Q);
	do{
		cout<<"Banyak Orang dalam Antrian(MAX 5): ";
		cin>>n;
	}while(n>maxE);
	cout<<"Input Nama(Inisial) : "<<endl;
	for(int i=0; i<n; i++){
		enQueue(Q);
	}
	do{
		system("cls");
        cout<<"\n\tMenu\n";
		cout<<"1. Push\n2. Pop\n3. View All"<<endl;
		do{
            cout<<"opt : ";
			cin>>opt;
		}while(opt<1 || opt>3);
		switch(opt){
			case 1:
				if(Q.head!=0){
					cout<<"Input Nama(Inisial) :"<<endl;
				}
				enQueue(Q);
				break;
			case 2:
				deQueue(Q);
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
