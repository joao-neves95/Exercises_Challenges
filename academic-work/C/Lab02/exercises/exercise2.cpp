#include "../includes/exercise2.hpp"

#include <iostream>
using namespace std;

void exercise2() {
    cout << "Type a number: ";

    int num;
    cin >> num;

    // se est� entre 0 e 100 (inclusiv�).
    if (num >= 0 && num <= 100) {
        cout << "O n�mero est� entre 0 e 100 (inclusiv�)" << endl;
    } else {
        cout << "O n�mero � menor que 0 ou maior que 100" << endl;
    }
    if ( !(num < 0) && !(num > 100) ) {
        cout << "O n�mero est� entre 0 e 100 (inclusiv�)" << endl;
    } else {
        cout << "O n�mero � menor que 0 ou maior que 100" << endl;
    }

    // se � par
    if ( num % 2 == 0 ) {
        cout << "O n�mero � par" << endl;
    } else {
        cout << "O n�mero � impar" << endl;
    }
    if ( !(num % 2 != 0) ) {
        cout << "O n�mero � par" << endl;
    } else {
        cout << "O n�mero � impar" << endl;
    }

    // se � m�ltiplo de 5 mas n�o � m�ltiplo de 2
    if (num % 5 == 0 && num % 2 != 0) {
        cout << "O n�mero � m�ltiplo de 5 mas n�o � m�ltiplo de 2" << endl;
    }
    if ( !(num % 5 != 0) && !(num % 2 == 0) ) {
        cout << "O n�mero � m�ltiplo de 5 mas n�o � m�ltiplo de 2" << endl;
    }

    // Se est� entre -20 e -10 (inclusiv�) ou entre 10 e 20 (inclusiv�) e � um
    // n�mero par
    if ( (num >= -20 && num <= -10 || num >= 10 && num <= 20) && num % 2 == 0 ) {
        cout << "O n�mero est� entre -20 e -10 (inclusiv�) ou entre 10 e 20 (inclusiv�) e � um n�mero par" << endl;
    }
    if ( ( !(num < -20) && !(num > -10) || !(num < 10) && !(num > 20) ) && !(num % 2 != 0)) {
        cout << "O n�mero est� entre -20 e -10 (inclusiv�) ou entre 10 e 20 (inclusiv�) e � um n�mero par" << endl;
    }

    // Se � um m�ltiplo de 7, n�o � negativo e tem 3 d�gitos
    int dividedBy100 = num / 100;
    if (num % 7 == 0 && num >= 0 && dividedBy100 >= 1 && dividedBy100 <= 9) {
        cout << "O n�mero � um m�ltiplo de 7, n�o � negativo e tem 3 d�gitos" << endl;
    }
    if (!(num % 7 != 0) && !(num < 0) && !(dividedBy100 < 1) && !(dividedBy100 > 9)) {
        cout << "O n�mero � um m�ltiplo de 7, n�o � negativo e tem 3 d�gitos" << endl;
    }
}

