/*
Algoritmo e Programação III
Quinta - Feira

Gabriel Andriola
Rafael Luciano


*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#define MAXLINHA 15
void display(char t[3][3]){

   printf("=====================\n");
   printf("==| JOGO DA VELHA |==\n");
   printf("=====================\n");
   printf("\n\n      0   1   2   Y\n");
   printf("    0 %c | %c | %c \n",t[0][0],t[0][1],t[0][2]);
   printf("     ---|---|--- \n ");
   printf("   1 %c | %c | %c \n",t[1][0],t[1][1],t[1][2]);
   printf("     ---|---|--- \n ");
   printf("   2 %c | %c | %c \n\n",t[2][0],t[2][1],t[2][2]);
   printf("    X\n\n");
   printf("DIGITE X=8 e Y=8 PARA SALVAR E SAIR\n");
}

void teste_trinca(int *x, int *y, int *jg, int *teste, int velha, char t[3][3])
{
	
//TESTE HORIZONTAL//
		
		if(*x==0)
         if((t[0][0]==t[0][1]) && (t[0][1]==t[0][2]))
         {
            display(t);
            printf("\n Jogador %i GANHOU!! \n",*jg);
               getch();
         	*teste=0;
         }
         
    	if(*x==1)
         if((t[1][0]==t[1][1]) && (t[1][1]==t[1][2]))
         {
            display(t);
            printf("\n Jogador %i GANHOU!! \n",*jg);
               getch();
            *teste=0;
         }
        if(*x==2) 
         if((t[2][0]==t[2][1]) && (t[2][1]==t[2][2]))
         {
            display(t);
            printf("\n Jogador %i GANHOU!! \n",*jg);
               getch();
            *teste=0;
         }

//TESTE VERTICAL//

		if(*y==0)
         if((t[0][0]==t[1][0]) && (t[1][0]==t[2][0]))
         {
        	display(t);
        	printf("\n Jogador %i GANHOU!! \n",*jg);
        	   getch();
            *teste=0;
         }
         
        if(*y==1)
         if((t[0][1]==t[1][1]) && (t[1][1]==t[2][1]))
         {
        	display(t);
        	printf("\n Jogador %i GANHOU!! \n",*jg);
        	   getch();
        	*teste=0;
         }
         
        if(*y==2)
         if((t[0][2]==t[1][2]) && (t[1][2]==t[2][2]))
         {
        	display(t);
        	printf("\n Jogador %i GANHOU!! \n",*jg);
        	   getch();
            *teste=0;
         }
         
//TESTA DIAGONAL//
    
    	if(((*x==0) && (*y==0))||((*x==1) && (*y==1))||((*x==2) && (*y==2)))
    	{
         if((t[0][0]==t[1][1]) && (t[0][0]==t[2][2]))
         {
            display(t);
            printf("\n Jogador %i GANHOU!! \n",*jg);
               getch();
            *teste=0;
         }
    	}
    	
        if(((*x==0)&&(*y==2))||((*x==1)&&(*y==1))||((*x==2)&&(*y==0)))
        {
         if((t[0][2]==t[1][1]) && (t[0][2]==t[2][0]))
         {
            display(t);
            printf("\n Jogador %i GANHOU!! \n",*jg);
            getch();
            *teste=0;
         }
    	}
// TESTE VELHA//

        if(velha >= 9 && *teste == 1)
        {
        	printf("\n DEU VELHA !");
			*teste = 0;	
		}
}

void play1(char t[3][3], int *x, int *y)
{
   display(t);
   printf("\nJogador 1: Digite a coordenada X: ");
   fflush(stdin);
   scanf("%i",&*x);
   printf("\nJogador 1: Digite a coordenada Y: ");
   fflush(stdin);
   scanf("%i",&*y);
}

void play2(int *x, int *y, char t[3][3])
{
   display(t);      
   printf("\nJogador 2: Digite a coordenada X: ");
   fflush(stdin);
   scanf("%i",&*x);
   printf("\nJogador 2: Digite a coordenada Y: ");
   fflush(stdin);
   scanf("%i",&*y);
}

void salvar(int *jg, int *teste, int velha, char t[3][3], int *player, int *x, int *y){
	
	FILE *pont_arq;
	pont_arq = fopen ( "jogo.txt", "w" );
	
	if (pont_arq == NULL)
    printf ("ERRO: Arquivo não pode ser aberto!\n");
    else{
    	 fprintf(pont_arq, "%c", t[0][0]);
    	 fprintf(pont_arq, "%c", t[0][1]);
    	 fprintf(pont_arq, "%c", t[0][2]);
    	 fprintf(pont_arq, "%c", t[1][0]);
    	 fprintf(pont_arq, "%c", t[1][1]);
    	 fprintf(pont_arq, "%c", t[1][2]);
    	 fprintf(pont_arq, "%c", t[2][0]);
    	 fprintf(pont_arq, "%c", t[2][1]);
    	 fprintf(pont_arq, "%c", t[2][2]);
    	 fclose(pont_arq);}
    	 
		pont_arq = fopen ( "valor.txt", "w" );
		
		if (pont_arq == NULL)
  	  		printf ("ERRO: Arquivo não pode ser aberto!\n");
  	  	else{
    		fprintf(pont_arq, "%i", *player);
    	 	fprintf(pont_arq, "%i", *jg);
    	 	fprintf(pont_arq, "%i", *teste);
    	 	fprintf(pont_arq, "%i", velha);
    	 	fprintf(pont_arq, "%i", *x);
    	 	fprintf(pont_arq, "%i", *y);
    		printf ("\nMSG: Arquivo criado corretamente!\n"); 	
	}
	getch();
}

int main()
{
   	char tela[3][3];
   	int teste = 1;
   	int x, y;
   	int velha = 0;
   	int jogador;
   	int jogada;
   	int player;
   	setlocale(LC_ALL, "Portuguese");
   	int menu=1;
   
	do{
		system("cls");
		fflush(stdin);
		printf("\n\n -----------------------");
		printf("\n 1 - Novo Jogo ");
		printf("\n 2 - Continuar Jogo Salvo ");
		printf("\n 3 - Sair ");
		printf("\n\n Escolha uma opção: ");
		scanf("%i",&menu);
		fflush(stdin);
		
		switch (menu){
		
			case 1: system("cls"); //Novo Jogo

   				for(int i=0;i<3;i++)
      				for(int j=0;j<3;j++)
         				tela[i][j]=' ';
      
      				while(teste!=0)
      				{      
        				if(teste!=0)
         				{
            				jogada = 0;
							jogador = 1;  
            				play1(tela, &x, &y);
            				if(x==8 && y==8){
            							player=1;
   										salvar(&jogador, &teste, velha, tela, &player, &x, &y);
   										return 0;
  									 	}
            				printf("\nX/Y: ");
            				printf("%i %i", x, y);
            				getch();
 
            				while (jogada == 0)
            				{
            					if(tela[x][y]==' ')
               					{
									tela[x][y]='X';
               						system("cls");
               						velha++;
               						teste_trinca (&x, &y, &jogador, &teste, velha, tela);   
			   						jogada = 1;
            					}
            					else
            					{
               						system("cls");
               						printf("\nPosição já utilizada! \n"); 
               						printf("\nPressione qualquer tecla para entrar novo valor\n");
               						getch();
               						system("cls");
               						play1(tela, &x, &y);
            					}
         					}
         				}
         				if(teste!=0)
         				{
            				jogada = 0;
							jogador = 2;         
            				play2(&x, &y, tela);
            				if(x==8 && y==8){
            							player=2;
   										salvar(&jogador, &teste, velha, tela, &player, &x, &y);
   										return 0;
  									 	}
        					while (jogada == 0)
            				{
            					if(tela[x][y]==' ')
            					{
									velha++;
               						tela[x][y]='O';
               						system("cls");
               						teste_trinca(&x, &y, &jogador, &teste, velha, tela);
									jogada = 1; 
								}			
            					else
            					{
               						system("cls");
               						printf("\nPosição já utilizada! \n"); 
               						printf("\nPressione qualquer tecla para entrar novo valor!!\n");
               						getch();
               						system("cls");
               						play2(&x, &y, tela);
            					}		
         					}	
						}
					}	
					
			case 2: {
						int saveplayer;
						FILE *pont_arq;
						pont_arq = fopen ( "jogo.txt", "r" );
   						if ( pont_arq != NULL )  {
  						  fscanf(pont_arq,"%c%c%c%c%c%c%c%c%c",&tela[0][0], &tela[0][1], &tela[0][2], &tela[1][0] ,&tela[1][1], &tela[1][2], &tela[2][0],&tela[2][1], &tela[2][2]);
   						  fclose ( pont_arq );}
   				
						pont_arq = fopen ( "valor.txt", "r" );
   						if ( pont_arq != NULL )  {
  						  fscanf(pont_arq,"%i%i%i%i%i%i",&saveplayer, &jogador, &teste, &velha, &x, &y);
   						  fclose ( pont_arq );	 	
   						  
   						  if(saveplayer=1){
   						  	system("cls"); 

   				for(int i=0;i<3;i++)
      				for(int j=0;j<3;j++)
         				
      
      				while(teste!=0)
      				{      
        				if(teste!=0)
         				{
            				jogada = 0;
							jogador = 1;  
            				play1(tela, &x, &y);
            				if(x==8 && y==8){
            							player=1;
   										salvar(&jogador, &teste, velha, tela, &player, &x, &y);
   										return 0;
  									 	}
            				printf("\nX/Y: ");
            				printf("%i %i", x, y);
            				getch();
 
            				while (jogada == 0)
            				{
            					if(tela[x][y]==' ')
               					{
									tela[x][y]='X';
               						system("cls");
               						velha++;
               						teste_trinca (&x, &y, &jogador, &teste, velha, tela);   
			   						jogada = 1;
            					}
            					else
            					{
               						system("cls");
               						printf("\nPosição já utilizada! \n"); 
               						printf("\nPressione qualquer tecla para entrar novo valor\n");
               						getch();
               						system("cls");
               						play1(tela, &x, &y);
            					}
         					}
         				}
         				if(teste!=0)
         				{
            				jogada = 0;
							jogador = 2;         
            				play2(&x, &y, tela);
            				if(x==8 && y==8){
            							player=2;
   										salvar(&jogador, &teste, velha, tela, &player, &x, &y);
   										return 0;
  									 	}
        					while (jogada == 0)
            				{
            					if(tela[x][y]==' ')
            					{
									velha++;
               						tela[x][y]='O';
               						system("cls");
               						teste_trinca(&x, &y, &jogador, &teste, velha, tela);
									jogada = 1; 
								}			
            					else
            					{
               						system("cls");
               						printf("\nPosição já utilizada! \n"); 
               						printf("\nPressione qualquer tecla para entrar novo valor!!\n");
               						getch();
               						system("cls");
               						play2(&x, &y, tela);
            					}		
         					}	
						}
					}	

   						  	}
						}				
						getch();
						break;}	
			case 3: system("cls");
					printf("\nSistema encerrado!!!");
					getch();
					break;	
					}
	}while(menu!=3);
	getch();
}

