#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <conio.h>
#include<windows.h>
using namespace std;
typedef struct{
    int posx;
    int posy;
}tiposapito;
typedef struct{
    int ncarriles;
    int ancho;
    tiposapito sapito;
}tipoautopista;
typedef struct{
    int listadecoches;
    int velocidad;
    int espacio;
}tipocarril;
typedef struct{
    char tipomovil;
    int posx;
    int posy;
}tipocoche;
typedef struct{
    int posx;
    int posy;
    int tiempo;
    int tipcomida;
}tipocomida;
void gotoxy(int x,int y)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X=x;
    dwPos.Y=y;
    SetConsoleCursorPosition(hcon, dwPos);
}
void color(int x)
{
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
}
void inicializar_autopista(tipoautopista autopista)
{
    gotoxy(0,0);
    char a=219;
    color(8);
    for(int x=0;x<autopista.ancho;x++)
        cout<<a;
    color(7);
    gotoxy(0,1);
    for(int x=0;x<autopista.ancho;x++)
        cout<<a;
    gotoxy(0,2);
    color(2);
    for(int y=0;y<autopista.ncarriles;y++)
        cout<<a;
    gotoxy(0,autopista.ncarriles);
    color(10);
    for(int x=0;x<autopista.ncarriles;x++)
        cout<<a;
    gotoxy(0,autopista.ncarriles);
    color(7);
    for(int x=0;x<autopista.ancho;x++)
        cout<<a;
}
void borrar_sapito(tiposapito sapito)
{
    char a=' ';
    gotoxy(sapito.posx,sapito.posy);
    cout<<a<<a<<a<<a;
    gotoxy(sapito.posx,sapito.posy+1);
    cout<<a<<a<<a<<a<<endl;
}
void inicializar_sapito(tiposapito sapito)
{
    color(10);
    char a=187,b=220,f=223,c=201,d=188,e=200;
    gotoxy(sapito.posx,sapito.posy);
    cout<<e<<b<<b<<d;
    gotoxy(sapito.posx,sapito.posy+1);
    cout<<c<<f<<f<<a<<endl;
}
void actualizar_sapito(tiposapito sapito)
{
    color(10);
    char a=187,b=220,f=223,c=201,d=188,e=200;
    gotoxy(sapito.posx,sapito.posy);
    cout<<e<<b<<b<<d;
    gotoxy(sapito.posx,sapito.posy+1);
    cout<<c<<f<<f<<a<<endl;
}
void inicializar_comida(tipocomida comida)
{

}
int main()
{
    tipoautopista autopista;
    tiposapito sapito;
    sapito.posx=12,sapito.posy=24;
    autopista.ancho=24,autopista.ncarriles=28;
    inicializar_autopista(autopista);
    inicializar_sapito(sapito);
    while(sapito.posy!=2)
    {
        if(_kbhit())
    {
        char tecla=getch();
        if(tecla=='w'){
                borrar_sapito(sapito);
                sapito.posy=sapito.posy-4;
                actualizar_sapito(sapito);
        }
        if(tecla=='s'){
                borrar_sapito(sapito);
                sapito.posy=sapito.posy+4;
                actualizar_sapito(sapito);
        }
        if(tecla=='d'){
                borrar_sapito(sapito);
                sapito.posx=sapito.posx+4;
                actualizar_sapito(sapito);
        }
        if(tecla=='a'){
                borrar_sapito(sapito);
                sapito.posx=sapito.posx-4;
                actualizar_sapito(sapito);
    }
    }
    }
    system("CLS");
    gotoxy(25,35);
    cout<<"llego a la meta"<<endl;
    return 0;
}
