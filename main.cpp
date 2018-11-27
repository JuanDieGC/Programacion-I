#include <iostream>
#include <fstream>
#include<windows.h>
#include <string.h>
#include <conio.h>
#define tam 100
#include <bits/stdc++.h>
using namespace std;
void gotoxy(short x, short y)
{
   COORD pos = { x, y };
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void color(WORD col)
{
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),col);
}

void aleatorio(int*num)
{
    *num=rand()%100;
}
void dibujar_sapito(int posrx,int posry)
{
    color(10);
    char a=187,b=153,f=240,c=201,d=188,e=200;
    gotoxy(posrx,posry);
    cout<<e<<b<<b<<d;
    gotoxy(posrx,posry+1);
    cout<<c<<f<<f<<a<<endl;
}
void borrar_sapito(int posrx,int posry)
{
    char a=' ';
    gotoxy(posrx,posry);
    cout<<a<<a<<a<<a;
    gotoxy(posrx,posry+1);
    cout<<a<<a<<a<<a<<endl;
}

void inicializar_autopista(int largo, int ancho)
{
    gotoxy(0,0);
    char a=174;
    int ancho1=largo*4;
    int altura1=ancho*4;
    color(3);
    for(int x=0;x<ancho1;x++)
        cout<<a;
    color(7);
    gotoxy(0,1);
    for(int x=0;x<ancho1;x++)
        cout<<a;
    gotoxy(0,2);
    color(2);
    for(int y=0;y<ancho1;y++)
        cout<<a;
    gotoxy(0,altura1+7);
    color(10);
    for(int x=0;x<altura1;x++)
        cout<<a;
    gotoxy(0,altura1+6);
    color(7);
    for(int x=0;x<ancho1;x++)
        cout<<a;
}
void dibujar_autitos(int posax,int posay)
{

    char a=219,b=220,c=226;

    color(4);
    gotoxy(posax,posay+1);
    cout<<b<<a<<a<<a<<a<<a<<a<<a<<a<<b;
    gotoxy(posax,posay+2);
    cout<<a;
    color(8);
    cout<<b<<b;
    color(4);
    cout<<a<<a<<a<<a;
    color(8);
    cout<<b<<b;
    color(4);
    cout<<a<<c;
    color(7);
    gotoxy(posax+2,posay+3);
    cout<<c<<c<<"   "<<c<<c;
}
void eliminar_auto(int posax,int posay)
{
    char a=' ';
    gotoxy(posax+2,posay);
    gotoxy(posax,posay+1);
    cout<<a<<a<<a<<a<<a<<a<<a<<a<<a<<a;
    gotoxy(posax,posay+2);
    cout<<a;
    color(8);
    cout<<a<<a;
    cout<<a<<a<<a<<a;
    color(8);
    cout<<a<<a;
    cout<<a<<a;
    color(7);
    gotoxy(posax+2,posay+3);
    cout<<a<<a<<"   "<<a<<a;
}

void Movimiento_Naranja(int *posrx,int *posry)
{
     if(_kbhit())
    {
        char tecla=getch();
        if(tecla=='w'){
                borrar_sapito(*posrx,*posry);
                *posry=*posry-1;

        }
        if(tecla=='s'){
                borrar_sapito(*posrx,*posry);
                *posry=*posry+1;

        }
        if(tecla=='d'){
                borrar_sapito(*posrx,*posry);
                *posrx=*posrx+1;

        }
        if(tecla=='a'){
                borrar_sapito(*posrx,*posry);
                *posrx=*posrx-1;

    }
    }
}
void choque(int posrx,int posry,int posax,int posay,int *muerte,int *vidas)
{
    int k=0,j=0,l=0,m=0;

        while(j<14&&k<13&&l<4&&m<3)
        {
            if(((posax+k)==posrx)&&((posay+l)==posry))
            {
                *muerte=1;
                *vidas=*vidas-1;
            }
            j++;
            k++;
            if(l!=3&&k==13){
                l++;
                k=0;
            }
            if(m!=2&&j==14){
                m++;
                j=0;
            }
        }
}

void avanzar_posiciones_auto(int *posx,int *posy)
{
    dibujar_autitos(*posx,*posy);
    Sleep(50);
    eliminar_auto(*posx,*posy);
    *posx+=1;
    dibujar_autitos(*posx,*posy);
    if(*posx>=90)
    {
        eliminar_auto(*posx,*posy);
        *posx=0;
        dibujar_autitos(*posx,*posy);
    }
}
int main()
{
    int ancho=25,largo=10;
    int posax=5,posay=3;
    int vidas=3,muerte,numAut=0,limite=ancho,reloj,nivel=1;
    int fin=0,aux=0;
    int posrx=(ancho*4)/2,posry=(largo*4)+4;
    inicializar_autopista(ancho,largo);
    while(fin!=1 && posry!=2)
    {
            muerte=0;
            reloj=1;
            dibujar_sapito(posrx,posry);
                avanzar_posiciones_auto(&posax,&posay);
            Movimiento_Naranja(&posrx,&posry);
            reloj++;
    }
    system("CLS");
    cout<<"GANASTE"<<endl;
}
