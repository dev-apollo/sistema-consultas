#include "consultas.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include "utilitarios.hpp"
using namespace std;

void cadastrarConsulta(string enderecoArquivo)
{
    Consulta consulta;
    ofstream arquivo(enderecoArquivo, ios::app);
    if(!arquivo.is_open()){
        cout<<"Erro ao abrir a lista de consultas"<<endl;
    }
    int idPaciente, idMedico;
    cout<<"Insira o id do paciente: ";
    cin>>idPaciente;
    cout<<"Insira o id do medico: ";
    cin >> idMedico;
    cout<<"Insira a data da consulta:[dd/mm/yyyy] ";
    cin.ignore();
    getline(cin, consulta.data);
    cout<<"Insira a queixa do paciente do paciente: ";
    // cin.ignore();
    getline(cin, consulta.queixaPaciente);
    cout << "Insira a receita: ";
    //cin.ignore();
    getline(cin,consulta.receitaMedico);
    arquivo<<consulta.idPaciente<<","<<consulta.idMedico<<","<<consulta.data<<","<<consulta.queixaPaciente<<","<<consulta.receitaMedico<<endl;   
    arquivo.close();    
}

vector<Consulta> readConsultas(string enderecoArquivo)
{
    vector<Consulta> consultas;
    ifstream arquivo(enderecoArquivo);
    if(!arquivo.is_open()){
        cout<<"Erro ao abrir a lista de consultas."<<endl;
    }
    string linha;
    while(getline(arquivo, linha)){
        istringstream iss(linha);
        string token;
        vector<string> dadosConsulta;
        while(getline(iss, token, ',')){
            dadosConsulta.push_back(token);
        }
        Consulta consulta = {stoi(dadosConsulta[0]), stoi(dadosConsulta[1]), dadosConsulta[2], dadosConsulta[3], dadosConsulta[4]};
        consultas.push_back(consulta);
    }
    arquivo.close();
    return consultas;
}

vector<Paciente> getPacientesByDoctor_(vector<Paciente> pacientes, vector<Consulta> consultas, int idMedico)
{
    vector<Paciente> pacienteEncontrado;
    for(Consulta c: consultas){
        if(c.idMedico == idMedico){
            pacienteEncontrado.push_back(getPacienteById(pacientes, c.idPaciente));
        }
    }
    return pacienteEncontrado;
}
