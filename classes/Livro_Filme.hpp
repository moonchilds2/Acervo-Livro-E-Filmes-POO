#include "Item.cpp"


class Livro : public Item{
	
	private:
	
		string autor;
		int paginas;
		
	public:
	
		Livro(string nome, string autor, string genero, int paginas, int pontuacao);
		string getAutor();
		int getPaginas();
		void descontarDias();
		void imprimeInfos();
};


class Filme : public Item{
	
	private:	
		string diretor;
		string tempo;
		
	public:
		
		Filme(string nome, string diretor, string genero, string tempo, int pontuacao);
		string getDiretor();
		string getTempo();
		void descontarDias();
		void imprimeInfos();
};
