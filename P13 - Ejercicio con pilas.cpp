//Fernando Martinez Macias
#include <iostream>
#include<string>

using namespace std;

struct persona{//persona
    string name;//nombre
    string app;//apellido
    float salario;//salario
    char genero;//genero

    persona *next;//persona apuntando a siguiente
};

persona *person = NULL;//persona apuntando a person es igual a vacio.

void push(string n, string a, float s, char g);//funcion pila
void pop();//funcion eliminar
void prt();//funcion imprimir


int main(){//aqui inicia el programa.
    int op;//opcion a elegir del usuario
    float s;//para ingresar salario
    string n;//para ingresar nombre
    string a;//para ingresar apellido
    char g;//para ingresar genero

    do{
        cout<<"\n(1) Push    (2) Pop    (3) Print   (4) Salir \n ";
        cout<<"\n Elija opcion  ?: ",cin>>op;

        switch (op){
            case 1:

                cout<<"Ingrese su nombre :  ";
                fflush(stdin);
                getline(cin, n);  //Esto es para que si mete dos palabras distitas no entre en un bucle infinito.

                cout<<"Ingresa su Apellido:  ";
                fflush(stdin);
                getline(cin, a);

                cout<<"Ingrese su Salario neto :  ",cin>>s;

                cout<<"Ingrese su Genero (m=masculino / f=femenino) :  ",cin>>g;

                push(n,a,s,g);//funcion push para variables temporales

                break;
            case 2:
                cout<<"Eliminando ..... : ";
                cout<<endl;
                pop();
                break;
            case 3:
                cout<<"Imprimiendo..... : ";
                cout<<endl;
                prt();
                break;
            case 4:
                cout<<endl;
                cout<<"------Bye--------";
        }
    }while(op!=4);
}

void push(string n, string a, float s, char g){
    persona *npersona =  new persona;
    // n="luis fernando";
    // a="martinez macias";
    // s= "$ 4,958.00";
    // g= "M";
    npersona->name=n;
    npersona->app=a;
    npersona->salario=s;
    npersona->genero=g;
    npersona->next=person;
    person=npersona;//aqui se asignan los valores temporales a la funcion push
}

void pop(){
    if(person==NULL)
        cout<<"Nada que imprimir, Stack vacia \n";
    else
        person=person->next;
}

void prt(){
    persona *aux = person;
    if(aux==NULL)
        cout<<"Nada que imprimir, Stack vacia\n";
    else
        while(aux!=NULL){
            cout<<endl;
            cout<<"-> Nombre :"<<aux->name<<endl;
            cout<<"-> Apellido: "<<aux->app<<endl;
            cout<<"-> Salario : "<<aux->salario<<endl;
            cout<<"-> Genero (m=masculino / f=femenino) : "<<aux->genero<<endl;
            cout<<endl;
            cout<<"============================"<<endl;
            cout<<endl;

            aux=aux->next;

        }
}
