// Exemplos desenvolvidos para ilustrar a sintaxe da linguagem.

#include <iostream>
#include <string>

using namespace std;

// Inclus�o de declara��es de classes.

#include "Dominios.h"

int main()
{

// EXEMPLO
// --------------------------------------------------------

    // Acesso a atributo de classe.

    cout << "numero_contas  = " << ContaCorrente::getNumeroContas() << endl;

    // Constru��o de objetos.

    ContaCorrente a, b("Jose"), c("Ana", 100);

    // Invoca��o de m�todos p�blicos.

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

    // Acesso a n�mero de banco.

    cout << "numero_banco  = "  << ContaCorrente::NUMERO_BANCO << endl;

    // Exemplo de erro: Acesso a vari�vel est�tica privada
    // ContaCorrente::numero_contas = 10;


// EXEMPLO
// --------------------------------------------------------

// Exemplifica aloca��o din�mica de objetos.

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

// Destrui��o de objetos.

    delete ptrA;
    delete ptrB;
    delete ptrC;

// EXEMPLO
// --------------------------------------------------------

// Exemplifica rela��o entre objetos e o tratamento de exce��o.

    Turma turmaA (117889);

    Disciplina disciplinaA("MOO", 117196), disciplinaB;

    // Estabelece rela��o entre objetos.

    turmaA.setDisciplina(disciplinaA);

    disciplinaB = turmaA.getDisciplina();

    cout << "Nome da disciplina na turma  = " << disciplinaB.getNome() << endl;
    cout << "Codigo da diciplina na turma = " << disciplinaB.getCodigo() << endl;

    // Tratamento de exce��o.

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

// Exemplifica aloca��o din�mica e acesso via ponteiro.

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

// Exemplifica aloca��o din�mica e o estabelecimento de rela��es entre m�ltiplos objetos.

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

// Exemplifica tratamento de exce��o.

    Codigo codigoA;

    try{
            // Valor v�lido n�o resulta em lan�amento de exce��o.

            codigoA.setCodigo(50);
            cout << "Codigo armazenado = " << codigoA.getCodigo() << endl;

            // Valor inv�lido resulta em lan�amento de exce��o.

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

// Exemplifica modos de passar objetos (por valor e por refer�ncia).

    Curso cursoB;

    Codigo codigoB;

    Disciplina *ptrG = new Disciplina();

    // Exemplo de passagem por valor.

    cursoB.setCodigo(codigoB);

    // Exemplo de passagem por refer�ncia usando ponteiro.

    cursoB.setDisciplina(ptrG);

    delete ptrG;

// EXEMPLO
// --------------------------------------------------------

// Exemplifica o uso de ponteiros e de refer�ncias.

    // Ponteiro para inst�ncia de classe.

    Codigo *ptrH = new Codigo();

    ptrH->setCodigo(100);

    cout << "Valor = " << ptrH->getCodigo() << endl;

    // Ponteiro para m�todo membro de classe.

    Codigo codigoC;

    void (Codigo::*ptrI) (int) throw (invalid_argument);

    int (Codigo::*ptrJ) ();

    // Atribui��es dos endere�os dos m�todos.

    ptrI = &Codigo::setCodigo;

    ptrJ = &Codigo::getCodigo;

    // Acesso aos objetos usando ponteiros para os m�todos.

    try{
            (codigoC.*ptrI)(150);

            cout << "Codigo armazenado = " << (codigoC.*ptrJ)() << endl;

            // Valor inv�lido resulta no lan�amento de exce��o.

            (codigoB.*ptrI)(10);

            // O pr�ximo enunciado n�o ser� executado.

            cout << "Codigo armazenado = " << (codigoC.*ptrJ)() << endl;
    }
    catch(invalid_argument excecao){
        cout << "Motivo da excecao = " << excecao.what() << endl;
        cout << "Codigo armazenado = " << (codigoC.*ptrJ)() << endl;
    }

    // Acesso aos objetos usando ponteiros para os objetos e ponteiros para os m�todos.

    try{
            (ptrH->*ptrI)(250);

            cout << "Codigo armazenado = " << (ptrH->*ptrJ)() << endl;

            // Valor inv�lido resulta no lan�amento de exce��o.

            (codigoB.*ptrI)(10);

            // O pr�ximo enunciado n�o ser� executado.

            cout << "Codigo armazenado = " << (ptrH->*ptrJ)() << endl;
    }
    catch(invalid_argument excecao){
        cout << "Motivo da excecao = " << excecao.what() << endl;
        cout << "Codigo armazenado = " << (ptrH->*ptrJ)() << endl;
    }

    // Ponteiro para atributo de classe.

    // C�digo comentado pois o atributo � privado.

    // int Codigo::*ptrK;

    // ptrk = &Codigo::codigo;

// EXEMPLO
// --------------------------------------------------------

// Exemplifica refer�ncias para objetos.

    Codigo codigoD, &codigoE = codigoD;

    codigoD.setCodigo(300);

    cout << "Codigo armazenado = " << codigoE.getCodigo() << endl;

    return 0;
}
