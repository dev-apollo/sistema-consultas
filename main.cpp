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
    vector<Paciente> pacientesEspecificos = getPacientesByDoctor_(pacientes,consultas, 2);
    for(Paciente paciente: pacientesEspecificos){
        cout<<paciente.nome<<endl;
    }
}