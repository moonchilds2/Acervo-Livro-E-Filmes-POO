#include "Endereco.cpp"
#include <vector>

using namespace std;


class Usuario{
	
	private:
		string nome;
		string email;
		Endereco* endereco;
		vector<Livro*> livros_doados;
		vector<Livro*> livros_emprestados;
		vector<Filme*> filmes_doados;
		vector<Filme*> filmes_emprestados;
		int pontuacao;

		
	public:	
		Usuario(string nome, string email, Endereco* endereco);
		string getNome();
		string getEmail();
		void getEndereco();
		void addLivroDoado(Livro* novoLivro);
		void addLivroEmprestado(string nome, string autor, string genero, int paginas, int pontuacao);
		void addFilmeDoado(Filme* novoFilme);
		void addFilmeEmprestado(string nome, string diretor, string genero, string tempo, int pontuacao);
		void getLivrosDoados();
		void getLivrosEmprestados();
		void getFilmesDoados();
		void getFilmesEmprestados();
		void addPontos(int pontos);
		void rmvPontos(int pontos);
		int getPontuacao();
		void mostrarInfos();
		
};
