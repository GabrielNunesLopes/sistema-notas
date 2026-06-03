#include <iostream>
#include <string>
#include <fstream>
#include <ctime> 
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
    cout << "=== SOBRE ===" << endl;
    cout << "\n=== SISTEMAS DE NOTAS 4.1 ===" << endl;
    cout << "Desenvolvido por: Gabriel Nunes Lopes" << endl;
    cout << "Turma: LOPAL 2026 - SENAI-SP" << endl;
    cout << "\n1. - Novo relatorio - " << endl;
    cout << "2. - Ver relatorio salvo - " << endl;
    // OPCIONAL C:
    cout << "4. - Relatorio de reprovados (Arquivo) - " << endl;
    cout << "Escolha uma opcao: " << endl;
    cin >> opcaoInicial;

    // LEITURA DE ARQUIVO (COMMIT 1)
    
    if(opcaoInicial == 2) {
    ifstream leitura("Relatorio.txt");
    if (leitura.is_open()){
        string linha;
        cout << "\n";
        while (getline(leitura, linha)) {
            cout << linha << endl; // <--- CORRIGIDO AQUI (era 'line')
        }
        leitura.close();
    } else {
        cout << "Nenhum relatorio encontrado" << endl;
    }
    return 0;
}

    // OPCIONAL C:
    if(opcaoInicial == 4) {
        ifstream leitura("reprovados.txt");
        if (leitura.is_open()){
            string linha;
            cout << "\n=== CONTEUDO ATUAL DE REPROVADOS.TXT ===\n";
            while (getline(leitura, linha)) {
                cout << linha << endl;
            }
            leitura.close();
        } else {
            cout << "\nNenhum relatorio de reprovados encontrado. Crie um novo relatorio primeiro." << endl;
        }
        return 0;
    }

    do {
        cout << "Quantidade de alunos (1 a 20): ";
        cin >> qtdAlunos;
    } while (qtdAlunos < 1 || qtdAlunos > 20);

    cin.ignore(); 

    for (int i = 0; i < qtdAlunos; i++) {
        // OPCONAL A: Validação de Nome
        do {
            cout << "Nome do aluno " << i + 1 << ": ";
            getline(cin, nomes[i]);
            
            if (nomes[i] == "") {
                cout << "Erro: O nome nao pode ser vazio. Tente novamente.\n";
            }
        } while (nomes[i] == "");
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

    // OPCIONAL B: Destaque de Notas
    int indiceMaior = 0;
    int indiceMenor = 0;

    for (int i = 1; i < qtdAlunos; i++) {
        if (media[i] > media[indiceMaior]) {
            indiceMaior = i;
        }
        if (media[i] < media[indiceMenor]) {
            indiceMenor = i;
        }
    }
    cout << "\nMaior media: " << nomes[indiceMaior] << " (" << media[indiceMaior] << ")" << endl;
    cout << "Menor media: " << nomes[indiceMenor] << " (" << media[indiceMenor] << ")" << endl;

    cout << "\n=== RESUMO DO SISTEMA ===" << endl;
    cout << "Alunos Aprovados: " << aprovados << endl;
    cout << "Alunos em Recuperacao: " << recuperacao << endl;
    cout << "Alunos Reprovados: " << reprovados << endl;

    // Salvando Relatório Geral
    ofstream arquivo("Relatorio.txt");

    if (arquivo.is_open()){
        arquivo << "=== RELATORIO ===" << endl;
        time_t agora = time(0);
        char* dataHora = ctime(&agora);
        arquivo << "Data do relatorio: " << dataHora << endl;
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
        cout << "Erro ao criar Relatorio.txt" << endl;
    }
    
    // OPCIONAL C: Geração do Relatório de Reprovados
    ofstream arqReprovados("reprovados.txt");
    if (arqReprovados.is_open()) {
        arqReprovados << "=== RELATORIO DE REPROVADOS (Media < 5.0) ===" << endl;
        for (int i = 0; i < qtdAlunos; i++) {
            if (media[i] < 5.0) {
                arqReprovados << nomes[i] << " - Media: " << media[i] << endl;
            }
        }
        arqReprovados.close();
        cout << "Relatorio de reprovados salvo em reprovados.txt" << endl;
    } else {
        cout << "Erro ao criar reprovados.txt" << endl;
    }
    
    return 0;
}