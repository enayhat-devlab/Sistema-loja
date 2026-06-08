#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


//cliente
int i=0;
int cont=0;
//produto
int i_prod=0;
int cont_prod=0;
//pedido
int i_ped=0;
int cont_ped=0;
    

typedef struct{
    char nome[50];
    char email[100];
}cliente;
typedef struct nocliente{
    cliente dado_cli;
    struct nocliente *prox_cli;
}nocliente;
typedef struct{
    char descrição_cli[100];
    int quantcliente;
    nocliente *iniciocliente;
}descritor_cli;


typedef struct{
    char nome_produto[50];
    float preço;
    int codigo;
    char tamanho[10];
    char cor[10];
    char material[20];
    int estoque;
}produto;
typedef struct noproduto{
    produto dado_pro;
    struct noproduto *prox_pro;
}noproduto;
typedef struct{
    char descrição_pro[100];
    int quantproduto;
    noproduto *inicioproduto;
}descritor_pro;


typedef struct{
    char email_cliente[50];
    int data; 
    int codigo_produto;
    int quantidades;
    int total_produto;
    float valor_total;
    char forma_pagamento[50];
}pedido;
typedef struct nopedido{
    pedido dado_ped;
    struct nopedido *prox_ped;
}nopedido;
typedef struct{
    char descrição_ped[100];
    int quantpedido;
    nopedido *iniciopedido;
}descritor_ped;

void limparBuffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF); }


cliente cadastrarcliente(cliente cad_c[], int total_cliente){
    cliente c1;
    int email_existente=0;

    printf("\n\n === Cadastrar cliente ===\n");
    printf("\nInforme seu nome: ");
    limparBuffer();
    fgets(c1.nome, sizeof(c1.nome),stdin);
    c1.nome[strcspn(c1.nome, "\n")] = '\0';
    printf("\nInforme seu email: ");
    fgets(c1.email, sizeof(c1.email), stdin);
    c1.email[strcspn(c1.email, "\n")] = '\0';

    for(int j=0; j<total_cliente; j++){
        if(strcmp(cad_c[j].email,c1.email) == 0){
            email_existente=1;
            break;
        }
    }
    if(email_existente){
        printf("\nERRO:Este email já está cadastrado!\n");
        strcpy(c1.email, " ");
    }
    else{
        printf("\nCliente cadastrado com sucesso!\n");
    }
    return c1;
}


produto cadastrarproduto(){
    produto p1;

    printf("\n===Cadastrar produto ===\n");
    limparBuffer();
    printf("Informe o nome do produto: ");
    fgets(p1.nome_produto, sizeof(p1.nome_produto), stdin);
    p1.nome_produto[strcspn(p1.nome_produto, "\n")] = '\0';
    printf("Informe o preço do produto: ");
    scanf("%f", &p1.preço);
    limparBuffer();
    printf("Informe o codigo do produto: ");
    scanf("%d", &p1.codigo);
    limparBuffer();
    printf("Informe o tamanho do produto: ");
    scanf("%9[^\n]", p1.tamanho);
    limparBuffer();
    printf("Informe a cor do produto: ");
    fgets(p1.cor, sizeof(p1.cor), stdin);
    p1.cor[strcspn(p1.cor,"\n")] ='\0';
    printf("Informe o material do produto: ");
    fgets(p1.material, sizeof(p1.material), stdin);
    p1.material[strcspn(p1.material,"\n")] ='\0';
    printf("Informe a quantidade no estoque: ");
    scanf("%d", &p1.estoque);
    limparBuffer();
    cont_prod++;
    return p1;
}


pedido fazerpedido(cliente cad_c[], int total_cliente){
    pedido ped;
    int cliente_encontrado=0;
    printf("\n=== Fazer pedido ===\n");
    limparBuffer();
    printf("Informe o email do cliente(ja cadastrado): ");
    fgets(ped.email_cliente, sizeof(ped.email_cliente), stdin);
    ped.email_cliente[strcspn(ped.email_cliente,"\n")] ='\0';
    for(int j=0; j<total_cliente; j++){
        if(strcmp(cad_c[j].email, ped.email_cliente) ==0){
            cliente_encontrado=1;
            break;
        }
    }
    if(!cliente_encontrado){
        printf("\nERRO:Este email não foi cadastrado!\nPedido cancelado!\n");
        strcpy(ped.email_cliente, " ");
        return ped;
    }
    printf("Infome a data da compra(ex:21042006): ");
    scanf("%d", &ped.data);
    limparBuffer();
    printf("Informe a quantidade: ");
    scanf("%d", &ped.quantidades);
    limparBuffer();
    printf("Informe a quantidade total de produtos: ");
    scanf("%d", &ped.total_produto);
    limparBuffer();
    printf("Informe o valor total das compras: ");
    scanf("%f", &ped.valor_total);
    limparBuffer();
    printf("Informe a forma de pagamento: ");
    fgets(ped.forma_pagamento, sizeof(ped.forma_pagamento), stdin);
    ped.forma_pagamento[strcspn(ped.forma_pagamento,"\n")] ='\0';
    cont_ped++;
    return ped;
}


void exibircliente(cliente cad_c[]){
    printf("\n=== Exibir cliente cadastardo ===\n");
    for(int j=0; j<cont; j++){
        printf("\nDados do cliente: %d", j+1);
        printf("\nNome...:%s",cad_c[j].nome);
        printf("Email...:%s\n",cad_c[j].email);
    }
}


void exibirprodutos(produto cad_p[]){
    printf("\n=== Exibir produtos cadastrados ===\n");
    for(int p=0; p<cont_prod; p++){
        printf("\nDados de cliente %d\n", p+1);
        printf("Nome do produto...: %s\n",cad_p[p].nome_produto);
        printf("Codigo do produto...: %d\n",cad_p[p].codigo);
        printf("Preço do produto...: %.2f\n",cad_p[p].preço);
        printf("Tamanho do produto...: %s\n",cad_p[p].tamanho);
        printf("Cor do produto...: %s\n",cad_p[p].cor);
        printf("Material do produto...: %s\n",cad_p[p].material);
        printf("Estoque do produto...: %d\n",cad_p[p].estoque);
    }
}


void exibirpedido(pedido ped_p[]){
    printf("\n=== Exibir pedido ===\n");
    for(int x=0; x<cont_ped; x++){
        printf("\nEmail do cliente...: %s\n", ped_p[x].email_cliente);
        printf("Data da compra...: %d\n", ped_p[x].data);
        printf("Codigo do produto...: %d\n",ped_p[x].codigo_produto);
        printf("Quantidade de cada produto...: %d\n",ped_p[x].quantidades);
        printf("Quantidade total dos produots...: %d\n",ped_p[x].total_produto);
        printf("Valor total da compra...: %.2f\n",ped_p[x].valor_total);
        printf("Forma de pagamento...: %s\n",ped_p[x].forma_pagamento);
    }
}


void mostrarcliente(descritor_cli *d_cli, cliente vet_cli[], int total){
    d_cli -> iniciocliente=NULL;
    nocliente *ultimo_cli = NULL;
    for(int i=0; i<total; i++){
        nocliente *novo_cli =(nocliente*) malloc(sizeof(nocliente));
        novo_cli -> dado_cli = vet_cli[i];
        novo_cli -> prox_cli =NULL;
        if(d_cli -> iniciocliente ==NULL){
            d_cli -> iniciocliente = novo_cli;
        }
        else{
            ultimo_cli -> prox_cli = novo_cli;
        }
        ultimo_cli = novo_cli;
    }
    printf("\n=== Lista de cliente ===\n");
    nocliente *aux_cli = d_cli ->iniciocliente;
    int n=1;
    while(aux_cli != NULL){
        printf("\nCliente %d \n", n++);
        printf("Nome: %s\n", aux_cli -> dado_cli.nome);
        printf("Email: %s\n", aux_cli -> dado_cli.email);
        aux_cli = aux_cli -> prox_cli;
    }
}


void mostrarlistaproduto(descritor_pro *d_pro, produto vet_pro[], int total){
    d_pro -> inicioproduto =NULL;
    noproduto *ultimo_pro =NULL;
    for(int i=0; i<total; i++){
        noproduto *novo_pro =(noproduto*) malloc(sizeof(noproduto));
        if(novo_pro ==NULL){
            printf("ERRO de alocação de memoria para produto.\n");
            return;
        }
        novo_pro -> dado_pro=vet_pro[i];
        novo_pro -> prox_pro=NULL;
        if(d_pro-> inicioproduto==NULL){
            d_pro-> inicioproduto=novo_pro;
        }
        else{
            ultimo_pro -> prox_pro= novo_pro;
        }
        ultimo_pro= novo_pro;
    }
    printf("\n=== Lista de produto ===\n");
    noproduto *aux_pro = d_pro -> inicioproduto;
    int n=1;
    while(aux_pro != NULL){
        printf("\nProduto %d\n", n++);
        printf("Nome do produto: %s\n",aux_pro-> dado_pro.nome_produto);
        printf("Codigo do produto: %d\n",aux_pro-> dado_pro.codigo);
        printf("Preço do produto: %.2f\n",aux_pro-> dado_pro.preço);
        printf("Tamanho do produto: %s\n",aux_pro-> dado_pro.tamanho);
        printf("Cor do produto: %s\n",aux_pro-> dado_pro.cor);
        printf("Material do produto: %s\n",aux_pro-> dado_pro.material);
        printf("Estoque do produto: %d\n",aux_pro-> dado_pro.estoque);
        aux_pro = aux_pro -> prox_pro;
    }
}


void mostrarlistapedido(descritor_ped *d_ped, pedido vet_ped[], int total){
    d_ped -> iniciopedido =NULL;
    nopedido *ultimo_ped = NULL;
    for(int i=0; i<total; i++){
        nopedido *novo_ped = (nopedido*) malloc(sizeof(nopedido));
        if(novo_ped == NULL){
            printf("ERRO de alocação de memoria para pedido!\n");
            return;
        }
        novo_ped -> dado_ped = vet_ped[i];
        novo_ped -> prox_ped = NULL;
        if(d_ped -> iniciopedido == NULL){
            d_ped-> iniciopedido = novo_ped;
        }
        else{
            ultimo_ped->prox_ped=novo_ped;
            ultimo_ped=novo_ped;
        }
        ultimo_ped=novo_ped;
    }
    printf("\n===Lista de pedidos ===\n");
    nopedido *aux_ped = d_ped->iniciopedido;
    int n=1;
    while(aux_ped != NULL){
        printf("\nPedido %d\n", n++);
        printf("Email do cliente...: %s\n", aux_ped -> dado_ped.email_cliente);
        printf("Data da compra...: %d\n", aux_ped -> dado_ped.data);
        printf("Codigo do produto...: %d\n", aux_ped -> dado_ped.codigo_produto);
        printf("Quantidade de cada compra...: %.2f\n", aux_ped -> dado_ped.quantidades);
        printf("Quatidade total de produtos...: %d\n", aux_ped -> dado_ped.total_produto);
        printf("Valor total da compra...: %.2f\n", aux_ped -> dado_ped.valor_total);
        printf("Forma de pagamento...: %s\n", aux_ped -> dado_ped.forma_pagamento);
        aux_ped = aux_ped->prox_ped;
    }
}


void relatoriocliente(cliente cad_c[], int total){
    FILE *arq;
    int result;
    arq = fopen("cliente.txt", "wt");
    if(arq==NULL){
        printf("Problema na criação do arquivo cliente.txt\n");
        return;
    }
    for(int i=0; i<total; i++){
        result=fprintf(arq,"Cliente %d\nNome...: %s\nEmail...%s\n-----\n", i+1, cad_c[i].nome,cad_c[i].email);
        if(result==EOF){
            printf("ERRO na gravação do cliente %d\n", i+1);
        }
        fclose(arq);
        printf("Relatorio de cliente gerado com sucesso em 'cilente.txt'\n");
    }
}


void relatorioproduto(produto cad_p[], int total){
    FILE *arq;
    int result;
    arq = fopen("produto.txt","wt");
    if(arq == NULL){
        printf("Problema a criação do arquivo produto.txt\n");
        return;
    }
    for(int i=0; i<total; i++){
        result = fprintf(arq, "Produto %d\nNome...: %s\nPreço...: %.2f\nCodigo...: %d\nCor...: %s\nMaterial...:%s\nEstoque...: %d\n-----\n",
            i+1,cad_p[i].nome_produto,cad_p[i].preço,cad_p[i].codigo,cad_p[i].cor,cad_p[i].material,cad_p[i].estoque);
    if(result==EOF){
        printf("ERRO na gravação do produto", i+1);
    }        
    fclose(arq);
    printf("Relatorio de produtos gerado com sucesso em 'produto.txt'\n");
    }
}


void relatoriopedido(pedido ped_p[], int total){
    FILE *arq;
    int result;
    arq = fopen("pedido.txt","wt");
    if(arq==NULL){
        printf("Problema na criação do arquivo pedido.txt\n");
        return;
    }
    for(int i=0; i<total; i++){
        result = fprintf(arq,"Pedido %d\nEmail do cliente...: %s\nData...: %d\nCodigodo produto...: %d\nQuantidade comprada...: %d\nTotal de produtos...: %d\nValor total...: %.2f\nFoorma de pagamento...: %s\n-----\n",
        i+1,ped_p[i].email_cliente,ped_p[i].data,ped_p[i].codigo_produto,ped_p[i].quantidades,ped_p[i].total_produto,ped_p[i].valor_total,ped_p[i].forma_pagamento);
        if(result==EOF){
            printf("ERRO na gravação do pedido", i+1);
        }
        fclose(arq);
        printf("Relatorio de pedidos gerado com sucesso em 'pedido.txt'\n");
    }
}


int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    int opc=0;
    cliente cad_c[50];
    produto cad_p[8];
    pedido ped_p[10];
    
    descritor_cli desc_cli;
    strcpy(desc_cli.descrição_cli,"Cadastro cliente");
    desc_cli.quantcliente=0;
    desc_cli.iniciocliente=NULL;
    
    descritor_pro desc_pro;
    strcpy(desc_pro.descrição_pro,"Cadastro produto");
    desc_pro.quantproduto =0;
    desc_pro.inicioproduto=NULL;
    
    descritor_ped desc_ped;
    strcpy(desc_ped.descrição_ped,"Cadastro pedido");
    desc_ped.quantpedido=0;
    desc_ped.iniciopedido=NULL;
    while(opc!=15){
        printf("Sistema de cadastro;\n");
        printf("1 - Cadastro cliente;\n");
        printf("2 - Exibir cliente cadastrado;\n");
        printf("3 - Cadastra produto;\n");
        printf("4 - Exibir produto cadastrado;\n");
        printf("5 - Fazer pedido;\n");
        printf("6 - Exibir pedido;\n");
        printf("7 - Consultar email;\n");
        printf("8 - Consultar codigo;\n");
        printf("9 - Gerar relatorio do cliente;\n");
        printf("10 - Gerar relatorio do produto;\n");
        printf("11 - Gerar relatorio do pedido;\n");
        printf("12 - Lista de nos do cliente;\n");
        printf("13 - Lista de nos do produto;\n");
        printf("14 - Lista de nos do pedido;\n");
        printf("--------------");
        printf("15 - sair");
        printf("\nDigite a opção que deseja: ");
        scanf("%d", &opc);
        switch (opc){
            case 1:
            if(i<50){
                cad_c[i]=cadastrarcliente(cad_c, cont);
                if(strcmp(cad_c[i].email," ")!=0){
                    i++;
                    cont++;
                }
            }
            else{
                printf("\nLimite de cliente atingido.\n");
            }
            desc_cli.quantcliente=cont;
            break;
            case 2:
            exibircliente(cad_c);
            break;
            case 3:
            if(i_prod<8){
                cad_p[i_prod]=cadastrarproduto();
                i_prod++;
            }
            else{
                printf("\nLimite de produtos atingido\n");
            }
            break;
            case 4:
            exibirprodutos(cad_p);
            break;
            case 5: 
            if(i_ped<10){
                ped_p[i_ped]=fazerpedido(cad_c,cont);
                if(strcmp(ped_p[i_ped].email_cliente," ")!=0){
                    i++;
                }
            }
            break;
            case 6:
            exibirpedido(ped_p);
            break;
            case 7:{
            char email_digitado[100];
            int achou_email=0;
            printf("\nDigite o email cadastrado para confirmar: ");
            limparBuffer();
            fgets(email_digitado, sizeof(email_digitado), stdin);
            email_digitado[strcspn(email_digitado, "\n")]='\0';
            for(int y=0; y<cont; y++){
                if(strcmp(cad_c[y].email, email_digitado)==0){
                    achou_email=1;
                    break;
                    
                }
            }
            if(achou_email==1){
                printf("\nEmail encontrado!\n");
            }
            else{
                printf("\nEmail não encontrado!\n");
            }
            break;
            }
            case 8:{
            int codigo_digitado;
            int achou_codigo=0;
            printf("\nDigite o codigo cadastrado para confirmar: ");
            scanf("%d", &codigo_digitado);
            limparBuffer();
            for(int z=0; z<cont_prod; z++){
                if(cad_p[z].codigo == codigo_digitado){
                    achou_codigo=1;
                    break;
                }
            }
            if(achou_codigo==1){
                printf("Codigo encontrado\n");
            }
            break;
            }
            case 9:
            relatoriocliente(cad_c, cont);
            break;
            case 10:
            relatorioproduto(cad_p, cont_prod);
            break;
            case 11:
            relatoriopedido(ped_p, cont_ped);
            break;
            case 12:
            mostrarcliente(&desc_cli,cad_c, cont);
            break;
            case 13:
            mostrarlistaproduto(&desc_pro, cad_p, cont_prod);
            break;
            case 14:
            mostrarlistapedido(&desc_ped, ped_p, cont_ped);
            break;
            case 15:
            printf("Saindo do sistema\n");
            break;
            default:
            printf("\nOPÇÃO INVALIDA!\n");
            break;
        }
    }
    return 0;
}
