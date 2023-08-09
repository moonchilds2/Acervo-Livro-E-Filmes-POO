#include "Usuario.hpp"

Usuario::Usuario(string nome, string email, Endereco* endereco){
	this->nome = nome;
	this->email = email;
	this->endereco = endereco;
	this->pontuacao = 0;
}

string Usuario::getNome(){
	return this->nome;
}

string Usuario::getEmail(){
	return this->email;
}

void Usuario::getEndereco(){
	this->endereco->imprimeEndereco();
}

void Usuario::addLivroDoado(Livro* novoLivro){

	this->livros_doados.push_back(novoLivro);
}

void Usuario::addLivroEmprestado(string nome, string autor, string genero, int paginas, int pontuacao){
	Livro* novoLivro = new Livro(nome, autor, genero, paginas, pontuacao);

	this->livros_emprestados.push_back(novoLivro);
}

void Usuario::addFilmeDoado(Filme* novoFilme){

	this->filmes_doados.push_back(novoFilme);
}

void Usuario::addFilmeEmprestado(string nome, string diretor, string genero, string tempo, int pontuacao){
	Filme* novoFilme = new Filme(nome, diretor, genero, tempo, pontuacao);

	this->filmes_emprestados.push_back(novoFilme);
}

void Usuario::getLivrosEmprestados(){
	cout << "\n\nLista dos livros emprestados ao usuario " << this->getNome() << endl << endl;
	for(int i=0; i < livros_emprestados.size(); i++){
		cout << "Livro " << i + 1<< ":" << endl;
		livros_emprestados[i]->imprimeInfos();
	}
}

void Usuario::getLivrosDoados(){
	cout << "\nLista dos livros doados pelo usuario " << this->getNome() << endl << endl;
	for(int i=0; i < livros_doados.size(); i++){
		cout << "Livro " << i + 1 << ":" << endl;
		livros_doados[i]->imprimeInfos();
	}
}

void Usuario::getFilmesDoados(){
	cout << "\n\nLista dos filmes doados pelo usuario " << this->getNome() << endl << endl;
	for(int i=0; i < filmes_doados.size(); i++){
		cout << "Filme " << i + 1<< ":" << endl;
		filmes_doados[i]->imprimeInfos();
	}
}

void Usuario::getFilmesEmprestados(){
	cout << "\n\nLista dos filmes emprestados ao usuario " << this->getNome() << endl << endl;
	for(int i=0; i < filmes_emprestados.size(); i++){
		cout << "Filme " << i + 1 << ":" << endl;
		filmes_emprestados[i]->imprimeInfos();
	}
}

int Usuario::getPontuacao(){
	return this->pontuacao;
}

void Usuario::mostrarInfos(){
	cout << "Nome: " << this->nome << endl;
	cout << "Email: " << this->email << endl;
	cout << "Endereco: "; this->endereco->imprimeEndereco();
	cout << "Pontuacao: " << this->pontuacao << endl << endl;
}

void Usuario::addPontos(int pontos){
	this->pontuacao += pontos;
}

void Usuario::rmvPontos(int pontos){
	this->pontuacao -= pontos;
}
