// Diretivas para controle de inclus�o.

#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

// Inclus�es e defini��es de espa�o de nomes.

#include <string>
#include <stdexcept>

using namespace std;

// Declara��o de classe.

// EXEMPLO
// --------------------------------------------------------
//
// Exemplifica:
//
// Atributos e m�todos de inst�ncia e de classe.
// M�todos construtores.
// Constante p�blica.


class ContaCorrente {

    // Atributos e m�todos privados.

 private:

    // Atributos de inst�ncia.

    string nome;
    float saldo;

    // Atributo de classe.

    static int numero_contas;

    // Atributos e m�todos p�blicos.

public:

    // Constante p�blica.

    static const int NUMERO_BANCO;

    // M�todos construtores sobrecarregados.

    ContaCorrente();
    ContaCorrente(string);
    ContaCorrente(string, float);

    // M�todos de inst�ncia.

    void setNome(string);
    string getNome() const;         // M�todo const (m�todo n�o altera estado do objeto).

    void setSaldo(float);
    float getSaldo() const;         // M�todo const (m�todo n�o altera estado do objeto).

    void depositar(float);

    // M�todo de classe.

    static int getNumeroContas();
};

// EXEMPLO
// --------------------------------------------------------
//
// Exemplifica:
//
// M�todos inline.
// Defini��o de valor default para par�metro.

class Disciplina {

private:
        string nome;
        int codigo;
public:

    // Construtor inline com valores definidos para par�metros.

    Disciplina(string nome = "A DEFINIR", int codigo = 0){
        this->nome = nome;
        this->codigo = codigo;
    }

    // M�todos inline definidos na declara�ao da classe.

    void setNome(int nome){
    this->nome = nome;
    }

    string getNome() const {
        return nome;
    }

    // M�todos inline posteriormente definidos.

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
// Defini��o de constante privada.
// M�todo com lan�amento de exce��o.

class Turma {

private:

    int codigo;
    int numero_alunos;

    // Atributo � um objeto.

    Disciplina disciplina;

    // Exemplo de constante privada usada para definir regra de neg�cio.

    const static int LIMITE;

public:

    // Construtor inline.

    Turma(int codigo){
        this->codigo = codigo;
        numero_alunos = 0;
    }
    // M�todo inline com atribui��o de objeto.

    void setDisciplina (Disciplina disciplina){
        this->disciplina = disciplina;
    }

    // M�todos inline e constantes.

    int getCodigo() const {
        return codigo;
    }

    int getNumeroAlunos() const {
        return numero_alunos;
    }

    Disciplina getDisciplina() const {
        return disciplina;
    }

    // M�todo n�o inline com lan�amento de exce��o.

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
    // Refer�ncia para deesenvolveodr.

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
// Classe que representa um dom�nio (com c�digo de valida��o).


class Codigo {
private:
        int codigo;

        const static int LIMITE;

        // Ilustra m�todo de valida��o.

        void validar(int) throw (invalid_argument);

public:
        void setCodigo(int) throw (invalid_argument);

        // Ilustra m�todo inline.

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

    // Declara��o de classe amiga.

    friend class Curso;

private:
    const Disciplina *disciplina;   // Disciplina associada ao elemento.
                                    // Exemplifica ponteiro para constante.
    ElementoLista *proximo;         // Pr�ximo elemento na lista de elementos.
};

// Classe com refer�ncias para m�ltiplos objetos.

class Curso {

private:

    Codigo codigo;

    // Primeiro elemento da lista.

    // Relacionamento 1 para N unidirecional (de curso para disciplina).

    ElementoLista *primeiroElemento;

public:

    // M�todo construtor inline.

    Curso(){
        primeiroElemento = NULL;
    }

    // Destrutor.

    ~Curso();

    // M�todo para estabelecer um relacionamento.

    // Exemplo de passagem por refer�ncia sem permitir altera��o da mesma.

    void setDisciplina(const Disciplina *disciplina);

    // Exemplo de passagem por valor;

    void setCodigo(Codigo codigo){

        // Ocorre c�pia do objeto.

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
// Teste de unidade de classe que representa um dom�nio.

class TUCodigo {
private:

    // Defini��es de constantes com o intuito de evitar numeros m�gicos.

    const static int VALOR_VALIDO;
    const static int VALOR_INVALIDO;

    Codigo *codigo;         // Refer�ncia para o objeto a ser testado.

    int estado;             // Estado do teste.

    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();
public:

    // Defini��es de constantes para reportar resultado do teste.

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

    // Atributos e m�todos privados.

private:

    // Atributos de inst�ncia.

    int matricula;

// Atributos e m�todos protegidos.

protected:

    int creditos;

// Atributos e m�todos p�blicos.

 public:

    // Construtores.

    Aluno(int);

    // M�todos inline posteriormente definidos.

    inline void setMatricula(int);
    inline int getMatricula() const;
    inline int getCreditos() const;

    // M�todo abstrato.

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

    // Declaral��o de atributo n�o herdado.

    int telefone;

public:

    AlunoPosGraduacao(int, int);

    // M�todos inline posteriormente definidos.

    inline void setTelefone(int);
    inline int getTelefone() const;

    void setCreditos(int);
};

// Defini��o de m�todos inline.

inline void AlunoPosGraduacao::setTelefone(int telefone) {
    this->telefone = telefone;
}

inline int AlunoPosGraduacao::getTelefone() const {
    return telefone;
}


#endif // DOMINIOS_H_INCLUDED
