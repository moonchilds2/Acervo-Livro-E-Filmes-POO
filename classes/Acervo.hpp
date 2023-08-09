#include <algorithm>
#include "Livro_Filme.cpp"
#include "Usuario.cpp"

class Acervo{
	
	protected:
		vector<Usuario*> usuarios;
	
	public:
					
		void cadastrarUsuario(string nome, string email, Endereco* endereco);
		void mostrarUsuarios();
		void relatorioUsuariosLivros();
		void relatorioUsuariosFilmes();
		bool validaUsuario(string emailUsuario);
		Usuario* usuarioValidado(string email);	
		bool comparaNomes(string nome1, string nome2);
};
