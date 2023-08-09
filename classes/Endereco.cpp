#include "Endereco.hpp"

Endereco::Endereco(string cidade, string rua, string numero, string bairro){
	
	this->cidade = cidade;
	this->rua = rua;
	this->numero = numero;
	this->bairro = bairro;

}


void Endereco::imprimeEndereco(){
	cout << this->cidade << ", " << this->rua << ", " << this->numero << ", " << this->bairro << endl;
}