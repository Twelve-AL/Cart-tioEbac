#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o 
#include <string.h> //biblioteca respons�vel por cuidar das string



int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio cria��o variav�l/string
	char arquivo [40];
    char cpf [40];
    char nome [40];
    char sobrenome [40];
    char cargo [40];
    //final da cria��o das variav�is/string
    
    printf ("Digite o CPF a ser cadastrado: "); //coletando informa��es do usu�rio
    scanf ("%s",cpf); //%s refere-se para salvar uma string
    

    strcpy (arquivo, cpf); //Respons�vel por copiar os valores das string
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); // cria o arquivo e o W significa escrever ou write
    fprintf(file, cpf); // salva o valor da variav�l
    fclose(file); // fecho o arquivo
    
    
     file = fopen(arquivo, "a"); // o "a" siginifica = atualizar
     fprintf(file, " Nome:");
     fclose(file);
     
     printf("Digite o nome a ser cadastrado: ");
     scanf("%s",nome); //%s refere-se para armazenar oq foi digitado pelo usu�rio na variav�l/string
     
     file = fopen(arquivo, "a"); // abre o arquivo para atualizar "a"
     fprintf(file, nome); // salva o valor da variav�l
     fclose(file); // fehca o arquivo
     
     file = fopen(arquivo, "a"); // abre o arquivo para atualizar "a"
     fprintf(file, " Sobrenome:"); // aqui s� pede para o computador escrever uma v�rgula mesmo
     fclose(file); // fecha o arquivo
     
     printf("Digite o sobrenome a ser cadastrado: ");
     scanf("%s", sobrenome); // refere-se para armazenar o que foi escrito pelo usu�rio na variav�l "sobrenome"
     
     file = fopen(arquivo, "a"); //abre o arquivo para atualizar "a"
     fprintf(file, sobrenome); //salva o valor da variav�l
     fclose(file); //fecha o arquivo
     
     file = fopen(arquivo, "a"); //abre o arquivo arquivo para atualizar "a"
     fprintf(file, " Cargo:"); //aqui s� pede para o computador escrever uma v�rgula depois do arquivo
     fclose(file); //fecha o arquivos
     
     printf("Digite o cargo a ser cadastrado: "); 
     scanf("%s",cargo); //refere-se a armazenar na variav�l o que foi digitado pelo usu�rio
     
     file = fopen(arquivo, "a"); //abre o arquivo para atualizar "a"
     fprintf(file, cargo); //salva o valor da variav�l
     fclose(file); // fecha o arquivo
     
     file = fopen(arquivo, "a"); //pede para abrir o arquivo para atualizar 
     fprintf(file, "."); //pede para escrever um ponto
     fclose(file); // fecha o arquivo
 
     
	 system("pause"); // pausa esse programa de registro e volta para o "menu"
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //possibilita escrever acentos nas palavras
	
	char cpf[40]; //variav�l criada para armazenar characteres 
	char conteudo[200]; //conte�do foi criado aqui para criar um "banco de dados", possibilitando assim uma consulta 
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf); //armazena o que foi digitado pelo usu�rio na variav�l
	
	FILE *file;
	file = fopen(cpf,"r"); // "r" = ler o arquivo que o usu�rio consultar 
	
	
	if(file == NULL) // se o cpf que o usu�rio est� preocurando n�o existir, escreva o que est� a baixo
	{
	printf("N�o foi possiv�l abrir o arquivo, n�o localizado.\n");
    }
	
	while(fgets(conteudo, 200, file) != NULL) //esquanto o computador preocura as informa��es e n�o for nulo, escreva o que est� a baixo
	{
		printf("\nEssas s�o as informa��es do usu�rio: CPF:",cpf);
		printf("%s", conteudo); //o %s aqui no caso, � para mostrar o que est� armazenado no conte�do, ou seja, no banco de dados
		printf("\n\n");
	}
	
	   system("pause"); //pausa o arquivo
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf); // armazena o que foi escrito pelo usu�rio na variav�l 
	
	remove(cpf); //remover o CPF diretamente no banco de dados, que foi solicitado pelo usu�rio
	
	FILE *file; //sinaliza para chamar o "FILE" para o computadoor que � um arquivo, e cria um novo arquivo com "*file"
	file = fopen(cpf, "r"); //abre o arquivo e l� 
	
	if(file == NULL) //se as informa��es a qual o usu�rio deletou forem nulas, 
	{
		printf("O usu�rio foi deletado do sistema!.\n");
		system("pause");
	}
	
}


int main ()
{
	int opcao=0; //definindo as vari�veiss 
    int laco=1;
    
	
	for(laco=1;laco=1;)
    {
        
		system("cls"); // respons�vel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
   
        printf("\n=== Cart�rio da EBAC ===\n"); //inicio do menu
        printf("Escolha a op��o desejada do menu:\n\n");
        printf("\t1 - Registrar CPF\n");
        printf("\t2 - Consultar CPF\n");
        printf("\t3 - Deletar   CPF\n"); 
        printf("\t4 - sair do sistema\n\n");
        printf("Op��o:"); //fim do menu

        scanf("%d", &opcao); //armazenamento do usuario
   
        system("cls"); //respons�vel por limpar a tela
        
        
        
        switch(opcao)
        {
        	case 1:
        	registro(); //chamama de fun��es registro
        	break;
        	
        	case 2:
        	consulta(); //chamada de fun��es consulta
        	break;
        	
        	case 3:
        	deletar(); //chamada de fun��es deletar
        	break;
        	
        	case 4:
        		printf("Obrigado por utilizar nosso sistema!\n");
        		return 0;
        		break;
        	
        	
        	
        	default:
        		printf("Essa op��o n�o est� dispon�vel\n");
        		system("pause");
        		break;
        	
		}//fim da sele��o
   
   }
}

