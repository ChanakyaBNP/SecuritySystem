#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    int a, i = 0;
    string text, old, password1, password2,pass,name,password0, age, user, word, word1;
    string creds[2], cp[2];
    cout<<endl<<endl;
    cout<<"\t=================================="<<endl;
    cout<<"\t----------Security System---------"<< endl;
    cout<<"\t=================================="<< endl<< endl<<endl;
    cout<<"\tSelect your own Choice."<<endl<<endl;
    cout<<"\t----------1. REGISTER-------------"<< endl;
    cout<<"\t----------2. Log In  -------------"<< endl;
    cout<<"\t----------3. Change Password------"<< endl;
    cout<<"\t----------4. End Program----------"<< endl<< endl<<endl;
    do
    {
        cout << endl<< endl;
        cout <<"\tEnter your Choice(1-4):- ";
        cin >> a;
        switch(a)
        {
            case 1:
                  {
                    cout<<"\t=================================="<<endl;
                    cout<<"\t-----------1. Register------------"<< endl;
                    cout<<"\t=================================="<< endl<< endl;
                    cout<<"\t--Please Enter USER NAME :- ";
                    cin>>name;
                    cout<<"\t--Please Enter Your Password :- ";
                    cin>>password0;
                    cout<<"\t--Please Enter Your Age :- ";
                    cin>>age;

                    ofstream of1;
                    of1.open("file.txt");
                    if(of1.is_open())
                    {
                        of1<<name<<"\n";
                        of1<<password0;
                        cout<<endl;
                        cout<<"\t---**Registration Successfull!**---"<<endl;
                    }


                  break;
                
                  }
            case 2:
                  {
                    i=0;
                    cout<<"\t=================================="<<endl;
                    cout<<"\t------------2. Log In-------------"<< endl;
                    cout<<"\t=================================="<< endl<< endl;

                    ifstream of2;
                    of2.open("file.txt");
                    cout<<"\t--Please Enter the USER NAME :- ";
                    cin>>user;
                    cout<<"\t--Please Enter the Password :- ";
                    cin>>pass;

                    if(of2.is_open())
                    {
                        while(!of2.eof())
                        {
                            while(getline(of2,text))
                            {
                                istringstream iss(text);
                                iss>>word;
                                creds[i]=word;
                                i++;
                            }
                            if(user==creds[0] && pass==creds[1])

                            {
                                cout<<endl;
                                cout<<"\t----**Log In Successfully!**----"<<endl<<endl;

                                cout<<"\t<-<-<-<-<-<-Details:>->->->->->-"<<endl;
                                cout<<endl;
                                cout<<"\t--Username:- "+ name<<endl;
                                cout<<"\t--Password:- "+ pass<<endl;
                                cout<<"\t--Age:- "+ age<<endl;

                            }
                            else{
                                cout<<endl<<endl;
                                cout<<"\t********Incorrect Crediantials*********"<<endl;
                                cout<<"\t     1. Press 2 to LogIn               "<<endl;
                                cout<<"\t     2. Press 3 to Change Password     "<<endl;
                                break;
                            }
                        }
                    }
                    break;
                  }


            case 3:
                  {
                      
                      i=0;
                      cout<<"\t====================================="<<endl;
                      cout<<"\t----------2. Change Password---------"<< endl;
                      cout<<"\t====================================="<< endl<< endl;
                      ifstream of0;
                      of0.open("file.txt");
                      cout<<"\t-->Enter the old password:- ";
                      cin>>old;
                      if(of0.is_open())
                      {
                        while(of0.eof())
                        {
                            while(getline(of0,text)){
                                istringstream iss(text);
                                iss>>word;
                                cp[i]=word;
                                i++;
                            }
                            if(old==cp[1])
                            {
                                of0.close();
                                 ofstream of1;
                                 if(of1.is_open())
                                 {
                                    cout<<"\t-->Enter Your New Password :- ";
                                    cin>>password1;
                                    cout<<"\t-->Enter Your Password Again :- ";
                                    cin>>password2;

                                    if(password1==password2)
                                    {
                                        of1<<cp[0]<<" \n";
                                        of1<<password1;
                                        cout<<"\t----**Password Change Successfully!**----"<<endl<<endl;
                                    }
                                    else{
                                        of1<<cp[0]<<"\n";
                                        of1<<old;
                                        cout<<"\t*********Password Do Not Match***********"<<endl;
                                    }

                                 }
                            }
                            else{
                                        cout<<"\t----===Please Enter Valid Password.===----"<<endl;
                                break;
                            }
                        }
                      }
                      break;
                  }    


            case 4:
                  {
                    cout<<endl<<endl;
                    cout<<"\t-------******ThankYou!******-------"<<endl<<endl;
                    break;
                  } 
            default:
                    cout<<"\t--****Enter your valid choice****--"<<endl;             

        }
    } 
    while (a!=4);
    return 0;
}