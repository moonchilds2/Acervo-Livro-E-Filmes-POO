#include "Item.hpp"


Item::Item(string nome, string genero, int pontuacao){
	this->nome = nome;
	this->genero = genero;
	this->pontuacao = pontuacao;
	this->prazoDevolucao = 0;
}


string Item::getNome(){
	return this->nome;
}


string Item::getGenero(){
	return this->genero;
}


int Item::getPrazoDevolucao(){
	return this->prazoDevolucao;
}


int Item::getPontuacao(){
	return this->pontuacao;
}
