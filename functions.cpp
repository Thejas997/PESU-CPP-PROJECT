#include "header.h"
#include <iostream>

using namespace std;


payroll payrolls;
void payroll:: reduce_salary_type()
{
  int type,reduced_by;
  std::cout << "Enter for which type of employee you want to reduce :";
  std::cin >> type;
  std::cout << "By what amount you want to reduce :" ;
  std::cin >> reduced_by;

  salary_of_typedemployee[type] = salary_of_typedemployee[type] - reduced_by;
}

void payroll:: give_bonus_to_all()
{
  int bonus;
  std::cout << "Enter the amount you want to give as bonus :";
  std::cin >> bonus;
  for (int type = 0; type < types_of_employees; type++)
  {
      salary_of_typedemployee[type] = salary_of_typedemployee[type] + bonus;
  }
}

void payroll::give_bonus_onetype()
{
  int bonus,type;

  std::cout << "Enter the type of employee you want to give bonus :";
  std::cin >> type;
  std::cout << "Enter the amount you want to give as bonus :" ;
  std::cin >> bonus;

  salary_of_typedemployee[type] = salary_of_typedemployee[type]  + bonus;

}

void payroll:: increase_salary_by_percentage()
{
  int for_all;
  double percent;

  std::cout << "For which types_of_employees you want to increase(if all enter -1 else enter type) :";
  std::cin >> for_all;
  std::cout << "Enter the percentage of increase :";
  std::cin >> percent;

  if(for_all == -1)
  {
    for(int type = 0; type < types_of_employees ; type++)
    {
      salary_of_typedemployee[type] = salary_of_typedemployee[type]*( 1 + percent/100);
    }
  }else
  {
    salary_of_typedemployee[for_all] = salary_of_typedemployee[for_all]*( 1 + percent/100);
  }

  std::cout << "Successfull in incrementing the salary |" << '\n';
}

void payroll:: display()
{
  double total_spend_inyear = 0;
  std::cout << "............................................................." << '\n';
  std::cout << "Companys Bank Balance is $"<<total_amount_in_bank << '\n';
  std::cout << ".............................................................." << '\n';
  std::cout << "|    Type    |" << "|    Number Of Them    |"<<"|    Salary    |" << '\n';
  std::cout << "_________________________________________________________________" << '\n';
  for(int type = 0;type < types_of_employees;type++)
  {

    total_spend_inyear = total_spend_inyear + no_of_typedemployee[type]*salary_of_typedemployee[type];

    std::cout << "|     "<<type<<"      |"<<"|           "<<no_of_typedemployee[type]<<"          |"<<"|      "<<
    salary_of_typedemployee[type]<<"      |" << '\n';
  }

  std::cout << "..............................................................." << '\n';
  std::cout << "Company has to spend $"<<total_spend_inyear<<" in an year !" << '\n';
  std::cout << "..............................................................." << '\n';
}


void payroll:: paysalary()
{
  double total_spend_inyear = 0;
  for (int type = 0;type < types_of_employees ;type++)
  {
    total_spend_inyear = total_spend_inyear + no_of_typedemployee[type]*salary_of_typedemployee[type];
  }

  if(total_spend_inyear >= total_amount_in_bank)
  {
    std::cout << "Your company is not having enough money to pay all employees " << '\n';
  }else
  {
    total_amount_in_bank = total_amount_in_bank - total_spend_inyear;
    std::cout << "Task Success............................ " << '\n';
    if(total_spend_inyear >= total_amount_in_bank)
    {
      std::cout << "You dont have enough money to pay next year so increase you income or \n reduce some unwanted workers ..." << '\n';
    }
  }
}

void payroll:: add_employee_type()
{
  int c;
  std::cout << "Enter 1 if you want to add new type of employee lse enter 2 :";
  std::cin >> c;
  std::cout << "_________________________________________________________________" << '\n';
  if(c == 1)
  {
    int index = types_of_employees,type_num;
    double income;
    std::cout << "Enter the income which you want to give to a new type of employee : " ;
    std::cin >> income;
    salary_of_typedemployee[index] = income;
    std::cout << "Enter the number of employee of new type : ";
    std::cin >> type_num;
    no_of_typedemployee[index] = type_num;
    std::cout << "_________________________________________________________________" << '\n';
    std::cout << "Successfull in adding employee" << '\n';
    std::cout << "_________________________________________________________________" << '\n';
    types_of_employees++;
  }else if( c == 2)
  {
    int type,number;
    std::cout << "Enter the type of employee which you want to increase :";
    std::cin >> type;
    std::cout << "By what number of employee you  want to increase :";
    std::cin >> number;

    no_of_typedemployee[type] = no_of_typedemployee[type] + number ;

    std::cout << "_________________________________________________________________" << '\n';
    std::cout << "Successfull in adding employee" << '\n';
    std::cout << "_________________________________________________________________" << '\n';

  }

}

void payroll::  Delete_employee()
{
  int c;
  std::cout << "Enter 1 if you want to delete  type of employee else enter 2  :";
  std::cin >> c;
  std::cout << "_________________________________________________________________" << '\n';
  if(c == 1)
  {
    int type;
    std::cout << "Enter type of employee you want to delete :";
    std::cin >> type;

    no_of_typedemployee[type] = 0;
    salary_of_typedemployee[type] = 0;
    types_of_employees--;
    std::cout << "_________________________________________________________________" << '\n';
    std::cout << "Successfull in Deleting type employee" << '\n';
    std::cout << "_________________________________________________________________" << '\n';
  }
  else
  {
    int type,number;
    std::cout << "Enter the type of employee in which you want to remove employee :";
    std::cin >> type;
    std::cout << "Enter the number of employees you want to remove :";
    std::cin >> number;

    no_of_typedemployee[type] = no_of_typedemployee[type] - number;

    std::cout << "_________________________________________________________________" << '\n';
    std::cout << "Successfull in removing some employee" << '\n';
    std::cout << "_________________________________________________________________" << '\n';

  }

}
