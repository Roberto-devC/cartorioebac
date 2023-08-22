/* ============================================================================

        				 PROGRAMAÇÃO EM C:
    
    Autor: Roberto Alves Monteiro Junior
    Data:  09/08/2023

============================================================================ */


/* ========================================================================= */
/* --- Bibliotecas --- */
#include <stdio.h> /* Biblioteca de comunicação com o úsuario*/
#include <stdlib.h> /* Biblioteca de alocação de espaço na memória */
#include <locale.h>  /* Biblioteca de alocações de texto por região */
#include <string.h> /* Biblioteca responsável por cuidar das strings */
/* ========================= funções externas ============================== */
int registro() /*Função responsável por cadastrar usuários no sistema */
{ 
    /* incio da criação de variáveis/ strings */
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	/*Final da criação de variáveis/sreings */
	
	printf("Digite o CPF a ser cadastrado:   ");/* Coletando informação do usuário*/
	scanf("%s", cpf);/* Salvando a informação na memoria*/
	
	strcpy(arquivo, cpf);/* Responsável por copiar os valores das strings */
	
	FILE *file; /* cria o arquivo */
	file = fopen(arquivo, "w"); /* cria o arquivo */
	fprintf(file, cpf); /* salva o valor da variável */
	fclose(file); /* fecha o arquivo */
	
	file = fopen(arquivo, "a");/* Abre o arquivo com "a" (de atualização)*/
	fprintf(file, ",");/* inclui a virgula */
	fclose(file); /*Fecha o arquivo novamente */
	
	printf("Digite o nome a ser cadastrado:  ");/* Coletando informação do usuário*/
	scanf("%s", nome);/* Salvando a informação na memoria*/
	
	file = fopen(arquivo, "a");/* Abre o arquivo com "a" (de atualização)*/
	fprintf(file,nome);/* salva o valor da variável */
	fclose(file);/* fecha o arquivo */
	
	file = fopen(arquivo, "a");/* Abre o arquivo com "a" (de atualização)*/
	fprintf(file, ",");/* inclui a virgula */
	fclose(file);/*Fecha o arquivo novamente */
	
	printf("Digite o sobrenome a ser cadastrado:  ");/* Coletando informação do usuário*/
	scanf("%s", sobrenome);/* Salvando a informação na memoria*/
	
	file = fopen(arquivo, "a");/* Abre o arquivo com "a" (de atualização)*/
	fprintf(file,sobrenome);/* salva o valor da variável */
	fclose(file);/* fecha o arquivo */
	
	file = fopen(arquivo, "a");/* Abre o arquivo com "a" (de atualização)*/
	fprintf(file, ",");/* inclui a virgula */
	fclose(file);/* fecha o arquivo */
	
	printf("Digite o cargo a ser cadastrado:   ");/* Coletando informação do usuário*/
	scanf("%s", cargo);/* Salvando a informação na memoria*/
	
	file = fopen(arquivo, "a");/* Abre o arquivo com "a" (de atualização)*/
	fprintf(file,cargo);/* salva o valor da variável */
	fclose(file);/* fecha o arquivo */
	
	system("pause");/*pausa o sistema*/
	
	
	
}

int consulta()/*Função responsável por consultar usuários no sistema */
{
	setlocale (LC_ALL,"Portuguese_Brazil");/*definindo a linguagem*/
	/* incio da criação de variáveis/ strings */
	char cpf[40];
	char conteudo[200];
	/*Final da criação de variáveis/strings */
	
		
	printf("Digite o CPF a ser consultado:  ");/* Coletando informação do usuário*/
	scanf("%s", cpf);/* Salvando a informação na memoria*/
	
	FILE  *file;/* cria o arquivo */
	file = fopen(cpf, "r");/* Abre o arquivo com "r" (de read = ler em inglês)*/
	
	if(file == NULL)/*operador relacional if*/
	{
		printf("Não foi possivel abrir o arquivo. Não localizado! \n\n");
	}/*Fim da estrutura de decisão*/	
	
	while(fgets(conteudo, 200, file) != NULL)/*Inicio laço dee repetição while*/
	{
		printf("\n Essas são as informações do usuário:  ");
		printf("%s", conteudo);
		printf("\n\n\n");
    }/*fim do laço de repetição*/
		system("pause");/*pausa o sistema*/
		
	
}
int deletar()/*Função responsável por deletar usuários no sistema */
{
	char cpf[40];/* criação de variáveis/ strings */
	
	printf("Digite o CPF do usuário a ser deletado:  ");/* Coletando informação do usuário*/
	scanf("%s", cpf);/* Salvando a informação na memoria*/
	
	remove(cpf);/* acessando função remove na biblioteca stdlib.h*/
	
	FILE *file;/* cria o arquivo */
	file = fopen(cpf, "r");/* Abre o arquivo com "r" (de read = ler em inglês)*/
	
	if(cpf == NULL)/*inicio operador relacional if/else*/
	{
		printf(" O usuário não se encontra no sistema. \n");
		
		system("pause");
	}
	else
	printf(" Usuário deletado com sucesso! \n");
	
	system("pause");
		
}/*fim operador relacional if/else*/




/* ========================================================================= */
/* --- Função Principal --- */
main()
{	 /* Incio variável/strings */
	int opcao = 0; /* Variável*/
	int laco;
	 /* fim variavel/strings*/
	



	{
		system("cls");
		
			for(laco=0;laco=1;)/* Início laço de repetição */
		  {  
			
		    setlocale (LC_ALL,"Portuguese_Brazil");/* Biblioteca de linguagem local*/
		  
			  	printf("\t\t### Cartório da EBAC ### \n\n");/* Início do menu */
				printf("Escolha a opção desejada de MENU: \n\n");
				printf("\t1: Registrar nomes: \n");
			  	printf("\t2: Colsultar nomes: \n");
			  	printf("\t3: Deletar nomes: \n");
			  	printf("\t4: Sair do Sistema: \n\n");
			  	printf("Opção: ");/* Fim do menu*/
				  	
			  	scanf("%d", &opcao); /* Armazenamento da escolha do usúario */
			 
			  	system("cls");/*responsável por limpar a tela*/
		  	
		  	switch(opcao) /*inicio da seleção do menu */
		  	{
			 	case 1 :
			 	registro();	/*chamada da função (registro)*/
		  		break;
		  		
		  		case 2 :
			 	consulta();	/*chamada da função (consulta)*/
		  		break;
		  		
		  		case 3 :
				deletar();/*chamada da função (deletar)*/
		  	  	break;
		  	  	
		  	  	case 4: 
		  	  	printf("Obrigado por utilizar nosso Sistema! \n");
		  	  	return 0;
		  	  	break;
		  		
		  		default:/*caso usuário entrar com uma informação inválida */
		  		
		  		printf("Essa opção não está disponível! \n\n\n");
		  		system("pause");
		  		break;
		  	  	
		  	}/* Fim da seleção */
        }/* Fim do laço de repetição */
    }

	    
   
    

  
  	 system("PAUSE");	                             /* pausa excução (Pressione qualquer tecla para continuar . . .) */
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
