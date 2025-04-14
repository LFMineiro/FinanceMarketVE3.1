# 📈 VE Lab Prog - Sistema de Gestão de Investimentos

O projeto tem como objetivo cadastrar investidores com seus respectivos perfis e ativos, e associá-los de forma a manter um histórico das carteiras dos investidores por período, além de permitir consultar quais investidores compraram determinado ativo em um período específico.

---

## ⚙️ Como Usar

O projeto pode ser executado da seguinte forma:

**Compilação:**

````
gcc src/financeMarket.c src/investor.c src/asset.c src/menu.c src/association.c -o FinanceMarketVE
````

**Execução:**

````
./FinanceMarketVE.exe
````

Em sistemas Unix/Linux/macOS, utilize `./FinanceMarketVE` sem o `.exe`.

---

## 📘 Roteiro

**Sistema de Gerenciamento de Investimentos no Mercado Financeiro**

Você foi designado para desenvolver um sistema de gerenciamento de investimentos no mercado financeiro.

---

### Entidades do Sistema:

1. **Investidor**
   - **Código:** 5 dígitos
   - **Nome**
   - **Perfil de Investidor:** (Ex.: Conservador, Moderado, Agressivo)

2. **Ativo**
   - **Código:** 4 dígitos
   - **Nome**
   - **Tipo:** (Ex.: ação, título, fundo de investimento)
   - **Valor Unitário**
   - **Risco**

---

### Requisitos do Sistema:

- O sistema deve ser capaz de armazenar uma lista de investidores e uma lista de ativos.
- Todas as estruturas devem ser alocadas dinamicamente.
- Deve ser implementado um menu de opções que permita:
  - Inserção e remoção de investidores
  - Inserção e remoção de ativos
- O sistema deve permitir consultas, tais como:
  - **Consulta 1:** Exibir todos os ativos da carteira de um determinado investidor por período
  - **Consulta 2:** Exibir os investidores que possuem determinado ativo em um determinado período
- Deve ser implementada a funcionalidade de salvamento e recuperação dos dados entre sessões, garantindo que as informações não sejam perdidas ao encerrar o programa.

---

### 📂 Dados de Teste:

- O projeto acompanha, como exemplo:
  - 3 registros de investidores
  - 3 registros de ativos
  - Associações entre eles para compor carteiras por período
 
 ---

## 🔍 Detalhamento Técnico por Funcionalidade

### Investidor e Ativo

As estruturas básicas do sistema são definidas da seguinte forma:

```c
// Em investor.h

typedef struct _investor {
    int id;
    char name[50];
    char profile[35];
} Investor;

// Em asset.h

typedef struct _asset {
    int id;
    char type[15];
    char ticker[15];
    float price;
    char risk;
} Asset;

````

### 📁 Armazenamento em Lista e Arquivos

O sistema armazena uma lista de investidores e ativos utilizando arquivos .txt:

- Investidores: salvos e carregados de investors.txt
- Ativos: salvos e carregados de assets.txt

Ambos podem ser consultados pelo menu:

- Opção 6 → `` printInvestors() ``
- Opção 7 → `` printAssets() ``

---

 ### 🧠 Alocação Dinâmica

Todas as estruturas são alocadas dinamicamente com calloc, como nos exemplos abaixo:

````c
Association *association = (Association *) calloc(1, sizeof(Association));
Investor *investor = (Investor *) calloc(1, sizeof(Investor));
Asset *asset = (Asset *)calloc(1, sizeof(Asset));
````

---

### ➕➖ Inserção e Remoção

**INVESTIDOR**

- Inserção → ``registerInvestor() (Opção 1)``
- Remoção → ``deleteInvestor() (Opção 2)``

**ATIVO**

- Inserção → ``registerAsset() (Opção 3)``
- Remoção → ``deleteAsset() (Opção 4)``

---

### 🔗 Associação Investidor–Ativo

Para simular a compra de ativos por investidores, é utilizada uma terceira estrutura Association, que liga um investidor a um ativo em um determinado período.

---

### 📊 Consultas
- Consulta 1: Mostrar ativos da carteira de um investidor em um período
   - Função: ``getAssetsByInvestorAndPeriod()``

- Consulta 2: Mostrar investidores que compraram determinado ativo em um período
   - Função: ``getInvestorsByAssetAndPeriod()``
 
---

### 💾 Funcionalidade de salvamento e recuperação

Todos os dados são salvos em arquivos .txt, para isso utilizamos as funções ``saveInvestors()``, ``saveAssets()`` e ``saveAssociations()`` e para recuperação dos dados usamos ``loadInvestors()``, ``loadAssets()`` e ``loadAssociations()``,
