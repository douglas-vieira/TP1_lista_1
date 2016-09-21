// Diretivas para controle de inclusão.

#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

// Inclusões e definições de espaço de nomes.

#include <string>
#include <stdexcept>

using namespace std;

// Declaração de classe.

// EXEMPLO
// --------------------------------------------------------
//
// Exemplifica:
//
// Atributos e métodos de instância e de classe.
// Métodos construtores.
// Constante pública.


class ContaCorrente {

    // Atributos e métodos privados.

 private:

    // Atributos de instância.

    string nome;
    float saldo;

    // Atributo de classe.

    static int numero_contas;

    // Atributos e métodos públicos.

public:

    // Constante pública.

    static const int NUMERO_BANCO;

    // Métodos construtores sobrecarregados.

    ContaCorrente();
    ContaCorrente(string);
    ContaCorrente(string, float);

    // Métodos de instância.

    void setNome(string);
    string getNome() const;         // Método const (método não altera estado do objeto).

    void setSaldo(float);
    float getSaldo() const;         // Método const (método não altera estado do objeto).

    void depositar(float);

    // Método de classe.

    static int getNumeroContas();
};

// EXEMPLO
// --------------------------------------------------------
//
// Exemplifica:
//
// Métodos inline.
// Definição de valor default para parâmetro.

class Disciplina {

private:
        string nome;
        int codigo;
public:

    // Construtor inline com valores definidos para parâmetros.

    Disciplina(string nome = "A DEFINIR", int codigo = 0){
        this->nome = nome;
        this->codigo = codigo;
    }

    // Métodos inline definidos na declaraçao da classe.

    void setNome(int nome){
    this->nome = nome;
    }

    string getNome() const {
        return nome;
    }

    // Métodos inline posteriormente definidos.

    inline void setCodigo(int);
    inline int getCodigo() const;
};

inline void Disciplina::setCodigo(int codigo){
    this->codigo = codigo;
}

inline int Disciplina::getCodigo() const{
    return codigo;
}

// EXEMPLO
// --------------------------------------------------------
//
// Exemplifica:
//
// Classe com atributo que consiste de objeto.
// Definição de constante privada.
// Método com lançamento de exceção.

class Turma {

private:

    int codigo;
    int numero_alunos;

    // Atributo é um objeto.

    Disciplina disciplina;

    // Exemplo de constante privada usada para definir regra de negócio.

    const static int LIMITE;

public:

    // Construtor inline.

    Turma(int codigo){
        this->codigo = codigo;
        numero_alunos = 0;
    }
    // Método inline com atribuição de objeto.

    void setDisciplina (Disciplina disciplina){
        this->disciplina = disciplina;
    }

    // Métodos inline e constantes.

    int getCodigo() const {
        return codigo;
    }

    int getNumeroAlunos() const {
        return numero_alunos;
    }

    Disciplina getDisciplina() const {
        return disciplina;
    }

    // Método não inline com lançamento de exceção.

    void setNumeroAlunos(int numero_alunos) throw(invalid_argument);
};

// EXEMPLO
// --------------------------------------------------------

// Exemplifica:
//
// Relacionamento entre objetos de diferentes classes.


class Desenvolvedor {
    private:
        string nome;
    public:
        void setNome(string nome) {
            this->nome = nome;
        }

        string getNome() const {
            return nome;
        }
};


class Projeto {
private:
    // Referência para deesenvolveodr.

    // Relacionamento 1 para 1 unidirecional (de Projeto para Desenvolvedor).

    Desenvolvedor *desenvolvedor;

public:

    void setDesenvolvedor(Desenvolvedor *desenvolvedor){
        this->desenvolvedor = desenvolvedor;
    }

    Desenvolvedor* getDesenvolvedor() const{
        return desenvolvedor;
    }
};

// EXEMPLO
// --------------------------------------------------------
//
// Exemplifica:
//
// Classe que representa um domínio (com código de validação).


class Codigo {
private:
        int codigo;

        const static int LIMITE;

        // Ilustra método de validação.

        void validar(int) throw (invalid_argument);

public:
        void setCodigo(int) throw (invalid_argument);

        // Ilustra método inline.

        int getCodigo(){
            return codigo;
        }
};


// EXEMPLO
// --------------------------------------------------------
//

// Forward declaration.

class Curso;

// Classe que modela elemento da lista.

class ElementoLista{

    // Declaração de classe amiga.

    friend class Curso;

private:
    const Disciplina *disciplina;   // Disciplina associada ao elemento.
                                    // Exemplifica ponteiro para constante.
    ElementoLista *proximo;         // Próximo elemento na lista de elementos.
};

// Classe com referências para múltiplos objetos.

class Curso {

private:

    Codigo codigo;

    // Primeiro elemento da lista.

    // Relacionamento 1 para N unidirecional (de curso para disciplina).

    ElementoLista *primeiroElemento;

public:

    // Método construtor inline.

    Curso(){
        primeiroElemento = NULL;
    }

    // Destrutor.

    ~Curso();

    // Método para estabelecer um relacionamento.

    // Exemplo de passagem por referência sem permitir alteração da mesma.

    void setDisciplina(const Disciplina *disciplina);

    // Exemplo de passagem por valor;

    void setCodigo(Codigo codigo){

        // Ocorre cópia do objeto.

        this->codigo = codigo;
    }

    Codigo getCodigo() {
        return codigo;
    }
};

// EXEMPLO
// --------------------------------------------------------
//
// Exemplifica:
//
// Teste de unidade de classe que representa um domínio.

class TUCodigo {
private:

    // Definições de constantes com o intuito de evitar numeros mágicos.

    const static int VALOR_VALIDO;
    const static int VALOR_INVALIDO;

    Codigo *codigo;         // Referência para o objeto a ser testado.

    int estado;             // Estado do teste.

    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();
public:

    // Definições de constantes para reportar resultado do teste.

    const static int SUCESSO;
    const static int FALHA;

    int run();
};

// EXEMPLO
// --------------------------------------------------------
//
// Exemplifica:
//
// Hierarquia de classes.

// Classe no topo da hierarquia.

class Aluno {

    // Atributos e métodos privados.

private:

    // Atributos de instância.

    int matricula;

// Atributos e métodos protegidos.

protected:

    int creditos;

// Atributos e métodos públicos.

 public:

    // Construtores.

    Aluno(int);

    // Métodos inline posteriormente definidos.

    inline void setMatricula(int);
    inline int getMatricula() const;
    inline int getCreditos() const;

    // Método abstrato.

    virtual void setCreditos(int) = 0;
};

inline void Aluno::setMatricula(int matricula){
    this->matricula = matricula;
    }

inline int Aluno::getCreditos() const {
        return creditos;
    }

inline int Aluno::getMatricula() const {
        return matricula;
    }

// Classes derivadas da hierarquia.

class AlunoGraduacao:Aluno {

private:

    // Constante privada.

    const static int LIMITE;

public:

    AlunoGraduacao(int creditos):Aluno(creditos){}

    void setCreditos(int);
};

// EXEMPLO 5
// --------------------------------------------------------

class AlunoPosGraduacao:Aluno {

private:

    // Declaralção de atributo não herdado.

    int telefone;

public:

    AlunoPosGraduacao(int, int);

    // Métodos inline posteriormente definidos.

    inline void setTelefone(int);
    inline int getTelefone() const;

    void setCreditos(int);
};

// Definição de métodos inline.

inline void AlunoPosGraduacao::setTelefone(int telefone) {
    this->telefone = telefone;
}

inline int AlunoPosGraduacao::getTelefone() const {
    return telefone;
}


#endif // DOMINIOS_H_INCLUDED
