/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


#include <stdio.h>

#include <string.h>
#include <stdlib.h> //rand();
#include <stdint.h> //uint32_t

#include <unistd.h> //delay


//Definitii
char tabla[]={'-','-','-','-','-','-','-','-','-'};

static uint32_t TimingDelay;

	
void Delay( uint32_t nTime )
{
    usleep( nTime * 1000 );
}

void sendString( char a[] )
{
	int i, n;
	n = strlen(a);
	for (i = 0; i < n; i++)
	{
		putchar( a[i] );
	}
}

void sendChar( char a )
{
	putchar( a );
}

char readChar()
{
	char chr;
	
	chr = getchar();
	return chr;
}

void afisare() 
{
	uint8_t i;
	
    for (i=0; i<9; i++) 
	{
		sendChar( tabla[i] );
		sendString( " " );
       
		if( i==2 || i==5 || i==8 ) 
			sendString( "\n" );
    }
}

_Bool victorie() 
{
	char winner = '-';
	uint8_t i;
  
	if( tabla[0]==tabla[1] && tabla[1]==tabla[2] ) winner = tabla[0]; // linie 1
	if( tabla[3]==tabla[4] && tabla[4]==tabla[5] ) winner = tabla[3]; // linie 2
	if( tabla[6]==tabla[7] && tabla[7]==tabla[8] ) winner = tabla[6]; // linie 3
	if( tabla[0]==tabla[3] && tabla[3]==tabla[6] ) winner = tabla[0]; // coloana 1
	if( tabla[1]==tabla[4] && tabla[4]==tabla[7] ) winner = tabla[1]; // coloana 2
	if( tabla[2]==tabla[5] && tabla[5]==tabla[8] ) winner = tabla[2]; // coloana 3
	if( tabla[0]==tabla[4] && tabla[4]==tabla[8] ) winner = tabla[0]; // diagonala principala
	if( tabla[2]==tabla[4] && tabla[4]==tabla[6] ) winner = tabla[2]; // diagonala secundara

	if( winner == '-' ) 
	{
		winner = '*';
		for(i=0; i<9; i++)
			if( tabla[i] == '-' ) 
				winner = '-';
	}
      
	if( winner == '-' ) 
		return 0;
	else 
	{
		if( winner == 'X' ) 
		{
			afisare(); 
			sendString( "Ati castigat! Felicitari!\n" );
		}
		if( winner == '0' ) 
			sendString( "Nucleo a castigat! Mai incercati!\n" );
		 
		if( winner == '*' ) 
			sendString( "Remiza! Plictisitor!\n" );
		 
		return 1;
   }
}

void mutare0() 
{
	int i=0,ales=0;
	 if(tabla[0] == 'X' && tabla[1] == 'X' && tabla[2] == '-') {i = 2;ales=1;}
	 if(tabla[0] == 'X' && tabla[2] == 'X' && tabla[1] == '-') {i = 1;ales=1;}
	 if(tabla[1] == 'X' && tabla[2] == 'X' && tabla[0] == '-') {i = 0;ales=1;}
	 if(tabla[3] == 'X' && tabla[4] == 'X' && tabla[5] == '-') {i = 5;ales=1;}
	 if(tabla[3] == 'X' && tabla[5] == 'X' && tabla[3] == '-') {i = 4;ales=1;}
	 if(tabla[4] == 'X' && tabla[5] == 'X' && tabla[3] == '-') {i = 3;ales=1;}
	 if(tabla[6] == 'X' && tabla[7] == 'X' && tabla[8] == '-') {i = 8;ales=1;}
	 if(tabla[6] == 'X' && tabla[8] == 'X' && tabla[7] == '-') {i = 7;ales=1;}
	 if(tabla[7] == 'X' && tabla[8] == 'X' && tabla[6] == '-') {i = 6;ales=1;}
	
	 if(tabla[0] == 'X' && tabla[3] == 'X' && tabla[6] == '-') {i = 6;ales=1;}
	 if(tabla[0] == 'X' && tabla[6] == 'X' && tabla[3] == '-') {i = 3;ales=1;}
	 if(tabla[3] == 'X' && tabla[6] == 'X' && tabla[0] == '-') {i = 0;ales=1;}
	 if(tabla[1] == 'X' && tabla[4] == 'X' && tabla[7] == '-') {i = 7;ales=1;}
	 if(tabla[1] == 'X' && tabla[7] == 'X' && tabla[4] == '-') {i = 4;ales=1;}
	 if(tabla[4] == 'X' && tabla[7] == 'X' && tabla[1] == '-') {i = 1;ales=1;}
	 if(tabla[2] == 'X' && tabla[5] == 'X' && tabla[8] == '-') {i = 8;ales=1;}
	 if(tabla[2] == 'X' && tabla[8] == 'X' && tabla[5] == '-') {i = 5;ales=1;}
	 if(tabla[5] == 'X' && tabla[8] == 'X' && tabla[2] == '-') {i = 2;ales=1;}
	
	 if(tabla[0] == 'X' && tabla[4] == 'X' && tabla[8] == '-') {i = 8;ales=1;}
	 if(tabla[0] == 'X' && tabla[8] == 'X' && tabla[4] == '-') {i = 4;ales=1;}
	 if(tabla[4] == 'X' && tabla[8] == 'X' && tabla[0] == '-') {i = 0;ales=1;}
	 if(tabla[6] == 'X' && tabla[4] == 'X' && tabla[2] == '-') {i = 2;ales=1;}
	 if(tabla[6] == 'X' && tabla[2] == 'X' && tabla[4] == '-') {i = 4;ales=1;}
	 if(tabla[2] == 'X' && tabla[4] == 'X' && tabla[6] == '-') {i = 6;ales=1;}
	
	 if(tabla[4] == 'X' && tabla[6] == 'X' && tabla[0] == '-') {i = 0;ales=1;}
	 
	if(tabla[4] == 'X' && tabla[6] == '-' && tabla[2] == '-') {i = 2;ales=1;}
	 if(ales == 0) i=-1;
	if(i==-1)
  while (i==-1) 
	{
    i = rand()%9;
    if (tabla[i]=='-') 
		{
        tabla[i]='0';
        sendString("Nucleo a ales pozitia: \n");
        sendChar(i+1+'0');
        sendString("\n");
        break;
    }
    else i=-1;
  }
	
	else
	{
		if (tabla[i]=='-') 
		{
        tabla[i]='0';
        sendString("Nucleo a ales pozitia: \n");
        sendChar(i+1+'0');
        sendString("\n");
    }
    else 
		{
			i = -1;
			while (i==-1) 
			{
				i = rand()%9;
				if (tabla[i]=='-') 
				{
					tabla[i]='0';
					sendString("Nucleo a ales pozitia: \n");
					sendChar(i+1+'0');
					sendString("\n");
					break;
				}
				else i=-1;
			}
		}
	}
}
	
void mutareX() 
{
   _Bool valid = 0;
   uint8_t m0 = 0;
   while (!valid) 
	 {
     sendString("Alege o pozitie de la 1 la 9.\n");
     while (m0<'1' || m0>'9') 
		 {
       m0 = readChar();
       Delay(1000);
     }
     
     sendString("Ati ales pozitia: \n");
     sendChar(m0);
		 m0 = m0 - 48;
     sendString("\n");
		 
     if (tabla[m0-1]!='-')
				sendString("Pozitie eronata!\n");
     
		 else 
		 { 
            tabla[m0-1]='X';
            valid = 1;
     }
		 
   }
}

int main()
{		
		uint8_t i;
		while(1)
		{
				sendString("Salut!\n");
				sendString("Tu vei muta primul - esti cu X.\n");
				sendString("Tabla de joc are pozitiile numerotate de la 1 la 9.\n");
				sendString("1 2 3\n");
				sendString("4 5 6\n");
				sendString("7 8 9\n");
			
				do
				{
					mutareX();
					if (victorie()) break;
					mutare0();
					afisare();
				}while(!victorie());
				
				Delay(5000);
				
				for (i=0; i<100; i++) 
						sendString("\n");
				for (i=0; i<9; i++) 
					tabla[i]='-';
		}
}