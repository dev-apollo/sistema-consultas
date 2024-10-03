#ifndef MEDICOS_HPP
#define MEDICOS_HPP
#include <string>
#include <vector>
using namespace std;

struct Medico {
    int id;
    string nome = "";
    char sexo;
    string especialidade;
};

vector<Medico> getMedicos(string enderecoLista);
Medico getMedicoByNome(vector<Medico> medicos, string nome);
Medico getMedicoByEspecialidade(vector<Medico> medicos, string especialidade);
Medico getMedicoById(vector<Medico> medicos, int id);
#endif