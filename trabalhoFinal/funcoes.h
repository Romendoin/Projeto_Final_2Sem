#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

typedef struct{
    char descricaoItem[200];
    float valorItem;
    int tipoLan;
}item;

typedef struct{
    int dia, mes, ano;
}data;

typedef struct{
    char nomeCargo[15];
    char descricao[200];
    float valor;
}cargo;
cargo carg[16];

typedef struct{
    char nome[30];
    data admicao;
    cargo funcCargo;
    char contato [20];
    int nfilhos;
    char cpf[15];
    int cont;
}funcionario;
funcionario pessoa[11];

typedef struct{
    data mesFat;
    funcionario func;
    float total;
    int situacao;
    item itemFolha[11];
}folhaPag;
folhaPag folha[21];

void salvarDados();
void editarCargo();
void editarFolha();
void editarFunc();
void cadastroAutomatico ();
void itens();
void cadastroFolhaPag();
void menu();
void cadastroFunc();
void cadastroCargo();
void gerarRelatorio();
void reprocessarFolha();
//sub-menus do gerar relatório
void Funcionario ();
void tabelaDEcargos ();
void totalFOLHAmes ();
void situacaoDAfolha ();
void MaiorSalario ();
void MediaDEsalarioFuncionario ();


#endif // FUNCOES_H_INCLUDED
