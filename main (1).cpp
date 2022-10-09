#include <iostream>
#include <cstring>
using namespace std;

class ATM
{
 private:
   char Account_name [100];
   char Card_num [21];
   float Amount;
  public:
   void create_new_acc();
   void Deposite ();
   void withdrawal();
   void Transfer (ATM a);
   void Print_acc_data();
   int areSame (char x[])
{
  char first = x[0];
  int i = 2;
  while (i < 10)
    if (x[2*i] == first)                 // (2*i) because there is space between digits
      i++;
    else return 1;
  if (i==10) return 0; }
   int check_num(char x []){   // check that each digit is from 0 to 9 and no characters is used.
       int y[10];
       for(int i=0;i<20;i++){
          if(!((x[i]>=48&&x[i]<=57)||(x[i]==32)||(x[i]==0)))
            return 0;}
           return 1;}
   int check_name(char x[]){      //check that name contains only letters
       for(int i=0;i<100;i++){
          if(!((Account_name[i]>=65&&Account_name[i]<=90)||(Account_name[i]>=97&&Account_name[i]<=122)||(Account_name[i]==32)||(Account_name[i]==0)))
            return 0;}
           return 1;}
   void enter_acc(){              //asks user to enter card number
       int l =0;
    while(l<10){
    cout <<"Please enter the account number separated by space"<< endl;
    cin.sync();                                        // to discard all what is left in the buffer.
    cin.getline(Card_num,21);
    int g=check_num(Card_num);
    int d = areSame (Card_num);      // make sure that the user doesn't have entered similar digits
    int lenght= strlen(Card_num);
    if (lenght <19) {
        cout<<"error! card number is less than 10 digits,try again"<<endl;
         l++;
         cin.clear();}
    else if(!cin){                            // to make sure that the user wouldn't enter a number that exceeds 10.
     cout<<"error! please don't exceed 10 digits,try again"<<endl;
         l++;
         cin.clear();}
     else if(!d) {
        cout<<"error! your card number is easy to guess,try to enter different digits"<<endl;
     l++;
     cin.clear();}
      else if(!g) {
        cout<<"error!please let each digit to be less than 10 and don't use characters,try again"<<endl;
     l++;
     cin.clear();}
     else break;
     }}

   int searching(char k[10])      //to make sure that the card_num doesn't already exist
   { int i=0;
     while(i<10){
    if ( Card_num[i]==k[i] )
          i++;
    else  return 0;}
    if(i==10)   return 1;
        }
};
  void ATM :: create_new_acc()
  {
      Amount =0;
      int l=0;
   while(l<10){
   cout << "please enter the account name "<<endl;
   cin.sync();                                        // to discard all what is left in the buffer.
     cin.getline(Account_name,100);
     int g=check_name(Account_name);
     if(!cin){                            // to make sure that the user wouldn't enter a name that exceeds 100.
     cout<<"error! please don't exceed 100 letters,try again"<<endl;
         l++;
         cin.clear();}
     else if(!g) {
         cout<<"error! please enter letters only,try again"<<endl;
         l++;
         cin.clear();}
    else  break;}
    enter_acc();
    Print_acc_data();
   }
  void ATM :: Deposite ()
  {
       float num ; // the number to be deposited
      int l=0;
      while(l<10){
      cout <<"Please enter the amount to be deposited:"<<endl;
      cin.sync();
      cin >> num;
     if(cin.fail()){                       //check that the user hasn't entered any characters.
     cout<<"error!please enter only numbers,try again"<<endl;
         cin.clear();
         l++;}
         else break;}
      Amount = Amount + (1.01)*num ;
      Print_acc_data();
  }

   void ATM :: withdrawal()
   {
    float num;
     int l=0;
      while(l<10){
     cout <<"Please enter the amount to be withdrawn:"<<endl;
      cin.sync();
      cin >> num;
      if(cin.fail()){                       //check that the user hasn't entered any characters.
     cout<<"error!please enter only numbers,try again"<<endl;
         cin.clear();
         l++;}
         else break;}
      if(Amount<num)
        cout<<"error! the account does not have enough money "<<endl;
      else {
      Amount = Amount - (1.03*num);
      Print_acc_data();}
   }
   void ATM :: Transfer(ATM a)
   {
     float num;
      int l=0;
      while(l<10){
     cout <<"Please enter the amount to be transfered:"<<endl;
      cin.sync();
      cin >> num;
      if(cin.fail()){                       //check that the user hasn't entered any characters.
     cout<<"error!please enter only numbers,try again"<<endl;
         cin.clear();
         l++;}
         else break;}
      if(Amount<num)
        cout<<"error! the account does not have enough money "<<endl;
      else {
      Amount = Amount - (1.015*num);
      a.Amount = a.Amount + num - (0.015*num);
      Print_acc_data();
        cout<<endl;
        a.Print_acc_data();}
    }

   void ATM :: Print_acc_data()
   {
 cout<<"account name: "<< Account_name<<endl;
 cout<<"card number: "<< Card_num<<endl;
 cout<<"amount: "<< Amount <<endl;
 }
int main()
{   int n ;
int i = 0;
int c,f;
int found = 0;
char Card_num[20];
ATM acc[100];
        for(int m=0;m<100;m++)
   {
     cout << " 1----Create new account " << endl;
     cout << " 2----Deposit " << endl;
     cout << " 3----transfer to another account " << endl;
     cout << " 4----withdrawal " << endl;
     cout << " 5----main menu " << endl;
     cout << " 6----exit "   << endl;
int l =0;
while(l<10){
   cout <<" enter the num of req operation "<<endl ;
   cin.sync();
    cin>> n;
      if(cin.fail()){                       //check that the user hasn't entered any characters.
     cout<<"error!please enter only numbers,try again"<<endl;
         cin.clear();
         l++;}
         else break;}
    switch (n)
    {
    case (1) :
       {
        acc[i].create_new_acc();
        i++;
        break;}
    case (2) : { int r = 0;
    while(r<10){
         cout <<"Please enter the account number"<< endl;
         cin.ignore();
         cin.getline(Card_num,20);

        int k=0;
        while( k<100){
                found = acc[k].searching(Card_num);
                if (found) {
                    acc[k].Deposite();
                    break;
                    break;}
                 if (!found) k++;
            }
            if (!found)
                cout << "error! this card number doesn't exist,try again" << endl;
                r++;}
      break;}
    case(3): { int r = 0;
    while(r<10){
        cout<<"please enter the sending account card number"<<endl;
        cin.ignore();
       cin.getline(Card_num,20);
       int k=0;
        while( k<100){
                found = acc[k].searching(Card_num);
                if (found) {
                    c=k;
                    break;
                    break;}
                 if (!found) k++;
            }
            if (!found){
                cout << "error! this card number doesn't exist, try again" << endl;
                r++;}}
        int d= 0;
        while(d<10){
    cout<<"please enter the recieving account card number"<<endl;
       cin.ignore();
       cin.getline(Card_num,20);
       int i=0;
        while( i<100){
                found = acc[i].searching(Card_num);
                if (found) {
                    f=i;
                    break;
                    break;}
                 if (!found) i++;
            }
            if (!found){
                cout << "this card number doesn't exist" << endl;
                d++;}}
     acc[c].Transfer(acc[f]);
     break;}
    case(4): { int r = 0;
    while(r<10){
       cout <<"Please enter the account number"<< endl;
         cin.ignore();
       cin.getline(Card_num,20);
        int k=0;
        while( k<100){
                found = acc[k].searching(Card_num);
                if (found) {
                    acc[k].withdrawal();
                    break;
                    break;}
                 if (!found) k++;
            }
            if (!found)
                cout << "this card number doesn't exist" << endl;
                r++;}
        break;}
        case (5): {
        }
     case (6):
          {   cout << " 1----Create new account " << endl;
              cout << " 2----Deposit " << endl;
              cout << " 3----transfer to another account " << endl;
              cout << " 4----withdrawal " << endl;
              cout << " 5----main menu " << endl;
              cout << " 6----exit "   << endl;
              return 0;
         break;}
     default : {
        cout << "Error!, the number of the required operator is not correct "<<endl;
        cout<<" please enter the correct number fro 1 to 5  "<<endl;}
    }}
    return 0;
}
