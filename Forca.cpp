#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;
string word, underscore, guess;
int wrong = 0;

string palavraSorteada;
string palavraEscondida;
int aleatorio;
string letra;
int letraFalhadas = 0;
int letrasAcertadas = 0;
int tentativasFalhadas = 0;


int main()

{
    srand(time(NULL));
    aleatorio = 1 + (rand() % 3); // gera aleatório para chave
    cout << "Aleatorio gerado: " << aleatorio << endl; // mostra o aleatório


    if (aleatorio == 1)
    {
        palavraSorteada = { 'b', 'a', 'n', 'a', 'n', 'a' };
        palavraEscondida = { '*', '*', '*', '*', '*', '*' };
    }
    if (aleatorio == 2)
    {
        palavraSorteada = { 'g', 'o', 'i', 'a', 'b', 'a' };
        palavraEscondida = { '*', '*', '*', '*', '*', '*' };
    }

    cout << "Palavra sorteada: " << endl;
    cout << palavraSorteada << endl;


    while (tentativasFalhadas < 8)
    {
        cout << "Acerte na palavra: " << palavraEscondida << endl;
        cout << "Pode falhar " << 8 - tentativasFalhadas << " vezes. " << endl;

        cout << "Escolha uma letra:" << endl;
        cin >> letra;

        cout << "Letra escolhida: ";
        cout << letra << endl;

            cout << "Letras acertadas: " << letrasAcertadas << endl;
            cout << "Letras falhadas: "  << letraFalhadas << endl;

        for (int i = 0; i < 6; i++)
        {
            if (letra[0] == palavraSorteada[i])
            {
                cout << "acertou na letra " << (i + 1) << endl;
                palavraEscondida[i] = palavraSorteada[i];
                letrasAcertadas++;

            }
            else if (letra[0] != palavraSorteada[i])
            {
                cout << "falhou na letra " << (i + 1) << endl;
                letraFalhadas++;
            }
        }

        cout << "Letras acertadas: " << letrasAcertadas << endl;
        cout << "Letras falhadas: " << letraFalhadas << endl;

        int comparar = palavraSorteada.compare(palavraEscondida);

        if (letrasAcertadas == 0)
        {
            tentativasFalhadas++;
        }

        letrasAcertadas = 0;
        letraFalhadas = 0;

        if (comparar == 0)
        {
            cout << "GAME OVER...acertou na palavra...a palavra era: " << palavraSorteada << endl;
            break;
        }

        if (tentativasFalhadas == 8)
        {
            cout << "GAME OVER...nao acertou na palavra...." << endl;
            break;
        }

    } 


}