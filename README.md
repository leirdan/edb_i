# EDB_I

Anotações e arquivos relacionados à 3a unidade da disciplina Estrutura de Dados Básicas I.
- Obs.: provavelmente não serão abordados os tópicos de busca e ordenação pois são tópicos vistos na unidade passada, e eu não pretendo escrevê-los novamente aqui.

## TAD ou Tipo Abstrato de Dados
**Def**: estrutura matemática que representa a natureza de um dado e operações que podem ser feitas sobre este. 
    - Funciona como uma interface.

### TAD Sequência
**Def**: coleção de elementos posicionados onde cada um tem um índice. 

**Operações comuns**: buscar, ordenar, inserir/remover.

#### Operação de Inserção 
- Arbitrária;
- Início; 
- Fim. 

#### Operação de Remoção 
- Arbitrária;
- Início; 
- Fim. 

#### Operação de Acesso 
- Arbitrária;
- Início; 
- Fim. 

### Outros TADs
- TAD Pilha: similar à Sequência, mas são necessárias somente as operações de Início ou Fim na Inserção/Remoção/Acesso, já que só existem pilhas FIFO ou LIFO.
- TAD Fila/Buffer: similar à Sequência, mas segue a lógica de remover o início e adicionar o fim (como um vídeo) ou remover o fim e adicionar o início (como um *download*).
## ED ou Estrutura de Dados
**Def**: implementação de um TAD em um computador, definindo como o TAD está disposto na memória e suas operações.

### ED Vetor : TAD Sequência
**Def**: implementação do TAD Sequência onde os elementos estão armazenados sequencialmente na memória do computador. Para criar um Vetor, são necessários 3 elementos fundamentais: 

* `n`: quantidade de elementos no vetor; 
* `n_max`: comprimento do vetor; 
* `*v`: ponteiro para o início do vetor.

**Vantagens**: exige menos memória para armazenar os elementos, além de que, por estar disposta em um bloco contínuo, é mais rápido acessar um elemento arbitrário em qualquer posição.

**Desvantagens**: é necessário um bloco contínuo na memória para armazenar todos os dados, o que nem sempre é possível; para acessar os elementos de um vetor utiliza-se *aritmética de ponteiros*, ou seja, é necessário que haja uma **homogeneidade de tipos** dos dados no vetor (precisam ocupar o mesmo espaço em memória para a aritmética funcionar).

Veja a minha própria implementação em `src/vector.cpp`. 

* Acesso: método `get`, complexidade O(1);
* Inserção: método `insert`, complexidade O(n) e O(1) caso insira no final do Vetor;
* Remoção: método `remove`, complexidade O(n) e O(1) caso remova no final do Vetor.

#### Informações

|             | Inserção | Remoção | Acesso |
| :---------: | :------: | :-----: | :----: |
| Início      | O(n)     | O(n)    | O(1)   |
| Fim         | O(1)     | O(1)    | O(1)   |
| Arbitrário  | O(n)     | O(n)    | O(1)   |


### ED Lista Ligada : TAD Sequência 
**Vantagens**: não necessita de um bloco contínuo na memória para armazenar os dados; não utiliza aritmética de ponteiros para acessar seus elementos (visto que estão espalhados ao longo da memória), logo, permite uma **heterogeneidade de tipos**.

**Desvantagens**: exige maiores recursos computacionais, visto que cada elemento guarda o seu valor e um ponteiro para o próximo elemento que pode ser de qualquer tipo, além de que para acessar elementos que não sejam o primeiro é necessário percorrer todos os elementos até encontrar o desejado.
