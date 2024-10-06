#ifndef PACIENTES_HPP
#define PACIENTES_HPP
#include <string>
#include <vector>
using namespace std;

struct Paciente {
    int id;
    string nome = "";
    string cpf;
    string endereco;
};

vector<Paciente> getPacientes(string enderecoLista);
void cadastrarPaciente(string enderecoArquivo);
Paciente getPacienteById(vector<Paciente> pacientes, int id);

#endif