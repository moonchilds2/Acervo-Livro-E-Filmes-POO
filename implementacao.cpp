#include "implementacao.hpp"

int main(){
	
	int resposta = -1;
	
	AcervoLivros acervoLivros;
	AcervoFilmes acervoFilmes;

	obrasPreRegistradas(&acervoLivros, &acervoFilmes);
	
	
	while(resposta != 0){
		
		mostrarInterface();
		
		cin >> resposta;
		
		if(resposta == 1){	
			cadastraUsuario(&acervoFilmes, &acervoLivros);		
		}
		else if(resposta == 2){
			sessaoLivros(&acervoLivros);
		}
		else if(resposta == 3){
			sessaoFilmes(&acervoFilmes);
		}
		
	}

	acervoLivros.relatorioUsuariosLivros();
	acervoFilmes.relatorioUsuariosFilmes();
	
}