#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<sstream>//ฟังก์ชันแปลตัวเลขเป้นหนังสือ
using namespace std;
int a;
void menu_bank();
void mian_p();
void mian_menu();
void deposit_1();
void Withdraw();
void Transfer_money();
void report_account();
void report_all();
string account[100][3] = {
						 {"001","Jiraporn ","Saving"},
						 {"002","Phanakron","Saving"},
						 {"003","Samith","Saving"},
						 };
int amount[100];
string report[100][4] ;
int index;
int main()
{	//หน้าแรก เมนูธนาคาร
	mian_menu();
	system ("cls");
	return(0);
}
//รายการที่สามารถทำได้
void menu_bank()
{
	int money= 0,deposit,withdraw,transfer;
	char menu;
	system("cls");

	cout << "welcome "<< account[index][1] << endl;
	cout << "Type account : " << account[index][2] << endl;
	cout << "Account balance : " << amount[index] << endl;
	cout << setfill('-')<<setw(40)<<"-"<<endl;
	cout << "1.Deposit" << endl;
	cout << "2.Withdraw" << endl;
	cout << "3.Transfer" << endl;
	cout << "4.Report" << endl;
	cout << "5.Exit"<<endl;
	cout << setfill('-')<<setw(40)<<"-"<<endl;
	
	cout << "Please select a menu : " ;
	cin >> menu ;
		
		switch(menu) {
			case '1': 
				system ("cls");
				deposit_1();
				break;
		
			case '2':
				system ("cls");
				Withdraw();
				break;
			case '3': 
				system ("cls");
				Transfer_money();
				break;
			case '4':
				system ("cls");
				report_account();
				break;
			case '5':
				cout << "----Exit----\n";
				mian_menu();
				break;
			default:
				cout << "Please try again.\n";
				menu_bank();
		}		
	
}

void mian_p()
{
		cout << setfill('=')<<setw(40)<<" "<<endl;
		cout << "\tWELCOME TO THE BANK\n";
		cout << setfill('=')<<setw(40)<<" "<<endl;
		cout << "1.Check information" << endl;
		cout << "2.Balance report" << endl;
		cout << "3.Log out"<<endl;
		cout << setfill('=')<<setw(40)<<" "<<endl;
}
void mian_menu()
{
	string ac_num;
	int balance;
	string nameaccount,deposit_type ;
	char menu,select1 ;
	bool pass = false;
	system ("cls");
		cout << setfill('=')<<setw(40)<<" "<<endl;
		cout << "\tWELCOME TO THE BANK\n";
		cout << setfill('=')<<setw(40)<<" "<<endl;
		cout << "1.Check information" << endl;
		cout << "2.Balance report" << endl;
		cout << "3.Log out"<<endl;
		cout << setfill('=')<<setw(40)<<" "<<endl;
		cout << "Please select a Menu : " ;
		cin >> menu ;
		
		
		if(menu=='1')
		{
			//ล็อคอินเข้าเมนู
			cout << "Please enter account number : ";
			cin>>ac_num;

			for(int i = 0; i < 100; i++)
			{
				if (ac_num == account[i][0]) 
				{
					pass = true;
					index = i; //อ้างอิงตำแหน่งในอาเรยย์
				}
			}
			if (pass)
			{
				menu_bank();
			}
			else 
			{
				system ("cls");
				cout << "----Account number not found--- " << endl;
				cout << "1.register account\n";
				cout << "2.back to menu \n";
				cin >> select1;
					switch (select1)
						{
							case '1':
								system ("cls");
								cout << "==========register=============\n";
									for(int j = 0; j < 100; j++) 
									{
										if (account[j][0].empty())
										{	
											cout <<"please enter account number :";
											cin >> account[j][0];
											cout << "please user name : ";
											cin >> account[j][1];
											cout << "please enter type (Daving(D) | Fixed deposit (FD)) : ";
											cin >> account[j][2];
											amount[j]= 0;
											break;
										}
									}
								mian_menu();
								break;
				
							case '2':
								mian_menu();
								break;
							default	:
								mian_menu();
				
						}
				
			}
			cout << setfill('-')<<setw(40)<<"-"<<endl;
		}

		else if (menu == '2')
		{
			system ("cls");
			report_all();
		}
		else if (menu == '3') 
		{
			cout << "----Exit----\n";
			exit(0);
		}
		else
		{
			cout << "Please try again.\n";
			mian_menu();
		}
		
}
void deposit_1()
{
	int deposit;
	char select1;
	cout << "Deposit money : ";
	cin >> deposit;
	amount[index] += deposit;
	for(int j = 0; j < 100; j++) 
	{
		if (report[j][0].empty())
		{	
			stringstream money;
			money << deposit;
			report[j][0] = account[index][0];
			report[j][1] = "Deposit"; //ประเภทในรายงาน
			report[j][2] = money.str();
			report[j][3] = "none";
			break;
		}
	}
	cout << "Your Balance is : " << amount[index] << endl;
	cout << setfill('-')<<setw(40)<<"-"<<endl;
	cout << "Wouldn you like to make a new deposit : " << endl;
	cout << "1.agian\n";
	cout << "2.back to menu \n";
	cout << "Enter menu : ";
	cin >> select1;
		switch (select1)
			{
				case '1':
					system ("cls");
					deposit_1();
					break;
				
				case '2':
					menu_bank();
					break;
				default	:
					menu_bank();
				
			}
}
void Withdraw()
{
	int withdraw;
	char select1;
	cout << "Withdraw money : ";
	cin >> withdraw;
	amount[index]-= withdraw;
	cout << "Your Balance is : " <<amount[index] << endl;
	for(int j = 0; j < 100; j++) 
	{
		if (report[j][0].empty())
		{	
			stringstream money;
			money << withdraw ;
			report[j][0] = account[index][0];
			report[j][1] = "Withdraw"; //ประเภทในรายงาน
			report[j][2] = money.str();
			report[j][3] = "none";
			break;
		}
	}
	cout << setfill('-')<<setw(40)<<"-"<<endl;
	cout << "Wouldn you like to make a new withdraw : " << endl;
	cout << "1.agian\n";
	cout << "2.back to menu \n";
	cout << "Enter menu : ";
	cin >> select1;
		switch (select1)
			{
				case '1':
					system ("cls");
					Withdraw();
					break;
				
				case '2':
					menu_bank();
					break;
				default	:
					menu_bank();
				
			}
}
void Transfer_money()
{
	int transfer;
	char select1;
	string acc;
	bool pass = false ;
	int acc_index;
	cout << "Transfer To Account :";
	cin >> acc;
	cout << "Transfer money : ";
	cin >> transfer;
	for(int i = 0; i < 100; i++)//หาทุก บัญชีว่าตรงกันไหม		
	{
				if (acc == account[i][0]) 
				{
					pass = true;
					acc_index = i; 
					break;
				}
	}
	if (pass == true)
	{

		amount[acc_index] += transfer;
		amount[index]-= transfer;
		cout << "Your Balance is : " << amount[index] << endl;
		for(int j = 0; j < 100; j++) 
	{
		if (report[j][0].empty())
		{	
			stringstream money;
			money << transfer ;
			report[j][0] = account[index][0];
			report[j][1] = "Transfer"; //ประเภทในรายงาน
			report[j][2] = money.str();
			report[j][3] = account[acc_index][0];//บันทึกรายการว่าโอนไปให้คนนี้เท่าไหร่
			break;
		}
	}
	}
	else 
	{
		cout << "----Account not found----\n";
	}
	cout << setfill('-')<<setw(40)<<"-"<<endl;
	cout << "Wouldn you like to make a new withdraw : " << endl;
	cout << "1.agian\n";
	cout << "2.back to menu \n";
	cout << "Enter menu : ";
	cin >> select1;
		switch (select1)
			{
				case '1':
					system ("cls");
					Transfer_money();
					break;
				
				case '2':
					menu_bank();
					break;
				default	:
					menu_bank();
			}
}
void report_account()
{
	cout << setw(65)<<setfill (' ') << "REPORT " <<endl;
	cout << setw(20)<<"No."<<setw(20)<<" Type"<<setw(20)<< "Money" << setw(20) << "Recipient"<<endl;
	for (int i = 0 ; i < 100 ; i++)
	{
		if (report[i][0] == account[index][0])
		{
			cout << setw(20)<<setfill (' ')<< i+1 <<setw(20)<< setfill (' ')<< report[i][1] <<setw(20)<< setfill (' ')<< report[i][2] << setw(20)<< setfill (' ') << report[i][3] <<endl;
		}
	}
	cout << "Please enter key to menu \n";
	cin.get();//รับค่าคีย์บอร์ด
	cin.ignore();//ให้กดปุ่มไหนก็ได้จะกลับไปหน้าแรก
	menu_bank();
}
void report_all()
{
	cout << "\n\n";
	cout << setw(65)<<setfill (' ') << "REPORT ALL" <<endl;
	cout <<endl;
	cout << setfill('=')<<setw(120)<<"="<<endl;
	cout << setw(20)<<setfill (' ')<<"No."<<setw(20)<<setfill (' ')<<"Account number";
	cout << setw(20)<<setfill (' ')<< "Name" << setw(20)<<setfill (' ') << "type"<< setw(20) << "Amount"<<endl;
	for (int i = 0 ; i < 100 ; i++)
	{
		if(!account[i][0].empty())//เช็คว่ามันว่างหรือป่าว
		{
			cout << setw(20)<<setfill (' ')<< i +1 <<setw(20)<<setfill (' ')<< account[i][0] <<setw(20)<<setfill (' ')<< account[i][1] ;
			cout << setw(20)<<setfill (' ')<< account[i][2] << setw(20) <<setfill (' ') << amount[i] <<endl;
		}
		else
		{
		break;
		}
	}
	cout << setfill('=')<<setw(120)<<"="<<endl;
	cout << "Please enter key to menu \n";
	cin.get();//รับค่าคีย์บอร์ด
	cin.ignore();//ให้กดปุ่มไหนก็ได้จะกลับไปหน้าแรก
	mian_menu();
}