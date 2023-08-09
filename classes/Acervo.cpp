#include "Acervo.hpp"


void Acervo::cadastrarUsuario(string nome, string email, Endereco* endereco){
	
	Usuario* novoUsuario = new Usuario(nome, email, endereco);
	
	this->usuarios.push_back(novoUsuario);
	
}


void Acervo::mostrarUsuarios(){
	
	for(int i = 0; i < (this->usuarios.size()); i++){
		cout << "Usuario " << i+1 << endl;
		usuarios[i]->mostrarInfos();
	}
}


void Acervo::relatorioUsuariosLivros(){
	for(int i = 0; i < this->usuarios.size(); i++){
		usuarios[i]->getLivrosDoados();
		usuarios[i]->getLivrosEmprestados();
		usuarios[i]->getFilmesDoados();
		usuarios[i]->getFilmesEmprestados();		
	}
}

void Acervo::relatorioUsuariosFilmes(){
	for(int i = 0; i < this->usuarios.size(); i++){
		usuarios[i]->getFilmesDoados();
		usuarios[i]->getFilmesEmprestados();		
	}
}

bool Acervo::validaUsuario(string emailUsuario){

	for(int i = 0; i < (this->usuarios.size()); i++){
		if(usuarios[i]->getEmail() == emailUsuario){
			return true;
		}		
	}
	
	return false;
	
}

Usuario* Acervo::usuarioValidado(string email){
	for(int i = 0; i < (this->usuarios.size()); i++){
		if(usuarios[i]->getEmail() == email){
			return usuarios[i];
		}		
	}
	
	return 0;
}

bool Acervo::comparaNomes(string nome1, string nome2){
	
	transform(nome2.begin(), nome2.end(), nome2.begin(), ::tolower);
    transform(nome1.begin(), nome1.end(), nome1.begin(), ::tolower);

    if(nome1 == nome2){
        return true;
    }
    return false;
}