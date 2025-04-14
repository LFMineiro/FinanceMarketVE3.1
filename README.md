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
   - **CPF**
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
