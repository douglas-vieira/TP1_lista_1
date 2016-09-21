// Exemplos desenvolvidos para ilustrar a sintaxe da linguagem.

#include <iostream>
#include <string>

using namespace std;

// Inclusão de declarações de classes.

#include "Dominios.h"

int main()
{

// EXEMPLO
// --------------------------------------------------------

    // Acesso a atributo de classe.

    cout << "numero_contas  = " << ContaCorrente::getNumeroContas() << endl;

    // Construção de objetos.

    ContaCorrente a, b("Jose"), c("Ana", 100);

    // Invocação de métodos públicos.

    cout << "a.nome  = " << a.getNome()  << endl;
    cout << "a.saldo = " << a.getSaldo() << endl;

    cout << "b.nome  = " << b.getNome()  << endl;
    cout << "b.saldo = " << b.getSaldo() << endl;

    cout << "c.nome  = " << c.getNome()  << endl;
    cout << "c.saldo = " << c.getSaldo() << endl;

    a.setNome("Marcos");
    a.setSaldo(1000);
    b.setSaldo(2000);
    c.setSaldo(3000);

    cout << "a.nome  = " << a.getNome()  << endl;
    cout << "a.saldo = " << a.getSaldo() << endl;

    cout << "b.nome  = " << b.getNome()  << endl;
    cout << "b.saldo = " << b.getSaldo() << endl;

    cout << "c.nome  = " << c.getNome()  << endl;
    cout << "c.saldo = " << c.getSaldo() << endl;

    a.depositar(1);
    b.depositar(2);
    c.depositar(3);

    cout << "a.nome  = " << a.getNome()  << endl;
    cout << "a.saldo = " << a.getSaldo() << endl;

    cout << "b.nome  = " << b.getNome()  << endl;
    cout << "b.saldo = " << b.getSaldo() << endl;

    cout << "c.nome  = " << c.getNome()  << endl;
    cout << "c.saldo = " << c.getSaldo() << endl;

    // Acesso a atributo de classe.

    cout << "numero_contas  = " << ContaCorrente::getNumeroContas() << endl;

    // Acesso a número de banco.

    cout << "numero_banco  = "  << ContaCorrente::NUMERO_BANCO << endl;

    // Exemplo de erro: Acesso a variável estática privada
    // ContaCorrente::numero_contas = 10;


// EXEMPLO
// --------------------------------------------------------

// Exemplifica alocação dinâmica de objetos.

    Disciplina *ptrA, *ptrB, *ptrC;

    ptrA = new Disciplina();
    ptrB = new Disciplina("MOO");

    // Exemplo de erro
    // ptrC = new Disciplina(,117196);

    ptrC = new Disciplina("TP1", 117889);

    cout << "ptrA->getNome   = " << ptrA->getNome() << endl;
    cout << "ptrA->getCodigo = " << ptrA->getCodigo() << endl;
    cout << "ptrB->getNome   = " << ptrB->getNome() << endl;
    cout << "ptrB->getCodigo = " << ptrB->getCodigo() << endl;
    cout << "ptrC->getNome   = " << ptrC->getNome() << endl;
    cout << "ptrC->getCodigo = " << ptrC->getCodigo() << endl;

// Destruição de objetos.

    delete ptrA;
    delete ptrB;
    delete ptrC;

// EXEMPLO
// --------------------------------------------------------

// Exemplifica relação entre objetos e o tratamento de exceção.

    Turma turmaA (117889);

    Disciplina disciplinaA("MOO", 117196), disciplinaB;

    // Estabelece relação entre objetos.

    turmaA.setDisciplina(disciplinaA);

    disciplinaB = turmaA.getDisciplina();

    cout << "Nome da disciplina na turma  = " << disciplinaB.getNome() << endl;
    cout << "Codigo da diciplina na turma = " << disciplinaB.getCodigo() << endl;

    // Tratamento de exceção.

    try {
        turmaA.setNumeroAlunos(10);

        cout << "Numero de alunos = " << turmaA.getNumeroAlunos() << endl;

        turmaA.setNumeroAlunos(50);

        cout << "Numero de alunos = " << turmaA.getNumeroAlunos() << endl;
    }
    catch(invalid_argument excecao){
        cout << "Motivo da excecao = " << excecao.what() << endl;
    }

// EXEMPLO
// --------------------------------------------------------

// Exemplifica alocação dinâmica e acesso via ponteiro.

    // Cria projeto e desenvolvedor.

    Projeto projeto;

    Desenvolvedor *ptrD = new Desenvolvedor();

    ptrD->setNome("Marcos");

    // Estabelece relacionamento entre projeto e desenvolvedor;

    projeto.setDesenvolvedor(ptrD);

    // Acessa desenvolvedor.

    ptrD = projeto.getDesenvolvedor();

    cout << "Nome do desenvolvedor = " << ptrD->getNome() << endl;

    delete ptrD;

// EXEMPLO
// --------------------------------------------------------

// Exemplifica alocação dinâmica e o estabelecimento de relações entre múltiplos objetos.

    // Cria um curso e duas disciplinas.

    Curso *cursoA = new Curso();

    Disciplina *ptrE = new Disciplina("TP", 117889);
    Disciplina *ptrF = new Disciplina("MOO",117196);

    // Estabelece relacionamentos entre o curso e as duas disciplinas.

    cursoA->setDisciplina(ptrE);
    cursoA->setDisciplina(ptrF);

    // Destroi os objetos.

    delete cursoA;
    delete ptrE;
    delete ptrF;

// EXEMPLO
// --------------------------------------------------------

// Exemplifica tratamento de exceção.

    Codigo codigoA;

    try{
            // Valor válido não resulta em lançamento de exceção.

            codigoA.setCodigo(50);
            cout << "Codigo armazenado = " << codigoA.getCodigo() << endl;

            // Valor inválido resulta em lançamento de exceção.

            codigoA.setCodigo(10);
            cout << "Codigo armazenado = " << codigoA.getCodigo() << endl;
    }
    catch(invalid_argument excecao){
        cout << "Motivo da excecao = " << excecao.what() << endl;
        cout << "Codigo armazenado = " << codigoA.getCodigo() << endl;
    }

// EXEMPLO
// --------------------------------------------------------

// Exemplifica teste de unidade.

    // Instancia o teste de unidade.

    TUCodigo teste;

    if(teste.run() == TUCodigo::FALHA)
        cout << "Falha   no teste de unidade." << endl;
    else
        cout << "Sucesso no teste de unidade." << endl;

// EXEMPLO
// --------------------------------------------------------

// Exemplifica modos de passar objetos (por valor e por referência).

    Curso cursoB;

    Codigo codigoB;

    Disciplina *ptrG = new Disciplina();

    // Exemplo de passagem por valor.

    cursoB.setCodigo(codigoB);

    // Exemplo de passagem por referência usando ponteiro.

    cursoB.setDisciplina(ptrG);

    delete ptrG;

// EXEMPLO
// --------------------------------------------------------

// Exemplifica o uso de ponteiros e de referências.

    // Ponteiro para instância de classe.

    Codigo *ptrH = new Codigo();

    ptrH->setCodigo(100);

    cout << "Valor = " << ptrH->getCodigo() << endl;

    // Ponteiro para método membro de classe.

    Codigo codigoC;

    void (Codigo::*ptrI) (int) throw (invalid_argument);

    int (Codigo::*ptrJ) ();

    // Atribuições dos endereços dos métodos.

    ptrI = &Codigo::setCodigo;

    ptrJ = &Codigo::getCodigo;

    // Acesso aos objetos usando ponteiros para os métodos.

    try{
            (codigoC.*ptrI)(150);

            cout << "Codigo armazenado = " << (codigoC.*ptrJ)() << endl;

            // Valor inválido resulta no lançamento de exceção.

            (codigoB.*ptrI)(10);

            // O próximo enunciado não será executado.

            cout << "Codigo armazenado = " << (codigoC.*ptrJ)() << endl;
    }
    catch(invalid_argument excecao){
        cout << "Motivo da excecao = " << excecao.what() << endl;
        cout << "Codigo armazenado = " << (codigoC.*ptrJ)() << endl;
    }

    // Acesso aos objetos usando ponteiros para os objetos e ponteiros para os métodos.

    try{
            (ptrH->*ptrI)(250);

            cout << "Codigo armazenado = " << (ptrH->*ptrJ)() << endl;

            // Valor inválido resulta no lançamento de exceção.

            (codigoB.*ptrI)(10);

            // O próximo enunciado não será executado.

            cout << "Codigo armazenado = " << (ptrH->*ptrJ)() << endl;
    }
    catch(invalid_argument excecao){
        cout << "Motivo da excecao = " << excecao.what() << endl;
        cout << "Codigo armazenado = " << (ptrH->*ptrJ)() << endl;
    }

    // Ponteiro para atributo de classe.

    // Código comentado pois o atributo é privado.

    // int Codigo::*ptrK;

    // ptrk = &Codigo::codigo;

// EXEMPLO
// --------------------------------------------------------

// Exemplifica referências para objetos.

    Codigo codigoD, &codigoE = codigoD;

    codigoD.setCodigo(300);

    cout << "Codigo armazenado = " << codigoE.getCodigo() << endl;

    return 0;
}
