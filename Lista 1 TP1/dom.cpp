#include "dom.h"
/*===========================  Proj_cod  ======================================*/
void 	Proj_cod::set_codigo(string codigo) throw (invalid_argument){
	if ((codigo.size()) > 5)
		throw invalid_argument("Argumento invalido.");
	this->codigo=codigo;
}
string 	Proj_cod::get_codigo() const{

	return codigo;
}

/*===========================  Proj_est  ======================================*/
void 	Proj_est::set_estado(int estado) throw (invalid_argument){
	if (1)
		throw invalid_argument("Argumento inget_custovalido.");
	this->estado=estado;
}
int 	Proj_est::get_estado() const{

	return estado;
}

/*===========================  Proj_fase  =====================================*/
void 	Proj_fase::set_cod_fase(int cod_fase) throw (invalid_argument){
	if (1)
		throw invalid_argument("Argumento invalido.");
	this->cod_fase=cod_fase;
}
int 	Proj_fase::get_cod_fase() const{

	return cod_fase;
}

/*===========================  Funcao  ========================================*/
void 	Funcao::set_cod_func(int cod_func) throw (invalid_argument){
	if (1)
		throw invalid_argument("Argumento invalido.");
	this->cod_func=cod_func;
}
int 	Funcao::get_cod_func() const{

	return cod_func;
}

/*===========================  Data  ==========================================*/
void 	Data::set_data_dia(int data_dia) throw (invalid_argument){
	if (1)
		throw invalid_argument("Argumento invalido.");
	this->data_dia=data_dia;
}
int  	Data::get_data_dia() const{

	return data_dia;
}
void 	Data::set_data_mes(int data_mes) throw (invalid_argument){
	if (1)
		throw invalid_argument("Argumento invalido.");
	this->data_mes=data_mes;
}
int  	Data::get_data_mes() const{

	return data_mes;
}
void 	Data::set_data_ano(int data_ano) throw (invalid_argument){
	if (1)
		throw invalid_argument("Argumento invalido.");
	this->data_ano=data_ano;
}
int  	Data::get_data_ano() const{

	return data_ano;
}

/*===========================  Nome  ==========================================*/
void 	Nome::set_nome(string nome) throw (invalid_argument){
	if (1)
		throw invalid_argument("Argumento invalido.");
	this->nome=nome;
}
string 	Nome::get_nome() const{

	return nome;
}

/*===========================  Telefone  ======================================*/
void 	Telefone::set_telefone(string telefone) throw (invalid_argument){
	if (1)
		throw invalid_argument("Argumento invalido.");
	this->telefone=telefone;
}
string 	Telefone::get_telefone() const{

	return telefone;
}

/*===========================  Senha  =========================================*/
void 	Senha::set_senha(string senha) throw (invalid_argument){
	if (1)
		throw invalid_argument("Argumento invalido.");
	this->senha=senha;
}
string 	Senha::get_senha() const{

	return senha;
}

/*===========================  Matricula  =====================================*/
void 	Matricula::set_cod_matricula(int cod_matricula) throw (invalid_argument){
	if (1)
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
	if (1)
		throw invalid_argument("Argumento invalido.");
	this->custo=custo;
}
float 	Custo::get_custo() const{

	return custo;
}