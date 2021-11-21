#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

list<string> :: iterator it;
int tema_escolhido;
int aleatorio;
int aleatorio2;
string palavra_escolhida;
string palavra_escondida;
string letra;
int letrasFalhadas = 0;
int letrasAcertadas = 0;
int tentativasFalhadas;
bool jogo_gravado;

class Dados
{
    public:
        int temaEscolhido;
        string palavraEscolhida;
        string palavraEscondida;
        int tentativaFalhadas;
        bool jogoGravado;

    public:
        Dados(){}

        void gravarJogo()
        {
            // cria e abre um ficheiro de texto
            ofstream ficheiro("dados.txt");

            // Escreve no ficheiro
            ficheiro << temaEscolhido << "\n";
            ficheiro << palavraEscolhida << "\n";
            ficheiro << palavraEscondida << "\n";
            ficheiro << tentativaFalhadas << "\n";
            ficheiro << jogoGravado;

            // Fecha o ficheiro
            ficheiro.close();
}

void carregarJogo()
{

    ifstream ficheiro ("dados.txt");

    while ( !ficheiro.eof() )
    {
        ficheiro >> temaEscolhido;
        ficheiro >> palavraEscolhida;
        ficheiro >> palavraEscondida;
        ficheiro >> tentativaFalhadas;
        ficheiro >> jogoGravado;
    }

    tema_escolhido = temaEscolhido;
    palavra_escolhida = palavraEscolhida;
    palavra_escondida = palavraEscondida;
    tentativasFalhadas = tentativaFalhadas;
    jogo_gravado = jogoGravado;

    cout << "Tema: " << tema_escolhido << endl;
    cout << "Palavra escolhida: " << palavra_escolhida << endl;
    cout << "Palavra escondida: " << palavra_escondida << endl;
    cout << "Tentativas falahadas: " << tentativasFalhadas << endl;
    cout << "Jogo gravado: " << jogo_gravado << endl;

    system("pause");
    }

};

int menu_inicial()
{
    int opcao_menu_inicial;
    do
    {
        system("cls");
        cout << "Bem-vindo(a) ao jogo da forca.\nEscolha um tema ou deixe que o programa decida:\n";
        cout << "1 - Escolher tema\n";
        cout << "2 - Definir aleatoriamente\n";
        cout << "3 - Carregar jogo gravado\n";
        cout << "0 - Sair\n";
        cin >> opcao_menu_inicial;
     }
     while(opcao_menu_inicial < 0 || opcao_menu_inicial > 3 );

     return opcao_menu_inicial;
 }

int escolher_tema()
{
    int tema;
    vector<string> temas = { "Paises", "Nomes", "Frutos" };

    cout << "Escolha um tema (numero): " << "\n";
    for (int i = 0; i < temas.size(); i++)
    {
        cout << "Tema #" << (i+1) << ": " << temas[i] << endl;
    }
    cin >> tema;

    cout << "Tema escolhido: " << temas[tema - 1] << endl;
    return tema;
 }

int tema_aleatorio()
{
    srand((unsigned)time(0));
    vector<string> temas = { "Paises", "Nomes", "Frutos" };
    aleatorio = 1 + rand() % 3;

    cout << "Aleatorio saido: " << aleatorio << endl;
    system("pause");

    for (int i = 0; i < temas.size(); i++)
    {
        if (i == aleatorio - 1)
            cout << "O tema escolhido aleatoriamente foi: " << temas[aleatorio - 1] << endl;
    }

    system("pause");
    return aleatorio;
}

string escolher_palavra()
{
    srand((unsigned)time(0));
    aleatorio2 = 1 + rand() % 10;

    cout << "Aleatorio saido: " << aleatorio2 << endl;
    system("pause");

    if (tema_escolhido == 1)
    {
        // 10 países:
        list<string> paises{"venezuela", "luxemburgo", "madagascar", "azerbaijao",
        "bangladexe", "dinamarca", "eslovaquia", "filipinas", "mocambique", "montenegro"};
        auto l_front = paises.begin();
        advance(l_front, aleatorio2 - 1);
        cout << *l_front << '\n';
        cout << "Palavra escolhida (dentro da funcao): " << *l_front << '\n';
        return *l_front;
    }

    if (tema_escolhido == 2)
    {
        // 10 nomes:
        list<string> nomes{"auxiliadora", "rosangela", "lucineide", "valentina", "francisco",
        "benjamin", "frederico", "querubim", "gertrude", "elisabete"};
        auto l_front = nomes.begin();
        advance(l_front, aleatorio2 - 1);
        cout << *l_front << '\n';
        cout << "Palavra escolhida (dentro da funcao): " << *l_front << '\n';
        return *l_front;
    }

    if (tema_escolhido == 3)
    {
        // 10 frutos:
        list<string> frutos{"castanha", "azeitona", "framboesa", "jabuticaba", "nectarina",
        "tangerina", "tamarindo", "camarinha", "maracuja", "jenipapo"};
        auto l_front = frutos.begin();
        advance(l_front, aleatorio2 - 1);
        cout << *l_front << '\n';
        cout << "Palavra escolhida (dentro da funcao): " << *l_front << '\n';
        return *l_front;
    }
}

int jogo()
{
    Dados d1;
    cout << "Já estamos dentro da funcao jogo..." << endl;
    cout << "A palavra escolhida foi: " << palavra_escolhida << endl;

    cout << "tamanho da palavra escolhida: " << palavra_escolhida.length() << endl;

    if (jogo_gravado == 0)
    {
    switch (palavra_escolhida.length())
    {
        case 8:
            palavra_escondida = "********";
            break;
        case 9:
            palavra_escondida = "*********";
            break;
        case 10:
            palavra_escondida = "**********";
            break;
        case 11:
            palavra_escondida = "***********";
            break;
    }
    }

    cout << "Palavra escondida: " << palavra_escondida << endl;

    while (tentativasFalhadas < 8)
    {
        char resposta;
        cout << "Deseja gravar o jogo (s/n): ";
        cin >> resposta;
        system("pause");
        if (resposta == 's')
        {
            d1.temaEscolhido = tema_escolhido;
            d1.palavraEscolhida = palavra_escolhida;
            d1.palavraEscondida = palavra_escondida;
            d1.tentativaFalhadas= tentativasFalhadas;
            d1.jogoGravado = 1;
            d1.gravarJogo();
        }
        else
        {
            jogo_gravado = 0;
        }
        cout << "Acerte na palavra: " << palavra_escondida << endl;
        cout << "Pode falhar " << 8 - tentativasFalhadas << " vezes. " << endl;

            cout << "Escolha uma letra:" << endl;
            cin >> letra;


        cout << "Letra escolhida: " << letra << endl;

        for (int i = 0; i < palavra_escolhida.length(); i++)
        {
            if (letra[0] == palavra_escolhida[i])
            {
                cout << (i + 1) << ":" << "SIM | ";
                palavra_escondida[i] = palavra_escolhida[i];
                letrasAcertadas++;
            }
            else if (letra[0] != palavra_escolhida[i])
            {
                cout << (i + 1) << ":" << "NAO | ";
                letrasFalhadas++;
            }
        }

        cout << "\n" << "Letras acertadas: " << letrasAcertadas << endl;
        cout << "Letras falhadas: " << letrasFalhadas << endl;
        system("pause");
        system("cls");

        int comparar = palavra_escolhida.compare(palavra_escondida);

        if (letrasAcertadas == 0)
        {
            tentativasFalhadas++;
        }

        letrasAcertadas = 0;
        letrasFalhadas = 0;

        if (comparar == 0)
        {
            cout << "BOM JOGO...acertou na palavra...a palavra era: " << palavra_escolhida << endl;
             system("pause");
            system("cls");
            break;
        }

        if (tentativasFalhadas == 8)
        {
            cout << "GAME OVER...nao acertou na palavra...." << endl;
            system("pause");
            system("cls");
            break;
        }
    }
    letrasFalhadas = 0;
    letrasAcertadas = 0;
    tentativasFalhadas = 0;
}


int main(void)
{
    Dados d1;
    int opcao_menu_inicial;

    opcao_menu_inicial = menu_inicial();

    while (opcao_menu_inicial != 0)
    {
        switch (opcao_menu_inicial)
        {
        case 1: // Escolher tema
            tema_escolhido = escolher_tema();
            cout << "Já no main: " << tema_escolhido << endl;
            system("pause");
            cout << "Primeiro passo completo..." << endl;
            cout << "Decidido o tema, o programa vai escolher uma palavra em 10 possíveis..." << endl;
            system("pause");
            palavra_escolhida = escolher_palavra();
            cout << "Palavra escolhida (main): " << palavra_escolhida << endl;
            system("pause");
            cout << "Olá!...agora vamos começar o jogo :) " << endl;
            system("pause");
            system("cls");
            jogo();
            break;

        case 2: // Decidir aleatoriamente
            tema_escolhido = tema_aleatorio();
            cout << "Já no main: " << tema_escolhido << endl;
            system("pause");
            cout << "Primeiro passo completo..." << endl;
            cout << "Sorteado o tema, o programa vai escolher uma palavra em 10 possíveis..." << endl;
            system("pause");
            palavra_escolhida = escolher_palavra();
            cout << "Palavra escolhida (main): " << palavra_escolhida << endl;
            system("pause");
            cout << "Olá!...agora vamos começar o jogo :) " << endl;
            system("pause");
            system("cls");
            jogo();
            break;

        case 3: // Carregar jogo gravado
            cout << "Carregar jogo gravado" << endl;
            d1.carregarJogo();
            cout << "Jogo carregado..." << endl;
            jogo();
            break;

        case 0:
        break;
        }
        opcao_menu_inicial = menu_inicial();   
    }
}