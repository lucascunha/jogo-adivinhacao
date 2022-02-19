#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    cout << "**************************************" << endl;
    cout << "* Bem-vindos ao jogo da adivinhacao! *" << endl;
    cout << "**************************************" << endl;
    cout << endl;
    cout << "Escolha o seu nivel de dificuldade:" << endl;
    cout << "Facil (F), Medio (M) ou Dificil (D)" << endl;
    cout << endl;

    char dificuldade;
    cout << "Digite o nivel: ";
    cin >> dificuldade;

    int numero_de_tentativas;

    if(dificuldade == 'F' || dificuldade == 'f'){
        numero_de_tentativas = 15;
        cout << "Nivel: Facil - Voce tem " << numero_de_tentativas << " tentativas" << endl;
        cout << endl;
    }
    else if(dificuldade == 'M' || dificuldade == 'm'){
        numero_de_tentativas = 10;
        cout << "Nivel: Medio - Voce tem " << numero_de_tentativas << " tentativas" << endl;
        cout << endl;
    }
    else if (dificuldade == 'D' || dificuldade == 'd') {
        numero_de_tentativas = 5;
        cout << "Nivel: Dificil - Voce tem " << numero_de_tentativas << " tentativas" << endl;
        cout << endl;
    } else {
        cout << "Nivel invalido!" << endl;
    }

    srand(time(NULL));
    const int NUMERO_SECRETO = rand() % 100;

    bool nao_acertou = true;
    int tentativas = 0;

    double pontos = 1000.0;

    for(tentativas = 1;tentativas <= numero_de_tentativas;tentativas++){
        int chute;
        cout << "Tentativa " << tentativas << " de " << numero_de_tentativas << endl;
        cout << "Qual seu chute? ";
        cin >> chute;
        cout << endl;

        double pontos_perdidos = abs(chute - NUMERO_SECRETO)/2.0;
        pontos -= pontos_perdidos;

        cout << "Seu chute: " << chute << endl;
        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        if (acertou)
        {
            cout << "Parabens! Voce acertou o numero secreto!" << endl;
            nao_acertou = false;
            break;
        }
        else if (maior)
        {
            cout << "Seu chute foi maior que o numero secreto!" << endl;
            cout << endl;
        }
        else
        {
            cout << "Seu chute foi menor que o numero secreto!" << endl;
            cout << endl;
        }
    }

    cout << "Fim de jogo!" << endl;
    if(nao_acertou){
        cout << "Voce perdeu! Tente novamente!" << endl;
        cout << "O numero secreto era " << NUMERO_SECRETO << endl;
    }
    else{
        cout << "Voce acertou o numero secreto em " << tentativas << " tentativas" << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuacao foi de " << pontos << " pontos." << endl;
    }
}