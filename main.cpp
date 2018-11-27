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

void movimiento_sapito(int *posrx,int *posry)
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
                borrar_sapito(posrx,posry);
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
void avanzar_posiciones_auto(int *posax,int *posay,int posrx,int posry,int *muerte,int *vidas)
{
    dibujar_autitos(*posax,*posay);
    Sleep(80);
    eliminar_auto(*posax,*posay);
    *posax+=1;
    dibujar_autitos(*posax,*posay);
    choque(posrx,posry,*posax,*posay,muerte,vidas);
    if(*posax>=90)
    {
        eliminar_auto(*posax,*posay);
        *posax=0;
        dibujar_autitos(*posax,*posay);
    }
}
int main()
{
    int ancho=25,largo=10;
    int posax=0,posay=4,posax1=20,posay1=posay+4,posax2=(rand()&8),posay2=posay1+4,posax3=(rand()&5),posay3=posay2+4;
    int vidas=3,muerte,numAut=0,limite=ancho,reloj,nivel=1;
    int fin=0,aux=0;
    int posrx=(ancho*4)/2,posry=(largo*4)+4;
    inicializar_autopista(ancho,largo);
    while(fin!=1 && posry!=2)
    {
        muerte=0;
        reloj=1;
        while(muerte!=1)
        {
            muerte=0;
            reloj=1;
            dibujar_sapito(posrx,posry);
            avanzar_posiciones_auto(&posax,&posay,posrx,posry,&muerte,&vidas);
            avanzar_posiciones_auto(&posax1,&posay1,posrx,posry,&muerte,&vidas);
            avanzar_posiciones_auto(&posax2,&posay2,posrx,posry,&muerte,&vidas);
            avanzar_posiciones_auto(&posax3,&posay3,posrx,posry,&muerte,&vidas);
            movimiento_sapito(&posrx,&posry);
            reloj++;
        }
        if(vidas==0){
            fin=1;
        }
        else
        {
            posrx=(ancho*4)/2,posry=(largo*4)+4;
        }
    }
    system("CLS");
    cout<<"GANASTE"<<endl;
}
