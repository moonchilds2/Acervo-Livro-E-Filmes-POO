#include <iostream>
#include <string>

using namespace std;


class Endereco{

	private:
		string cidade;
		string rua;
		string numero;
		string bairro;
		
	public:
		
		Endereco(string cidade, string rua, string numero, string bairro);
		void imprimeEndereco();

};
