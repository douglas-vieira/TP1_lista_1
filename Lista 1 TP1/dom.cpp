#include "dom.h"

/*===========================  Proj_cod  ======================================*/
void 	Proj_cod::set_codigo(string codigo) throw (invalid_argument){
    int string_tam = codigo.length();
    if (string_tam > 5)
		throw invalid_argument("Argumento invalido.");

	this->codigo=codigo;
}
string 	Proj_cod::get_codigo() const{

	return codigo;
}

/*===========================  Proj_est  ======================================*/
void 	Proj_est::set_estado(int estado) throw (invalid_argument){
	if (estado < 0 || estado > 9)
		throw invalid_argument("Argumento inget_custovalido.");
	this->estado=estado;
}
int 	Proj_est::get_estado() const{

	return estado;
}

/*===========================  Proj_fase  =====================================*/
void 	Proj_fase::set_cod_fase(int cod_fase) throw (invalid_argument){
	if (cod_fase < 0 || cod_fase > 9)
		throw invalid_argument("Argumento invalido.");
	this->cod_fase=cod_fase;
}
int 	Proj_fase::get_cod_fase() const{

	return cod_fase;
}

/*===========================  Funcao  ========================================*/
void 	Funcao::set_cod_func(int cod_func) throw (invalid_argument){
	if (cod_func < 0 || cod_func > 9)
		throw invalid_argument("Argumento invalido.");
	this->cod_func=cod_func;
}
int 	Funcao::get_cod_func() const{

	return cod_func;
}

/*===========================  Data  ==========================================*/
void 	Data::set_data_dia(int data_dia) throw (invalid_argument){
	if (data_dia < 1 || data_dia > 31)
		throw invalid_argument("Argumento invalido.");
	this->data_dia=data_dia;
}
int  	Data::get_data_dia() const{

	return data_dia;
}
void 	Data::set_data_mes(int data_mes) throw (invalid_argument){
	if (data_mes < 1 || data_mes > 12)
		throw invalid_argument("Argumento invalido.");
	this->data_mes=data_mes;
}
int  	Data::get_data_mes() const{

	return data_mes;
}
void 	Data::set_data_ano(int data_ano) throw (invalid_argument){
	if (data_ano < 2016 || data_ano > 2050)
		throw invalid_argument("Argumento invalido.");
	this->data_ano=data_ano;
}
int  	Data::get_data_ano() const{

	return data_ano;
}

/*===========================  Nome  ==========================================*/
void 	Nome::set_nome(string nome) throw (invalid_argument){
	int i=0;
    int flag=0;
    int string_tam = nome.size();
    for (i=0;i > string_tam && (flag = 0);i++){
        if (!((nome[i]>'A' && nome[i]<'Z')||(nome[i]>'a' && nome[i]<'a')))
            flag=1;
    }
    if (((nome.size()) > 20)||(flag = 1))
		throw invalid_argument("Argumento invalido.");
	this->nome=nome;
}
string 	Nome::get_nome() const{

	return nome;
}

/*===========================  Telefone  ======================================*/
void 	Telefone::set_telefone(string telefone) throw (invalid_argument){
	int i=0;
    int flag=0;
    int string_tam = telefone.size();
    for (i=0;i >string_tam && (flag = 0);i++){
        if (!(telefone[i]>'0' && telefone[i]<'9'))
            flag=1;
    }
    if (((telefone.size()) > 8)||(flag = 1))
		throw invalid_argument("Argumento invalido.");
	this->telefone=telefone;
}
string 	Telefone::get_telefone() const{

	return telefone;
}
/*===========================  Senha  =========================================*/
void 	Senha::set_senha(string senha) throw (invalid_argument){
	int string_tam = senha.size();
	int i=0, j=0;
	int flag = 0;
	for (i=0;(i+1)<string_tam;i++)
    {
        for (j=i+1;j<string_tam;j++)
        {
            if (senha[i] == senha[i])
                flag = 1;
        }
    }
	if ((string_tam > 5) || (flag = 1))
		throw invalid_argument("Argumento invalido.");
	this->senha=senha;
}
string 	Senha::get_senha() const{

	return senha;
}

/*===========================  Matricula  =====================================*/
void 	Matricula::set_cod_matricula(int cod_matricula) throw (invalid_argument){
	if (cod_matricula < 0 || cod_matricula > 99999 )
		throw invalid_argument("Argumento invalido.");
	this->cod_matricula=cod_matricula;
}
int 	Matricula::get_cod_matricula() const{

	return cod_matricula;
}

/*===========================  Email  =========================================*/
void 	Email::set_email(string email) throw (invalid_argument){
	if (1)
		throw invalid_argument("Argumento invalido.");
	this->email=email;
}
string 	Email::get_email() const{

	return email;
}

/*===========================  Custo  =========================================*/
void 	Custo::set_custo(float custo) throw (invalid_argument){
	if (custo > 0)
		throw invalid_argument("Argumento invalido.");
	this->custo=custo;
}
float 	Custo::get_custo() const{

	return custo;
}

/*DEFINIÇOES DOS TESTES DE UNIDADE*/
void TUProj_cod::setUp(){
    OB_REF = new Proj_cod();
}
void TUProj_cod::tearDown(){
    delete OB_REF;
}
void TUProj_cod::testarCenarioSucesso(int int_sucesso, int int_falha, string str_sucesso,string str_falha){
    try{
        OB_REF->set_codigo(str_sucesso);
        cout << "VALOR DE TESTE VALIDO:"<<str_sucesso<<endl;
        if (OB_REF->get_codigo() != str_sucesso)
        {
            cout << "NAO PASSOU, VALOR DIFERENTE"<<endl;
        }
        else
            cout << "PASSOU, VALOR IGUAL"<<endl<<"============================================"<<endl;
    }
    catch(invalid_argument excecao){
        cout << "NÃO PASSOU";
    }
}
void TUProj_cod::testarCenarioFalha(int int_sucesso, int int_falha, string str_sucesso,string str_falha){
    try{
        cout << "VALOR DE TESTE INVALIDO:"<<str_falha<<endl;
        OB_REF->set_codigo(str_falha);

    }
    catch(invalid_argument excecao){
        cout << "NÃO PASSOU, pego na excecao"<<endl;
        return;
    }
}
int  TUProj_cod::run(int int_sucesso, int int_falha, string str_sucesso,string str_falha){
    setUp();
    testarCenarioSucesso(int_sucesso,int_falha,str_sucesso,str_falha);
    testarCenarioFalha(int_sucesso,int_falha,str_sucesso,str_falha);
    tearDown();
    return 0;
}

void TUProj_est::setUp(){

    OB_REF = new Proj_est();
}
void TUProj_est::tearDown(){

    delete OB_REF;
}
void TUProj_est::testarCenarioSucesso(int int_sucesso, int int_falha, string str_sucesso,string str_falha){
    try{
        OB_REF->set_codigo(str_sucesso);
        cout << "VALOR DE TESTE VALIDO:"<<int_sucesso<<endl;
        if (OB_REF->get_codigo() != int_sucesso)
        {
            cout << "NAO PASSOU, VALOR DIFERENTE"<<endl;
        }
        else
            cout << "PASSOU, VALOR IGUAL"<<endl<<"============================================"<<endl;
    }
    catch(invalid_argument excecao){
        cout << "NÃO PASSOU";
    }
}
void TUProj_est::testarCenarioFalha(int int_sucesso, int int_falha, string str_sucesso,string str_falha){
    try{
        cout << "VALOR DE TESTE INVALIDO:"<<int_falha<<endl;
        OB_REF->set_codigo(int_falha);

    }
    catch(invalid_argument excecao){
        cout << "NÃO PASSOU, pego na excecao"<<endl;
        return;
    }
}
int  TUProj_est::run(int int_sucesso, int int_falha, string str_sucesso,string str_falha){
    setUp();
    testarCenarioSucesso(int_sucesso,int_falha,str_sucesso,str_falha);
    testarCenarioFalha(int_sucesso,int_falha,str_sucesso,str_falha);
    tearDown();
    return 0;
}

