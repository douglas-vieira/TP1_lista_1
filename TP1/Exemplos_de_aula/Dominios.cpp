#include "Dominios.h"

// EXEMPLO
// --------------------------------------------------------

//Definições de constantes.

const int ContaCorrente::NUMERO_BANCO  = 1;
const int Turma::LIMITE = 20;
const int AlunoGraduacao::LIMITE = 400;
const int Codigo::LIMITE = 25;
const int TUCodigo::SUCESSO =  0;
const int TUCodigo::FALHA   = -1;
const int TUCodigo::VALOR_VALIDO   = 30;
const int TUCodigo::VALOR_INVALIDO = 20;

// Definição de atributos de classe.


int ContaCorrente::numero_contas = 0;

// Definições de métodos da classe ContaCorrente.

ContaCorrente::ContaCorrente(){
    nome = "";
    saldo = 0;
    numero_contas++;
}

ContaCorrente::ContaCorrente(string nome){
    this->nome = nome;                          // Resolução de conflito de nomes.
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

// Exemplo de erro: Modificação de atributo em método const.
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

// Definições de métodos da classe Turma.

void Turma::setNumeroAlunos(int numero_alunos) throw(invalid_argument){

    // Testa e lança exceção se número de alunos superior ao limite.

    if (numero_alunos > LIMITE) throw invalid_argument("Argumento invalido.");

    // Atribui valores se não lançou exceção.

    this->numero_alunos = numero_alunos;
}

// EXEMPLO
// --------------------------------------------------------

// Definições de métodos da classe Codigo.


// Ilustra uso de um método privado para validação.

void Codigo::validar(int codigo) throw (invalid_argument){

    // Lança exceção se valor for menor que o limite definido.

    if (codigo < LIMITE)
        throw invalid_argument("Argumento invalido.");
}

// Ilustra método que nao trata exceção lançada.

void Codigo::setCodigo(int codigo) throw (invalid_argument){
    validar(codigo);
    this->codigo = codigo;
}

// EXEMPLO
// --------------------------------------------------------

// Definições de métodos da classe Curso.

// Método ilustra ponteiro para constante.

void Curso::setDisciplina(const Disciplina *disciplina){

    // Cria elemento para a lista de disciplinas.

    ElementoLista *ptr = new ElementoLista();

    ptr->disciplina = disciplina;

    ptr->proximo = primeiroElemento;

    primeiroElemento = ptr;
}

// Método destrutor.

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

// Definições de métodos da classe TUCodigo.

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

// Definições de métodos da classe Aluno.

Aluno::Aluno(int matricula){
    this->matricula = matricula;
}

// Definições de métodos da classe AlunoGraduacao.

void AlunoGraduacao::setCreditos(int creditos) {
    if (this->creditos < AlunoGraduacao::LIMITE)
        this->creditos = this->creditos + creditos;
}

// EXEMPLO
// --------------------------------------------------------

// Definições de métodos da classe AlunoPosGraduacao.

AlunoPosGraduacao::AlunoPosGraduacao(int matricula, int telefone):Aluno(matricula){
    this->telefone = telefone;
}

void AlunoPosGraduacao::setCreditos(int creditos) {
    this->creditos = this->creditos + creditos;
}

