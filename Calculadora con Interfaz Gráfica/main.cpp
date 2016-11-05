/*Calculadora grafica v 1.1 
Calculadora que utiliza la interfaz grafica con la libreria winbgim
la impresion de pantalla la realiza en la consola y pantalla
Solo realiza operacion con dos variables... ._.
Aun no se separan las operaciones en metodos diferentes 
...No tenía internet para hacerla chida :(
.
.
.
Mejoras para la v 2.0
--> realizar mas de dos operaciones
--> agregar potenciacion y radicacion
*/
#include <winbgim.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
       //Declara los metodos
        void DibujarBotones();
        void DibujarNumeros();
        void waitForLeftMouseClick(); //Metodo para capturar los clics del mouse
        //Metodos para las operaciones
        int sumar(int num1,int num2);
        int restar(int num1,int num2);
        int multiplicar(int num1,int num2);
        int dividir(int num1,int num2);
        int convertir(char cadena[]);
        void imprimir(int num);
            //Declaracion de constantes
        const int DELAY = 50; //Tiempo de espera para obtener otro clic
        const int MaxTam = 3; //Cantidad de caracteres que permiten almacenar los arrays
        const int ArrayTam = 16; //DEBE SER MAYOR que MaxTam!!!
main()
{
    //Crea la ventana
    initwindow(430,440); 
    setbkcolor(COLOR(40,40,40)); //Fondo color gris obscuro
    cleardevice();
    
    DibujarBotones(); //Dibuja el contorno de los botones
    DibujarNumeros(); //Dibuja los numeros de los botones
    waitForLeftMouseClick();
}


void DibujarBotones(){
    /*Lista de colores en Wibgim:
    0  BLACK
    1  BLUE
    2  GREEN
    3  CYAN
    4  RED
    5  MAGENTA
    6  BROWN
    7  LIGHTGRAY
    8  DARKGRAY
    9  LIGHTBLUE
    10 LIGHTGREEN
    11 LIGHTCYAN
    12 LIGHTRED
    13 LIGHTMAGENTA
    14 YELLOW
    15 WHITE
    */
    
    setcolor(2);                    //Lineas de color rojo
    rectangle(20,20,400,80);        //Pantalla
    
    setcolor(7);                    //Lineas de color rojo
    rectangle(20,100,100,140);      //Boton CE (Borrar Pantalla)
    rectangle(120,100,200,140);     //Boton C (Borrar memoria)
    rectangle(220,100,300,140);     //Boton Del (Borra solo un numero)
    
    setcolor(9);                    //Lineas de color azul
    rectangle(20,160,100,200);      //Boton 7
    rectangle(120,160,200,200);     //Boton 8
    rectangle(220,160,300,200);     //Boton 9
    
    rectangle(20,220,100,260);      //Boton 4
    rectangle(120,220,200,260);     //Boton 5
    rectangle(220,220,300,256);     //Boton 6

    rectangle(20,280,100,320);      //Boton 1
    rectangle(120,280,200,320);     //Boton 2
    rectangle(220,280,300,320);     //Boton 3
    
    rectangle(20,340,200,380);      //Boton 0
    rectangle(220,340,300,380);     //Boton Punto
    
    setcolor(12);                   //Lineas de color verde claro
    rectangle(320,100,400,140);     //Boton Division
    rectangle(320,160,400,200);     //Boton Multiplicacion
    rectangle(320,220,400,260);     //Boton Resta
    rectangle(320,280,400,320);     //Boton Suma
    
    setcolor(10);                   //Linea color verde claro
    rectangle(320,340,400,380);     //Boton IGUAL
} 

void DibujarNumeros(){
    setcolor(COLOR(230,230,230));
    settextstyle(4,0,2);
    
    outtextxy(37,110,"CE");     //Boton CE (Borrar Pantalla o la variable actual)
    outtextxy(150,110,"C");     //Boton C (Borrar memoria)
    outtextxy(230,110,"DEL");   //Boton Del (Borra solo un numero)
    outtextxy(352,110,"÷");     //Boton Division
    
    outtextxy(50,170,"7");      //Boton 7
    outtextxy(150,170,"8");     //Boton 8
    outtextxy(250,170,"9");     //Boton 9
    outtextxy(352,170,"×");     //Boton Multiplicacion

    outtextxy(50,230,"4");      //Boton 4
    outtextxy(150,230,"5");     //Boton 5
    outtextxy(250,230,"6");     //Boton 6
    outtextxy(352,230,"-");     //Boton Resta
    
    outtextxy(50,290,"1");      //Boton 1
    outtextxy(150,290,"2");     //Boton 2
    outtextxy(250,290,"3");     //Boton 3
    outtextxy(352,290,"+");     //Boton Suma
    
    outtextxy(100,350,"0");     //Boton 0
    outtextxy(255,350,".");     //Boton Punto
    outtextxy(352,350,"=");     //Boton IGUAL

}

void waitForLeftMouseClick(){
    //Declara variables
    clearmouseclick(WM_LBUTTONDOWN);  
    char var1[ArrayTam] = {'\0'};
    char var2[ArrayTam] = {'\0'};
    char resultado[ArrayTam] = {'\0'};
    bool ocupado1[ArrayTam] = {false};
    bool ocupado2[ArrayTam] = {false};
    char impresion[ArrayTam];
    char operacion = '0'; //Captura el tipo de operacion
    int x, y;  //Coordenadas elementos
    int intVar1, intVar2, intResultado;
    char cont;//Variable para continuar con la ejecucion de la calculadora

    //Inicio del metodo para capturar click
    while (!ismouseclick(WM_LBUTTONDOWN)) {
        delay(DELAY);  
        getmouseclick(WM_LBUTTONDOWN,x,y);  
        
        //Boton 1
        if (x>=20 && x<=100 && y>=280 && y<=320){
            setcolor(3); //Texto de color cyan
            outtextxy(40,36,"1");       //Pantalla
            if(operacion == '0'){//Verifica que no haya operacion establecida
                if(!ocupado1[0]){//Comprueba Si var1[] esta vacio --> se comprueba con ocupado1
                    var1[0] = '1';
                    ocupado1[0] = true;
                    printf("%c\n",var1[0]);
                }else{//Si el array en la posicion 1 esta ocupado
                    for(int i = 1; i <= MaxTam; i++){
                        if(!ocupado1[i]){//Verifica cada caracter del arreglo
                            var1[i] = '1';
                            ocupado1[i] = true;
                            printf("%i.-",i);
                            printf("%c\n",var1[i]);
                            break;
                        }
                        if(ocupado1[MaxTam]){
                            printf("Arreglo lleno\n");
                            break;
                        }
                    }
                }
            }else{ //Cuando haya una operacion seleccionada
                if(!ocupado2[0]){//Comprueba Si var2[] esta vacio --> se comprueba con ocupado2[]
                    var2[0] = '1';
                    ocupado2[0] = true;
                    printf("%c\n",var2[0]);
                }else{//Si el array en la posicion 1 esta ocupado
                    for(int i = 1; i <= MaxTam; i++){
                        if(!ocupado2[i]){//Verifica cada caracter del arreglo
                            var2[i] = '1';
                            ocupado2[i] = true;
                            printf("%i.-",i);
                            printf("%c\n",var2[i]);
                            break;
                        }
                        if(ocupado2[MaxTam]){
                            printf("2Arreglo lleno\n");
                            break;
                        }
                    }
                }
            }
        }
        //Boton 2
        else if (x>=120 && x<=200 && y>=280 && y<=320){ 
            setcolor(3); 
            outtextxy(40,36,"2");
            if(operacion == '0'){//Verifica que no haya operacion establecida
                if(!ocupado1[0]){//Comprueba Si var1[] esta vacio --> se comprueba con ocupado1
                    var1[0] = '2';
                    ocupado1[0] = true;
                    printf("%c\n",var1[0]);
                }else{//Si el array en la posicion 1 esta ocupado
                    for(int i = 1; i <= MaxTam; i++){
                        if(!ocupado1[i]){//Verifica cada caracter del arreglo
                            var1[i] = '2';
                            ocupado1[i] = true;
                            printf("%i.-",i);
                            printf("%c\n",var1[i]);
                            break;
                        }
                        if(ocupado1[MaxTam]){
                            printf("Arreglo lleno\n");
                            break;
                        }
                    }
                }
            }else{ //Cuando haya una operacion seleccionada
                if(!ocupado2[0]){//Comprueba Si var2[] esta vacio --> se comprueba con ocupado2[]
                    var2[0] = '2';
                    ocupado2[0] = true;
                    printf("%c\n",var2[0]);
                }else{//Si el array en la posicion 1 esta ocupado
                    for(int i = 1; i <= MaxTam; i++){
                        if(!ocupado2[i]){//Verifica cada caracter del arreglo
                            var2[i] = '2';
                            ocupado2[i] = true;
                            printf("%i.-",i);
                            printf("%c\n",var2[i]);
                            break;
                        }
                        if(ocupado2[MaxTam]){
                            printf("2Arreglo lleno\n");
                            break;
                        }
                    }
                }
            }
        }
        //Boton 3
        else if (x>=220 && x<=300 && y>280 && y<=320){ 
            setcolor(3); 
            outtextxy(40,36,"3");   
            if(operacion == '0'){//Verifica que no haya operacion establecida
                if(!ocupado1[0]){//Comprueba Si var1[] esta vacio --> se comprueba con ocupado1
                    var1[0] = '3';
                    ocupado1[0] = true;
                    printf("%c\n",var1[0]);
                }else{//Si el array en la posicion 1 esta ocupado
                    for(int i = 1; i <= MaxTam; i++){
                        if(!ocupado1[i]){//Verifica cada caracter del arreglo
                            var1[i] = '3';
                            ocupado1[i] = true;
                            printf("%i.-",i);
                            printf("%c\n",var1[i]);
                            break;
                        }
                        if(ocupado1[MaxTam]){
                            printf("Arreglo lleno\n");
                            break;
                        }
                    }
                }
            }else{ //Cuando haya una operacion seleccionada
                if(!ocupado2[0]){//Comprueba Si var2[] esta vacio --> se comprueba con ocupado2[]
                    var2[0] = '3';
                    ocupado2[0] = true;
                    printf("%c\n",var2[0]);
                }else{//Si el array en la posicion 1 esta ocupado
                    for(int i = 1; i <= MaxTam; i++){
                        if(!ocupado2[i]){//Verifica cada caracter del arreglo
                            var2[i] = '3';
                            ocupado2[i] = true;
                            printf("%i.-",i);
                            printf("%c\n",var2[i]);
                            break;
                        }
                        if(ocupado2[MaxTam]){
                            printf("2Arreglo lleno\n");
                            break;
                        }
                    }
                }
            }
        }
        //Boton 4
        else if (x>=20 && x<=100 && y>=220 && y<=260){ 
            setcolor(3); 
            outtextxy(40,36,"4"); 
            if(operacion == '0'){//Verifica que no haya operacion establecida
                if(!ocupado1[0]){//Comprueba Si var1[] esta vacio --> se comprueba con ocupado1
                    var1[0] = '4';
                    ocupado1[0] = true;
                    printf("%c\n",var1[0]);
                }else{//Si el array en la posicion 1 esta ocupado
                    for(int i = 1; i <= MaxTam; i++){
                        if(!ocupado1[i]){//Verifica cada caracter del arreglo
                            var1[i] = '4';
                            ocupado1[i] = true;
                            printf("%i.-",i);
                            printf("%c\n",var1[i]);
                            break;
                        }
                        if(ocupado1[MaxTam]){
                            printf("Arreglo lleno\n");
                            break;
                        }
                    }
                }
            }else{ //Cuando haya una operacion seleccionada
                if(!ocupado2[0]){//Comprueba Si var2[] esta vacio --> se comprueba con ocupado2[]
                    var2[0] = '4';
                    ocupado2[0] = true;
                    printf("%c\n",var2[0]);
                }else{//Si el array en la posicion 1 esta ocupado
                    for(int i = 1; i <= MaxTam; i++){
                        if(!ocupado2[i]){//Verifica cada caracter del arreglo
                            var2[i] = '4';
                            ocupado2[i] = true;
                            printf("%i.-",i);
                            printf("%c\n",var2[i]);
                            break;
                        }
                        if(ocupado2[MaxTam]){
                            printf("2Arreglo lleno\n");
                            break;
                        }
                    }
                }
            }
        }
        //Boton 5
        else if (x>=120 && x<=200 && y>=220 && y<=260){ 
            setcolor(3); 
            outtextxy(40,36,"5");
            if(operacion == '0'){//Verifica que no haya operacion establecida
                if(!ocupado1[0]){//Comprueba Si var1[] esta vacio --> se comprueba con ocupado1
                    var1[0] = '5';
                    ocupado1[0] = true;
                    printf("%c\n",var1[0]);
                }else{//Si el array en la posicion 1 esta ocupado
                    for(int i = 1; i <= MaxTam; i++){
                        if(!ocupado1[i]){//Verifica cada caracter del arreglo
                            var1[i] = '5';
                            ocupado1[i] = true;
                            printf("%i.-",i);
                            printf("%c\n",var1[i]);
                            break;
                        }
                        if(ocupado1[MaxTam]){
                            printf("Arreglo lleno\n");
                            break;
                        }
                    }
                }
            }else{ //Cuando haya una operacion seleccionada
                if(!ocupado2[0]){//Comprueba Si var2[] esta vacio --> se comprueba con ocupado2[]
                    var2[0] = '5';
                    ocupado2[0] = true;
                    printf("%c\n",var2[0]);
                }else{//Si el array en la posicion 1 esta ocupado
                    for(int i = 1; i <= MaxTam; i++){
                        if(!ocupado2[i]){//Verifica cada caracter del arreglo
                            var2[i] = '5';
                            ocupado2[i] = true;
                            printf("%i.-",i);
                            printf("%c\n",var2[i]);
                            break;
                        }
                        if(ocupado2[MaxTam]){
                            printf("2Arreglo lleno\n");
                            break;
                        }
                    }
                }
            }
        }
        //Boton 6
        else if (x>=220 && x<=300 && y>=220 && y<=260){ 
            setcolor(3); 
            outtextxy(40,36,"6");
            if(operacion == '0'){//Verifica que no haya operacion establecida
                if(!ocupado1[0]){//Comprueba Si var1[] esta vacio --> se comprueba con ocupado1
                    var1[0] = '6';
                    ocupado1[0] = true;
                    printf("%c\n",var1[0]);
                }else{//Si el array en la posicion 1 esta ocupado
                    for(int i = 1; i <= MaxTam; i++){
                        if(!ocupado1[i]){//Verifica cada caracter del arreglo
                            var1[i] = '6';
                            ocupado1[i] = true;
                            printf("%i.-",i);
                            printf("%c\n",var1[i]);
                            break;
                        }
                        if(ocupado1[MaxTam]){
                            printf("Arreglo lleno\n");
                            break;
                        }
                    }
                }
            }else{ //Cuando haya una operacion seleccionada
                if(!ocupado2[0]){//Comprueba Si var2[] esta vacio --> se comprueba con ocupado2[]
                    var2[0] = '6';
                    ocupado2[0] = true;
                    printf("%c\n",var2[0]);
                }else{//Si el array en la posicion 1 esta ocupado
                    for(int i = 1; i <= MaxTam; i++){
                        if(!ocupado2[i]){//Verifica cada caracter del arreglo
                            var2[i] = '6';
                            ocupado2[i] = true;
                            printf("%i.-",i);
                            printf("%c\n",var2[i]);
                            break;
                        }
                        if(ocupado2[MaxTam]){
                            printf("2Arreglo lleno\n");
                            break;
                        }
                    }
                }
            }
        }
        //Boton 7
        else if (x>=20 && x<=100 && y>=160 && y<=200){ 
            setcolor(3); 
            outtextxy(40,36,"7");
            if(operacion == '0'){//Verifica que no haya operacion establecida
                if(!ocupado1[0]){//Comprueba Si var1[] esta vacio --> se comprueba con ocupado1
                    var1[0] = '7';
                    ocupado1[0] = true;
                    printf("%c\n",var1[0]);
                }else{//Si el array en la posicion 1 esta ocupado
                    for(int i = 1; i <= MaxTam; i++){
                        if(!ocupado1[i]){//Verifica cada caracter del arreglo
                            var1[i] = '7';
                            ocupado1[i] = true;
                            printf("%i.-",i);
                            printf("%c\n",var1[i]);
                            break;
                        }
                        if(ocupado1[MaxTam]){
                            printf("Arreglo lleno\n");
                            break;
                        }
                    }
                }
            }else{ //Cuando haya una operacion seleccionada
                if(!ocupado2[0]){//Comprueba Si var2[] esta vacio --> se comprueba con ocupado2[]
                    var2[0] = '7';
                    ocupado2[0] = true;
                    printf("%c\n",var2[0]);
                }else{//Si el array en la posicion 1 esta ocupado
                    for(int i = 1; i <= MaxTam; i++){
                        if(!ocupado2[i]){//Verifica cada caracter del arreglo
                            var2[i] = '7';
                            ocupado2[i] = true;
                            printf("%i.-",i);
                            printf("%c\n",var2[i]);
                            break;
                        }
                        if(ocupado2[MaxTam]){
                            printf("2Arreglo lleno\n");
                            break;
                        }
                    }
                }
            }
        }
        //Boton 8
        else if (x>=120 && x<=200 && y>=160 && y<=200){ 
            setcolor(3); 
            outtextxy(40,36,"8");
            if(operacion == '0'){//Verifica que no haya operacion establecida
                if(!ocupado1[0]){//Comprueba Si var1[] esta vacio --> se comprueba con ocupado1
                    var1[0] = '8';
                    ocupado1[0] = true;
                    printf("%c\n",var1[0]);
                }else{//Si el array en la posicion 1 esta ocupado
                    for(int i = 1; i <= MaxTam; i++){
                        if(!ocupado1[i]){//Verifica cada caracter del arreglo
                            var1[i] = '8';
                            ocupado1[i] = true;
                            printf("%i.-",i);
                            printf("%c\n",var1[i]);
                            break;
                        }
                        if(ocupado1[MaxTam]){
                            printf("Arreglo lleno\n");
                            break;
                        }
                    }
                }
            }else{ //Cuando haya una operacion seleccionada
                if(!ocupado2[0]){//Comprueba Si var2[] esta vacio --> se comprueba con ocupado2[]
                    var2[0] = '8';
                    ocupado2[0] = true;
                    printf("%c\n",var2[0]);
                }else{//Si el array en la posicion 1 esta ocupado
                    for(int i = 1; i <= MaxTam; i++){
                        if(!ocupado2[i]){//Verifica cada caracter del arreglo
                            var2[i] = '8';
                            ocupado2[i] = true;
                            printf("%i.-",i);
                            printf("%c\n",var2[i]);
                            break;
                        }
                        if(ocupado2[MaxTam]){
                            printf("2Arreglo lleno\n");
                            break;
                        }
                    }
                }
            }
        }
        //Boton 9
        else if (x>=220 && x<=300 && y>=160 && y<=200){ 
            setcolor(3); 
            outtextxy(40,36,"9");
            if(operacion == '0'){//Verifica que no haya operacion establecida
                if(!ocupado1[0]){//Comprueba Si var1[] esta vacio --> se comprueba con ocupado1
                    var1[0] = '9';
                    ocupado1[0] = true;
                    printf("%c\n",var1[0]);
                }else{//Si el array en la posicion 1 esta ocupado
                    for(int i = 1; i <= MaxTam; i++){
                        if(!ocupado1[i]){//Verifica cada caracter del arreglo
                            var1[i] = '9';
                            ocupado1[i] = true;
                            printf("%i.-",i);
                            printf("%c\n",var1[i]);
                            break;
                        }
                        if(ocupado1[MaxTam]){
                            printf("Arreglo lleno\n");
                            break;
                        }
                    }
                }
            }else{ //Cuando haya una operacion seleccionada
                if(!ocupado2[0]){//Comprueba Si var2[] esta vacio --> se comprueba con ocupado2[]
                    var2[0] = '9';
                    ocupado2[0] = true;
                    printf("%c\n",var2[0]);
                }else{//Si el array en la posicion 1 esta ocupado
                    for(int i = 1; i <= MaxTam; i++){
                        if(!ocupado2[i]){//Verifica cada caracter del arreglo
                            var2[i] = '9';
                            ocupado2[i] = true;
                            printf("%i.-",i);
                            printf("%c\n",var2[i]);
                            break;
                        }
                        if(ocupado2[MaxTam]){
                            printf("2Arreglo lleno\n");
                            break;
                        }
                    }
                }
            }
        }
        //Boton 0
        else if (x>=20 && x<=200 && y>=340 && y<=380){ 
            setcolor(3); 
            outtextxy(40,36,"0");
            if(operacion == '0'){//Verifica que no haya operacion establecida
                if(!ocupado1[0]){//Comprueba Si var1[] esta vacio --> se comprueba con ocupado1
                    var1[0] = '0';
                    ocupado1[0] = true;
                    printf("%c\n",var1[0]);
                }else{//Si el array en la posicion 1 esta ocupado
                    for(int i = 1; i <= MaxTam; i++){
                        if(!ocupado1[i]){//Verifica cada caracter del arreglo
                            var1[i] = '0';
                            ocupado1[i] = true;
                            printf("%i.-",i);
                            printf("%c\n",var1[i]);
                            break;
                        }
                        if(ocupado1[MaxTam]){
                            printf("Arreglo lleno\n");
                            break;
                        }
                    }
                }
            }else{ //Cuando haya una operacion seleccionada
                if(!ocupado2[0]){//Comprueba Si var2[] esta vacio --> se comprueba con ocupado2[]
                    var2[0] = '0';
                    ocupado2[0] = true;
                    printf("%c\n",var2[0]);
                }else{//Si el array en la posicion 1 esta ocupado
                    for(int i = 1; i <= MaxTam; i++){
                        if(!ocupado2[i]){//Verifica cada caracter del arreglo
                            var2[i] = '0';
                            ocupado2[i] = true;
                            printf("%i.-",i);
                            printf("%c\n",var2[i]);
                            break;
                        }
                        if(ocupado2[MaxTam]){
                            printf("2Arreglo lleno\n");
                            break;
                        }
                    }
                }
            }
        }
        //Boton Punto
        else if (x>=220 && x<=300 && y>=340 && y<=380){ 
            setcolor(3); 
            outtextxy(40,36,".");
            if(operacion == '0'){//Verifica que no haya operacion establecida
                if(!ocupado1[0]){//Comprueba Si var1[] esta vacio --> se comprueba con ocupado1
                    var1[0] = '0';
                    ocupado1[0] = true;
                    //Como es un punto se asigna en la posicion 2 de var1[]
                    var1[1] = '.';
                    ocupado1[1] = true;
                    printf("%c\n",var1[0]);
                }else{//Si el array en la posicion 1 esta ocupado
                    for(int i = 1; i <= MaxTam; i++){
                        if(var1[i] == '.'){//Verifica que no haya un punto previamente escrito
                            printf("No se pueden poner mas de dos puntos");
                            break;
                        }else if (!ocupado1[i]){//Verifica cada caracter del arreglo
                            var1[i] = '.';
                            ocupado1[i] = true;
                            printf("%i.-",i);
                            printf("%c\n",var1[i]);
                            break;
                        }
                        if(ocupado1[MaxTam]){
                            printf("Arreglo lleno\n");
                            break;
                        }
                    }
                }
            }else{ //Cuando haya una operacion seleccionada
                if(!ocupado2[0]){//Comprueba Si var1[] esta vacio --> se comprueba con ocupado1
                    var2[0] = '0';
                    ocupado2[0] = true;
                    //Como es un punto se asigna en la posicion 2 de var1[]
                    var2[1] = '.';
                    ocupado2[1] = true;
                    printf("%c\n",var2[0]);
                }else{//Si el array en la posicion 1 esta ocupado
                    for(int i = 1; i <= MaxTam; i++){
                        if(var2[i] == '.'){//Verifica que no haya un punto previamente escrito
                            printf("No se pueden poner mas de dos puntos");
                            break;
                        }else if (!ocupado2[i]){//Verifica cada caracter del arreglo
                            var2[i] = '.';
                            ocupado2[i] = true;
                            printf("%i.-",i);
                            printf("%c\n",var2[i]);
                            break;
                        }
                        if(ocupado2[MaxTam]){
                            printf("Arreglo lleno\n");
                            break;
                        }
                    }
                }
            }
        }
        //Boton CE (Borrar Pantalla o la variable actual)
        else if (x>=20 && x<=100 && y>=100 && y<=140){ 
            setcolor(3); 
            outtextxy(40,36,"CE");
        }
        //Boton C (Borrar memoria)
        else if (x>=120 && x<=200 && y>=100 && y<=140){ 
            setcolor(3); 
            outtextxy(40,36,"C");
        }
        //Boton DEL (Borra solo un numero)
        else if (x>=220 && x<=300 && y>=100 && y<=140){ 
            setcolor(3); 
            outtextxy(40,36,"DEL");
        }
        //Boton Division
        else if (x>=320 && x<=400 && y>=100 && y<=140){ 
            setcolor(3); 
            outtextxy(40,36,"÷");
            if(!ocupado1[0]){//Valida que la var1[0] este ocupado
                    printf("No se ha asignado un valor a la variable 1\n");
            }else{
                if(operacion == '0'){//Valida que 'operacion' tenga una operacion asignada
                    operacion = '÷';
                }else if(operacion == '÷'){ //Valida que 'operacion' ya haya sido asignada
                    printf("Solo puedes dividir dos numeros a la vez\n");
                }else{
                    operacion = '÷';
                }
            }
        }
        //Boton Multiplicacion
        else if (x>=320 && x<=400 && y>=160 && y<=200){ 
            setcolor(3); 
            outtextxy(40,36,"x");
            if(!ocupado1[0]){//Valida que la var1[0] este ocupado
                    printf("No se ha asignado un valor a la variable 1\n");
            }else{
                if(operacion == '0'){//Valida que 'operacion' tenga una operacion asignada
                    operacion = 'x';
                }else if(operacion == 'x'){ //Valida que 'operacion' ya haya sido asignada
                    printf("Solo puedes muliplicar dos numeros a la vez\n");
                }else{
                    operacion = 'x';
                }
            }
        }
        //Boton Resta
        else if (x>=320 && x<=400 && y>=220 && y<=260){ 
            setcolor(3); 
            outtextxy(40,36,"-");
            if(!ocupado1[0]){//Valida que la var1[0] este ocupado
                    printf("No se ha asignado un valor a la variable 1\n");
            }else{
                if(operacion == '0'){//Valida que 'operacion' tenga una operacion asignada
                    operacion = '-';
                }else if(operacion == '-'){ //Valida que 'operacion' ya haya sido asignada
                    printf("Solo puedes restar dos numeros a la vez\n");
                }else{
                    operacion = '-';
                }
            }
        }
        //Boton Suma
        else if (x>=320 && x<=400 && y>=280 && y<=320){
            setcolor(3); 
            outtextxy(40,36,"+");
            if(!ocupado1[0]){//Valida que la var1[0] este ocupado
                    printf("No se ha asignado un valor a la variable 1\n");
            }else{
                if(operacion == '0'){//Valida que 'operacion' tenga una operacion asignada
                    operacion = '+';
                }else if(operacion == '+'){ //Valida que 'operacion' ya haya sido asignada
                    printf("Solo puedes sumar dos numeros a la vez\n");
                }
            }
        }
        //Boton IGUAL
        else if (x>=320 && x<=400 && y>=340 && y<=380){
            setcolor(3); 
            outtextxy(40,36,"=");
            if(!ocupado1[0]){
                printf("Debes asignar un valor a la variable 1");
            }else if(!ocupado2[0]){
                printf("Debes asignar un valor a la variable 2");
            }else{
                switch(operacion){
                    case '+':
                        //Convierte las cadenas a numeros
                        intVar1 = convertir(var1);
                        intVar2 = convertir(var2);
                        intResultado = sumar(intVar1,intVar2);
                        printf("%i + %i = %i\n",intVar1,intVar2,intResultado);
                        imprimir(intResultado);
                        break;
                    case '-':
                        //Convierte las cadenas a numeros
                        intVar1 = convertir(var1);
                        intVar2 = convertir(var2);
                        intResultado = restar(intVar1,intVar2);
                        printf("%i - %i = %i\n",intVar1,intVar2,intResultado);
                        break;
                    case 'x':
                        //Convierte las cadenas a numeros
                        intVar1 = convertir(var1);
                        intVar2 = convertir(var2);
                        intResultado = multiplicar(intVar1,intVar2);
                        printf("%i x %i = %i\n",intVar1,intVar2,intResultado);
                        break;
                    case '÷':
                        //Convierte las cadenas a numeros
                        intVar1 = convertir(var1);
                        intVar2 = convertir(var2);
                        intResultado = dividir(intVar1,intVar2);
                        printf("%i ÷ %i = %i\n",intVar1,intVar2,intResultado);
                        break;
                    default:
                        break;
                }
            }
            printf("%s\n","Otra operacion (s/n)?");
            scanf("%c",&cont);
            if(cont=='s'){
                printf("Ok sigamos:\n");
            }else{
                closegraph();
                system("pause");
                exit(0);
            }
        }
    }
}
int sumar(int num1,int num2){
    return (num1+num2);
}
int restar(int num1,int num2){
    return (num1-num2);
}
int multiplicar(int num1,int num2){
    return (num1*num2);
}
int dividir(int num1,int num2){
    return (num1/num2);
}
int convertir(char cadena[]){
    return atoi(cadena);
}
void imprimir(int num){
    char cadena[ArrayTam];//Conversion del entero a cadena
    sprintf(cadena,"%d",num);
    outtextxy(40,36,cadena);
}
