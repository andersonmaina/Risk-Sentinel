#include <iostream>
#include <string.h>
#include <fstream>
#include <chrono>
#include <windows.h>
#include <math.h>
#include <thread>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <shellapi.h>
#include <wininet.h>
#include <map>

using namespace std;

//GLOBAL CONSTANTS
const double recommended_risk = 2.0000000001;

//GLOBAL VARIABLES
int instrument = 0;
double previous_price = 0.0;
double account_balance = 0.0;
double digits = 0.0;
string color, user_currency;

bool currency = false;//usd
bool currency_2 = false;
bool currency_3 = false;
bool metal = false;
bool index = false;
bool index_2 = false;

bool long_ = false;
bool short_ = false;

char *date_time;

//COMMON OPTIONS/CHOICES
string one = "1";
string two = "2";
string three = "3";
string four = "4";
string five = "5";
string six = "6";
string seven = "7";
string eight = "8";
string nine = "9";
string ten = "10";
string default_ = "0";

//SYSMBOL COEFFFICIENT CONSTANTS
const double usd_plus = 100.00;
const double usd_less = 100.00;

const double jpy_plus = 147.8;
const double jpy_less = 67.7;

const double cad_plus = 136.4;
const double cad_less = 73.3;

const double metal_plus = 100.00;
const double metal_less = 100.00;

const double index_1_plus = 100.00;
const double index_1_less = 1.00;

const double index_2_plus = 100.00;
const double index_2_less = 10.00;

// COMMON VARIABLE
double capture_initial_account_balance = 0.0;
string capture_trade_type = "null";
string capture_instrument = "No pair";
string captured_instrument = "null";
string capture_method = "null";
string capture_group = "null";
//new variables


// PROFIT VARIABLES
double capture_lot_size = 0.0, capture_profit = 0.0, capture_pip_value = 0.0;
//new variables

//new variables

// TARGET PRICES VARIABLES
double capture_profit_amount = 0.0,capture_loss_amount = 0.0,capture_profit_pips = 0.0,capture_loss_pips = 0.0;
double capture_positon_size = 0.0, capture_market_price = 0.0, capture_profit_ticks = 0.0,capture_loss_ticks = 0.0;
double capture_target_price = 0.0, capture_stop_loss = 0.0;
string capture_risk_reward_ratio = "null";
//new variables

// PIPS VARIABLES
double capture_close_price = 0.0, capture_number_of_ticks = 0.0, capture_number_of_pips = 0.0;
//new variables


class FX_INSTRUMENTS
{
public:

    //EXPERT VARIABLES

    int option;

    double number_of_pips, number_of_ticks;
    double market_price, close_price, open_price;
    double profit_amount,loss_amount;
    double profit_pips, loss_pips;
    double risk,risk_ratio,reward_ratio;
    double profit_ticks,loss_ticks;
    double target_price,stop_loss;
    double position_size;

    string risk_reward_ratio;

    bool out_of_range = true;

    char currencies[4][25] = {"EURUSD", "GBPUSD", "NZDUSD", "AUDUSD"};
    char currencies_2[5][25] = {"USDJPY", "GBPJPY", "EURJPY", "AUDJPY" ,"NZDJPY"};
    char currencies_3[5][25] = {"AUDCAD", "USDCAD", "GBPCAD", "NZDCAD", "EURCAD"};
    char currencies_4[5][25] = {"GBPAUD", "EURAUD", "USDAUD", "JPY/AUD", "CADAUD"};
    char metals[1][25] = {"XAUUSD"};
    char indices[1][25] = {"NAS100/USTECH/NASDAQ"};
    char indices_2[1][25] = {"US30"};

    double lot_size, pip_value, profit,loss;

    void clearBuffer()
    {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout.flush(); 
    }

    void register_instrument()
    {
        system("cls");

        clearBuffer();

        cout << "CHOOSE THE INSTRUMENT YOU WANT TO LOAD\n";

        if (currency == true)
        {
            capture_group = "CURRENCY";

            cout << "<====FX-CURRENCIES===>\n";
            for (int i = 0; i < 4; i++)
            {
                cout << i + 1 << "." << currencies[i] << "\n";
            }
            cout << "\nEnter option: ";
            cin >> option;
            instrument = option - 1;
            capture_instrument = currencies[instrument];
            captured_instrument = capture_instrument;
        }
        if (currency_2 == true)
        {
            capture_group = "CURRENCY_2";

            cout << "<====FX-CURRENCIES_2===>\n";
            for (int i = 0; i < 5; i++)
            {
                cout << i + 1 << "." << currencies_2[i] << "\n";
            }
            cout << "\nEnter option: ";
            cin >> option;
            instrument = option - 1;
            capture_instrument = currencies_2[instrument];
            captured_instrument = capture_instrument;
        }
        if (currency_3 == true)
        {
            capture_group = "CURRENCY_2";

            cout << "<====FX-CURRENCIES_2===>\n";
            for (int i = 0; i < 5; i++)
            {
                cout << i + 1 << "." << currencies_3[i] << "\n";
            }
            cout << "\nEnter option: ";
            cin >> option;
            instrument = option - 1;
            capture_instrument = currencies_3[instrument];
            captured_instrument = capture_instrument;
        }
        if (metal == true)
        {
            capture_group = "METAL";

            cout << "<====FX-METALS===>\n";
            for (int j = 0; j < 1; j++)
            {
                cout << j + 1 << "." << metals[j] << "\n";
            }
            cout << "\nEnter option: ";
            cin >> option;
            instrument = option - 1;
            capture_instrument = metals[instrument];
            captured_instrument = capture_instrument;
        }

        if(index == true)
        {
            capture_group = "INDEX";

            cout << "<====FX-INDICES==>\n";
            for (int j = 0; j < 1; j++)
            {
                cout << j + 1 << "." << indices[j] << "\n";
            }
            cout << "\nEnter option: ";
            cin >> option;
            instrument = option - 1;
            capture_instrument = indices[instrument];
            captured_instrument = capture_instrument;
        }
        if(index_2 == true)
        {
            capture_group = "INDEX(2)";

            cout << "<====FX-INDICES==>\n";
            for (int j = 0; j < 1; j++)
            {
                cout << j + 1 << "." << indices_2[j] << "\n";
            }
            cout << "\nEnter option: ";
            cin >> option;
            instrument = option - 1;
            capture_instrument = indices_2[instrument];
            captured_instrument = capture_instrument;
        }
    }

    void register_trade_type()
    {
        clearBuffer();

        string type;
        cout << "1.Long\n2.Short\n";
        cout << "Enter trade type: ";
        cin >> type;
        if (type == one)
        {
            long_ = true;
            short_ = false;

            capture_trade_type = "LONG";
        }
        else if (type == two)
        {
            short_ = true;
            long_ = false;

            capture_trade_type = "SHORT";
        }
        else
        {
            cout << "Invalid choice, try again...\n";
            system("pause");
            register_trade_type();
        }
    }

    void compute_target_price()
    {
        clearBuffer();

        cout<<"\nChoose method\n";
        cout<<"<==AVAILABLE METHODS==>\n";
        cout<<"1.By profit/loss\n2.By Pips\n3.By RR\n4.Back\n";
        cout<<"Select method: ";

        string method;
        cin>>method;

        if(method == one)
        {
            double real_profit_amount,real_loss_amount;

            capture_method = "By price";

            cout<<"How much money do you want(in any currency)? \n";
            cout<<"Enter amount: ";
            cin>>profit_amount;

            cout<<"How much money are you risking to lose ?\n";
            cout<<"Enter amount: ";
            cin>>loss_amount;

            cout << "Enter position size: ";
            cin >> position_size;

            cout << "Enter market/open price: ";
            cin >> market_price;

            if (currency == true) //OKAY
            {
                real_profit_amount = (usd_plus * profit_amount)/100;
                real_loss_amount = (usd_plus * loss_amount)/100;

                profit_ticks = real_profit_amount / position_size;
                loss_ticks= real_loss_amount/position_size ;

                if (long_ == true)
                {
                    target_price = market_price + (profit_ticks * 0.00001);
                    stop_loss = market_price - (loss_ticks * 0.00001);
                }
                if (short_ == true)
                {
                    target_price = market_price - (profit_ticks * 0.00001);
                    stop_loss = market_price + (loss_ticks * 0.00001);
                }
                cout << "\nInstrument: " << currencies[instrument] << "\n";
                cout << "Appropriate Target price: " << target_price << "\n";
                cout << "Apprpriate Stop Loss: "<<stop_loss << "\n";
            }
            if (currency_2 == true)//OKAY
            {                
                real_profit_amount = (jpy_plus * profit_amount)/100;
                real_loss_amount = (jpy_plus * loss_amount)/100;

                profit_ticks = real_profit_amount / position_size;
                loss_ticks= real_loss_amount/position_size ;
                
                if (long_ == true)
                {
                    target_price = market_price + (profit_ticks * 0.001);
                    stop_loss = market_price - (loss_ticks * 0.001);
                }
                if (short_ == true)
                {
                    target_price = market_price - (profit_ticks * 0.001);
                    stop_loss = market_price + (loss_ticks * 0.001);
                }
                cout << "\nInstrument: " << currencies_2[instrument] << "\n";
                cout << "Appropriate Target price: " << target_price << "\n";
                cout << "Apprpriate Stop Loss: "<<stop_loss << "\n";
            }
            if (currency_3 == true)//OKAY
            {
                real_profit_amount = (cad_plus * profit_amount)/100;//73.3
                real_loss_amount = (cad_plus * loss_amount)/100;

                profit_ticks = real_profit_amount / position_size;
                loss_ticks= real_loss_amount/position_size ;

                if (long_ == true)
                {
                    target_price = market_price + (profit_ticks * 0.00001);
                    stop_loss = market_price - (loss_ticks * 0.00001);
                }
                if (short_ == true)
                {
                    target_price = market_price - (profit_ticks * 0.00001);
                    stop_loss = market_price + (loss_ticks * 0.00001);
                }
                cout << "\nInstrument: " << currencies_3[instrument] << "\n";
                cout << "Appropriate Target price: " << target_price << "\n";
                cout << "Apprpriate Stop Loss: "<<stop_loss << "\n";
            }
            if (metal == true)//OKAY
            {
                real_profit_amount = (metal_plus * profit_amount)/100;
                real_loss_amount = (metal_plus * loss_amount)/100;

                profit_ticks = real_profit_amount / position_size;
                loss_ticks= real_loss_amount/position_size ;

                if (long_ == true)
                {
                    target_price = market_price + (profit_ticks * 0.01);
                    stop_loss = market_price - (loss_ticks * 0.01);
                }
                if (short_ == true)
                {
                    target_price = market_price - (profit_ticks * 0.01);
                    stop_loss = market_price + (loss_ticks * 0.01);
                }
                cout << "\nInstrument: " << metals[instrument] << "\n";
                cout << "Appropriate Target price: " << target_price << "\n";
                cout << "Apprpriate Stop Loss: "<<stop_loss << "\n";
            }
            if (index == true)// OKAY
            {
                real_profit_amount = (index_1_plus * profit_amount)/100;
                real_loss_amount = (index_1_plus * loss_amount)/100;

                profit_ticks = real_profit_amount / position_size;
                loss_ticks= real_loss_amount/position_size ;

                if (long_ == true)
                {
                    target_price = market_price + (profit_ticks * 1); 
                    stop_loss = market_price - (loss_ticks * 1);
                }
                if (short_ == true)
                {
                    target_price = market_price - (profit_ticks * 1);
                    stop_loss = market_price + (loss_ticks * 1);
                }
                cout << "\nInstrument: " << indices[instrument] << "\n";
                cout << "Appropriate Target price: " << target_price << "\n";
                cout << "Apprpriate Stop Loss: "<<stop_loss << "\n";
            }
            if (index_2 == true)//OKAY
            {
                real_profit_amount = (index_2_plus * profit_amount)/100;
                real_loss_amount = (index_2_plus * loss_amount)/100;

                profit_ticks = real_profit_amount / position_size;
                loss_ticks= real_loss_amount/position_size ;

                if (long_ == true)
                {
                    target_price = market_price + (profit_ticks * 1);
                    stop_loss = market_price - (loss_ticks * 0.1);
                }
                if (short_ == true)
                {
                    target_price = market_price - (profit_ticks * 1);
                    stop_loss = market_price + (loss_ticks * 1);
                }
                cout << "\nInstrument: " << indices_2[instrument] << "\n";
                cout << "Appropriate Target price: " << target_price << "\n";
                cout << "Apprpriate Stop Loss: "<<stop_loss << "\n";
            }
            system("pause");
        }
        else if(method == two)
        {
            capture_method = "By pips";

            cout<<"How many pips are you targeting ?\n";
            cin>>profit_pips;

            cout<<"How many pips are you risking?\n";
            cin>>loss_pips;

            cout << "Enter position size: ";
            cin >> position_size;

            cout << "Enter market/open price: ";
            cin >> market_price;

            if(currency == true)//OKAY
            {
                profit_ticks = profit_pips * 10;
                loss_ticks = loss_pips * 10;

                if(long_ ==true)
                {
                    target_price = market_price + (profit_ticks * 0.00001);
                    stop_loss = market_price - (loss_ticks * 0.00001);
                }
                if(short_ == true)
                {
                    target_price = market_price - (profit_ticks * 0.00001);
                    stop_loss = market_price + (loss_ticks * 0.00001);
                }
                cout << "\nInstrument: " << currencies[instrument] << "\n";
                cout << "Appropriate Target price: " << target_price << "\n";
                cout << "Apprpriate Stop Loss: "<<stop_loss << "\n";
            }
            else if(currency_2 == true)//OKAY
            {
                profit_ticks = profit_pips * 10;
                loss_ticks = loss_pips * 10;

                if(long_ ==true)
                {
                    target_price = market_price + (profit_ticks * 0.001);
                    stop_loss = market_price - (loss_ticks * 0.001);
                }
                if(short_ == true)
                {
                    target_price = market_price - (profit_ticks * 0.001);
                    stop_loss = market_price + (loss_ticks * 0.001);
                }
                cout << "\nInstrument: " << currencies_2[instrument] << "\n";
                cout << "Appropriate Target price: " << target_price << "\n";
                cout << "Apprpriate Stop Loss: "<<stop_loss << "\n";
            }
            else if(currency_3 == true)//OKAY
            {
                profit_ticks = profit_pips * 10;
                loss_ticks = loss_pips * 10;

                if(long_ ==true)
                {
                    target_price = market_price + (profit_ticks * 0.00001);
                    stop_loss = market_price - (loss_ticks * 0.00001);
                }
                if(short_ == true)
                {
                    target_price = market_price - (profit_ticks * 0.00001);
                    stop_loss = market_price + (loss_ticks * 0.00001);
                }
                cout << "\nInstrument: " << currencies_3[instrument] << "\n";
                cout << "Appropriate Target price: " << target_price << "\n";
                cout << "Apprpriate Stop Loss: "<<stop_loss << "\n";
            }
            else if(metal == true)//OKAY
            {
                profit_ticks = profit_pips * 10;
                loss_ticks = loss_pips * 10;

                if(long_ ==true)
                {
                    target_price = market_price + (profit_ticks * 0.01);
                    stop_loss = market_price - (loss_ticks * 0.01);
                }
                if(short_ == true)
                {
                    target_price = market_price - (profit_ticks * 0.01);
                    stop_loss = market_price + (loss_ticks * 0.01);
                }
                cout << "\nInstrument: " << metals[instrument] << "\n";
                cout << "Appropriate Target price: " << target_price << "\n";
                cout << "Apprpriate Stop Loss: "<<stop_loss << "\n";
            }
            else if(index == true)//OKAY
            {
                profit_ticks = profit_pips * 10;
                loss_ticks = loss_pips * 10;

                if(long_ ==true)
                {
                    target_price = market_price + (profit_ticks * 0.01);
                    stop_loss = market_price - (loss_ticks * 0.01);
                }
                if(short_ == true)
                {
                    target_price = market_price - (profit_ticks * 0.01);
                    stop_loss = market_price + (loss_ticks * 0.01);
                }
                cout << "\nInstrument: " << indices[instrument] << "\n";
                cout << "Appropriate Target price: " << target_price << "\n";
                cout << "Apprpriate Stop Loss: "<<stop_loss << "\n";
            }
            else if(index_2 == true)//OKAY
            {
                profit_ticks = profit_pips * 1;
                loss_ticks = loss_pips * 1;

                if(long_ ==true)
                {
                    target_price = market_price + (profit_ticks * 1);
                    stop_loss = market_price - (loss_ticks * 1);
                }
                if(short_ == true)//OKAY
                {
                    target_price = market_price - (profit_ticks * 1);
                    stop_loss = market_price + (loss_ticks * 1);
                }
                cout << "\nInstrument: " << indices_2[instrument] << "\n";
                cout << "Appropriate Target price: " << target_price << "\n";
                cout << "Apprpriate Stop Loss: "<<stop_loss << "\n";
            }
            system("pause");
        }
        else if(method == three)
        {
            capture_method = "By RR";

            bool out_of_range = true;

            cout<<"Enter risk(in % (0-100) of your account balance("<<account_balance<<")): ";

            while(out_of_range == true)
            {
                cin>>risk;
                Sleep(2000);
                cout<<"\nAmount in risk: "<<((risk/100)*account_balance)<<"\n";
                Sleep(2000);
                if(risk>=0 && risk<=100)
                {
                    if(((risk/100)*account_balance)>((recommended_risk/100)*account_balance))
                    {
                        cout<<"**EA: Warning ! More than 2% of your account is at risk.\n\n";
                        Sleep(2000);
                        out_of_range = false;
                    }
                    else
                    {
                        out_of_range = false;
                    }
                }
                else
                {
                    cout<<"Value out of range, try again.\n";
                    out_of_range = true;
                }
            }

            cout<<"Provide risk-reward ratio(eg.1 then 2, where 1 is risk and 2 is reward ,1:2)\n";

            cout<<"Enter risk: ";
            cin>>risk_ratio;
            cout<<"Enter reward: ";
            cin>>reward_ratio;

            ostringstream oss;
            oss << risk_ratio <<":"<<reward_ratio;
            risk_reward_ratio = oss.str();

            Sleep(1000);
            cout<<"\nRisk reward ratio in effect---->"<<risk_ratio<<":"<<reward_ratio<<"\n";
            Sleep(1000);


            cout << "Enter market/open price: ";
            cin >> market_price;

            profit_ticks = reward_ratio*((risk/100)*account_balance)*100;
            loss_ticks= risk_ratio*((risk/100)*account_balance)*100;

            if(currency == true)//OKAY
            {
                if(long_ ==true)
                {
                    target_price = market_price + (profit_ticks * 0.00001);
                    stop_loss = market_price - (loss_ticks * 0.00001);
                }
                if(short_ == true)
                {
                    target_price = market_price - (profit_ticks * 0.00001);
                    stop_loss = market_price + (loss_ticks * 0.00001);
                }
                cout << "\nInstrument: " << currencies[instrument] << "\n";
                cout << "Appropriate Target price: " << target_price << "\n";
                cout << "Apprpriate Stop Loss: "<<stop_loss << "\n";
            }
            else if(currency_2 == true)//OKAY
            {
                if(long_ ==true)
                {
                    target_price = market_price + (profit_ticks * 0.001);
                    stop_loss = market_price - (loss_ticks * 0.001);
                }
                if(short_ == true)
                {
                    target_price = market_price - (profit_ticks * 0.001);
                    stop_loss = market_price + (loss_ticks * 0.001);
                }
                cout << "\nInstrument: " << currencies_2[instrument] << "\n";
                cout << "Appropriate Target price: " << target_price << "\n";
                cout << "Apprpriate Stop Loss: "<<stop_loss << "\n";
            }
            else if(currency_3 == true)//OKAY
            {
                if(long_ ==true)
                {
                    target_price = market_price + (profit_ticks * 0.00001);
                    stop_loss = market_price - (loss_ticks * 0.00001);
                }
                if(short_ == true)
                {
                    target_price = market_price - (profit_ticks * 0.00001);
                    stop_loss = market_price + (loss_ticks * 0.00001);
                }
                cout << "\nInstrument: " << currencies_3[instrument] << "\n";
                cout << "Appropriate Target price: " << target_price << "\n";
                cout << "Apprpriate Stop Loss: "<<stop_loss << "\n";
            }
            else if(metal == true)//OKAY
            {
                if(long_ ==true)
                {
                    target_price = market_price + (profit_ticks * 0.01);
                    stop_loss = market_price - (loss_ticks * 0.01);
                }
                if(short_ == true)
                {
                    target_price = market_price - (profit_ticks * 0.01);
                    stop_loss = market_price + (loss_ticks * 0.01);
                }
                cout << "\nInstrument: " << metals[instrument] << "\n";
                cout << "Appropriate Target price: " << target_price << "\n";
                cout << "Apprpriate Stop Loss: "<<stop_loss << "\n";
            }
            else if(index == true)//OKAY
            {
                if(long_ ==true)
                {
                    target_price = market_price + (profit_ticks * 1);
                    stop_loss = market_price - (loss_ticks * 1);
                }
                if(short_ == true)
                {
                    target_price = market_price - (profit_ticks * 1);
                    stop_loss = market_price + (loss_ticks * 1);
                }
                cout << "\nInstrument: " << indices[instrument] << "\n";
                cout << "Appropriate Target price: " << target_price << "\n";
                cout << "Apprpriate Stop Loss: "<<stop_loss << "\n";
            }
            else if(index_2 == true)//OKAY
            {
                if(long_ ==true)
                {
                    target_price = market_price + (profit_ticks * 1);
                    stop_loss = market_price - (loss_ticks * 1);
                }
                if(short_ == true)
                {
                    target_price = market_price - (profit_ticks * 1);
                    stop_loss = market_price + (loss_ticks * 1);
                }
                cout << "\nInstrument: " << indices_2[instrument] << "\n";
                cout << "Appropriate Target price: " << target_price << "\n";
                cout << "Apprpriate Stop Loss: "<<stop_loss << "\n";
            }
            system("pause");
        }
        else if(method == four)
        {
            system("pause");
        }
        else
        {
            cout<<"Invalid option, try again.\n";
            system("pause");
        }
    }

    void compute_profit_loss()
    {
        clearBuffer();

        double tp_price,sl_price,tp_pips,sl_pips;

        string choice;
        bool profit_=false,loss_=false,rr_choosen=false;

        cout<<"1.Profit\n2.Loss\n3.Both Profit & Loss\n4.Continue to RR\n5.Back\n";
        cout<<"Choose result: ";
        cin>>choice;

        if(choice == one)
        {
            profit_ = true;
            loss_ = false;
        }
        else if(choice == two)
        {
            loss_ = true;
            profit_ = false;
        }
        else if(choice == three)
        {
            profit_ = true;
            loss_ = true;
        }
        else if(choice == four)
        {
            profit_ = false;
            loss_ = false;
            rr_choosen = true;
        }
        else if(choice == five)
        {
            system("pause");
        }
        else
        {
            cout<<"Invalid option, try again.\n";
            system("pause");
            compute_profit_loss();
        }

        if(rr_choosen == true)
        {
            clearBuffer();

            capture_method == "By RR";

            cout<<"\nAccount Balance: "<<account_balance<<"\n";
            cout<<"Enter risk(in % (0-100) of your account balance("<<account_balance<<")):";

            while(out_of_range == true)
            {
                cin>>risk;
                Sleep(2000);
                cout<<"\nAmount in risk: "<<((risk/100)*account_balance)<<"\n";
                Sleep(2000);
                if(risk>=0 && risk<=100)
                {
                    if(((risk/100)*account_balance)>((recommended_risk/100)*account_balance))
                    {
                        cout<<"**EA: Warning ! More than 2% of your account is at risk.\n\n";
                        Sleep(2000);
                        out_of_range = false;
                    }
                    else
                    {
                        out_of_range = false;
                    }
                }
                else
                {
                    cout<<"Value out of range, try again.\n";
                    out_of_range = true;
                }
            }

            cout<<"Provide risk-reward ratio(eg.1 then 2, where 1 is risk and 2 is reward ,1:2)\n";

            cout<<"Enter risk: ";
            cin>>risk_ratio;
            cout<<"Enter reward: ";
            cin>>reward_ratio;

            ostringstream oss;
            oss << risk_ratio <<":"<<reward_ratio;
            risk_reward_ratio = oss.str();

            Sleep(1000);
            cout<<"\nRisk reward ratio in effect---->"<<risk_ratio<<":"<<reward_ratio<<"\n";
            Sleep(1000);

            cout << "Enter position/lot size: ";
            cin >> position_size;

            profit_ticks = reward_ratio*((risk/100)*account_balance)*100;
            loss_ticks= risk_ratio*((risk/100)*account_balance)*100;

            profit = position_size * profit_ticks;
            loss = position_size * loss_ticks;

            cout<<"\nInstrument: "<<capture_instrument<<"\n";
            cout<<"Profit: "<<profit<<"\n";
            cout<<"Loss: "<<loss<<"\n";
 
            system("pause");  
        }
        else
        {
            cout<<"\nChoose method\n";
            cout<<"<==AVAILABLE METHODS==>\n";
            cout<<"1.By price\n2.By Pips\n3.Back\n";
            cout<<"Select method: ";

            string method;
            cin>>method;

            if(method == one)
            {
                double no_of_profit_pips,no_of_loss_pips;
                double no_of_profit_ticks,no_of_loss_ticks;

                capture_method = "By price";

                if(profit_ == true && loss_ == true)
                {
                    cout<<"Enter market/open price: ";
                    cin>> market_price;

                    cout<<"Enter take profit price: ";
                    cin >>tp_price;
                    cout<<"Enter stop loss price: ";
                    cin>>sl_price;

                    cout<<"Enter lot size: ";
                    cin>>lot_size;

                    if(currency == true)
                    {
                        if(long_ == true)
                        {
                            profit_ticks = (usd_less/100)*((tp_price - market_price) / 0.00001);
                            loss_ticks = (usd_less/100)*((market_price - sl_price) /0.00001);

                            profit = profit_ticks*lot_size;
                            loss = loss_ticks*lot_size;
                        }
                        if(short_ == true)
                        {
                            profit_ticks = (usd_less/100)*((market_price - tp_price) / 0.00001);
                            loss_ticks = (usd_less/100)*((market_price + sl_price) /0.00001);
                            
                            profit = profit_ticks*lot_size;
                            loss = loss_ticks*lot_size;
                        }
                    }
                    else if(currency_2 == true)//OKAY
                    {
                        if(long_ == true)
                        {
                            profit_ticks = (jpy_less/100)*((tp_price - market_price) / 0.001);
                            loss_ticks = (jpy_less/100)*(market_price - sl_price) /0.001;

                            profit = profit_ticks*lot_size;
                            loss = loss_ticks*lot_size;
                        }
                        if(short_ == true)
                        {
                            profit_ticks = (jpy_less/100)*((market_price - tp_price) / 0.001);
                            loss_ticks = (jpy_less/100)*((market_price + sl_price) /0.001);

                            profit = profit_ticks*lot_size;
                            loss = loss_ticks*lot_size;
                        }
                    }
                    else if(currency_3 == true)
                    {
                        if(long_ == true)
                        {
                            profit_ticks = (cad_less/100)*((tp_price - market_price) / 0.00001);
                            loss_ticks = (cad_less/100)*((market_price - sl_price) /0.00001);

                            profit = profit_ticks*lot_size;
                            loss = loss_ticks*lot_size;
                        }
                        if(short_ == true)
                        {
                            profit_ticks = (cad_less/100)*((market_price - tp_price) / 0.00001);
                            loss_ticks = (cad_less/100)*((market_price + sl_price) /0.00001);

                            profit = profit_ticks*lot_size;
                            loss = loss_ticks*lot_size;
                        }
                    }
                    else if(metal == true)
                    {
                        if(long_ == true)
                        {
                            profit_ticks = (metal_less/100)*((tp_price - market_price) / 0.01);
                            loss_ticks = (metal_less/100)*((market_price - sl_price) /0.01);

                            profit = profit_ticks*lot_size;
                            loss = loss_ticks*lot_size;
                        }
                        if(short_ == true)
                        {
                            profit_ticks = (metal_less/100)*((market_price - tp_price) / 0.01);
                            loss_ticks = (metal_less/100)*((market_price + sl_price) /0.01);

                            profit = profit_ticks*lot_size;
                            loss = loss_ticks*lot_size;
                        }
                    }
                    else if(index == true)
                    {
                        if(long_ == true)
                        {
                            profit_ticks = (index_1_less/100)*((tp_price - market_price) / 1);
                            loss_ticks = (index_1_less/100)*((market_price - sl_price) /1);

                            profit = profit_ticks*lot_size;
                            loss = loss_ticks*lot_size;
                        }
                        if(short_ == true)
                        {
                            profit_ticks = (index_1_less/100)*((market_price - tp_price) / 1);
                            loss_ticks = (index_1_less/100)*((market_price + sl_price) /1);

                            profit = profit_ticks*lot_size;
                            loss = loss_ticks*lot_size;
                        }
                    }
                    else if(index_2 == true)
                    {
                        if(long_ == true)
                        {
                            profit_ticks = (index_2_less/100)*((tp_price - market_price) / 1);
                            loss_ticks = (index_2_less/100)*((market_price - sl_price) /1);

                            profit = profit_ticks*lot_size;
                            loss = loss_ticks*lot_size;
                        }
                        if(short_ == true)
                        {
                            profit_ticks = (index_2_less/100)*((market_price - tp_price) / 1);
                            loss_ticks = (index_2_less/100)*((market_price + sl_price) /1);

                            profit = profit_ticks*lot_size;
                            loss = loss_ticks*lot_size;
                        }
                    }
                    no_of_profit_pips = profit_ticks/10;
                    no_of_loss_pips = loss_ticks/10;
                    pip_value = (profit - lot_size) / no_of_profit_pips;

                    cout << "\nInstrument: " << captured_instrument << "\n\n";

                    cout << "Profit ticks: " << profit_ticks << "\n";
                    cout << "Loss ticks: " << loss_ticks << "\n\n";
                    
                    cout << "Profit pips: " << no_of_profit_pips << "\n";
                    cout << "Loss pips: " << no_of_loss_pips << "\n\n";

                    cout << "Pip value: " << pip_value << "\n";

                    cout << "Profit: " << profit << "\n";
                    cout << "Loss: " <<loss<< "\n";

                    system("pause");
                }
                else if(profit_ == true || loss_ == true)
                {
                    cout << "Enter market/open price: ";
                    cin >> market_price;

                    cout << "Enter closing price: ";
                    cin >> close_price;

                    cout << "Enter lot/position size: ";
                    cin >> lot_size;
                
                    if(currency == true)
                    {
                        if(long_ ==true)
                        {
                            number_of_ticks = ((usd_less/100)*(close_price - market_price)) / 0.00001;
                            profit = number_of_ticks * lot_size;
                        }
                        if(short_ == true)
                        {
                            number_of_ticks = ((usd_less/100)*((close_price - market_price) * -1)) / 0.00001;
                            profit = number_of_ticks * lot_size;
                        }
                    }
                    else if(currency_2 == true)
                    {
                        if(long_ ==true)
                        {
                            number_of_ticks = ((jpy_less/100)*((close_price - market_price))) / 0.001;
                            profit = number_of_ticks * lot_size;
                        }
                        if(short_ == true)
                        {
                            number_of_ticks = ((jpy_less/100)*(((close_price - market_price) * -1))) / 0.001;
                            profit = number_of_ticks * lot_size;
                        }
                    }
                    else if(currency_3 == true)
                    {
                        if(long_ ==true)
                        {
                            number_of_ticks = ((cad_less/100)*((close_price - market_price))) / 0.00001;
                            profit = number_of_ticks * lot_size;
                        }
                        if(short_ == true)
                        {
                            number_of_ticks = ((cad_less/100)*(((close_price - market_price) * -1))) / 0.00001;
                            profit = number_of_ticks * lot_size;
                        }
                    }
                    else if(metal == true)
                    {
                        if(long_ ==true)
                        {
                            number_of_ticks = ((metal_less/100)*((close_price - market_price))) / 0.01;
                            profit = number_of_ticks * lot_size;
                        }
                        if(short_ == true)
                        {
                            number_of_ticks = ((metal_less/100)*(((close_price - market_price) * -1))) / 0.01;
                            profit = number_of_ticks * lot_size;
                        }
                    }
                    else if(index == true)
                    {
                        if(long_ ==true)
                        {
                            number_of_ticks = ((index_1_less/100)*((close_price - market_price))) / 1;
                            profit = number_of_ticks * lot_size;
                        }
                        if(short_ == true)
                        {
                            number_of_ticks = ((index_1_less/100)*(((close_price - market_price) * -1))) / 1;
                            profit = number_of_ticks * lot_size;
                        }
                    }
                    else if(index_2 == true)
                    {
                        if(long_ ==true)
                        {
                            number_of_ticks = ((index_2_less/100)*((close_price - market_price))) / 1;
                            profit = number_of_ticks * lot_size;
                        }
                        if(short_ == true)
                        {
                            number_of_ticks = ((index_2_less/100)*(((close_price - market_price) * -1))) / 1;
                            profit = number_of_ticks * lot_size;
                        }
                    }
                    number_of_pips = number_of_ticks / 10;
                    pip_value = (profit - lot_size) / number_of_pips;

                    cout << "\nInstrument: " << captured_instrument << "\n";
                    cout << "Ticks: " << number_of_ticks << "\n";
                    cout << "Pips: " << number_of_pips << "\n";
                    cout << "Pip value: " << pip_value << "\n";
                    cout << "Profit/Loss: " << profit << "\n";
                }
                system("pause");
            }
            else if(method == two)
            {
                clearBuffer();

                capture_method = "By pips";

                if(profit_ == true && loss_ == true)//Confirm
                {
                    cout<<"Enter take profit pips: ";
                    cin >>tp_pips;
                    cout<<"Enter stop loss pips: ";
                    cin>>sl_pips;

                    cout<<"Enter lot size: ";
                    cin>>lot_size;

                    if(currency == true)
                    {
                        tp_pips = tp_pips * (usd_less/100);
                        sl_pips = sl_pips * (usd_less/100);

                        profit_ticks = tp_pips * 10;
                        loss_ticks = sl_pips * 10;

                        profit = profit_ticks * lot_size;   
                        loss = loss_ticks * lot_size;
                    }
                    else if(currency_2 == true)
                    {
                        tp_pips = tp_pips * (jpy_less/100);
                        sl_pips = sl_pips * (jpy_less/100);

                        profit_ticks = tp_pips * 10;
                        loss_ticks = sl_pips * 10;
                        
                        profit = profit_ticks * lot_size;   
                        loss = loss_ticks * lot_size;
                    }
                    else if(currency_3 == true)
                    {
                        tp_pips = tp_pips * (cad_less/100);
                        sl_pips = sl_pips * (cad_less/100);

                        profit_ticks = tp_pips * 10;
                        loss_ticks = sl_pips * 10;

                        profit = profit_ticks * lot_size;   
                        loss = loss_ticks * lot_size;
                    }
                    else if(metal == true)
                    {
                        tp_pips = tp_pips * (metal_less/100);
                        sl_pips = sl_pips * (metal_less/100);

                        profit_ticks = tp_pips * 10;
                        loss_ticks = sl_pips * 10;

                        profit = profit_ticks * lot_size;   
                        loss = loss_ticks * lot_size;
                    }
                    else if(index == true)
                    {
                        tp_pips = tp_pips * (index_1_less/100);
                        sl_pips = sl_pips * (index_1_less/100);

                        profit_ticks = tp_pips * 10;
                        loss_ticks = sl_pips * 10;

                        profit = profit_ticks * lot_size;   
                        loss = loss_ticks * lot_size;
                    }
                    else if(index_2 == true)
                    {
                        tp_pips = tp_pips * (index_2_less/100);
                        sl_pips = sl_pips * (index_2_less/100);

                        profit_ticks = tp_pips * 10;
                        loss_ticks = sl_pips * 10;

                        profit = profit_ticks * lot_size;   
                        loss = loss_ticks * lot_size;
                    }

                    cout << "\nInstrument: " << captured_instrument << "\n\n";
                    cout << "Profit: "<<profit<<"\n";
                    cout << "Loss: "<<loss<<"\n\n";
                    
                    system("pause");
                }
                else if(profit_ == true || loss_ == true)//Confirm
                {
                    double pips,pips_ticks,outcome;

                    cout << "Enter pips: ";
                    cin >> pips;

                    cout<<"Enter lot size: ";
                    cin>>lot_size;

                    if(currency == true)
                    {
                        pips = pips * (usd_less/100);
                        pips_ticks = pips* 10;

                        outcome = lot_size * pips_ticks;
                    }
                    else if(currency_2 == true)
                    {
                        pips = pips * (jpy_less/100);
                        pips_ticks = pips* 10;

                        outcome = lot_size * pips_ticks;
                    }
                    else if(currency_3 == true)
                    {
                        pips = pips * (cad_less/100);
                        pips_ticks = pips* 10;

                        outcome = lot_size * pips_ticks;
                    }
                    else if(metal == true)
                    {
                        pips = pips * (metal_less/100);
                        pips_ticks = pips* 10;

                        outcome = lot_size * pips_ticks;
                    }
                    else if(index == true)
                    {
                        pips = pips * (index_1_less/100);
                        pips_ticks = pips* 10;

                        outcome = lot_size * pips_ticks;
                    }
                    else if(index_2 == true)
                    {
                        pips = pips * (index_2_less/100);
                        pips_ticks = pips* 10;

                        outcome = lot_size * pips_ticks;
                    }

                    cout << "\nInstrument: " << captured_instrument << "\n";
                    cout << "Profit/Loss: "<<outcome<<"\n";

                    system("pause");

                }
            }
            else if(method == three)
            {
                system("pause");
            }
            else
            {
                cout<<"Invalid option, try again.\n";
                system("pause");
            }
            method = default_;
        }
    }

    void compute_pips()
    {
        clearBuffer();

        cout<<"\nChoose method\n";
        cout<<"<==AVAILABLE METHODS==>\n";
        cout<<"1.By price\n2.By Profit/Loss\n3.Back\n";
        cout<<"Select method: ";

        string method;
        cin>>method;

        if(method == one)
        {
            capture_method = "By Price";

            cout << "Enter market/open price: ";
            cin >> market_price;
            cout << "Enter close price: ";
            cin >> close_price;

            if(currency == true)
            {
                if (long_ == true)
                {
                    number_of_ticks = ((usd_less/100)*(close_price - market_price)) / 0.00001;
                }
                if (short_ == true)
                {
                    number_of_ticks = ((usd_less/100)*((close_price - market_price) * -1)) / 0.00001;
                }
            }
            else if(currency_2 == true)
            {
                if (long_ == true)
                {
                    number_of_ticks = ((jpy_less/100)*((close_price - market_price))) / 0.001;
                }
                if (short_ == true)
                {
                    number_of_ticks = ((jpy_less/100)*(((close_price - market_price) * -1))) / 0.001;
                }
            }
            else if(currency_3 == true)
            {
                if (long_ == true)
                {
                    number_of_ticks = ((cad_less/100)*((close_price - market_price))) / 0.00001;
                }
                if (short_ == true)
                {
                    number_of_ticks = ((cad_less/100)*(((close_price - market_price) * -1))) / 0.00001;
                }
            }
            else if(metal == true)
            {
                if (long_ == true)
                {
                    number_of_ticks = ((metal_less/100)*((close_price - market_price))) / 0.01;
                }
                if (short_ == true)
                {
                    number_of_ticks = ((metal_less/100)*(((close_price - market_price) * -1))) / 0.01;
                }
            }
            else if(index == true)
            {
                if (long_ == true)
                {
                    number_of_ticks = ((index_1_less/100)*((close_price - market_price))) / 0.0001;
                }
                if (short_ == true)
                {
                    number_of_ticks = ((index_1_less/100)*(((close_price - market_price) * -1))) / 0.0001;
                }
            }
            else if(index_2 == true)
            {
                if (long_ == true)
                {
                    number_of_ticks = ((index_2_less/100)*((close_price - market_price))) / 0.01;
                }
                if (short_ == true)
                {
                    number_of_ticks = ((index_2_less/100)*(((close_price - market_price) * -1))) / 0.01;
                }
            }
    
        number_of_pips = number_of_ticks / 10;

        cout << "\nInstrument: " << captured_instrument << "\n";
        cout << "Ticks: " << number_of_ticks << "\n";
        cout << "Pips: " << number_of_pips << "\n";

        system("pause");

        }
        else if(method == two)
        {
            capture_method = "By Profit/Loss";

            cout<<"Enter profit/loss: ";
            cin >> profit;

            number_of_ticks = profit*100;
            number_of_pips = number_of_ticks/10;

            if(currency == true || currency_2 == true || currency_3 == true || metal == true)
            {
                number_of_ticks = profit*100;
                number_of_pips = number_of_ticks/10;
            }
            else if(index == true)
            {
                number_of_ticks = profit*100;
                number_of_pips = number_of_ticks/10;
            }
            else if(index_2 == true)
            {
                number_of_ticks = profit*1000;
                number_of_pips = number_of_ticks/10;
            }

            cout << "\nInstrument: " << captured_instrument << "\n";
            cout << "Ticks: " << number_of_ticks << "\n";
            cout << "Pips: " << number_of_pips << "\n";

            system("pause");
        }
        else if(method == three)
        {
            system("pause");
        }
        else
        {
            cout<<"Invalid option, try again.\n";
            system("pause");
        }
    }

    void expert_advisor()
    {

    }
};

//FUNCTION DECLARATION POINT
void login();
void menu();
void help_section();
void configuration();
void clearBuffer();
void correlation_advisor();
void simulateBootProcess();
void delay(int milliseconds);
void save_profits();
void save_target_prices();
void save_pips();
void read_profits();
void read_target_prices();
void read_pips();
void read_time();
void select_database();
void settings();
bool isInternetConnected();

void clearBuffer() 
{
    cin.clear(); 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cout.flush(); 
}

void delay(int milliseconds)
{
    clock_t start = clock();

    double duration = static_cast<double>(milliseconds) / (CLOCKS_PER_SEC / 1000);
    double endTime = start + duration;

    while (clock() < endTime){}
}

void configuration()
{
    bool opened;

    ifstream configFile("config.ini");
    
    if (!configFile.is_open()) 
    {
        cerr << "Error: Cannot open config.ini file, check to see if its in same directory as the app" << "\n";
        Sleep(4000);

        opened = false;
    }
    else
    {
        opened = true;
    }


    if(opened == true)
    {
        string line;

        while (getline(configFile, line)) 
        {
            if (line.find("COLOR") != string::npos) 
            {
                size_t pos = line.find("=");
                if (pos != string::npos) 
                {
                    color = line.substr(pos + 2); // +2 to skip '=' and space
                }
            }
            else if (line.find("CURRENCY") != string::npos) 
            {
                size_t pos = line.find("=");
                if (pos != string::npos) 
                {
                    user_currency = line.substr(pos + 2); // +2 to skip '=' and space
                }
            } 
        }
        configFile.close();

        // Change text color based on configuration
        if (color == "BLACK") 
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
        } 
        else if (color == "BLUE") 
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
        } 
        else if (color == "GREEN") 
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
        } 
        else if (color == "CYAN") 
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE);
        } 
        else if (color == "RED") 
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
        } 
        else if (color == "MAGENTA") 
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE);
        } 
        else if (color == "BROWN") 
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
        } 
        else if (color == "LIGHTGRAY") 
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        } 
        else if (color == "DARKGRAY") 
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
        } 
        else if (color == "LIGHTBLUE") 
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
        } 
        else if (color == "LIGHTGREEN") 
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
        } 
        else if (color == "LIGHTCYAN") 
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
        } 
        else if (color == "LIGHTRED") 
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        } 
        else if (color == "LIGHTMAGENTA") 
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
        } 
        else if (color == "YELLOW") 
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
        } 
        else if (color == "WHITE") 
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        } 
        else 
        {
            cerr << "Error: Invalid color specified in config.ini." << "\n";
        }
    }
    else
    {
        system("cls");
        cout<<"\nFATAL ERROR\n";
        system("pause");
        exit(1);
    }
}

int main()
{
    system("cls");

    configuration();

    cout << "**********" << "          *************" << "\n";
    cout << "***********" << "        **************" << "\n";
    cout << "**      ***" << "        ****" << "\n";
    cout << "**      **" << "         ****" << "\n";
    cout << "**********" << "         **************" << "\n";
    cout << "**********" << "         ***************" << "\n";
    cout << "***     ***" << "            " <<"       ****"<< "\n";
    cout << "***     ***" << "            " <<"       ****"<< "\n";
    cout << "***     ***" << "        **************" << "\n";
    cout << "***     ***" << "        *************" << "\n";

    Sleep(2000);

    simulateBootProcess();

    system("cls");
    cout <<"|<======RISK SENTINEL RISK MANAGEMENT APPLICATION=====>|\n\n\n\n";
    cout<<"DESCRIPTION\n";
    cout<<"______________________________________________________________________________\n";
    cout<<"THIS SOFTWARE IS DESIGNED TO HELP YOU MANAGE YOUR RISK AND ADVISE ON THE SAME.\n";
    cout<<"______________________________________________________________________________\n";
    Sleep(2000);
    cout << "Trading Disclaimer Warning:\n\n"
              << "Risk Sentinel provides risk management advice for trading forex, crypto, indices, futures, and CFDs; however, it is not financial guidance.\n"
              << "While it offers insights into market trends and historical data, trading carries inherent risks of gains and losses.\n"
              << "Use Risk Sentinel to inform your decisions, but remember to prioritize thorough research and consultation with professionals if uncertainty arises.\n"
              << "We emphasize responsible trading aligned with your risk tolerance and goals.\n"
              << "Be vigilant about potential outcomes, as success relies on well-informed choices.\n"
              << "Risk Sentinel complements but does not substitute comprehensive research for trading.\n"
              << "HAPPY TRADING !! \n";
    system("pause");
    login();
}

bool isInternetConnected() {
    int exitCode = system("curl --silent --head https://www.google.com/ --max-time 5 > nul 2>&1");
    return exitCode == 0;
}

void simulateBootProcess()
{
    system("cls");

    delay(2000);
    cout<<"RISK SENTINEL_v1.0.1          SYSTEM ONLINE         PlEASE WAIT...\n\n";
    delay(2000);
    cout<<"Property of MAJORIS ENTERPRISE\n";
    delay(2000);
    cout<<"Designed and Developed by Anderson\n";
    delay(2000);
    cout<<"COPYRIGHT 2023 \n";
    delay(2000);
    cout<<"ALL RIGHTS RESERVED\n";
    delay(2000);
    cout<<"Website: https://risksentinel.rf.gd\n\n";
    delay(4000);

    const int delayInSeconds = 1;
    const int totalIterations = 10;

    clock_t start = clock();
    double duration;

    for (int i = 0; i < totalIterations; i++)
    {
        system("cls");
        cout << "Loading menus, please don't close the app..... " << (i * 10) << "% complete" <<"\n";

        // Delay loop
        while ((clock() - start) / static_cast<double>(CLOCKS_PER_SEC) < delayInSeconds)
        {
            // Do nothing
        }

        start = clock();
    }

    system("cls");

    delay(2000);
    cout<<"SYSTEM STARTUP COMPLETE\nWELCOME!\n";

    delay(3000);
}

void login()
{
    menu();
}
void menu()
{
    int option;

    system("cls");
    cout<<"Please provide your account balance to see how it would be affected in a live account.\n";
    system("pause");

    cout<<"Enter account balance: ";
    cin>>account_balance;

    capture_initial_account_balance = account_balance;

    bool open = true;

    while (open == true)
    {
        system("cls");
        
        cout<<"\n<==RISK SENTINEL==>\n";
        cout<<"Virtual Account Balance: "<< account_balance <<"\n";
        cout << "\n1.FX-CURRENCIES  (~USD)\n2.FX-CURRENCIES (~JPY)\n3.FX-CURRENCIES (~CAD)\n4.FX-METALS     (GOLD~)\n5.FX-INDICES   (USTEC)\n6.FX-INDICES   (US30)\n\n7.View Databases\n8.Help(internet connection required)\n9.Settings\n10.Quit\n";
        cout << "\nEnter option: ";

        string group;
        cin >> group;

        if (group == one)//currencies
        {
            currency = true; currency_2 = false; currency_3 = false; metal = false; index = false; index_2 = false;
        }
        else if(group == two)//currencies_2
        {
            currency_2 = true; currency = false; currency_3 = false; metal = false; index = false; index_2 = false;
        }
        else if(group == three)//currencies_3
        {
            currency_3 = true; currency_2 = false; currency = false; metal = false; index = false; index_2 = false;
        }
        else if(group == four)//metals
        {
            metal = true; currency_2 = false; currency_3 = false; currency = false; index = false; index_2 = false;
        }
        else if(group == five)//indices
        {
            index = true; currency_2 = false; currency_3 = false; metal = false; currency = false; index_2 = false;
        }
        else if(group == six)//indices_2
        {
            index_2 = true; currency_2 = false; currency_3 = false; metal = false; index = false; currency = false;
        }
        else if(group == seven)
        {
            select_database();
        }
        else if(group == eight)
        { 
            help_section();
        }
        else if(group == nine)
        {
            system("pause");
            settings();
            open = true;
        }
        else if(group == ten)
        { 
            system("pause");
            cout<<"**program terminated\n";
            open = false;
            exit(0);
        }
        else
        { 
            cout<<"Invalid option, try again \n";
            system("pause");
            open = true;
        }
        
        if(currency == true || currency_2 == true || metal == true || index == true || index_2 ==true || currency_3 == true)
        {
            FX_INSTRUMENTS instrument;
            FX_INSTRUMENTS *ptr_instrument;

            ptr_instrument = &instrument;

            bool operate = true;

            while (operate == true)
            {
                system("cls");
                cout<<"\n"<<"Last pair loaded: "<<captured_instrument<<"\n";
                cout << "\n1.Calculate profit/Loss/Both\n2.Calculate target price(sl & tp)\n3.Calculate pips\n4.Back\n5.Reset instrument\n6.Quit\n\n";
                cout << "Choose option: ";
                cin >> option;

                switch (option)
                {
                case 1:
                    instrument.register_instrument();
                    instrument.register_trade_type();
                    instrument.compute_profit_loss();
                    save_profits();
                    operate = true;
                    break;
                case 2:
                    instrument.register_instrument();
                    instrument.register_trade_type();
                    instrument.compute_target_price();
                    save_target_prices();
                    operate = true;
                    break;
                case 3:
                    instrument.register_instrument();
                    instrument.register_trade_type();
                    instrument.compute_pips();
                    save_pips();
                    operate = true;
                    break;
                case 4:
                    system("pause");
                    operate = false;
                    break;
                case 5:
                    captured_instrument = "No instrument";
                    operate = true;
                    system("pause");
                    break;
                case 6:
                    system("pause");
                    system("cls");
                    operate = false;
                    open = false;
                    cout<<"**program terminated\n";
                    exit(0);
                    break;
                default:
                    cout << "Invalid choice, try again... \n";
                    operate = true;
                    break;
                }
                open = true;
            }
        }
        else
        {
            open = true;
        } 
    }  
}

void settings() //operate on global variables 
{
    bool settings_on = true;
    bool balance_changed = false;
    
    double initialise_acc_balance,previous_balance;

    string setting,choice;

    while(settings_on == true)
    {
        cout<<"\n<==SETTINGS==>\n";
        cout<<"1.View account balance.\n2.Change account balance\n3.Reset all variables\n4.Back \n";
        
        cout<<"\nEnter option: ";
        cin>>setting;

        if(setting == one)
        {
            cout<<"\nBalance: "<<account_balance<<"\n";
            settings_on= true;
        }
        else if(setting == two)
        {    
            while(balance_changed == false)
            {
                previous_balance = account_balance;

                cout<<"\nCurrent balance: "<<account_balance<<"\n";
                cout<<"\nEnter new balance: ";
                cin>>initialise_acc_balance;

                account_balance = initialise_acc_balance;

                Sleep(2000);

                if(account_balance != previous_balance && account_balance == initialise_acc_balance)
                {
                    cout<<"\nAccount balance changed succesfully\n";
                    balance_changed = true;
                    system("pause");
                }
                else if(initialise_acc_balance == previous_balance)
                {
                    cout<<"Your new balance cannot be the same as the old one, try again.\n";
                    balance_changed = false;
                    system("pause");
                }
                else
                {
                    cout<<"Failed to change balance, please try again.\n";
                    balance_changed = false;
                    system("pause");
                }
            }
            settings_on = true;
        }
        else if(setting == three)
        {
            string ch;

            cout<<"Do you really want to reset all variables ?(y/n)";
            cin>>ch;

            if(ch == "y" || ch == "Y" || ch == "yes" || ch == "Yes" || ch == "YES")
            {
                settings_on = true;
            }
            else if(ch == "n" || ch == "N" || ch == "no" || ch == "No" || ch == "NO")
            {
                settings_on = true;
            }
            else
            {
                cout<<"Invalid option, try aagin.\n";
                system("pause");
            }
        }
        else if(setting == four)
        {
            settings_on = false;
        }
        else
        {
            cout<<"Invalid option, try aagin.\n";
            settings_on = true;
            system("pause");
        }
    }
    system("pause");
}

void select_database()
{
    int x;
    bool read = true;

    while (read == true)
    {
        system("cls");

        string db;
        char dbs[3][25] = {"PROFITS DATABASE", "PRICE TARGETS DATABASE", "PIPS DATABASE"};

        cout << "<=====AVAILABLE DATABASE RECORDS=====>\n";
        cout << "(To apply formulas, open the documents manually)\n";
        cout << "_____________________________________________________\n";

        for (x = 0; x < 3; x++)
        {
            cout << x + 1 << "." << dbs[x] << "\n";
        }
        cout << x + 1 << "."<< "Back"<<"\n";
        cout << "_____________________________________________________\n";
        cout << "Select database(read-only): ";
        cin >> db;

        if(db == one) 
        {
            const char* filePath = "Databases/PROFITS.csv";
            const char* command = "start excel.exe /r \"%s\"";
            char cmd[256];

            snprintf(cmd, sizeof(cmd), command, filePath);

            int result = system(cmd);

            if (result == 0) 
            {
                cout << "Opened profits.csv in Excel." <<"\n";
                Sleep(2000);
            } 
            else 
            {
                cout << "Error opening profits.csv in Excel." <<"\n";
                Sleep(2000);
            }
        }
        else if(db == two) 
        {
            const char* filePath = "Databases/PRICE TARGETS.csv";
            const char* command = "start excel.exe /r \"%s\"";
            char cmd[256];

            snprintf(cmd, sizeof(cmd), command, filePath);

            int result = system(cmd);

            if(result == 0)
            {
                cout << "Opened target prices.csv in Excel." <<"\n";
                Sleep(2000);
            }
            else
            {
                cout << "Error opening targetprices.csv in Excel." <<"\n";
                Sleep(2000);
            }
        }
        else if(db == three) 
        {
            const char* filePath = "Databases/PIPS.csv";
            const char* command = "start excel.exe /r \"%s\"";
            char cmd[256];

            snprintf(cmd, sizeof(cmd), command, filePath);

            int result = system(cmd);

            if(result == 0) 
            {
                cout << "Opened PIPS.csv in Excel." <<"\n";
                Sleep(2000);
            } 
            else 
            {
                cout << "Error opening pips.csv in Excel." <<"\n";
                Sleep(2000);
            }
        }
        else
        {
            cout << "Invalid value of db." <<"\n";
        }
    }
}


void read_time()
{
    time_t now = time(0);

    date_time = ctime(&now);
}

void save_profits()
{
    ofstream open_PROFITS_CSV("Databases/PROFITS.csv", ios::app);

    if (open_PROFITS_CSV.is_open())
    {
        read_time();
        open_PROFITS_CSV << capture_group << "," << capture_instrument << "," << capture_trade_type << "," << capture_market_price << "," << capture_close_price << "," << capture_lot_size << "," << capture_number_of_ticks << "," << capture_number_of_pips << "," << capture_pip_value << "," << capture_profit << "," << date_time << "\n";
    }
    open_PROFITS_CSV.close();
}

void save_target_prices()
{
    ofstream open_PRICE_TARGETS_CSV("Databases/PRICE TARGETS.CSV", ios::app);

    if (open_PRICE_TARGETS_CSV.is_open())
    {
        read_time();
        open_PRICE_TARGETS_CSV << capture_group << "," << capture_instrument << "," << capture_trade_type << "," << capture_profit_amount << "," << capture_positon_size << "," << capture_market_price << "," << capture_target_price << "," << capture_profit_ticks << "," << capture_profit_amount << "," << date_time << "\n";
    }
    open_PRICE_TARGETS_CSV.close();
}

void save_pips()
{
    ofstream open_PIPS_CSV("Databases/PIPS.CSV", ios::app);

    if (open_PIPS_CSV.is_open())
    {
        read_time();
        open_PIPS_CSV << capture_group << "," << capture_instrument << "," << capture_trade_type << "," << capture_market_price << "," << capture_close_price << "," << capture_number_of_ticks << "," << capture_number_of_pips << "," << date_time << "\n";
    }
    open_PIPS_CSV.close();
}

void help_section()
{
    bool help_section_open = true;

    while(help_section_open == true)
    {
        system("cls");
    
        cout << "Hello, welcome to the help section!" << "\n";
        cout << "Menu" << "\n" << "___________________________________________\n";
        cout << "1. Get help with Navigation\n2. Get help with Calculations\n3. Get help with Database\n4. Others\n5. Back\n";
        cout << "____________________________________\n";
        cout << "Enter option: ";

        int option;
        cin >> option;

        map<int, const wchar_t*> optionLinks = {
            {1, L"https://www.youtube.com/playlist?list=PLakUjcfVUzng7L4tuTGKGVlRTSMS36-xD"},
            {2, L"https://www.youtube.com/playlist?list=PLakUjcfVUznjRPgcln7cQPA6HJos49ZJP"},
            {3, L"https://www.youtube.com/playlist?list=PLakUjcfVUznjOGCwThXI-YFLkq_KkXe55"},
            {4, L"https://www.youtube.com/playlist?list=PLakUjcfVUznjC0vqM2qZmltLRjUIDGx7k"}
        };

        auto it = optionLinks.find(option);
        if (it != optionLinks.end() && isInternetConnected()) 
        {
            HINSTANCE result = ShellExecuteW(NULL, L"open", it->second, NULL, NULL, SW_SHOWNORMAL);

            if ((int)result <= 32) 
            {
                cout << "Failed to open web browser.\n";
                system("pause");
            }
            else
            {
                Sleep(2000);
                help_section_open = true;
            }
        } 
        else if (option == 5) 
        {

            help_section_open = false;
        } 
        else if(option > 5 && option < 10000000)
        {
            cout<<"Invalid option, try again.\n";
            system("pause");
            help_section_open = true;
        }
        else
        {
            if(option == 1 || option == 2 || option == 3 || option == 4)
            {
                cout<<"No internet connection, try agin later\n";
                system("pause");
                help_section_open = true;
            }
            else
            {
                cout<<"Invalid option, try again.\n";
                system("pause");
                help_section_open = true;
            }
        }
    }
}  

//add expert advisors - 1 day

//add  affect account balance(viewing only)- 2 hrs

//saving - 2 hrs
