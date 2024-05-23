#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string


int registro() //função responsável por cadastrar os usuarios no sistema
{
	//inicio da criação de variáveis/strings
	char arquivo[40]; //colchete é porque é uma string
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado:"); //coletando informação do usuário
	scanf("%s",cpf); // "%s" refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file= fopen(arquivo, "w"); // cria o arquivo e "w" vem de write
	fprintf(file,cpf); //salvo o valor da variavel que nesse caso é cpf
	fclose(file); //fecha o arquivo
	
	file= fopen(arquivo, "a"); //a é pra atualizar informação pois o file ja foi criado
	fprintf(file,","); // a virgula nas aspas e pra criar espaço
	fclose(file); // assim como é necessário abrir o file, é necessário fechar.
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s",nome);
	
	file= fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file= fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado:");
	scanf("%s", sobrenome);
	
	file= fopen(arquivo,"a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file= fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado:");
	scanf("%s", cargo);
	
	file=fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file= fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	system("pause");
	
	
}
int consulta()
{
		setlocale(LC_ALL, "Portuguese");
		char cpf[40];
		char conteudo[200];
		
		
		printf("Digite o CPF a ser consultado: ");
		scanf("%s", cpf);
		
		FILE *file;
		file = fopen(cpf, "r"); //r significa read, pra fazer leitura.
		
		if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!");	
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\n Essas são as informações do usuário:");
		printf("%s", conteudo);
		printf("\n\n");
		
	}	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado:");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file=fopen(cpf,"r");
	
	if(file== NULL)
	{
		printf("O usuário não se encontra no sistema! \n");
		system("pause");
	}
	

	
	
}

int main()
{
	int opcao=0; //definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls"); //limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo linguagem em português
	
		printf("###  Cartório da EBAC ### \n\n"); //inicio do menu
		printf("Escolha a opção desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção:");// fim do menu
	
	
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls"); //responsável por limpar a tela
		
		switch(opcao)
		{
			case 1: //pra iniciar o switch
			
	    	registro(); //chamada das funções
	    	break; //pra encerrar o switch
	    	
	    	case 2:
	    	consulta();
			break;
			
			case 3:
			deletar();
			break;	
			
		
			
						
			default:
			printf("Essa opção não está disponível\n");
			system("pause");
			break;
		}
	
	
	} 
    
	
}	





