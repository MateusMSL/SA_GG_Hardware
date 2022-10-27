#include <iostream>
#include <string.h>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <cstdio>
#include <windows.h>
#include <chrono>
#include <thread>
#include <iomanip>

using namespace std;

enum IN {
	
    IN_BACK = 8,
    IN_RET = 13
 
};
 
// Criptografia
std::string takePasswdFromUser(
    char sp = '*')
{
    string passwd = "";
    char ch_ipt;

    while (true) {
 
        ch_ipt = getch();
 
        if (ch_ipt == IN::IN_RET) {
            cout << endl;
            return passwd;
        }
        else if (ch_ipt == IN::IN_BACK
                 && passwd.length() != 0) {
            passwd.pop_back();
 
            cout << "\b \b";
 
            continue;
        }
 
        else if (ch_ipt == IN::IN_BACK
                 && passwd.length() == 0) {
            continue;
        }
 
        passwd.push_back(ch_ipt);
        cout << sp;
    }
}


//------------------------------------------------------------------------------------------------------//
void produto_periferico(){
	
	system("cls"); // Limpar tela anterior e exibir parte cadastrar clientes.
	
	cout << "===================> Cadastrar Novos Produtos <================== \n\n";
	    
    fstream fin, fout; // Biblioteca ou Classe que cria obejtos ou variaveis para manipular arquivos externos.
    				  // fin = file in = arquivo de entrada, fout = file out - arquivo de saida

    fin.open("produto_periferico.csv", ios::in); // Abre e ler o arquivo se ele existir
    
    vector<string> linhas; // criado um vetor linhas do tipo string - ex. linhas[5]
    string linha, palavra, temp;
  
    int x = 0;
  
  	while(fin >> temp) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
	  
	    linhas.clear(); // Remove todos os dados do vetor. ex. linhas = 0 ou nULL
	
	    getline(fin, linha); // Busca os dados linha por linha
	
	    stringstream s(linha); // separa os dados por linha
	    
	    char virgula = ','; // Variavel recebe a virgula como separador dos dados

	    while (getline(s, palavra, virgula)) { // Cada linha tem variis dados que são sepadados por virgula e armazenado no vetor linhas.
			linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5] 
	    }
	    x = stoi(linhas[0]); // variavel x recebe o valor da posição [0] - código - como string convertido para inteiro.
	    // Esta parte tem como objetivo buscar o ultimo código, para quando precisar adcionar um novo cliente sempre com um id diferente dos existentes.
	}

    fout.open("produto_periferico.csv", ios::out | ios::app); // Cria um novo arquivo se ele não existir.
    
    int codigo;
    string nome, marca, loja, quantia, preco, teste;
    
	codigo = x; // Objetivo da variavel x citada acima.

	string tipoperiferico, backup;
	
		cout << "\t \t \t \t \t \t \t Qual tipo de periferico será cadastrado? \n";
		cout << "\t \t \t \t \t \t \t 1.  Mouse \n";
		cout << "\t \t \t \t \t \t \t 2.  Teclado \n";
		cout << "\t \t \t \t \t \t \t 3.  Headset \n";
		cout << "\t \t \t \t \t \t \t 4.  Controle \n";
		cout << "\t \t \t \t \t \t \t 5.  Webcam \n";
		cout << "\t \t \t \t \t \t \t 6.  Microfone \n";
		cout << "\t \t \t \t \t \t \t 7.  Cadeira Gamer \n";
		cout << "\t \t \t \t \t \t \t 8.  Mesa Digitalizadora \n";
		cout << "\t \t \t \t \t \t \t 9.  Oculos VR \n";
		cout << "\t \t \t \t \t \t \t 10. Cabo VGI \n";
		cout << "\t \t \t \t \t \t \t 11. Cabo DVA \n";
		cout << "\t \t \t \t \t \t \t 12. Cabo HDMI \n";
		cout << "\t \t \t \t \t \t \t 13. Cabo Ethernet (REDE) \n";
		cout << "\t \t \t \t \t \t \t 14. Roteador \n";
		cout << "\t \t \t \t \t \t \t     Escolha: ";
		
		cin >> tipoperiferico;
		if (tipoperiferico == "1"){
		backup = "Mouse";
		}else if (tipoperiferico == "2"){
		backup = "Teclado";
		}else if (tipoperiferico == "3"){
		backup = "Headset";
		}else if (tipoperiferico == "4"){
		backup = "Controle";	
		}else if (tipoperiferico == "5"){
		backup = "Webcam";
		}else if (tipoperiferico == "6"){
		backup = "Microfone";
		}else if (tipoperiferico == "7"){
		backup = "Cadeira Gamer";	
		}else if (tipoperiferico == "8"){
		backup = "Mesa Digitalizadora";
		}else if (tipoperiferico == "9"){	
		backup = "Oculos VR";
		}else if (tipoperiferico == "10"){
		backup = "Cabo VGI";
		}else if (tipoperiferico == "11"){
		backup = "Cabo DVA";
		}else if (tipoperiferico == "12"){
		backup = "Cabo HDMI";
		}else if (tipoperiferico == "13"){
		backup = "Cabo Ethernet (REDE)";
		}else if (tipoperiferico == "14"){
		backup = "Roteador";
		}else{
		produto_periferico();
		}
		
		
    	codigo++;
  		cout << "\t \t \t \t \t \t \t ===========> Adicionar Periferico " << codigo << " <============== \n\n";
  		getline(cin, teste);
  		teste = backup;
		cout << "\t \t \t \t \t \t \t Informe o nome do Produto: ";
        getline(cin, nome);
        cout << "\t \t \t \t \t \t \t Informe a marca do Produto: ";
        getline(cin, marca);
        cout << "\t \t \t \t \t \t \t Informe o preco do Produto (exemplo: 200.00)\n";
		cout << "\t \t \t \t \t \t \t R$: ";
     	getline(cin, preco);
        cout << "\t \t \t \t \t \t \t Quantos Desse Produto Você Possui em Estoque?: ";
        getline(cin, quantia);
        cout << "\t \t \t \t \t \t \t Informe a loja que vende o Produto: ";
		getline(cin, loja);
        cout << "\t \t \t \t \t \t \t =======================================================> \n\n";
        
        cout << "\t \t \t \t \t \t \t Dados Gravados com Sucesso.\n";
		
  
        fout << ", " // Gravar os dados no arquivo criado ou lido anteriormente. 
			 << codigo << ", " // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5] 
			 << teste << ", "
			 << nome << ", "
             << marca << ", "
             << preco << ", "
             << quantia << ", "
             << loja
             << "\n";
    
	
}
void produto_hardware(){
	system("cls"); // Limpar tela anterior e exibir parte cadastrar clientes.
	
	cout << "\t \t \t \t \t \t \t ===================> Cadastrar Novos Produtos <================== \n\n";
	    
    fstream fin, fout; // Biblioteca ou Classe que cria obejtos ou variaveis para manipular arquivos externos.
    				  // fin = file in = arquivo de entrada, fout = file out - arquivo de saida

    fin.open("produto_hardware.csv", ios::in); // Abre e ler o arquivo se ele existir
    
    vector<string> linhas; // criado um vetor linhas do tipo string - ex. linhas[5]
    string linha, palavra, temp;
  
    int x = 0;
  
  	while(fin >> temp) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
	  
	    linhas.clear(); // Remove todos os dados do vetor. ex. linhas = 0 ou nULL
	
	    getline(fin, linha); // Busca os dados linha por linha
	
	    stringstream s(linha); // separa os dados por linha
	    
	    char virgula = ','; // Variavel recebe a virgula como separador dos dados

	    while (getline(s, palavra, virgula)) { // Cada linha tem variis dados que são sepadados por virgula e armazenado no vetor linhas.
			linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5] 
	    }
	    x = stoi(linhas[0]); // variavel x recebe o valor da posição [0] - código - como string convertido para inteiro.
	    // Esta parte tem como objetivo buscar o ultimo código, para quando precisar adcionar um novo cliente sempre com um id diferente dos existentes.
	}

    fout.open("produto_hardware.csv", ios::out | ios::app); // Cria um novo arquivo se ele não existir.
    
    int quantia, codigo ;
    string nome, marca, loja, preco, teste;

    codigo = x; // Objetivo da variavel x citada acima.

	string tipoperiferico, backup;
	
		cout << "\t \t \t \t \t \t \t Qual tipo de Hardware será cadastrado? \n";
		cout << "\t \t \t \t \t \t \t 1.  Processador \n";
		cout << "\t \t \t \t \t \t \t 2.  Water-Cooler \n";
		cout << "\t \t \t \t \t \t \t 3.  Cooler \n";
		cout << "\t \t \t \t \t \t \t 4.  Fan \n";
		cout << "\t \t \t \t \t \t \t 5.  Memória Ram \n";
		cout << "\t \t \t \t \t \t \t 6.  HD \n";
		cout << "\t \t \t \t \t \t \t 7.  SSD \n";
		cout << "\t \t \t \t \t \t \t 8.  Fonte de Alimentação \n";
		cout << "\t \t \t \t \t \t \t 9.  Placa de Vídeo \n";
		cout << "\t \t \t \t \t \t \t 10. Placa-Mãe \n";
		cout << "\t \t \t \t \t \t \t 11. Gabinete \n \n";
		cout << "\t \t \t \t \t \t \t     Escolha: ";
		cin >> tipoperiferico;
		if ((tipoperiferico == "1") or (tipoperiferico == "Processador") or (tipoperiferico == "processador")){
		backup = "Processador";
		}else if (tipoperiferico == "2"){
		backup = "Water-Cooler";
		}else if (tipoperiferico == "3"){
		backup = "Cooler";
		}else if (tipoperiferico == "4"){
		backup = "Fan";	
		}else if (tipoperiferico == "5"){
		backup = "Memória Ram";
		}else if (tipoperiferico == "6"){
		backup = "HD";
		}else if (tipoperiferico == "7"){
		backup = "SSD";	
		}else if (tipoperiferico == "8"){
		backup = "Fonte de Alimentação";
		}else if (tipoperiferico == "9"){	
		backup = "Placa de Vídeo";
		}else if (tipoperiferico == "10"){
		backup = "Placa-Mãe";
		}else if (tipoperiferico == "11"){	
		backup = "Gabinete";
		}else{
		produto_hardware();
		}
		
		
    	codigo++;
  		cout << "\t \t \t \t \t \t \t ===========> Adicionar Hardware " << codigo << " <============== \n\n";
  		getline(cin, teste);
  		teste = backup;
		cout << "\t \t \t \t \t \t \t Informe o nome do Produto: ";
        getline(cin, nome);
        cout << "\t \t \t \t \t \t \t Informe a marca do Produto: ";
        getline(cin, marca);
        cout << "\t \t \t \t \t \t \t Informe o preco do Produto (exemplo: 200.00)\n";
		cout << "\t \t \t \t \t \t \t R$: ";
        getline(cin, preco);
        cout << "\t \t \t \t \t \t \t Quantos Desse Produto Você Possui em Estoque? \n";
     	cout << "\t \t \t \t \t \t \t Informe em Decimal: ";
		 cin >> quantia;
     	cin.sync();
        cout << "\t \t \t \t \t \t \t Informe a loja que vende o Produto: ";
		getline(cin, loja);
        cout << "\t \t \t \t \t \t \t =======================================================> \n\n";
        
        cout << "\t \t \t \t \t \t \t Dados Gravados com Sucesso.\n";
		
  
        fout << ", " // Gravar os dados no arquivo criado ou lido anteriormente. 
			 << codigo << ", " // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5] 
			 << teste << ", "
			 << nome << ", "
             << marca << ", "
             << preco << ", "
             << quantia << ", "
             << loja
             << "\n";
    
	
}
//------------------------------------------------------------------------------------------------------//

//------------------------------------------------------------------------------------------------------//
void criarfornecedores() {
	
	system("cls"); // Limpar tela anterior e exibir parte cadastrar clientes.
	
	cout << "\t \t \t \t \t \t \t ===================> Cadastrar Novos Fornecedores <================== \n\n";
	    
    fstream fin, fout; // Biblioteca ou Classe que cria obejtos ou variaveis para manipular arquivos externos.
    				  // fin = file in = arquivo de entrada, fout = file out - arquivo de saida

    fin.open("fornecedores.csv", ios::in); // Abre e ler o arquivo se ele existir
    
    vector<string> linhas; // criado um vetor linhas do tipo string - ex. linhas[5]
    string linha, palavra, temp;
  
    int x = 0;
  
  	while(fin >> temp) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
	  
	    linhas.clear(); // Remove todos os dados do vetor. ex. linhas = 0 ou nULL
	
	    getline(fin, linha); // Busca os dados linha por linha
	
	    stringstream s(linha); // separa os dados por linha
	    
	    char virgula = ','; // Variavel recebe a virgula como separador dos dados

	    while (getline(s, palavra, virgula)) { // Cada linha tem variis dados que são sepadados por virgula e armazenado no vetor linhas.
			linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5] 
	    }
	    x = stoi(linhas[0]); // variavel x recebe o valor da posição [0] - código - como string convertido para inteiro.
	    // Esta parte tem como objetivo buscar o ultimo código, para quando precisar adcionar um novo cliente sempre com um id diferente dos existentes.
	}

    fout.open("fornecedores.csv", ios::out | ios::app); // Cria um novo arquivo se ele não existir.
    
    int n;
	
	cout << "\t \t \t \t \t \t \t |----------------------------------------------------| \n";
    cout << "\t \t \t \t \t \t \t |    Voce deseja cadastrar quantos Fornecedores?     | \n \n";
    cout << "\t \t \t \t \t \t \t |     Caso não queira mais cadastrar, Digite -1      | \n";
    cout << "\t \t \t \t \t \t \t -----------------------------------------------------| \n";
    cout << "\t \t \t \t \t \t \t                      Escolha: ";
	cin >> n;
    cin.sync();
    
    if (n == -1){
    
	}else{
		
	
  
    cout << "\t \t \t \t \t \t \t  Informe os dados de " << n << " Fornecedores:" << "\n\n";
  
    int codigo;
    string nome, marca, preco, cnpj, produtos, ctt;

    codigo = x; // Objetivo da variavel x citada acima.

    for (int i = 0; i < n; i++) {
    	
    	codigo++;
  		cout << "\t \t \t \t \t \t \t ===========> Adicionar Fornecedor " << codigo << " <============== \n\n";
  		
  		cout << "\t \t \t \t \t \t \t Informe o nome do Fornecedor: ";
        getline(cin, nome);
        cout << "\t \t \t \t \t \t \t Informe a Empresa do Fornecedor: ";
        getline(cin, marca);
        cout << "\t \t \t \t \t \t \t Informe quais produtos o Fornecedor ira enviar mensalmente: ";
        getline(cin, produtos);
        cout << "\t \t \t \t \t \t \t Informe a quantidade correspondente a cada produtos mensal que o Fornecedor enviara: ";
		getline(cin, preco);
        cout << "\t \t \t \t \t \t \t Informe o CPNJ do Fornecedor: ";
		getline(cin, cnpj);
		cout << "\t \t \t \t \t \t \t Informe o e-mail do Fornecedor: ";
		getline(cin, ctt);
        cout << "\t \t \t \t \t \t \t =======================================================> \n\n";
  
        fout << ", " // Gravar os dados no arquivo criado ou lido anteriormente. 
			 << codigo << ", " // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5] 
             << nome << ", "
             << marca << ", "
             << produtos << ", "
             << preco << ", "
			 << cnpj << ", "
			 << ctt
             << "\n";
    }
	cout << "\t \t \t \t \t \t \t               Dados Gravados com Sucesso! \n";
}
}
void buscar_fornecedores() {
	
	system("cls");  // Limpar tela anterior e exibir parte buscar clientes.
	
	cout << "\t \t \t \t \t \t \t  ===================> Pesquisar Fornecedores <================== \n\n";

    fstream fin; // Biblioteca ou Classe que cria obejtos ou variaveis para manipular arquivos externos.
    			// fin = file in = arquivo de entrada, fout = file out - arquivo de saida
    
    fin.open("fornecedores.csv", ios::in); // Abre e ler o arquivo se ele existir

    int linhan1, linhan2, cont = 0; // se cont manter-se 0 nenhum dado ou arquivo foi encontrado.
    cout << "\t \t \t \t \t \t \t |----------------------------------------------------------------| \n";
    cout << "\t \t \t \t \t \t \t |    Digite o codigo do Fornecedor para visualizar seus dados.   | \n";
    cout << "\t \t \t \t \t \t \t |       Caso não queira mais buscar fornecedores, Digite -1      | \n";
    cout << "\t \t \t \t \t \t \t |----------------------------------------------------------------| \n";
    cout << "\t \t \t \t \t \t \t                      Escolha: ";
    cin >> linhan1;
    
    if (linhan1 == -1){
    
	}else{
		

  
    vector<string> linhas; // criado um vetor linhas do tipo string - ex. linhas[5]
    string linha, palavra, temp;
  
    while (fin >> temp) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
  
        linhas.clear(); // Remove todos os dados do vetor. ex. linhas = 0 ou nULL

        getline(fin, linha); // Busca os dados linha por linha
  
        stringstream s(linha); // separa os dados por linha
        
        char virgula = ','; // Variavel recebe a virgula como separador dos dados
  
        while (getline(s, palavra, virgula)) { // Cada linha tem variis dados que são sepadados por virgula e armazenado no vetor linhas.
			linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5]
        }
        
        linhan2 = stoi(linhas[0]); // variavel linhan2 recebe o valor da posição [0] - código - como string convertido para inteiro.
  
        if (linhan2 == linhan1) { // Se a variavel linhan2 for igual a variavel linhan1 informada pelo usuario, mostre o cliente correspondente a ela.
  
            cont = 1; // caso seja verdadeira a condição
            cout << "\t \t \t \t \t \t \t ==============> Produto " << linhas[0] << " <================ \n\n";
            cout << "\t \t \t \t \t \t \t Codigo: " << linhas[0] << "\n";
            cout << "\t \t \t \t \t \t \t Nome:" << linhas[1] << "\n";
            cout << "\t \t \t \t \t \t \t Empresa: " << linhas[2] << "\n";
            cout << "\t \t \t \t \t \t \t Produto: " << linhas[3] << "\n";
            cout << "\t \t \t \t \t \t \t Quantidade: " << linhas[4] << "\n";
            cout << "\t \t \t \t \t \t \t CPNJ: " << linhas[5] << "\n";
            cout << "\t \t \t \t \t \t \t E-mail: " << linhas[6] << "\n";
            cout << "\t \t \t \t \t \t \t ======================================================== \n\n";
            cout << "\n\n\n";
           // cout << "Pressione ENTER para voltar a aba de produtos...\n";
            break;
        }
    }
    if (cont == 0) { // condição explicado acima.
        cout << "\t \t \t \t \t \t \t Dados nao encontrados... \n";
        buscar_fornecedores(); // retorna ao inicio da busca.
	}
	int op; // Opções de pesquisar novamente ou sair desta ação de busca.
	
	cout << "\t \t \t \t \t \t \t |----------------------------------------------------------------| \n";
    cout << "\t \t \t \t \t \t \t |           Deseja buscar outro Fornecedor? Digite 1.            | \n";
    cout << "\t \t \t \t \t \t \t |       Caso não queira mais buscar fornecedores, Digite 0       | \n";
    cout << "\t \t \t \t \t \t \t |----------------------------------------------------------------| \n";
    cout << "\t \t \t \t \t \t \t                           Escolha: ";
	cin >> op;	
    
    switch(op) {
    	case 1:
			buscar_fornecedores();
			break;
		case 0:
			system("exit");
			break;
		default:
			cout << "\t \t \t \t \t \t \t           Opçao Invalida!";
			buscar_fornecedores();
			break;
	} 
} 
}
void listar_fornecedores() {
	
	system("cls"); // Limpar tela anterior e exibir parte de listar todos os clientes.
	
	fstream fin; // Biblioteca ou Classe que cria obejtos ou variaveis para manipular arquivos externos.
    			// fin = file in = arquivo de entrada, fout = file out - arquivo de saida
    
    fin.open("fornecedores.csv", ios::in); // Abre e ler o arquivo se ele existir

    vector<string> linhas; // criado um vetor linhas do tipo string - ex. linhas[5]
    string linha, palavra, temp;
    
    cout << "\t \t \t \t \t \t \ ==============> Lista de Fornecedores Cadastrados <================ \n\n";
  
    while (fin >> temp) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
  
        linhas.clear(); // Remove todos os dados do vetor. ex. linhas = 0 ou nULL

        getline(fin, linha); // Busca os dados linha por linha
  
        stringstream s(linha); // separa os dados por linha
        
        char virgula = ','; // Variavel recebe a virgula como separador dos dados
  
        while (getline(s, palavra, virgula)) { // Cada linha tem varios dados que são sepadados por virgula e armazenado no vetor linhas.
			linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5]
        }

		cout << "\t \t \t \t \t \t \t ==============> Fornecedor " << linhas[0] << " <================ \n\n";
		
            cout << "\t \t \t \t \t \t \t Nome: " << linhas[1] << "\n";
            cout << "\t \t \t \t \t \t \t Empresa : " << linhas[2] << "\n";
            cout << "\t \t \t \t \t \t \t Produto: " << linhas[3] << "\n";
            cout << "\t \t \t \t \t \t \t Quantidade: " << linhas[4] << "\n";
            cout << "\t \t \t \t \t \t \t CPNJ: " << linhas[5] << "\n";
            cout << "\t \t \t \t \t \t \t E-mail: " << linhas[6] << "\n";
            
        cout << "\t \t \t \t \t \t \t ======================================================== \n\n";


    }
	
} 
void atualizarfornecedores() {
	
	system("cls"); // Limpar tela anterior e exibir parte de atualizar1 dados dos clientes.
	listar_fornecedores();
	cout << "\t \t \t \t \t \t \ ===================> Atualizar dados dos Fornecedores <================== \n\n";
	
    fstream fin, fout; // Biblioteca ou Classe que cria obejtos ou variaveis para manipular arquivos externos.
    				  // fin = file in = arquivo de entrada, fout = file out - arquivo de saida

    fin.open("fornecedores.csv", ios::in); // Abre e ler o arquivo se ele existir

    fout.open("attfornecedores.csv", ios::out); // Cria um novo arquivo se ele não existir, neste caso temporariamente até que seja atualizado, backup.
  
    int linhan1, linhan2, indice, sub, cont = 0; // se cont manter-se 0 nenhum dado ou arquivo foi encontrado.
    string linha, palavra, novo, temp;
    vector<string> linhas; // criado um vetor linhas do tipo string - ex. linhas[5]

	cout << "\t \t \t \t \t \t \    =-------------------------------------------------------------= \n";
    cout << "\t \t \t \t \t \t \    | Digite o codigo do Fornecedor que deseja atualizar os dados | \n";
    cout << "\t \t \t \t \t \t \    |    Caso não queira atualizar fornecedores, Digite -1        | \n";
    cout << "\t \t \t \t \t \t \    =-------------------------------------------------------------= \n\n";
    cout << "\t \t \t \t \t \t \                             Escolha: ";
    cin >> linhan1;
    cin.sync();
    
    if (linhan1 == -1){
  	
	}else{

    cout << "\t \t \t \t \t \t \ ==========> Alterar dados do Fornecedor " << linhan1 << " <=========== \n\n";
    cout << "\t \t \t \t \t \t \ Para alterar o nome, Digite 1. \n\n";
    cout << "\t \t \t \t \t \t \ Para alterar o empresa, Digite 2. \n\n";
    cout << "\t \t \t \t \t \t \ Para alterar o(s) produto(s), Digite 3. \n\n";
    cout << "\t \t \t \t \t \t \ Para alterar a(as) quantidade(s), Digite 4. \n\n";
	cout << "\t \t \t \t \t \t \ Para alterar o CNPJ, Digite 5. \n\n";
	cout << "\t \t \t \t \t \t \ Para alterar o E-mail, Digite 6. \n\n\n";
	cout << "\t \t \t \t \t \t \            Escolha: ";
    cin >> sub;
  	cin.sync();
  	
  	system("cls");
  	listar_fornecedores();
  	switch(sub) { // As alterações dependem da escolha do usuário, a variavel indice vai indicar qual valor será alterado.
  		case 1:
  		    cout << "\t \t \t \t \t \t \ ==============> Alterar nome do Fornecedor <================ \n\n";
  			indice = 1;
  			break;
  		case 2:
  			cout << "\t \t \t \t \t \t \ ==============> Alterar Empresa do Fornecedor <================ \n\n";
  			indice = 2;
  			break;
  		case 3:
  			cout << "\t \t \t \t \t \t \ ==============> Alterar Produto do Fornecedor <================ \n\n";
  			indice = 3;
  			break;
  		case 4:
  			cout << "\t \t \t \t \t \t \ ==============> Alterar quantidade mensal de Produtos do Fornecedor <================ \n\n";
  			indice = 4;
  			break;
  		case 5:
  			cout << "\t \t \t \t \t \t \ ==============> Alterar CPNJ do Fornecedor <================ \n\n";
  			indice = 5;
  			break;
  		case 6:
  			cout << "\t \t \t \t \t \t \ ==============> Alterar E-mail do Fornecedor <================ \n\n";
  			indice = 6;
  			break;			    			
  		default:
	        cout << "\t \t \t \t \t \t \                      Opçao Invalida!! \n";
	        atualizarfornecedores();
			break;  			
	  }

    cout << "\t \t \t \t \t \t \t Informe o novo dado: "; // Variavel que armazena as novas informações do cliente
    getline(cin, novo);

    while (fin >> temp) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
  
        linhas.clear(); // Remove todos os dados do vetor. ex. linhas = 0 ou nULL
  
        getline(fin, linha); // Busca os dados linha por linha
        stringstream s(linha); // separa os dados por linha
        
        char virgula = ','; // Variavel recebe a virgula como separador dos dados
  
        while (getline(s, palavra, virgula)) { // Cada linha tem varios dados que são sepadados por virgula e armazenado no vetor linhas.
            linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5]
        }
  
        linhan2 = stoi(linhas[0]); // variavel linhan2 recebe o valor da posição [0] - código - como string convertido para inteiro.
        
        int row_size = linhas.size(); // A variavel row_size armazena quantas linhas de dados contém no arquivo.
  
        if (linhan2 == linhan1) { // Se a variavel linhan2 for igual a variavel linhan1 informada pelo usuario, atualize o cliente correspondente a ela.
            cont = 1; // caso seja verdadeira a condição
            stringstream convert; // A variavel convert é um objeto ou classe que passa o valor informado pelo o usuario para string.

            convert << novo; // Valor informado pelo usuario sendo convertido.

            linhas[indice] = convert.str(); // O valor é copiado para o indice informado e substituindo o valor anterior.
  
            if (!fin.eof()) { // Escreve o dado atualizado no arquivo temporario criado anteriomente attProdutos.
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {

                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        else {
            if (!fin.eof()) { // Escreve os dados existentes no arquivo temporario criado anteriomente attProdutos.
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
  
                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        if (fin.eof()) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
            break;
		}
    }
    if (cont == 1) { // Caso condição verdadeira
        cout << "\t \t \t \t \t \t \ Dados atualizados com Sucesso!! \n";
	} else if (cont == 0) { // Caso condição falsa
    	cout << "\t \t \t \t \t \t \ Dados nao encontrados!! Nao foi Possivel atualizar dados! \n\n";
    	atualizarfornecedores(); // Retorna ao inicio da função 
	}

    fin.close(); // fecha a leitura do arquivo.
    fout.close(); // fecha a escrita no arquivo.

    remove("fornecedores.csv"); // Remove o arquivo
    rename("attfornecedores.csv", "fornecedores.csv"); // Renomeia o aquivo temporario para o nome do arquivo principal com os dados atualizados.
}
}
void excluirfornecedores() {
	
	system("cls"); // Limpar tela anterior e exibir parte de excluir dados dos parceiros.
	listar_fornecedores();
	cout << "\t \t \t \t \t \t      ===================> Encerrar contrato <================== \n\n";

    fstream fin, fout; // Biblioteca ou Classe que cria obejtos ou variaveis para manipular arquivos externos.
    				  // fin = file in = arquivo de entrada, fout = file out - arquivo de saida

    fin.open("fornecedores.csv", ios::in); // Abre e ler o arquivo se ele existir

    fout.open("attfornecedores.csv", ios::out); // Cria um novo arquivo se ele não existir, neste caso temporariamente até que seja atualizado, backup.
  
    int linhan1, linhan2, cont = 0; // se cont manter-se 0 nenhum dado ou arquivo foi encontrado.
    string linha, palavra, temp;
    vector<string> linhas; // criado um vetor linhas do tipo string - ex. linhas[5]
	
	cout << "\t \t \t \t \t \t  |-----------------------------------------------------------------| \n";
    cout << "\t \t \t \t \t \t  |    Digite o codigo do fornecedor que deseja excluir os dados.   | \n";
    cout << "\t \t \t \t \t \t  |       Caso não queira mais excluir fornecedores, Digite -1      | \n";
    cout << "\t \t \t \t \t \t  |-----------------------------------------------------------------| \n";
    cout << "\t \t \t \t \t \t                       Escolha: ";
    cin >> linhan1;
    
    if (linhan1 == -1){
    
	}else{
	

    while (fin >> temp) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
  
        linhas.clear(); // Remove todos os dados do vetor. ex. linhas = 0 ou nULL
        getline(fin, linha); // Busca os dados linha por linha
        stringstream s(linha);  // separa os dados por linha
  
  		char virgula = ','; // Variavel recebe a virgula como separador dos dados
  		
        while (getline(s, palavra, virgula)) { // Cada linha tem varios dados que são sepadados por virgula e armazenado no vetor linhas.
            linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5]
        }
  
        int row_size = linhas.size(); // A variavel row_size armazena quantas linhas de dados contém no arquivo.
        linhan2 = stoi(linhas[0]); // variavel linhan2 recebe o valor da posição [0] - código - como string convertido para inteiro.

        if (linhan2 != linhan1) { // Se a variavel linhan2 for igual a variavel linhan1 informada pelo usuario, exclui o cliente correspondente a ela
        	
            if (!fin.eof()) { // Escreve os dados existentes, exceto o dado deletado, no arquivo temporario criado anteriomente attparceiros.
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof()) // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
            break;
    }
    if (cont == 1) {
        cout << "\t \t \t \t \t \t \t Dados deletados com sucesso!! \n";
    } else {
        cout << "\t \t \t \t \t \t \t Dados nao encontrados!! Nao foi Possivel excluir dados! \n\n";
	}
		
    fin.close(); // fecha a leitura do arquivo.
    fout.close(); // fecha a escrita no arquivo.

    remove("fornecedores.csv"); // Remove o arquivo
    rename("attfornecedores.csv", "fornecedores.csv"); // Renomeia o aquivo temporario para o nome do arquivo principal com os dados atualizados.
    
    int opex; // Opções de excluir novamente ou sair desta ação de deletar dados.
	
	cout << "\t \t \t \t \t \t \t |--------------------------------------------------------------| \n";
    cout << "\t \t \t \t \t \t \t |            Deseja excluir outro cliente? Digite 1.           | \n";
    cout << "\t \t \t \t \t \t \t |                    Deseja sair? Digite 0.                    | \n";
    cout << "\t \t \t \t \t \t \t |--------------------------------------------------------------| \n";
    cout << "\t \t \t \t \t \t \t                          Escolha: ";
	
	cin >> opex;	
    
    switch(opex) {
    	case 1:
			excluirfornecedores();
			break;
		case 0:
			system("exit");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
	
}
}
//------------------------------------------------------------------------------------------------------//
void criarclientes(){

	
	system("cls"); // Limpar tela anterior e exibir parte cadastrar clientes.
	
	cout << "\t \t \t \t \t \t \t ===================> Cadastrar Novos Clientes <================== \n\n";
	    
    fstream fin, fout; // Biblioteca ou Classe que cria obejtos ou variaveis para manipular arquivos externos.
    				  // fin = file in = arquivo de entrada, fout = file out - arquivo de saida

    fin.open("clientes.csv", ios::in); // Abre e ler o arquivo se ele existir
    
    vector<string> linhas; // criado um vetor linhas do tipo string - ex. linhas[5]
    string linha, palavra, temp;
  
    int x = 0;
  
  	while(fin >> temp) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
	  
	    linhas.clear(); // Remove todos os dados do vetor. ex. linhas = 0 ou nULL
	
	    getline(fin, linha); // Busca os dados linha por linha
	
	    stringstream s(linha); // separa os dados por linha
	    
	    char virgula = ','; // Variavel recebe a virgula como separador dos dados

	    while (getline(s, palavra, virgula)) { // Cada linha tem variis dados que são sepadados por virgula e armazenado no vetor linhas.
			linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5] 
	    }
	    x = stoi(linhas[0]); // variavel x recebe o valor da posição [0] - código - como string convertido para inteiro.
	    // Esta parte tem como objetivo buscar o ultimo código, para quando precisar adcionar um novo cliente sempre com um id diferente dos existentes.
	}

    fout.open("clientes.csv", ios::out | ios::app); // Cria um novo arquivo se ele não existir.
    
    int n;
	    
	cout << "\t \t \t \t \t \t \t |--------------------------------------------------------| \n";
    cout << "\t \t \t \t \t \t \t |        Voce deseja cadastrar quantos clientes?         | \n \n";
    cout << "\t \t \t \t \t \t \t |       Caso não queira mais cadastrar, Digite -1        | \n";
    cout << "\t \t \t \t \t \t \t |--------------------------------------------------------| \n";
    cout << "\t \t \t \t \t \t \t                      Escolha: "; 
	    
    
	cin >> n;
    cin.sync();
    
    
    if (n == -1){
    	
	}else{
	
  
    cout << "\t \t \t \t \t \t \t   Informe os dados do " << n << " Cliente:" << "\n\n";
  
    int codigo;
    string nome, email, contato, CPF, DN, compras;
    

    codigo = x; 

    for (int i = 0; i < n; i++) {
    	
    	codigo++;
  		cout << "\t \t \t \t \t \t \t ===========> Adicionar Cliente " << codigo << " <============== \n\n";
  		cout << "\t \t \t \t \t \t \t Informe o nome completo do cliente: ";
        getline(cin, nome);
        cout << "\t \t \t \t \t \t \t Informe o email do cliente: ";
        getline(cin, email);
        cout << "\t \t \t \t \t \t \t Informe um meio de contato do cliente: ";
        getline(cin, contato);
        cout << "\t \t \t \t \t \t \t Informe o CPF do cliente: ";
        getline(cin, CPF);
        cout << "\t \t \t \t \t \t \t Informe a Data de Nascimento do Cliente (XX/YY/ZZZZ): ";
        getline(cin, DN);
        cout << "\t \t \t \t \t \t \t Quais compras o cliente ja realizou?\n ";
        cout << "\t \t \t \t \t \t \t (Caso o cliente seja novo e nao tenha comprado nada, pressione ENTER) \n";
        getline(cin, compras);
        
        cout << "\t \t \t \t \t \t \t =======================================================> \n\n";
  
        fout << ", " 
			 << codigo << ", " 
             << nome << ", "
             << email << ", "
             << contato << ", "
             << CPF << ", "
             << DN << ", "
             << compras
             << "\n";
    }
	cout << "\t \t \t \t \t \t \tDados Gravados com Sucesso! \n";
}
}
void buscar_clientes() {

	system("cls");  
	
	cout << "\t \t \t \t \t \t \t ===================> Pesquisar Clientes <================== \n\n";

    fstream fin; 
    			
    
    fin.open("clientes.csv", ios::in); 

    int linhan1, linhan2, cont = 0; 
    cout << "\t \t \t \t \t \t \t =--------------------------------------------------------= \n";
    cout << "\t \t \t \t \t \t \t | Digite o codigo do cliente para visualizar seus dados. | \n";
    cout << "\t \t \t \t \t \t \t |       Caso não queira mais Buscar, Digite -1           | \n";
    cout << "\t \t \t \t \t \t \t =--------------------------------------------------------= \n";

    cout << "\t \t \t \t \t \t \t                        Escolha: ";
    cin >> linhan1;
    
    if (linhan1 == -1){
    	
	}else{
		
  
    vector<string> linhas; 
    string linha, palavra, temp;
  
    while (fin >> temp) { 
  
        linhas.clear(); 

        getline(fin, linha); 
  
        stringstream s(linha); 
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra);
        }
        
        linhan2 = stoi(linhas[0]); 
  
        if (linhan2 == linhan1) { 
  
            cont = 1; 
            cout << "\t \t \t \t \t \t \t ==============> cliente " << linhas[0] << " <================ \n\n";
            cout << "\t \t \t \t \t \t \t Codigo: " << linhas[0] << "\n";
            cout << "\t \t \t \t \t \t \t Nome " << linhas[1] << "\n";
            cout << "\t \t \t \t \t \t \t Email: " << linhas[2] << "\n";
            cout << "\t \t \t \t \t \t \t Meio de Contato: " << linhas[3] << "\n";
            cout << "\t \t \t \t \t \t \t CPF: " << linhas[4] << "\n";
            cout << "\t \t \t \t \t \t \t Aniversário: " << linhas[5] << "\n";
            cout << "\t \t \t \t \t \t \t Historico: " << linhas[6] << "\n";
            cout << "\t \t \t \t \t \t \t ======================================================== \n\n";
            cout << "\n\n\n";
           
            break;
        }
    }
    if (cont == 0) { 
        cout << "\t \t \t \t \t \t \t Dados nao encontrados... \n";
        buscar_clientes();
	}
	int op; 
	cout << "\t \t \t \t \t \t \t =------------------------------------------------=\n";
    cout << "\t \t \t \t \t \t \t |                                                |\n";
    cout << "\t \t \t \t \t \t \t |  Voce deseja Buscar outro Cliente?, Digite 1   |\n";
    cout << "\t \t \t \t \t \t \t |                                                |\n";
    cout << "\t \t \t \t \t \t \t |     Caso queira cancelar a venda, Digite 0     |\n";
    cout << "\t \t \t \t \t \t \t |                                                |\n";
    cout << "\t \t \t \t \t \t \t =------------------------------------------------=\n\n";
    cout << "\t \t \t \t \t \t \t                   Escolha: ";
	cin >> op;	
    
    if (op == 1){
    buscar_clientes();
	}else if (op == 0){
	system("exit");
	}else{
	cout << "\t \t \t \t \t \t \t          Opçao Invalida!";
	buscar_clientes();	
	}

}	
} 
void listar_clientes() {
	
	system("cls"); 
	
	fstream fin; 
    fin.open("clientes.csv", ios::in); 
    vector<string> linhas; 
    string linha, palavra, temp;
    
    cout << "\t \t \t \t \t \t \t ==============> Lista de Clientes Cadastrados <================ \n\n";
  
    while (fin >> temp) { 
  
        linhas.clear(); 

        getline(fin, linha);
  
        stringstream s(linha); 
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra); 
        }

		cout << "\t \t \t \t \t \t \t ==============> Clientes " << linhas[0] << " <================ \n\n";
		
            cout << "\t \t \t \t \t \t \t Nome: " << linhas[1] << "\n";
            cout << "\t \t \t \t \t \t \t E-mail : " << linhas[2] << "\n";
            cout << "\t \t \t \t \t \t \t Contato: " << linhas[3] << "\n";
            cout << "\t \t \t \t \t \t \t CPF: " << linhas[4] << "\n";
            cout << "\t \t \t \t \t \t \t Data de Nascimento: " << linhas[5] << "\n";
            cout << "\t \t \t \t \t \t \t Compras: " << linhas[6] << "\n";
            
        cout << "\t \t \t \t \t \t \t ======================================================== \n\n";

    }
	
} 
void atualizarclientes() {
	
	system("cls"); 
	listar_clientes();
	cout << "\t \t \t \t \t \t \t ===================> Atualizar dados dos clientes <================== \n\n";
	
    fstream fin, fout; 

    fin.open("clientes.csv", ios::in); 

    fout.open("attclientes.csv", ios::out); 
  
    int linhan1, linhan2, indice, sub, cont = 0; 
    string linha, palavra, novo, temp;
    vector<string> linhas; 

    cout << "\t \t \t \t \t \t \t =-----------------------------------------------------------= \n";
    cout << "\t \t \t \t \t \t \t | Digite o codigo do Cliente que deseja atualizar os dados. | \n";
    cout << "\t \t \t \t \t \t \t |     Caso Não queira mais atualizar dados, Digite -1       | \n";
    cout << "\t \t \t \t \t \t \t =-----------------------------------------------------------= \n";

    cout << "\t \t \t \t \t \t \t                       Escolha: ";
    cin >> linhan1;
    cin.sync();
    
    if (linhan1 == -1){
  	
	}else{

    cout << "\t \t \t \t \t \t \t ==========> Alterar dados do Cliente " << linhan1 << " <=========== \n\n";
    cout << "\t \t \t \t \t \t \t             Para alterar o nome, Digite 1. \n\n";
    cout << "\t \t \t \t \t \t \t             Para alterar o email, Digite 2. \n\n";
    cout << "\t \t \t \t \t \t \t             Para alterar o meio de contato, Digite 3. \n\n";
    cout << "\t \t \t \t \t \t \t             Para alterar o CPF, Digite 4. \n\n";
    cout << "\t \t \t \t \t \t \t             Para alterar a Data de Nascimento, Digite 5. \n\n";
    cout << "\t \t \t \t \t \t \t             Para alterar o Historico de Compras, Digite 6. \n\n";
    cin >> sub;
  	cin.sync();
  	
  	system("cls");
  	listar_clientes();
  	
  	switch(sub) { 
  		case 1:
  		    cout << "\t \t \t \t \t \t \t ==============> Alterar Nome do Cliente <================ \n\n";
  			indice = 1;
  			break;
  		case 2:
  			cout << "\t \t \t \t \t \t \t ==============> Alterar Email do Cliente <================ \n\n";
  			indice = 2;
  			break;
  		case 3:
  			cout << "\t \t \t \t \t \t \t ==============> Alterar Meio de Contato do CLiente <================ \n\n";
  			indice = 3;
  			break;
  		case 4:
  			cout << "\t \t \t \t \t \t \t ==============> Alterar CPF do Cliente <================ \n\n";
  			indice = 4;
  			break;
  		case 5:
  			cout << "\t \t \t \t \t \t \t ==============> Alterar Data de Nascimento do Cliente <================ \n\n";
  			indice = 5;
  			break;
  		case 6:
  			cout << "\t \t \t \t \t \t \t ==============> Alterar Historico de Compras do Cliente <================ \n\n";
  			indice = 6;
  			break;	
  		default:
	        cout << "\t \t \t \t \t \t \t                         Opçao Invalida!! \n";
	        atualizarclientes();
			break;  			
	  }

    cout << "\t \t \t \t \t \t \t Informe o novo dado: "; 
    getline(cin, novo);

    while (fin >> temp) { 
  
        linhas.clear(); 
  
        getline(fin, linha); 
        stringstream s(linha); 
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
            linhas.push_back(palavra); 
        }
  
        linhan2 = stoi(linhas[0]); 
        
        int row_size = linhas.size(); 
  
        if (linhan2 == linhan1) { 
            cont = 1; 
            stringstream convert; 

            convert << novo; 

            linhas[indice] = convert.str(); 
  
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {

                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        else {
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
  
                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        if (fin.eof()) { 
            break;
		}
    }
    if (cont == 1) { 
        cout << "\t \t \t \t \t \t \t Dados atualizados com Sucesso!! \n";
	} else if (cont == 0) { 
    	cout << "\t \t \t \t \t \t \t Dados nao encontrados!! Nao foi Possivel atualizar dados! \n\n";
    	atualizarclientes(); 
	}

    fin.close(); 
    fout.close(); 

    remove("clientes.csv"); 
    rename("attclientes.csv", "clientes.csv"); 
}
}
void excluirclientes() {
	
	system("cls"); 
	listar_clientes();
	cout << "\t \t \t \t \t \t \t ===================> Excluir dados de Clientes <================== \n\n";

    fstream fin, fout; 

    fin.open("clientes.csv", ios::in); 

    fout.open("attclientes.csv", ios::out); 
    int linhan1, linhan2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas; 
    
    cout << "\t \t \t \t \t \t \t =--------------------------------------------------------= \n";
	cout << "\t \t \t \t \t \t \t | Digite o codigo do Cliente que deseja excluir os dados | \n";
	cout << "\t \t \t \t \t \t \t | Caso Não queira mais excluir um cliente, digite -1     | \n";
	cout << "\t \t \t \t \t \t \t =--------------------------------------------------------= \n\n";

	cout << "\t \t \t \t \t \t \t                    Escolha: ";
    cin >> linhan1;
    
    if (linhan1 == -1){
    
	}else{
	

    while (fin >> temp) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
  
        linhas.clear(); // Remove todos os dados do vetor. ex. linhas = 0 ou nULL
        getline(fin, linha); // Busca os dados linha por linha
        stringstream s(linha);  // separa os dados por linha
  
  		char virgula = ','; // Variavel recebe a virgula como separador dos dados
  		
        while (getline(s, palavra, virgula)) { // Cada linha tem varios dados que são sepadados por virgula e armazenado no vetor linhas.
            linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5]
        }
  
        int row_size = linhas.size(); // A variavel row_size armazena quantas linhas de dados contém no arquivo.
        linhan2 = stoi(linhas[0]); // variavel linhan2 recebe o valor da posição [0] - código - como string convertido para inteiro.

        if (linhan2 != linhan1) { // Se a variavel linhan2 for igual a variavel linhan1 informada pelo usuario, exclui o cliente correspondente a ela
        	
            if (!fin.eof()) { // Escreve os dados existentes, exceto o dado deletado, no arquivo temporario criado anteriomente attparceiros.
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof()) // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
            break;
    }
    if (cont == 1) {
        cout << "\t \t \t \t \t \t \t Dados deletados com sucesso!! \n";
    } else {
        cout << "\t \t \t \t \t \t \t Dados nao encontrados!! Nao foi Possivel excluir dados! \n\n";
	}
		
    fin.close(); // fecha a leitura do arquivo.
    fout.close(); // fecha a escrita no arquivo. 

    remove("clientes.csv"); 
    rename("attclientes.csv", "clientes.csv"); 
    
    int opex; 
    cout << "\t \t \t \t \t \t \t =-----------------------------------------= \n";
	cout << "\t \t \t \t \t \t \t | Deseja excluir outro cliente? Digite 1. | \n";
	cout << "\t \t \t \t \t \t \t |         Deseja sair? Digite 0.          | \n";
	cout << "\t \t \t \t \t \t \t =-----------------------------------------= \n";

	cout << "\t \t \t \t \t \t \t                  Escolha: ";
	cin >> opex;	
    
    switch(opex) {
    	case 1:
			excluirclientes();
			break;
		case 0:
			system("exit");
			break;
		default:
			cout << "\t \t \t \t \t \t \t Opçao Invalida!";
			break;
	} 
}
}
//------------------------------------------------------------------------------------------------------//
void buscar_hardware() {

	system("cls");  
	
	cout << "\t \t \t \t \t \t \t ===================> Pesquisar Hardware <================== \n\n";

    fstream fin; 
    			
    
    fin.open("produto_hardware.csv", ios::in); 

    int linhan1, linhan2, cont = 0;
	cout << "\t \t \t \t \t \t \t =----------------------------------------------------------= \n"; 
    cout << "\t \t \t \t \t \t \t |  Digite o codigo do Hardware para visualizar seus dados. | \n";
    cout << "\t \t \t \t \t \t \t |        Caso não queira mais Buscar, Digite -1            | \n";
    cout << "\t \t \t \t \t \t \t =----------------------------------------------------------= \n \n"; 

    cout << "\t \t \t \t \t \t \t                      Escolha:  ";
    cin >> linhan1;
    
    if (linhan1 == -1){
    	
	}else{
		
  
    vector<string> linhas; 
    string linha, palavra, temp;
  
    while (fin >> temp) { 
  
        linhas.clear(); 

        getline(fin, linha); 
  
        stringstream s(linha); 
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra);
        }
        
        linhan2 = stoi(linhas[0]); 
  
        if (linhan2 == linhan1) { 
  
            cont = 1; 
            cout << "\t \t \t \t \t \t \t ==============> Produto Hardware " << linhas[0] << " <================ \n\n";
            cout << "\t \t \t \t \t \t \t Tipo de Periférico: " << linhas[1] << "\n";
			cout << "\t \t \t \t \t \t \t Codigo: " << linhas[0] << "\n";
            cout << "\t \t \t \t \t \t \t Nome " << linhas[2] << "\n";
            cout << "\t \t \t \t \t \t \t Marca: " << linhas[3] << "\n";
            cout << "\t \t \t \t \t \t \t Preco: " << linhas[4] << "\n";
            cout << "\t \t \t \t \t \t \t Quantia: " << linhas[5] << "\n";
			cout << "\t \t \t \t \t \t \t Loja: " << linhas[6] << "\n";
            cout << "\t \t \t \t \t \t \t ======================================================== \n\n";
            cout << "\n\n\n";
           
            break;
        }
    }
    if (cont == 0) { 
        cout << "\t \t \t \t \t \t \t Dados nao encontrados... \n";
        buscar_hardware();
	}
	int op; 
	cout << "\t \t \t \t \t \t \t =----------------------------------------= \n";
	cout << "\t \t \t \t \t \t \t | Deseja buscar outro hardware? Digite 1.| \n";
	cout << "\t \t \t \t \t \t \t |        Deseja sair? Digite 0.          | \n";
	cout << "\t \t \t \t \t \t \t =----------------------------------------= \n\n";
	cout << "\t \t \t \t \t \t \t                Escolha: ";
	cin >> op;	
    
    if (op == 1){
    buscar_hardware();
	}else if (op == 0){
	system("exit");
	}else{
	cout << "\t \t \t \t \t \t \t          Opçao Invalida!";
	buscar_hardware();	
	}

}	
}
void buscar_periferico() {

	system("cls");  
	
	cout << "\t \t \t \t \t \t \t ===================> Pesquisar Periferico <================== \n\n";

    fstream fin; 
    			
    
    fin.open("produto_periferico.csv", ios::in); 

    int linhan1, linhan2, cont = 0; 
    cout << "\t \t \t \t \t \t \t =------------------------------------------------------------= \n"; 
    cout << "\t \t \t \t \t \t \t |  Digite o codigo do Periferico para visualizar seus dados. | \n";
    cout << "\t \t \t \t \t \t \t |        Caso não queira mais Buscar, Digite -1              | \n";
    cout << "\t \t \t \t \t \t \t =------------------------------------------------------------= \n \n"; 

    cout << "\t \t \t \t \t \t \t                      Escolha:  ";
    
    cin >> linhan1;
    
    if (linhan1 == -1){
    	
	}else{
		
  
    vector<string> linhas; 
    string linha, palavra, temp;
  
    while (fin >> temp) { 
  
        linhas.clear(); 

        getline(fin, linha); 
  
        stringstream s(linha); 
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra);
        }
        
        linhan2 = stoi(linhas[0]); 
  
        if (linhan2 == linhan1) { 
  
            cont = 1; 
            cout << "\t \t \t \t \t \t \t ==============> Produto Periférico " << linhas[0] << " <================ \n\n";
            cout << "\t \t \t \t \t \t \t Tipo de Periférico: " << linhas[1] << "\n";
			cout << "\t \t \t \t \t \t \t Codigo: " << linhas[0] << "\n";
            cout << "\t \t \t \t \t \t \t Nome " << linhas[2] << "\n";
            cout << "\t \t \t \t \t \t \t Marca: " << linhas[3] << "\n";
            cout << "\t \t \t \t \t \t \t Preco: " << linhas[4] << "\n";
            cout << "\t \t \t \t \t \t \t Quantia: " << linhas[5] << "\n";
			cout << "\t \t \t \t \t \t \t Loja: " << linhas[6] << "\n";
            cout << "\t \t \t \t \t \t \t ======================================================== \n\n";
            cout << "\n\n\n";
           
            break;
        }
    }
    if (cont == 0) { 
        cout << "\t \t \t \t \t \t \t Dados nao encontrados... \n";
        buscar_periferico();
	}
	int op; 
	cout << "\t \t \t \t \t \t \t =------------------------------------------= \n";
	cout << "\t \t \t \t \t \t \t | Deseja buscar outro periferico? Digite 1.| \n";
	cout << "\t \t \t \t \t \t \t |         Deseja sair? Digite 0.           | \n";
	cout << "\t \t \t \t \t \t \t =------------------------------------------= \n\n";
	cout << "\t \t \t \t \t \t \t                  Escolha: ";
	cin >> op;	
    
    if (op == 1){
    buscar_periferico();
	}else if (op == 0){
	system("exit");
	}else{
	cout << "\t \t \t \t \t \t \t          Opçao Invalida!";
	buscar_periferico();	
	}

}	
} 
void buscar_produtos() {
	string escolha;
	cout << "\t \t \t \t \t \t \t =-------------------------------------=\n";
	cout << "\t \t \t \t \t \t \t |                                     |\n";
	cout << "\t \t \t \t \t \t \t |       Selecione uma Opção:          |\n";
	cout << "\t \t \t \t \t \t \t |                                     |\n";
	cout << "\t \t \t \t \t \t \t =-------------------------------------=\n";
	cout << "\t \t \t \t \t \t \t | 1. Buscar Produtos em Perifericos   |\n";
	cout << "\t \t \t \t \t \t \t | 2. Buscar Produtos em Hardwares     |\n";
	cout << "\t \t \t \t \t \t \t | 3. Retornar ao menu de Produtos     |\n";
	cout << "\t \t \t \t \t \t \t =-------------------------------------=\n";
	cout << "\t \t \t \t \t \t \t                Escolha: ";
	cin >> escolha;
	if (escolha == "1"){
	system("cls");
	buscar_periferico();
	system("cls");
	system("exit");
	buscar_produtos();
	}else if (escolha == "2"){
	system("cls");
	buscar_hardware();
	system("cls");
	system("exit");
	buscar_produtos();
	}else if (escolha == "3"){
	system("cls");
	}else{
	system("cls");
	cout << "\t \t \t \t \t \t \t --- A opção Escolhida infelizmente não é valida, tente novamente ou retorne ao menu de produtos --- \n";
	buscar_produtos();
	}
	
	}
//------------------------------------------------------------------------------------------------------//
void listar_hardware() {
	
    system("cls");
	fstream fin; 
    
    fin.open("produto_hardware.csv", ios::in);

    vector<string> linhas; 
    string linha, palavra, temp;
    
	cout << "\n \n \n";
  
    while (fin >> temp) { 
  
        linhas.clear(); 

        getline(fin, linha); 
  
        stringstream s(linha); 
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra); 
        }

			cout << " \t \t \t \t \t \t \t |===================> Hardware " << linhas[0] << " <===================| \n\n";
		
            cout << " \t \t \t \t \t \t \t   Tipo de Hardware: " << linhas[1] << "\n";
			cout << " \t \t \t \t \t \t \t   Nome: " << linhas[2] << "\n";
            cout << " \t \t \t \t \t \t \t   Marca : " << linhas[3] << "\n";
            cout << " \t \t \t \t \t \t \t   Preço: " << linhas[4] << "\n";
            cout << " \t \t \t \t \t \t \t   Quantidade em Estoque: " << linhas[5] << "\n";
            cout << " \t \t \t \t \t \t \t   Lojas: " << linhas[6] << "\n";
            
        	cout << " \t \t \t \t \t \t \t |=======================================================| \n\n";

    }
	cout << "\t \t  \t \t \t \t \t         ";
	system("pause");
}  
void listarestoquehardware(){

    system("cls"); 
	fstream fin; 
    
    fin.open("produto_hardware.csv", ios::in); 

    vector<string> linhas;
    string linha, palavra, temp;
    
    		cout << "\t \t \t \t \t \t \t   ==============> Lista de Produtos <================ \n\n";
  
    while (fin >> temp) { 
  
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha);
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra); 
        }

			cout << "\t \t \t \t \t \t \t ---------------------> Hardware " << linhas[0] << " <------------------- \n\n";
		
            cout << "\t \t \t \t \t \t \t Tipo de Hardware :" << linhas[1] << "\n";
			cout << "\t \t \t \t \t \t \t Nome: " << linhas[2] << "\n";
            cout << "\t \t \t \t \t \t \t Quantidade em Estoque: " << linhas[5] << "\n";
            
        	cout << "\t \t \t \t \t \t \t ======================================================== \n\n";

    }

}
void listarestoqueperiferico(){

    system("cls");
	
	fstream fin; 
    fin.open("produto_periferico.csv", ios::in); 
    vector<string> linhas; 
    string linha, palavra, temp;
    
    		cout << "\t \t \t \t \t \t \t           ==============> Lista de Produtos <================ \n\n";
  
    while (fin >> temp) { 
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha); 
        char virgula = ','; 
        while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra); 
        }

			cout << "\t \t \t \t \t \t \t --------------------> Periferico " << linhas[0] << " <------------------ \n\n";
		
            cout << "\t \t \t \t \t \t \t Tipo de Hardware :" << linhas[1] << "\n";
			cout << "\t \t \t \t \t \t \t Nome: " << linhas[2] << "\n";
            cout << "\t \t \t \t \t \t \t Quantidade em Estoque: " << linhas[5] << "\n";
            
        	cout << "\t \t \t \t \t \t \t =======================================================| \n\n";

    }
	
}
void listar_periferico() {

	
    system("cls");
	fstream fin; 
    fin.open("produto_periferico.csv", ios::in); 
	
    vector<string> linhas;
    string linha, palavra, temp;
    
    cout << "\n \n \n";
    
    while (fin >> temp) { 
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha); 
        char virgula = ','; 
        while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra); 
        }
		
			cout << " \t \t \t \t \t \t \t|===================> Periferico " << linhas[0] << " <===================| \n\n";
		
            cout << " \t \t \t \t \t \t \t  Tipo de Periférico: " << linhas[1] << "\n";
			cout << " \t \t \t \t \t \t \t  Nome: " << linhas[2] << "\n";
            cout << " \t \t \t \t \t \t \t  Marca : " << linhas[3] << "\n";
            cout << " \t \t \t \t \t \t \t  Preço: " << linhas[4] << "\n";
            cout << " \t \t \t \t \t \t \t  Quantidade em Estoque: " << linhas[5] << "\n";
            cout << " \t \t \t \t \t \t \t  Lojas: " << linhas[6] << "\n";
            
        	cout << " \t \t \t \t \t \t \t|=======================================================| \n\n";

    }
	cout << "\t \t  \t \t \t \t \t         ";
	system("pause");
}  
void listar_produtos() {
	string escolha;
	cout << "\t \t \t \t \t \t \t =-------------------------------------=\n";
	cout << "\t \t \t \t \t \t \t |                                     |\n";
	cout << "\t \t \t \t \t \t \t |       Selecione uma Opção:          |\n";
	cout << "\t \t \t \t \t \t \t |                                     |\n";
	cout << "\t \t \t \t \t \t \t =-------------------------------------=\n";
	cout << "\t \t \t \t \t \t \t |1. Listar todos os Perifericos       |\n";
	cout << "\t \t \t \t \t \t \t |2. Listar todos os Hardwares         |\n";
	cout << "\t \t \t \t \t \t \t |3. Retornar ao menu de Produtos      |\n";
	cout << "\t \t \t \t \t \t \t =-------------------------------------=\n";

	cout << "\t \t \t \t \t \t \t               Escolha: ";
	cin >> escolha;
	if (escolha == "1"){
	system("cls");
	listar_periferico();
	system("cls");
	system("exit");
	listar_produtos();
	}else if (escolha == "2"){
	system("cls");
	listar_hardware();
	system("cls");
	system("exit");
	listar_produtos();
	}else if (escolha == "3"){
	system("cls");
	}else{
	system("cls");
	cout << "\t \t \t \t \t \t \t --- A opção Escolhida infelizmente não é valida, tente novamente ou retorne ao menu de produtos --- \n";
	listar_produtos();
	}
	
	}
//------------------------------------------------------------------------------------------------------//
void atualizarperiferico() {
	
	system("cls");
	listar_periferico();
	cout << "\t \t \t \t \t \t \t ===================> Atualizar dados dos Perifericos <================== \n\n";
	
    fstream fin, fout; 
    fin.open("produto_periferico.csv", ios::in); 
    fout.open("attproduto_periferico.csv", ios::out); 
    int linhan1, linhan2, indice, cont = 0; 
    string linha, palavra, sub, novo, temp;
    vector<string> linhas;

    cout << "\t \t \t \t \t \t \t =--------------------------------------------------------------------------=\n";
    cout << "\t \t \t \t \t \t \t |                                                                          |\n";
    cout << "\t \t \t \t \t \t \t |      Digite o codigo do produto que deseja atualizar os dados            |\n";
    cout << "\t \t \t \t \t \t \t |      Caso não queira mais atualizar um produto, Digite -1                |\n";
    cout << "\t \t \t \t \t \t \t |                                                                          |\n";
    cout << "\t \t \t \t \t \t \t =--------------------------------------------------------------------------=\n";

    cout << "\t \t \t \t \t \t \t                                 Escolha: ";
    cin >> linhan1;
    cin.sync();
    
    if (linhan1 == -1){
    system("cls");
    system("exit");
	}else{
	
	

    cout << "\t \t \t \t \t \t \t ==========> Alterar dados do Periferico " << linhan1 << " <=========== \n\n";
    cout << "\t \t \t \t \t \t \t Para alterar o nome, Digite 1. \n";
    cout << "\t \t \t \t \t \t \t Para alterar o marca, Digite 2. \n";
    cout << "\t \t \t \t \t \t \t Para alterar o preco, Digite 3. \n";
    cout << "\t \t \t \t \t \t \t para alterar a quantia, Digite 4. \n";
    cout << "\t \t \t \t \t \t \t Para alterar a loja, Digite 5. \n";
    cout << " ";
    cin >> sub;
  	cin.sync();
  	
  	system("cls");
  	listar_periferico();
  	
  	if (sub == "1"){
          cout << "\t \t \t \t \t \t \t ==============> Alterar Nome do Produto <================ \n\n";
              indice = 2;
                   }else if (sub == "2"){
                       cout << "\t \t \t \t \t \t \t ==============> Alterar Marca do Produto <================ \n\n";
                          indice = 3;
                   }else if (sub == "3"){
                       cout << "\t \t \t \t \t \t \t ==============> Alterar Preco do Produto <================ \n\n";
                          indice = 4;
                   }else if (sub == "4"){
                       cout << "\t \t \t \t \t \t \t ==============> Alterar Quantia do Produto <================ \n\n";
                          indice = 5;
                   }else if (sub == "5"){
                       cout << "\t \t \t \t \t \t \t ==============> Alterar Loja do Produto <================ \n\n";
                          indice = 6;
                   }else if (sub == "6"){
                       system("exit");
                       atualizarperiferico();
                   }else{
                    cout << "\t \t \t \t \t \t \t                      Opçao Invalida!! \n";
                    indice = 10;
                   }

    cout << "\t \t \t \t \t \t \t Informe o novo dado: "; 
    getline(cin, novo);

    while (fin >> temp) { 
  
        linhas.clear(); 
  
        getline(fin, linha); 
        stringstream s(linha); 
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
            linhas.push_back(palavra); 
        }
  
        linhan2 = stoi(linhas[0]); 
        
        int row_size = linhas.size(); 
  
        if (linhan2 == linhan1) { 
            cont = 1; 
            stringstream convert; 

            convert << novo;

            linhas[indice] = convert.str(); 
  
            if (!fin.eof()) {
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {

                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        else {
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
  
                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        if (fin.eof()) { 
            break;
		}
    }
    if (cont == 1) { 
        cout << "\t \t \t \t \t \t \t Dados atualizados com Sucesso!! \n";
	} else if (cont == 0) { 
    	cout << "\t \t \t \t \t \t \t Dados nao encontrados!! Nao foi Possivel atualizar dados! \n\n";
    	atualizarperiferico();
	}

    fin.close(); 
    fout.close(); 

    remove("produto_periferico.csv"); 
    rename("attproduto_periferico.csv", "produto_periferico.csv");
} 
}
void atualizarhardware() {
	
	system("cls"); 
	listar_hardware();
	cout << "\t \t \t \t \t \t \t ===================> Atualizar dados dos Hardwares <================== \n\n";
	
    fstream fin, fout; 
    fin.open("produto_hardware.csv", ios::in); 

    fout.open("attproduto_hardware.csv", ios::out); 
  
    int linhan1, linhan2, indice, cont = 0; 
    string linha, palavra, sub, novo, temp;
    vector<string> linhas; 

    cout << "\t \t \t \t \t \t \t =--------------------------------------------------------------------------=\n";
    cout << "\t \t \t \t \t \t \t |                                                                          |\n";
    cout << "\t \t \t \t \t \t \t |      Digite o codigo do produto que deseja atualizar os dados            |\n";
    cout << "\t \t \t \t \t \t \t |      Caso não queira mais atualizar um produto, Digite -1                |\n";
    cout << "\t \t \t \t \t \t \t |                                                                          |\n";
    cout << "\t \t \t \t \t \t \t =--------------------------------------------------------------------------=\n";

    cout << "\t \t \t \t \t \t \t                                 Escolha: ";
    cin >> linhan1;
    cin.sync();
    
    if (linhan1 == -1){
  
	}else{
	
	

    cout << "\t \t \t \t \t \t \t ==========> Alterar dados do Hardware " << linhan1 << " <=========== \n\n";
    cout << "\t \t \t \t \t \t \t Para alterar o nome, Digite 1. \n";
    cout << "\t \t \t \t \t \t \t Para alterar o marca, Digite 2. \n";
    cout << "\t \t \t \t \t \t \t Para alterar o preco, Digite 3. \n";
    cout << "\t \t \t \t \t \t \t para alterar a quantia, Digite 4. \n";
    cout << "\t \t \t \t \t \t \t Para alterar a loja, Digite 5. \n";
    cout << " ";
    cin >> sub;
  	cin.sync();
  	
  	system("cls"); 
	listar_hardware();
	
  	if (sub == "1"){
          cout << "\t \t \t \t \t \t \t ==============> Alterar Nome do Produto <================ \n\n";
              indice = 2;
                   }else if (sub == "2"){
                       cout << "\t \t \t \t \t \t \t ==============> Alterar Marca do Produto <================ \n\n";
                          indice = 3;
                   }else if (sub == "3"){
                       cout << "\t \t \t \t \t \t \t ==============> Alterar Preco do Produto <================ \n\n";
                          indice = 4;
                   }else if (sub == "4"){
                       cout << "\t \t \t \t \t \t \t ==============> Alterar Quantia do Produto <================ \n\n";
                          indice = 5;
                   }else if (sub == "5"){
                       cout << "\t \t \t \t \t \t \t ==============> Alterar Loja do Produto <================ \n\n";
                          indice = 6;
                   }else if (sub == "6"){
                       system("exit");
                       atualizarhardware();
                   }else{
                       cout << "\t \t \t \t \t \t \t                   Opçao Invalida!! \n";
                    indice = 10;
                   }

    cout << "\t \t \t \t \t \t \t Informe o novo dado: "; 
    getline(cin, novo);

    while (fin >> temp) { 
  
        linhas.clear(); 
  
        getline(fin, linha); 
        stringstream s(linha); 
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
            linhas.push_back(palavra); 
        }
  
        linhan2 = stoi(linhas[0]); 
        
        int row_size = linhas.size(); 
  
        if (linhan2 == linhan1) { 
            cont = 1; 
            stringstream convert; 

            convert << novo; 

            linhas[indice] = convert.str(); 
  
            if (!fin.eof()) {
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {

                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        else {
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
  
                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        if (fin.eof()) { 
            break;
		}
    }
    if (cont == 1) { 
        cout << "\t \t \t \t \t \t \t Dados atualizados com Sucesso!! \n";
	} else if (cont == 0) { 
    	cout << "\t \t \t \t \t \t \t Dados nao encontrados!! Nao foi Possivel atualizar dados! \n\n";
    	atualizarhardware();
	}

    fin.close(); 
    fout.close();

    remove("produto_hardware.csv"); 
    rename("attproduto_hardware.csv", "produto_hardware.csv"); 
} 
}
void atualizarprodutos() {
	string escolha;
	cout << "\t \t \t \t \t \t \t =-------------------------------------=\n";
	cout << "\t \t \t \t \t \t \t |       Selecione uma Opção:          |\n";
	cout << "\t \t \t \t \t \t \t =-------------------------------------=\n";	
	cout << "\t \t \t \t \t \t \t |                                     |\n";	 
	cout << "\t \t \t \t \t \t \t |    1. Atualizar Perifericos         |\n";
	cout << "\t \t \t \t \t \t \t |    2. Atualizar Hardwares           |\n";
	cout << "\t \t \t \t \t \t \t |    3. Retornar ao menu de Produtos  |\n";
	cout << "\t \t \t \t \t \t \t |                                     |\n";
	cout << "\t \t \t \t \t \t \t =-------------------------------------=\n";

	cout << "\t \t \t \t \t \t \t Escolha: ";
	cin >> escolha;
	if (escolha == "1"){
	system("cls");
	atualizarperiferico();
	system("cls");
	system("exit");
	atualizarprodutos();
	}else if (escolha == "2"){
	system("cls");
	atualizarhardware();
	system("cls");
	system("exit");
	atualizarprodutos();
	}else if (escolha == "3"){
	system("cls");
	}else{
	system("cls");
	cout << "\t \t \t \t \t \t \t --- A opção Escolhida infelizmente não é valida, tente novamente ou retorne ao menu de produtos --- \n";
	listar_produtos();
	}
	
	}	
//------------------------------------------------------------------------------------------------------//
void excluirprodutoshardware() {
	
	system("cls"); 
	listar_hardware();
	cout << "\t \t \t \t \t \t \ ===================> Excluir dados de Produtos <================== \n\n";

    fstream fin, fout; 
    				  

    fin.open("produto_hardware.csv", ios::in); 

    fout.open("attproduto_hardware.csv", ios::out); 
  
    int linhan1, linhan2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas; 
	
	cout << "\t \t \t \t \t \t   =-----------------------------------------------------------------= \n";
    cout << "\t \t \t \t \t \t   |     Digite o codigo do Hardware que deseja excluir os dados     | \n";
    cout << "\t \t \t \t \t \t   |       Caso não queira mais excluir hardwares, Digite -1         | \n";
    cout << "\t \t \t \t \t \t   =-----------------------------------------------------------------= \n";
    cout << "\t \t \t \t \t \t                               Escolha: ";
    cin >> linhan1;
    
    if (linhan1 == -1){
    
	}else{
	

    while (fin >> temp) { 
  
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha); 
  
  		char virgula = ','; 
  		
        while (getline(s, palavra, virgula)) { 
            linhas.push_back(palavra); 
        }
  
        int row_size = linhas.size(); 
        linhan2 = stoi(linhas[0]); 

        if (linhan2 != linhan1) { 
        	
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof()) 
            break;
    }
    if (cont == 1) {
        cout << "\t \t \t \t \t \t \t Dados deletados com sucesso!! \n";
    } else {
        cout << "\t \t \t \t \t \t \t Dados nao encontrados!! Nao foi Possivel excluir dados! \n\n";
	}
		
    fin.close(); 
    fout.close(); 

    remove("produto_hardware.csv"); 
    rename("attproduto_hardware.csv", "produto_periferico.csv"); 
    
    int opex; 
	
	cout << "\t \t \t \t \t \t \t |--------------------------------------------------------------| \n";
    cout << "\t \t \t \t \t \t \t |            Deseja excluir outro produto? Digite 1.           | \n \n";
    cout << "\t \t \t \t \t \t \t |                    Deseja sair? Digite 0.                    | \n";
    cout << "\t \t \t \t \t \t \t |--------------------------------------------------------------| \n";
    cout << "\t \t \t \t \t \t \t                          Escolha: ";
	
	cin >> opex;	
    
    switch(opex) {
    	case 1:
			excluirprodutoshardware();
			break;
		case 0:
			system("exit");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
	
}
}
void excluirprodutosperiferico() {
	
	system("cls"); 
	listar_periferico();
	cout << "\t \t \t \t \t \t \ ===================> Excluir dados de Produtos <================== \n\n";

    fstream fin, fout; 
    				  

    fin.open("produto_periferico.csv", ios::in); 

    fout.open("attproduto_periferico.csv", ios::out); 
  
    int linhan1, linhan2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas; 
	
	cout << "\t \t \t \t \t \t   =-------------------------------------------------------------------= \n";
    cout << "\t \t \t \t \t \t   |     Digite o codigo do Periferico que deseja excluir os dados     | \n";
    cout << "\t \t \t \t \t \t   |       Caso não queira mais excluir perifericos, Digite -1         | \n";
    cout << "\t \t \t \t \t \t   =-------------------------------------------------------------------= \n";
    cout << "\t \t \t \t \t \t                               Escolha: ";
    cin >> linhan1;
    
    if (linhan1 == -1){
    
	}else{
	

    while (fin >> temp) { 
  
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha);  
  
  		char virgula = ','; 
  		
        while (getline(s, palavra, virgula)) { 
            linhas.push_back(palavra); 
        }
  
        int row_size = linhas.size(); 
        linhan2 = stoi(linhas[0]); 

        if (linhan2 != linhan1) { 
        	
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof()) 
            break;
    }
    if (cont == 1) {
        cout << "\t \t \t \t \t \t \t Dados deletados com sucesso!! \n";
    } else {
        cout << "\t \t \t \t \t \t \t Dados nao encontrados!! Nao foi Possivel excluir dados! \n\n";
	}
		
    fin.close(); 
    fout.close(); 

    remove("produto_periferico.csv"); 
    rename("attproduto_periferico.csv", "produto_periferico.csv"); 
    
    int opex; 
	
	cout << "\t \t \t \t \t \t \t |--------------------------------------------------------------| \n";
    cout << "\t \t \t \t \t \t \t |            Deseja excluir outro produto? Digite 1.           | \n \n";
    cout << "\t \t \t \t \t \t \t |                    Deseja sair? Digite 0.                    | \n";
    cout << "\t \t \t \t \t \t \t |--------------------------------------------------------------| \n";
    cout << "\t \t \t \t \t \t \t                          Escolha: ";
	
	cin >> opex;	
    
    switch(opex) {
    	case 1:
			excluirprodutosperiferico();
			break;
		case 0:
			system("exit");
			break;
		default:
			cout << "Opçao Invalida!";
			break;
	} 
	
}
}
void excluirprodutos() {
	string escolha;
	cout << "\t \t \t \t \t \t \t =----------------------------------=\n";
	cout << "\t \t \t \t \t \t \t |  Deseja Verificar Qual Estoque?  |\n";
	cout << "\t \t \t \t \t \t \t =----------------------------------=\n";
	cout << "\t \t \t \t \t \t \t |                                  |\n";
	cout << "\t \t \t \t \t \t \t |  1. Apagar produtos Perifericos  |\n";
	cout << "\t \t \t \t \t \t \t |  2. Apagar produtos Hardwares    |\n";
	cout << "\t \t \t \t \t \t \t |  3. Retornar ao Menu Principal   |\n";
	cout << "\t \t \t \t \t \t \t |                                  |\n";
	cout << "\t \t \t \t \t \t \t =----------------------------------=\n";
	
	cout << "\t \t \t \t \t \t \t            Escolha: ";
	cin >> escolha;
	if (escolha == "1"){
	system("cls");
	excluirprodutosperiferico();
	system("cls");
	system("exit");
	excluirprodutos();
	}else if (escolha == "2"){
	system("cls");
	excluirprodutoshardware();
	system("cls");
	system("exit");
	excluirprodutos();
	}else if (escolha == "3"){
	system("cls");
	}else{
	system("cls");
	cout << "\t \t \t \t \t \t \t --- A opção Escolhida infelizmente não é valida, tente novamente ou retorne ao menu de produtos --- \n";
	excluirprodutos();
	}
	
	}
void criarprodutos() {
	
	system("cls"); 
	
	cout << "\t \t \t \t \t \t \t ===================> Cadastrar Novos Produtos <================== \n\n";
	    
    string produtoescolha;
    int n;
	    
	cout << "\t \t \t \t \t \t \t |----------------------------------------------------------------| \n";
    cout << "\t \t \t \t \t \t \t |            Voce deseja cadastrar quantos produtos?             | \n \n";
    cout << "\t \t \t \t \t \t \t |              Caso nao queira cadastrar, Digite -1              | \n";
    cout << "\t \t \t \t \t \t \t |----------------------------------------------------------------| \n";
    cout << "\t \t \t \t \t \t \t                      Escolha: ";

	cin >> n;
    cin.sync();
    
    if (n == -1){
    
	}else{

    for (int i = 0; i < n; i++) {
    	
    cout << "\t \t \t \t \t \t \t |----------------------------------------------------------------| \n";
    cout << "\t \t \t \t \t \t \t |             Qual Tipo de produto deseja adicionar?             | \n \n";
    cout << "\t \t \t \t \t \t \t |                      1. Hardware                               | \n";
    cout << "\t \t \t \t \t \t \t |                      2. Periferico                             | \n";
    cout << "\t \t \t \t \t \t \t |----------------------------------------------------------------| \n";
    cout << "\t \t \t \t \t \t \t                          Escolha: ";
    

    	cin >> produtoescolha;
    	
    	if (produtoescolha == "1"){
    	produto_hardware();	
		}else if (produtoescolha == "2"){
		produto_periferico();
		}else{
		criarprodutos();
		}
}
}


}
//------------------------------------------------------------------------------------------------------//
void estoque_periferico(){
system("cls");
listarestoqueperiferico();
cout << "\t \t \t \t \t \t \t ";
system("pause");
system("cls");	
}
void estoque_hardware(){
system("cls");
listarestoquehardware();
cout << "\t \t \t \t \t \t \t ";
system("pause");
system("cls");

}
void estoque(){
	
	string escolha;
	cout << "\t \t \t \t \t \t \t =----------------------------------=\n";
	cout << "\t \t \t \t \t \t \t |  Deseja Verificar Qual Estoque?  |\n";
	cout << "\t \t \t \t \t \t \t =----------------------------------=\n";
	cout << "\t \t \t \t \t \t \t |                                  |\n";
	cout << "\t \t \t \t \t \t \t |  1. Estoque de Perifericos       |\n";
	cout << "\t \t \t \t \t \t \t |  2. Estoque de Hardwares         |\n";
	cout << "\t \t \t \t \t \t \t |  3. Retornar ao Menu Principal   |\n";
	cout << "\t \t \t \t \t \t \t |                                  |\n";
	cout << "\t \t \t \t \t \t \t =----------------------------------=\n";
	
	cout << "\t \t \t \t \t \t \t            Escolha: ";
	cin >> escolha;
	cin.sync();
	if (escolha == "1"){
	system("cls");
	estoque_periferico();
	estoque();
	}else if (escolha == "2"){
	system("cls");
	estoque_hardware();
	estoque();
	}else if (escolha == "3"){
	system("cls");
	system("exit");
	}else{
	system("cls");
	cout << "\t \t \t \t \t \t \t OPÇÃO INVÁLIDA, DIGITE SOMENTE UMA DAS OPÇÕES FORNECIDAS\n";
	estoque();
	}
}
//------------------------------------------------------------------------------------------------------//
void historicoperiferico() {
	
	system("cls");
	
	cout << "\t \t \t \t \t \t \t ===================> Registrar compra do Cliente (Periferico) <================== \n\n";
	    
    fstream fin, fout; 
    fin.open("historicoperiferico.csv", ios::in); 
    
    vector<string> linhas; 
    string linha, palavra, temp;
  
    int x = 0;
  
  	while(fin >> temp) { 
	  
	    linhas.clear(); 
	
	    getline(fin, linha); 
	
	    stringstream s(linha); 
	    
	    char virgula = ','; 

	    while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra);  
	    }
	    x = stoi(linhas[0]); 
	}

    fout.open("historicoperiferico.csv", ios::out | ios::app);
    
  
    int codigo;
    string nome, marca, preco, cnpj, produtos, ctt;

    codigo = x; 


    	
    	codigo++;
  		cout << "\t \t \t \t \t \t \t ===========> Adicionar Novos Clientes <============== \n\n";
  		cout << "\t \t \t \t \t \t \t Informe o nome do Cliente: ";
        getline(cin, nome);
        cout << "\t \t \t \t \t \t \t Informe o CPF do cliente: ";
		getline(cin, cnpj);
		cout << "\t \t \t \t \t \t \t Informe a data em que foi realizada a compra: ";
		getline(cin, ctt);
		
        cout << "\t \t \t \t \t \t \t =======================================================> \n\n";
  
        fout << ", " 
			 << codigo << ", " 
             << nome << ", "
			 << cnpj << ", "
			 << ctt
             << "\n";
    
             cout << "\t \t \t \t \t \t \t A Venda foi Realizada com Sucesso :D \n";
             cout << "\t \t \t \t \t \t \t ";
			 system("pause");
}
void historicohardware() {
	
	system("cls"); 
	
	cout << "\t \t \t \t \t \t \t ===================> Registrar compra do Cliente (Hardware) <================== \n\n";
	    
    fstream fin, fout; 
    fin.open("historicohardware.csv", ios::in); 
    vector<string> linhas;
    string linha, palavra, temp;
  
    int x = 0;
  
  	while(fin >> temp) { 
	  
	    linhas.clear(); 
	
	    getline(fin, linha);
	    stringstream s(linha); 
	    char virgula = ','; 
	    while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra); 
	    }
	    x = stoi(linhas[0]); 
	    
	}

    fout.open("historicohardware.csv", ios::out | ios::app); 
    
	
  
    cout << "\t \t \t \t \t \t \t Informe os dados do Novo Cliente:" << "\n\n";
  
    int codigo;
    string nome, marca, preco, cnpj, produtos, ctt;

    codigo = x; 

    	
    codigo++;
  		cout << "\t \t \t \t \t \t \t ===========> Adicionar Novos Clientes <============== \n\n";
  		cout << "\t \t \t \t \t \t \t Informe o nome do Cliente: ";
        getline(cin, nome);
        cout << "\t \t \t \t \t \t \t Informe o CPF do cliente: ";
		getline(cin, cnpj);
		cout << "\t \t \t \t \t \t \t Informe a data em que foi realizada a compra: ";
		getline(cin, ctt);
		
        cout << "\t \t \t \t \t \t \t =======================================================> \n\n";
  
        fout << ", " 
			 << codigo << ", " 
             << nome << ", "
			 << cnpj << ", "
			 << ctt
             << "\n";
             cout << "\t \t \t \t \t \t \t A Venda foi Realizada com Sucesso :D \n";
             cout << "\t \t \t \t \t \t \t ";
			 system("pause");
    }
//------------------------------------------------------------------------------------------------------//
void atualizarvendaperiferico2() {
	
	cout << "\t \t \t \t \t \t \t ===================> Venda de Perifericos <================== \n\n";
	
    fstream fin, fout; 
    fin.open("produto_periferico.csv", ios::in); 
    fout.open("attproduto_periferico.csv", ios::out); 
    int linhan1, linhan2, indice, cont = 0; 
    string linha, palavra, sub, novo, temp;
    vector<string> linhas; 

	cout << "\t \t \t \t \t \t \t =---------------------------------------------------=\n";
    cout << "\t \t \t \t \t \t \t |                                                   |\n";
    cout << "\t \t \t \t \t \t \t |  Digite o codigo do periférico que será vendido   |\n";
    cout << "\t \t \t \t \t \t \t |                                                   |\n";
    cout << "\t \t \t \t \t \t \t |       Caso queira cancelar a venda, Digite -1     |\n";
    cout << "\t \t \t \t \t \t \t |                                                   |\n";
    cout << "\t \t \t \t \t \t \t =---------------------------------------------------=\n";
	cout << "\t \t \t \t \t \t \t                         Escolha: ";
	
    cin >> linhan1;
    cin.sync();
    
    if (linhan1 == -1){
  
	}else{
	
	indice = 5;
	string quantia;
	int num1, num2, num3, num4;
	
	
	
    cout << "\t \t \t \t \t \t \t Informe quantos desse produto foram vendidos: "; 
    getline(cin, novo);
	
	
	num2 = stoi(novo);

	
    while (fin >> temp) { 
  
        linhas.clear(); 
  
        getline(fin, linha); 
        stringstream s(linha); 
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
            linhas.push_back(palavra); 
        }
  
        linhan2 = stoi(linhas[0]); 
        
        int row_size = linhas.size(); 
  
        if (linhan2 == linhan1) { 
            cont = 1; 
            stringstream convert; 
            
            
            
            num3 = stoi(linhas[5]); 
			num1 = num3 - num2;
			
			
            convert << num1;
            linhas[indice] = convert.str(); 
  
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {

                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        else {
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
  
                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        if (fin.eof()) { 
            break;
		}
    }
    if (cont == 1) { 
        cout << "\t \t \t \t \t \t \t Dados atualizados com Sucesso!! \n";
	} else if (cont == 0) { 
    	cout << "\t \t \t \t \t \t \t Dados nao encontrados!! Nao foi Possivel atualizar dados! \n\n";
    	atualizarhardware(); 
	}

    fin.close(); 
    fout.close(); 

    remove("produto_periferico.csv"); 
    rename("attproduto_periferico.csv", "produto_periferico.csv"); 
historicoperiferico();
}

}
void atualizarvendahardware2() {
	cout << "\t \t \t \t \t \t \t ===================> Venda de Hardwares <================== \n\n";
	
    fstream fin, fout; 
    				  

    fin.open("produto_hardware.csv", ios::in); 

    fout.open("attproduto_hardware.csv", ios::out); 
    int linhan1, linhan2, indice, cont = 0; 
    string linha, palavra, sub, novo, temp;
    vector<string> linhas; 

    cout << "\t \t \t \t \t \t \t =---------------------------------------------------=\n";
    cout << "\t \t \t \t \t \t \t |                                                   |\n";
    cout << "\t \t \t \t \t \t \t |    Digite o codigo do hardware que será vendido   |\n";
    cout << "\t \t \t \t \t \t \t |                                                   |\n";
    cout << "\t \t \t \t \t \t \t |       Caso queira cancelar a venda, Digite -1     |\n";
    cout << "\t \t \t \t \t \t \t |                                                   |\n";
    cout << "\t \t \t \t \t \t \t =---------------------------------------------------=\n";
	cout << "\t \t \t \t \t \t \t                         Escolha: ";
    cin >> linhan1;
    cin.sync();
    
    if (linhan1 == -1){
  	system("exit");
	}else{
	
	indice = 5;
	string quantia;
	int num1, num2, num3, num4;
	
	
	
    cout << "\t \t \t \t \t \t \t Informe quantos desse produto foram vendidos: "; 
    getline(cin, novo);
	
	
	num2 = stoi(novo);
	

	
    while (fin >> temp) { 
  
        linhas.clear(); 
  
        getline(fin, linha); 
        stringstream s(linha); 
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
            linhas.push_back(palavra); 
        }
  
        linhan2 = stoi(linhas[0]);
        
        int row_size = linhas.size(); 
  
        if (linhan2 == linhan1) { 
            cont = 1; 
            stringstream convert; 


			num3 = stoi(linhas[5]);
			num1 = num3 - num2;
			
			
            convert << num1;
            
            linhas[indice] = convert.str(); 
  
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {

                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        else {
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
  
                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        if (fin.eof()) { 
            break;
		}
    }
    if (cont == 1) { 
		cout << "\t \t \t \t \t \t \t Dados atualizados com Sucesso!! \n"; 
	} else if (cont == 0) { 
    	cout << "\t \t \t \t \t \t \t Dados nao encontrados!! Nao foi Possivel atualizar dados! \n\n";
    	atualizarhardware(); 
	}

    fin.close(); 
    fout.close(); 

    remove("produto_hardware.csv"); 
    rename("attproduto_hardware.csv", "produto_hardware.csv"); 
historicohardware();
}
}
void atualizarvendaperiferico() {
	
	cout << "\t \t \t \t \t \t \t ===================> Venda de Perifericos <================== \n\n";
	
    fstream fin, fout; 
    fin.open("produto_periferico.csv", ios::in); 
    fout.open("attproduto_periferico.csv", ios::out); 
    int linhan1, linhan2, indice, cont = 0; 
    string linha, palavra, sub, novo, temp;
    vector<string> linhas; 

	cout << "\t \t \t \t \t \t \t =---------------------------------------------------=\n";
    cout << "\t \t \t \t \t \t \t |                                                   |\n";
    cout << "\t \t \t \t \t \t \t |  Digite o codigo do periférico que será vendido   |\n";
    cout << "\t \t \t \t \t \t \t |                                                   |\n";
    cout << "\t \t \t \t \t \t \t |       Caso queira cancelar a venda, Digite -1     |\n";
    cout << "\t \t \t \t \t \t \t |                                                   |\n";
    cout << "\t \t \t \t \t \t \t =---------------------------------------------------=\n";
	cout << "\t \t \t \t \t \t \t                         Escolha: ";
	
    cin >> linhan1;
    cin.sync();
    
    if (linhan1 == -1){
  
	}else{
	
	indice = 5;
	string quantia;
	int num1, num2, num3, num4;
	
	
	
    cout << "\t \t \t \t \t \t \t Informe quantos desse produto foram vendidos: "; 
    getline(cin, novo);
	
	
	num2 = stoi(novo);

	
    while (fin >> temp) { 
  
        linhas.clear(); 
  
        getline(fin, linha); 
        stringstream s(linha); 
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
            linhas.push_back(palavra); 
        }
  
        linhan2 = stoi(linhas[0]); 
        
        int row_size = linhas.size(); 
  
        if (linhan2 == linhan1) { 
            cont = 1; 
            stringstream convert; 
            
            
            
            num3 = stoi(linhas[5]); 
			num1 = num3 - num2;
			
			
            convert << num1;
            linhas[indice] = convert.str(); 
  
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {

                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        else {
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
  
                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        if (fin.eof()) { 
            break;
		}
    }
    if (cont == 1) { 
        cout << "\t \t \t \t \t \t \t Dados atualizados com Sucesso!! \n";
	} else if (cont == 0) { 
    	cout << "\t \t \t \t \t \t \t Dados nao encontrados!! Nao foi Possivel atualizar dados! \n\n";
    	atualizarhardware(); 
	}

    fin.close(); 
    fout.close(); 

    remove("produto_periferico.csv"); 
    rename("attproduto_periferico.csv", "produto_periferico.csv"); 
}
 	
}
void atualizarvendahardware() {
	cout << "\t \t \t \t \t \t \t ===================> Venda de Hardwares <================== \n\n";
	
    fstream fin, fout; 
    				  

    fin.open("produto_hardware.csv", ios::in); 

    fout.open("attproduto_hardware.csv", ios::out); 
    int linhan1, linhan2, indice, cont = 0; 
    string linha, palavra, sub, novo, temp;
    vector<string> linhas; 

    cout << "\t \t \t \t \t \t \t =---------------------------------------------------=\n";
    cout << "\t \t \t \t \t \t \t |                                                   |\n";
    cout << "\t \t \t \t \t \t \t |    Digite o codigo do hardware que será vendido   |\n";
    cout << "\t \t \t \t \t \t \t |                                                   |\n";
    cout << "\t \t \t \t \t \t \t |       Caso queira cancelar a venda, Digite -1     |\n";
    cout << "\t \t \t \t \t \t \t |                                                   |\n";
    cout << "\t \t \t \t \t \t \t =---------------------------------------------------=\n";
	cout << "\t \t \t \t \t \t \t                         Escolha: ";
    cin >> linhan1;
    cin.sync();
    
    if (linhan1 == -1){
  	system("exit");
	}else{
	
	indice = 5;
	string quantia;
	int num1, num2, num3, num4;
	
	
	
    cout << "\t \t \t \t \t \t \t Informe quantos desse produto foram vendidos: "; 
    getline(cin, novo);
	
	
	num2 = stoi(novo);
	

	
    while (fin >> temp) { 
  
        linhas.clear(); 
  
        getline(fin, linha); 
        stringstream s(linha); 
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
            linhas.push_back(palavra); 
        }
  
        linhan2 = stoi(linhas[0]);
        
        int row_size = linhas.size(); 
  
        if (linhan2 == linhan1) { 
            cont = 1; 
            stringstream convert; 


			num3 = stoi(linhas[5]);
			num1 = num3 - num2;
			
			
            convert << num1;
            
            linhas[indice] = convert.str(); 
  
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {

                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        else {
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
  
                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        if (fin.eof()) { 
            break;
		}
    }
    if (cont == 1) { 
		cout << "\t \t \t \t \t \t \t Dados atualizados com Sucesso!! \n"; 
	} else if (cont == 0) { 
    	cout << "\t \t \t \t \t \t \t Dados nao encontrados!! Nao foi Possivel atualizar dados! \n\n";
    	atualizarhardware(); 
	}

    fin.close(); 
    fout.close(); 

    remove("produto_hardware.csv"); 
    rename("attproduto_hardware.csv", "produto_hardware.csv"); 
 
}
}
//------------------------------------------------------------------------------------------------------//
void listar_clientesperiferico() {
	
	system("cls"); 
	
	fstream fin; 
    			
    
    fin.open("historicoperiferico.csv", ios::in); 

    vector<string> linhas; 
    string linha, palavra, temp;
    
    cout << "\t \t \t \t \t \t \t ==============> Registro de Vendas Realizadas (Periféricos) <================ \n\n";
  
    while (fin >> temp) { 
  
        linhas.clear(); 

        getline(fin, linha); 
  
        stringstream s(linha); 
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra);   
        }

		cout << "\t \t \t \t \t \t \t ==============> Cliente " << linhas[0] << " <================ \n\n";
		
            cout << "\t \t \t \t \t \t \t Nome: " << linhas[1] << "\n";
            cout << "\t \t \t \t \t \t \t CPF: " << linhas[2] << "\n";
            cout << "\t \t \t \t \t \t \t Data: " << linhas[3] << "\n";
            
        cout << "\t \t \t \t \t \t \t ======================================================== \n\n";


    }
	
} 
void listar_clienteshardware() {
	
	system("cls");

	
	fstream fin; 
    
    fin.open("historicohardware.csv", ios::in); 
    vector<string> linhas; 
    string linha, palavra, temp;
    
    cout << "\t \t \t \t \t \t \t ==============> Registro de Vendas Realizadas (Hardware) <================ \n\n";
  
    while (fin >> temp) { 
  
        linhas.clear(); 

        getline(fin, linha); 
  
        stringstream s(linha); 
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra); 
        }

			cout << "\t \t \t \t \t \t \t==============> Cliente " << linhas[0] << " <================ \n\n";
		
            cout << "\t \t \t \t \t \t \t Nome: " << linhas[1] << "\n";
			cout << "\t \t \t \t \t \t \t CPF: " << linhas[2] << "\n";
            cout << "\t \t \t \t \t \t \t Data: " << linhas[3] << "\n";
            
        	cout << "\t \t \t \t \t \t \t ======================================================== \n\n";
		

    }
	
} 
//------------------------------------------------------------------------------------------------------//
void historicodevendas() {
string escolha;

	cout << "\t \t \t \t \t \t \t =------------------------------------------------------------------=\n";
    cout << "\t \t \t \t \t \t \t |  Deseja acessar o histórico de compra referente a qual produto:  |\n";
    cout << "\t \t \t \t \t \t \t =------------------------------------------------------------------=\n";
    cout << "\t \t \t \t \t \t \t |                                                                  |\n";
    cout << "\t \t \t \t \t \t \t |                        1. Hardware                               |\n";
    cout << "\t \t \t \t \t \t \t |                        2. Perifericos                            |\n";
    cout << "\t \t \t \t \t \t \t |                        3. Retornar a aba de Vendas               |\n";
    cout << "\t \t \t \t \t \t \t |                                                                  |\n";
    cout << "\t \t \t \t \t \t \t =------------------------------------------------------------------=\n";

cout << "\t \t \t \t \t \t \t                                        Escolha: "; 


cin >> escolha;

if (escolha == "1"){
listar_clienteshardware();
cout << "\t \t \t \t \t \t \t ";
system("pause");
system("cls");
system("exit");
historicodevendas();
}else if (escolha == "2"){
listar_clientesperiferico();
cout << "\t \t \t \t \t \t \t ";
system("pause");
system("cls");
system("exit");
historicodevendas();
}else if (escolha == "3"){
system("cls");
system("exit");
}else{
system("cls");
cout << "\t \t \t \t \t \t \t OPÇÃO INVÁLIDA, DIGITE SOMENTE UMA DAS OPÇÕES FORNECIDAS\n";
historicodevendas();
	}
}
void criarvenda(){
string escolha;

	cout << "\t \t \t \t \t \t \t =----------------------------------------------------------=\n";
    cout << "\t \t \t \t \t \t \t |      Qual a Categoria do Produto que foi vendido?:       |\n";
    cout << "\t \t \t \t \t \t \t =----------------------------------------------------------=\n";
    cout << "\t \t \t \t \t \t \t |                                                          |\n";
    cout << "\t \t \t \t \t \t \t |                  1. Hardware                             |\n";
    cout << "\t \t \t \t \t \t \t |                  2. Perifericos                          |\n";
    cout << "\t \t \t \t \t \t \t |                  3. Retornar a aba de Vendas             |\n";
    cout << "\t \t \t \t \t \t \t |                                                          |\n";
    cout << "\t \t \t \t \t \t \t =----------------------------------------------------------=\n";

	cout << "\t \t \t \t \t \t \t                         Escolha: "; 
	cin >> escolha;
	cin.sync();

	if (escolha == "1"){
	estoque_hardware();
	atualizarvendahardware2();
	system("cls");
	system("exit");
	criarvenda();
	}else if (escolha == "2"){
	estoque_periferico();
	atualizarvendaperiferico2();
	system("cls");
	system("exit");
	criarvenda();
	} else if ( escolha == "3") {
	system("exit");
	} else {
	criarvenda();
	}
}
void listarvendas(){
string escolha;

	cout << "\t \t \t \t \t \t \t =----------------------------------------=\n";
    cout << "\t \t \t \t \t \t \t |              Deseja Listar:            |\n";
    cout << "\t \t \t \t \t \t \t =----------------------------------------=\n";
    cout << "\t \t \t \t \t \t \t |                                        |\n";
    cout << "\t \t \t \t \t \t \t |      1. Hardware                       |\n";
    cout << "\t \t \t \t \t \t \t |      2. Perifericos                    |\n";
    cout << "\t \t \t \t \t \t \t |      3. Retornar a aba de Vendas       |\n";
    cout << "\t \t \t \t \t \t \t |                                        |\n";
    cout << "\t \t \t \t \t \t \t =----------------------------------------=\n";

	cout << "\t \t \t \t \t \t \t                  Escolha: ";

cin >> escolha;

if (escolha == "1"){
estoque_hardware();
listarvendas();
}else if (escolha == "2"){
estoque_periferico();
listarvendas();
}
}
void excluirvendaperiferico() {
	
	
	cout << "Deseja Listar: ===================> Atualizar dados dos Perifericos <================== \n\n";
	
    fstream fin, fout; 

    fin.open("produto_periferico.csv", ios::in); 

    fout.open("attproduto_periferico.csv", ios::out); 
    int linhan1, linhan2, indice, cont = 0; 
    string linha, palavra, sub, novo, temp;
    vector<string> linhas; 

    cout << "\t \t \t \t \t \t \t =--------------------------------------------------------------------------=\n";
    cout << "\t \t \t \t \t \t \t |                                                                          |\n";
    cout << "\t \t \t \t \t \t \t |      Digite o codigo do produto que deseja atualizar os dados            |\n";
    cout << "\t \t \t \t \t \t \t |      Caso não queira mais atualizar um produto, Digite -1                |\n";
    cout << "\t \t \t \t \t \t \t |                                                                          |\n";
    cout << "\t \t \t \t \t \t \t =--------------------------------------------------------------------------=\n";
	
    cout << "\t \t \t \t \t \t \t                                 Escolha: ";
    cin >> linhan1;
    cin.sync();
    
    if (linhan1 == -1){
  
	}else{
	
	indice = 5;
	string quantia;
	int num1, num2, num3, num4;
	
	
	
    cout << "\t \t \t \t \t \t \t Informe quantos desse produto foram vendidos: "; 
    getline(cin, novo);
	
	
	num2 = stoi(novo);

	
    while (fin >> temp) {
  
        linhas.clear(); 
  
        getline(fin, linha); 
        stringstream s(linha); 
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
            linhas.push_back(palavra); 
        }
  
        linhan2 = stoi(linhas[0]); 
        
        int row_size = linhas.size(); 
  
        if (linhan2 == linhan1) { 
            cont = 1; 
            stringstream convert; 
            
            
            
            num3 = stoi(linhas[5]); 
			num1 = num3 + num2;
			
			
            convert << num1;
            linhas[indice] = convert.str(); 
  
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {

                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        else {
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
  
                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        if (fin.eof()) { 
            break;
		}
    }
    if (cont == 1) { 
        cout << "\t \t \t \t \t \t \t Dados atualizados com Sucesso!! \n";
	} else if (cont == 0) { 
    	cout << "\t \t \t \t \t \t \t Dados nao encontrados!! Nao foi Possivel atualizar dados! \n\n";
    	atualizarhardware(); 
	}

    fin.close(); 
    fout.close(); 

    remove("produto_periferico.csv"); 
    rename("attproduto_periferico.csv", "produto_periferico.csv"); 
	
} 
system("cls");
}
void excluirvendahardware() {
	
	cout << "\t \t \t \t \t \t \t ===================> Atualizar dados dos Hardwares <================== \n\n";
	
    fstream fin, fout; 

    fin.open("produto_hardware.csv", ios::in); 

    fout.open("attproduto_hardware.csv", ios::out); 
  
    int linhan1, linhan2, indice, cont = 0; 
    string linha, palavra, sub, novo, temp;
    vector<string> linhas;

    cout << "\t \t \t \t \t \t \t =--------------------------------------------------------------------------=\n";
    cout << "\t \t \t \t \t \t \t |                                                                          |\n";
    cout << "\t \t \t \t \t \t \t |      Digite o codigo do produto que deseja atualizar os dados            |\n";
    cout << "\t \t \t \t \t \t \t |      Caso não queira mais atualizar um produto, Digite -1                |\n";
    cout << "\t \t \t \t \t \t \t |                                                                          |\n";
    cout << "\t \t \t \t \t \t \t =--------------------------------------------------------------------------=\n";

    cout << "\t \t \t \t \t \t \t                                 Escolha: ";
    cin >> linhan1;
    cin.sync();
    
    if (linhan1 == -1){
  
	}else{
	
	indice = 5;
	string quantia;
	int num1, num2, num3, num4;
	
	
	
    cout << "\t \t \t \t \t \t \t Informe quantos desse produto foram vendidos: "; 
    getline(cin, novo);
	
	
	num2 = stoi(novo);

	
    while (fin >> temp) { 
  
        linhas.clear(); 
  
        getline(fin, linha);
        stringstream s(linha); 
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
            linhas.push_back(palavra);
        }
  
        linhan2 = stoi(linhas[0]); 
        
        int row_size = linhas.size(); 
  
        if (linhan2 == linhan1) { 
            cont = 1; 
            stringstream convert; 


			num3 = stoi(linhas[5]);
			num1 = num3 + num2;
			
			
            convert << num1;
            linhas[indice] = convert.str(); 
  
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {

                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        else {
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
  
                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        if (fin.eof()) { 
            break;
		}
    }
    if (cont == 1) { 
        cout << "\t \t \t \t \t \t \t Dados atualizados com Sucesso!! \n";
	} else if (cont == 0) { 
    	cout << "\t \t \t \t \t \t \t Dados nao encontrados!! Nao foi Possivel atualizar dados! \n\n";
    	atualizarhardware(); 
	}

    fin.close(); 
    fout.close(); 

    remove("produto_hardware.csv"); 
    rename("attproduto_hardware.csv", "produto_hardware.csv"); 
 
}
}
void excluirvenda(){
string escolha;
cout << " \n";
	cout << "\t \t \t \t \t \t \t =-------------------------------------------------=\n";
    cout << "\t \t \t \t \t \t \t | Qual a Categoria do Produto que será excluido?: |\n";
    cout << "\t \t \t \t \t \t \t =-------------------------------------------------=\n";
    cout << "\t \t \t \t \t \t \t |                                                 |\n";
    cout << "\t \t \t \t \t \t \t |            	   1. Hardware                      |\n";
    cout << "\t \t \t \t \t \t \t |                2. Perifericos                   |\n";
    cout << "\t \t \t \t \t \t \t |                3. Retornar a aba de Vendas      |\n";
    cout << "\t \t \t \t \t \t \t |                                                 |\n";
    cout << "\t \t \t \t \t \t \t =-------------------------------------------------=\n";

    cout << "\t \t \t \t \t \t \t                  Escolha: ";
cin >> escolha;

if (escolha == "1"){
estoque_hardware();
excluirvendahardware();
system("cls");
system("exit");
excluirvenda();
}else if (escolha == "2"){
estoque_periferico();
excluirvendaperiferico();
excluirvenda();
}else if (escolha == "3"){
system("cls");
system("exit");
	}else{
	system("cls");
	cout << "\t \t \t \t \t \t \t OPÇÃO INVÁLIDA, DIGITE SOMENTE UMA DAS OPÇÕES FORNECIDAS\n";
	excluirvenda();
	}
}
void vendas() {
			system("cls");
			string choice;
			cout << "\t \t \t \t \t \t \t |-------------------------------------| \n";
			cout << "\t \t \t \t \t \t \t |        REGISTRO DAS VENDAS          | \n";
			cout << "\t \t \t \t \t \t \t |-------------------------------------| \n";
			cout << "\t \t \t \t \t \t \t |                                     | \n";
			cout << "\t \t \t \t \t \t \t |  1- Listagem de estoque disponivel  | \n";
			cout << "\t \t \t \t \t \t \t |  2- Cadastrar uma nova Venda        | \n";
			cout << "\t \t \t \t \t \t \t |  3- Cancelar Venda                  | \n";
			cout << "\t \t \t \t \t \t \t |  4- Histórico de Vendas             | \n";
			cout << "\t \t \t \t \t \t \t |  5- Sair                            | \n";
			cout << "\t \t \t \t \t \t \t |-------------------------------------| \n";
			cout << "\n";
			cout << "\t \t \t \t \t \t \t                Escolha: ";
			cin >> choice;
			cin.sync();
			
			if (choice == "1"){
			system("cls");
			listarvendas();
			system("cls");
			vendas();																																					
			}else if (choice == "2"){
			system("cls");
			criarvenda();
			system("cls");
			vendas();
			}else if (choice == "3"){
			system("cls");
			excluirvenda();
			system("cls");
			vendas();	
			}else if (choice == "4"){
			system("cls");
			historicodevendas();
			system("cls");
			vendas();
			}else if (choice == "5"){
			system("cls");
			system("exit");
			system("cls");
			} else {
			system("cls");
			vendas();
			}

}
//------------------------------------------------------------------------------------------------------//
void criarparceiros() {
	
	system("cls"); 
	
	cout << "\t \t \t \t \t \t \t ===================> Cadastrar Novos Parceiros <================== \n\n";
	    
    fstream fin, fout; 
    fin.open("parceiros.csv", ios::in); 
    vector<string> linhas; 
    string linha, palavra, temp;
  
    int x = 0;
  
  	while(fin >> temp) {
	  
	    linhas.clear(); 
	
	    getline(fin, linha); 
	
	    stringstream s(linha); 
	    
	    char virgula = ','; 

	    while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra); 
	    }
	    x = stoi(linhas[0]); 
	    
	}

    fout.open("parceiros.csv", ios::out | ios::app);
    
    int n;
	
	cout << "\t \t \t \t \t \t \t =---------------------------------------------------------------=\n";
    cout << "\t \t \t \t \t \t \t |                                                               |\n";
    cout << "\t \t \t \t \t \t \t |         Voce deseja cadastrar quantos Parceiros?              |\n";
    cout << "\t \t \t \t \t \t \t |                                                               |\n";
    cout << "\t \t \t \t \t \t \t |     Caso não queira mais cadastrar parceiros, Digite -1       |\n";
    cout << "\t \t \t \t \t \t \t |                                                               |\n";
    cout << "\t \t \t \t \t \t \t =---------------------------------------------------------------=\n";
    cout << "\t \t \t \t \t \t \t                         Escolha: ";
	cin >> n;
    cin.sync();
    
    if (n == -1){
    	
	}else{
	
  
    cout << "\t \t \t \t \t \t \t Informe os dados de " << n << " Parceiros:" << "\n\n";
  
    int codigo;
    string nome, marca, loja, preco;

    codigo = x; 

    for (int i = 0; i < n; i++) {
    	
    	codigo++;
  		cout << "\t \t \t \t \t \t \t ===========> Adicionar Parceiro " << codigo << " <============== \n\n";
  		cout << "\t \t \t \t \t \t \t Informe o nome do Parceiro: ";
        getline(cin, nome);
        cout << "\t \t \t \t \t \t \t Informe a empresa e o produto do Parceiro: ";
        getline(cin, marca);
        cout << "\t \t \t \t \t \t \t Informe a quantidade de materiais mensais que o Parceiro enviara: ";
		getline(cin, preco);
        cout << "\t \t \t \t \t \t \t Informe a(as) loja(s) que vendem o produtos do Parceiro: ";
		getline(cin, loja);
        cout << "\t \t \t \t \t \t \t =======================================================> \n\n";
  
        fout << ", " 
			 << codigo << ", " 
             << nome << ", "
             << marca << ", "
             << preco << ", "
             << loja
             << "\n";
    }
	cout << "\t \t \t \t \t \t \t Dados Gravados com Sucesso! \n";
}
}
void buscar_parceiros() {
	
	system("cls");  
	
	cout << "\t \t \t \t \t \t \t ===================> Pesquisar Parceiros <================== \n\n";

    fstream fin;
    fin.open("parceiros.csv", ios::in); 

    int linhan1, linhan2, cont = 0;
	
	cout << "\t \t \t \t \t \t \t =-----------------------------------------------------------------------------=\n";
    cout << "\t \t \t \t \t \t \t |                                                                            |\n";
    cout << "\t \t \t \t \t \t \t |      Digite o codigo do parceiro que deseja visualizar os dados            |\n";
    cout << "\t \t \t \t \t \t \t |          Caso não queira mais buscar parceiros, Digite -1                  |\n";
    cout << "\t \t \t \t \t \t \t |                                                                            |\n";
    cout << "\t \t \t \t \t \t \t =----------------------------------------------------------------------------=\n";

    cout << "\t \t \t \t \t \t \t                                 Escolha: "; 
    cin >> linhan1;
    
    if (linhan1 == -1){
    	
	}else{
		
	
  
    vector<string> linhas;
    string linha, palavra, temp;
  
    while (fin >> temp) { 
  
        linhas.clear(); 

        getline(fin, linha); 
  
        stringstream s(linha); 
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra);
        }
        
        linhan2 = stoi(linhas[0]); 
  
        if (linhan2 == linhan1) { 
  
            cont = 1; 
            cout << "\t \t \t \t \t \t \t ==============> Produto " << linhas[0] << " <================ \n\n";
            cout << "\t \t \t \t \t \t \t Codigo: " << linhas[0] << "\n";
            cout << "\t \t \t \t \t \t \t Nome " << linhas[1] << "\n";
            cout << "\t \t \t \t \t \t \t Empresa / Produto: " << linhas[2] << "\n";
            cout << "\t \t \t \t \t \t \t Materiais Mensais: " << linhas[3] << "\n";
            cout << "\t \t \t \t \t \t \t Loja: " << linhas[4] << "\n";
            cout << "\t \t \t \t \t \t \t ======================================================== \n\n";
            cout << "\n\n\n";
            break;
        }
    }
    if (cont == 0) { 
        cout << "\t \t \t \t \t \t \t Dados nao encontrados... \n";
        buscar_parceiros(); 
	}
	int op; 
	
	cout << "\t \t \t \t \t \t \t =--------------------------------------------------------------=\n";
    cout << "\t \t \t \t \t \t \t |                                                              |\n";
    cout << "\t \t \t \t \t \t \t |          Deseja buscar outro Parceiro? Digite 1              |\n";
    cout << "\t \t \t \t \t \t \t |      Caso não queira mais buscar um parceiro, Digite 0       |\n";
    cout << "\t \t \t \t \t \t \t |                                                              |\n";
    cout << "\t \t \t \t \t \t \t =--------------------------------------------------------------=\n";

    cout << "\t \t \t \t \t \t \t                           Escolha: ";
	cin >> op;	
    
    switch(op) {
    	case 1:
			buscar_parceiros();
			break;
		case 0:
			system("exit");
			break;
		default:
			cout << "\t \t \t \t \t \t \tOpçao Invalida!";
			buscar_parceiros();
			break;
	} 
} 
}
void listar_parceiros() {
	
	system("cls"); 
	
	fstream fin; 
    fin.open("parceiros.csv", ios::in); 
    vector<string> linhas; 
    string linha, palavra, temp;
    
    cout << "\t \t \t \t \t \t \t ==============> Lista de Parceiros Cadastrados <================ \n\n";
  
    while (fin >> temp) { 
  
        linhas.clear(); 

        getline(fin, linha); 
  
        stringstream s(linha); 
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra); 
        }

		cout << "\t \t \t \t \t \t \t           ==============> Parceiro " << linhas[0] << " <================ \n\n";
		
        cout << "\t \t \t \t \t \t \t            Nome: " << linhas[1] << "\n";
        cout << "\t \t \t \t \t \t \t            Empresa / Produto : " << linhas[2] << "\n";
        cout << "\t \t \t \t \t \t \t            Materiais Mensais: " << linhas[3] << "\n";
        cout << "\t \t \t \t \t \t \t            Loja: " << linhas[4] << "\n";
            
        cout << "\t \t \t \t \t \t \t    ======================================================== \n\n";

    }
	
}  
void atualizarparceiros() {
	
	system("cls"); 
	listar_parceiros();
	cout << "\t \t \t \t \t \t \t ===================> Atualizar dados dos Parceiros <================== \n\n";
	
    fstream fin, fout; 
    fin.open("parceiros.csv", ios::in); 
    fout.open("attparceiros.csv", ios::out); 
    int linhan1, linhan2, indice, sub, cont = 0; 
    string linha, palavra, novo, temp;
    vector<string> linhas; 


	cout << "\t \t \t \t \t \t \t =--------------------------------------------------------------------------=\n";
    cout << "\t \t \t \t \t \t \t |                                                                          |\n";
    cout << "\t \t \t \t \t \t \t |      Digite o codigo do parceiro que deseja atualizar os dados           |\n";
    cout << "\t \t \t \t \t \t \t |      Caso não queira mais atualizar dados de parceiros, Digite -1        |\n";
    cout << "\t \t \t \t \t \t \t |                                                                          |\n";
    cout << "\t \t \t \t \t \t \t =--------------------------------------------------------------------------=\n";

    cout << "\t \t \t \t \t \t \t                                 Escolha: ";
    cin >> linhan1;
    cin.sync();
    
    if (linhan1 == -1){
  
	}else{

    cout << "\t \t \t \t \t \t \t ==========> Alterar dados do Parceiro " << linhan1 << " <=========== \n\n";
    cout << "\t \t \t \t \t \t \t Para alterar o nome, Digite 1. \n";
    cout << "\t \t \t \t \t \t \t Para alterar o empresa, Digite 2. \n";
    cout << "\t \t \t \t \t \t \t Para alterar o quantidade de materiais mensais, Digite 3. \n";
    cout << "\t \t \t \t \t \t \t para alterar a loja(s), Digite 4. \n";
    cout << " ";
    cin >> sub;
  	cin.sync();
  	
  	
  	system("cls"); 
	listar_parceiros();
	
  	switch(sub) { 
  		case 1:
  		    cout << "\t \t \t \t \t \t \t ==============> Alterar Nome do Parceiro <================ \n\n";
  			indice = 1;
  			break;
  		case 2:
  			cout << "\t \t \t \t \t \t \t ==============> Alterar Marca da Empresa <================ \n\n";
  			indice = 2;
  			break;
  		case 3:
  			cout << "\t \t \t \t \t \t \t ==============> Alterar Quantidade de Materiais Mensais <================ \n\n";
  			indice = 3;
  			break;
  		case 4:
  			cout << "\t \t \t \t \t \t \t ==============> Alterar Loja(s) do Parceiro <================ \n\n";
  			indice = 4;
  			break;
  		default:
	        cout << "\t \t \t \t \t \t \t Opçao Invalida!! \n";
	        atualizarprodutos();
			break;  			
	  }

    cout << "\t \t \t \t \t \t \t Informe o novo dado: "; 
    getline(cin, novo);

    while (fin >> temp) { 
  
        linhas.clear(); 
  
        getline(fin, linha); 
        stringstream s(linha); 
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
            linhas.push_back(palavra); 
        }
  
        linhan2 = stoi(linhas[0]); 
        
        int row_size = linhas.size(); 
  
        if (linhan2 == linhan1) { 
            cont = 1; 
            stringstream convert; 

            convert << novo; 

            linhas[indice] = convert.str(); 
  
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {

                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        else {
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
  
                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        if (fin.eof()) { 
            break;
		}
    }
    if (cont == 1) { 
        cout << "\t \t \t \t \t \t \t Dados atualizados com Sucesso!! \n";
	} else if (cont == 0) { 
    	cout << "\t \t \t \t \t \t \t Dados nao encontrados!! Nao foi Possivel atualizar dados! \n\n";
    	atualizarprodutos(); 
	}

    fin.close(); 
    fout.close(); 

    remove("parceiros.csv"); 
    rename("attparceiros.csv", "parceiros.csv"); 
}
}
void excluirparceiros() {
system("cls");
	listar_parceiros();
	cout << "\t \t \t \t \t \t \t ===================> Excluir dados de Parceiros <================== \n\n";

    fstream fin, fout; 
    fin.open("parceiros.csv", ios::in); 
    fout.open("attparceiros.csv", ios::out);
    int linhan1, linhan2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas; 
	
	cout << "\t \t \t \t \t \t \t =--------------------------------------------------------------------------=\n";
    cout << "\t \t \t \t \t \t \t |                                                                          |\n";
    cout << "\t \t \t \t \t \t \t |      Digite o codigo do Parceiro que deseja excluir os dados             |\n";
    cout << "\t \t \t \t \t \t \t |      Caso não queira mais excluir dados de parceiro, Digite -1           |\n";
    cout << "\t \t \t \t \t \t \t |                                                                          |\n";
    cout << "\t \t \t \t \t \t \t =--------------------------------------------------------------------------=\n";

    cout << "\t \t \t \t \t \t \t                                 Escolha: ";
	

    cin >> linhan1;
    
    if (linhan1 == -1){
    	
	}else{
		
	

    while (fin >> temp) { 
        linhas.clear(); 
        getline(fin, linha); 
        stringstream s(linha);  
  
  		char virgula = ','; 
  		
        while (getline(s, palavra, virgula)) { 
            linhas.push_back(palavra); 
        }
  
        int row_size = linhas.size(); 
        linhan2 = stoi(linhas[0]); 

        if (linhan2 != linhan1) { 
        	
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof()) 
            break;
    }
    if (cont == 1) {
        cout << "\t \t \t \t \t \t \t Dados deletados com sucesso!! \n";
    } else {
        cout << "\t \t \t \t \t \t \t Dados nao encontrados!! Nao foi Possivel excluir dados! \n\n";
	}
		
    fin.close(); 
    fout.close(); 

    remove("parceiros.csv"); 
    rename("attparceiros.csv", "parceiros.csv"); 
    
    int opex;
	
	cout << "\t \t \t \t \t \t \t =--------------------------------------------=\n";
    cout << "\t \t \t \t \t \t \t |                                            |\n";
    cout << "\t \t \t \t \t \t \t |  Deseja excluir outro parceiro? Digite 1.  |\n";
    cout << "\t \t \t \t \t \t \t |                                            |\n";
    cout << "\t \t \t \t \t \t \t |          Deseja sair? Digite 0.            |\n";
    cout << "\t \t \t \t \t \t \t |                                            |\n";
    cout << "\t \t \t \t \t \t \t =--------------------------------------------=\n";
    cout << "\t \t \t \t \t \t \t                   Escolha: ";
	 

	cin >> opex;	
    
    switch(opex) {
    	case 1:
			excluirparceiros();
			break;
		case 0:
			system("exit");
			break;
		default:
			cout << "\t \t \t \t \t \t \t Opçao Invalida!";
			break;
	} 
	
}
}
//------------------------------------------------------------------------------------------------------//
void gerenciarlogins() {
system("cls");
cout << "gerenciar logins \n";
system("pause");
system("cls");	
}
void fazerlogoff(){
system("cls");
cout << "\t \t \t \t \t \t \t [EASTER EGG] sabia que você ia testar esse numero :), tenta outro que nao funciona \n";
system("pause");
system("cls");
}
void sobre() {
	
	
				int confirma, enqt, dev;
				
				
				system("cls");
				cout << "\t \t \t   =-------------------------------------------------------------------------------------------------------------=\n";
				cout << "\t \t \t   |                          O Software Atualmente Está na Versão: 9.99.999.9999                                |\n";
				cout << "\t \t \t   =-------------------------------------------------------------------------------------------------------------=\n";
				cout << "\t \t \t   |              Ele Foi Criado pela equipe MLPE, composta pelos desenvolvedores de sistemas:                   |\n";
				cout << "\t \t \t   |                                                                                                             |\n";	
				cout << "\t \t \t   |                                                                                                             |\n";		
				cout << "\t \t \t   |                                           - Mateus Meira                                                    |\n";
				cout << "\t \t \t   |                                           - Leonardo Guedes                                                 |\n";
				cout << "\t \t \t   |                                           - Priscila Candida                                                |\n";
				cout << "\t \t \t   |                                           - Emmily Vitória                                                  |\n";
				cout << "\t \t \t   |                                                                                                             |\n";	
				cout << "\t \t \t   |                                                                                                             |\n";
				cout << "\t \t \t   |                                                        Copyright © 2022 MLPE - Todos os direitos reservados |\n";
				cout << "\t \t \t   =-------------------------------------------------------------------------------------------------------------=\n";
				
				cout << "\t \t \t \t \t \t \t ";
				system("pause");
				cout << "\n\n\n\n";
				
				cout << "\t \t \t Caso tenha interesse em permanecer e conhecer mais sobre cada Desenvolvedor que participou da criação desse Software: \n\n";
				cout << "\t \t \t Digite: 1, Para acessar a aba sobre os desenvolvedores \n \n";
				cout << "\t \t \t Digite: 0, Retornar ao Menu Principal! \n\n";
				
				cout << "\t \t \t -> Escolha: ";
				cin >> confirma;
				
				switch (confirma) {
					
				case 0:
					system("cls");
					system("exit");
					break;
				case 1: 
					enqt = 1;
					while (enqt != 0) {
					system("cls");
					cout << "\t \t \t  =---------------------------------------------------------------------------------------------------------------------= \n";
					cout << "\t \t \t  | Nossa equipe fica contente em saber da curiosidade sobre os criadores do Software interno da empresa GGHARDWARE!!!  | \n";
					cout << "\t \t \t  =---------------------------------------------------------------------------------------------------------------------= \n";	
				
					cout << "\t \t \t  =---------------------------------------------------------------------------------------------------------------------=\n";
					cout << "\t \t \t  |                                                                                                                     |\n";
					cout << "\t \t \t  |                       Gostaria de saber mais sobre qual desenolvedor especificamente??                              |\n";
					cout << "\t \t \t  |                                                                                                                     |\n"; 
					cout << "\t \t \t  |                                       1 - Emmily Vitoria Barbosa Veloso                                             |\n";
					cout << "\t \t \t  |                                       2 - Leonardo Guedes Gomes Junior                                              |\n";
					cout << "\t \t \t  |                                       3 - Mateus Meira Santos                                                       |\n";
					cout << "\t \t \t  |                                       4 - Priscila Cândida Costa                                                    |\n";
					cout << "\t \t \t  |                                                                                                                     |\n";
					cout << "\t \t \t  |                                       5 - Retornar ao Menu Anterior                                                 |\n";
					cout << "\t \t \t  |                                                                                                                     |\n";
					cout << "\t \t \t  |                 Por favor, selecione um número relacionado a um dos Desenvolvedores acima:                          |\n";
					cout << "\t \t \t  |                                                                                                                     |\n";
					cout << "\t \t \t  =---------------------------------------------------------------------------------------------------------------------=\n";
					cout << "\t \t \t                                                  Escolha: ";
					cin >> dev;
					
								switch (dev){
											
								case 1:
					system("cls");
					cout << "\n\n\n";					
				cout << "\t \t \t =-------------------------------------------------------------------------------------------------------------------------= \n";
				cout << "\t \t \t |                                        EMMILY VITORIA BARBOSA VELOSO                                                    | \n";
				cout << "\t \t \t =-------------------------------------------------------------------------------------------------------------------------= \n";
				cout << "\t \t \t | Emmily Vitoria Barbosa Veloso, possui Ensino Médio completo pela Escola Estadual Anita Brina Brandão, é muito criativa, | \n";
				cout << "\t \t \t | perspicaz, resiliente, é ótima em trabalho em equipe. E além dessas habilidades sociais, ela está fazendo o Curso Téc-  | \n";
				cout << "\t \t \t | nico em Desenolvimento de Sistemas pelo SENAI, mas, ela também possui cursos extras curriculares, como Introdução à Co- | \n";
				cout << "\t \t \t | municação Empresarial e Word Básico, ambos pela fundção Bradesco.                                                       | \n";
				cout << "\t \t \t | Telefone Pessoal : (31) 99360-6990                                                                                      | \n";
				cout << "\t \t \t | E-mail Pessoal : Emmilyvitoria0906@gmail.com                                                                            | \n";
				cout << "\t \t \t =-------------------------------------------------------------------------------------------------------------------------= \n";	
					cout << "\t \t \t \t \t \t \t ";
					system("pause");
					enqt = 0;
					system("cls");
					break;
							
								case 2:
						system("cls");
						cout << "\n\n\n";					
				cout << "\t \t \t =-------------------------------------------------------------------------------------------------------------------------= \n";
				cout << "\t \t \t |                                        LEONARDO GUEDES GOMES JUNIOR                                                     | \n";
				cout << "\t \t \t =-------------------------------------------------------------------------------------------------------------------------= \n";
				cout << "\t \t \t | Leonardo Guedes Gomes Junior, concluiu o Ensino Fundamental e Médio pelo Colégio Tiradentes da Polícia Militar de Minas | \n";
				cout << "\t \t \t | Gerais, é dedicado, bem aplicado, possui grandes ambições de mercado e procura evoluir em conjunto de seus companheiros | \n";
				cout << "\t \t \t | de serviço. Além disso, Leonardo também é possui inglês avançado e fluente pela Yours School, conhece o intermediário / | \n";
				cout << "\t \t \t | avançado de Excel, e sua carreira na área de T.I está em evolução, cursando o Técnico em Desenvolvimento de Sistemas e  | \n";
				cout << "\t \t \t | a aprendizagem em Instalação e Reparação de Redes de Computadores, com  experiência profissional na multinacional Anglo | \n";
				cout << "\t \t \t | American.                                                                                                               | \n";
				cout << "\t \t \t | Telefone Pessoal : (31) 98690-3247                                                                                      | \n";
				cout << "\t \t \t | E-mail Pessoal : Leoguedesjr@gmail.com                                                                                  | \n";				
				cout << "\t \t \t =-------------------------------------------------------------------------------------------------------------------------= \n";	
					cout << "\t \t \t \t \t \t \t ";
					system("pause");
					enqt = 0;		
					system("cls");
					break;
								
								case 3:
						system("cls");
						cout << "\n\n\n";					
				cout << "\t \t \t =-------------------------------------------------------------------------------------------------------------------------=\n";
				cout << "\t \t \t |                                               MATEUS MEIRA SANTOS                                                       |  \n";
				cout << "\t \t \t =-------------------------------------------------------------------------------------------------------------------------=\n";
				cout << "\t \t \t | Mateus Meira Santos, é o profisional que toda equipe precisa de ter, dedicado, esforçado e proativo, um destaque geral. |\n";
				cout << "\t \t \t | Formou se no Ensino Médio na Escola Estadual Leonina Mourthé de Araújo. Mateus possui também um Curso Profissionalizan- |\n";
				cout << "\t \t \t | te pelo Divina Providência em Informática Avançada(aproveitamentos acima de 80%). Está atualmente cursando o Técnico em |\n";
				cout << "\t \t \t | Desenvolvimento de Sistemas pelo SENAI, e possui inglês intermediário / avançado .                                      |\n";
				cout << "\t \t \t | Telefone Pessoal : (31) 99133-7237                                                                                      |\n";
				cout << "\t \t \t | E-mail Pessoal : Mateus.meira.santos1@gmail.com                                                                         |\n";				
				cout << "\t \t \t =-------------------------------------------------------------------------------------------------------------------------=\n";	
					cout << "\t \t \t \t \t \t \t ";
					system("pause");
					enqt = 0;		
					system("cls");
					break;	
					
								case 4:
					system("cls");
					cout << "\n\n\n";					
				cout << "\t \t \t  =-------------------------------------------------------------------------------------------------------------------------=\n";
				cout << "\t \t \t  |                                              PRISCILA CÂNDIDA COSTA                                                     |  \n";
				cout << "\t \t \t  =-------------------------------------------------------------------------------------------------------------------------=\n";
				cout << "\t \t \t  | Priscila Cândida Costa, possui Ensino Médio completo pela Escola Estadual Anita Brina Brandão, é sem duvidas uma colega |\n";
				cout << "\t \t \t  | invejável para qualquer grupo, já que é muito divertida, com raciocínio rápido e curiosa para novas habilidades. Atual- |\n";
				cout << "\t \t \t  | mente está fazendo o Curso Técnico em Desenvolvimento de Sistemas pelo SENAI, mas não para por aí, ela ainda possui os  |\n";
				cout << "\t \t \t  | seguintes curso, Introdução à Comunicação Empresarial e Word Básico, amnbos pela Fundação Bradesco;                     |\n";
				cout << "\t \t \t  | Telefone Pessoal : (33) 99847-0186                                                                                      |\n";
				cout << "\t \t \t  | E-mail Pessoal : Priscilacandidacosta@gmail.com                                                                         |\n";
				cout << "\t \t \t  =-------------------------------------------------------------------------------------------------------------------------=\n";	
					cout << "\t \t \t \t \t \t \t ";
					system("pause");
					enqt = 0;		
					system("cls");
					break;
					
					default:
					system("cls");
					sobre();
					break;
					
				}
				}
					enqt = 0;
					system("exit");
					break;
				default :
					system("cls");
					system("exit");
					break;
					
}
}
//------------------------------------------------------------------------------------------------------//
void ajuda8(){

string escolha;

cout << "\t \t \t a função da aba de estoque é basicamente exibir informações resumidas de todos os produtos no estoque." << endl;
cout << "\t \t \t ela serve para a exibição de informações rapidas" << endl;
cout << "\t \t \t Para Acessar a aba de estoque é simples..., após o login: " << endl;
cout << "\t \t \t Digite: '1' para acessar produtos." << endl;
cout << "\t \t \t Digite: '7' para acessar a aba de estoque." << endl;
cout << "\t \t \t Após isso, escolha qual das opções você deseja listar. \n\n";
cout << "\t \t \t \t \t \t \t ";
system("pause");
}
void ajuda7() {
	int escolha;
cout << "\t \t \t Tudo bem, pra facilitar a explicação, qual das opções abaixo é o problema que você precisa de ajuda? \n";
cout << "\t \t \t 1. Como efetivo uma nova Venda? \n";
cout << "\t \t \t 2. Como Consulto a Lista de produtos Vendidos? \n";
cout << "\t \t \t 3. Como  posso cancelar uma Venda que ja foi efetivada? \n";
cout << "\t \t \t 4. Como posso verificar o histórico de vendas? \n";
cout << "\t \t \t 5. Retornar ao menu Principal\n";
cout << "\t \t \t                          Escolha: ";
cin >> escolha;
switch (escolha){

case 1:
system("cls");
cout << "\t \t \t Para efetivar uma nova venda é muito simples. \n";
cout << "\t \t \t 1- Após realizar o login, no menu principal digite ->1<- para acessar a aba: 'Produtos' \n";
cout << "\t \t \t 2- Dentro da aba produtos, digite ->6<- para acessar a aba: 'PRODUTOS VENDIDOS'. \n";
cout << "\t \t \t 2- Dentro da aba produtos, digite ->2<- para acessar a aba: 'CADASTRAR UMA NOVA VENDA' \n";
cout << "\t \t \t 3- Dentro da aba de cadastro, finalmente responda as perguntas do algoritmo e a efetivação da venda será realizada :) \n\n";
cout << "\t \t \t \t \t \t \t ";
system("pause");
system("cls");
ajuda7(); 
break;

case 2:
system("cls");
cout << "\t \t \t Para checar a lista de produtos vendidos é muito simples. \n";
cout << "\t \t \t 1- Após realizar o login, no menu principal digite ->1<- para acessar a aba: 'Produtos'. \n";
cout << "\t \t \t 2- Dentro da aba produtos, digite ->6<- para acessar a aba: 'PRODUTOS VENDIDOS'. \n";
cout << "\t \t \t 3- Dentro da aba vendas, digite ->1<- para acessar a aba: 'LISTAR'. \n";
cout << "\t \t \t 4- Em seguida, basta decidir em qual ala de produtos desejará acessar, então você estará com a lista de de produtos vendidos. :) \n\n";
cout << "\t \t \t \t \t \t \t ";
system("pause");
system("cls"); 
ajuda7();
break;

case 3:
system("cls");
cout << "\t \t \t Para cancelar uma venda que já foi efetivada é muito simples. \n";
cout << "\t \t \t 1- Após realizar o login, no menu principal digite ->1<- para acessar a aba: 'Produtos'. \n";
cout << "\t \t \t 2- Dentro da aba produtos, digite ->6<- para acessar a aba: 'PRODUTOS VENDIDOS'. \n";
cout << "\t \t \t 3- Dentro da aba vendas, digite ->3<- para acessar a aba: 'CANCELAR VENDA'. \n";
cout << "\t \t \t 4- Dentro da aba de cadastro, finalmente responda as perguntas do algoritmo e o cancelamento da venda será realizado :) \n\n";
cout << "\t \t \t \t \t \t \t ";
system("pause");
system("cls");
ajuda7();
break;

case 4:
system("cls");
cout << "\t \t \t Para acessar o histórico de compra dos clientes é muito simples. \n";
cout << "\t \t \t 1- Após realizar o login, no menu principal digite ->1<- para acessar a aba: 'Produtos'. \n";
cout << "\t \t \t 2- Dentro da aba produtos, digite ->6<- para acessar a aba: 'PRODUTOS VENDIDOS'. \n";
cout << "\t \t \t 3- Dentro da aba vendas, digite ->4<- para acessar a aba: 'HISTÓRICO DE COMPRA'. \n";
cout << "\t \t \t 4- E decidir sobre qual tipo de prodduto deseja ver o histórico, e está feito. :) \n\n";
cout << "\t \t \t \t \t \t \t ";
system("pause");
system("cls");
ajuda7();
break;

case 5:
system("cls");
system("exit");
break;

default:
system("cls");
system("exit");
}
}
void ajuda6(){
system("cls");
cout << "\t \t \t Lamentamos por não conseguir responder a sua dúvida.\n";
cout << "\t \t \t Por favor comunique os desenvolvedores do software!\n";
cout << "\t \t \t Na aba, Sobre, no menu principal, você encontrará o contato de todos desenvolvedores!\n";
cout << "\t \t \t Assim que possível ire-mos prestar a assistência necessária para corrigir um erro que esteja no aplicativo ou responder suas dúvidas\n\n";
cout << "\t \t \t \t \t \t \t ";
system("pause");
system("cls");
}
void ajuda5(){
int escolha;
cout << "\t \t \t Tudo bem, pra facilitar a explicação, qual das opções abaixo é o problema que você precisa de ajuda? \n";
cout << "\t \t \t 1. Como Cadastro um novo parceiro? \n";
cout << "\t \t \t 2. Como Consulto a Lista de todos os meus parceiros? \n";
cout << "\t \t \t 3. Como Busco apenas um parceiro especifico para saber suas informações? \n";
cout << "\t \t \t 4. Como Atualizo os dados de um parceiro? \n";
cout << "\t \t \t 5. Preciso Excluir um parceiro da lista e nao sei como... \n";
cout << "\t \t \t 6. Retornar ao menu Principal \n\n";
cout << "\t \t \t                                               Escolha: ";
cin >> escolha;
switch (escolha){

case 1:
system("cls");
cout << "\t \t \t Para cadastrar um novo parceiro é muito simples. \n";
cout << "\t \t \t 1- após realizar o login, no menu principal digite ->4<- para acessar a aba: 'PARCEIROS' \n";
cout << "\t \t \t 2- dentro da aba parceiros, digite ->2<- para acessar a aba: 'CADASTRAR UM NOVO PARCEIRO' \n";
cout << "\t \t \t 3- dentro da aba de cadastro, finalmente responda as perguntas do algoritmo e seu cadastro de fornecedores será realizado :) \n\n";
cout << "\t \t \t \t \t \t \t ";
system("pause");
system("cls");
ajuda5(); 
break;

case 2:
system("cls");
cout << "\t \t \t Para listar seus parceiros é muito simples. \n";
cout << "\t \t \t 1- após realizar o login, no menu principal digite ->4<- para acessar a aba: 'PARCEIROS' \n";
cout << "\t \t \t 2- dentro da aba parceiros, digite ->1<- para acessar a aba: 'LISTAR PERFIS DE PARCEIROS' \n";
cout << "\t \t \t 3- após isso, você estará dentro da aba desejada e conseguirá saber a lista completa de seus parceiros :) \n\n";
cout << "\t \t \t \t \t \t \t ";
system("pause");
system("cls"); 
ajuda5();
break;

case 3:
system("cls");
cout << "\t \t \t Para buscar informações especificas de um parceiro é muito simples. \n";
cout << "\t \t \t 1- após realizar o login, no menu principal digite ->4<- para acessar a aba: 'PARCEIROS' \n";
cout << "\t \t \t 2- dentro da aba parceiros, digite ->3<- para acessar a aba: 'PESQUISAR PARCEIROS' \n";
cout << "\t \t \t 3- dentro da aba será exibido uma lista com todos os nomes de parceiros da loja \n";
cout << "\t \t \t 4- agora basta escolher o numero do parceiro para saber mais sobre ele :) \n\n";
cout << "\t \t \t \t \t \t \t ";
system("pause");
system("cls");
ajuda5();
break;

case 4:
system("cls");
cout << "\t \t \t Para Atualizar um Parceiro é muito simples. \n";
cout << "\t \t \t 1- após realizar o login, no menu principal digite ->4<- para acessar a aba: 'PARCEIROS' \n";
cout << "\t \t \t 2- dentro da aba parceiros, digite ->4<- para acessar a aba: 'ATUALIZAR PARCEIROS' \n";
cout << "\t \t \t 3- dentro da aba atualização, digite o codigo do parceiro \n";
cout << "\t \t \t 4- o software irá solicitar qual informação deverá ser alterada, informe o numero da informação e depois digite os novos dados \n\n";
cout << "\t \t \t \t \t \t \t ";
system("pause");
system("cls");
ajuda5();
break;

case 5:
system("cls");
cout << "\t \t \t Para Excluir um Parceiro é muito simples. \n";
cout << "\t \t \t 1- após realizar o login, no menu principal digite ->4<- para acessar a aba: 'PARCEIROS' \n";
cout << "\t \t \t 2- dentro da aba parceiros, digite ->5<- para acessar a aba: 'EXCLUIR PARCEIROS' \n";
cout << "\t \t \t 3- dentro da aba exclusão, digite o codigo do parceiro e a exclusão será realizada :) \n\n";
cout << "\t \t \t \t \t \t \t ";
system("pause");
system("cls");
ajuda5();
break;

case 6:
system("cls");
system("exit");
break;

default:
system("cls");
ajuda5();
}	
}
void ajuda4(){
int escolha;
cout << "\t \t \t Tudo bem, pra facilitar a explicação, qual das opções abaixo é o problema que você precisa de ajuda? \n";
cout << "\t \t \t 1. Como Cadastro um novo Fornecedor? \n";
cout << "\t \t \t 2. Como Consulto a Lista de todos os meus Fornecedores? \n";
cout << "\t \t \t 3. Como Busco apenas um Fornecedor especifico para saber suas informações? \n";
cout << "\t \t \t 4. Como Atualizo os dados de um fornecedor? \n";
cout << "\t \t \t 5. Preciso Excluir um Fornecedor da lista e nao sei como... \n";
cout << "\t \t \t 6. Retornar ao menu Principal \n\n";
cout << "\t \t \t                                        Escolha: ";
cin >> escolha;
switch (escolha){

case 1:
system("cls");
cout << "\t \t \t Para cadastrar um novo Fornecedor é muito simples. \n";
cout << "\t \t \t 1- após realizar o login, no menu principal digite ->3<- para acessar a aba: 'FORNECEDORES' \n";
cout << "\t \t \t 2- dentro da aba fornecedores, digite ->2<- para acessar a aba: 'CADASTRAR UM NOVO CLIENTE' \n";
cout << "\t \t \t 3- dentro da aba de cadastro, finalmente responda as perguntas do algoritmo e seu cadastro de fornecedores será realizado :) \n\n";
cout << "\t \t \t \t \t \t \t ";
system("pause");
system("cls"); 
ajuda4();
break;

case 2:
system("cls");
cout << "\t \t \t Para listar seus Fornecedores é muito simples. \n";
cout << "\t \t \t 1- após realizar o login, no menu principal digite ->3<- para acessar a aba: 'FORNECEDORES' \n";
cout << "\t \t \t 2- dentro da aba fornecedores, digite ->1<- para acessar a aba: 'LISTAR PERFIS DE FORNECEDORES' \n";
cout << "\t \t \t 3- após isso, você estará dentro da aba desejada e conseguirá saber a lista completa de seus fornecedores :) \n\n";
cout << "\t \t \t \t \t \t \t ";
system("pause");
system("cls"); 
ajuda4();
break;

case 3:
system("cls");
cout << "\t \t \t Para buscar informações especificas de um Fornecedor é muito simples. \n";
cout << "\t \t \t 1- após realizar o login, no menu principal digite ->3<- para acessar a aba: 'FORNECEDORES' \n";
cout << "\t \t \t 2- dentro da aba fornecedores, digite ->3<- para acessar a aba: 'PESQUISAR FORNECEDORES' \n";
cout << "\t \t \t 3- dentro da aba será exibido uma lista com todos os nomes de fornecedores da loja\n";
cout << "\t \t \t 4- agora basta escolher o numero do fornecedor para saber mais sobre ele :) \n\n";
cout << "\t \t \t \t \t \t \t ";
system("pause");
system("cls");
ajuda4();
break;

case 4:
system("cls");
cout << "\t \t \t Para Atualizar um fornecedor é muito simples. \n";
cout << "\t \t \t 1- após realizar o login, no menu principal digite ->3<- para acessar a aba: 'FORNECEDORES' \n";
cout << "\t \t \t 2- dentro da aba fornecedores, digite ->4<- para acessar a aba: 'ATUALIZAR FORNECEDORES' \n";
cout << "\t \t \t 3- dentro da aba atualização, digite o codigo do fornecedor \n";
cout << "\t \t \t 4- o software irá solicitar qual informação deverá ser alterada, informe o numero da informação e depois digite os novos dados \n\n";
cout << "\t \t \t \t \t \t \t ";
system("pause");
system("cls");
ajuda4();
break;

case 5:
system("cls");
cout << "\t \t \t Para Excluir um Fornecedor é muito simples. \n";
cout << "\t \t \t 1- após realizar o login, no menu principal digite ->3<- para acessar a aba: 'FORNECEDORES' \n";
cout << "\t \t \t 2- dentro da aba fornecedores, digite ->5<- para acessar a aba: 'EXCLUIR FORNECEDORES' \n";
cout << "\t \t \t 3- dentro da aba exclusão, digite o codigo do cliente e a exclusão será realizada :) \n\n";
cout << "\t \t \t \t \t \t \t ";
system("pause");
system("cls");
ajuda4();
break;

case 6:
system("cls");
system("exit");
break;

default:
system("cls");
ajuda4();
}
}
void ajuda3(){
int escolha;
cout << "\t \t \t Tudo bem, pra facilitar a explicação, qual das opções abaixo é o problema que você precisa de ajuda? \n";
cout << "\t \t \t 1. Como Cadastro um novo cliente? \n";
cout << "\t \t \t 2. Como Consulto a Lista de todos os meus clientes? \n";
cout << "\t \t \t 3. Como Busco apenas um cliente especifico para saber suas informações? \n";
cout << "\t \t \t 4. Como Atualizo os dados de um cliente? \n";
cout << "\t \t \t 5. Preciso Excluir um cliente da lista e nao sei como... \n";
cout << "\t \t \t 6. Retornar ao menu Principal\n\n";

cout << "\t \t \t                                         Escolha: ";
cin >> escolha;
switch (escolha){

case 1:
system("cls");
cout << "\t \t \t Para cadastrar um novo cliente é muito simples. \n";
cout << "\t \t \t 1- após realizar o login, no menu principal digite ->2<- para acessar a aba: 'CLIENTES' \n";
cout << "\t \t \t 2- dentro da aba clientes, digite ->2<- para acessar a aba: 'CADASTRAR UM NOVO CLIENTE' \n";
cout << "\t \t \t 3- dentro da aba de cadastro, finalmente responda as perguntas do algoritmo e seu cadastro de produto será realizado :) \n\n";
cout << "\t \t \t \t \t \t \t ";
system("pause");
system("cls"); 
ajuda3();
break;

case 2:
system("cls");
cout << "\t \t \t Para listar seus clientes é muito simples. \n";
cout << "\t \t \t 1- após realizar o login, no menu principal digite '2' para acessar a aba: 'CLIENTES' \n";
cout << "\t \t \t 2- dentro da aba clientes, digite ->1<- para acessar a aba: 'LISTAR PERFIS DE CLIENTES' \n";
cout << "\t \t \t 3- após isso, você estará dentro da aba desejada e conseguirá saber a lista completa de seus produtos :) \n\n";
cout << "\t \t \t \t \t \t \t ";
system("pause");
system("cls"); 
ajuda3();
break;

case 3:
system("cls");
cout << "\t \t \t Para buscar informações especificas de um cliente é muito simples. \n";
cout << "\t \t \t 1- após realizar o login, no menu principal digite '2' para acessar a aba: 'CLIENTES' \n";
cout << "\t \t \t 2- dentro da aba clientes, digite ->3<- para acessar a aba: 'PESQUISAR CLIENTES' \n";
cout << "\t \t \t 3- dentro da aba será exibido uma lista com todos os nomes de clientes da loja \n";
cout << "\t \t \t 4- com isso, basta escolher o numero do cliente para saber mais sobre ele :) \n\n";
cout << "\t \t \t \t \t \t \t ";
system("pause");
system("cls");
ajuda3();
break;

case 4:
system("cls");
cout << "\t \t \t Para Atualizar um cliente é muito simples. \n";
cout << "\t \t \t 1- após realizar o login, no menu principal digite '2' para acessar a aba: 'CLIENTES' \n";
cout << "\t \t \t 2- dentro da aba clientes, digite ->4<- para acessar a aba: 'ATUALIZAR CLIENTES' \n";
cout << "\t \t \t 3- dentro da aba atualização, digite o codigo do produto \n";
cout << "\t \t \t 4- o software irá solicitar qual informação deverá ser alterada, informe o numero da informação e depois digite os novos dados \n\n";
cout << "\t \t \t \t \t \t \t ";
system("pause");
system("cls");
ajuda3();
break;

case 5:
system("cls");
cout << "\t \t \t Para Excluir um cliente é muito simples. \n";
cout << "\t \t \t 1- após realizar o login, no menu principal digite '2' para acessar a aba: 'CLIENTES' \n";
cout << "\t \t \t 2- dentro da aba clientes, digite ->5<- para acessar a aba: 'EXCLUIR CLIENTES' \n";
cout << "\t \t \t 3- dentro da aba exclusão, digite o codigo do cliente e a exclusão será realizada :) \n\n";
cout << "\t \t \t \t \t \t \t ";
system("pause");
system("cls");
ajuda3();
break;


case 6:
system("cls");
system("exit");
break;
	
default:
system("cls");
ajuda3();
}
}	
void ajuda2(){
int escolha;
cout << "\t \t \t Tudo bem, pra facilitar a explicação, qual das opções abaixo é o problema que você precisa de ajuda? \n";
cout << "\t \t \t 1. Como Cadastro um novo produto? \n";
cout << "\t \t \t 2. Como Consulto a Lista de todos os meus produtos em estoque? \n";
cout << "\t \t \t 3. Como Busco apenas um produto especifico para saber suas informações? \n";
cout << "\t \t \t 4. Como Atualizo os dados de um produto? \n";
cout << "\t \t \t 5. Preciso Excluir um produto da lista e nao sei como... \n";
cout << "\t \t \t 6. Retornar ao menu Principal \n\n";

cout << "\t \t \t                                               Escolha: ";
cin >> escolha;
switch (escolha){

case 1:
system("cls");
cout << "\t \t \t Para cadastrar um novo produto é muito simples. \n";
cout << "\t \t \t 1- após realizar o login, no menu principal digite '1' para acessar a aba: 'PRODUTO' \n";
cout << "\t \t \t 2- dentro da aba produto, digite ->3<- para acessar a aba: 'CADASTRAR NOVO PRODUTO' \n";
cout << "\t \t \t 3- dentro da aba de cadastro, finalmente responda as perguntas do algoritmo e seu cadastro de produto será realizado :) \n\n";
cout << "\t \t \t \t \t \t \t ";
system("pause");
system("cls"); 
ajuda2();
break;

case 2:
system("cls");
cout << "\t \t \t Para listar seus produtos é muito simples. \n";
cout << "\t \t \t 1- após realizar o login, no menu principal digite '1' para acessar a aba: 'PRODUTO' \n";
cout << "\t \t \t 2- dentro da aba produto, digite ->2<- para acessar a aba: 'LISTAR PRODUTOS' \n";
cout << "\t \t \t 3- após isso, você estará dentro da aba desejada e conseguirá saber a lista completa de seus produtos :) \n\n";
cout << "\t \t \t \t \t \t \t ";
system("pause");
system("cls"); 
ajuda2();
break;

case 3:
system("cls");
cout << "\t \t \t Para buscar informações especificas de um produto é muito simples. \n";
cout << "\t \t \t 1- após realizar o login, no menu principal digite '1' para acessar a aba: 'PRODUTO' \n";
cout << "\t \t \t 2- dentro da aba produto, digite ->4<- para acessar a aba: 'PESQUISAR UM PRODUTO' \n";
cout << "\t \t \t 3- dentro da aba será exibido uma lista com todos os nomes de produtos cadastrados da loja \n";
cout << "\t \t \t 4- Pronto, agora basta escolher a categoria e o numero do produto para saber mais sobre ele :) \n\n";
cout << "\t \t \t \t \t \t \t ";
system("pause");
system("cls");
ajuda2();
break;

case 4:
system("cls");
cout << "\t \t \t Para Atualizar um produto é muito simples. \n";
cout << "\t \t \t 1- após realizar o login, no menu principal digite '1' para acessar a aba: 'PRODUTO' \n";
cout << "\t \t \t 2- dentro da aba produto, digite ->1<- para acessar a aba: 'ATUALIZAR PRODUTO' \n";
cout << "\t \t \t 3- dentro da aba atualização, digite o codigo do produto \n";
cout << "\t \t \t 4- o software irá solicitar qual informação deverá ser alterada, informe o numero da informação e depois digite os novos dados \n\n";
cout << "\t \t \t \t \t \t \t ";
system("pause");
system("cls");
ajuda2();
break;

case 5:
system("cls");
cout << "\t \t \t Para Excluir um produto é muito simples. \n";
cout << "\t \t \t 1- após realizar o login, no menu principal digite '1' para acessar a aba: 'PRODUTO' \n";
cout << "\t \t \t 2- dentro da aba produto, digite ->5<- para acessar a aba: 'EXCLUIR PRODUTO' \n";
cout << "\t \t \t 3- dentro da aba exclusão, digite o codigo do produto e a exclusão será realizada :) \n\n";
cout << "\t \t \t \t \t \t \t ";
system("pause");
system("cls");
ajuda2();
break;

case 6:

system("cls");
system("exit");
break;

default:
system("cls");
ajuda2();
}
}
void ajuda() {
int escolha;
cout << "\t \t \t -============================================= BEM VINDO AO MENU DE AJUDA! =============================================- \n";
cout << "\t \t \t ------------------------------------------------ Como podemos atende-lo? ------------------------------------------------ \n\n";
cout << "\t \t \t 1. Preciso de suporte em relação a: Cadastrar Produtos / Listar ou Buscar Produtos / Excluir Produtos \n";
cout << "\t \t \t 2. Preciso de suporte em relação a: Cadastrar Clientes / Listar ou Buscar Clientes / Excluir Cadastro de Cliente \n";
cout << "\t \t \t 3. Preciso de suporte em relação a: Cadastrar Fornecedor / Listar ou Buscar Fornecedor / Excluir Cadastro de Fornecedor \n";
cout << "\t \t \t 4. Preciso de suporte em relação a: Cadastrar Parceiros / Listar ou Buscar Parceiros / Excluir Fornecedor \n";
cout << "\t \t \t 5. O Aplicativo não esta sendo executado como deveria / nao achei a resposta para uma duvida. \n";
cout << "\t \t \t 6. Preciso de suporte em relação a: Cadastrar Venda / Listar Vendas / Cancelar Venda / Histórico de Vendas \n";
cout << "\t \t \t 7. Não Entendi como Utilizar a aba de estoque \n";
cout << "\t \t \t 8. Retornar ao Menu Principal \n \n";

cout << "\t \t \t                                                          Escolha: ";
cin >> escolha;
switch (escolha){


case 1:
system("cls");
ajuda2();
system("cls");
ajuda();
break;

case 2:
system("cls");
ajuda3();
system("cls");
ajuda();
break;

case 3:
system("cls");
ajuda4();
system("cls");
ajuda();
break;

case 4:
system("cls");
ajuda5();
system("cls");
ajuda();
break;

case 5:
system("cls");
ajuda6();
system("cls");
ajuda();
break;

case 6:
system("cls");
ajuda7();
system("cls");
ajuda();
break;

case 7:
system("cls");
ajuda8();
system("cls");
ajuda();
break;

case 8:
system("cls");
break;

default:
system("cls");
cout << "\t \t \t Você Digitou uma Opção que não esta disponivel... Retornamos para o Menu de Escolhas! \n\n\n";
ajuda();
break;
}

}
//------------------------------------------------------------------------------------------------------//
void parceiros() {
		
		
					system("cls");
			string choice;
		
			cout << "\t \t \t \t \t \t \t |-------------------------------------| \n";
			cout << "\t \t \t \t \t \t \t |         AREA DOS PARCEIROS          | \n";
			cout << "\t \t \t \t \t \t \t |-------------------------------------| \n";
			cout << "\t \t \t \t \t \t \t |                                     | \n";
			cout << "\t \t \t \t \t \t \t |   1- Listar Perfis dos Parceiros    | \n";
			cout << "\t \t \t \t \t \t \t |   2- Cadastrar um novo Parceiro     | \n";
			cout << "\t \t \t \t \t \t \t |   3- Pesquisar Parceiro             | \n";
			cout << "\t \t \t \t \t \t \t |   4- Atualizar dados do Parceiro    | \n";
			cout << "\t \t \t \t \t \t \t |   5- Encerrar parceiria             | \n";
			cout << "\t \t \t \t \t \t \t |   6- Sair                           | \n";
			cout << "\t \t \t \t \t \t \t |-------------------------------------| \n";
			cout << "\n";
			cout << "\t \t \t \t \t \t \t                Escolha: ";
			cin >> choice;
			cin.sync();
			
			if (choice == "1") {
		
				system("cls");
				listar_parceiros();
				cout << "\t \t \t \t \t \t \t             ";
				system("pause");
				parceiros();

				
				
			}else if (choice == "2"){
				
				system("cls");	
				criarparceiros();
				parceiros();
				
			} else if (choice == "3"){
				
				
				system("cls");
				buscar_parceiros();
				
				parceiros();
				
			} else if(choice == "4"){
				
			
				system("cls");
				atualizarparceiros();
				parceiros();
				
				
			} else if(choice == "5"){
				
			
				system("cls");
				excluirparceiros();
			
				parceiros();
				
				
				
			}  else if (choice == "6"){
				
			
				system("cls");
				system("exit");
			
				
				
			} else {
			cout << "------ a opção digitada não está disponivel, tente novamente ------\n";
			system("pause");
			parceiros();				
			}

}
void fornecedores() {
		
		
					system("cls");
			string choice;
		
			cout << "\t \t \t \t \t \t \t|--------------------------------------| \n";
			cout << "\t \t \t \t \t \t \t|         AREA DOS FORNECEDORES        | \n";
			cout << "\t \t \t \t \t \t \t|--------------------------------------| \n";
			cout << "\t \t \t \t \t \t \t|                                      | \n";
			cout << "\t \t \t \t \t \t \t|  1- Listar Perfis dos Fornecedores   | \n";
			cout << "\t \t \t \t \t \t \t|  2- Cadastrar um novo Fornecedor     | \n";
			cout << "\t \t \t \t \t \t \t|  3- Pesquisar Fornecedor             | \n";
			cout << "\t \t \t \t \t \t \t|  4- Atualizar dados do Fornecedor    | \n";
			cout << "\t \t \t \t \t \t \t|  5- Encerrar contrato com Fornecedor | \n";
			cout << "\t \t \t \t \t \t \t|  6- Sair                             | \n";
			cout << "\t \t \t \t \t \t \t|--------------------------------------| \n";
			cout << "\n";
			cout << "\t \t \t \t \t \t \t                Escolha: ";
			cin >> choice;
			cin.sync();
			
			if (choice == "1") {
		
				system("cls");
				listar_fornecedores();
				cout << "\t \t \t \t \t \t \t ";
				system("pause");
				fornecedores();
				system("cls");

				
				
			}else if (choice == "2"){
				
				system("cls");	
				criarfornecedores();
				fornecedores();
				
			} else if (choice == "3"){
				
				
				system("cls");
				buscar_fornecedores();
				
				fornecedores();
				
			} else if(choice == "4"){
				
			
				system("cls");
				atualizarfornecedores();
				
			
				fornecedores();
				
				
			} else if(choice == "5"){
				
			
				system("cls");
				excluirfornecedores();
			
				fornecedores();
				
				
				
			}  else if (choice == "6"){
				
			
				system("cls");
				system("exit");
			
				
				
			} else {
			cout << "------ a opção digitada não está disponivel, tente novamente ------\n";
			cout << "\t \t \t \t \t \t \t ";
			system("pause");
			fornecedores();				
			}
}
void clientes() {
		
		
					system("cls");
			string choice;
		
			cout << "\t \t \t \t \t \t \t |-------------------------------------| \n";
			cout << "\t \t \t \t \t \t \t |         AREA DOS CLIENTES           | \n";
			cout << "\t \t \t \t \t \t \t |-------------------------------------| \n";
			cout << "\t \t \t \t \t \t \t |                                     | \n";
			cout << "\t \t \t \t \t \t \t |  1- Listar Perfis dos Clientes      | \n";
			cout << "\t \t \t \t \t \t \t |  2- Cadastrar um novo Cliente       | \n";
			cout << "\t \t \t \t \t \t \t |  3- Pesquisar Cliente               | \n";
			cout << "\t \t \t \t \t \t \t |  4- Atualizar dados do Cliente      | \n";
			cout << "\t \t \t \t \t \t \t |  5- Excluir Cadastro de um Cliente  | \n";
			cout << "\t \t \t \t \t \t \t |  6- Sair                            | \n";
			cout << "\t \t \t \t \t \t \t |-------------------------------------| \n";
			cout << "\n";
			cout << "\t \t \t \t \t \t \t               Escolha: ";
			cin >> choice;
			cin.sync();
			
				
				if (choice == "1") {
		
				system("cls");	
				listar_clientes();
				cout << "\t \t \t \t \t \t \t ";
				system("pause");
				clientes();

				
				
			}else if (choice == "2"){
				
				system("cls");	
				criarclientes();
				clientes();
				
			} else if (choice == "3"){
				
				
				system("cls");
				buscar_clientes();
				
				clientes();
				
			} else if(choice == "4"){
				
			
				system("cls");
				atualizarclientes();
				clientes();
				
				
			} else if(choice == "5"){
				
			
				system("cls");
				excluirclientes();
			
				clientes();
				
				
				
			}  else if (choice == "6"){
				
			
				system("cls");
				system("exit");
			
				
				
			} else {
			cout << "------ a opção digitada não está disponivel, tente novamente ------\n";
			system("pause");
			clientes();				
			}
}
void produtos() {
			
			system("cls");
			string choice;
			cout << "\n \n \n"; 
			cout << " \t \t \t \t \t \t \t |--------------------------------------------------| \n";
			cout << " \t \t \t \t \t \t \t |                 AREA DOS PRODUTOS                | \n";
			cout << " \t \t \t \t \t \t \t |--------------------------------------------------| \n";
			cout << " \t \t \t \t \t \t \t |                                                  | \n";
			cout << " \t \t \t \t \t \t \t |           1- Atualizar                           | \n";
			cout << " \t \t \t \t \t \t \t |           2- Listar                              | \n";
			cout << " \t \t \t \t \t \t \t |           3- Cadastrar um produto novo           | \n";
			cout << " \t \t \t \t \t \t \t |           4- Pesquisar Produto                   | \n";
			cout << " \t \t \t \t \t \t \t |           5- Excluir Produto                     | \n";
			cout << " \t \t \t \t \t \t \t |           6- Produtos Vendidos                   | \n";
			cout << " \t \t \t \t \t \t \t |           7- Produtos em Estoque                 | \n";
			cout << " \t \t \t \t \t \t \t |           8- Sair                                | \n";
			cout << " \t \t \t \t \t \t \t |                                                  | \n";
			cout << " \t \t \t \t \t \t \t |--------------------------------------------------| \n";
			cout << " \t \t \t \t \t \t \t \n";
			cout << " \t \t \t \t \t \t \t               Escolha: ";
			cin >> choice;
			cin.sync();
			
		if (choice == "1") {
		
				system("cls");
				atualizarprodutos();
			
				produtos();

				
				
			}else if (choice == "2"){
				
				system("cls");	
				listar_produtos();
				produtos();
				
			} else if (choice == "3"){
				
				
				system("cls");
				criarprodutos();
				
				produtos();
				
			} else if(choice == "4"){
				
			
				system("cls");
				buscar_produtos();
			
				produtos();
				
				
			} else if(choice == "5"){
				
			
				system("cls");
				excluirprodutos();
			
				produtos();
				
				
				
			} else if(choice == "6"){
				
		
				system("cls");
				vendas();
				
				produtos();
						
				
			} else if(choice == "7"){
				
				system("cls");
				estoque();
				
				produtos();
			
				
			} else if (choice == "8"){
				
			
				system("cls");
				system("exit");
			
				
				
			} else {
			cout << "------ a opção digitada não está disponivel, tente novamente ------\n";
			system("pause");
			produtos();				
			}		
}			
void select() {
int num, confirma, abc, constante2, inicio;
string choice;

confirma = 13;
while (confirma != 14){
	
			cout << "\n \n \n";
			cout << " \t \t \t \t \t \t \t =------------------------------------= \n";
			cout << " \t \t \t \t \t \t \t |          SEJA BEM - VINDO          | \n";
			cout << " \t \t \t \t \t \t \t =------------------------------------= \n";
			cout << " \t \t \t \t \t \t \t |                                    | \n";
			cout << " \t \t \t \t \t \t \t |          1- Produtos               | \n";
			cout << " \t \t \t \t \t \t \t |          2- Clientes               | \n";
			cout << " \t \t \t \t \t \t \t |          3- Fornecedores           | \n";
			cout << " \t \t \t \t \t \t \t |          4- Parceiros              | \n";
			cout << " \t \t \t \t \t \t \t |          5- Ajuda                  | \n";
			cout << " \t \t \t \t \t \t \t |          6- Sobre                  | \n";
			cout << " \t \t \t \t \t \t \t |          7- Sair do Aplicativo     | \n";
			cout << " \t \t \t \t \t \t \t |                                    | \n";
			cout << " \t \t \t \t \t \t \t =------------------------------------= \n";
			cout << "\n";
			cout << "\t\t \t \t \t \t \t \tQual funcao deseja realizar? \n";
			cout << "\t        \t \t \t \t \t \t \tEscolha: ";
			cin >> choice;
			if (choice == "1"){
			system("cls");	
			produtos();
			}else if (choice == "2"){
			system("cls");
			clientes();
			}else if (choice == "3"){
			system("cls");
			fornecedores();
			}else if (choice == "4"){
			system("cls");
			parceiros();
			}else if (choice == "5"){
			system("cls");
			ajuda();
			}else if (choice == "6"){
			system("cls");
			sobre();
			}else if (choice == "7"){
			system("cls");	
			confirma = 14;
			cout << "Finalizando Processos...\n";
			cout << "Obrigado por Utilizar nosso aplicativo! :D";
			system("exit");
			
			}else if (choice == "0"){
			system("cls");
			fazerlogoff();
			}else{
			system("cls");
			select();
			}
}
			
}
//------------------------------------------------------------------------------------------------------//
void login3() {
string senha, login, cad1, cad2, senha1;
	
	int i;	
	
	//==================================================
	 // ALTERAR O LOGIN DO ADMNISTRADOR DO APLICATIVO
	cad1 = "Admin";
	cad2 = "GGHardware";
	//==================================================
	cout << "\t \t \t \t \t \t \t <---------------------------------->" << "\n" << endl;
	cout << " \t \t \t \t \t \t \t \tLogin: ";
	cin >> login;
	cout << " \t \t \t \t \t \t \t \tSenha: ";
	senha = takePasswdFromUser();
	cout << "\n";
	cout << "\t \t \t \t \t \t \t <---------------------------------->" << "\n" << endl;

	
	if ((login == cad1) && (senha == cad2)){
	
	cout << " \t \t \t \t \t \t \t \t   Acesso permitido \n";
	cout << "\t \t \t \t \t \t      ";
	system("pause");
	system("cls");
	
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);

SetConsoleTextAttribute(h,1);


SetConsoleTextAttribute(h,14);
cout << "\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n";
cout << setw(60) << "                        oooooooooo.  oooooooooooo ooo        ooooo               oooooo     oooo ooooo ooooo      ooo oooooooooo.     .oooooo.  \n";
cout << setw(60) << "                        `888'   `Y8b `888'      8 `88.       .888'                `888.     .8'  `888' `888b.     `8' `888'   `Y8b   d8P'  `Y8b \n";
cout << setw(60) << "                         888     888  888          888b     d'888                  `888.   .8'    888   8 `88b.    8   888      888 888      888\n";
cout << setw(60) << "                         888oooo888'  888oooo8     8 Y88. .P  888                   `888. .8'     888   8   `88b.  8   888      888 888      888\n";
cout << setw(60) << "                         888    `88b  888          8  `888'   888     8888888        `888.8'      888   8     `88b.8   888      888 888      888\n";
cout << setw(60) << "                         888    .88P  888       o  8    Y     888                     `888'       888   8       `888   888     d88' `88b    d88'\n";
cout << setw(60) << "                        o888bood8P'  o888ooooood8 o8o        o888o                     `8'       o888o o8o        `8  o888bood8P'    `Y8bood8P' \n";
Sleep(2000);
system("cls");
SetConsoleTextAttribute(h,10);
cout << "\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n";
cout << setw(60) << "                        oooooooooo.  oooooooooooo ooo        ooooo               oooooo     oooo ooooo ooooo      ooo oooooooooo.     .oooooo.  \n";
cout << setw(60) << "                        `888'   `Y8b `888'      8 `88.       .888'                `888.     .8'  `888' `888b.     `8' `888'   `Y8b   d8P'  `Y8b \n";
cout << setw(60) << "                         888     888  888          888b     d'888                  `888.   .8'    888   8 `88b.    8   888      888 888      888\n";
cout << setw(60) << "                         888oooo888'  888oooo8     8 Y88. .P  888                   `888. .8'     888   8   `88b.  8   888      888 888      888\n";
cout << setw(60) << "                         888    `88b  888          8  `888'   888     8888888        `888.8'      888   8     `88b.8   888      888 888      888\n";
cout << setw(60) << "                         888    .88P  888       o  8    Y     888                     `888'       888   8       `888   888     d88' `88b    d88'\n";
cout << setw(60) << "                        o888bood8P'  o888ooooood8 o8o        o888o                     `8'       o888o o8o        `8  o888bood8P'    `Y8bood8P' \n";
Sleep(2000);
system("cls");
SetConsoleTextAttribute(h,7);
cout << "\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n";
cout << setw(60) << "                        oooooooooo.  oooooooooooo ooo        ooooo               oooooo     oooo ooooo ooooo      ooo oooooooooo.     .oooooo.  \n";
cout << setw(60) << "                        `888'   `Y8b `888'      8 `88.       .888'                `888.     .8'  `888' `888b.     `8' `888'   `Y8b   d8P'  `Y8b \n";
cout << setw(60) << "                         888     888  888          888b     d'888                  `888.   .8'    888   8 `88b.    8   888      888 888      888\n";
cout << setw(60) << "                         888oooo888'  888oooo8     8 Y88. .P  888                   `888. .8'     888   8   `88b.  8   888      888 888      888\n";
cout << setw(60) << "                         888    `88b  888          8  `888'   888     8888888        `888.8'      888   8     `88b.8   888      888 888      888\n";
cout << setw(60) << "                         888    .88P  888       o  8    Y     888                     `888'       888   8       `888   888     d88' `88b    d88'\n";
cout << setw(60) << "                        o888bood8P'  o888ooooood8 o8o        o888o                     `8'       o888o o8o        `8  o888bood8P'    `Y8bood8P' \n";
Sleep(2000);
system("cls");
SetConsoleTextAttribute(h,13);
cout << "\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n";
cout << setw(60) << "                        oooooooooo.  oooooooooooo ooo        ooooo               oooooo     oooo ooooo ooooo      ooo oooooooooo.     .oooooo.  \n";
cout << setw(60) << "                        `888'   `Y8b `888'      8 `88.       .888'                `888.     .8'  `888' `888b.     `8' `888'   `Y8b   d8P'  `Y8b \n";
cout << setw(60) << "                         888     888  888          888b     d'888                  `888.   .8'    888   8 `88b.    8   888      888 888      888\n";
cout << setw(60) << "                         888oooo888'  888oooo8     8 Y88. .P  888                   `888. .8'     888   8   `88b.  8   888      888 888      888\n";
cout << setw(60) << "                         888    `88b  888          8  `888'   888     8888888        `888.8'      888   8     `88b.8   888      888 888      888\n";
cout << setw(60) << "                         888    .88P  888       o  8    Y     888                     `888'       888   8       `888   888     d88' `88b    d88'\n";
cout << setw(60) << "                        o888bood8P'  o888ooooood8 o8o        o888o                     `8'       o888o o8o        `8  o888bood8P'    `Y8bood8P' \n";
Sleep(2000);
system("cls");
SetConsoleTextAttribute(h,15);
cout << "\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n";
cout << setw(60) << "                        oooooooooo.  oooooooooooo ooo        ooooo               oooooo     oooo ooooo ooooo      ooo oooooooooo.     .oooooo.  \n";
cout << setw(60) << "                        `888'   `Y8b `888'      8 `88.       .888'                `888.     .8'  `888' `888b.     `8' `888'   `Y8b   d8P'  `Y8b \n";
cout << setw(60) << "                         888     888  888          888b     d'888                  `888.   .8'    888   8 `88b.    8   888      888 888      888\n";
cout << setw(60) << "                         888oooo888'  888oooo8     8 Y88. .P  888                   `888. .8'     888   8   `88b.  8   888      888 888      888\n";
cout << setw(60) << "                         888    `88b  888          8  `888'   888     8888888        `888.8'      888   8     `88b.8   888      888 888      888\n";
cout << setw(60) << "                         888    .88P  888       o  8    Y     888                     `888'       888   8       `888   888     d88' `88b    d88'\n";
cout << setw(60) << "                        o888bood8P'  o888ooooood8 o8o        o888o                     `8'       o888o o8o        `8  o888bood8P'    `Y8bood8P' \n";
Sleep(5000);
system("cls");
	select();
	
	}else{
	system("cls");
	system("exit");
}
}
void login2() {

string senha, login, cad1, cad2, senha1;
	int i;	
	
	//==================================================
	 // ALTERAR O LOGIN DO ADMNISTRADOR DO APLICATIVO
	cad1 = "Admin";
	cad2 = "GGHardware";
	//==================================================
	cout << "\t \t \t \t \t \t \t <---------------------------------->" << "\n" << endl;
	cout << " \t \t \t \t \t \t \t \tLogin: ";
	cin >> login;
	cout << " \t \t \t \t \t \t \t \tSenha: ";
	senha = takePasswdFromUser();
	cout << "\n";
	cout << "\t \t \t \t \t \t \t <---------------------------------->" << "\n" << endl;

	
	if ((login == cad1) && (senha == cad2)){
	
	cout << " \t \t \t \t \t \t \t \t   Acesso permitido \n";
	cout << "\t \t \t \t \t \t      ";
	system("pause");
	system("cls");
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);

SetConsoleTextAttribute(h,1);


SetConsoleTextAttribute(h,14);
cout << "\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n";
cout << setw(60) << "                        oooooooooo.  oooooooooooo ooo        ooooo               oooooo     oooo ooooo ooooo      ooo oooooooooo.     .oooooo.  \n";
cout << setw(60) << "                        `888'   `Y8b `888'      8 `88.       .888'                `888.     .8'  `888' `888b.     `8' `888'   `Y8b   d8P'  `Y8b \n";
cout << setw(60) << "                         888     888  888          888b     d'888                  `888.   .8'    888   8 `88b.    8   888      888 888      888\n";
cout << setw(60) << "                         888oooo888'  888oooo8     8 Y88. .P  888                   `888. .8'     888   8   `88b.  8   888      888 888      888\n";
cout << setw(60) << "                         888    `88b  888          8  `888'   888     8888888        `888.8'      888   8     `88b.8   888      888 888      888\n";
cout << setw(60) << "                         888    .88P  888       o  8    Y     888                     `888'       888   8       `888   888     d88' `88b    d88'\n";
cout << setw(60) << "                        o888bood8P'  o888ooooood8 o8o        o888o                     `8'       o888o o8o        `8  o888bood8P'    `Y8bood8P' \n";
Sleep(2000);
system("cls");
SetConsoleTextAttribute(h,10);
cout << "\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n";
cout << setw(60) << "                        oooooooooo.  oooooooooooo ooo        ooooo               oooooo     oooo ooooo ooooo      ooo oooooooooo.     .oooooo.  \n";
cout << setw(60) << "                        `888'   `Y8b `888'      8 `88.       .888'                `888.     .8'  `888' `888b.     `8' `888'   `Y8b   d8P'  `Y8b \n";
cout << setw(60) << "                         888     888  888          888b     d'888                  `888.   .8'    888   8 `88b.    8   888      888 888      888\n";
cout << setw(60) << "                         888oooo888'  888oooo8     8 Y88. .P  888                   `888. .8'     888   8   `88b.  8   888      888 888      888\n";
cout << setw(60) << "                         888    `88b  888          8  `888'   888     8888888        `888.8'      888   8     `88b.8   888      888 888      888\n";
cout << setw(60) << "                         888    .88P  888       o  8    Y     888                     `888'       888   8       `888   888     d88' `88b    d88'\n";
cout << setw(60) << "                        o888bood8P'  o888ooooood8 o8o        o888o                     `8'       o888o o8o        `8  o888bood8P'    `Y8bood8P' \n";
Sleep(2000);
system("cls");
SetConsoleTextAttribute(h,7);
cout << "\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n";
cout << setw(60) << "                        oooooooooo.  oooooooooooo ooo        ooooo               oooooo     oooo ooooo ooooo      ooo oooooooooo.     .oooooo.  \n";
cout << setw(60) << "                        `888'   `Y8b `888'      8 `88.       .888'                `888.     .8'  `888' `888b.     `8' `888'   `Y8b   d8P'  `Y8b \n";
cout << setw(60) << "                         888     888  888          888b     d'888                  `888.   .8'    888   8 `88b.    8   888      888 888      888\n";
cout << setw(60) << "                         888oooo888'  888oooo8     8 Y88. .P  888                   `888. .8'     888   8   `88b.  8   888      888 888      888\n";
cout << setw(60) << "                         888    `88b  888          8  `888'   888     8888888        `888.8'      888   8     `88b.8   888      888 888      888\n";
cout << setw(60) << "                         888    .88P  888       o  8    Y     888                     `888'       888   8       `888   888     d88' `88b    d88'\n";
cout << setw(60) << "                        o888bood8P'  o888ooooood8 o8o        o888o                     `8'       o888o o8o        `8  o888bood8P'    `Y8bood8P' \n";
Sleep(2000);
system("cls");
SetConsoleTextAttribute(h,13);
cout << "\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n";
cout << setw(60) << "                        oooooooooo.  oooooooooooo ooo        ooooo               oooooo     oooo ooooo ooooo      ooo oooooooooo.     .oooooo.  \n";
cout << setw(60) << "                        `888'   `Y8b `888'      8 `88.       .888'                `888.     .8'  `888' `888b.     `8' `888'   `Y8b   d8P'  `Y8b \n";
cout << setw(60) << "                         888     888  888          888b     d'888                  `888.   .8'    888   8 `88b.    8   888      888 888      888\n";
cout << setw(60) << "                         888oooo888'  888oooo8     8 Y88. .P  888                   `888. .8'     888   8   `88b.  8   888      888 888      888\n";
cout << setw(60) << "                         888    `88b  888          8  `888'   888     8888888        `888.8'      888   8     `88b.8   888      888 888      888\n";
cout << setw(60) << "                         888    .88P  888       o  8    Y     888                     `888'       888   8       `888   888     d88' `88b    d88'\n";
cout << setw(60) << "                        o888bood8P'  o888ooooood8 o8o        o888o                     `8'       o888o o8o        `8  o888bood8P'    `Y8bood8P' \n";
Sleep(2000);
system("cls");
SetConsoleTextAttribute(h,15);
cout << "\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n";
cout << setw(60) << "                        oooooooooo.  oooooooooooo ooo        ooooo               oooooo     oooo ooooo ooooo      ooo oooooooooo.     .oooooo.  \n";
cout << setw(60) << "                        `888'   `Y8b `888'      8 `88.       .888'                `888.     .8'  `888' `888b.     `8' `888'   `Y8b   d8P'  `Y8b \n";
cout << setw(60) << "                         888     888  888          888b     d'888                  `888.   .8'    888   8 `88b.    8   888      888 888      888\n";
cout << setw(60) << "                         888oooo888'  888oooo8     8 Y88. .P  888                   `888. .8'     888   8   `88b.  8   888      888 888      888\n";
cout << setw(60) << "                         888    `88b  888          8  `888'   888     8888888        `888.8'      888   8     `88b.8   888      888 888      888\n";
cout << setw(60) << "                         888    .88P  888       o  8    Y     888                     `888'       888   8       `888   888     d88' `88b    d88'\n";
cout << setw(60) << "                        o888bood8P'  o888ooooood8 o8o        o888o                     `8'       o888o o8o        `8  o888bood8P'    `Y8bood8P' \n";
Sleep(5000);
system("cls");
	select();
	
	}else{
	cout << "\n \n \n";
	cout << "\t \t \t \t \t \t    Voce Ainda Pode Tentar Logar mais uma Vez!\n";
	cout << "\n \n \n";
	login3();
}
}
void login1() {
string login, cad1, cad2, senha1;
	string senha;
	int i;
	
		



	
	//==================================================
	 // ALTERAR O LOGIN DO ADMNISTRADOR DO APLICATIVO
	cad1 = "Admin";
	cad2 = "GGHardware";
	//==================================================
	cout << "\t \t \t \t \t \t \t <---------------------------------->" << "\n" << endl;
	cout << " \t \t \t \t \t \t \t \tLogin: ";
	cin >> login;
	cout << " \t \t \t \t \t \t \t \tSenha: ";
	senha = takePasswdFromUser();
	
	cout << "\n";
	cout << "\t \t \t \t \t \t \t <---------------------------------->" << "\n" << endl;

	
	if ((login == cad1) && (senha == cad2)){
	
	cout << " \t \t \t \t \t \t \t \t   Acesso permitido \n";
	cout << "\t \t \t \t \t \t      ";
	system("pause");
	system("cls");
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);

SetConsoleTextAttribute(h,1);


SetConsoleTextAttribute(h,3);
cout << "\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n";
cout << setw(60) << "                        oooooooooo.  oooooooooooo ooo        ooooo               oooooo     oooo ooooo ooooo      ooo oooooooooo.     .oooooo.  \n";
cout << setw(60) << "                        `888'   `Y8b `888'      8 `88.       .888'                `888.     .8'  `888' `888b.     `8' `888'   `Y8b   d8P'  `Y8b \n";
cout << setw(60) << "                         888     888  888          888b     d'888                  `888.   .8'    888   8 `88b.    8   888      888 888      888\n";
cout << setw(60) << "                         888oooo888'  888oooo8     8 Y88. .P  888                   `888. .8'     888   8   `88b.  8   888      888 888      888\n";
cout << setw(60) << "                         888    `88b  888          8  `888'   888     8888888        `888.8'      888   8     `88b.8   888      888 888      888\n";
cout << setw(60) << "                         888    .88P  888       o  8    Y     888                     `888'       888   8       `888   888     d88' `88b    d88'\n";
cout << setw(60) << "                        o888bood8P'  o888ooooood8 o8o        o888o                     `8'       o888o o8o        `8  o888bood8P'    `Y8bood8P' \n";
Sleep(2000);
system("cls");
SetConsoleTextAttribute(h,6);
cout << "\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n";
cout << setw(60) << "                        oooooooooo.  oooooooooooo ooo        ooooo               oooooo     oooo ooooo ooooo      ooo oooooooooo.     .oooooo.  \n";
cout << setw(60) << "                        `888'   `Y8b `888'      8 `88.       .888'                `888.     .8'  `888' `888b.     `8' `888'   `Y8b   d8P'  `Y8b \n";
cout << setw(60) << "                         888     888  888          888b     d'888                  `888.   .8'    888   8 `88b.    8   888      888 888      888\n";
cout << setw(60) << "                         888oooo888'  888oooo8     8 Y88. .P  888                   `888. .8'     888   8   `88b.  8   888      888 888      888\n";
cout << setw(60) << "                         888    `88b  888          8  `888'   888     8888888        `888.8'      888   8     `88b.8   888      888 888      888\n";
cout << setw(60) << "                         888    .88P  888       o  8    Y     888                     `888'       888   8       `888   888     d88' `88b    d88'\n";
cout << setw(60) << "                        o888bood8P'  o888ooooood8 o8o        o888o                     `8'       o888o o8o        `8  o888bood8P'    `Y8bood8P' \n";
Sleep(2000);
system("cls");
SetConsoleTextAttribute(h,9);
cout << "\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n";
cout << setw(60) << "                        oooooooooo.  oooooooooooo ooo        ooooo               oooooo     oooo ooooo ooooo      ooo oooooooooo.     .oooooo.  \n";
cout << setw(60) << "                        `888'   `Y8b `888'      8 `88.       .888'                `888.     .8'  `888' `888b.     `8' `888'   `Y8b   d8P'  `Y8b \n";
cout << setw(60) << "                         888     888  888          888b     d'888                  `888.   .8'    888   8 `88b.    8   888      888 888      888\n";
cout << setw(60) << "                         888oooo888'  888oooo8     8 Y88. .P  888                   `888. .8'     888   8   `88b.  8   888      888 888      888\n";
cout << setw(60) << "                         888    `88b  888          8  `888'   888     8888888        `888.8'      888   8     `88b.8   888      888 888      888\n";
cout << setw(60) << "                         888    .88P  888       o  8    Y     888                     `888'       888   8       `888   888     d88' `88b    d88'\n";
cout << setw(60) << "                        o888bood8P'  o888ooooood8 o8o        o888o                     `8'       o888o o8o        `8  o888bood8P'    `Y8bood8P' \n";
Sleep(2000);
system("cls");
SetConsoleTextAttribute(h,13);
cout << "\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n";
cout << setw(60) << "                        oooooooooo.  oooooooooooo ooo        ooooo               oooooo     oooo ooooo ooooo      ooo oooooooooo.     .oooooo.  \n";
cout << setw(60) << "                        `888'   `Y8b `888'      8 `88.       .888'                `888.     .8'  `888' `888b.     `8' `888'   `Y8b   d8P'  `Y8b \n";
cout << setw(60) << "                         888     888  888          888b     d'888                  `888.   .8'    888   8 `88b.    8   888      888 888      888\n";
cout << setw(60) << "                         888oooo888'  888oooo8     8 Y88. .P  888                   `888. .8'     888   8   `88b.  8   888      888 888      888\n";
cout << setw(60) << "                         888    `88b  888          8  `888'   888     8888888        `888.8'      888   8     `88b.8   888      888 888      888\n";
cout << setw(60) << "                         888    .88P  888       o  8    Y     888                     `888'       888   8       `888   888     d88' `88b    d88'\n";
cout << setw(60) << "                        o888bood8P'  o888ooooood8 o8o        o888o                     `8'       o888o o8o        `8  o888bood8P'    `Y8bood8P' \n";
Sleep(2000);
system("cls");
SetConsoleTextAttribute(h,15);
cout << "\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n";
cout << setw(60) << "                        oooooooooo.  oooooooooooo ooo        ooooo               oooooo     oooo ooooo ooooo      ooo oooooooooo.     .oooooo.  \n";
cout << setw(60) << "                        `888'   `Y8b `888'      8 `88.       .888'                `888.     .8'  `888' `888b.     `8' `888'   `Y8b   d8P'  `Y8b \n";
cout << setw(60) << "                         888     888  888          888b     d'888                  `888.   .8'    888   8 `88b.    8   888      888 888      888\n";
cout << setw(60) << "                         888oooo888'  888oooo8     8 Y88. .P  888                   `888. .8'     888   8   `88b.  8   888      888 888      888\n";
cout << setw(60) << "                         888    `88b  888          8  `888'   888     8888888        `888.8'      888   8     `88b.8   888      888 888      888\n";
cout << setw(60) << "                         888    .88P  888       o  8    Y     888                     `888'       888   8       `888   888     d88' `88b    d88'\n";
cout << setw(60) << "                        o888bood8P'  o888ooooood8 o8o        o888o                     `8'       o888o o8o        `8  o888bood8P'    `Y8bood8P' \n";
Sleep(5000);
system("cls");
	select();
	
	}else{
	cout << "\n \n \n";
	cout << "\t \t \t \t \t \t    Voce Ainda Pode Tentar Logar mais duas Vezes!\n";
	cout << "\n \n \n";
	login2();
}
}
//------------------------------------------------------------------------------------------------------//
int main(int argc, char** argv) {
setlocale(LC_ALL, "Portuguese");



//select(); // para desativar o modo adm, comente essa opção
 login1();  //" "; // para desativar o modo usuário, comente essa opção
}
