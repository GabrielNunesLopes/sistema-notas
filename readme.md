# 📊 Sistema de Notas 4.0

![C++](https://img.shields.io/badge/C++11-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Git](https://img.shields.io/badge/Git-F05032?style=for-the-badge&logo=git&logoColor=white)

Um sistema simples e eficiente desenvolvido em **C++** para console, projetado para gerenciar o desempenho escolar de estudantes. O programa permite cadastrar alunos, registrar notas de múltiplas disciplinas, calcular médias automaticamente e exportar relatórios consolidados em arquivos físicos de texto.

---

## 🚀 Funcionalidades

* **Menu Dinâmico:** Escolha entre iniciar um novo relatório ou abrir os dados da última execução.
* **Validação de Entradas (Anti-Crash):** O sistema impede dados incorretos, forçando limites de notas e quantidades.
* **Critérios de Avaliação Automáticos:**
  * 🟢 **Aprovado:** Média $\ge$ 7.0
  * 🟡 **Recuperação:** Média entre 5.0 e 6.9
  * 🔴 **Reprovado:** Média $<$ 5.0
* **Persistência de Dados:** Gravação automática dos resultados no arquivo `Relatorio.txt`.

---

## 🛠️ Regras de Negócio e Limites

Para manter a integridade da memória e o controle de matrizes, o sistema obedece estritamente aos seguintes limites:

| Parâmetro | Mínimo | Máximo |
| :--- | :---: | :---: |
| **Quantidade de Alunos** | 1 | 20 |
| **Disciplinas por Aluno** | 1 | 5 |
| **Nota Permitida** | 0.0 | 10.0 |

---

## 💻 Como Compilar e Executar

Certifique-se de ter um compilador para C++ (como o `g++`) instalado em sua máquina.

```bash
# 1. Compile o código fonte
g++ main.cpp -o sistema_notas

# 2. Execute o programa
# No Linux/macOS:
./sistema_notas

# No Windows (Prompt/PowerShell):
./sistema_notas.exe