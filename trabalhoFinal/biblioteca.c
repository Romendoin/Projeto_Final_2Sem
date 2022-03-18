#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "funcoes.h"
#define AUX_ALI 300
#define AUX_FIL 35.50

///sub-menus
void gerarRelatorio (){
       int opcao;
       bool sair = false;
       system("cls");

       while(sair==false){
        system("cls");
        printf("\t\tGerar relatório:\n");
        printf("1 - Funcionário\n2 - Tabela de cargos e salários\n3 - Total da folha do mês\n4 - Situação das folhas de pagamento\n5 - Maior Salário\n6 - Média de salário por funcionário\n7 - Voltar");
        printf("\nSelecione a opção desejada: ");
        fflush(stdin);
        scanf(" %d", &opcao);
        fflush(stdin);
        switch(opcao){
            case 1: Funcionario();
                break;
           case 2: tabelaDEcargos();
                break;
           case 3: totalFOLHAmes();
                break;
           case 4: situacaoDAfolha();
                break;
           case 5: MaiorSalario();
                break;
           case 6: MediaDEsalarioFuncionario();
                break;
            case 7:
                sair = true;
                break;
            default: printf("Escolha uma das opções. Pressione enter para continuar\n\n");
                fflush(stdin);
                getc(stdin);
        }

}

}
///cadastro funcionário
void cadastroFunc(){
    int i=1;
    int escolhaCarg;
    char ch;
    char *c;
    system("cls");

    if(carg[1].valor==0){
        printf("Nenhum cargo registrado. Cadastre um cargo para continuar");
        fflush(stdin);
        getc(stdin);
        return menu();
    }

    system("cls");
    while(pessoa[i].cont!=0){
        i++;
    }

    printf("====================================//==================================\n");
    printf("\t\tCadastro de Funcionário");
    printf("\nNome: ");
    fgets(pessoa[i].nome, 31, stdin);
    strtok(pessoa[i].nome, "\n");
	if (strlen(pessoa[i].nome) == 31 - 1)
	{
		while ((ch = getchar()) != '\n' && ch != EOF);
	}
    printf("\nCargos\n");

    for(int x = 1; x<16; x++){
        if(carg[x].valor == 0 && carg[x+1].valor == 0){
            break;
        }
        if(carg[x].valor == 0){
            x++;
        }
        printf("%d - %s\n", x, carg[x].nomeCargo);
    }
    printf("Selecione um cargo: ");
    scanf("%d", &escolhaCarg);
    scanf("%c", &c);
    strcpy(pessoa[i].funcCargo.nomeCargo, carg[escolhaCarg].nomeCargo);
    strcpy(pessoa[i].funcCargo.descricao, carg[escolhaCarg].descricao);
    pessoa[i].funcCargo.valor = carg[escolhaCarg].valor;

    printf("\nData de Admição. Digite no formato dd mm aaaa: ");
    scanf("%d%d%d", &pessoa[i].admicao.dia, &pessoa[i].admicao.mes, &pessoa[i].admicao.ano);
    scanf("%c", &c);

    printf("CPF: ");
    fgets(pessoa[i].cpf, 15, stdin);
    strtok(pessoa[i].cpf, "\n");
	if (strlen(pessoa[i].cpf) == 15 - 1)
	{
		while ((ch = getchar()) != '\n' && ch != EOF);
	}
    printf("Contato: ");
    fflush(stdin);
    fgets(pessoa[i].contato, 20, stdin);
    strtok(pessoa[i].contato, "\n");
    if (strlen(pessoa[i].contato) == 20 - 1)
	{
		while ((ch = getchar()) != '\n' && ch != EOF);
	}
    printf("Número de filhos: ");
    scanf("%d", &pessoa[i].nfilhos);
    scanf("%c", &c);

    pessoa[i].cont = 1;
    printf("\nFuncionário cadastrado com sussesso. Pressione enter para continuar");
    fflush(stdin);
    getc(stdin);

}

///cadastro cargo
void cadastroCargo(){
    int i = 1;
    char ch;
    char *c;
    while(carg[i].valor!=0){
        i++;
    }

    system ("cls");
    printf("====================================//==================================\n");
    printf("\t\tCadastro de Cargos\n");
    printf("Nome do Cargo: ");
    fgets(carg[i].nomeCargo, 16, stdin);
    strtok(carg[i].nomeCargo, "\n");
	if (strlen(carg[i].nomeCargo) ==  15- 1)
	{
		while ((ch = getchar()) != '\n' && ch != EOF);
	}

    printf("Descrição do Cargo: ");
    fgets(carg[i].descricao, 200, stdin);
    strtok(carg[i].descricao, "\n");
	if (strlen(carg[i].descricao) ==  200 - 1)
	{
		while ((ch = getchar()) != '\n' && ch != EOF);
	}
    printf("Valor: ");
    scanf("%f", &carg[i].valor);
    scanf("%c", &c);
    printf("\nCargo cadastrado com sussesso. Pressione enter para continuar");
    fflush(stdin);
    getc(stdin);

}

///menu

void menu(){
    int opcao, opcao2;
    char *c;
    bool sair = false;

    while(sair==false){
        system("cls");
        printf("====================================//==================================\n");
        printf("\t\tTema 12: Folha de Pagamento\n");
        printf("1 - Cadastro de Cargos\n2 - Cadastro de Funcionários\n3 - Cadastro de Folha de Pagamento\n4 - Cadastrar itens na folha\n5 - Gerar relatórios\n6 - Editar ou excluir dado\n7 - Salvar dados em arquivos .txt\n8 - sair");
        printf("\nO que deseja fazer?: ");
        fflush(stdin);
        scanf(" %d", &opcao);
        fflush(stdin);

        switch(opcao){
            case 1: cadastroCargo();
                break;
            case 2: cadastroFunc();
                break;
            case 3: cadastroFolhaPag();
                break;
            case 4: itens();
                break;
            case 5: gerarRelatorio();
                break;
            case 6:  while(sair==false){
                system("cls");
                printf("====================================//==================================\n");
                printf("1 - Funcionários\n2 - Folhas de pagamento\n3 - Cargos\n4 - Cancelar");
                printf("\nSelecione o que deseja editar/excluir: ");
                scanf(" %d", &opcao2);
                scanf("%c", &c);
                switch(opcao2){
                    case 1: editarFunc();
                        break;
                    case 2: editarFolha();
                        break;
                    case 3: editarCargo();
                        break;
                    case 4: return menu();
                        break;
                    default: printf("Escolha uma das opções. Pressione enter para continuar\n\n");
                        fflush(stdin);
                        getc(stdin);
                }
            }
                break;
            case 7:
                salvarDados();
                break;
            case 8: printf("Tenha um ótimo dia!\n\n");
                sair = true;
                break;
            default: printf("Escolha uma das opções. Pressione enter para continuar\n\n");
                fflush(stdin);
                getc(stdin);
        }

    }



}

///funcionário

void Funcionario (){
    system("cls");
    printf("Tabela de Funcionários\n\n");
    printf("\tNome\t\tCargo\n");
    for (int i=1; i<11; i++) {
        if (pessoa[i].cont==0){
            break;
        }
        printf ("%d\t%s\t\t%s\n",i,pessoa[i].nome,pessoa[i].funcCargo.nomeCargo);
    }
    printf("Pressione enter para continuar");
    fflush(stdin);
    getc(stdin);
}


///cadastro folha pagamento


void cadastroFolhaPag(){
    int i = 1;
    float aux;
    int escolhaFunc;
    int opcao;
    char *c;
    bool continuar = false;
    bool situacao = false;
    system("cls");
    if(pessoa[1].cont==0 && pessoa[2].cont == 0){
        printf("Nenhum funcionário cadastrado. Digite enter para continuar");
        fflush(stdin);
        getc(stdin);
        return menu();
    }

    while (continuar ==false){
        printf ("1 - Registrar folha de pagamento individual\n2 - Registrar folha de pagamento em geral\n3 - Reprocessar folha de pagamento");
        printf ("\nSelecione uma opção: ");
        scanf ("%d", &opcao);

        switch (opcao){

                case 1: continuar=true;
                    break;
                case 2: return cadastroAutomatico ();
                    break;
                case 3: return reprocessarFolha();
                    break;

                default: printf("Escolha uma das opções. Pressione enter para continuar\n\n");
                    fflush(stdin);
                    getc(stdin);
        }
    }
    while(folha[i].situacao != 0){
        i++;
    }
    system ("cls");
    printf("====================================//==================================\n");
    printf("\t\tCadastro de Folha de Pagamento\n");
    printf("Mês de faturamento: ");
    scanf("%d", &folha[i].mesFat.mes);
    scanf("%c", &c);
    printf("\nFuncionários\n");

    for(int x = 1; x<11; x++){
        if(pessoa[x].cont == 0 &&  pessoa[x+1].cont == 0){
            break;
        }
        if(pessoa[x].cont == 0){
            x++;
        }
        printf("%d - %s\n", x, pessoa[x].nome);
    }
    printf("Selecione o funcionário: ");
    scanf("%d", &escolhaFunc);
    scanf("%c", &c);
    strcpy(folha[i].func.nome, pessoa[escolhaFunc].nome);
    strcpy(folha[i].func.contato, pessoa[escolhaFunc].contato);
    strcpy(folha[i].func.funcCargo.nomeCargo,  pessoa[escolhaFunc].funcCargo.nomeCargo);
    strcpy(folha[i].func.cpf, pessoa[escolhaFunc].cpf);
    folha[i].func.nfilhos = pessoa[escolhaFunc].nfilhos;
    folha[i].func.admicao.mes = pessoa[escolhaFunc].admicao.mes;
    folha[i].func.admicao.dia = pessoa[escolhaFunc].admicao.dia;
    folha[i].func.admicao.ano = pessoa[escolhaFunc].admicao.ano;
    folha[i].func.funcCargo.valor = pessoa[escolhaFunc].funcCargo.valor;
    folha[i].total = folha[i].func.funcCargo.valor + AUX_ALI;
    aux = folha[i].func.nfilhos*AUX_FIL;
    folha[i].total+=aux;
    folha[i].func.cont = pessoa[escolhaFunc].cont;
    if (folha[i].total >= 5000) {
        folha[i].total -= (folha[i].total*0.05);}
    folha[i].total -= (folha[i].total*0.075);


    printf("\nSituação");
    while(situacao == false){
        printf("\n1 - Em aberto\n2 - Pago\nSelecione uma opção: ");
        fflush(stdin);
        scanf("%d", &folha[i].situacao);

        if(folha[i].situacao == 1 || folha[i].situacao == 2){
            situacao = true;
        }
        else{
            printf("\nSelecione uma das opções listadas");
        }
    }

    printf("\nFolha cadastrada com sucesso. Pressione enter para continuar.");
    fflush(stdin);
    getc(stdin);



}

///itens
void itens(){
    int escolhaMes;
    int escolhaFunc;
    int i =1, x = 1;
    char *c;
    char ch;
    bool condicao = false;
    system("cls");
    if(folha[1].situacao == 0 && folha[2].situacao == 0){
        printf("Nenhuma folha cadastrada. Digite enter para continuar");
        fflush(stdin);
        getc(stdin);
        return menu();
    }

    printf("====================================//==================================\n");
    printf("\t\tCadastro de Itens na Folha\n");
    printf("Digite um mês de referência: ");
    scanf(" %d", &escolhaMes);
    scanf("%c", &c);


    for(int y = 1; y<21; y++){

        if(folha[y].mesFat.mes == escolhaMes){
            printf("%d - %s\n",x, folha[y].func.nome);
        }
    }

    printf("Selecione um funcionário: ");
    scanf("%d", &escolhaFunc);
    scanf("%c", &c);
    i = 1;
    while(folha[escolhaFunc].itemFolha[i].tipoLan != 0){
        i++;
    }
    printf("Descrição do item: ");
    fgets(folha[escolhaFunc].itemFolha[i].descricaoItem, 200, stdin);
    strtok(folha[escolhaFunc].itemFolha[i].descricaoItem, "\n");
	if (strlen(folha[escolhaFunc].itemFolha[i].descricaoItem) == 200 - 1)
	{
		while ((ch = getchar()) != '\n' && ch != EOF);
	}
    printf("Valor do Item: ");
    scanf ("%f",&folha[escolhaFunc].itemFolha[i].valorItem);
    scanf("%c", &c);

    while (condicao==false){
        printf ("1 - Receita\n2 - Despesa\nSelecione uma das opções: ");
        scanf ("%d", &folha[escolhaFunc].itemFolha[i].tipoLan);
        scanf("%c", &c);

        if (folha[escolhaFunc].itemFolha[i].tipoLan==1){
            folha[escolhaFunc].total += folha[escolhaFunc].itemFolha[i].valorItem;
            condicao=true;
        }
        else{
            if (folha[escolhaFunc].itemFolha[i].tipoLan==2) {
                folha[escolhaFunc].total -= folha[escolhaFunc].itemFolha[i].valorItem;
                condicao=true;

            }
            else {
                condicao=false;
            }
        }
    }

    printf("\nItem cadastrado com sucesso. Pressione enter para continuar!");
    fflush(stdin);
    getc(stdin);
}

///cadastro automatico

void cadastroAutomatico () {
    int x = 1, escolhaMes;
    float aux;
    char *c;
    printf ("Mês de Referencia: ");
    scanf ("%d", &escolhaMes);
    scanf ("%c", &c);


    for (int i = 1; i<21; i++)
{
        while(folha[i].situacao != 0){
            i++;
        }
        if (pessoa[x].cont==0 && pessoa[x+1].cont == 0){
            break;
        }
        folha[i].mesFat.mes=escolhaMes;
        strcpy(folha[i].func.nome, pessoa[x].nome);
        strcpy(folha[i].func.contato, pessoa[x].contato);
        strcpy(folha[i].func.funcCargo.nomeCargo,  pessoa[x].funcCargo.nomeCargo);
        strcpy(folha[i].func.cpf, pessoa[x].cpf);
        folha[i].func.nfilhos = pessoa[x].nfilhos;
        folha[i].func.admicao.mes = pessoa[x].admicao.mes;
        folha[i].func.admicao.dia = pessoa[x].admicao.dia;
        folha[i].func.admicao.ano = pessoa[x].admicao.ano;
        folha[i].func.funcCargo.valor = pessoa[x].funcCargo.valor;
        folha[i].total = folha[i].func.funcCargo.valor + AUX_ALI;
        aux = folha[i].func.nfilhos*AUX_FIL;
        folha[i].total+=aux;
        folha[i].func.cont =1;
        if (folha[i].total >= 5000) {
            folha[i].total -= (folha[i].total*0.05);}
        folha[i].total -= (folha[i].total*0.075);
        folha[i].situacao = 1;

        x++;

    }

    printf("\nFolhas cadastradas com sucesso. Pressione enter para continuar.");
    fflush(stdin);
    getc(stdin);
}

void MaiorSalario () {
    float maior;
    int i=1;
    system("cls");

    maior=folha[i].func.funcCargo.valor;


    for (i=1; i<21; i++){
        if(maior<folha[i].func.funcCargo.valor){
            maior=folha[i].func.funcCargo.valor;
        }
    }
    printf ("O maior salário é: %.2f",maior);
    printf("\nPressione enter para continuar");
    fflush(stdin);
    getc(stdin);
}


void situacaoDAfolha () {
    char situacao[15];
    system("cls");
    for(int i=1;i<21; i++){
        if(folha[i].situacao==0 && folha[i+1].situacao == 0 ){
            break;
        }
        if (folha[i].situacao==1){
            strcpy (situacao,"Em aberto!");
        }
        else{
            if(folha[i].situacao==2){
                strcpy (situacao,"Fechado!");
            }

        }
        printf("Funcionário: %s - Mês: %d - Situação: %s\n",folha[i].func.nome,folha[i].mesFat.mes,situacao);
    }
    printf("\nPressione enter para continuar");
    fflush(stdin);
    getc(stdin);


}

void tabelaDEcargos () {
    system("cls");
    printf("Tabela de Cargos\n");
    printf("\n\tCargo\tValor\n");
    for (int i=1; i<11; i++) {
        if (carg[i].valor==0){
            break;
        }
        printf ("%d\t%s\t%.2f\n",i,carg[i].nomeCargo, carg[i].valor);
       }
    printf("\nPressione enter para continuar");
    fflush(stdin);
    getc(stdin);
}



void MediaDEsalarioFuncionario (){
    int i=1;
    int j=0;
    float aux;
    system ("cls");

    for (i=1; i<21; i++) {
        if(pessoa[i].funcCargo.valor==0){
            break;
        }
        j++;
        aux+=pessoa[i].funcCargo.valor;
    }

    aux=aux/j;
    printf("A média de salário é: R$ %.2f\n",aux);

    printf("\nPressione enter para continuar");
    fflush(stdin);
    getc(stdin);


}

void reprocessarFolha(){
    int escolhaFunc, escolhaFolha;
    float aux;
    system("cls");

    if(folha[1].situacao==0){
        printf("Nenhuma folha cadastrada. Pressione enter para continuar");
        fflush(stdin);
        getc(stdin);
        return cadastroFolhaPag();
    }
    printf("Folhas\n");
    for(int i = 1; i<21; i++){
        if(folha[i].situacao==0 && folha[i+1].situacao){
            break;
        }
        printf("%d - %s - Mês: %d\n", i, folha[i].func.nome, folha[i].mesFat.mes);
    }
    printf("Selecione uma folha para reprocessar: ");
    fflush(stdin);
    scanf(" %d", &escolhaFolha);
    printf("\nFuncionários\n");
    for(int x = 1; x<11; x++){
        if(pessoa[x].cont == 0){
            break;
        }
        printf("%d - %s\n", x, pessoa[x].nome);
    }
    printf("Selecione o funcionário para reprocessar na folha: ");
    scanf("%d", &escolhaFunc);
    strcpy(folha[escolhaFolha].func.nome, pessoa[escolhaFunc].nome);
    strcpy(folha[escolhaFolha].func.contato, pessoa[escolhaFunc].contato);
    strcpy(folha[escolhaFolha].func.funcCargo.nomeCargo,  pessoa[escolhaFunc].funcCargo.nomeCargo);
    strcpy(folha[escolhaFolha].func.cpf, pessoa[escolhaFunc].cpf);
    folha[escolhaFolha].func.nfilhos = pessoa[escolhaFunc].nfilhos;
    folha[escolhaFolha].func.admicao.mes = pessoa[escolhaFunc].admicao.mes;
    folha[escolhaFolha].func.admicao.dia = pessoa[escolhaFunc].admicao.dia;
    folha[escolhaFolha].func.admicao.ano = pessoa[escolhaFunc].admicao.ano;
    folha[escolhaFolha].func.funcCargo.valor = pessoa[escolhaFunc].funcCargo.valor;
    folha[escolhaFolha].total = folha[escolhaFolha].func.funcCargo.valor + AUX_ALI;
    aux = folha[escolhaFolha].func.nfilhos*AUX_FIL;
    folha[escolhaFolha].total+=aux;
    if (folha[escolhaFolha].total >= 5000) {
        folha[escolhaFolha].total -= (folha[escolhaFolha].total*0.05);}
    folha[escolhaFolha].total -= (folha[escolhaFolha].total*0.075);

    printf("\nFolha reprocessada com sucesso. Pressione enter para continuar");
    fflush(stdin);
    getc(stdin);

}


void editarFunc(){
    bool continuar = false;
    int opcao, escolhaFunc, escolhaCarg;
    char *c;
    char ch;
    system("cls");
    if(pessoa[1].cont==0 && pessoa[2].cont == 0){
            printf("Nenhum funcionário cadastrado. Pressione enter para continuar");
            fflush(stdin);
            getc(stdin);
            return menu();
        }

    while(continuar == false){
        system("cls");
        printf("1 - Editar Funcionário\n2 - Excluir funcionário\n3 - Cancelar");
        printf("\nSelecione uma opção listada: ");
        scanf("%d", &opcao);
        scanf("%c", &c);

        switch(opcao){
            case 1:
                system("cls");
                printf("Funcionários\n");
                for(int x = 1; x<11; x++){
                    if(pessoa[x].cont == 0 && pessoa[x+1].cont == 0){
                        break;
                    }
                    if(pessoa[x].cont == 0){
                        x++;
                    }
                    printf("%d - %s\n", x, pessoa[x].nome);
                }
                printf("Selecione o funcionário: ");
                scanf("%d", &escolhaFunc);
                scanf("%c", &c);
                printf("\nNome registrado: %s\nNovo nome: ", pessoa[escolhaFunc].nome);
                fgets(pessoa[escolhaFunc].nome, 31, stdin);
                strtok(pessoa[escolhaFunc].nome, "\n");
                if (strlen(pessoa[escolhaFunc].nome) == 31 - 1){
                    while ((ch = getchar()) != '\n' && ch != EOF);
                }

                printf("\nCargo Registrado: %s\n", pessoa[escolhaFunc].funcCargo.nomeCargo);
                for(int x = 1; x<16; x++){
                    if(carg[x].valor == 0){
                        break;
                        }
                    printf("%d - %s\n", x, carg[x].nomeCargo);
                }
                printf("Selecione o novo cargo: ");
                scanf("%d", &escolhaCarg);
                scanf("%c", &c);
                strcpy(pessoa[escolhaFunc].funcCargo.nomeCargo, carg[escolhaCarg].nomeCargo);
                strtok(pessoa[escolhaFunc].funcCargo.nomeCargo, "\n");
                if (strlen(pessoa[escolhaFunc].funcCargo.nomeCargo) == 15 - 1){
                    while ((ch = getchar()) != '\n' && ch != EOF);
                }
                strcpy(pessoa[escolhaFunc].funcCargo.descricao, carg[escolhaCarg].descricao);
                strtok(pessoa[escolhaFunc].funcCargo.descricao, "\n");
                if (strlen(pessoa[escolhaFunc].funcCargo.descricao) == 200 - 1){
                    while ((ch = getchar()) != '\n' && ch != EOF);
                }
                pessoa[escolhaFunc].funcCargo.valor = carg[escolhaCarg].valor;

                printf("\nData de admição registrada: %d/%d/%d\nNova data de admição (digite no formato dd mm aaaa): ", pessoa[escolhaFunc].admicao.dia, pessoa[escolhaFunc].admicao.mes, pessoa[escolhaFunc].admicao.ano);
                scanf("%d%d%d", &pessoa[escolhaFunc].admicao.dia, &pessoa[escolhaFunc].admicao.mes, &pessoa[escolhaFunc].admicao.ano);
                scanf("%c", &c);

                printf("\nCPF Registrado: %s\nNovo CPF: ", pessoa[escolhaFunc].cpf);
                fgets(pessoa[escolhaFunc].cpf, 15, stdin);
                strtok(pessoa[escolhaFunc].cpf, "\n");
                if (strlen(pessoa[escolhaFunc].cpf) == 15 - 1)
                {
                    while ((ch = getchar()) != '\n' && ch != EOF);
                }

                printf("\nContado Registrado: %s\nNovo contato: ", pessoa[escolhaFunc].contato);
                fgets(pessoa[escolhaFunc].contato, 50, stdin);
                strtok(pessoa[escolhaFunc].contato, "\n");
                if (strlen(pessoa[escolhaFunc].nome) == 31 - 1){
                    while ((ch = getchar()) != '\n' && ch != EOF);
                }

                printf("\nNúmero de filhos: %d\nNovo número de filhos: ", pessoa[escolhaFunc].nfilhos);
                scanf("%d", &pessoa[escolhaFunc].nfilhos);
                scanf("%c", &c);

                printf("\nFuncionário editado com sucesso. Pressione enter para continuar");
                fflush(stdin);
                getc(stdin);
                continuar = true;
                break;

            case 2:
                system("cls");
                printf("Funcionários\n");
                for(int x = 1; x<11; x++){
                    if(pessoa[x].cont == 0 && pessoa[x+1].cont == 0){
                        break;
                    }
                    if(pessoa[x].cont == 0){
                        x++;
                    }
                printf("%d - %s\n", x, pessoa[x].nome);
                }
                printf("Selecione o funcionário: ");
                scanf("%d", &escolhaFunc);
                scanf("%c", &c);

                for(int i = 1; i<21; i++){
                    if(folha[i].func.cont == pessoa[escolhaFunc].cont){
                        printf("Não é possivel excluir esse funcionário. Ele possui registro em folha de pagamento! Pressione enter para continuar");
                        fflush(stdin);
                        getc(stdin);
                        return menu();
                    }
                }
                pessoa[escolhaFunc].cont=0;
                printf("\nFuncionário excluido com sucesso. Pressione enter para continuar");
                fflush(stdin);
                getc(stdin);
                continuar = true;
                break;
            case 3: return menu();
                break;


        }
    }


}void editarFolha(){
    bool continuar = false;
    bool situacao = false;
    int opcao, escolhaFolha;
    char *c;
    char ch;
    system("cls");
    if(folha[1].situacao == 0 && folha[2].situacao == 0){
            printf("Nenhuma folha cadastrado. Pressione enter para continuar");
            fflush(stdin);
            getc(stdin);
            return menu();
        }

    while(continuar == false){
        system("cls");
        printf("1 - Editar folha de pagamento\n2 - Excluir folha de pagamento\n3 - Cancelar");
        printf("\nSelecione uma opção listada: ");
        scanf("%d", &opcao);
        scanf("%c", &c);

        switch(opcao){
            case 1:
                system("cls");
                printf("Folhas\n");
                for(int x = 1; x<11; x++){
                    if(folha[x].situacao == 0 && folha[x+1].situacao == 0 ){
                        break;
                    }
                    if (folha[x].situacao == 0){
                        x++;
                    }
                    printf("%d - %s - Mês: %d\n", x, folha[x].func.nome, folha[x].mesFat.mes);
                }
                printf("Selecione uma folha: ");
                scanf("%d", &escolhaFolha);
                scanf("%c", &c);

                printf("\nMês de faturamento da folha: %d\nNovo mês de faturamento: ", folha[escolhaFolha].mesFat.mes);
                scanf("%d", &folha[escolhaFolha].mesFat.mes);
                scanf("%c", &c);

                if(folha[escolhaFolha].situacao == 1){
                    printf("\nSituação atual da folha: Em aberto");
                }
                else{
                    printf("\nSituação atual da folha: Fechado");
                }
                folha[escolhaFolha].situacao = 0;

                while(situacao == false){
                    printf("\n1 - Em aberto\n2 - Fechado\nSelecione a nova situação: ");
                    scanf("%d", &folha[escolhaFolha].situacao);
                    scanf("%c", &c);

                    if(folha[escolhaFolha].situacao == 1 || folha[escolhaFolha].situacao == 2){
                        situacao = true;
                    }

                }

                printf("\nFolha editada com sucesso. Pressione enter para continuar");
                fflush(stdin);
                getc(stdin);
                continuar = true;
                break;

            case 2:
                printf("Folhas\n");
                for(int x = 1; x<11; x++){
                    if(folha[x].situacao == 0 && folha[x+1].situacao == 0 ){
                        break;
                    }
                    if (folha[x].situacao == 0){
                        x++;
                    }
                    printf("%d - %s - Mês: %d\n", x, folha[x].func.nome, folha[x].mesFat.mes);
                }
                printf("Selecione uma folha: ");
                scanf("%d", &escolhaFolha);
                scanf("%c", &c);

                for(int x = 1; x < 21; x++){
                    if(folha[escolhaFolha].itemFolha[x].tipoLan != 0){
                        printf("Não é possivel excluir essa folha. Ela possui registro de item! Pressione enter para continuar");
                        fflush(stdin);
                        getc(stdin);
                        return menu();
                    }
                }

                folha[escolhaFolha].func.funcCargo.valor = 0;
                folha[escolhaFolha].func.cont = 0;
                folha[escolhaFolha].situacao=0;
                printf("\nFolha excluida com sucesso. Pressione enter para continuar");
                fflush(stdin);
                getc(stdin);
                continuar = true;
                break;

            case 3: continuar = true;
                break;

            default: continuar = false;
        }
    }
}
void editarCargo(){
    bool continuar = false;
    int opcao, escolhaCarg;
    char *c;
    char  ch;
    system("cls");

    if(carg[1].valor == 0 && carg[2].valor == 0){
            printf("Nenhum cargo registrado. Pressione enter para continuar");
            fflush(stdin);
            getc(stdin);
            return menu();
        }

    while(continuar == false){
        system ("cls");
        printf("1 - Editar Cargo\n2 - Excluir Cargo\n3 - Cancelar");
        printf("\nSelecione uma opção listada: ");
        scanf("%d", &opcao);
        scanf("%c", &c);

        switch(opcao){
            case 1:
                printf("\nCargos\n");
                for(int i = 1; i <16; i++){
                    if(carg[i].valor == 0 && carg[i+1].valor == 0){
                        break;
                    }
                    printf("%d - %s\n", i, carg[i].nomeCargo);
                }
                printf("Selecione um cargo: ");
                scanf("%d", &escolhaCarg);
                scanf("%c", &c);

                printf("\nNome do cargo: %s\nNovo nome do cargo: ", carg[escolhaCarg].nomeCargo);
                fgets(carg[escolhaCarg].nomeCargo, 16, stdin);
                strtok(carg[escolhaCarg].nomeCargo, "\n");
                if (strlen(carg[escolhaCarg].nomeCargo) == 16 - 1){
                    while ((ch = getchar()) != '\n' && ch != EOF);
                }

                printf("\nDescrição do cargo: %s\nNova Descrição: ", carg[escolhaCarg].descricao);
                fgets(carg[escolhaCarg].descricao, 200, stdin);
                strtok(carg[escolhaCarg].descricao, "\n");
                if (strlen(carg[escolhaCarg].descricao) == 200 - 1){
                    while ((ch = getchar()) != '\n' && ch != EOF);
                }

                printf("\nValor do cargo: R$ %.2f\nNovo valor: ", carg[escolhaCarg].valor);
                scanf("%f", &carg[escolhaCarg].valor);
                scanf("%c", &c);

                printf("Cargo editado com sucesso. Pressione enter para continuar.");
                fflush(stdin);
                getc(stdin);
                break;

            case 2:
                printf("\nCargos\n");
                for(int i = 1; i <16; i++){
                    if(carg[i].valor == 0 && carg[i+1].valor == 0){
                        break;
                    }
                    printf("%d - %s\n", i, carg[i].nomeCargo);
                }
                printf("Selecione um cargo: ");
                scanf("%d", &escolhaCarg);
                scanf("%c", &c);

                for(int i = 1; i<15; i++){
                    if(folha[i].func.funcCargo.valor == carg[escolhaCarg].valor){
                        printf("Não é possível excluir esse cargo. Ele possui registro em folha de pagamento. Pressione enter para continuar");
                        fflush(stdin);
                        getc(stdin);
                        return menu();
                    }
                }

                carg[escolhaCarg].valor = 0;
                printf("\nCargo excluido com sucesso. Pressione enter para continuar");
                fflush(stdin);
                getc(stdin);
                continuar = true;
                break;

            case 3: continuar = true;
                break;

            default: continuar = false;


    }
    }



}

void salvarDados(){
    bool sair = false;
    char *c;
    int opcao, i = 1;
    FILE *file;



    while(sair == false){
        system("cls");
        printf("1 - Funcionários\n2 - Cargos\n3 - Voltar\nO que deseja fazer?: ");
        scanf("%d", &opcao);
        scanf("%c", &c);

        switch(opcao){
            case 1:
                file = fopen("Funcionarios.txt", "w");
                if(file == NULL){
                    printf("Não foi possível abrir o arquivo.");
                    getc(stdin);
                }
                    while(pessoa[i].cont != 0){
                        fprintf(file,"===================================//=================================");
                        fprintf(file, "\n");
                        fputs(pessoa[i].nome, file);
                        fprintf(file, "\n");
                        fputs(pessoa[i].funcCargo.nomeCargo, file);
                        fprintf(file, "\n");
                        fputs(pessoa[i].cpf, file);
                        fprintf(file, "\n");
                        fputs(pessoa[i].contato, file);
                        fprintf(file, "\n");
                        fprintf(file, "Data de admição: ");
                        fprintf(file, "%d/%d/%d", pessoa[i].admicao.dia, pessoa[i].admicao.mes, pessoa[i].admicao.ano);
                        fprintf(file, "\n");
                        fprintf(file, "Numero de filhos: %d", pessoa[i].nfilhos);
                        fprintf(file, "\n");
                        i++;
                    }
                    fclose(file);
                    printf("\nArquivo salvo no diretório do projeto. Pressione enter para continuar");
                    fflush(stdin);
                    getc(stdin);
                break;
            case 2:
                file = fopen("Cargos.txt", "w");
                if(file == NULL){
                    printf("Não foi possível abrir o arquivo.");
                    getc(stdin);
                }
                    while(carg[i].valor != 0){
                        fprintf(file,"===================================//=================================");
                        fprintf(file, "\n");
                        fputs(carg[i].nomeCargo, file);
                        fprintf(file, "\n");
                        fputs(carg[i].descricao, file);
                        fprintf(file, "\n");
                        fprintf(file, "Valor: %.2f", carg[i].valor);
                        fprintf(file, "\n");
                        i++;
                    }
                    fclose(file);
                    printf("\nArquivo salvo no diretório do projeto. Pressione enter para continuar");
                    fflush(stdin);
                    getc(stdin);
                break;
            case 3: sair= true;
                break;


        }
    }

}

void totalFOLHAmes (){
    int escolhaMes;
    char *c;
    float aux =0;
    system("cls");
    printf("Mês de referência: ");
    scanf("%d", &escolhaMes);
    scanf("%c", &c);
    printf("\nFuncionários com folha nesse mês:\n");

    for(int i=1; i<21; i++){
        if(folha[i].mesFat.mes==escolhaMes){
            printf ("%d - %s\n",i,folha[i].func.nome);
            aux += folha[i].total;
        }



 }
    printf("Total do Mês: %.2f",aux);

    printf("\n\nPressione enter para continuar");
    fflush(stdin);
    getc(stdin);
}
