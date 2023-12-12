#include <iostream>
#include <numeric>

using namespace std;

void pizzaCheck();
void salesCalc();

void main()
{
    int choice;
    do {
    cout << "Do you want to go to pizza place or calculate managers' payment?\n1 - Pizza\n2 - Managers' payment calculator\n";
    cin >> choice;
    } 
    while (choice != 1 && choice != 2);
    switch (choice) {
    case 1: pizzaCheck();
        break;
    case 2: salesCalc();
        break;
    }
}


void pizzaCheck() {
    string pizzaMenu[4];
    pizzaMenu[0] = "Pepperoni";
    pizzaMenu[1] = "Bacon";
    pizzaMenu[2] = "Cheese";
    pizzaMenu[3] = "Pineapple";

    string drinkMenu[3];
    drinkMenu[0] = "Cola";
    drinkMenu[1] = "Juice";
    drinkMenu[2] = "Beer";

    double pizzaPrices[4];
    pizzaPrices[0] = 5.49;
    pizzaPrices[1] = 6.49;
    pizzaPrices[2] = 4.99;
    pizzaPrices[3] = 3.99;

    double drinkPrices[3];
    drinkPrices[0] = 1.99;
    drinkPrices[1] = 3.49;
    drinkPrices[2] = 3.99;

    int pizzaQty[4] = {};
    int drinkQty[3] = {};
    bool drinksDisc = false;
    
    int pizzasForDisc = 0, freePizzas, pricedDrinksInOrder = 0, inputCode, inputQty;
    double pizzasPrice = 0, drinksPrice = 0, totalPrice = 0;

    while (true) {
        //Pizza menu
        cout << "\nAdd a pizza to your order (enter pizza's code) or proceed to order drinks:\nCode\tQuantity\tPrice\tPizza\n";
        for (int i = 0; i < 4; i++) {
            cout << i << "\t" << pizzaQty[i] << "\t\t" << pizzaPrices[i] << "$\t" << pizzaMenu[i] << endl;
        }
        cout << 4 << "\tProceed to order drinks\n";
        cout << "Current pizzas' price: " << pizzasPrice << " $" << endl;

        cin >> inputCode;
        if (inputCode < 4) {
            cout << "How many pizzas do you want to add? (Every fifth pizza is free):\n";
            cin >> inputQty;
            pizzasForDisc += inputQty;
            freePizzas = pizzasForDisc / 5;
            pizzasForDisc %= 5;
            pizzaQty[inputCode] += inputQty;
            pizzasPrice += (pizzaPrices[inputCode] * inputQty) - (pizzaPrices[inputCode] * freePizzas);
            if (freePizzas) cout << "You got " << freePizzas << " pizza(s) for free!" << endl;
        }
        else break;
    }
    while (true) {
        //Drinks menu
        cout << "\nAdd drinks to your order (enter drink's code) or proceed to print check:\nCode\tQuantity\tPrice\tDrink\n";
        for (int i = 0; i < 3; i++) {
            cout << i << "\t" << drinkQty[i] << "\t\t" << drinkPrices[i] << "$\t" << drinkMenu[i] << endl;
        }
        cout << 3 << "\tProceed to print check\n";
        if (drinksDisc) cout << "You will get 15% discount on drinks!" << endl;
        cout << "Current drinks' price: " << drinksPrice << " $" << endl;

        cin >> inputCode;
        if (inputCode < 3) {
            cout << "How many drinks do you want to add? (If more than 3 drinks for >2$ - -15% for all drinks):\n";
            cin >> inputQty;
            drinkQty[inputCode] += inputQty;
            if (not drinksDisc) {
                if (drinkPrices[inputCode] > 2) pricedDrinksInOrder += inputQty;
                if (pricedDrinksInOrder >= 3) drinksDisc = true, cout << "You got 15% discount on drinks!" << endl;
            }
            drinksPrice += drinkPrices[inputCode] * inputQty;
        }
        else break;
    }
    //Total
    cout << "\n\nYour check: " << endl;
    for (int i = 0; i < 4; i++) {
        if (pizzaQty[i]) cout << pizzaQty[i] << "\t" << pizzaMenu[i] << endl;
    }
    cout << endl;
    for (int i = 0; i < 3; i++) {
        if (drinkQty[i]) cout << drinkQty[i] << "\t" << drinkMenu[i] << endl;
    }
    totalPrice = (drinksDisc) ? (pizzasPrice + (drinksPrice * 75 / 100)) : (pizzasPrice + drinksPrice);
    cout << "\nYour total is: " << totalPrice << "$\n";
}

void salesCalc() {
    const int basicPayment = 200;
    double managerSales[3] = {};
    double managersPayment[3] = {};
    int salesPercentage, bestManager = 0;
    
    cout << "Enter sales amount in $ for 3 managers:\n";
    for (int i = 0; i < 3; i++) cin >> managerSales[i];

    for (int i = 0; i < 3; i++) {
        if (managerSales[i] < 500) salesPercentage = 3;
        else if (managerSales[i] < 1000) salesPercentage = 5;
        else salesPercentage = 8;
        managersPayment[i] = basicPayment + managerSales[i] * (salesPercentage / (double)100);
        if (managersPayment[i] > managersPayment[bestManager]) bestManager = i;
    }

    managersPayment[bestManager] += 200;

    cout << "Managers' payment:\n";
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << " manager - " << managersPayment[i] << "$";
        (i == bestManager) ? cout << "\tBest manager! +200$\n" : cout << endl;
    }
}   