#include "medicos.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include "utilitarios.hpp"
using namespace std;

vector<Medico> getMedicos(string enderecoLista)
{
    vector<Medico> medicos;
    ifstream arquivo(enderecoLista);
    if(!arquivo.is_open()){
        cout<<"Erro ao abrir a lista de medicos."<<endl;
    }
    string linha;
    while(getline(arquivo, linha)){
        istringstream iss(linha);
        string token;
        vector<string> dadosMedico;
        while(getline(iss, token, ',')){
            dadosMedico.push_back(token);
        }
        Medico medico = {stoi(dadosMedico[0]), dadosMedico[1], dadosMedico[2][0], dadosMedico[3]};
        medicos.push_back(medico);
    }
    arquivo.close();
    return medicos;
}

Medico getMedicoByNome(vector<Medico> medicos, string nome)
{
    Medico medicoEncontrado;
    for(Medico medico: medicos){
        if(toLowerCase(medico.nome) == toLowerCase(nome)){
            medicoEncontrado = medico;
            break;
        }
    }
    return medicoEncontrado;
}

Medico getMedicoByEspecialidade(vector<Medico> medicos, string especialidade)
{
    Medico medicoEncontrado;
    for(Medico medico: medicos){
        if(toLowerCase(medico.especialidade) == toLowerCase(especialidade)){
            medicoEncontrado = medico;
            break;
        }
    }
    return medicoEncontrado;
}


Medico getMedicoById(vector<Medico> medicos, int id)
{
    Medico medicoEncontrado;
    for(Medico medico: medicos){
        if(medico.id == id){
            medicoEncontrado = medico;
            break;
        }
    }
    return medicoEncontrado;
}