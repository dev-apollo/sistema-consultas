#include <iostream>
#include "utilitarios.hpp"
#include "medicos.hpp"
#include "pacientes.hpp"
#include "consultas.hpp"
using namespace std;

int main(){
    //cadastrarPaciente("pacientes.txt");
    vector<Consulta> consultas = readConsultas("consulta.txt");
    vector<Paciente> pacientes = getPacientes("pacientes.txt");
    vector<Medico> medicos = getMedicos("medicos.txt");

    vector<Paciente> pacientesEspecificos = getPacientesByDoctor_(pacientes,consultas, 2);
    cout << "-> Pacientes por medico " << endl;
    for(Paciente p: pacientesEspecificos){
        cout << p.nome << endl;
        cout << p.id << endl; 
        cout << p.cpf << endl;
        cout << p.endereco << endl;
        cout << "--------------" << endl;
    }

    vector<string> especialidades = getPacientesByEspecialidade(consultas,medicos);
    cout << "-> Especialidades consultadas por um paciente" << endl;
    for(string e: especialidades){
        cout << e << endl;
        cout << "----------------"<< endl;
    }

    vector<string> histReceitas = historicoReceitas(consultas, medicos,pacientes);
    cout << "-> Histórico de receitas que um médico descreveu para um paciente" << endl;
    for(string r: histReceitas){
        cout << r << endl;
        cout << "----------------"<< endl;
    }

    int qtdConsultas = qtdConsultasPorMedico(consultas, medicos);
    cout << "-> Quatidade de consultas medico" << endl;
    cout << qtdConsultas << endl;
    cout << "----------------" << endl;

   
}