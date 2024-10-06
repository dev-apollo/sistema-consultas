#ifndef CONSULTAS_HPP
#define CONSULTAS_HPP
#include <string>
#include <vector>
#include "pacientes.hpp"
#include "medicos.hpp"
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
vector<string> getPacientesByEspecialidade(vector<Consulta> consultas, vector<Medico> medicos);
int qtdConsultasPorMedico(vector<Consulta> consultas, vector<Medico> medicos);
vector<string> historicoReceitas(vector<Consulta> consultas, vector<Medico> medicos,vector<Paciente> pacientes);
bool verificarIdMedico(int id, vector<Medico> medicos);
bool verificarIdPaciente(int id, vector<Paciente> pacientes);
#endif