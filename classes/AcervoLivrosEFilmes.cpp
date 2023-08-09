#include "AcervoLivrosEFilmes.hpp"

void AcervoLivros::addLivro(string nome, string autor, string genero, int paginas, int pontuacao){

	Livro* novoLivro = new Livro(nome, autor, genero, paginas, pontuacao);
	
	string email;
	cout << "Digite o seu email para confirmar a disponibilizacao da obra e atualizar sua pontuacao." << endl;
	cin >> email;
	
	bool validado = this->validaUsuario(email);
	
	if(validado == true){
		this->livrosDisponiveis.push_back(novoLivro);
		this->usuarioValidado(email)->addLivroDoado(novoLivro);
		this->usuarioValidado(email)->addPontos(pontuacao * 2);
		
		cout << "\nO livro foi adicionado ao acervo com sucesso." << endl << endl;

	}else{
		cout << "Nao foi possivel confirmar o email, tente adicionar novamente." << endl;
	}

	
}

void AcervoLivros::addDiretamente(string nome, string autor, string genero, int paginas, int pontuacao){

	Livro* novoLivro = new Livro(nome, autor, genero, paginas, pontuacao);

	this->livrosDisponiveis.push_back(novoLivro);
}


void AcervoLivros::realizarEmprestimo(string nomeLivro){

	int pontuacao;
	string email;
	
	cout << "Digite o seu email para confirmar o emprestimo e atualizar sua pontuacao." << endl;
	cin >> email;
	
	bool validado = this->validaUsuario(email);
	bool achou;
		
	if(validado == true){
	
		for(int i = 0; i < (this->livrosDisponiveis.size()); i++){
			bool nomesIguais = this->comparaNomes(livrosDisponiveis[i]->getNome(), nomeLivro);
			if(nomesIguais == true){
				achou = true;
				this->usuarioValidado(email)->addLivroEmprestado(nomeLivro, livrosDisponiveis[i]->getAutor(), livrosDisponiveis[i]->getGenero(), livrosDisponiveis[i]->getPaginas(), livrosDisponiveis[i]->getPontuacao());
				pontuacao = livrosDisponiveis[i]->getPontuacao();
			}
		}
			
		if(achou){
			
			this->usuarioValidado(email)->rmvPontos(pontuacao);
			this->ajustarPrazo();
			this->addAosEmprestados(nomeLivro);
			this->rmvLivro(nomeLivro);
			
			cout << "O emprestimo foi efetuado com sucesso." << endl;
		}else{
			cout << "Este livro nao existe no acervo" << endl;
		}
		
		
	}else{
		cout << "Nao foi possivel confirmar o email, tente realizar o emprestimo novamente." << endl;
	}
	
	
}


void AcervoLivros::ajustarPrazo(){
	for(int i = 0; i < livrosEmprestados.size(); i++){
		livrosEmprestados[i]->descontarDias();
		
		if(livrosEmprestados[i]->getPrazoDevolucao() == 0){
			this->livrosDisponiveis.push_back(livrosEmprestados[i]);
			livrosEmprestados.erase(livrosEmprestados.begin()+i);
		}
	}
	
}


void AcervoLivros::mostrarLivrosDisponiveis(){

	cout << "Livros Disponiveis no acervo: " << endl;
	for(int i = 0; i < (this->livrosDisponiveis.size()); i++){
		cout << "\nLivro " << i + 1 << endl;
		livrosDisponiveis[i]->imprimeInfos();
		cout << endl;
	}
}


void AcervoLivros::mostrarLivrosEmprestados(){

	cout << "Lista dos livros emprestados: " << endl << endl;
	for(int i = 0; i < (this->livrosEmprestados.size()); i++){
		
		cout << "Livro " << i + 1 << endl;
		livrosEmprestados[i]->imprimeInfos();
		cout << endl;
	}
}


void AcervoLivros::rmvLivro(string nome){

	for(int i = 0; i < (this->livrosDisponiveis.size()); i++){	
		bool nomesIguais = this->comparaNomes(livrosDisponiveis[i]->getNome(), nome);	
		if(nomesIguais == true){
			livrosDisponiveis.erase(livrosDisponiveis.begin()+i);
		}
	}
}


void AcervoLivros::addAosEmprestados(string nomeLivro){
	for(int i = 0; i < (this->livrosDisponiveis.size()); i++){	
		bool nomesIguais = this->comparaNomes(livrosDisponiveis[i]->getNome(), nomeLivro);	
		if(nomesIguais == true){
			this->livrosEmprestados.push_back(livrosDisponiveis[i]);
		}
	}
}

void AcervoLivros::buscaLivro(string nome){
	
	bool achou;
	bool emprestado;
	
	for(int i = 0; i < this->livrosDisponiveis.size(); i++){
		bool nomesIguais = this->comparaNomes(livrosDisponiveis[i]->getNome(), nome);
	
		if(nomesIguais == true){
			achou = true;
			cout << "O livro buscado esta disponivel para emprestimo." << endl;
			cout << "Informacoes completas do livro: " << endl;
			livrosDisponiveis[i]->imprimeInfos();
		}
	}
	
	if(achou != true){
	
		for(int i = 0; i < this->livrosEmprestados.size(); i++){
			if(this->comparaNomes(livrosEmprestados[i]->getNome(), nome) == true){
				emprestado = true;
				cout << "O livro buscado ja foi emprestado, mas estara disponivel em ";
				cout << livrosEmprestados[i]->getPrazoDevolucao() << " dias." << endl;
			}
		}
		
		if(emprestado != true){
			cout << "O livro buscado nao existe em nosso acervo, sentimos muito." << endl;
		}
	
	}
	
	
}


void AcervoLivros::buscaAutor(string nomeAutor){

	bool achou = false;
	vector<Livro*> livrosEncontrados;
	
	for(int i = 0; i < this->livrosDisponiveis.size(); i++){
		bool nomesIguais = this->comparaNomes(livrosDisponiveis[i]->getAutor(), nomeAutor);
		if(nomesIguais == true){
			achou = true;
			livrosEncontrados.push_back(livrosDisponiveis[i]);
		}
	}

	if(achou == true){
		cout << "Livros encontrados do(a) autor(a) " << nomeAutor << ":" << endl << endl;
		for(int i = 0; i < livrosEncontrados.size(); i++){
			cout << "Livro " << i+1 << ":" << endl;
			livrosEncontrados[i]->imprimeInfos();
			cout << endl;
		}
	}else{
		cout << "Nao foram encontrados livros deste(a) autor(a) no acervo, sentimos muito." << endl;
	}
}


void AcervoLivros::buscaGenero(string nomeGenero){
	bool achou = false;
	vector<Livro*> livrosEncontrados;
	
	for(int i = 0; i < (this->livrosDisponiveis.size()); i++){
		bool nomesIguais = this->comparaNomes(livrosDisponiveis[i]->getGenero(), nomeGenero);
		if(nomesIguais == true){
			achou = true;
			livrosEncontrados.push_back(livrosDisponiveis[i]);
		}
	}

	if(achou == true){
		cout << "Livros encontrados do genero " << nomeGenero << ":" << endl << endl;
		for(int i = 0; i < livrosEncontrados.size(); i++){
			cout << "Livro " << i+1 << ":" << endl;
			livrosEncontrados[i]->imprimeInfos();
			cout << endl;
		}
	}else{
		cout << "Nao foram encontrados livros deste genero no acervo, sentimos muito." << endl;
	}
}



void AcervoFilmes::addFilme(string nome, string diretor, string genero, string tempo, int pontuacao){

	Filme* novoFilme = new Filme(nome, diretor, genero, tempo, pontuacao);
	
	string email;
	cout << "Digite o seu email para confirmar a disponibilizacao da obra e atualizar sua pontuacao." << endl;
	cin >> email;
	
	bool validado = this->validaUsuario(email);
	
	if(validado == true){
		this->filmesDisponiveis.push_back(novoFilme);
		this->usuarioValidado(email)->addFilmeDoado(novoFilme);
		this->usuarioValidado(email)->addPontos(pontuacao * 2);
		
		cout << "\nO filme foi adicionado ao acervo com sucesso." << endl << endl;
		
	}else{
		cout << "Nao foi possivel confirmar o email, tente adicionar novamente." << endl;
	}

	
}

void AcervoFilmes::addDiretamente(string nome, string diretor, string genero, string tempo, int pontuacao){

	Filme* novoFilme = new Filme(nome, diretor, genero, tempo, pontuacao);

	this->filmesDisponiveis.push_back(novoFilme);
}


void AcervoFilmes::realizarEmprestimo(string nomeFilme){

	int pontuacao;
	string email;
	
	cout << "Digite o seu email para confirmar o emprestimo e atualizar sua pontuacao." << endl;
	cin >> email;
	
	bool validado = this->validaUsuario(email);
	bool achou;
		
	if(validado == true){
	
		for(int i = 0; i < this->filmesDisponiveis.size(); i++){
			bool nomesIguais = this->comparaNomes(filmesDisponiveis[i]->getNome(), nomeFilme);
			if(nomesIguais == true){
				pontuacao = filmesDisponiveis[i]->getPontuacao();
				this->usuarioValidado(email)->addFilmeEmprestado(filmesDisponiveis[i]->getNome(), filmesDisponiveis[i]->getDiretor(), filmesDisponiveis[i]->getGenero(), filmesDisponiveis[i]->getTempo(), filmesDisponiveis[i]->getPontuacao());
				achou = true;
			}
		}
		
		if(achou){
			this->usuarioValidado(email)->rmvPontos(pontuacao);
			this->ajustarPrazo();
			this->addAosEmprestados(nomeFilme);
			this->rmvFilme(nomeFilme);
				
			cout << "O emprestimo foi efetuado com sucesso." << endl;
		}else{
			cout << "Este filme nao existe no acervo." << endl;
		}
		
		
	}else{
		cout << "Nao foi possivel confirmar o email, tente realizar o emprestimo novamente." << endl;
	}
	
	
}


void AcervoFilmes::rmvFilme(string nomeFilme){
	for(int i = 0; i < (this->filmesDisponiveis.size()); i++){	
		bool nomesIguais = this->comparaNomes(filmesDisponiveis[i]->getNome(), nomeFilme);	
		if(nomesIguais == true){
			filmesDisponiveis.erase(filmesDisponiveis.begin()+i);
		}
	}
}


void AcervoFilmes::addAosEmprestados(string nomeFilme){
	for(int i = 0; i < (this->filmesDisponiveis.size()); i++){	
		bool nomesIguais = this->comparaNomes(filmesDisponiveis[i]->getNome(), nomeFilme);	
		if(nomesIguais == true){
			this->filmesEmprestados.push_back(filmesDisponiveis[i]);
		}
	}
}


void AcervoFilmes::ajustarPrazo(){
	for(int i = 0; i < filmesEmprestados.size(); i++){
		filmesEmprestados[i]->descontarDias();
		
		if(filmesEmprestados[i]->getPrazoDevolucao() == 0){
			this->filmesDisponiveis.push_back(filmesEmprestados[i]);
			filmesEmprestados.erase(filmesEmprestados.begin()+i);
		}
	}
	
}


void AcervoFilmes::buscaFilme(string nomeFilme){
	
	bool achou;
	bool emprestado;
	
	for(int i = 0; i < (this->filmesDisponiveis.size()); i++){
		bool nomesIguais = this->comparaNomes(filmesDisponiveis[i]->getNome(), nomeFilme);
	
		if(nomesIguais == true){
			achou = true;
			cout << "O filme buscado esta disponivel para emprestimo." << endl;
			cout << "Informacoes completas do filme: " << endl;
			filmesDisponiveis[i]->imprimeInfos();
		}
	}
	
	if(achou != true){
	
		for(int i = 0; i < this->filmesEmprestados.size(); i++){
			bool nomesIguais = this->comparaNomes(filmesEmprestados[i]->getNome(), nomeFilme);
			if(nomesIguais == true){
				emprestado = true;
				cout << "O filme buscado ja foi emprestado, mas estara disponivel em ";
				cout << filmesEmprestados[i]->getPrazoDevolucao() << " dias." << endl;
			}
		}
		
		if(emprestado != true){
			cout << "O filme buscado nao existe em nosso acervo, sentimos muito." << endl;
		}
	
	}
	
}


void AcervoFilmes::buscaDiretor(string nomeDiretor){
	
	bool achou = false;
	vector<Filme*> filmesEncontrados;
	
	for(int i = 0; i < this->filmesDisponiveis.size(); i++){
		bool nomesIguais = this->comparaNomes(filmesDisponiveis[i]->getDiretor(), nomeDiretor);
		if(nomesIguais == true){
			achou = true;
			filmesEncontrados.push_back(filmesDisponiveis[i]);
		}
	}

	if(achou == true){
		cout << "Filmes encontrados do(a) autor(a) " << nomeDiretor << ":" << endl << endl;
		for(int i = 0; i < filmesEncontrados.size(); i++){
			cout << "Livro " << i+1 << ":" << endl;
			filmesEncontrados[i]->imprimeInfos();
			cout << endl;
		}
	}else{
		cout << "Nao foram encontrados filmes deste(a) autor(a) no acervo, sentimos muito." << endl;
	}
}


void AcervoFilmes::buscaGenero(string nomeGenero){
	bool achou = false;
	vector<Filme*> filmesEncontrados;
	
	for(int i = 0; i < this->filmesDisponiveis.size(); i++){
		bool nomesIguais = this->comparaNomes(filmesDisponiveis[i]->getGenero(), nomeGenero);
		if(nomesIguais == true){
			achou = true;
			filmesEncontrados.push_back(filmesDisponiveis[i]);
		}
	}

	if(achou == true){
		cout << "Filmes encontrados do genero " << nomeGenero << ":" << endl << endl;
		for(int i = 0; i < filmesEncontrados.size(); i++){
			cout << "Livro " << i+1 << ":" << endl;
			filmesEncontrados[i]->imprimeInfos();
			cout << endl;
		}
	}else{
		cout << "Nao foram encontrados filmes deste genero no acervo, sentimos muito." << endl;
	}
}


void AcervoFilmes::mostrarFilmesDisponiveis(){

	cout << "Filmes disponiveis no acervo: " << endl << endl;
	for(int i = 0; i < (this->filmesDisponiveis.size()); i++){
		cout << "\nFilme " << i+1 << endl;
		filmesDisponiveis[i]->imprimeInfos();
		cout << endl;
	}
}


void AcervoFilmes::mostrarFilmesEmprestados(){

	cout << "Lista dos filmes emprestados: " << endl << endl;
	
	for(int i = 0; i < (this->filmesEmprestados.size()); i++){
		cout << "Filme " << i + 1 << endl;
		filmesEmprestados[i]->imprimeInfos();
		cout << endl;
	}
}