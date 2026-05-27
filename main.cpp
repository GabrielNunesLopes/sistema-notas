#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {

    //Entrada
    string nomes[20];
    int qtdAlunos;
    float notas[20][5];
    float media[20];
    int qtdDisciplinas;
    int opcaoInicial;

    //Processamento
    cout << "=== SISTEMAS DE NOTAS 4.0 ===" << endl;
    cout << "1. - Novo relatorio - " << endl;
    cout << "2. - Ver relatorio salvo - " << endl;
    cout << "Escolha uma opcao: " << endl;
    cin >> opcaoInicial;

    // LEITURA DE ARQUIVO (COMMIT 1)
    if(opcaoInicial == 2) {
        ifstream leitura("Relatorio.txt");
        if (leitura.is_open()){
            string linha;
            cout << "\n";
            while (getline(leitura, linha)) {
                cout << linha << endl;
            }
            leitura.close();
        } else {
        cout << "Nenhuma relatorio encontrado" << endl;
        }
        return 0;
    }


    do {
        cout << "Quantidade de alunos (1 a 20): ";
        cin >> qtdAlunos;
    } while (qtdAlunos < 1 || qtdAlunos > 20);

    cin.ignore(); 

    for (int i = 0; i < qtdAlunos; i++) {
        cout << "Nome do aluno " << i + 1 << ": ";
        getline(cin, nomes[i]);
    }

    // NOTAS E MEDIA (COMMIT 2)
    do {
        cout << "Quantidade de disciplinas(1 a 5): ";
        cin >> qtdDisciplinas;
    } while (qtdDisciplinas < 1 || qtdDisciplinas > 5);

    for (int i = 0; i < qtdAlunos; i++){
        cout << "\nNotas de " << nomes[i] << ": " << endl;
        float soma = 0;
        
        for (int j = 0; j < qtdDisciplinas; j++) {
            do {
                cout << "  Disciplina " << j + 1 << " (Nota de 0 a 10): "; 
                cin >> notas[i][j];
            } while (notas[i][j] < 0 || notas[i][j] > 10); 
            
            soma += notas[i][j];
        }
        
        media[i] = soma / qtdDisciplinas; 
    }

    //Saida
    cout << "\nAlunos cadastrados: " << endl;

    for (int i = 0; i < qtdAlunos; i++) {
        cout << " " << i + 1 << ". " << nomes[i] << endl;
    }

    cout << "\n=== RELATORIO ===" << endl;
    int aprovados = 0, recuperacao = 0, reprovados = 0;
    
    for (int i = 0; i < qtdAlunos; i++) {
        cout << nomes[i] << " - Media: " << media[i] << " - ";
        
        if (media[i] >= 7.0) {
            cout << "Aprovado" << endl;
            aprovados++;
        } else if (media[i] >= 5.0) {
            cout << "Recuperacao" << endl;
            recuperacao++;
        } else {
            cout << "Reprovado" << endl;
            reprovados++;
        }
    }

    cout << "\n=== RESUMO DO SISTEMA ===" << endl;
    cout << "Alunos Aprovados: " << aprovados << endl;
    cout << "Alunos em Recuperacao: " << recuperacao << endl;
    cout << "Alunos Reprovados: " << reprovados << endl;

    ofstream arquivo("Relatorio.txt");

    if (arquivo.is_open()){
        arquivo << "=== RELATORIO ===" << endl;
        for(int i = 0; i < qtdAlunos; i++) {
            arquivo << nomes[i] << " - Media: " << media[i] << " - ";
            if (media[i] >= 7){
                arquivo << "Aprovado" << endl;
            } else if (media[i] >= 5) {
                arquivo << "Recuperacao" << endl;
            } else {
                arquivo << "Reprovado" << endl;
            }
        }
        arquivo << "\nResumo: " << aprovados << " aprovados, " << recuperacao << " em recuperacao, " << reprovados << " reprovados." << endl;

        arquivo.close();
        cout << "\nRelatorio salvo em Relatorio.txt" << endl;
    } else {
        cout << "Erro ao criar" << endl;
    }
    
    return 0;
}