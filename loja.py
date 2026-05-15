from rich import print
from rich.panel import Panel

def divisor(msg):
       
        print('=-=' *30)
        print(f' {msg}')
        print('=-=' *30)

"""
cadastro de clientes 
"""
class Cliente: 

    def __init__(self):
        self.nome = ""
        self.email = ""

    def mensagem(self):
        return f"[green]O email[/] '{self.email}'[green] do cliente[/] '{self.nome}' [green]foi cadastrado com sucesso.[/]"

#criando uma lista para clientes    
clientes = list()    
def cadastrar_cliente():
    print('====[yellow]Cadastro cliente[/]====')

    c1 = Cliente()
    c1.nome = str(input('Digite seu nome: '))
    c1.email = str(input('Digite seu email: '))
    clientes.append(c1)
    divisor(c1.mensagem()) #adicionar clientes na lista
     
    while True:
        
        res = str(input('Deseja cadastrar outro cliente:(s/n): '))
        if res == 's' or res == 'S':
            c1 = Cliente()
            c1.nome = str(input('Digite seu nome: '))
            c1.email = str(input('Digite seu email: '))

            clientes.append(c1) #adicionar clientes em lista 
            divisor(c1.mensagem())
        
        elif res == 'n' or res == 'N':
            print('Fim do cadastro cliente!')
            break

"""
funçao de listar clientes dentro de um panel
"""
def listar_clientes(clientes):
    for i,c in enumerate(clientes, start=1):
        conteudo = f"{i}º cliente\n"
        conteudo += f"NOME:{c.nome}\n"
        conteudo += f"{'=-=' *3}\n"
        conteudo += f"EMAIL:{c.email}"
        listar_clientes = Panel(conteudo, title = "LISTA DE CLIENTES")
        print(listar_clientes)

"""
cadastro de produtos
"""

class Produto:
    
    def __init__(self):
          self.n_produto = ""
          self.preço = 0
          self.codigo = 0
          self.estoque = 0

    def mensagem_produto(self):
        return f"[green]O nome do produto:[/] {self.n_produto}\n[green]O preço:[/] {self.preço}\n[green]O codigo:[/] {self.codigo} com {self.estoque} no estoque"
    
#criando lista do produtos    
produtos = list()    
def cadastrar_produto():
    print('====[yellow]Cadastrar produto[/]====')
    
    p2 = Produto()
    p2.n_produto = str(input('Digite o nome do produto: '))
    p2.preço = float(input('Digite o preço do produto: '))
    p2.codigo = int(input('Digite o codigo do produto: '))
    p2.estoque = int(input('Digite a quantidade em estoque: '))

    produtos.append(p2)#adicionar produtos em uma lista
    divisor(p2.mensagem_produto()) 
    
    while True:
            res = str(input('Deseja cadastrar outro produto(s/n): '))
            if res == 's' or res == 'S':
                p2 = Produto()
                p2.n_produto = str(input('Digite o nome do produto: '))
                p2.preço = float(input('Digite o preço do produto: '))
                p2.codigo = int(input('Digite o codigo do produto: '))
                p2.estoque = int(input('Digite a quantidade em estoque: '))

                produtos.append(p2)  #adicionar produtos em uma lista
                divisor(p2.mensagem_produto())

            elif res == 'n' or res == 'N':
                print('Fim do cadastro dos produtos')
                break
"""
função de listar produtos dentro de um panel
"""
def listar_produtos(produtos):
    for i, p in enumerate(produtos, start = 1):
        conteudo = f"{i}º Produtos\n"
        conteudo += f"NOME DO PRODUTO...:{p.n_produto}\n"
        conteudo += f"{' =-= ' *3}\n"
        conteudo += f"PREÇO DO PRODUTO...: {p.preço}\n"
        conteudo += f"{' =-= ' *3}\n"
        conteudo += f"CODIGO DO PRODUTO...:{p.codigo}"
        listar_produtos = Panel(conteudo, title = "LISTA DE PRODUTOS")
        print(listar_produtos)

"""
cadastra pedido      
"""

class Pedido:

    def __init__(self):
          self.email = ""
          self.preço = 0
          self.codigo = 0

    def __str__ (self):
         return f"[green]O email do cliente[/] {self.email}\n[green]O preço[/] {self.preço}\n[green]O codigo[/] {self.codigo}" 

#criando lista para pedidos
pedidos = list()   
def cadastrar_pedido():
    print('====[yellow]Cadastro pedido[/]====')
    
    p3 = Pedido()
    p3.email = str(input('Digite seu email: '))
    p3.codigo = int(input('Digite o codigo do produto: '))
    p3.preço = float(input('Digite o preço do produto: '))
            
    pedidos.append(p3)#adicionar pedidos em uma lista 
    divisor(p3)
   
    while True:
        res = str(input('Deseja cadastrar outro pedido(s/n): '))
        if res == 's' or res == 'S':
            p3 = Pedido()
            p3.email = str(input('Digite seu email: '))
            p3.codigo = int(input('Digite o codigo do produto: '))
            p3.preço = float(input('Digite o preço do produto: '))
            
            pedidos.append(p3)#adicionar pedidos em uma lista 
            divisor(p3)

        elif res == 'n' or res == 'N':
            print('Fim do cadastro de pedidos!')
            break

"""
função de listar pedidos dentro de um panel
"""
def listar_pedidos(pedidos):
    for i, pe in enumerate(pedidos, start = 1):
        conteudo = f"{i}º pedido\n"
        conteudo += f"NOME DO EMAIL...:{pe.email}\n"
        conteudo += f"{'=-=' *3}\n"
        conteudo += f"CODIGO DO PRODUTO...:{pe.codigo}\n"
        conteudo += f"{'=-=' *3}"
        conteudo += f"PREÇO DO PRODUTO...:{pe.preço}"
        listar_pedidos = Panel(conteudo, title = "LISTA DE PEDIDOS")
        print(listar_pedidos)

"""
menu de interação com o cliente
"""
while True:
    print('[blue]==== Bem vindo a loja ====[/]')
    print('[blue]1 - Cadastrar cliente[/]')
    print('[blue]2 - Cadastrar produto[/]')
    print('[blue]3 - Cadastrar pedido[/]')
    print('[blue]4 - Listar clientes cadastrados[/]')
    print('[blue]5 - Listar produtos cadastrados[/]')
    print('[blue]6 - Listar pedidos cadastrados[/]')
    print('[blue]7 - Sair[/]')

    escolha = int(input('Digite a opção desejada: '))

    if escolha == 1:
        #chamar função para cadastrar cliente
        cadastrar_cliente()
           
    elif escolha == 2:
        #chamar função para cadastrar produto
        cadastrar_produto()

    elif escolha == 3:
        #chamar função para cadastrar pedido
        cadastrar_pedido()

    elif escolha == 4:
        #chamar função para listar clientes cadastrados
        listar_clientes(clientes)

    elif escolha == 5:
        #chamar função para listar produtos cadastrados
        listar_produtos(produtos)

    elif escolha == 6:
        #chamar função para listar pedidos cadastrados
        listar_pedidos(pedidos)

    elif escolha == 7:
         print('Obrigado por visitar nossa loja!')
         break
     

