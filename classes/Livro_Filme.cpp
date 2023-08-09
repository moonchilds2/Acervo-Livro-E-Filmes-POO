#include "Livro_Filme.hpp"

Livro::Livro(string nome, string autor, string genero, int paginas, int pontuacao) : Item(nome, genero, pontuacao){
	this->autor = autor;
	this->paginas = paginas;
	this->prazoDevolucao = 21;
	
}


string Livro::getAutor(){
	return this->autor;
}

int Livro::getPaginas(){
	return this->paginas;
}

void Livro::descontarDias(){
	this->prazoDevolucao -= 3;
}

void Livro::imprimeInfos(){
	cout << "Titulo: " << this->nome << endl;
	cout << "Autor: " << this->autor << endl;
	cout << "Genero: " << this->genero << endl;
	cout << "Quantidade de Paginas: " << this->paginas << endl;
	cout << "Prazo de devolucao: " << this->prazoDevolucao << " dias.";
}




Filme::Filme(string nome, string diretor, string genero, string tempo, int pontuacao) : Item(nome, genero, pontuacao){
	this->diretor = diretor;
	this->tempo = tempo;
	this->prazoDevolucao = 10;
}


string Filme::getDiretor(){
	return this->diretor;
}


string Filme::getTempo(){
	return this->tempo;
}


void Filme::descontarDias(){
	this->prazoDevolucao -= 2;
}	


void Filme::imprimeInfos(){
	cout << "Titulo: " << this->nome << endl;
	cout << "Diretor: " << this->diretor << endl;
	cout << "Genero: " << this->genero << endl;
	cout << "Tempo de filme: " << this->tempo << endl;
	cout << "Prazo de devolucao: " << this->prazoDevolucao << " dias.";
}
