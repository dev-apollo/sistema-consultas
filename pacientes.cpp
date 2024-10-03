#include "pacientes.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include "utilitarios.hpp"
using namespace std;
vector<Paciente> getPacientes(string enderecoLista)
{
    vector<Paciente> pacientes;
    ifstream arquivo(enderecoLista);
    if(!arquivo.is_open()){
        cout<<"Erro ao abrir a lista de pacientes."<<endl;
    }
    string linha;
    while(getline(arquivo, linha)){
        istringstream iss(linha);
        string token;
        vector<string> dadosPaciente;
        while(getline(iss, token, ',')){
            dadosPaciente.push_back(token);
        }
        Paciente paciente = {stoi(dadosPaciente[0]), dadosPaciente[1], dadosPaciente[2], dadosPaciente[3]};
        pacientes.push_back(paciente);
    }
    arquivo.close();
    return pacientes;
}

void cadastrarPaciente(string enderecoArquivo)
{
    Paciente paciente;
    ofstream arquivo(enderecoArquivo, ios::app);
    if(!arquivo.is_open()){
        cout<<"Erro ao abrir a lista de pacientes"<<endl;
    }
    cout<<"Insira o id do paciente: ";
    cin>>paciente.id;
    cout<<"Insira o nome do paciente: ";
    cin.ignore();
    getline(cin, paciente.nome);
    cout<<"Insira o CPF do paciente: ";
    // cin.ignore();
    getline(cin, paciente.cpf);
    cout<<"Insira o endereco do paciente: ";
    // cin.ignore();
    getline(cin, paciente.endereco);
    arquivo<<paciente.id<<","<<paciente.nome<<","<<paciente.cpf<<","<<paciente.endereco<<endl;   
    arquivo.close();
}

Paciente getPacienteById(vector<Paciente> pacientes, int id)
{
    Paciente pacienteEncontrado;
    for(Paciente paciente: pacientes){
        if(paciente.id == id){
            pacienteEncontrado = paciente;
            break;
        }
    }
    return pacienteEncontrado;
}