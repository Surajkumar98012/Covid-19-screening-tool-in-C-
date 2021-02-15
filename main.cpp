/*Student name:Gurmandeep Singh,
  Student id:100405318 */

#include <iostream>
#include <cmath>
#include <ctime>
#include <string.h>

using namespace std;
//here we make structure variable for containing areacode,exchangecode,linenumber
struct PhoneNumber{
    long int areaCode,exchangeCode,lineNumber;
    };
struct Date{
    int day,month,year;
};

int main()
{

    char menu_input;//Making variable to store first letter of menu option

    int temp1,temp2,temp3,temp4,digit5,digit3;

    std::string name;//Making variable for name
    int student_number;//Making variable for student number
    long int num,num1,num2,ticket_number;//Making variable for considering last two digit of student number and for phone number and date
    string answer;//Making variable for answer of question adopted from BC website

    //Ask the student to enter their full name and student number
    cout << "Please enter your Full Name:";
    std::getline(std::cin,name);//get full line with whitespace from user

    cout <<"Please enter your Student Number:";
    cin>>student_number;
    temp1=student_number/pow(10,4);//here we find 5th digit of student number
    temp2=(temp1/10)*10;
    digit5=temp1-temp2;
    temp3=student_number/pow(10,2);//here we find 3rd digit of student number
    temp4=(temp3/10)*10;
    digit3=temp3-temp4;

    num=student_number%100;//considering last 2 digit of student number
    num1=num+20;//adding 20 to last 2 digit of student number
    num2=num-9;//subtracting 9 from last 2 digit of number

    //Asking from student the following questions with Yes/No answers (questions are adopted from BC website https://bc.thrive.health/covid19/en)
    cout <<"\nFor the following questions answer Y(for yes) or N(for no)\n";
    cout <<"Are you or anyone in your household have traveled outside of Canada within the past 14 days?Or Have you had contact with any person with, or under investigation for, COVID-19 in the last 14 days?\n";
    cin >>answer;
    //Making Decision through if statement
    if(answer=="Y"){
        cout <<"We apologize,you are not allowed to enter the campus";
    }
    //if the answer is No the we ask some question for precaution
    if(answer=="N"){
        cout<<"Are you experiencing any of the following?\n";
        cout<<"   -Severe difficulty breathing (e.g. struggling to breathe or speaking in single words)\n";
        cout<<"   -Severe chest pain\n";
        cout<<"   -Having a very hard time waking up\n";
        cout<<"   -Feeling confused\n";
        cout<<"   -Losing consciousness\n";
        cin>>answer;
           //if the answer is given by user is yes then we display message of apology
           if(answer=="Y"){
           cout <<"We apologize,you are not allowed to enter the campus";
           }
           //if the answer is no the we ask some more question
           if(answer=="N"){
                cout<<"Are you experiencing any of the following?\n";
                cout<<"   -Mild to moderate shortness of breath\n";
                cout<<"   -Inability to lie down because of difficulty breathing\n";
                cout<<"   -Chronic health conditions that you are having difficulty managing because of difficulty breathing\n";
           }
           cin>>answer;
                //if the answer is Yes we give him instruction to follow
                if(answer=="Y"){
                    cout<<"Please call 911 or visit the nearest emergency department.";
                }
                //Here if the answer is no from user the we give him menu option to user
                if(answer=="N"){
                    cout<<"Welcome "<<name<< " to KPU, Please select where you want to go(enter the first letter of the option):\n";
                    cout<<"\nBookstores\n";
                    cout<<"It Helpdesk Services\n";
                    cout<<"Library\n";
                }
                cin>>menu_input;

                    switch(menu_input){
                      case 'b'://if the user select b for bookstores the we give output and generating code through ASCII notation
                      case 'B':
                          cout <<"Student Name          Student Number       Price        Access Code\n";
                          cout <<"############          ##############       #####        ###########\n";
                          if(num>=0 && num<=47){
                            cout<<name<<"       "<<student_number<<"           $89          K"<<digit3<<digit5<<endl;
                          }
                          else if((num>=48&&num<=57) || (num>=65&&num<=90)){
                            cout<<name<<"      "<<student_number<<"            $89          "<<(char)num<<digit3<<digit5<<endl;
                          }
                          else if(num>=58&&num<=64){
                            cout<<name<<"      "<<student_number<<"            $89          "<<(char)num1<<digit3<<digit5<<endl;
                          }
                          else if(num>=91&&num<=99)
                            cout<<name<<"      "<<student_number<<"            $89          "<<(char)num2<<digit3<<digit5<<endl;

                          break;
                      case 'i'://if the user type i for it helpdesk services we display this output given below
                      case 'I':
                          cout<<"Please Enter your ticket Number:";
                          cin>>ticket_number;
                          //Here we formatting phone no. with areaCode and exchangeCode through structure
                          cout<<"Please Enter your Phone Number with space(eg. 123 456 7890):";
                          PhoneNumber number;
                          cin>>number.areaCode>>number.exchangeCode>>number.lineNumber;

                          cout<<"*****************************************"<<ticket_number<<"******************************************************"<<endl;
                          cout<<name<<", you are in the line. A message will be sent to "<<number.areaCode<<"-"<<number.exchangeCode<<"-"<<number.lineNumber<<" to tell you when it is your turn."<<endl;
                          cout<<"*****************************************************************************************************";
                          break;
                      case 'l'://if the user type l for library the we display this output to user
                      case 'L':
                          cout<<"Please Enter today's date:\n";
                          Date currentDate;
                          cout<<"Day:";
                          cin>>currentDate.day;
                          cout<<"Month:";
                          cin>>currentDate.month;
                          cout<<"Year:";
                          cin>>currentDate.year;
                          if((currentDate.day>=0&&currentDate.day<=9)&&(currentDate.month>=0&&currentDate.month<=9)){
                          cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
                          cout<<"&                                                    &\n";
                          cout<<"&  XXXXXX    Kwantlen Polytechnic Uneversity         &\n";
                          cout<<"&  XXXXXX    Student Name   : "<<name<<"       &\n";
                          cout<<"&  XXXXXX    Student Number : "<<student_number<<"              &\n";
                          cout<<"&            Expires        : 0"<<currentDate.day<<"/0"<<currentDate.month<<"/"<<(currentDate.year)+4<<"             &\n";
                          cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
                          }
                          else if((currentDate.month>=10&&currentDate.day<=9)){
                          cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
                          cout<<"&                                                    &\n";
                          cout<<"&  XXXXXX    Kwantlen Polytechnic Uneversity         &\n";
                          cout<<"&  XXXXXX    Student Name   : "<<name<<"       &\n";
                          cout<<"&  XXXXXX    Student Number : "<<student_number<<"              &\n";
                          cout<<"&            Expires        : 0"<<currentDate.day<<"/"<<currentDate.month<<"/"<<(currentDate.year)+4<<"             &\n";
                          cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
                          }
                          else if((currentDate.month<=9&&currentDate.day>=10)){
                          cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
                          cout<<"&                                                    &\n";
                          cout<<"&  XXXXXX    Kwantlen Polytechnic Uneversity         &\n";
                          cout<<"&  XXXXXX    Student Name   : "<<name<<"       &\n";
                          cout<<"&  XXXXXX    Student Number : "<<student_number<<"              &\n";
                          cout<<"&            Expires        : "<<currentDate.day<<"/0"<<currentDate.month<<"/"<<(currentDate.year)+4<<"             &\n";
                          cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
                          }
                          else{
                             cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
                          cout<<"&                                                    &\n";
                          cout<<"&  XXXXXX    Kwantlen Polytechnic Uneversity         &\n";
                          cout<<"&  XXXXXX    Student Name   : "<<name<<"       &\n";
                          cout<<"&  XXXXXX    Student Number : "<<student_number<<"              &\n";
                          cout<<"&            Expires        : "<<currentDate.day<<"/"<<currentDate.month<<"/"<<(currentDate.year)+4<<"             &\n";
                          cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
                          }

                          break;
                      default:
                          cout<<"you are not selecting right letter,please select from b,i,l";
                          break;

                    }
    }
    return 0;
}
