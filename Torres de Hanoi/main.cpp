/* Torres de Hanoi By Ramses Martinez Ortiz ~ Paradise1296
v 0.0.3

-Despliega interfaz de winbgim con torres en modo consola
-Falta rellenar bases
-Sólo imprime el procedimiento de 3 discos
-UNICAMENTE 3 DISCOS
-Falta adaptarlo a cualquier cantidad de discos
-Máximo a 10 discos
*/
//#include <stdio.h>
//#include <stdlib.h>   
#include <iostream>
#include <conio.h>
#include <windows.h>//Solo usamos Sleep
#include <winbgim.h>

#define TORRE_INICIAL 1
#define TORRE_AUXILIAR 2
#define TORRE_FINAL 3

using namespace std;
int hanoi(int numDiscos, int torreInicial, int torreAuxiliar, int torreFinal);//Logica
void mostrarEnConsola();
void dibujarBaseHanoi();
bool moverDiscos(int paso);

//Modo grafico consola

int t1=0,t2=0,t3=0,i,maxdiscos;
char disko = '*';
int cantDiscos, movimientos;
//Modo grafico (Winbgim)
int width; 
int height;

int main(){
	cout << "Cantidad de discos a mover ";
	cin >> cantDiscos;
	cout << "\n_________________________________________ \n" << endl;
	t1=cantDiscos;
	maxdiscos = cantDiscos;
	cout << "La torre: " << endl;
	mostrarEnConsola();
	Sleep(500);
	cout << "\n_________________________________________\nLa serie de movimientos a realizar es:\n" << endl;
	//Inicia winbgim
	width = 790;
	height = 300 +(25*cantDiscos);
	initwindow(width,height);
	movimientos = hanoi(cantDiscos, TORRE_INICIAL, TORRE_AUXILIAR, TORRE_FINAL);
	cout << "\n\nSe realizaron en total " << movimientos << " movimientos" << endl;
	getch();
	closegraph();
	return 0;
}
 
int hanoi(int numDiscos, int torreInicial, int torreAuxiliar, int torreFinal){
	static int movimientos = 0;
	if(numDiscos == 1){ // solo hay un disco
		cout << "\n\n" << movimientos+1 << ".- Mover el disco superior de la torre " << torreInicial << " a la torre " << torreFinal << endl;
		movimientos++;
 
        if(torreInicial==1)
            t1--;
        if(torreInicial==2)
            t2--;
        if(torreInicial==3)
            t3--;
        if(torreFinal==1)
            t1++;
        if(torreFinal==2)
            t2++;
        if(torreFinal==3)
            t3++;
			
		mostrarEnConsola();
		if(moverDiscos(movimientos)){
			return movimientos;	
		}
	} else{ // mas de un disco
  		hanoi(numDiscos - 1, torreInicial, torreFinal, torreAuxiliar);
  		cout << "\n\n" << movimientos +1 << ".- Mover el disco superior de la torre " << torreInicial << " a la torre " << torreFinal << endl;
  		movimientos++;
 
        if(torreInicial==1)
            t1--;
        if(torreInicial==2)
            t2--;
        if(torreInicial==3)
            t3--;
        if(torreFinal==1)
            t1++;
        if(torreFinal==2)
            t2++;
        if(torreFinal==3)
            t3++;
 
  		mostrarEnConsola();
  		if(moverDiscos(movimientos)){
  			hanoi(numDiscos - 1, torreAuxiliar, torreInicial, torreFinal);
  			return movimientos;	
		}
  		
	}
}
 
void mostrarEnConsola(){
    cout << "\n\t Torre 1: ";
    for(i=1;i<=t1;i++)
       	cout << disko;
    cout << "\n\t Torre 2: ";
	for(i=1;i<=t2;i++)
		cout << disko;
    cout << "\n\t Torre 3: ";
 	for(i=1;i<=t3;i++)
        cout << disko;
}

void dibujarBaseHanoi(){
	setcolor(14);
	moveto(300,50);
	settextstyle(4,0,3);// settextstyle(int fuente, int orientacion, int tam_caracter);
	outtext("Hola Hanoi");
	setcolor(2);
	line(0,height-50,width+30,height-50);//Piso
	rectangle(140,height-250,160,height-50);//Torre 1
	rectangle(390,height-250,410,height-50);//Torre 1
	rectangle(640,height-250,660,height-50);//Torre 1
	setcolor(3);
}

bool moverDiscos(int paso){
	switch(paso){
		case 1:		
			for(int i = 0; i<= (25*6); i++){
				cleardevice();
				dibujarBaseHanoi();
				rectangle(40,height-75,260,height-50);//Disco 1
				rectangle(50,height-100,250,height-75);//Disco 2
				rectangle(60,height-125-i,240,height-100-i);//Disco 3
				Sleep(5);
			}
			for(int i = 0; i<=500; i++){
				cleardevice();
				dibujarBaseHanoi();
				rectangle(40,height-75,260,height-50);//Disco 1
				rectangle(50,height-100,250,height-75);//Disco 2
				rectangle(60+i,height-125-(25*6),240+i,height-100-(25*6));//Disco 3
				Sleep(5);
			}
			for(int i = 0; i<=(25*8); i++){
				cleardevice();
				dibujarBaseHanoi();
				rectangle(40,height-75,260,height-50);//Disco 1
				rectangle(50,height-100,250,height-75);//Disco 2
				rectangle(60+500,height-125-(25*6)+i,240+500,height-100-(25*6)+i);//Disco 3
				Sleep(5);
			}
		break;
		case 2:
			for(int i = 0; i<= (25*7); i++){
				cleardevice();
				dibujarBaseHanoi();
				rectangle(40,height-75,260,height-50);//Disco 1
				rectangle(50,height-100-i,250,height-75-i);//Disco 2
				rectangle(60+500,height-75,240+500,height-50);//Disco 3
				Sleep(5);
			}
			for(int i = 0; i<=250; i++){
				cleardevice();
				dibujarBaseHanoi();
				rectangle(40,height-75,260,height-50);//Disco 1
				rectangle(50+i,height-100-(25*7),250+i,height-75-(25*7));//Disco 2
				rectangle(60+500,height-75,240+500,height-50);//Disco 3
				Sleep(5);
			}
			for(int i = 0; i<=(25*7); i++){
				cleardevice();
				dibujarBaseHanoi();
				rectangle(40,height-75,260,height-50);//Disco 1
				rectangle(50+250,height-100-(25*6)+i,250+250,height-75-(25*6)+i);//Disco 2
				rectangle(60+500,height-75,240+500,height-50);//Disco 3
				Sleep(5);
			}
		break;
		case 3:
		for(int i = 0; i<= (25*8); i++){
				cleardevice();
				dibujarBaseHanoi();
				rectangle(40,height-75,260,height-50);//Disco 1
				rectangle(50+250,height-100-(25*6)+(25*7),250+250,height-75-(25*6)+(25*7));//Disco 2
				rectangle(60+500,height-75-i,240+500,height-50-i);//Disco 3
				Sleep(5);
			}
			for(int i = 0; i<=250; i++){
				cleardevice();
				dibujarBaseHanoi();
				rectangle(40,height-75,260,height-50);//Disco 1
				rectangle(50+250,height-100-(25*6)+(25*7),250+250,height-75-(25*6)+(25*7));//Disco 2
				rectangle(60+500-i,height-75-(25*8),240+500-i,height-50-(25*8));//Disco 3
				Sleep(5);
			}
			for(int i = 0; i<=(25*7); i++){
				cleardevice();
				dibujarBaseHanoi();
				rectangle(40,height-75,260,height-50);//Disco 1
				rectangle(50+250,height-100-(25*6)+(25*7),250+250,height-75-(25*6)+(25*7));//Disco 2
				rectangle(60+500-250,height-75-(25*8)+i,240+500-250,height-50-(25*8)+i);//Disco 3
				Sleep(5);
			}
		break;
		case 4:
			for(int i = 0; i<= (25*8); i++){
				cleardevice();
				dibujarBaseHanoi();
				rectangle(40,height-75-i,260,height-50-i);//Disco 1
				rectangle(300,height-100-(25*6)+(25*7),500,height-75-(25*6)+(25*7));//Disco 2
				rectangle(560-250,height-75-(25*8)+(25*7),740-250,height-50-(25*8)+(25*7));//Disco 3
				Sleep(5);
			}
			for(int i = 0; i<=500; i++){
				cleardevice();
				dibujarBaseHanoi();
				rectangle(40+i,height-75-(25*8),260+i,height-50-(25*8));//Disco 1
				rectangle(300,height-100-(25*6)+(25*7),500,height-75-(25*6)+(25*7));//Disco 2
				rectangle(60+500-250,height-75-(25*8)+(25*7),240+500-250,height-50-(25*8)+(25*7));//Disco 3
				Sleep(5);
			}
			for(int i = 0; i<=(25*8); i++){
				cleardevice();
				dibujarBaseHanoi();
				rectangle(540,height-75-(25*8)+i,760,height-50-(25*8)+i);//Disco 1
				rectangle(300,height-100-(25*6)+(25*7),500,height-75-(25*6)+(25*7));//Disco 2
				rectangle(60+500-250,height-75-(25*8)+(25*7),240+500-250,height-50-(25*8)+(25*7));//Disco 3
				Sleep(5);
			}
		break;
		case 5:
			for(int i = 0; i<= (25*7); i++){
				cleardevice();
				dibujarBaseHanoi();
				rectangle(540,height-75,760,height-50);//Disco 1
				rectangle(300,height-100-(25*6)+(25*7),500,height-75-(25*6)+(25*7));//Disco 2
				rectangle(560-250,height-100-i,740-250,height-75-i);//Disco 3
				Sleep(5);
			}
			for(int i = 0; i<=250; i++){
				cleardevice();
				dibujarBaseHanoi();
				rectangle(540,height-75,760,height-50);//Disco 1
				rectangle(300,height-100-(25*6)+(25*7),500,height-75-(25*6)+(25*7));//Disco 2
				rectangle(560-250-i,height-100-(25*7),740-250-i,height-75-(25*7));//Disco 3
				Sleep(5);
			}
			for(int i = 0; i<=(25*8); i++){
				cleardevice();
				dibujarBaseHanoi();
				rectangle(540,height-75,760,height-50);//Disco 1
				rectangle(300,height-100-(25*6)+(25*7),500,height-75-(25*6)+(25*7));//Disco 2
				rectangle(60,height-100-(25*7)+i,240,height-75-(25*7)+i);//Disco 3
				Sleep(5);
			}
		break;
		case 6:
			for(int i = 0; i<= (25*8); i++){
				cleardevice();
				dibujarBaseHanoi();
				rectangle(540,height-75,760,height-50);//Disco 1
				rectangle(300,height-75-i,500,height-50-i);//Disco 2
				rectangle(60,height-100-(25*7)+(25*8),740-500,height-75-(25*7)+(25*8));//Disco 3
				Sleep(5);
			}
			for(int i = 0; i<=250; i++){
				cleardevice();
				dibujarBaseHanoi();
				rectangle(540,height-75,760,height-50);//Disco 1
				rectangle(300+i,height-75-(25*8),500+i,height-50-(25*8));//Disco 2
				rectangle(60,height-100-(25*7)+(25*8),740-500,height-75-(25*7)+(25*8));//Disco 3
				Sleep(5);
			}
			for(int i = 0; i<=(25*7); i++){
				cleardevice();
				dibujarBaseHanoi();
				rectangle(540,height-75,760,height-50);//Disco 1
				rectangle(300+250,height-75-(25*8)+i,500+250,height-50-(25*8)+i);//Disco 2
				rectangle(60,height-100-(25*7)+(25*8),740-500,height-75-(25*7)+(25*8));//Disco 3
				Sleep(5);
			}
		break;
		case 7:
			for(int i = 0; i<= (25*8); i++){
				cleardevice();
				dibujarBaseHanoi();
				rectangle(540,height-75,760,height-50);//Disco 1
				rectangle(300+250,height-75-(25*8)+(25*7),500+250,height-50-(25*8)+(25*7));//Disco 2
				rectangle(60,height-100-(25*7)+(25*8)-i,740-500,height-75-(25*7)+(25*8)-i);//Disco 3
				Sleep(5);
			}
			for(int i = 0; i<=500; i++){
				cleardevice();
				dibujarBaseHanoi();
				rectangle(540,height-75,760,height-50);//Disco 1
				rectangle(300+250,height-75-(25*8)+(25*7),500+250,height-50-(25*8)+(25*7));//Disco 2
				rectangle(60+i,height-100-(25*7),740-500+i,height-75-(25*7));//Disco 3
				Sleep(5);
			}
			for(int i = 0; i<=(25*6); i++){
				cleardevice();
				dibujarBaseHanoi();
				rectangle(540,height-75,760,height-50);//Disco 1
				rectangle(300+250,height-75-(25*8)+(25*7),500+250,height-50-(25*8)+(25*7));//Disco 2
				rectangle(60+500,height-100-(25*7)+i,740,height-75-(25*7)+i);//Disco 3
				Sleep(5);
			}
		break;
	}
	return true;
}
