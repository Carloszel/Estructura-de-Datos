#include <iostream>
#include<cstdlib> //Usat getline
#include<iomanip>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define VOLVER_MENU cout<<"\n\nPRESIONE ENTER PARA VOLVER AL MENU"; setbuf(stdin, NULL); cin.get(); 


struct nodo
{
	string nombre;
	int id;
	int cuenta;
	string asignatura;
	string genero;
	int nota;
	nodo *siguiente;      
};

nodo *pIni = NULL; 
nodo *pFin;
nodo *p;

char op = 'n';
int cont = 0;
int i = 0;
int enc =0;
int mayor;


void cargar();
void mostrarlista();
void cargarnodo(nodo *x);
void consultar();
void eliminar();
void borrarNodo();
void modificarNodo(nodo *x);
void aprobados();
void reprobados();
void modif();  


int main()
{
	
	do{          
		system("cls");       
		cout<<"Registrar estudiante ------------(1)     (Personas ingresadas) "<<cont<<endl;        
		cout<<"Mostrar lista de estudiantes ----(2)\n";  
		cout<<"Buscar un estudiante ------------(3)\n";
		cout<<"Mostrar aprobados ---------------(4)\n";
		cout<<"Mostrar reprobados --------------(5)\n";
		cout<<"Eliminar Todos los estudiantes --(6)\n";
		cout<<"Eliminar estudiante por id ------(7)\n";
		cout<<"Modificar estudiante-------------(8)\n";  //juan carlos zelaya 
		cout<<"Salir ---------------------------(9)\n"; 
		cin.get(op);
		if(toupper(op) == '1')
		{ 
			cargar();
		}    
		else if(toupper(op) == '2')
		   mostrarlista();
		else if(toupper(op) == '3')
			consultar();
		else if(toupper(op) == '4')
			aprobados();
		else if(toupper(op) == '5')
			reprobados();
		else if(toupper(op) == '6')
			eliminar();
		else if(toupper(op) == '7')
			borrarNodo();  
		else if(toupper(op) == '8')
			modif();              
	}while(toupper(op) != '9');
	p = pIni;
	if(p != NULL)
	{
		nodo *aux;
		while(p!=NULL)
		{  
			aux = new nodo;
			aux = pIni;
			pIni = pIni->siguiente;
			free(aux);
			p = p->siguiente;                         
		}
	} 
	return 0;
	
}


void mostrarlista()
{
	
	system("cls");
	if(pIni != NULL)
	{ 
		p = pIni;
		i = 0;
		while (p->siguiente != NULL)
		{ 
			i++;
			cout<<i<<"Direccion : "<<int(p)<<endl;
			cout<<i<<".1) Numero de Cuenta: "<<p->cuenta<<endl;
			cout<<i<<".2) Id: "<<p->id<<endl;
			cout<<i<<".3) Nombre: "<<p->nombre<<endl;
			cout<<i<<".4) Genero: "<<p->genero<<endl;
			cout<<i<<".5) Asignatura: "<<p->asignatura<<endl;
		    cout<<i<<".6) Nota: "<<p->nota<<endl<<endl;
			p = p->siguiente;
		}     
	}else
	   cout<<"NO HAY ESTUDIANTES REGISTRADOS PARA MOSTAR";
	VOLVER_MENU
}


void cargar()
{
	if(pIni == NULL)  
	{       
		pIni = new nodo;
		pFin = new nodo;
		pIni->siguiente = pFin;           
		pFin->siguiente = NULL;           
		cargarnodo(pIni);                 
	}
	else                                
	{
		cargarnodo(pFin);                      
		pFin->siguiente = new nodo;         
		pFin = pFin->siguiente;           
		pFin->siguiente = NULL;              
	}
	cont++;
	p = pIni;
}
//  juan carlos zelaya
void modif()
{
	if(pIni == NULL)  
	{       
		pIni = new nodo;
		pFin = new nodo;
		pIni->siguiente = pFin;           
		pFin->siguiente = NULL;           
		modificarNodo(pIni);                 
	}
	else                                
	{
		modificarNodo(pFin);                      
		pFin->siguiente = new nodo;         
		pFin = pFin->siguiente;           
		pFin->siguiente = NULL;              
	}
	cont++;
	p = pIni;
}


void cargarnodo(nodo *x)
{
	system("cls");
	cout<<"introduzca el numero de cuenta: ";
	cin>>x->cuenta;  
	cout<<"introduzca el id: ";
	cin>>x->id;	
	cout<<"introduzca el nombre del estudiante: ";
	cin>>x->nombre;
	cout<<"introduzca el genero: ";
	cin>>x->genero;  
	cout<<"introduzca la Asignatura: ";
	cin>>x->asignatura;
	cout<<"introduzca la nota: ";
	cin>>x->nota;  
	 
}

void consultar()
{
	system("cls");
	p = pIni;          
	if(p != NULL)
	{
		nodo *c = NULL;
		c = new nodo;              
		cout<<"INGRESE ID DEL ESTUDIANTE QUE DESEA CONSULTAR\n";
		cin>>c->id;
		enc = 0;
		while(p != NULL)
		{    
			if(c->id == p->id)
			{  
				enc = 1;         
				cout<<i<<"Direccion : "<<int(p)<<endl;
				cout<<i<<".1) Numero de Cuenta: "<<p->cuenta<<endl;
				cout<<i<<".2) Id: "<<p->id<<endl;
				cout<<i<<".3) Nombre: "<<p->nombre<<endl;
				cout<<i<<".4) Genero: "<<p->genero<<endl;
				cout<<i<<".5) Asignatura: "<<p->asignatura<<endl;
				cout<<i<<".6) Nota: "<<p->nota<<endl<<endl;
				
			}
			p = p->siguiente;
		}     
		if(enc == 0)
		{
			cout<<"\n\nESTUDIANTE NO ENCONTRADO";
		}  
		free(c);
	}else
	   cout<<"NO HAY ESTUDIANTES REGISTRADOS PARA CONSULTAR";
	VOLVER_MENU   
}  


void eliminar()
{
	system("cls");
	p = pIni;
	if(p!=NULL)
	{
		nodo *aux;
		aux = new nodo;
		while(p->siguiente != NULL)
		{       
			aux = pIni;
			pIni = pIni->siguiente;
			free(aux);
			p = p->siguiente;                         
		}
		cout<<"ESTUDIANTES ELIMINADOS";                
		cont = 0;     
		
	}else   
	   cout<<"NO HAY ESTUDIANTES REGISTRADOS PARA ELIMINAR";
	VOLVER_MENU       
}


void borrarNodo()
{
	system("cls");
	p = pIni; 
	if(p)
	{
		
		nodo *aux = NULL, *ant = NULL;
		ant = new nodo;  
		aux = new nodo;
		cout<<"INTRODUZCA EL ID DEL ESTUDIANTE QUE DESEA ELIMINAR\n";
		cin>>aux->id;
		while(aux->id != p->id)
		{
			ant = p;
			p = p->siguiente;
		}            
		if(aux->id == p->id)
		{                   
			ant = p;
			p = p->siguiente;                
			free(ant);
			free(aux);
			cout<<"ESTUDIANTE ELIMINADO";
			cont--;
		}                                 
	}else   
	   cout<<"ESTUDIANTE NO ENCONTRADO";
	VOLVER_MENU       
}



void reprobados()
{
	
	system("cls");
	if(pIni != NULL)
	{ 
	cout<<"***** Listado de Estudiantes que Reprobaron ***** "<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<setw(7)<<setw(20)<<"Nombre del Alumno"<<setw(15)<<"Nota"<<endl;	
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		
		p = pIni;
		i = 0;
		while (p->siguiente != NULL)
		{ 
			i++;
			
			if(p->nota<65)
			{  
				
				
				cout<<setw(7)<<setw(20)<<p->nombre<<setw(15)<<p->nota<<endl;
			}
			
			p = p->siguiente;
		}     
	}else
	   cout<<"NO HAY ESTUDIANTES REPROBADOS PARA MOSTAR";
	VOLVER_MENU
}


void aprobados()
{
	
	system("cls");
	if(pIni != NULL)
	{ 
		
	cout<<"***** Listado de Estudiantes que Aprobaron ***** "<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<setw(7)<<setw(20)<<"Nombre del Alumno"<<setw(15)<<"Nota"<<endl;	
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

		p = pIni;
		i = 0;
		while (p->siguiente != NULL)
		{ 
			i++;
			if(p->nota>65)
			{  
				cout<<setw(7)<<setw(20)<<p->nombre<<setw(15)<<p->nota<<endl;
			}
			
			p = p->siguiente;
		}     
	}else
	   cout<<"NO HAY ESTUDIANTES APROBADOS PARA MOSTAR";
	
	VOLVER_MENU
}
// juan carlos zelaya 
 void modificarNodo(nodo *x)
{
		system("cls");
		
	p = pIni;          
	if(p != NULL)
	{
		nodo *c = NULL;
		c = new nodo;              
		cout<<"INGRESE ID DEL ESTUDIANTE QUE DESEA MODIFICAR\n";
		cin>>c->id;
		enc = 0;
		while(p != NULL)
		{    
			if(c->id == p->id)
			{  
				enc = 1;         
				cout<<i<<"Direccion : "<<int(p)<<endl;
				cout<<i<<".1) Numero de Cuenta: "<<p->cuenta<<endl;
				cout<<i<<".2) Id: "<<p->id<<endl;
				cout<<i<<".3) Nombre: "<<p->nombre<<endl;
				cout<<i<<".4) Genero: "<<p->genero<<endl;
				cout<<i<<".5) Asignatura: "<<p->asignatura<<endl;
				cout<<i<<".6) Nota: "<<p->nota<<endl<<endl;
					cout<<"INGRESE NUEVOS DATOS DEL ESTUDIANTE";
					
					cout<<"introduzca el numero de cuenta: ";
			cin>>x->cuenta;  
			cout<<"introduzca el id: ";
			cin>>x->id;	
			cout<<"introduzca el nombre del estudiante: ";
			cin>>x->nombre;
			cout<<"introduzca el genero: ";
			cin>>x->genero;  
			cout<<"introduzca la Asignatura: ";
			cin>>x->asignatura;
			cout<<"introduzca la nota: ";
			cin>>x->nota;  
			
			}
		
			
			
			
			p = p->siguiente;
		}     
		if(enc == 0)
		{
			cout<<"\n\nESTUDIANTE NO ENCONTRADO";
		}  
		free(c);
	}else
	   cout<<"NO HAY ESTUDIANTES REGISTRADOS PARA MODIFICAR";
	
	VOLVER_MENU
}
