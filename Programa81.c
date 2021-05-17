#include<ncurses.h>

#define CTRL(x) (x & 0x1F)

int main(void){	
	initscr();			/* Start curses mode 		  */
	noecho();

    char caracterEscrito;
    /*Presentacion y explicacion de comandos de control*/
    printw("SUPER EDITOR DE TEXTO OSIOSI...\nPRESIONE CTRL+A PARA SALIR...\n");

    /*Empieza a detectar las teclas presionadas*/
    while (caracterEscrito=getch())
    {                
        if (caracterEscrito == CTRL('A'))        {            
            break;
        }
        printw("Presionaste: %s, En ASCII: 0x%02x\n",keyname(caracterEscrito),caracterEscrito);
    }
    
	endwin();			/* End curses mode		  */
	return 0;
}