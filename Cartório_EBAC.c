#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de texto por região 
#include <string.h> //biblioteca responsável por cuidar das string



int registro() //função responsável por cadastrar os usuários no sistema
{
	//início criação variavél/string
	char arquivo [40];
    char cpf [40];
    char nome [40];
    char sobrenome [40];
    char cargo [40];
    //final da criação das variavéis/string
    
    printf ("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
    scanf ("%s",cpf); //%s refere-se para salvar uma string
    

    strcpy (arquivo, cpf); //Responsável por copiar os valores das string
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); // cria o arquivo e o W significa escrever ou write
    fprintf(file, cpf); // salva o valor da variavél
    fclose(file); // fecho o arquivo
    
    
     file = fopen(arquivo, "a"); // o "a" siginifica = atualizar
     fprintf(file, " Nome:");
     fclose(file);
     
     printf("Digite o nome a ser cadastrado: ");
     scanf("%s",nome); //%s refere-se para armazenar oq foi digitado pelo usuário na variavél/string
     
     file = fopen(arquivo, "a"); // abre o arquivo para atualizar "a"
     fprintf(file, nome); // salva o valor da variavél
     fclose(file); // fehca o arquivo
     
     file = fopen(arquivo, "a"); // abre o arquivo para atualizar "a"
     fprintf(file, " Sobrenome:"); // aqui só pede para o computador escrever uma vírgula mesmo
     fclose(file); // fecha o arquivo
     
     printf("Digite o sobrenome a ser cadastrado: ");
     scanf("%s", sobrenome); // refere-se para armazenar o que foi escrito pelo usuário na variavél "sobrenome"
     
     file = fopen(arquivo, "a"); //abre o arquivo para atualizar "a"
     fprintf(file, sobrenome); //salva o valor da variavél
     fclose(file); //fecha o arquivo
     
     file = fopen(arquivo, "a"); //abre o arquivo arquivo para atualizar "a"
     fprintf(file, " Cargo:"); //aqui só pede para o computador escrever uma vírgula depois do arquivo
     fclose(file); //fecha o arquivos
     
     printf("Digite o cargo a ser cadastrado: "); 
     scanf("%s",cargo); //refere-se a armazenar na variavél o que foi digitado pelo usuário
     
     file = fopen(arquivo, "a"); //abre o arquivo para atualizar "a"
     fprintf(file, cargo); //salva o valor da variavél
     fclose(file); // fecha o arquivo
     
     file = fopen(arquivo, "a"); //pede para abrir o arquivo para atualizar 
     fprintf(file, "."); //pede para escrever um ponto
     fclose(file); // fecha o arquivo
 
     
	 system("pause"); // pausa esse programa de registro e volta para o "menu"
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //possibilita escrever acentos nas palavras
	
	char cpf[40]; //variavél criada para armazenar characteres 
	char conteudo[200]; //conteúdo foi criado aqui para criar um "banco de dados", possibilitando assim uma consulta 
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf); //armazena o que foi digitado pelo usuário na variavél
	
	FILE *file;
	file = fopen(cpf,"r"); // "r" = ler o arquivo que o usuário consultar 
	
	
	if(file == NULL) // se o cpf que o usuário está preocurando não existir, escreva o que está a baixo
	{
	printf("Não foi possivél abrir o arquivo, não localizado.\n");
    }
	
	while(fgets(conteudo, 200, file) != NULL) //esquanto o computador preocura as informações e não for nulo, escreva o que está a baixo
	{
		printf("\nEssas são as informações do usuário: CPF:",cpf);
		printf("%s", conteudo); //o %s aqui no caso, é para mostrar o que está armazenado no conteúdo, ou seja, no banco de dados
		printf("\n\n");
	}
	
	   system("pause"); //pausa o arquivo
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf); // armazena o que foi escrito pelo usuário na variavél 
	
	remove(cpf); //remover o CPF diretamente no banco de dados, que foi solicitado pelo usuário
	
	FILE *file; //sinaliza para chamar o "FILE" para o computadoor que é um arquivo, e cria um novo arquivo com "*file"
	file = fopen(cpf, "r"); //abre o arquivo e lê 
	
	if(file == NULL) //se as informações a qual o usuário deletou forem nulas, 
	{
		printf("O usuário foi deletado do sistema!.\n");
		system("pause");
	}
	
}


int main ()
{
	int opcao=0; //definindo as variáveiss 
    int laco=1;
    
	
	for(laco=1;laco=1;)
    {
        
		system("cls"); // responsável por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
   
        printf("\n=== Cartório da EBAC ===\n"); //inicio do menu
        printf("Escolha a opção desejada do menu:\n\n");
        printf("\t1 - Registrar CPF\n");
        printf("\t2 - Consultar CPF\n");
        printf("\t3 - Deletar   CPF\n"); 
        printf("\t4 - sair do sistema\n\n");
        printf("Opção:"); //fim do menu

        scanf("%d", &opcao); //armazenamento do usuario
   
        system("cls"); //responsável por limpar a tela
        
        
        
        switch(opcao)
        {
        	case 1:
        	registro(); //chamama de funções registro
        	break;
        	
        	case 2:
        	consulta(); //chamada de funções consulta
        	break;
        	
        	case 3:
        	deletar(); //chamada de funções deletar
        	break;
        	
        	case 4:
        		printf("Obrigado por utilizar nosso sistema!\n");
        		return 0;
        		break;
        	
        	
        	
        	default:
        		printf("Essa opção não está disponível\n");
        		system("pause");
        		break;
        	
		}//fim da seleção
   
   }
}

