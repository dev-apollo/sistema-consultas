#ifndef CONSULTAS_HPP
#define CONSULTAS_HPP
#include <string>
#include <vector>
#include "pacientes.hpp"
using namespace std;

struct Consulta {
    int idPaciente;
    int idMedico;
    string data;
    string queixaPaciente;
    string receitaMedico;
};

void cadastrarConsulta(string enderecoArquivo);
vector<Consulta> readConsultas(string enderecoArquivo);
vector<Paciente> getPacientesByDoctor_(vector<Paciente> pacientes, vector<Consulta> consultas, int idMedico);
#endif