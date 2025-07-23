# Trabalho de Linguagens Formais e Automatos
# Alunos: Alexandre Alves Maciel Filho, Arthur G. S. Marques, Julia Davies
================================================================================

# Como usar
  Compilar: g++ transicao.cpp afd.cpp main.cpp -o leitor_de_afd
  Executar: ./leitor_de_afd

  O programa irá pedir para inserir o nome do arquivo txt a ser lido, ex: "arq.txt". Logo em seguida a gramática equivalente à ele será impressa.
  No terminal o usuário pode inserir uma palavra para ser processada e o programa irá indicar se essa palavra é ou não aceita pela gramática do afd.
  O programa para quando o usuário decidir que não quer mais processar palavras.

# Formato esperado do Arquivo de Entrada

  alfabeto={a,b,c}
  estados={q0,q1,q2}
  finais={q1,q2}
  (q0,a)=q1
  (q0,b)=q2
  (q1,a)=q1
  (q1,b)=q2
  (q2,a)=q1
  (q2,b)=q2

================================================================================

# Funcionalidades
  - Leitura de AFD a partir de arquivo texto
  - Conversão de AFD para gramática regular
  - Processamento de cadeias, com output indicando se a cadeia é aceita ou não pela gramática

# Estrutura de Arquivos
  - transicao.h: header da classe transicao
  - transicao.cpp: imlementacao da classe transicao
  - afd.h: header da classe afd definindo os metodos a serem implementados na classe
  - afd.cpp: implementação da classe afd
      - Métodos de armazenar no objeto: add_simbolo, add_estado, add_estado_final, add_transicao;
      - eh_estado_final: Método de confirmar se o estado é final;
      - prox_estado: Avança para o estado destino de acordo com o simbolo lido no estado atual, retornando vazio caso não haja um estado destino correspondente;
      - mostrar: Imprime o afd lido, implementado para funções de teste e confirmação se o arquivo foi lido e armazenado corretamente;
      - processa_cadeia: Processa a cadeia lida, indicando se esta é ou não aceita pela gramática do afd;
  - main.cpp: lê o afd, gera a gramática e processa as cadeias em loop enquanto o usuário quiser continuar
      - ler_afd: Função que lê o afd no arquivo txt e armazena no objeto "automato";
      - ger_gramar: gera e imprime a gramática equivalente ao afd lido;
   
================================================================================
