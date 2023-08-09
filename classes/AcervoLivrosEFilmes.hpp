#include "Acervo.cpp"


class AcervoLivros : public Acervo{

	private:
		vector<Livro*> livrosDisponiveis;
		vector<Livro*> livrosEmprestados;
		void rmvLivro(string nome);
		void addAosEmprestados(string nomeLivro);
		void ajustarPrazo();	
	
	public:
		void addLivro(string nome, string autor, string genero, int paginas, int pontuacao);
		void addDiretamente(string nome, string autor, string genero, int paginas, int pontuacao);
		void buscaLivro(string nome);
		void buscaAutor(string nomeAutor);
		void buscaGenero(string nomeGenero);
		void mostrarLivrosDisponiveis();
		void mostrarLivrosEmprestados();
		void realizarEmprestimo(string nomeLivro);
		
};



class AcervoFilmes : public Acervo{
	
	private:
		
		vector<Filme*> filmesDisponiveis;
		vector<Filme*> filmesEmprestados;
		void rmvFilme(string nome);
		void addAosEmprestados(string nomeFilme);
		void ajustarPrazo();
		
	public:
		void addFilme(string nome, string diretor, string genero, string tempo, int pontuacao);
		void addDiretamente(string nome, string diretor, string genero, string tempo, int pontuacao);
		void buscaFilme(string nomeFilme);
		void buscaDiretor(string nomeDiretor);
		void buscaGenero(string nomeGenero);
		void mostrarFilmesDisponiveis();
		void mostrarFilmesEmprestados();
		void realizarEmprestimo(string nomeFilme);
		
		
};