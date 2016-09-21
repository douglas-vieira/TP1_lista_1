
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

#endif
