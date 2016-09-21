#include "Dominios.h"

// EXEMPLO
// --------------------------------------------------------

//Defini��es de constantes.

const int ContaCorrente::NUMERO_BANCO  = 1;
const int Turma::LIMITE = 20;
const int AlunoGraduacao::LIMITE = 400;
const int Codigo::LIMITE = 25;
const int TUCodigo::SUCESSO =  0;
const int TUCodigo::FALHA   = -1;
const int TUCodigo::VALOR_VALIDO   = 30;
const int TUCodigo::VALOR_INVALIDO = 20;

// Defini��o de atributos de classe.


int ContaCorrente::numero_contas = 0;

// Defini��es de m�todos da classe ContaCorrente.

ContaCorrente::ContaCorrente(){
    nome = "";
    saldo = 0;
    numero_contas++;
}

ContaCorrente::ContaCorrente(string nome){
    this->nome = nome;                          // Resolu��o de conflito de nomes.
    saldo = 0;
    numero_contas++;
}

ContaCorrente::ContaCorrente(string nome, float saldo){
    this->nome = nome;
    this->saldo = saldo;
    numero_contas++;
}

void ContaCorrente::setNome(string nome){
    this->nome = nome;
}

string ContaCorrente::getNome() const {
    return nome;
}

void ContaCorrente::setSaldo(float saldo){
    this->saldo = saldo;
}

float ContaCorrente::getSaldo() const {

// Exemplo de erro: Modifica��o de atributo em m�todo const.
// saldo = 10;

    return saldo;
}

void ContaCorrente::depositar(float valor) {
    this->saldo = saldo + valor;
}

int ContaCorrente::getNumeroContas() {
    return numero_contas;
}

// EXEMPLO
// --------------------------------------------------------

// Defini��es de m�todos da classe Turma.

void Turma::setNumeroAlunos(int numero_alunos) throw(invalid_argument){

    // Testa e lan�a exce��o se n�mero de alunos superior ao limite.

    if (numero_alunos > LIMITE) throw invalid_argument("Argumento invalido.");

    // Atribui valores se n�o lan�ou exce��o.

    this->numero_alunos = numero_alunos;
}

// EXEMPLO
// --------------------------------------------------------

// Defini��es de m�todos da classe Codigo.


// Ilustra uso de um m�todo privado para valida��o.

void Codigo::validar(int codigo) throw (invalid_argument){

    // Lan�a exce��o se valor for menor que o limite definido.

    if (codigo < LIMITE)
        throw invalid_argument("Argumento invalido.");
}

// Ilustra m�todo que nao trata exce��o lan�ada.

void Codigo::setCodigo(int codigo) throw (invalid_argument){
    validar(codigo);
    this->codigo = codigo;
}

// EXEMPLO
// --------------------------------------------------------

// Defini��es de m�todos da classe Curso.

// M�todo ilustra ponteiro para constante.

void Curso::setDisciplina(const Disciplina *disciplina){

    // Cria elemento para a lista de disciplinas.

    ElementoLista *ptr = new ElementoLista();

    ptr->disciplina = disciplina;

    ptr->proximo = primeiroElemento;

    primeiroElemento = ptr;
}

// M�todo destrutor.

Curso::~Curso(){

    ElementoLista *ptrA, *ptrB;
    ptrA = primeiroElemento;

    // Percorre a lista e deleta elementos.

    while (ptrA != NULL){

        ptrB = ptrA;
        ptrA = ptrA->proximo;
        delete ptrB;
    };
}

// EXEMPLO
// --------------------------------------------------------

// Defini��es de m�todos da classe TUCodigo.

void TUCodigo::setUp(){
    codigo = new Codigo();
    estado = SUCESSO;
}

void TUCodigo::tearDown(){
    delete codigo;
}

void TUCodigo::testarCenarioSucesso(){
    try{
        codigo->setCodigo(VALOR_VALIDO);
        if (codigo->getCodigo() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

void TUCodigo::testarCenarioFalha(){
    try{
        codigo->setCodigo(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument excecao){
        return;
    }
}

int TUCodigo::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

// EXEMPLO
// --------------------------------------------------------

// Defini��es de m�todos da classe Aluno.

Aluno::Aluno(int matricula){
    this->matricula = matricula;
}

// Defini��es de m�todos da classe AlunoGraduacao.

void AlunoGraduacao::setCreditos(int creditos) {
    if (this->creditos < AlunoGraduacao::LIMITE)
        this->creditos = this->creditos + creditos;
}

// EXEMPLO
// --------------------------------------------------------

// Defini��es de m�todos da classe AlunoPosGraduacao.

AlunoPosGraduacao::AlunoPosGraduacao(int matricula, int telefone):Aluno(matricula){
    this->telefone = telefone;
}

void AlunoPosGraduacao::setCreditos(int creditos) {
    this->creditos = this->creditos + creditos;
}

