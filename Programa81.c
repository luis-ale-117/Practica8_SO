#include<ncurses.h>
#include<string.h>

#define CTRL(x) (x & 0x1F)

void creaVentanaEntrada();
void creaVentanaPresentacion();
void creaVentanaArchivo();

void despliegaPresentacion();
void despliegaInstrucciones();
void despliegaInfoArchivo(char* info);


WINDOW *ventEntrada,*ventPresentacion,*ventArchivo;

int main(void){	
	initscr();			/* Start curses mode 		  */
	noecho();
    char textoArchivo[3000]="adfadfadfdfdfasdf\nadf adsfadf\nsasdas dfd saf\nklj lkjl kjlkj\nljlk jl  kjlkj\nkljlkjl kjlkj.\nFin del documento.\n\n";
    char textoNuevo[200]="";
    char caracterEscrito;
    
    creaVentanaPresentacion();
    creaVentanaArchivo();
    creaVentanaEntrada();  
    
    despliegaInfoArchivo(textoArchivo);
    wrefresh(ventArchivo);
    //refresh();  

    /*Empieza a detectar las teclas presionadas*/
    while (caracterEscrito=wgetch(ventEntrada))
    {                
        if (caracterEscrito == CTRL('A'))        {            
            break;
        }
        else if(caracterEscrito == CTRL('D')){            
            echo();
            
            wmove(ventEntrada,1,1);
            wgetstr(ventEntrada,textoNuevo);            
            strcat(textoArchivo,textoNuevo);
            strcat(textoArchivo,"\n");
            despliegaInfoArchivo(textoArchivo);
            wrefresh(ventArchivo);

            noecho();
        }
        /*else if (caracterEscrito == CTRL('F'))
        {
            printw("\nGUARDADO UWU .......\n");
        }*/
        else{
            //wmove(ventArchivo,1,1);
            mvwprintw(ventArchivo,1,1,"SIN ACCION, PRESIONE CTRL + char");
            wrefresh(ventArchivo);
        }        
        
    }        
	endwin();			/* End curses mode		  */
	return 0;
}


void creaVentanaEntrada(){
    int yMax, xMax;
    getmaxyx(stdscr,yMax,xMax);
    ventEntrada = newwin(3,xMax-5,yMax-5,3);
    box(ventEntrada,0,0);
    wrefresh(ventEntrada);
    wmove(ventEntrada,1,1);
}
void creaVentanaPresentacion(){
    int yMax, xMax;
    getmaxyx(stdscr,yMax,xMax);
    ventPresentacion = newwin(6,xMax-5,1,3);
    box(ventPresentacion,0,0);
    wrefresh(ventPresentacion);
    despliegaPresentacion();    
}
void creaVentanaArchivo(){
    int yMax, xMax;
    getmaxyx(stdscr,yMax,xMax);
    ventArchivo = newwin(12,xMax-5,9,3);
    box(ventArchivo,0,0);
    wrefresh(ventArchivo);       
}


void despliegaPresentacion(){
    /*Presentacion y explicacion de comandos de control*/
    wmove(ventPresentacion,1,1);
    wprintw(ventPresentacion,"SUPER EDITOR DE TEXTO OSIOSI...");
    wmove(ventPresentacion,2,1);
    wprintw(ventPresentacion,"PRESIONE CTRL+A PARA SALIR...");
    wmove(ventPresentacion,3,1);
    wprintw(ventPresentacion,"PRESIONE CTRL+D PARA ESCRIBIR NUEVA LINEA AL FINAL...");    
    wrefresh(ventPresentacion);
}
void despliegaInstrucciones(){
    /*Presentacion y explicacion de comandos de control*/
    printw("INSERTA TEXTO,PRESIONA ENTER PARA ANADIR:\n");
}
void despliegaInfoArchivo(char* info){
    mvwprintw(ventArchivo,1,1,info);
}