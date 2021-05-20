#include<ncurses.h>
#include<string.h>

#define CTRL(x) (x & 0x1F)

void despliegaPresentacion();
void despliegaInstrucciones();
void despliegaInfoArchivo(char* info);

int main(void){	
	initscr();			/* Start curses mode 		  */
	noecho();
    char textoArchivo[3000]="adfadfadfdfdfasdf\nadf adsfadf\nsasdas dfd saf\nklj lkjl kjlkj\nljlk jl  kjlkj\nkljlkjl kjlkj.\nFin del documento.\n\n";
    char textoNuevo[200]="";
    char caracterEscrito;
    
    despliegaPresentacion();
    despliegaInfoArchivo(textoArchivo);
    /*Empieza a detectar las teclas presionadas*/
    while (caracterEscrito=getch())
    {                
        if (caracterEscrito == CTRL('A'))        {            
            break;
        }
        else if(caracterEscrito == CTRL('D')){
            despliegaInstrucciones();
            echo();                        
            getstr(textoNuevo);            
            strcat(textoArchivo,textoNuevo);
            strcat(textoArchivo,"\n");
            clear();
            despliegaPresentacion();
            despliegaInfoArchivo(textoArchivo);
            
            noecho();
        }
        else if (caracterEscrito == CTRL('F'))
        {
            printw("\nGUARDADO UWU .......\n");
        }
        else{
            printw("SIN ACCION, PRESIONE CTRL + char\n");
        }        
        
    }        
	endwin();			/* End curses mode		  */
	return 0;
}



void despliegaPresentacion(){
    /*Presentacion y explicacion de comandos de control*/
    printw("SUPER EDITOR DE TEXTO OSIOSI...\nPRESIONE CTRL+A PARA SALIR...\nPRESIONE CTRL+D PARA ESCRIBIR NUEVA LINEA AL FINAL...\n\n");    
}
void despliegaInstrucciones(){
    /*Presentacion y explicacion de comandos de control*/
    printw("INSERTA TEXTO,PRESIONA ENTER PARA ANADIR:\n");
}
void despliegaInfoArchivo(char* info){
    printw(info);
}