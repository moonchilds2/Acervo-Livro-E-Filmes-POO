#include <iostream>
#include <string>

using namespace std;


class Item{

	protected:
	
		string nome;
		string genero;
		int prazoDevolucao;
		int pontuacao;
		
	public:
		
		Item(string nome, string genero, int pontuacao);
		string getNome();
		string getGenero();
		int getPrazoDevolucao();
		int getPontuacao();
		void descontarDias();
		void imprimeInfos();
		
};
