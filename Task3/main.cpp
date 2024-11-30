#include<iostream>

using namespace std;

void EnterMoney(int banknotes)
{
	cout << "Your cash: " << banknotes << " UAN" << endl;
}

void EnterMoney(int banknotes, int coins)
{
	double cash = banknotes + (coins / 100.0);
	cout << "Your cash: " << cash << " UAN" << endl;
}

void EnterMoney(string card, int sum)
{
	cout << "Your card: " << card << endl;
	cout << "Your cash: " << sum << " UAN" << endl;
}


int main()
{
	string card = "3523466798234312";
	int banknotes = 25;
	int coins = 55;

	cout << "--> Banknotes" << endl;
	EnterMoney(banknotes);
	cout << "--> Banknotes + Coins" << endl;
	EnterMoney(banknotes, coins);
	cout << "--> Card" << endl;
	EnterMoney(card, banknotes);

	return 0;
}