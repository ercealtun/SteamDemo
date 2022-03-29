#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <cstring>
#include <string.h>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include "ConsoleColor.h"
using namespace std;

// GLOBAL VARIABLES
int current_size = 5;
int game_number = 100;
int now_gamenumber = 50; // last game's index+1
///////////////////

class Account { // ACCOUNT CLASS
protected:
	string friends[20], games[100], installedGames[100], favGames[100],nl[100];  //nl = not loaded;
	int nl_size;
private:
	string name, surname, mail, password, phoneNumber, username, wallet, creditNumber, creditMoney, creditSecurity;
	double double_wallet,double_creditMoney;
public:
	int accountIndex;
	Account() {};
	~Account(){};
	//NAME
	string getName() {
		return name;
	}
	void setName(string name) {
		this->name = name;
	}
	//SURNAME
	string getSurname() {
		return surname;
	}
	void setSurname(string surname) {
		this->surname = surname;
	}
	//MAIL
	string getMail() {
		return mail;
	}
	void setMail(string mail) {
		this->mail = mail;
	}
	//PASSWORD
	string getPassword() {
		return password;
	}
	void setPassword(string password) {
		this->password = password;
	}
	//PHONE NUMBER
	string get_phoneNumber() {
		return phoneNumber;
	}
	void set_phoneNumber(string phoneNumber) {
		this->phoneNumber = phoneNumber;
	}
	//USERNAME
	string getUsername() {
		return username;
	}
	void setUsername(string username) {
		this->username = username;
	}
	//WALLET
	string getWallet() {
		return wallet;
	}
	void setWallet(string wallet) {
		this->wallet = wallet;
	}
	// FRIENDS 
	string getFriends(int i) {
		return friends[i];
	}
	void setFriends(string f, int i) {
		friends[i] = f;
	}
	//GAMES
	void setGames(string g, int i) {
		games[i] = g;
	}
	string getGames(int i) {
		return games[i];
	}
	// CREDIT CARD NUMBER
	void setCard(string creditNumber) {
		this->creditNumber = creditNumber;
	}
	string getCard() {
		return creditNumber;
	}
	// CREDIT CARD MONEY
	void set_cardMoney(string creditMoney) {
		this->creditMoney = creditMoney;
	}
	string get_cardMoney() {
		return creditMoney;
	}
	// CREDIT SECURITY CODE
	void set_creditSec(string creditSecurity) {
		this->creditSecurity = creditSecurity;
	}
	string get_creditSec() {
		return creditSecurity;
	}
	// INSTALLED GAMES
	void set_installedGames(string a, int i) {
		installedGames[i] = a;
	}
	string get_installedGames(int i) {
		return installedGames[i];
	}
	//FAV GAMES
	void set_favGames(string f, int i) {
		favGames[i] = f;
	}
	string get_favGames(int i) {
		return favGames[i];
	}
	// CONVERTING WALLET AND CREDIT CASH
	void convertDouble() {
		this->double_wallet = stod(wallet);
		this->double_creditMoney= stod(creditMoney);
	}
	// (DOUBLE)WALLET
	double get_double_wallet(){
		return double_wallet;
	}
	void set_double_wallet(double x){
		wallet=to_string(x);
		this->double_wallet = x;
	}
	//  (DOUBLE)CREDIT_MONEY
	double get_double_creditMoney(){
		return double_creditMoney;
	}
	void set_double_creditMoney(double x){
		creditMoney= to_string(x);
		this->double_creditMoney = x;
	}
	// BUYING GAME (FOR ACCOUNT) 
	void setNewGame(string x, int i){
		games[i] = x;
	}
	////////   not loaded     ///////////////////////////////////////
	void set_notLoaded(string a, int i){
		nl[i] = a;
	}
	string get_notLoaded(int i){
		return nl[i];
	}
	void set_nlSize(){
		int i=0;
		while(1){
			if(nl[i].length() == 0){
				break;
			}
			i++;
		}
		nl_size=i;
	}
	int get_nLsize(){
		return nl_size;
	}
	void nlSize_up(){
		nl_size++;
	}
	void nlSize_down(){
		nl_size--;
	}
	/////////////////////////////////////////////////////////////
};

class Profile : public Account { 
private:
	double gameMoney, myMoney;
	double add = 0;
	char ans;
	int money;
	Account* acc;
	string cNumber, cName, cSec, cMoney, newMail, newNum, newPass, newUser;
	vector<vector<double>> p_hist;
	vector<double> row;
public:
	Profile() : acc{NULL}, gameMoney{0.0}, myMoney{0.0} {};
//		acc = NULL;
//		gameMoney = 0.0;
//		myMoney = 0.0;
	void login(Account& a) {
		acc = &a;
	}
	~Profile() {};
	void profile_menu();
	void display();
	void convertDouble() {
		gameMoney = stod(acc->getWallet());
		myMoney = stod(acc->get_cardMoney());
	}
	void convertString() {
		acc->setWallet(to_string(gameMoney));
		acc->set_cardMoney(to_string(myMoney));
	}
	void deposit(double amount);
	void displayBalance()const;
	void checkCardInfo();
	void payMethod();
	void displayHistory()const;
	void changeContact();
	void changePassword();
	void changeUsername();
	void addFunds();
};

void Profile::addFunds() {
	while (1) {
		cout << "\tDo you want to add money in your Beam Wallet? (y/n)  >> ";
		cin >> ans;
		if (ans == 'y' || ans == 'Y') {
			try {
				if (acc->getCard() == "0")
					throw 0;
				cout << "\n\t|1| 10,00 TL (minimum fund level)\n\t|2| 20,00 TL\n\t|3| 50,00 TL\n\t|4| 100,00 TL \n\t|5| 200,00 TL" << endl;
				cout << "\n\tPlease select  >> ";
				cin >> money;
				do {
					switch (money) {
					case 1:	add = 10.0; break;
					case 2:	add = 20.0; break;
					case 3: add = 50.0; break;
					case 4: add = 100.0; break;
					case 5: add = 200.0; break;
					case 6:break;
					default: cout << "\n\tInvalid choice !\nPlease re-enter   >> ";
					}
				} while (money == 6);
				if (stod(acc->get_cardMoney()) >= add) {
					cout << "\n\t| To be added to your Beam Wallet: \t" << add << " |\n" << endl;
					try {
						cout << "\n\t>> Do you confirm? (y / n): ";
						cin >> ans;
						if (ans == 'n' || ans == 'N')
							throw 0;
						deposit(add);
						double m = stod(acc->getWallet());
						//vector for purchase history
						row.push_back(add);
						row.push_back(m);
						p_hist.push_back(row);
						row.pop_back();
						row.pop_back();

						cout << "\n\tTask Completed ! " << endl;
						cout << "\n\tPress ENTER to go back :) \n";
					}
					catch (int& ex) {
						cerr << "\n\t-Nothing changed-\n";
						cerr << "\n\tPress ENTER to go back :) \n";
					}
				}
				else {
					cout << "\n\tNot enough money in your credit card." << endl;
					cout << "\n\tPress ENTER to go back :) \n";
				}
				_getch();
				system("cls");
			}
			catch (int& ex) {
				cout << "\n\tYou have no payment methods associated with this account.\n";
				cout << "\n\tDo you want to add a payment method to this account? (y/n): ";
				cin >> ans;
				if (ans == 'y' || ans == 'Y')
					payMethod();
			}
			break;
		}
		else if (ans == 'n' || ans == 'N') {
			cout << "Going back to menu . ";
			for (int i = 0; i < 5; ++i) {
				Sleep(500); // 1 second = 1000milisecond
				cout << ". ";
			}
			break;
		}
		else {
			cout << "Wrong attempt... Please enter proper choice ! \n" << endl;
			continue;
		}
	}
}
void Profile::changeUsername() {
	cout << "\n\tEnter your new username:  >> ";
	cin >> newUser;
	try {
		cout << "\n\t>> Do you confirm? (y / n): ";
		cin >> ans;
		if (ans == 'n' || ans == 'N')
			throw 0;
		acc->setUsername(newUser);
	}
	catch (int& ex) {
		cerr << "\n\t- Nothing changed -\n";
		cerr << "\n\tPress ENTER to go back :) \n";
		_getch();
	}
}
void Profile::changePassword() {
	cout << "\n\tEnter your new password:  >> ";
	cin >> newPass;
	try {
		cout << "\n\t>> Do you confirm? (y / n): ";
		cin >> ans;
		if (ans == 'n' || ans == 'N')
			throw 0;
		acc->setPassword(newPass);
	}
	catch (int& ex) {
		cerr << "\n\t- Nothing changed -\n";
		cerr << "\n\tPress ENTER to go back :) \n";
		_getch();
	}
}
void Profile::changeContact() {
	char c;
	int check = 1;
	while (check) {
		cout << "\n\t -1- Change my email address\n\t -2- Change my phone number\n\t -3- Go Back\n\n\t Select:  >> ";
		cin >> c;
		switch (c) {
		case '1':
			cout << "\tEnter your (new) email adress:  >> ";
			cin >> newMail;
			acc->setMail(newMail);
			cout << "\n\t\tDONE !" << endl;
			break;
		case '2':
			cout << "\tEnter your (new) phone number:  >> ";
			cin >> newNum;
			acc->set_phoneNumber(newNum);
			cout << "\n\t\tDONE !" << endl;
			break;
		case '3':
			check = 0;
			break;
		}
	}
}
void Profile::displayHistory()const {
	cout << "\n\t\tCHANGE\t\t\tBALANCE";
	cout << "\n\t----------------------------------------------------\n";
	for (int i = 0; i < p_hist.size(); i++)
	{
		cout << "\t\t+";
		for (int j = 0; j < p_hist[i].size(); j++)
		{
			cout << p_hist[i][j] << " TL\t\t";
		}
		cout << endl;
	}
	cout << "\n\tPress ENTER to go back :) \n";
	_getch();
	system("cls");
}
void Profile::payMethod() {
	try {
		cout << "\n\t\t~ UPDATE CACHED PAYMENT METHOD ~" << endl;
		cout << "\n\tEnter a new payment method for future purchases and subscription renewals." << endl;
		cout << "\n\tCard number: ";
		cin >> cNumber;
		cout << "\n\tCVC code: ";
		cin >> cSec;
		cout << "\n\tMoney in your credit card: ";
		cin >> cMoney;
		char ans;
		cout << "\n\t>> Do you confirm? (y / n): ";
		cin >> ans;
		if (ans == 'n' || ans == 'N')
			throw 0;
		acc->setCard(cNumber);
		acc->set_creditSec(cSec);
		acc->set_cardMoney(cMoney);
		cout << "\n\tTask Completed ! " << endl;
		cout << "\n\tPress ENTER to go back :) \n";
	}
	catch (int& ex) {
		cerr << "\n\tPress ENTER to go back :) \n";
	}
	_getch();
	system("cls");
}
void Profile::displayBalance()const {
	cout << "\n\t----------------------------------------------------\n";
	cout << "\n\t\t\tWallet Balance: " << fixed << setprecision(2) << stod(acc->getWallet()) << " TL" << endl;
	cout << "\n\t\t\tCredit Card Balance: " << fixed << setprecision(2) << stod(acc->get_cardMoney()) << " TL" << endl;
	cout << "\n\t----------------------------------------------------\n";
}
void Profile::deposit(double amount) {
	checkCardInfo();
	convertDouble();
	gameMoney += amount;
	myMoney -= amount;
	convertString();
}
void Profile::checkCardInfo() {
	cout << "\n\tPlease Enter your card details: " << endl;
	cout << "\n\tCard number: ";
	cin >> cNumber;
	while (cNumber.compare(acc->getCard()) != 0) {
		cout << "\n\tYou have entered wrong card number. Please re-enter   >> ";
		cin >> cNumber;
	}
	cout << "\n\tCVC code: ";
	cin >> cSec;
	while (cSec.compare(acc->get_creditSec()) != 0) {
		cout << "\n\tYou have entered wrong CVC code. Please re-enter   >> ";
		cin >> cSec;
	}
	cout << "\n\tCardholder's Name: ";
	cin >> cName;
	while (cName.compare(acc->getName()) != 0) {
		cout << "\n\tYou have entered wrong name. Please re-enter   >> ";
		cin >> cName;
	}
}
void Profile::display() {
	acc->getName();
	system("color 0c");
	cout << "\n\t====================================================\n";
	cout << "\n\n\t\tUsername: " << acc->getUsername() << endl;
	cout << "\n\t\tName: " << acc->getName() << endl;
	cout << "\t\tLast Name: " << acc->getSurname() << endl;
	cout << "\t\tE-mail: " << acc->getMail() << endl;
	cout << "\t\tPhone Number: " << acc->get_phoneNumber() << endl;
	cout << "\n\t====================================================\n";
	cout << "\n\tPress ENTER to go back :) \n";
	_getch();
	system("color 7");

}
void Profile::profile_menu() {
	char choice, ch, select, c;
	int flag = 1;
	while (flag) {
		system("cls");
		cout << "\n\t----------------------------------------------------\n";
		cout << "\t\t\t " << acc->getUsername() << " 'S ACCOUNT";
		cout << "\n\t----------------------------------------------------\n\n";
		cout << "\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "\n\tSelect one option below \n";
		cout << "\n\t|1| View My Profile";
		cout << "\n\t|2| Account Details";
		cout << "\n\t|3| View My Wallet";
		cout << "\n\t|4| Back to Menu";
		cout << "\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "\n\tEnter your choice: ";
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case '1':
			display();
			break;
		case '2':
			do {
				system("cls");
				cout << "\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
				cout << "\n\t|1| Store & Purchase History";
				cout << "\n\t|2| Contact Info";
				cout << "\n\t|3| Change Password / Username";
				cout << "\n\t|4| Back to User Profile";
				cout << "\n\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
				cout << "\n\tEnter your choice: ";
				cin >> ch;
				system("cls");
				switch (ch)
				{
				case '1':
					system("cls");
					do {
						displayBalance();
						cout << "\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
						cout << "\n\t|1| Add funds to your Beam Wallet" << endl;
						cout << "\n\t|2| Add / Change a payment method" << endl;
						cout << "\n\t|3| View purchase history" << endl;
						cout << "\n\t|4| Go Back" << endl;
						cout << "\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
						cout << "\n\tEnter your choice: ";
						cin >> select;
						system("cls");
						switch (select)
						{
						case '1':
							addFunds();
							break;
						case '2':
							payMethod();
							break;
						case '3':
							displayHistory();
							break;
						case'4':
							break;
						default:
							cout << "\n\tPlease re-enter your choice !" << endl;
							break;
						}
					} while (select != '4');
					break;
				case '2':
					cout << "\n\t----------------------------------------------------\n";
					cout << "\tEmail Address:   " << acc->getMail();
					cout << "\n\tPhone Number:   " << acc->get_phoneNumber();
					cout << "\n\t----------------------------------------------------\n\n";
					changeContact();
					break;
				case '3':
					do {
						system("cls");
						cout << "\n\tWhat do you want to change? ";
						cout << "\n\t-1- Password\n\t-2- Username\n\t-3- Go Back";
						cout << "\n\tSelect  >> ";
						cin >> select;
						switch (select)
						{
						case '1':
							changePassword();
							break;
						case '2':
							changeUsername();
							break;
						case '3':
							break;
						default:
							cout << "\n\tPlease re-enter your choice !" << endl;
							break;
						}
					} while (select != '3');
					break;
				case '4':
					break;
				default:
					cout << "\n\tPlease re-enter your choice !" << endl;
					break;
				}
			} while (ch != '4');
			break;
		case '3':
			displayBalance();
			addFunds();
			break;
		case '4':
			flag = 0;
			break;
		default:
			cout << "\nEnter correct choice please.......";
			Sleep(500);
			break;
		}
	}
	system("cls");
}

class Store{
private:
	Account *acc;
	Account *allacc;
	Profile *pro;
	string gameName[100],gameCategory[100],gamePrice[100],gameRam[100],gameStorage[100],gameExp[100];
	int gameIndex[100];
	int popularGames[7] = {35,36,37,38,41,42,44};
	int choice, *c, c_index , checkSpeciel = 0 , check = 0,random;
	double double_price[100], discountgames[100],price;
public:
	int i;
	Store(){};
	~Store(){};
	//GAME NUMBER
	void set_gameIndex (int i){
		gameIndex[i]=i;
	}
	int get_gameIndex(int i){
		return gameIndex[i];
	}
	//GAME NAME
	void set_gameName(string gameName,int i){
		this->gameName[i]=gameName;
	}
	string get_gameName(int i){
		return gameName[i];
	}
	//GAME CAT.
	void set_gameCat(string gameCategory,int i){
		this->gameCategory[i]=gameCategory;
	}
	string get_gameCat(int i){
		return gameCategory[i];
	}
	//GAME PRICE
	void set_gamePrice(string gamePrice,int i){
		this->gamePrice[i]=gamePrice;
	}
	string get_gamePrice(int i){
		return gamePrice[i];
	}
	// GAME RAM
	void set_gameRam(string gameRam,int i){
		this->gameRam[i]=gameRam;
	}
	string get_gameRam(int i){
		return gameRam[i];
	}
	//GAME STO.
	void set_gameSto(string gameStorage,int i){
		this->gameStorage[i]=gameStorage;
	}
	string get_gameSto(int i){
		return gameStorage[i];
	}
	//GAME EXPLAINATIONS
	void set_gameExp(string gameExp,int i){
		this->gameExp[i]=gameExp;
	}
	string get_gameExp(int i){
		return gameExp[i];
	}
	void setdouble_price(double x,int i){
		double_price[i] = x;
	}
	void set_discountgames(int i,double x){
		discountgames[i] = x;
	}
	double get_double_price(int i){
		return double_price[i];
	}	
	void login(Account& a, Profile& p){
		acc = &a;
		pro = &p;
	}
	void loginall(Account& a){
		allacc = &a;
	}
	void creatC(){
		c = new int[now_gamenumber]; 
		c_index=1;
	}
	void destroyC(){ 
		delete[] c;
	}
	void covertDouble_Price(int i){
		price = stod(get_gamePrice(i));
	}
	int lenghtofarray(){
		int counter = 0;
		for(i=0;i<game_number;i++){
			if(acc->getGames(i).length() != 0){
				counter++;
			}
		}
		return counter;
	}
	int lenghtofALLarray(int k){
		int counter = 0;
		for(int i=0;i<game_number;i++){
			if(allacc[k].getGames(i).length() != 0){
				counter++;
			}
		}
		Sleep(2000);
		return counter;
	}	
	int len(string x){
		return x.length();
	}
	int gamechoice(){
		cout << "Please select one of the above to view or press 0 to go back to store menu: " << endl; 
		cin >> choice;
		if (choice == 0){
			destroyC();
			return 0;
		}
		else {
			return choice;
		}		
	}
	int searchbar(){
		system("cls");
		check = 0;
		char input[20];
		int  choice, i ;
		creatC();
		while (1){
		cout << "Enter game name: ";
		cin >> input;				
			if (strlen(input) < 2){
				cout << "Please enter at least 2 characters." << endl;
			}
			else {
				break;
			}
		}

		for(i=0;i<=game_number;i++){
			int found = get_gameName(i).find(input);
			if (found >= 0 && check == 0){
				cout << left << setw(20) << "GAME NUMBER" << setw(30) <<  "GAME NAME" << "GAME PRICE" << endl;	
				check = 1;			
			}
			if (found >= 0){
				if(double_price[i] == 0){
					cout << left << setw(20) << c_index << setw(30) << get_gameName(i) << "Free" <<endl;							
				}
				else {
					cout << left << setw(20) << c_index << setw(30) << get_gameName(i) << get_gamePrice(i) << "TL" <<endl;		
				}					
				c[c_index] = i;
				c_index++;
			}
		}
		if (check == 0){
			cout << "Game not found.Please enter valid game name. " << endl;
			
			Sleep(1000);
			return 0;
		}
		return gamechoice();
	}
	
	int categorize(){
		system("cls");
		int choice;
		string type;
		while(1){
			cout << "1-Fps Games \n2-Horror Games \n3-Multiplayer Games \n4-Open World Games \n5-Puzzle Games"<< endl;
			cout << "6-Simulation Games \n7-Sport Games \n8-Strategy Games \n9-Survival Games \n10-Tps Games \n0-Go to Main Menu" << endl;
			cout << "Enter number to which category would you like to see: ";
			cin >> choice;
			if (choice==1){
				type = "FPS";
				break;
			}
			else if (choice==2){
				type = "Horror";
				break;
			}
			else if(choice==3){
				type = "Multiplayer";
				break;
			}
			else if(choice==4){
				type = "Open World";
				break;
			}
			else if(choice == 5){
				type = "Puzzle";
				break;
			}
			else if(choice == 6){
				type = "Simulation";
				break;
			}
			else if (choice == 7){
				type = "Sport";
				break;
			}
			else if (choice == 8){
				type = "Strategy";
				break;
			}
			else if (choice == 9){
				type = "Survival";
				break;
			}
			else if (choice == 10){
				type = "TPS";
				break;
			}
			else if (choice == 0){
				system("cls");
				break;
			}
			else {
				cout << "Wrong input. Please try again.." << endl;
			}
		}
		system("cls");
		if (choice !=0 ){
			cout << left << setw(20) << "GAME NUMBER" << setw(30) <<  "GAME NAME" << "GAME PRICE" << endl;
			creatC();
			for (i=0;i<game_number;i++){
				if (type.compare(get_gameCat(i)) == 0 ){
					if(double_price[i] == 0){
						cout << left << setw(20) << c_index << setw(30) << get_gameName(i) << "Free" <<endl;							
					}
					else {
						cout << left << setw(20) << c_index << setw(30) << get_gameName(i) << get_gamePrice(i) << "TL" <<endl;		
					}				
					c[c_index] = i;
					c_index++;				
				}
			}
		return gamechoice();				
		}
	}
	
	int Popular(){
		system("cls");
		int choice;
		creatC();
		cout << left << setw(20) << "GAME NUMBER" << setw(30) <<  "GAME NAME" << "GAME PRICE" << endl;
		for (i=0;i<7;i++){
			cout << left << setw(20) << c_index << setw(30) << get_gameName(popularGames[i]) << get_gamePrice(popularGames[i]) << "TL" << endl;					
			c[c_index] = popularGames[i];
			c_index++;
		}
		return gamechoice();
	}

	
	int Special (){
		int choice;
		string type;
		if(checkSpeciel == 0){
			srand (time(NULL));
			random = rand() % 10 + 1; 
			checkSpeciel = 1;
		}
		if (random == 1){
			type = "FPS";
			creatC();
			cout << left  << "\t\tFPS GAMES DAY" << endl << endl;
			cout << left << setw(20) << "GAME NUMBER" << setw(30) <<  "GAME NAME" << "GAME PRICE" << endl;
			for (i=1;i<now_gamenumber;i++){
				if (type.compare(get_gameCat(i)) == 0 ){
					if(double_price[i] == 0){
						cout << left << setw(20) << c_index << setw(30) << get_gameName(i) << "Free" <<endl;							
					}
					else {
						cout << left << setw(20) << c_index << setw(30) << get_gameName(i) << double_price[i]-(double_price[i]*0.1) << "TL" <<endl;		
					}			
					c[c_index] = i;
					c_index++;				
				}
			}
			return gamechoice();	
		}
		
		else if (random == 2){
			type = "Horror";
			creatC();
			cout << left << setw(20) << "\t\t\tHORROR GAMES DAY"<< endl << endl;
			cout << left << setw(20) << "GAME NUMBER" << setw(30) <<  "GAME NAME" << "GAME PRICE" << endl;
			for (i=1;i<now_gamenumber;i++){
				if (type.compare(get_gameCat(i)) == 0 ){
					if(double_price[i] == 0){
						cout << left << setw(20) << c_index << setw(30) << get_gameName(i) << "Free" <<endl;							
					}
					else {
						cout << left << setw(20) << c_index << setw(30) << get_gameName(i) << double_price[i]-(double_price[i]*0.1) << "TL" <<endl;		
					}				
					c[c_index] = i;
					c_index++;				
				}
			}
			return gamechoice();				
		}
		else if (random == 3){
			type = "Multiplayer";
			creatC();
			cout << left << "\t\tLet's play with friends day"<< endl << endl;
			cout << left << setw(20) << "GAME NUMBER" << setw(30) <<  "GAME NAME" << "GAME PRICE" << endl;
			for (i=1;i<game_number;i++){
				if (type.compare(get_gameCat(i)) == 0 ){
					if(double_price[i] == 0){
						cout << left << setw(20) << c_index << setw(30) << get_gameName(i) << "Free" <<endl;							
					}
					else {
						cout << left << setw(20) << c_index << setw(30) << get_gameName(i) << double_price[i]-(double_price[i]*0.1) << "TL" <<endl;		
					}				
					c[c_index] = i;
					c_index++;				
				}
			}
			return gamechoice();				
		}
		else if (random == 4){
			type = "Open World";
			creatC();
			cout << left << "\t\t\tAdventure Day"<< endl << endl;
			cout << left << setw(20) << "GAME NUMBER" << setw(30) <<  "GAME NAME" << "GAME PRICE" << endl;
			for (i=1;i<game_number;i++){
				if (type.compare(get_gameCat(i)) == 0 ){
					if(double_price[i] == 0){
						cout << left << setw(20) << c_index << setw(30) << get_gameName(i) << "Free" <<endl;							
					}
					else {
						cout << left << setw(20) << c_index << setw(30) << get_gameName(i) << double_price[i]-(double_price[i]*0.1) << "TL" <<endl;		
					}			
					c[c_index] = i;
					c_index++;				
				}
			}
			return gamechoice();				
		}
		else if (random == 5){
			type = "Puzzle";
			creatC();
			cout << left  << "\t\t\tPuzzle Games Day"<< endl << endl;
			cout << left << setw(20) << "GAME NUMBER" << setw(30) <<  "GAME NAME" << "GAME PRICE" << endl;
			for (i=1;i<game_number;i++){
				if (type.compare(get_gameCat(i)) == 0 ){
					if(double_price[i] == 0){
						cout << left << setw(20) << c_index << setw(30) << get_gameName(i) << "Free" <<endl;							
					}
					else {
						cout << left << setw(20) << c_index << setw(30) << get_gameName(i) << double_price[i]-(double_price[i]*0.1) << "TL" <<endl;		
					}			
					c[c_index] = i;
					c_index++;				
				}
			}
			return gamechoice();				
		}
		else if (random == 6){
			type = "Simulation";
			creatC();
			cout << left << "\t\t\tSimulation Games Day"<< endl << endl;
			cout << left << setw(20) << "GAME NUMBER" << setw(30) <<  "GAME NAME" << "GAME PRICE" << endl;
			for (i=1;i<game_number;i++){
				if (type.compare(get_gameCat(i)) == 0 ){
					if(double_price[i] == 0){
						cout << left << setw(20) << c_index << setw(30) << get_gameName(i) << "Free" <<endl;							
					}
					else {
						cout << left << setw(20) << c_index << setw(30) << get_gameName(i) << double_price[i]-(double_price[i]*0.1) << "TL" <<endl;		
					}			
					c[c_index] = i;
					c_index++;				
				}
			}
			return gamechoice();				
		}
		else if (random == 7){
			type = "Sport";
			creatC();
			cout << left << "\t\t\tSport Games Day"<< endl << endl;
			cout << left << setw(20) << "GAME NUMBER" << setw(30) <<  "GAME NAME" << "GAME PRICE" << endl;
			for (i=1;i<game_number;i++){
				if (type.compare(get_gameCat(i)) == 0 ){
					if(double_price[i] == 0){
						cout << left << setw(20) << c_index << setw(30) << get_gameName(i) << "Free" <<endl;							
					}
					else {
						cout << left << setw(20) << c_index << setw(30) << get_gameName(i) << double_price[i]-(double_price[i]*0.1) << "TL" <<endl;		
					}			
					c[c_index] = i;
					c_index++;				
				}
			}	
			return gamechoice();			
		}
		else if (random == 8){
			type = "Strategy";
			creatC();
			cout << left << "\t\t\tStrategy Games Day"<< endl << endl;
			cout << left << setw(20) << "GAME NUMBER" << setw(30) <<  "GAME NAME" << "GAME PRICE" << endl;
			for (i=1;i<game_number;i++){
				if (type.compare(get_gameCat(i)) == 0 ){
					if(double_price[i] == 0){
						cout << left << setw(20) << c_index << setw(30) << get_gameName(i) << "Free" <<endl;							
					}
					else {
						cout << left << setw(20) << c_index << setw(30) << get_gameName(i) << double_price[i]-(double_price[i]*0.1) << "TL" <<endl;		
					}		
					c[c_index] = i;
					c_index++;				
				}
			}	
			return gamechoice();			
		}
		else if (random == 9){
			type = "Survival";
			creatC();
			cout << left << "\t\t\tSurvival Games Day"<< endl << endl;
			cout << left << setw(20) << "GAME NUMBER" << setw(30) <<  "GAME NAME" << "GAME PRICE" << endl;
			for (i=1;i<game_number;i++){
				if (type.compare(get_gameCat(i)) == 0 ){
					if(double_price[i] == 0){
						cout << left << setw(20) << c_index << setw(30) << get_gameName(i) << "Free" <<endl;							
					}
					else {
						cout << left << setw(20) << c_index << setw(30) << get_gameName(i) << double_price[i]-(double_price[i]*0.1) << "TL" <<endl;		
					}			
					c[c_index] = i;
					c_index++;				
				}
			}
			
			return gamechoice();				
		}
		else if (random == 10){
			type = "TPS";
			creatC();
			cout << left << "\t\t\tTPS Games Day" << endl << endl;
			
			for (i=1;i<game_number;i++){
				if (type.compare(get_gameCat(i)) == 0 ){
					if(double_price[i] == 0){
						cout << left << setw(20) << c_index << setw(30) << get_gameName(i) << "Free" <<endl;							
					}
					else {
						cout << left << setw(20) << c_index << setw(30) << get_gameName(i) << double_price[i]-(double_price[i]*0.1) << "TL" <<endl;		
					}			
					c[c_index] = i;
					c_index++;				
				}
			}
			return gamechoice();				
		}	
	}

	void allGameList(){
		system("cls");
		cout << "\t\t\t All Games" << endl << endl ;
		cout << left << setw(20) << "GAME NUMBER" << setw(30) <<  "GAME NAME" << "GAME PRICE" << endl;			
		for(i=1;i<=now_gamenumber;i++){
			if(double_price[i] == 0){
				cout << left << setw(20) << i << setw(30) << get_gameName(i-1) << yellow << "Free" <<white <<endl;							
			}
			else {
				cout << left << setw(20) << i << setw(30) << get_gameName(i-1) << get_gamePrice(i-1) << "TL" <<endl;		
			}							
		} 	
	}
	
	
	void selling (int choice){ 
		acc->convertDouble();
		system("cls");
		int number,i,sellingChoice,methodChoice,temp , index , length, check ,k, counter = 0;
		string friendChoice;
		number = c[choice];
		covertDouble_Price(number);			
		cout << left << setw(30) <<  "GAME NAME" << "GAME PRICE" << endl; 
		cout << left << setw(30) << get_gameName(number) << get_gamePrice(number) << "TL" << endl;	
		cout << endl <<  "ABOUT THIS GAME" << endl;
		
		for(i=0;i<get_gameExp(number).length();i++){
			if( gameExp[number][i] == ' '){
				counter ++;
			}
			if (counter == 7){
				cout << endl;
				counter = 0;
			}
			else {
				cout << gameExp[number][i];
			}
		}
		cout << endl << endl << "SYSTEM REQUIREMENTS" << endl;
		cout << "Memory -------> " << get_gameRam(number) << " GB RAM" <<  endl;
		cout << "Storage ------> " << get_gameSto(number) << " GB available space"<< endl;
		cout << endl << endl << endl <<"1-Purchase for myself" << endl << "2-Purchase as a gift" << endl << "3-Go back to store menu" << endl;
		cin >> sellingChoice;
		if (sellingChoice == 1){
			system("cls");	
			while(1){	
				for(i=0;i<game_number;i++){
					if(acc->getGames(i) == get_gameName(number)){
						check=1;
					}
				}
				if(check==1){
					cout << "You already have this game." << endl;
					for(i=0;i<20;++i){
						cout<<".";
						Sleep(500);
					}
					cout<<endl;
					break;
				}
				cout << "Total---------->" << get_gamePrice(number) << "TL" << endl; 
				cout << "Wallet: " << acc->get_double_wallet() <<endl; 
				
				if(acc->getCard() == "0"){ 
					cout << endl << "Sorry. No credit card associated with this account found\nYou can add new credit card in profile or use wallet" << endl;
				}
				else {
					cout << "Credit Card: " << acc->get_double_creditMoney() << endl;
				}
				cout << "\n1-Wallet\n2-Credit card\n3-Exit\nPlease select payment method or exit: ";
				cin >>  methodChoice;
				if (methodChoice == 1){
					if (acc->get_double_wallet() < price){
						cout << endl << "Sorry, You don't have enough money in your wallet to buy this game. You can use your credit card or load money your wallet in profile menu" << endl ;
					}
					else {
						system("cls");
						cout << "Total---------->" << get_gamePrice(number) << "TL" << endl; 
						cout << "Wallet: " << acc->get_double_wallet() <<endl; 
						cout << "---------------------" << endl;
						cout << "After purchase wallet: " << acc->get_double_wallet() - price << endl << endl;
						system("cls");
						cout << "Please waiting. Game adding your library";
						for(i=0;i<7;++i){
							cout<<".";
							Sleep(500);
						}
						system("cls");
						index = lenghtofarray();
						acc->setNewGame(get_gameName(number),index);
						acc->set_notLoaded(get_gameName(number),acc->get_nLsize());
						acc->nlSize_up();
						acc->set_double_wallet(acc->get_double_wallet()-price);
						cout << "The games added your library. Have fun! :) " << endl;
						for(i=0;i<3;++i){
							cout<<". ";
							Sleep(2000);
						}
						system("cls");
						break;
					}
				}
				else if (methodChoice == 2){  // credit card check
					if (acc->get_double_creditMoney() < price){
						cout << endl << "Sorry, You don't have enough money in your credit card to buy this game. You can use your wallet or load money your credit card" << endl ;
					}
					else {
						system("cls");
						cout << "Total---------->" << get_gamePrice(number) << "TL" << endl; 
						cout << "Credit Card: " << acc->get_double_creditMoney() <<endl; 
						cout << "---------------------" << endl;
						cout << "After purchase wallet: " << acc->get_double_creditMoney()-price << endl << endl;
						cout << "Please waiting. Game adding your library" << endl;
						for(i=0;i<7;++i){
							cout<<".";
							Sleep(600);
						}
						system("cls");
						index = lenghtofarray();
						acc->setNewGame(get_gameName(number),index);
						acc->set_notLoaded(get_gameName(number),acc->get_nLsize());
						acc->nlSize_up();
						acc->set_double_creditMoney(acc->get_double_creditMoney()-price);
						cout << "The games added your library. Have fun! :) " << endl;
						for(i=0;i<3;++i){
							cout<<". ";
							Sleep(500);
						}
						system("cls");
						break;
					}				
			
				}
				else if (methodChoice == 3){
					break;
				}
				else {
					cout << "Wrong input. Please try again.";
				}
			}
		}
		else if (sellingChoice == 2){
			check = 0;
			system("cls");	
			if(acc->getFriends(0).length()!=0){
					for(i=0;i<20;i++){
						cout << "\t" << acc->getFriends(i) << endl;
					}
					cout << "Select a friend to receive your gift: " << endl;
					cin >> friendChoice;						
					for(i=0; i<50; ++i){
	        	        if(allacc[i].getUsername() == friendChoice){
	           		        k = i;
	           		        break;
	              			}
	           		}				   	
					for(i=0;i<game_number;i++){
					if(allacc[k].getGames(i) == get_gameName(number)){
						check=1;
						cout << "Your friend have already this game." << endl;
						for(i=0;i<20;++i){
							cout<<".";
							Sleep(500);
						}
						cout<<endl;				
						break;
						}
					}
				if (check == 0){					
					cout << "Total---------->" << get_gamePrice(number) << "TL" << endl; 
					cout << "Wallet: " << acc->get_double_wallet() <<endl; 				
					if(acc->getCard() == "0"){ 
						cout << endl << "Sorry. No credit card associated with this account found\nYou can add new credit card in profile or use wallet" << endl;
					}
					else {
						cout << "Credit Card: " << acc->get_double_creditMoney() << endl;
					}
					
					cout << "\n1-Wallet\n2-Credit card\n3-Exit\nPlease select payment method or exit: ";
					cin >>  methodChoice;
					if (methodChoice == 1){
						if (acc->get_double_wallet() < price){
							cout << endl <<"Sorry, You don't have enough money in your wallet to buy this game. You can use your credit card or load money your wallet in profile menu" << endl ;
						}
						else {
							system("cls");
							cout << "Total---------->" << get_gamePrice(number) << "TL" << endl; 
							cout << "Wallet: " << acc->get_double_wallet() <<endl; 
							cout << "---------------------" << endl;
							cout << "After purchase wallet: " << acc->get_double_wallet() - price << endl << endl;
							for(i=0;i<5;++i){
								cout<<". ";
								Sleep(500);
							}
							system("cls");
							cout << "Please waiting. Game adding your library" << endl;
							for(i=0;i<5;++i){
								cout<<". ";
								Sleep(500);
							}
							system("cls");
							index = lenghtofALLarray(k);
							allacc[k].setNewGame(get_gameName(number),index);
							allacc[k].set_notLoaded(get_gameName(number), allacc[k].get_nLsize());
							allacc[k].nlSize_up();
							acc->set_double_wallet(acc->get_double_wallet()-price);
							cout << "The games added your friends library. Have fun! :) " << endl;
							for(i=0;i<5;++i){
								cout<<". ";
								Sleep(500);
							}
							system("cls");
						}
					}
					else if (methodChoice == 2){  //credit card check
						if (acc->get_double_creditMoney() < price){
							cout << endl << "Sorry, You don't have enough money in your credit card to buy this game. You can use your wallet or load money your credit card" << endl ;
						}
						else {
							system("cls");
							cout << "Total---------->" << get_gamePrice(number) << "TL" << endl; 
							cout << "Credit Card: " << acc->get_double_creditMoney() <<endl; 
							cout << "---------------------" << endl;
							cout << "After purchase wallet: " << acc->get_double_creditMoney()-price << endl << endl;
							for(i=0;i<5;++i){
								cout<<". ";
								Sleep(500);
							}
							cout << "Please waiting. Game adding your library" << endl;
							for(i=0;i<5;++i){
								cout<<". ";
								Sleep(500);
							}
							system("cls");
							index = lenghtofALLarray(k);
							allacc[k].setNewGame(get_gameName(number),index);
							allacc[k].set_notLoaded(get_gameName(number), allacc[k].get_nLsize());
							allacc[k].nlSize_up();
							acc->set_double_creditMoney(acc->get_double_creditMoney()-price);
							cout << "The games added your friends library. Have fun! :) " << endl;
							for(i=0;i<5;++i){
								cout<<". ";
								Sleep(500);
							}
							system("cls");
						}				
					}
					else if (methodChoice == 3){
						
					}
					else {
						cout << "Wrong input. Please try again.";
					}									
				}	
			}else{
				cout<<"You got no friends fam :( \nYou can add some friends to get in touch.\nTransferring you to store menu";
				for(i=0;i<5;++i){
					cout<<"."<<endl;
					Sleep(500);
				}
			}
		}
		else if(sellingChoice == 3){
			//exit
		}
		else {
			cout << "Wrong input. Please try again." <<endl;
		}		
		check=0;
	}
	
	void sellingSpecial (int choice){
		system("cls");
		int number,i,sellingChoice,methodChoice,temp , index , length, check ,k, counter = 0;
		string friendChoice;
		number = c[choice];	
		acc->convertDouble();
					
		cout << left << setw(30) <<  "GAME NAME" << "GAME PRICE" << endl; 
		cout << left << setw(30) << get_gameName(number) << discountgames[number] << "TL" << endl;	
		cout << endl <<  "ABOUT THIS GAME" << endl;		
		for(i=0;i<get_gameExp(number).length();i++){
			if( gameExp[number][i] == ' '){
				counter ++;
			}
			if (counter == 7){
				cout << endl;
				counter = 0;
			}
			else {
				cout << gameExp[number][i];
			}
		}
		cout << endl << endl << "SYSTEM REQUIREMENTS" << endl;
		cout << "Memory -------> " << get_gameRam(number) << " GB RAM" <<  endl;
		cout << "Storage ------> " << get_gameSto(number) << " GB available space"<< endl;
		cout << endl << endl << endl <<"1-Purchase for myself" << endl << "2-Purchase as a gift" << endl << "3-Go back to store menu" << endl;
		cin >> sellingChoice;
		if (sellingChoice == 1){
			system("cls");	
			while(1){	
				for(i=0;i<game_number;i++){
					if(acc->getGames(i) == get_gameName(number)){
						check=1;
					}
				}
				if(check==1){
					cout << "You have already this game." << endl;
					for(i=0;i<5;++i){
						cout<<". ";
						Sleep(500);
					}
					break;
				}
				cout << "Total---------->" << discountgames[number]  << "TL" << endl; 
				cout << "Wallet: " << acc->get_double_wallet() <<endl; 
				
				if(acc->getCard() == "0"){ 
					cout << endl << "Sorry. No credit card associated with this account found\nYou can add new credit card in profile or use wallet" << endl;
				}
				else {
					cout << "Credit Card: " << acc->get_double_creditMoney() << endl;
				}
				cout << "\n1-Wallet\n2-Credit card\n3-Exit\nPlease select payment method or exit: ";
				cin >>  methodChoice;
				if (methodChoice == 1){
					if (acc->get_double_wallet() < discountgames[number] ){
						cout << endl << "Sorry, You don't have enough money in your wallet to buy this game. You can use your credit card or load money your wallet in profile menu" << endl ;
					}
					else {
						system("cls");
						cout << "Total---------->" << discountgames[number]  << "TL" << endl; 
						cout << "Wallet: " << acc->get_double_wallet() <<endl; 
						cout << "---------------------" << endl;
						cout << "After purchase wallet: " << acc->get_double_wallet() - discountgames[number]  << endl << endl;
						system("cls");
						cout << "Please waiting. Game adding your library" << endl;
						for(i=0;i<5;++i){
							cout<<". ";
							Sleep(500);
						}
						system("cls");
						index = lenghtofarray();
						acc->setNewGame(get_gameName(number),index);
						acc->set_notLoaded(get_gameName(number),acc->get_nLsize());
						acc->nlSize_up();
						acc->set_double_wallet(acc->get_double_wallet() - discountgames[number] );
						cout << "The games added your library. Have fun" << endl;
						for(i=0;i<5;++i){
							cout<<". ";
							Sleep(500);
						}
						system("cls");
						break;
					}
				}
				else if (methodChoice == 2){  //credit card check
					if (acc->get_double_creditMoney() < discountgames[number] ){
						cout << endl << "Sorry, You don't have enough money in your credit card to buy this game. You can use your wallet or load money your credit card" << endl ;
					}
					else {
						system("cls");
						cout << "Total---------->" << discountgames[number]  << "TL" << endl; 
						cout << "Credit Card: " << acc->get_double_creditMoney() <<endl; 
						cout << "---------------------" << endl;
						cout << "After purchase wallet: " << acc->get_double_creditMoney()-discountgames[number]  << endl << endl;
						cout << "Please waiting. Game adding your library" << endl;
						for(i=0;i<5;++i){
							cout<<". ";
							Sleep(500);
						}
						system("cls");
						index = lenghtofarray();
						acc->setNewGame(get_gameName(number),index);
						acc->set_notLoaded(get_gameName(number),acc->get_nLsize());
						acc->nlSize_up();
						acc->set_double_creditMoney(acc->get_double_creditMoney()-discountgames[number] );
						cout << "The games added your library. Have fun" << endl;
						for(i=0;i<5;++i){
							cout<<". ";
							Sleep(500);
						}
						system("cls");
						break;
					}				
			
				}
				else if (methodChoice == 3){
					break;
				}
				else {
					cout << "Wrong input. Please try again.";
				}
			}					
		}	
		else if (sellingChoice == 2){
			check = 0;
			system("cls");	
						
				for(i=0;i<20;i++){
					cout << "\t" << acc->getFriends(i) << endl;
				}
				cout << "Select a friend to receive your gift: " << endl;
				cin >> friendChoice;						
				for(i=0; i<50; ++i){
        	        if(allacc[i].getUsername() == friendChoice){
           		        k = i;
           		        break;
              			}
           		}				   	
				for(i=0;i<game_number;i++){
				if(allacc[k].getGames(i) == get_gameName(number)){
					check=1;
					cout << "Your friend have already this game." << endl;					
					break;
					}
				}
				cout << "3" << endl;
			if (check == 0){					
				cout << "Total---------->" << discountgames[number]  << "TL" << endl; 
				cout << "Wallet: " << acc->get_double_wallet() <<endl; 				
				if(acc->getCard() == "0"){ 
					cout << endl << "Sorry. No credit card associated with this account found\nYou can add new credit card in profile or use wallet" << endl;
				}
				else {
					cout << "Credit Card: " << acc->get_double_creditMoney() << endl;
				}
				
				cout << "\n1-Wallet\n2-Credit card\n3-Exit\nPlease select payment method or exit: ";
				cin >>  methodChoice;
				if (methodChoice == 1){
					if (acc->get_double_wallet() < discountgames[number] ){
						cout << endl <<"Sorry, You don't have enough money in your wallet to buy this game. You can use your credit card or load money your wallet in profile menu" << endl ;
					}
					else {
						system("cls");
						cout << "Total---------->" << discountgames[number]  << "TL" << endl; 
						cout << "Wallet: " << acc->get_double_wallet() <<endl; 
						cout << "---------------------" << endl;
						cout << "After purchase wallet: " << acc->get_double_wallet() - discountgames[number]  << endl << endl;
						for(i=0;i<5;++i){
							cout<<". ";
							Sleep(500);
						}
						system("cls");
						cout << "Please waiting. Game adding your library" << endl;
						for(i=0;i<5;++i){
							cout<<". ";
							Sleep(500);
						}
						system("cls");
						index = lenghtofALLarray(k);
						allacc[k].setNewGame(get_gameName(number),index);
						allacc[k].set_notLoaded(get_gameName(number), allacc[k].get_nLsize());
						allacc[k].nlSize_up();
						acc->set_double_wallet(acc->get_double_wallet()-discountgames[number] );
						cout << "The games added your friends library. Have fun" << endl;
						for(i=0;i<5;++i){
							cout<<". ";
							Sleep(500);
						}
						system("cls");
					}
				}
				else if (methodChoice == 2){  //credit card check
					if (acc->get_double_creditMoney() < discountgames[number] ){
						cout << endl << "Sorry, You don't have enough money in your credit card to buy this game. You can use your wallet or load money your credit card" << endl ;
					}
					else {
						system("cls");
						cout << "Total---------->" << discountgames[number]  << "TL" << endl; 
						cout << "Credit Card: " << acc->get_double_creditMoney() <<endl; 
						cout << "---------------------" << endl;
						cout << "After purchase wallet: " << acc->get_double_creditMoney()-discountgames[number]  << endl << endl;
						for(i=0;i<5;++i){
							cout<<". ";
							Sleep(500);
						}
						cout << "Please waiting. Game adding your library" << endl;
						for(i=0;i<5;++i){
							cout<<". ";
							Sleep(500);
						};
						system("cls");
						index = lenghtofALLarray(k);
						allacc[k].setNewGame(get_gameName(number),index);
						allacc[k].set_notLoaded(get_gameName(number), allacc[k].get_nLsize());
						allacc[k].nlSize_up();
						acc->set_double_creditMoney(acc->get_double_creditMoney()-discountgames[number] );
						cout << "The games added your friends library. Have fun" << endl;
						for(i=0;i<5;++i){
							cout<<". ";
							Sleep(500);
						}
						system("cls");
					}				
				}
				else if (methodChoice == 3){
					
				}
				else {
					cout << "Wrong input. Please try again.";
				}									
			}
			
		}
		else if(sellingChoice == 3){
			//exit
		}
		else {
			cout << "Wrong input. Please try again." <<endl;
		}		
		check=0;
	}		
};

class Admin {
private:
	string username, password;
	Store* sto;
public:
	int i, stop, indexer, sign, kar;
	bool light;
	char ch175 = 175;
	string temp, select, dec, sec, ex;
	Admin(){};
	~Admin(){};
	// USERNAME
	void setUsername(string username) {
		this->username = username;
	}
	string getUsername() {
		return username;
	}
	// PASSWORD 
	void setPassword(string password) {
		this->password = password;
	}
	string getPassword() {
		return password;
	}
	// GETTING GAME CLASS
	void getGame(Store& s) {
		sto = &s;
	}
	// ADD GAME
	void addGame() {
		system("cls");
		light = false;
		cout << "You are adding game into system boss, u ready? \n->yes\n->no\n" << ch175 << " ";
		cin >> select;
		stop = 1;
		do {
			sign = 1;
			kar = 1;

			if (light == true) {
				cout << "Do you want to continue: ( yes / no ) :";
				cin >> select;
				if (select == "no") {
					stop = 0;
					cout << "Opening admin lobby";
					for (i = 0; i < 5; ++i) {
						cout << ". ";
						Sleep(400);
					}
				}
			}
			if (select == "yes") {
				light = true;
				while (kar) {
					cout << ch175 << " Game name: ";
					getline(cin >> ws, temp);
					for (i = 0; i < now_gamenumber; ++i) {
						if (temp == sto->get_gameName(i)) {
							cout << "Beam already has this game, boss please.." << endl;
							sign = 0;
							break;
						}
					}

					if (sign == 0) {
						while (1) {
							cout << "Do you want to continue: ( 1: yes / 0: no (opens admin lobby) ) : ";
							cin >> dec;
							if (dec == "yes") {
								kar = 1;
								break;
							}
							else if (dec == "no") {
								light = false;
								cout << "Opening admin lobby";
								for (i = 0; i < 5; ++i) {
									cout << ". ";
									Sleep(400);
								}
								kar = 0;
								stop = 0;
								break;
							}
							else {
								cout << "Please enter proper choice..";
								system("cls");
							}
						}

					}
					else {
						if (i == now_gamenumber) {
							sto->set_gameName(temp, now_gamenumber);
							kar = 1;
							break;
						}
					}
				}

				if (kar == 1) {
					cout << ch175 << " Game category: (FPS / Horror / Multiplayer / Open World / Puzzle / Simulation / Sport / Strategy / Survival / TPS): ";
					cin >> temp;
					sto->set_gameCat(temp, now_gamenumber);

					cout << ch175 << " Game price: ";
					cin >> temp;
					sto->set_gamePrice(temp, now_gamenumber);

					cout << ch175 << " Game Ram: ";
					cin >> temp;
					sto->set_gameRam(temp, now_gamenumber);

					cout << ch175 << " Game storage: ";
					cin >> temp;
					sto->set_gameSto(temp, now_gamenumber);


					while (1) {
						cout << endl << ch175 << " " << ch175 << " Do you want to add explaination the " << sto->get_gameName(now_gamenumber) << " ? ( yes / no ) : ";
						cin >> dec;
						if (dec == "yes") {
							cout << "Enter explaination : ";
							getline(cin >> ws, temp);
							sto->set_gameExp(temp, now_gamenumber);
							break;
						}
						else if (dec == "no") {
							cout << "No explaination added for " << sto->get_gameName(now_gamenumber) << endl;
							break;
						}
						else {
							cout << "Wrong decision attempt.. Enter proper option, please: ";
							continue;
							system("cls");
						}
					}
					now_gamenumber++;
				}
			}
			else if (select == "no") {
				light = true;
				cout << "\tNo game were changed." << endl;
				Sleep(2000);
			}
			else {
				light = true;
				cout << "Wrong decision attempt.. Enter proper option, please!" << endl;
				stop = 1;
			}
		} while (stop);
	}
	// CHANGE GAME
	void changeGame() {
		system("cls");
		cout << "You are changing game in the system boss, u ready? \n->yes\n->no(quit to menu)\n" << ch175 << " ";
		cin >> select;
		stop = 1;
		do {
			if (select == "yes") {
				cout << "Which game you want to change: ";
				getline(cin >> ws, temp);
				for (i = 0; i < now_gamenumber; ++i) {
					if (temp == sto->get_gameName(i)) {
						indexer = i;
						break;
					}
				}
				if (i == now_gamenumber) {
					cout << "No game named " << temp << " was found." << endl;
				}
				else {

					while (1) {
						cout << "Change game " << sto->get_gameName(indexer) << "'s name ? ( yes or no ) : ";
						getline(cin >> ws, sec);
						if (sec == "yes") {
							cout << ch175 << " New game name for the " << sto->get_gameName(indexer) << " : ";
							getline(cin >> ws, temp);
							sto->set_gameName(temp, indexer);
							break;
						}
						else if (sec == "no") {
							cout << "No name changed for the game " << sto->get_gameName(indexer) << endl;
							break;
						}
						else {
							cout << "Wrong entry.. Please try again.." << endl;
							system("cls");
							continue;
						}
					}

					while (1) {
						cout << "Change game " << sto->get_gameName(indexer) << "'s category ? ( yes or no ) : ";
						cin >> sec;
						if (sec == "yes") {
							cout << ch175 << " New game category for the " << sto->get_gameName(indexer) << " : ";
							cin >> temp;
							sto->set_gameCat(temp, indexer);
							break;
						}
						else if (sec == "no") {
							cout << "No category changed for the game " << sto->get_gameName(indexer) << endl;
							break;
						}
						else {
							cout << "Wrong entry.. Please try again.." << endl;
							system("cls");
							continue;
						}
					}

					while (1) {
						cout << "Change game " << sto->get_gameName(indexer) << "'s price ? ( yes or no ) : ";
						cin >> sec;
						if (sec == "yes") {
							cout << ch175 << " New game price for the " << sto->get_gameName(indexer) << " : ";
							cin >> temp;
							sto->set_gamePrice(temp, indexer);
							break;
						}
						else if (sec == "no") {
							cout << "No price changed for the game " << sto->get_gameName(indexer) << endl;
							break;
						}
						else {
							cout << "Wrong entry.. Please try again.." << endl;
							system("cls");
							continue;
						}
					}

					while (1) {
						cout << "Change game " << sto->get_gameName(indexer) << "'s RAM ? ( yes or no ) : ";
						cin >> sec;
						if (sec == "yes") {
							cout << ch175 << " New game RAM for the " << sto->get_gameName(indexer) << " : ";
							cin >> temp;
							sto->set_gameRam(temp, indexer);
							break;
						}
						else if (sec == "no") {
							cout << "No RAM changed for the game " << sto->get_gameName(indexer) << endl;
							break;
						}
						else {
							cout << "Wrong entry.. Please try again.." << endl;
							system("cls");
							continue;
						}
					}

					while (1) {
						cout << "Change game " << sto->get_gameName(indexer) << "'s storage ? ( yes or no ) : ";
						cin >> sec;
						if (sec == "yes") {
							cout << ch175 << " New game storage for the " << sto->get_gameName(indexer) << " : ";
							cin >> temp;
							sto->set_gameSto(temp, indexer);
							break;
						}
						else if (sec == "no") {
							cout << "No storage changed for the game " << sto->get_gameName(indexer) << endl;
							break;
						}
						else {
							cout << "Wrong entry.. Please try again.." << endl;
							system("cls");
							continue;
						}
					}
					while (1) {
						cout << endl << ch175 << " " << ch175 << " Do you want to add explaination the " << sto->get_gameName(now_gamenumber) << " ? ( yes / no ) : ";
						cin >> dec;
						if (dec == "yes") {
							cout << "Enter explaination : ";
							getline(cin>>ws,temp);
							sto->set_gameExp(temp, indexer);
							break;
						}
						else if (dec == "no") {
							cout << "No explaination added for " << sto->get_gameName(indexer) << endl;
							break;
						}
						else {
							cout << "Wrong decision attempt.. Enter proper option, please: ";
							continue;
							system("cls");
						}
					}
				}
			}
			else if (select == "no") {
				cout << "No games were changed." << endl;
			}
			else {
				cout << "Wrong decision attempt.. Enter proper option, please!" << endl;
				stop = 1;
			}

			if (select == "no" || select == "yes" || stop == 1) {
				cout << "Do you want to continue: ( yes / no ) :";
				cin >> select;
				if (select == "no") {
					stop = 0;
					cout << "Opening admin lobby";
					for (i = 0; i < 5; ++i) {
						cout << ". ";
						Sleep(400);
					}
				}
			}
		} while (stop);
	}
	// CHANGE LOGIN OPTIONS
	void changeLogin() {
		system("cls");
		cout << "I think you're having some security issues :) " << endl;
		cout << "U Ready Boss ? ( yes / no ) : ";
		while (1) {
			cin >> select;
			if (select == "yes") {
				cout << "Please enter the current password: ";
				cin >> temp;
				if (temp == password) {
					cout << "Do you want to change username (yes or press any key for no): ";
					cin >> ex;
					if (ex == "yes") {
						cout << ch175 << " Enter new username: ";
						cin >> temp;
						username = temp;
						cout << "New username saved to Beam servers boss!" << endl;
						Sleep(3000);
						cout << "Do you want to change password (yes or press any key for no): ";
						cin >> ex;
						if (ex == "yes") {
							cout << ch175 << " Enter new password: ";
							cin >> temp;
							password = temp;
							cout << "New password saved to Beam servers boss!" << endl;
							Sleep(4000);
							break;
						}
						else {
							cout << "No password changed." << endl;
							Sleep(1000);
							break;
						}
					}
					else {
						cout << "No username changed." << endl;
						cout << "Do you want to change password (yes or press any key for no): ";
						cin >> ex;
						if (ex == "yes") {
							cout << ch175 << " Enter new password: ";
							cin >> temp;
							password = temp;
							cout << "New password saved to Beam servers boss!" << endl;
							Sleep(4000);
							break;
						}
						else {
							cout << "No password changed." << endl;
							Sleep(1000);
							break;
						}
					}
				}
				else {
					cout << "Wrong entry boss. We make wait you for a while, for your safety";
					for (i = 0; i < 8; ++i)
					{
						cout << ".";
						Sleep(500);
					}
					system("cls");
					cout << "U Ready Boss ? ( yes / no ) : ";
				}
			}
			else if (select == "no") {
				cout << "Okey boss.. You are in a complicated feelings.. I guess :/ Take care of yourself." << endl;
				Sleep(7000);
				break;
			}
			else {
				cout << "Wrong entry boss..";
				Sleep(400);
				system("cls");
				cout << "Again.. U Ready Boss ? ( yes / no ) : ";
			}
		}
	}
};

class GameLibrary : protected Account {
private:
	Account* acc;  
	int gameSize, size, fav_size; //size indirilenlerin size ý
public:
	GameLibrary() {};
	void login(Account& a) {
		acc = &a;
	}
	~GameLibrary(){};
	Account& library() {
		char ch175 = 175;
		string game, choose;
		int oper, check = 1, i, check1, check2, continuous, sign;
		display();
		setSize();
		do {
			cout << "\t1-Install Game \n\t2-Uninstall Game \n\t3-Back to the Beam menu" << endl << "\t" << ch175;
			cin >> oper;
			switch (oper)
			{
			case 1:
				do {
					check1 = 0;
					check2 = 1;
					system("cls");
					displayNotLoaded();
					if (acc->get_nLsize() != 0) {
						cout << endl << "\tWhich game do you want to install?" << endl << "\t" << ch175;
						getline(cin >> ws, game);
						for (i = 0; i < gameSize; ++i) {
							if (acc->getGames(i) == game) {
								check1 = 1;
								break;
							}
						}
						for (i = 0; i < size; ++i) {
							if (acc->get_installedGames(i) == game) {
								check2 = 0;
								break;
							}
						}
						if (check1 == 1 && check2 == 1) {
							install(game);
						}
						else if (check1 == 0) {
							cout << endl << "\tYou don't have this game library either. You cannot install the game without it in your library :(" << endl << endl;
						}
						else if (check2 == 0) {
							cout << endl << "\t" << game << " is already installed." << endl << endl;
						}
					}
					else {
						if (gameSize == 0) {
							cout << endl << "\tYou don't have any games, also there are no games in your library." << endl << endl;
						}
						else {
							cout << endl << "\tYou don't have a game not downloaded." << endl << endl;
						}
					}
					sign = 1;
					while (sign) {
						cout << "\tDo you want to continue(yes/no)?" << endl << "\t" << ch175;
						cin >> choose;
						if (choose == "yes" || choose == "Yes") {
							system("cls");
							continuous = 1;
							sign = 0;
						}
						else if (choose == "no" || choose == "No") {
							system("cls");
							display();
							continuous = 0;
							sign = 0;
						}
						else {
							continuous = 1;
							sign = 1;
							cout << "\tWrong input!! Please try again." << endl << endl;
						}
					}
				} while (continuous == 1);
				break;
			case 2:
				do {
					system("cls");
					loaded();
					check1 = 1;
					if (size == 0) {
						if (gameSize == 0 && size == 0) {
							cout << endl << "\tYou don't have any games, also there are no games in your library." << endl << endl;
							check1 = 0;
						}
						if (check1 == 1) {
							cout << endl << "\tYou don't have a downloaded game." << endl << endl;
						}
					}
					else {
						check1 = 0;
						check2 = 1;
						cout << endl << "\tWhich game do you want to uninstall?" << endl << "\t" << ch175;
						getline(cin >> ws, game);
						for (i = 0; i < gameSize; ++i) {
							if (acc->getGames(i) == game) {
								check1 = 1;
								break;
							}
						}
						for (i = 0; i < size; ++i) {
							if (acc->get_installedGames(i) == game) {
								check2 = 0;
								break;
							}
						}
						if (check1 == 1 && check2 == 0) {
							uninstall(game);
						}
						else if (check1 == 0) {
							cout << endl << "\tYou don't have this game library either. You cannot install the game without it in your library :(" << endl << endl;
						}
						else if (check2 == 1) {
							cout << endl << "\t" << game << " is NOT already installed." << endl << endl;
						}
					}
					sign = 1;
					while (sign) {
						cout << "\tDo you want to continue(yes/no)?" << endl << "\t" << ch175;
						cin >> choose;
						if (choose == "yes" || choose == "Yes") {
							system("cls");
							continuous = 1;
							sign = 0;
						}
						else if (choose == "no" || choose == "No") {
							system("cls");
							display();
							continuous = 0;
							sign = 0;
						}
						else {
							continuous = 1;
							sign = 1;
							cout << "\tWrong input!! Please try again." << endl << endl;
						}
					}
				} while (continuous == 1);
				break;
			case 3:
				check = 0;
				break;
			default:
				cout << "\tWrong input!! Please try again.." << endl << endl;
				break;
			}
		} while (check == 1);
		system("cls");
		return *acc;
	}
	void setSize() {
		size = 0;
		fav_size = 0;
		while (1) {
			if ((acc->get_installedGames(size)).length() == 0) {
				break;
			}
			size++;
		}
		while (1) {
			if ((acc->get_favGames(fav_size)).length() == 0) {
				break;
			}
			fav_size++;
		}
	}
	void display() {
		gameSize = 0;
		system("cls");
		cout << endl << "\t\t\t\t\t\tGAME LIBRARY" << endl;
		cout << "\t**********************************************************************************************" << endl;
		cout << "\t" << left << setw(35) << yellow << "ALL YOUR GAMES" << white << setw(35) << red <<"YOUR FAVORITE GAMES" << white <<
		green << "GAMES THAT DOWNLOADED" << white << endl << endl;
		while (1) {
			if ((acc->getGames(gameSize)).length() == 0) {
				break;
			}
			cout << "\t" << left << setw(35) << yellow << acc->getGames(gameSize) << setw(35) << red << acc->get_favGames(gameSize) << green << 
			acc->get_installedGames(gameSize) << white << endl;
			gameSize++;
		}
		if (gameSize == 0) {
			cout << "\t\tThese places are very quiet, you have no games. Visit the store and join the fun :) " << endl << endl;
		}
		cout << "\t**********************************************************************************************" << endl << endl;
	}
	
	void displayNotLoaded() {
		cout << endl << "\t>>GAMES THAT NOT DOWNLOADED<<" << endl;
		for (int i = 0; i < acc->get_nLsize(); ++i) {
			cout << "\t" << acc->get_notLoaded(i) << endl;
		}
	}
	void install(string game) {
		char ch175 = 175;
		string choice, temp;
		int i, check = 1, index, nl_index, check1;
		acc->set_installedGames(game, size); //install
		size++;
		cout << "\tGame is loading. . .";
		for (i = 0; i < 10; ++i) {
			Sleep(500);
			cout << " .";
		}
		system("cls");
		for (i = 0; i < acc->get_nLsize(); ++i) {
			if (acc->get_notLoaded(i) == game) {
				nl_index = i;
				break;
			}
		}
		for (i = nl_index; i < acc->get_nLsize(); ++i) {
			temp = acc->get_notLoaded(i+1);
			acc->set_notLoaded(temp,i);
		}
		acc->nlSize_down();
		for (i = 0; i < fav_size; ++i) {
			if ((acc->get_favGames(i)) == game) {
				index = i;
				check = 0;
				break;
			}
		}
		if (fav_size >= 0) {
			cout << endl << "\t       YOUR FAVORITE GAMES" << endl;
			cout << "\t---------------------------------------" << endl << endl;
			for (i = 0; i < fav_size; ++i) {
				cout << "\t" << acc->get_favGames(i) << endl;
			}
			cout << "\t---------------------------------------" << endl << endl;
			switch (check)
			{
			case 0:
				check1 = 1;
				do {
					cout << endl << "\t" << game << " is included in your favorite games. Would you like to remove(yes/no)?" << endl << "\t" << ch175;
					cin >> choice;
					if (choice == "yes" || choice == "Yes") {
						for (i = index; i < fav_size; ++i) {
							temp = acc->get_favGames(i + 1);
							acc->set_favGames(temp, i);
						}
						fav_size--;
						cout << "\t" << game << " has been removed from your favorite games..." << endl;
						cout << "\t----------------------------------------------------------------" << endl << endl;
						check1 = 0;
					}
					else if (choice == "no" || choice == "No") {
						cout << "\t----------------------------------------------------------------" << endl << endl;
						check1 = 0;
					}
					else {
						cout << endl << "\tWrong input!!" << endl << endl;
						check1 = 1;
					}
				} while (check1 == 1);
				break;
			case 1:
				check1 = 1;
				do {
					cout << endl << "\t" << game << " is not included in your favorite games. Would you like to add(yes/no)?" << endl << "\t" << ch175;
					cin >> choice;
					if (choice == "yes" || choice == "Yes") {
						acc->set_favGames(game, fav_size);
						cout << "\t" << game << " has been added to your favorite games.." << endl;
						cout << "\t----------------------------------------------------------------" << endl << endl;
						fav_size++;
						check1 = 0;
					}
					else if (choice == "no" || choice == "No") {
						cout << "\t----------------------------------------------------------------" << endl << endl;
						check1 = 0;
					}
					else {
						cout << endl << "\tWrong input!!" << endl << endl;
						check1 = 1;
					}
				} while (check1 == 1);
				break;
			}
		}

	}
	void loaded() {
		cout << endl << "\t>>GAMES THAT DOWNLOADED<<" << endl;
		for (int i = 0; i < size; ++i) {
			cout << "\t" << acc->get_installedGames(i) << endl;
		}
	}
	void uninstall(string game) {
		char ch175 = 175;
		string choice, temp;
		int i, index, check = 1, check1;
		for (i = 0; i < size; ++i) {
			if ((acc->get_installedGames(i)) == game) {
				index = i;
				break;
			}
		}
		for (i = index; i < size; ++i) {   //uninstall
			temp = acc->get_installedGames(i + 1);
			acc->set_installedGames(temp, i);
		}
		size--;
		cout << "\tGame is uninstalling. . .";
		for (i = 0; i < 10; ++i) {
			Sleep(500);
			cout << " .";
		}
		system("cls");
		acc->set_notLoaded(game, acc->get_nLsize());
		acc->nlSize_up();
		for (i = 0; i < fav_size; ++i) {
			if ((acc->get_favGames(i)) == game) {
				index = i;
				check = 0;
				break;
			}
		}
		if (fav_size >= 0) {
			cout << endl << "\t       YOUR FAVORITE GAMES" << endl;
			cout << "\t---------------------------------------" << endl << endl;
			for (i = 0; i < fav_size; ++i) {
				cout << "\t" << acc->get_favGames(i) << endl;
			}
			cout << "\t---------------------------------------" << endl << endl;
			switch (check)
			{
			case 0:
				check1 = 1;
				do {
					cout << endl << "\t" << game << " is included in your favorite games. Would you like to remove(yes/no)?" << endl << "\t" << ch175;
					cin >> choice;
					if (choice == "yes" || choice == "Yes") {
						for (i = index; i < fav_size; ++i) {
							temp = acc->get_favGames(i + 1);
							acc->set_favGames(temp, i);
						}
						fav_size--;
						cout << "\t" << game << " has been removed from your favorite games..." << endl;
						cout << "\t----------------------------------------------------------------" << endl << endl;
						check1 = 0;
					}
					else if (choice == "no" || choice == "No") {
						cout << "\t----------------------------------------------------------------" << endl << endl;
						check1 = 0;
					}
					else {
						cout << endl << "\tWrong input!!" << endl << endl;
						check1 = 1;
					}
				} while (check1 == 1);
				break;
			case 1:
				check1 = 1;
				do {
					cout << endl << "\t" << game << " is not included in your favorite games. Would you like to add(yes/no)?" << endl << "\t" << ch175;
					cin >> choice;
					if (choice == "yes" || choice == "Yes") {
						acc->set_favGames(game, fav_size);
						cout << "\t" << game << " has been added to your favorite games.." << endl;
						cout << "\t----------------------------------------------------------------" << endl << endl;
						fav_size++;
						check1 = 0;
					}
					else if (choice == "no" || choice == "No") {
						cout << "\t----------------------------------------------------------------" << endl << endl;
						check1 = 0;
					}
					else {
						cout << endl << "\tWrong input!!" << endl << endl;
						check1 = 1;
					}
				} while (check1 == 1);
				break;
			}
		}
	}
};

class Friends : protected Account {
private:
	int index, size;
	Account* acc;
public:
	Friends() {};
	~Friends(){};
	void setIndex(int index) {
		this->index = index;
	}
	void login(Account& a) {
		acc = &a;
	}
	void findSize() {
		size = 0;
		while (1) {
			if ((acc[index].getFriends(size).length()) == 0) {
				break;
			}
			size++;
		}
	}
	Account& friends() {
		char ch175 = 175;
		int check = 1, oper, check1;
		string choose;
		findSize();
		displayfriends();
		do {
			cout << "\t1-Add to friends \n\t2-Delete from friends \n\t3-Back to Beam menu" << endl << "\t" << ch175;
			cin >> oper;
			switch (oper)
			{
			case 1:
				check1 = 1;
				system("cls");
				addfriends();
				do {
					cout << "\tDo you want to continue(yes/no)?" << endl << "\t" << ch175;
					cin >> choose;
					if (choose == "yes" || choose == "Yes") {
						addfriends();
						check = 1;
						check1 = 1;
					}
					else if (choose == "no" || choose == "No") {
						system("cls");
						displayfriends();
						check = 1;
						check1 = 0;
					}
					else {
						check = 1;
						check1 = 1;
						cout << "\tWrong input!! Please try again." << endl;
					}
				} while (check1 == 1);
				break;
			case 2:
				check1 = 1;
				system("cls");
				removefriends();
				do {
					cout << "\tDo you want to continue(yes/no)?" << endl << "\t" << ch175;
					cin >> choose;
					if (choose == "yes" || choose == "Yes") {
						removefriends();
						check = 1;
						check1 = 1;
					}
					else if (choose == "no" || choose == "No") {
						system("cls");
						displayfriends();
						check = 1;
						check1 = 0;
					}
					else {
						check = 1;
						check1 = 1;
						cout << "\tWrong input!! Please try again." << endl;
					}
				} while (check1 == 1);
				break;
			case 3:
				check = 0;
				break;
			default:
				cout << "\tWrong inputt!! Please try again." << endl;
				check = 1;
				break;
			}
		} while (check == 1);
		system("cls");
		return *acc;
	}
	void displayfriends() {
		int i, k, j = 0, x, r, r1;  //k oyunda olan kiþinin accounttaki indexi
		string username;
		char ch175 = 175, ch174 = 174;
		srand((unsigned)time(0));
		system("cls");
		cout << endl << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "\t\t    >>FRIENDS LIST<<" << endl;
		cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		if (size == 0) {
			cout << "\tYou don't have any friends yet. \n\tYou can add friends to revive this place :) " << endl;
		}
		else {
			for (i = 0; i < size; ++i) {

				cout << "\t" << acc[index].getFriends(i) << ": " << endl;
				r = rand() % 90 + 1;
				if (r >= 1 && r <= 30) {
					cout << blue<<"\t\tonline" << white <<  endl << endl;
				}
				else if (r >= 31 && r <= 60) {
					cout << red << "\t\toffline" <<white<< endl << endl;  
				}
				else {

					username = acc[index].getFriends(i);
					x = 0;
					while (1) {  //oyunda olan kiþinin indexini bulma
						if ((acc[x].getUsername()).length() == 0) {
							break;
						}
						if (acc[x].getUsername() == username) {
							k = x;
							break;
						}
						x++;
					}
					while (1) {
						if ((acc[k].get_installedGames(j)).length() == 0) {
							break;
						}
						j++;
					}
					if (j == 0) {
						cout << red<< "\toffline" << white << endl << endl;
					}
					else{
						r1 = rand() % j;
						cout << green << "\t\tat game: playing " << ch174 << acc[k].get_installedGames(r1) << ch175 << white << endl << endl;
					}
				}
			}
		}
		cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
	}
	void addfriends() {
		string frUserName;
		int i = 0, check = 1, j = 0, check2 = 0, k, fr_size = 0; //fr_size eklediðimiz arkadaþýn arkadaþ sayýsý
		char ch175 = 175;
		cout << endl << "\tEnter the username of the your friend you want to add: " << endl << "\t" << ch175;
		getline(cin >> ws, frUserName);
		while (1) {
			if ((acc[j].getUsername()).length() == 0) {
				break;
			}
			if (acc[j].getUsername() == frUserName) {
				k = j;
				check2 = 1;
				break;
			}
			j++;
		}
		if (check2 == 0) {
			cout << endl << "\tThe person you are looking for could not be found :( \n\tPlease enter a valid username." << endl << endl;
		}
		for (i = 0; i < size; ++i) {
			if (acc[index].getFriends(i) == frUserName) {
				check = 0;
				cout << endl << "\tYou already have this friend..." << endl << endl;
				break;
			}
		}
		if (check == 1 && check2 == 1) {
			acc[index].setFriends(frUserName, size);
			size++;
			cout << endl << "\t" << frUserName << " has been added to your friend list.";
			for (i = 0; i < 5; ++i) {
				Sleep(400);
				cout << ".";
			}
			while (1) {
				if ((acc[k].getFriends(fr_size)).length() == 0) {
					break;
				}
				fr_size++;
			}
			acc[k].setFriends(acc[index].getUsername(), fr_size);
			cout << endl << endl;
		}
	}
	void removefriends() {
		string frUserName, temp;
		int i, check = 0, k, j = 0, check1, fr_size = 0, z, y; //k silinecek arkadaþýn indexi
		char ch175 = 175;
		cout << endl << "\tEnter the username of the your friend you want to remove: " << endl << "\t" << ch175;
		getline(cin >> ws, frUserName);
		if (size == 0) {
			cout << endl << "\tYou don't have any friends :(" << endl << endl;
		}
		else {
			for (i = 0; i < current_size; ++i) {
				if (acc[i].getUsername() == frUserName) {
					z = i;
					break;
				}
			}
			for (i = 0; i < size; ++i) {
				if (acc[index].getFriends(i) == frUserName) {
					check = 1;
					k = i;
					break;
				}
			}
			if (check == 1) {
				for (i = k; i < size; ++i) {
					temp = acc[index].getFriends(i + 1);
					acc[index].setFriends(temp, i);
				}/*
				if(i == size){
					acc[index].getFriends(i).clear();
				}*/
				size--;
				while (1) {
					if ((acc[z].getFriends(fr_size)).length() == 0) {
						break;
					}
					fr_size++;
				}
				for (i = 0; i < fr_size; ++i) {
					if (acc[z].getFriends(i) == acc[index].getUsername()) {
						y = i;
						break;
					}
				}
				for (i = y; i < fr_size; ++i) {
					temp = acc[z].getFriends(i + 1);
					acc[z].setFriends(temp, i);
				}/*
				if(i == fr_size){
					acc[k].getFriends(i).clear();
				}*/
				cout << "\t" << frUserName << " has been removed to your friend list.";
				for (i = 0; i < 5; ++i) {
					Sleep(400);
					cout << ".";
				}
				cout << endl << endl;
			}
			else {
				cout << endl << "\tThis friend is not already in your friend list." << endl << endl;
			}
		}
	}
};

void fileWrite(Account &a,Store &s,Admin &b){
	int i,j;
	Account *ac=&a;
	// GAMEFILE WRITING
	ofstream gamefile;
	gamefile.open ("games.txt");
	if(!gamefile){
		cerr<<"Game file couldn't opened! Consol terminated..."<<endl;
		exit(1);
	}
	else{
		for(i=0;i<now_gamenumber;++i){
			gamefile<<s.get_gameIndex(i)+1<<"-"<<s.get_gameName(i)<<"-"<<s.get_gameCat(i)<<"-"
			<<s.get_gamePrice(i)<<"-"<<s.get_gameRam(i)<<"-"<<s.get_gameSto(i)<<"-"
			<<s.get_gameExp(i);
			if(s.get_gameName(i+1).length()!=0){
				gamefile<<endl;
			}
		}
	}
	gamefile.close();
	// USERFILE WRITING
	ofstream userfile;
	userfile.open("users.txt");
	if(!userfile){
		cerr<<"User file couldn't opened! Consol terminated..."<<endl;
		exit(1);		
	}else{
		for(i=0;i<current_size;++i){
			userfile<<ac[i].getName()<<"-"<<ac[i].getSurname()<<"-"<<ac[i].getWallet()<<
			"-"<<ac[i].getMail()<<"-"<<ac[i].getUsername()<<"-"<<ac[i].get_phoneNumber()<<"-"<<ac[i].getPassword()<<"-"
			<<ac[i].getCard()<<"-"<<ac[i].get_cardMoney()<<"-"<<ac[i].get_creditSec()
			<<endl;
			j=0;
			while(1){ // FRIENDS
				if(ac[i].getFriends(j).length()!=0){
					userfile<<ac[i].getFriends(j);
				}
				if(ac[i].getFriends(j+1).length()!=0){
					userfile<<" ";
				}else{
					break;
				}
				++j;
			}
			userfile<<endl;
			j=0;
			while(1){ // GAMES
				if(ac[i].getGames(j).length()!=0){
					userfile<<ac[i].getGames(j);
				}
				if(ac[i].getGames(j+1).length()!=0){
					userfile<<"_";
				}else{
					break;
				}
				++j;
			}
			userfile<<endl;
			j=0;
			while(1){ // INSTALLED
				if(ac[i].get_installedGames(j).length()!=0){
					userfile<<ac[i].get_installedGames(j);
				}
				if(ac[i].get_installedGames(j+1).length()!=0){
					userfile<<"_";
				}else{
					break;
				}
				++j;
			}
			userfile<<endl;
			j=0;
			
			while(1){ // NOT LOADED
				if(ac[i].get_notLoaded(j).length()!=0){
					userfile<<ac[i].get_notLoaded(j);
				}
				if(ac[i].get_notLoaded(j+1).length()!=0){
					userfile<<"_";
				}else{
					break;
				}
				++j;
			}
			userfile<<endl;
			j=0;
			
			while(1){ // FAV
				if(ac[i].get_favGames(j).length()!=0){
					userfile<<ac[i].get_favGames(j);
				}
				if(ac[i].get_favGames(j+1).length()!=0){
					userfile<<"_";
				}else{
					break;
				}
				++j;
			}
			if(ac[i+1].getName().length()!=0){
				userfile<<endl;
			}else{
				continue;
			}
		}
	}
	userfile.close();
	// ADMIN WRITING
	ofstream adminfile;
	adminfile.open("admin.txt");	
	if(!adminfile){
		cerr<<"Admin file couldn't opened! Consol terminated..."<<endl;
		exit(1);
	}
	else{
		adminfile<<b.getUsername()<<"-"<<b.getPassword();
	}
	adminfile.close();
	//by
}

int userMenu(Account &a , Admin &bo,Store &st) {
	Store *s=&st;
	Account *ac=&a;
	Admin *b=&bo;
	string temp_attempt;
	char creditDec;
	char ch174 = 174, ch175 = 175, ch248 = 248;
	int i, select, sign = 1, dec = 1, indexer, u = 1, p = 1; // dec,u,p and sign is loop variables
	string m;
	while (sign) {
		cout<<endl<<ifstream("beam.txt").rdbuf()<<endl;
		cout << "\t\t\t\t\t\t";
		for (i = 0; i < 7; ++i)
			cout << ch174;
		cout << " LOGIN MENU ";
		for (i = 0; i < 7; ++i)
			cout << ch175;
		cout << "\n\n" << endl << "\t\t\t\t\t\t1. User Registration \n\t\t\t\t\t\t2. User Login\n\t\t\t\t\t\t3. Admin Login\n\t\t\t\t\t\t4. Exit\n\t\t\t\t\t\t" << ch175 << " ";
		cin >> select;
		system("cls");
		switch (select) {
		case 1: //	USER REGISTRATION
			cout<<endl<<"\t\t\tYOU CAN PRESS -1 ANYTIME TO GO BACK TO THE LOGIN MENU :)"<<endl;
			Sleep(3000);
			system("cls");
			dec=1;
			while (dec) {
				cout << ch175 << " e-mail: (you still have a chance for quit :) ) : ";
				cin >> m;
				if (m == "-1") {
					dec = 0; sign = 1;
				}else{
					for (i = 0; i < 20; ++i) { // max acc is 20
						if (m==ac[i].getMail() ) {
							cout << "There is already a Beam account for the mail you entered. Please enter the mail again." << endl;
							dec = 1;
							break;
						}
					}
					if(i==20){
						ac[current_size].setMail(m);
						break;
					}
				}
			}
			if (m != "-1") {
				dec=1;
				while (dec) {
					cout << ch175 << " Username: ";
					cin >> temp_attempt;
					for (i = 0; i < 20; ++i) { // max acc is 20
						if (temp_attempt==ac[i].getUsername() ) {
							cout << "There is already a Beam account for the username you entered. Please enter the username again." << endl;
							dec = 1;
							break;
						}
					}
					if(i==20){
						ac[current_size].setUsername(temp_attempt);
						break;
					}
				}
				
				if(m!="-1"){
					cout << ch175 << " Name: ";
					cin >> temp_attempt;
					if (temp_attempt == "-1") {
						sign = 1; dec = 0;
					}
					else {
						ac[current_size].setName(temp_attempt);
					}
	
					cout << ch175 << " Surname: ";
					cin >> temp_attempt;
					if (temp_attempt == "-1") {
						sign = 1; dec = 0;
					}
					else {
						ac[current_size].setSurname(temp_attempt);
					}
	
	
					cout << ch175 << " Password: ";
					cin >> temp_attempt;
					if (temp_attempt == "-1") {
						sign = 1; dec = 0;
					}
					else {
						ac[current_size].setPassword(temp_attempt);
					}
	
					cout << ch175 << " Phone number: ";
					cin >> temp_attempt;
					if (temp_attempt == "-1") {
						sign = 1; dec = 0;
					}
					else {
						ac[current_size].set_phoneNumber(temp_attempt);
					}
	
					cout << "Do you want to add credit card to Beam ? ( y / n ) : ";
					cin >> creditDec;
					dec = 1;
					
					while (1)
					{
						if (creditDec == 'y') {
							cout << ch175 << " Card number: ";
							cin >> temp_attempt;
							if (temp_attempt == "-1") {
								sign = 1; dec = 0; break;
							}
							else {
								ac[current_size].setCard(temp_attempt);
							}
							
							cout << ch175 << " Enter cash: ";
							cin >> temp_attempt;
							if (temp_attempt == "-1") {
								sign = 1; dec = 0; break;
							}
							else {
								ac[current_size].set_cardMoney(temp_attempt);
							}
	
	
							cout << ch175 << " Enter security number: ";
							cin >> temp_attempt;
							if (temp_attempt == "-1") {
								sign = 1; dec = 0; break;
							}
							else {
								ac[current_size].set_creditSec(temp_attempt);
							}
	
							ac[current_size].setWallet("0");
	
							break;
						}
						else if (creditDec == 'n') {
							ac[current_size].setCard("0");
							ac[current_size].set_cardMoney("0");
							ac[current_size].set_creditSec("0");
							ac[current_size].setWallet("0");
							cout << "No card entered your Beam account." << endl << endl;
							break;
						}
						else {
							cout << "Wrong attempt.. Please enter proper choice ( y / n ) :";
							continue;
						}
					}
					indexer = current_size;
					current_size++;
					sign = 0; // task is done, quit the loop
					cout << "Registration is succesfully done, now you need to log in your account again for your safety :)" << endl;
					for (i = 0; i < 41; ++i) {
						Sleep(90); // 1 second = 1000milisecond
						cout << ch248 << " ";
					}
					system("cls");
				}
			}
			system("cls");
			break;
		case 2: // lOGIN
			cout<<endl<<"\t\t\tYOU CAN PRESS -1 ANYTIME TO GO BACK TO THE LOGIN MENU :)"<<endl;
			Sleep(3000);
			system("cls");
			u=1;
			while (u) {
				cout << ch175 << " Username: "; // username attempt
				cin >> temp_attempt;
				if (temp_attempt == "-1") {
					u = 0; p = 0; sign = 1; break;
				}
				else {
					for (i = 0; i < 15; ++i) {
						if (ac[i].getUsername() == temp_attempt) {
							indexer = i;
							u = 0;
							p=1;
							break;
						}
					}
					if (u != 0) {
						cout << "No username matched in the system.. Please try again.." << endl;
						u = 1;
					}
				}
			}
			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			p=1;
			while (p) {
				cout << ch175 << " Password: "; // password attempt
				cin >> temp_attempt;
				if (ac[indexer].getPassword() == temp_attempt) {
					p = 0; sign = 0;
					// USER COULD ENTERED HIS/HER SELF ACCOUNT
				}
				else if (temp_attempt == "-1") {
					sign = 1; p = 0; break;
				}
				else {
					for (i = 3; i > 0; --i) {
						cout << "Wrong password attempt.. " << i << " attempts left you could enter correctly.. Otherwise we have to kick you from Beam." << endl;
						cout << ch175 << " ";
						cin >> temp_attempt;
						if (ac[indexer].getPassword() == temp_attempt) {
							// USER COULD ENTERED HIS/HER SELF ACCOUNT
							p = 0; sign = 0;
							break;
						}
					}
					if (i == 0) {
						cout << "All attempts you did is wrong.. Terminating beam";
						for (int j = 0; i < 3; ++i) {
							cout << "- ";
							Sleep(300);
						}
						system("cls");
						exit(1);
					}
				}
			}
			break;
		case 3:
			cout<<endl<<"\t\t\tYOU CAN PRESS -1 ANYTIME TO GO BACK TO THE LOGIN MENU :)"<<endl;
			Sleep(3000);
			system("cls");
			dec = 1; u = 1;
			while (dec) {
				cout << ch175 << " Admin Username: ";
				cin >> temp_attempt;
				if (temp_attempt == "-1") {
					sign = 1;
					dec = 0;
					system("cls");
				}
				else if (temp_attempt == b->getUsername()) {
					while (u) {
						cout << ch175 << " Admin Password: ";
						cin >> temp_attempt;
						if (temp_attempt == b->getPassword()) {
							indexer = -1;
							dec = 0;
							sign = 0;
							system("cls");
							u = 0;
						}
						else if (temp_attempt == "-1") {
							dec = 0;
							sign = 1;
							u = 0;
							system("cls");
						}
						else {
							for (i = 3; i > 0; i--) {
								cout << "Wrong admin password attempt.." << i << " attempts left, if all attempts are wrong, we will have to kick you out of the system.." << endl;
								cout << ch175 << " ";
								cin >> temp_attempt;
								if (temp_attempt == b->getPassword()) {
									indexer = -1;
									dec = 0;
									sign = 0;
									system("cls");
									u = 0;
									break;
								}
								else if (temp_attempt == "-1") {
									dec = 0;
									sign = 1;
									system("cls");
									u = 0;
									break;
								}
							}
							if (i == 0) {
								system("cls"); exit(1);
							}
						}
					}
				}
				else {
					cout << "No username matched in the system.. Try again.." << endl;
					continue;
				}
			}
			break;
		case 4:
			indexer=-2;
			sign=0;
			break;
		default:
			cout << "Wrong entry.. please attempt properly. Opening login page";
			for (i = 0; i < 3; ++i) {
				cout << ". ";
				Sleep(400);
			}
			sign = 1;
			break;
		}
		system("cls");
	}
	system("cls");
	return indexer;
}

// MAIN'IN BOLGESÝ


void fileRead(Account *ac,Store *s,Admin *b)  {
	int i,j;
	string a, temp; // a is one line of the file
	vector<string>a1; // a1 is divided version of string a
	char const delim = '-';
	char const delim1=' ';
	char const delim2='_';
	// GAME FILE READING
	ifstream gamefile("games.txt");
	if(!gamefile){
		cerr<<"Game file couldn't opened! Consol terminated";
		exit(1);
	}
	j=0;
	while(gamefile){
		getline(gamefile, a);
		stringstream ss(a);
		while(getline(ss, temp, delim))
		{
			a1.push_back(temp);
		}
		for(i=0; i<a1.size(); ++i)
		{
			switch(i)
			{
				case 0:
					s->set_gameIndex(j);
					break; 
				case 1:
					s->set_gameName(a1[i],j);
					break;
				case 2:
					s->set_gameCat(a1[i],j);
					break;
				case 3:
					s->set_gamePrice(a1[i],j);
					break;
				case 4:
					s->set_gameRam(a1[i],j);
					break;
				case 5:
					s->set_gameSto(a1[i],j);
					break;
				case 6:
					s->set_gameExp(a1[i],j);
					break;
			}
		}
		j++; a1.clear(); a.clear();
	}
	gamefile.close();
	
	// USER FILE READING
	j=0;
	ifstream userfile("users.txt");
	if(!userfile){
		cerr<<"User file couldn't opened! Consol terminated..."<<endl;
		cout<<endl;
		exit(1);
	}
	int counter;
	while(userfile){
		getline(userfile,a);
		stringstream ss(a);
		while(getline(ss,temp,delim))
		{
			a1.push_back(temp);
		}
		for(i=0;i<a1.size();++i) // 1.satýr : kullanýcý kisisel bilgiler
		{
			switch(i)
			{
				case 0:
					ac[j].accountIndex=j;
					ac[j].setName(a1[i]);
					break;
				case 1:
					ac[j].setSurname(a1[i]);
					break;
				case 2:
					ac[j].setWallet(a1[i]);
					break;
				case 3:
					ac[j].setMail(a1[i]);
					break;
				case 4:
					ac[j].setUsername(a1[i]);
					break;
				case 5:
					ac[j].set_phoneNumber(a1[i]);
					break;
				case 6:
					ac[j].setPassword(a1[i]);
					break;
				case 7:
					ac[j].setCard(a1[i]);
					break;
				case 8:
					ac[j].set_cardMoney(a1[i]);
					break;
				case 9:
					ac[j].set_creditSec(a1[i]);
					break;	
			}
		}
		a1.clear(); a.clear(); // REFRESH //
		
		getline(userfile,a);
		stringstream ss1(a);
		while(getline(ss1,temp,delim1))
		{
			a1.push_back(temp);	
		}
		for(i=0;i<a1.size();++i) // 2.satýr: arkadaslar
		{
			ac[j].setFriends(a1[i],i);
		}
		a1.clear(); a.clear(); // REFRESH //
		
		getline(userfile,a);
		stringstream ss2(a);
		while(getline(ss2,temp,delim2))
		{
			a1.push_back(temp);	
		}
		for(i=0;i<a1.size();++i) // 3.satýr : sahip olunan oyunlar
		{
			ac[j].setGames(a1[i],i);
		}
		a1.clear(); a.clear(); // REFRESH // 
		
		getline(userfile,a);
		stringstream ss3(a);
		while(getline(ss3,temp,delim2))
		{
			a1.push_back(temp);	
		}
		for(i=0;i<a1.size();++i) // 4.satýr: indirili oyunlar
		{
			ac[j].set_installedGames(a1[i],i);
		}		
		a1.clear(); a.clear(); // REFRESH // 		
		
		getline(userfile,a);
		stringstream ss4(a);
		while(getline(ss4,temp,delim2))
		{
			a1.push_back(temp);	
		}
		for(i=0;i<a1.size();++i) // 5.satýr: yüklenmemis oyunlar
		{
			ac[j].set_notLoaded(a1[i],i);
		}		
		a1.clear(); a.clear(); // REFRESH // 
		
		getline(userfile,a);
		stringstream ss5(a);
		while(getline(ss5,temp,delim2))
		{
			a1.push_back(temp);	
		}
		for(i=0;i<a1.size();++i) // 6.satýr: fav oyunlar
		{
			ac[j].set_favGames(a1[i],i);
		}		
		a1.clear(); a.clear(); // REFRESH // 		
		
		j++; // LOOP IS DONE INCREASE THE J
	}
	userfile.close();
	
	// ADMIN FILE READING
	ifstream adminfile("admin.txt");
	if(!adminfile){
		cerr<<"Admin file couldn't opened! Consol terminated..."<<endl;
		exit(1);
	}
	while(adminfile){
		getline(adminfile,a);
		stringstream ss6(a);
		while(getline(ss6,temp,delim)){
			a1.push_back(temp);
		}
	}
	for(i=0;i<a1.size();++i){
		switch(i){
			case 0:
				b->setUsername(a1[i]);
				break;
			case 1:
				b->setPassword(a1[i]);
				break;
		}
	}
	a1.clear(); a.clear();
	adminfile.close();
}

int StoreMenu(){
	char ch175=175; 
	int choice;
	while(1){
		system("cls");
		cout <<endl<<"\t\t\t1.Search Bar 2.Categories 3.Popular games 4.Special offers 5.All Games 6.Exit: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				return 1;
				break;
			case 2:
				return 2;
				break;
			case 3:
				return 3;
				break;
			case 4:
				return 4;
				break;
			case 5:
				return 5; 
				break;
			case 6:
				return 6;
				break;
			default:
				cout << "Wrong input. Please try again." << endl;
		}
	}
}

int mainMenu() {
	int choice;
	cout<<endl<<ifstream("beam.txt").rdbuf()<<endl;
	cout << endl << "\t\t1.STORE 2.LIBRARY 3.WHAT ARE MY FRIENDS DOING? 4.PROFILE 5.LOGOUT 6. EXIT FROM BEAM: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		return 1;
		break;
	case 2:
		return 2;
		break;
	case 3:
		return 3;
		break;
	case 4:
		return 4;
		break;
	case 5:
		return 5;
		break;
	case 6:
		return 6;
		break;
	default:
		return 7;
		break;
	}
}


int main() { // BEAM
	int choice, stop, storeMenuChoice, storeGameChoice, dec, i, select;
	char ch175=175;
	Store s;
	Account ac[20];
	GameLibrary gl;
	Friends f;
	Admin boss;
	Profile p;
	fileRead(ac, &s, &boss);
	while (1)
	{
		int index = userMenu(*ac, boss,s);
		if (index == -1) {
			cout <<endl<< "\t\t\t\t  WE MISSED YOU BOSS.. WHERE HAVE YOU BEEN :) " << endl;
			Sleep(3000);
			system("cls");
			cout << ch175 << " Transferring you to the administrator menu";
			for (i = 0; i < 3; ++i) {
				cout << ". ";
				Sleep(500);
			}
			dec = 1;
			system("cls");
			while (dec) {
				cout << endl<< "\t\t 1. ADD GAME 2. CHANGE GAME FEATURES 3. CHANGE LOGIN OPTIONS 4. LOGOUT 5. EXIT BEAM: ";
				cin >> select;
				boss.getGame(s);
				system("cls");
				switch (select) {
				case 1:
					boss.addGame();
					break;
				case 2:
					boss.changeGame();
					break;
				case 3:
					boss.changeLogin();
					break;
				case 4:
					dec = 0;
					break;
				case 5:
					system("cls");
					exit(1);
					break;
				default:
					cout << "Wrong choosing entry.. Please try again..";
					continue;
				}
				system("cls");
			}
		}
		else if(index==-2){
			fileWrite(*ac,s,boss);
			exit(0);	
		}else {
			stop = 1;
			while (stop) {
				choice = mainMenu();
				switch (choice)
				{
					case 1: // STORE
					for(i=0;i<now_gamenumber;i++){
						s.setdouble_price(stod(s.get_gamePrice(i)),i);
					}
					while(1){
						storeMenuChoice = StoreMenu();
						system("cls");
						if (storeMenuChoice == 1){
							storeGameChoice=s.searchbar();					
							if (storeGameChoice == 0){
								continue;
							}
							else {
								s.login(ac[index],p);
								s.loginall(*ac);
								s.selling(storeGameChoice);
							}
							s.destroyC();
						}
						else if (storeMenuChoice == 2){
							storeGameChoice = s.categorize();
							if (storeGameChoice == 0){
								continue;
							}
							else {
								s.login(ac[index],p);
								s.loginall(*ac);
								s.selling(storeGameChoice);
							}
							s.destroyC();
						}
						else if (storeMenuChoice == 3){
							storeGameChoice = s.Popular();
							if (storeGameChoice == 0){
								continue;
							}
							else {
								s.login(ac[index],p);
								s.loginall(*ac);
								s.selling(storeGameChoice);
							}
							s.destroyC();
						}
						else if(storeMenuChoice == 4){
							storeGameChoice = s.Special();
							if (storeGameChoice == 0){
								continue;
							}
							else {
								s.login(ac[index],p);
								s.loginall(*ac);
								for(int i=0;i<now_gamenumber;i++){
									s.set_discountgames(i,s.get_double_price(i)-(s.get_double_price(i)*0.1));
								}
								s.sellingSpecial(storeGameChoice);
							}
							s.destroyC();
						}
						else if(storeMenuChoice == 5){
							s.allGameList();
							for(i=0;i<50;++i){
								cout<<".";
								Sleep(200);
							}						
						}
						else if(storeMenuChoice == 6){
							break;
						}
						else {
							// wrong input
						}
					}						
					break;
				case 2: // GAME LIBRARY
					ac[index].set_nlSize();
					gl.login(ac[index]);
					ac[index] = gl.library();
					break;
				case 3: //FRIENDS
					f.setIndex(index);
					f.login(*ac);
					*ac = f.friends();
					break;
				case 4: // PROFILE
					p.login(ac[index]);
					p.profile_menu();
					break;
				case 5:
					system("cls");
					stop = 0;
					break;
				case 6:
					system("cls");
					fileWrite(*ac,s,boss);
					exit(0);
					break;
				default:
					cout << "Wrong choice attempt.. Please try again.. " << endl;
					Sleep(500);
					system("cls");
					stop = 1;
				}
			}
		}
	}
	return 0;
}





























