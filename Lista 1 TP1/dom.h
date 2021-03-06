#ifndef DOM_H_INCLUDED
#define DOM_H_INCLUDED
    #include <cstring>
    #include <stdexcept>
    #include <iostream>
    using namespace std;

    class Proj_cod  {
        private:
            string codigo;
        public:
            void set_codigo(string) throw (invalid_argument);
            string get_codigo() const;
    };
    class Proj_est  {
        private:
            int estado;
        public:
            void set_estado(int) throw (invalid_argument);
            int get_estado() const;
    };
    class Proj_fase {
        private:
            int cod_fase;
        public:
            void set_cod_fase(int) throw (invalid_argument);
            int get_cod_fase() const;
    };
    class Funcao    {
        private:
            int cod_func;
        public:
            void set_cod_func(int) throw (invalid_argument);
            int get_cod_func() const;
    };
    class Data      {
        private:
            int data_dia;
            int data_mes;
            int data_ano;
        public:
            void set_data_dia(int) throw (invalid_argument);
            int  get_data_dia() const;

            void set_data_mes(int) throw (invalid_argument);
            int  get_data_mes() const;

            void set_data_ano(int) throw (invalid_argument);
            int  get_data_ano() const;
    };
    class Nome      {
        private:
            string nome;
        public:
            void set_nome(string) throw (invalid_argument);
            string get_nome() const;
    };
    class Telefone  {
        private:
            string telefone;
        public:
            void set_telefone(string) throw (invalid_argument);
            string get_telefone() const;
    };
    class Senha     {
        private:
            string senha;
        public:
            void set_senha(string) throw (invalid_argument);
            string get_senha() const;
    };
    class Matricula {
        private:
            int cod_matricula;
        public:
            void set_cod_matricula(int) throw (invalid_argument);
            int get_cod_matricula() const;
    };
    class Email     {
        private:
            string email;
        public:
            void set_email(string) throw (invalid_argument);
            string get_email() const;
    };
    class Custo     {
        private:
            float custo;
        public:
            void set_custo(float custo) throw (invalid_argument);
            float get_custo() const;
    };

    class TUProj_cod {
    private:
        Proj_cod *OB_REF;

        void setUp();
        void tearDown();
        void testarCenarioSucesso(int int_sucesso, int int_falha, string str_sucesso,string str_falha);
        void testarCenarioFalha(int int_sucesso, int int_falha, string str_sucesso,string str_falha);
    public:
        int run(int int_sucesso, int int_falha, string str_sucesso,string str_falha);
};
    class TUProj_est {
    private:
        Proj_cod *OB_REF;

        void setUp();
        void tearDown();
        void testarCenarioSucesso(int int_sucesso, int int_falha, string str_sucesso,string str_falha);
        void testarCenarioFalha(int int_sucesso, int int_falha, string str_sucesso,string str_falha);
    public:
        int run(int int_sucesso, int int_falha, string str_sucesso,string str_falha);
};
    class TUProj_fase {
    private:
        Proj_cod *OB_REF;

        void setUp();
        void tearDown();
        void testarCenarioSucesso(int int_sucesso, int int_falha, string str_sucesso,string str_falha);
        void testarCenarioFalha(int int_sucesso, int int_falha, string str_sucesso,string str_falha);
    public:
        int run(int int_sucesso, int int_falha, string str_sucesso,string str_falha);
};
    class TUFuncao {
    private:
        Proj_cod *OB_REF;

        void setUp();
        void tearDown();
        void testarCenarioSucesso(int int_sucesso, int int_falha, string str_sucesso,string str_falha);
        void testarCenarioFalha(int int_sucesso, int int_falha, string str_sucesso,string str_falha);
    public:
        int run(int int_sucesso, int int_falha, string str_sucesso,string str_falha);
};
    class TUData {
    private:
        Proj_cod *OB_REF;

        void setUp();
        void tearDown();
        void testarCenarioSucesso(int int_sucesso, int int_falha, string str_sucesso,string str_falha);
        void testarCenarioFalha(int int_sucesso, int int_falha, string str_sucesso,string str_falha);
    public:
        int run(int int_sucesso, int int_falha, string str_sucesso,string str_falha);
};
    class TUNome {
    private:
        Proj_cod *OB_REF;

        void setUp();
        void tearDown();
        void testarCenarioSucesso(int int_sucesso, int int_falha, string str_sucesso,string str_falha);
        void testarCenarioFalha(int int_sucesso, int int_falha, string str_sucesso,string str_falha);
    public:
        int run(int int_sucesso, int int_falha, string str_sucesso,string str_falha);
};
    class TUTelefone {
    private:
        Proj_cod *OB_REF;

        void setUp();
        void tearDown();
        void testarCenarioSucesso(int int_sucesso, int int_falha, string str_sucesso,string str_falha);
        void testarCenarioFalha(int int_sucesso, int int_falha, string str_sucesso,string str_falha);
    public:
        int run(int int_sucesso, int int_falha, string str_sucesso,string str_falha);
};
    class TUSenha {
    private:
        Proj_cod *OB_REF;

        void setUp();
        void tearDown();
        void testarCenarioSucesso(int int_sucesso, int int_falha, string str_sucesso,string str_falha);
        void testarCenarioFalha(int int_sucesso, int int_falha, string str_sucesso,string str_falha);
    public:
        int run(int int_sucesso, int int_falha, string str_sucesso,string str_falha);
};
    class TUMatricula {
    private:
        Proj_cod *OB_REF;

        void setUp();
        void tearDown();
        void testarCenarioSucesso(int int_sucesso, int int_falha, string str_sucesso,string str_falha);
        void testarCenarioFalha(int int_sucesso, int int_falha, string str_sucesso,string str_falha);
    public:
        int run(int int_sucesso, int int_falha, string str_sucesso,string str_falha);
};
    class TUEmail {
    private:
        Proj_cod *OB_REF;

        void setUp();
        void tearDown();
        void testarCenarioSucesso(int int_sucesso, int int_falha, string str_sucesso,string str_falha);
        void testarCenarioFalha(int int_sucesso, int int_falha, string str_sucesso,string str_falha);
    public:
        int run(int int_sucesso, int int_falha, string str_sucesso,string str_falha);
};
    class TUCusto {
    private:
        Proj_cod *OB_REF;

        void setUp();
        void tearDown();
        void testarCenarioSucesso(int int_sucesso, int int_falha, string str_sucesso,string str_falha);
        void testarCenarioFalha(int int_sucesso, int int_falha, string str_sucesso,string str_falha);
    public:
        int run(int int_sucesso, int int_falha, string str_sucesso,string str_falha);
};
#endif
