# 📊 Sistema de Notas 4.0

![C++](https://img.shields.io/badge/C++11-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Git](https://img.shields.io/badge/Git-F05032?style=for-the-badge&logo=git&logoColor=white)

Um sistema simples e eficiente desenvolvido em **C++** para console, projetado para gerenciar o desempenho escolar de estudantes. O programa permite cadastrar alunos, registrar notas de múltiplas disciplinas, calcular médias automaticamente e exportar relatórios consolidados em arquivos físicos de texto.

---

##  Funcionalidades Principais

### Menu Dinâmico
Ao iniciar, o sistema oferece uma interface de escolha interativa:
1. **Novo Relatório:** Inicia um novo ciclo de cadastro de alunos, disciplinas e notas.
2. **Abrir Última Execução:** Lê e exibe diretamente no terminal os dados salvos no arquivo `Relatorio.txt`.
4. **Relatório de Reprovados:** Filtra e exibe os alunos que estão com status de reprovados a partir do arquivo `reprovados.txt`.

### Cadastro e Cálculo Automatizado
* Permite cadastrar até **20 alunos**.
* Permite definir entre **1 e 5 disciplinas** por ciclo.
* **Cálculo de Médias:** O sistema processa automaticamente a média aritmética individual de cada aluno com base nas disciplinas inseridas.

### Critérios de Avaliação Automáticos
O sistema analisa a média final de cada aluno de forma autônoma e atribui um status com base nos seguintes critérios pedagógicos:
* 🟢 **Aprovado:** Média $\ge$ 7.0
* 🟡 **Recuperação:** Média entre 5.0 e 6.9
* 🔴 **Reprovado:** Média $<$ 5.0

### Persistência de Dados e Relatórios
Ao finalizar os cálculos, o sistema exporta e atualiza automaticamente dois arquivos de texto no mesmo diretório:
* **`Relatorio.txt`:** Contém o relatório geral completo com data/hora da execução, médias de todos os alunos, destaques de **Maior e Menor Média** do grupo e um resumo estatístico total (quantidade de aprovados, recuperação e reprovados).
* **`reprovados.txt`:** Um arquivo exclusivo que filtra apenas os alunos que não atingiram a nota mínima de 5.0, facilitando ações pedagógicas de apoio.

---

##  Regras de Negócio e Limites

Para manter a integridade da memória e o controle de matrizes, o sistema obedece estritamente aos seguintes limites:

| Parâmetro | Mínimo | Máximo |
| :--- | :---: | :---: |
| **Quantidade de Alunos** | 1 | 20 |
| **Disciplinas por Aluno** | 1 | 5 |
| **Nota Permitida** | 0.0 | 10.0 |

---

##  Como Compilar e Executar

Certifique-se de ter um compilador para C++ (como o `g++`) instalado em sua máquina.

```bash
# 1. Compile o código fonte
g++ main.cpp -o sistema_notas

# 2. Execute o programa
# No Linux/macOS:
./sistema_notas

# No Windows (Prompt/# 📊 Sistema de Notas 4.0

![C++](https://img.shields.io/badge/C++11-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Git](https://img.shields.io/badge/Git-F05032?style=for-the-badge&logo=git&logoColor=white)

Um sistema simples e eficiente desenvolvido em **C++** para console, projetado para gerenciar o desempenho escolar de estudantes. O programa permite cadastrar alunos, registrar notas de múltiplas disciplinas, calcular médias automaticamente e exportar relatórios consolidados em arquivos físicos de texto.

---

##  Funcionalidades Principais

### Menu Dinâmico
Ao iniciar, o sistema oferece uma interface de escolha interativa:
1. **Novo Relatório:** Inicia um novo ciclo de cadastro de alunos, disciplinas e notas.
2. **Abrir Última Execução:** Lê e exibe diretamente no terminal os dados salvos no arquivo `Relatorio.txt`.
4. **Relatório de Reprovados:** Filtra e exibe os alunos que estão com status de reprovados a partir do arquivo `reprovados.txt`.

### Cadastro e Cálculo Automatizado
* Permite cadastrar até **20 alunos**.
* Permite definir entre **1 e 5 disciplinas** por ciclo.
* **Cálculo de Médias:** O sistema processa automaticamente a média aritmética individual de cada aluno com base nas disciplinas inseridas.

### Critérios de Avaliação Automáticos
O sistema analisa a média final de cada aluno de forma autônoma e atribui um status com base nos seguintes critérios pedagógicos:
* 🟢 **Aprovado:** Média $\ge$ 7.0
* 🟡 **Recuperação:** Média entre 5.0 e 6.9
* 🔴 **Reprovado:** Média $<$ 5.0

### Persistência de Dados e Relatórios
Ao finalizar os cálculos, o sistema exporta e atualiza automaticamente dois arquivos de texto no mesmo diretório:
* **`Relatorio.txt`:** Contém o relatório geral completo com data/hora da execução, médias de todos os alunos, destaques de **Maior e Menor Média** do grupo e um resumo estatístico total (quantidade de aprovados, recuperação e reprovados).
* **`reprovados.txt`:** Um arquivo exclusivo que filtra apenas os alunos que não atingiram a nota mínima de 5.0, facilitando ações pedagógicas de apoio.

---

##  Regras de Negócio e Limites

Para manter a integridade da memória e o controle de matrizes, o sistema obedece estritamente aos seguintes limites:

| Parâmetro | Mínimo | Máximo |
| :--- | :---: | :---: |
| **Quantidade de Alunos** | 1 | 20 |
| **Disciplinas por Aluno** | 1 | 5 |
| **Nota Permitida** | 0.0 | 10.0 |

---

##  Como Compilar e Executar

Certifique-se de ter um compilador para C++ (como o `g++`) instalado em sua máquina.

```bash
# 1. Compile o código fonte
g++ main.cpp -o sistema_notas

# 2. Execute o programa
# No Linux/macOS:
./sistema_notas

# No Windows (Prompt/PowerShell):
./sistema_notas.exe 
```

---

## **Top contributors:**
<a href="https://github.com/GabrielNunesLopes">
<img src="https://github.com/GabrielNunesLopes.png" width="60px" style="border-radius: 50%;" alt="GabrielNunesLopes">
</a>