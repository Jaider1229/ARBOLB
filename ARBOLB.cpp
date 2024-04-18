#include<iostream>
#include<queue>

using namespace std;

struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
};

void menu();
Nodo *crearNodo(int n);
void insertar(Nodo *&, int);
void mostrarArbol(Nodo *, int);
void preOrden(Nodo *);
void inOrden(Nodo *);
void postOrden(Nodo *);
void nivelOrden(Nodo *);

Nodo *arbol = NULL;

int main(){

menu();

return 0;
}

void menu(){
	
	int dato, opcion, contador = 0;
	do{
	
		cout<<"\t\t MENU..."<<endl;
		cout<<" 1. Insertar un nuevo nodo"<<endl;
		cout<<" 2. Mostar Arbol"<<endl;
		cout<<" 3. Recorrido Preorden"<<endl;
		cout<<" 4. Recorrido Inorden"<<endl;
		cout<<" 5. Recorrido Postorden"<<endl;
		cout<<" 6. Recorrido por Niveles"<<endl;
		cout<<" 7. Salir "<<endl;
		cout<<" Opcion: ";
		cin>>opcion;
	
		switch(opcion){
			case 1: 
				cout<<"Digite un numero ";
				cin>>dato;
				insertar(arbol , dato);
				cout<<"\n ";		
				break;
				
			case 2:
				cout<<"\nMostrando el Arbol: \n\n";
				mostrarArbol(arbol,contador);
				cout<<"\n";
				break;
				
			case 3:
				cout<<"\nRecorrido Preorden: \n\n";
				preOrden(arbol);
				cout<<"\n";
				break;
				
			case 4:
				cout<<"\nRecorrido Inorden: \n\n";
				inOrden(arbol);
				cout<<"\n";
				break;
				
			case 5:
				cout<<"\nRecorrido Postorden: \n\n";
				postOrden(arbol);
				cout<<"\n";
				break;
				
			case 6:
				cout<<"\nRecorrido por Niveles: \n\n";
				nivelOrden(arbol);
				cout<<"\n";
				break;
		}
	}while(opcion != 7);
}

Nodo *crearNodo(int n){
	Nodo *nuevo = new Nodo();
	nuevo->dato = n;
	nuevo->der = NULL;	
	nuevo->izq = NULL;	
	
	return nuevo;
}

void insertar(Nodo *&arbol, int n){
	if(arbol == NULL){
		Nodo *nuevo = crearNodo(n);
		arbol = nuevo;		
	}
	else{
		int Raiz = arbol->dato;
		if(n < Raiz){
			insertar(arbol->izq,n);
		}
		else{
			insertar(arbol->der, n);
		}
	}

}

void mostrarArbol(Nodo *arbol, int contador){
	if(arbol == NULL){
		return;
	}
	else{
		mostrarArbol(arbol->der, contador+1);
		for(int i=0; i<contador;i++){
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		mostrarArbol(arbol->izq, contador+1);
	}
}

void preOrden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		cout<<arbol->dato<<" ";
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}

void inOrden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		inOrden(arbol->izq);
		cout<<arbol->dato<<" ";
		inOrden(arbol->der);
	}
}

void postOrden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		postOrden(arbol->izq);
		postOrden(arbol->der);
		cout<<arbol->dato<<" ";
	}
}

void nivelOrden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		queue<Nodo *> q;
		q.push(arbol);
		
		while(!q.empty()){
			Nodo *current = q.front();
			cout<<current->dato<<" ";
			if(current->izq != NULL) q.push(current->izq);
			if(current->der != NULL) q.push(current->der);
			q.pop();
		}
	}
}
