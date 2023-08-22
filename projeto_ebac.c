/* ============================================================================

        				 PROGRAMA��O EM C:
    
    Autor: Roberto Alves Monteiro Junior
    Data:  09/08/2023

============================================================================ */


/* ========================================================================= */
/* --- Bibliotecas --- */
#include <stdio.h> /* Biblioteca de comunica��o com o �suario*/
#include <stdlib.h> /* Biblioteca de aloca��o de espa�o na mem�ria */
#include <locale.h>  /* Biblioteca de aloca��es de texto por regi�o */
#include <string.h> /* Biblioteca respons�vel por cuidar das strings */
/* ========================= fun��es externas ============================== */
int registro() /*Fun��o respons�vel por cadastrar usu�rios no sistema */
{ 
    /* incio da cria��o de vari�veis/ strings */
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	/*Final da cria��o de vari�veis/sreings */
	
	printf("Digite o CPF a ser cadastrado:   ");/* Coletando informa��o do usu�rio*/
	scanf("%s", cpf);/* Salvando a informa��o na memoria*/
	
	strcpy(arquivo, cpf);/* Respons�vel por copiar os valores das strings */
	
	FILE *file; /* cria o arquivo */
	file = fopen(arquivo, "w"); /* cria o arquivo */
	fprintf(file, cpf); /* salva o valor da vari�vel */
	fclose(file); /* fecha o arquivo */
	
	file = fopen(arquivo, "a");/* Abre o arquivo com "a" (de atualiza��o)*/
	fprintf(file, ",");/* inclui a virgula */
	fclose(file); /*Fecha o arquivo novamente */
	
	printf("Digite o nome a ser cadastrado:  ");/* Coletando informa��o do usu�rio*/
	scanf("%s", nome);/* Salvando a informa��o na memoria*/
	
	file = fopen(arquivo, "a");/* Abre o arquivo com "a" (de atualiza��o)*/
	fprintf(file,nome);/* salva o valor da vari�vel */
	fclose(file);/* fecha o arquivo */
	
	file = fopen(arquivo, "a");/* Abre o arquivo com "a" (de atualiza��o)*/
	fprintf(file, ",");/* inclui a virgula */
	fclose(file);/*Fecha o arquivo novamente */
	
	printf("Digite o sobrenome a ser cadastrado:  ");/* Coletando informa��o do usu�rio*/
	scanf("%s", sobrenome);/* Salvando a informa��o na memoria*/
	
	file = fopen(arquivo, "a");/* Abre o arquivo com "a" (de atualiza��o)*/
	fprintf(file,sobrenome);/* salva o valor da vari�vel */
	fclose(file);/* fecha o arquivo */
	
	file = fopen(arquivo, "a");/* Abre o arquivo com "a" (de atualiza��o)*/
	fprintf(file, ",");/* inclui a virgula */
	fclose(file);/* fecha o arquivo */
	
	printf("Digite o cargo a ser cadastrado:   ");/* Coletando informa��o do usu�rio*/
	scanf("%s", cargo);/* Salvando a informa��o na memoria*/
	
	file = fopen(arquivo, "a");/* Abre o arquivo com "a" (de atualiza��o)*/
	fprintf(file,cargo);/* salva o valor da vari�vel */
	fclose(file);/* fecha o arquivo */
	
	system("pause");/*pausa o sistema*/
	
	
	
}

int consulta()/*Fun��o respons�vel por consultar usu�rios no sistema */
{
	setlocale (LC_ALL,"Portuguese_Brazil");/*definindo a linguagem*/
	/* incio da cria��o de vari�veis/ strings */
	char cpf[40];
	char conteudo[200];
	/*Final da cria��o de vari�veis/strings */
	
		
	printf("Digite o CPF a ser consultado:  ");/* Coletando informa��o do usu�rio*/
	scanf("%s", cpf);/* Salvando a informa��o na memoria*/
	
	FILE  *file;/* cria o arquivo */
	file = fopen(cpf, "r");/* Abre o arquivo com "r" (de read = ler em ingl�s)*/
	
	if(file == NULL)/*operador relacional if*/
	{
		printf("N�o foi possivel abrir o arquivo. N�o localizado! \n\n");
	}/*Fim da estrutura de decis�o*/	
	
	while(fgets(conteudo, 200, file) != NULL)/*Inicio la�o dee repeti��o while*/
	{
		printf("\n Essas s�o as informa��es do usu�rio:  ");
		printf("%s", conteudo);
		printf("\n\n\n");
    }/*fim do la�o de repeti��o*/
		system("pause");/*pausa o sistema*/
		
	
}
int deletar()/*Fun��o respons�vel por deletar usu�rios no sistema */
{
	char cpf[40];/* cria��o de vari�veis/ strings */
	
	printf("Digite o CPF do usu�rio a ser deletado:  ");/* Coletando informa��o do usu�rio*/
	scanf("%s", cpf);/* Salvando a informa��o na memoria*/
	
	remove(cpf);/* acessando fun��o remove na biblioteca stdlib.h*/
	
	FILE *file;/* cria o arquivo */
	file = fopen(cpf, "r");/* Abre o arquivo com "r" (de read = ler em ingl�s)*/
	
	if(cpf == NULL)/*inicio operador relacional if/else*/
	{
		printf(" O usu�rio n�o se encontra no sistema. \n");
		
		system("pause");
	}
	else
	printf(" Usu�rio deletado com sucesso! \n");
	
	system("pause");
		
}/*fim operador relacional if/else*/




/* ========================================================================= */
/* --- Fun��o Principal --- */
main()
{	 /* Incio vari�vel/strings */
	int opcao = 0; /* Vari�vel*/
	int laco;
	 /* fim variavel/strings*/
	



	{
		system("cls");
		
			for(laco=0;laco=1;)/* In�cio la�o de repeti��o */
		  {  
			
		    setlocale (LC_ALL,"Portuguese_Brazil");/* Biblioteca de linguagem local*/
		  
			  	printf("\t\t### Cart�rio da EBAC ### \n\n");/* In�cio do menu */
				printf("Escolha a op��o desejada de MENU: \n\n");
				printf("\t1: Registrar nomes: \n");
			  	printf("\t2: Colsultar nomes: \n");
			  	printf("\t3: Deletar nomes: \n");
			  	printf("\t4: Sair do Sistema: \n\n");
			  	printf("Op��o: ");/* Fim do menu*/
				  	
			  	scanf("%d", &opcao); /* Armazenamento da escolha do us�ario */
			 
			  	system("cls");/*respons�vel por limpar a tela*/
		  	
		  	switch(opcao) /*inicio da sele��o do menu */
		  	{
			 	case 1 :
			 	registro();	/*chamada da fun��o (registro)*/
		  		break;
		  		
		  		case 2 :
			 	consulta();	/*chamada da fun��o (consulta)*/
		  		break;
		  		
		  		case 3 :
				deletar();/*chamada da fun��o (deletar)*/
		  	  	break;
		  	  	
		  	  	case 4: 
		  	  	printf("Obrigado por utilizar nosso Sistema! \n");
		  	  	return 0;
		  	  	break;
		  		
		  		default:/*caso usu�rio entrar com uma informa��o inv�lida */
		  		
		  		printf("Essa op��o n�o est� dispon�vel! \n\n\n");
		  		system("pause");
		  		break;
		  	  	
		  	}/* Fim da sele��o */
        }/* Fim do la�o de repeti��o */
    }

	    
   
    

  
  	 system("PAUSE");	                             /* pausa excu��o (Pressione qualquer tecla para continuar . . .) */
 	 return 0;                                      /* retorna 0, se main for executada corretamente */
  

} /* end main */


/* ============================================================================  
                                                              
                                       _                      
                                      / \                     
                                     |oo >                    
                                     _\=/_                    
                    ___         #   /  _  \   #               
                   /<> \         \\//|/.\|\\//                
                 _|_____|_        \/  \_/  \/                 
                | | === | |          |\ /|                    
                |_|  0  |_|          \_ _/                    
                 ||  0  ||           | | |                    
                 ||__*__||           | | |                    
                |* \___/ *|          []|[]                    
                /=\ /=\ /=\          | | |                    
________________[_]_[_]_[_]_________/_]_[_\_______________________________
                                                              
                                                              
============================================================================ */
/* --- Final do Programa --- */
