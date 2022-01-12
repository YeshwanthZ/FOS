#include<iostream>
using namespace std;
int main()
{
cout<<"Welcome to the All-Space app"<<endl;
cout<<"Create your account to continue"<<endl;
cout<<"Let's start with your user name: "<<endl;
string user,pass;
int user_food_units[5],j; //Number of units of each food ordered
for(j=0;j<5;j++)
{
   user_food_units[j]=0;
}
while(1){ //Check length of user name
getline(cin,user);
if(user.length()>=6)
{
   break;
}
else{
   cout<<"Username should be at least 6 characters in length"<<endl;
}
}
cout<<"Enter a password: "<<endl; //user registration

while(1){ //Check length of password
getline(cin,pass);
if(pass.length()>=8)
{
   cout<<"Thank You for registering!"<<endl;break;
}
else{
   cout<<"Password should be at least 8 characters in length"<<endl;
}
}

cout<<"\nLogin again to order"<<endl;
while(1){ //Check valid user name
cout<<"Username: ";
string username;
getline(cin,username);
if(username!=user)   //(username!=user)||password!=pass) use this statement to combine the user name and password modules
{
   cout<<"Username is invalid. Please re-enter"<<endl; //If stored username doesn't match then re-enter prompt
}
else
{
   break;
}
}

while(1) //Check correct password
{
cout<<"Password: ";
string password;
getline(cin,password);
if(password!=pass)
{
   cout<<"Password is invalid. Please re-enter"<<endl; //If stored password doesn't match then re-enter prompt
}
else{
   break;
}
} //You can also customize the module by giving a limit on the number of attempts

cout<<"\nWelcome to the All-Space app!"<<endl;
double balance=100.00;
cout<<"Your wallet balance is $"<<balance<<endl;
cout<<"Would you like to add money to your wallet?(Yes/No)"<<endl;
string option;
getline(cin,option);
double addmoney;
if((option=="yes") || (option=="Yes") || (option=="YES"))
{
   cout<<"Enter how much money you want to add: $";
   cin>>addmoney;
   balance+=addmoney;
   cout<<"Your balance has been updated\nBalance = $"<<balance<<endl;//Add balance
}
else
{
   cout<<"Your balance remains $"<<balance<<endl;
}
string order_interest;
cout<<"Would you like to order?(Yes/No)"<<endl;
cin>>order_interest;
int i;

if((order_interest=="yes") || (order_interest=="Yes") || (order_interest=="YES"))
{
   cout<<"Select what you like to order"<<endl;
   string items[]={"Burger-Combo","Pizza-Lunch-Combo","Burrito-pack","Spring-Roll","choco-lava cake"};
   double items_prices[]={55.00,68.75,30.50,45.75,50.00};
      cout<<"    Item            Price\n";
   for(i=0;i<5;i++)
   {
      cout<<i+1<<". "<<items[i]<<"---------"<<"$"<<items_prices[i]<<endl;
   }
   cout<<"Which one do you choose?\n";
   int choices;
   string exit_choice;
   double total_bill=0;
while(1){
      cin>>choices;
   switch(choices)
   {
      case 1:
          cout<<items[choices-1]<<" has been added to cart\n"; //[choices-1] since array indexing is form 0
          total_bill+=items_prices[choices-1]; //update total_bill
          user_food_units[choices-1]++;
          break;
      case 2:
          cout<<items[choices-1]<<" has been added to cart\n";
          total_bill+=items_prices[choices-1];//update total_bill
          user_food_units[choices-1]++;
          break;
      case 3:
          cout<<items[choices-1]<<" has been added to cart\n";
          total_bill+=items_prices[choices-1];//update total_bill
          user_food_units[choices-1]++;
          break;
      case 4:
           cout<<items[choices-1]<<" has been added to cart\n";
           total_bill+=items_prices[choices-1];//update total_bill
           user_food_units[choices-1]++;
           break;
      case 5:
           cout<<items[choices-1]<<" has been added to cart\n";
           total_bill+=items_prices[choices-1];//update total_bill
           user_food_units[choices-1]++;
           break;
      default: cout<<"Invalid choice! Please try again\n";break;
   }
   if(total_bill*1.1>balance) //Balance is not sufficient so reset the total_bill to 0
   {
      total_bill=0;
      cout<<"The total amount is subject to tax. You may have in-sufficient balance."<<endl;
      cout<<"Would you like to add balance and continue?(Yes/No)"<<endl;
      cin>>option;
      if((option=="yes") || (option=="Yes") || (option=="YES"))
     {
        cout<<"How much would you like to add?"<<endl;
        cin>>addmoney;
        balance+=addmoney;
        cout<<"Added successfully! Updated balance = $"<<balance<<"\nFill your cart again to continue"<<endl;
      }
      else
         {
          cout<<"Looking forward to see you again! Have a good day."<<endl;
          break;
         }
         }
   else if(total_bill!=0)
   {
       int checkout_choice;
       cout<<"Proceed to checkout? \n(Yes then enter 1/No then enter 0)\n";
       cin>>checkout_choice;
       if(checkout_choice)
        {
           break;
         }
       else
       {
         cout<<"Very well! Continue adding....."<<total_bill<<endl;
       }
   }
}
cout<<"\n\nYour bill summary (inclusive of all taxes) is as follows:"<<endl;
for(i=0;i<5;i++)
{
   if(user_food_units[i])
   {
      cout<<items[i]<<"---"<<"units: "<<user_food_units[i]<<"---price: "<<user_food_units[i]*items_prices[i]<<endl;
   }
}
cout<<"Total: $"<<total_bill<<endl;
cout<<"Taxes: $"<<0.1*total_bill<<endl;
cout<<"Grand Total: $"<<1.1*total_bill<<endl; //Bill inclusive of taxes
balance-=1.1*total_bill;
cout<<"Updated balance: $"<<balance<<endl;
cout<<"\nThank You for considering our app! Have a good day.\n";
}
else
{
   cout<<"Looking forward to see you again! Have a good day."<<endl;
}
return 0;
}
