#include<iostream>
#include<fstream>
#include "header.h"

using namespace std;

int main()
{
  int choice;
  payroll payrolls;
  int number;

  std::cout << "_________________________________________________________________" << '\n';
  std::cout << "Enter the initial investment in company : ";
  std::cin >> payrolls.total_amount_in_bank;
  std::cout << "_________________________________________________________________" << '\n';

  std::cout << "Enter the number of different type of employees you want : ";
  std::cin >> number;
  payrolls.types_of_employees = number;
  std::cout << "_________________________________________________________________" << '\n';

  for (int i = 0; i < number;i++)
  {
    std::cout << "Enter the number of type "<< i<<" employee  and their salary(space_seperated) : ";
    std::cin >> payrolls.no_of_typedemployee[i]>>payrolls.salary_of_typedemployee[i];
  }

  do
  {
    std::cout << "          MENU          " <<'\n';
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~" << '\n';
    std::cout << "1.Modify the salary of employees."  << '\n';
    std::cout << "2.List all the records " << '\n';
    std::cout << "3.Pay the salary" << '\n';
    std::cout << "4.Add employee type" << '\n';
    std::cout << "5.Delete employee type or reduce employee_of_type" << '\n';
    std::cout << "6.Exit" << '\n';
    std::cout << "_________________________________________________________________" << '\n';
    std::cout << "Enter your choice :";
    cin >> choice;
    std::cout << "_________________________________________________________________\n" << '\n';
    switch (choice)
    {
      case 1:
        int choose;
        std::cout << " OPTIONS YOU CAN DO " << '\n';
        std::cout << "~~~~~~~~~~~~~~~~~~~~" << '\n';
        std::cout << "1.Reduce_salary_for_one_type " << '\n';
        std::cout << "2.give_bonus_to_all" << '\n';
        std::cout << "3.give_bonus_onetype" << '\n';
        std::cout << "4.increase_salary_by_percentage" << '\n';
        std::cout << "_________________________________________________________________\n" << '\n';
        std::cout << "Enter your choice :";
        std::cin >> choose;
        std::cout << "_________________________________________________________________\n" << '\n';
        switch (choose)
        {
          case 1:
            payrolls.reduce_salary_type();
            break;
          case 2:
             payrolls.give_bonus_to_all();
             break;
          case 3:
            payrolls.give_bonus_onetype();
            break;
          case 4:
            payrolls.increase_salary_by_percentage();
            break;

        };
      break;
      case 2:
        payrolls.display();
        break;
      case 3:
        payrolls.paysalary();
        break;
      case 4:
        payrolls.add_employee_type();
        break;
      case 5:
        payrolls.Delete_employee();
        break;

    };

    std::cout << "_________________________________________________________________\n\n" << '\n';
  }while(choice < 6);
}
