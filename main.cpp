#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

using namespace std;

struct Client //Strecuture declaration
{
   string name;
   char risk;  //Structure variables declaration
   double payment;
   int dependents;

};

int main()
{
    int n = 0; //Declaring counter
    struct Client clients[20];

    while (clients[n].name != "XXX") // "XXX" will stop the loop asking for user input
    {
        cout << "Enter the client name (XXX to stop): ";
        cin >> clients[n].name; //Input for user name
        if (clients[n].name == "xxx")
        {
            break;
        }
        cout << "Enter the risk status (H/M/L): ";
        cin >> clients[n].risk; //Input for user risk status
        while (tolower(clients[n].risk) != 'h' && tolower(clients[n].risk) != 'm' && tolower(clients[n].risk) != 'l') //Validating user input
        {
            cout << "Invalid! Risk level should be H, M or L). " << endl; //Case if user inserted invalid character
            cout << "Enter the risk status (H/M/L): ";
            cin >> clients[n].risk;
        }
        cout << "Enter the monthly payment: R ";
        cin >> clients[n].payment; //Input for user monthly payment
        cout << "Enter the number of dependents: ";
        cin >> clients[n].dependents; //Input for user number of dependents
        n++;
    }

    cout << "Client insurance information" << endl;
    cout << "\tClient Name \t Risk Level \t Monthly Payment \t Num of dependents" << endl;
    for (int i = 0; i < n; i++) //Iterating though array to display all of the information
    {
        cout << i + 1 << "\t";
        cout << clients[i].name;
        printf("\t \t %c \t\t R %.2f \t\t\t %d\n", clients[i].risk, clients[i].payment, clients[i].dependents);
    }

    int num;
    int num_add_remove; //Declaring variables used to modify the number of dependents
    char add_or_remove;

    while (num != - 1)
    {
        cout << "Enter a number from the list (-1 to cancel): ";
        cin >> num;
        if (num == -1)
        {
            break; //-1 ends the loop
        }
        num = num -1;
        cout << "Enter the number of dependents to add or remove: ";
        cin >> num_add_remove; //Receiving modification iformation from the user
        cout << "Do you want to Add or Remove dependents (A or R): ";
        cin >> add_or_remove;

        if (add_or_remove == 'A' || add_or_remove == 'a') //Case if user wants to add dependents
        {
            clients[num].dependents += num_add_remove;
            cout << "\n\nThe adjusted number of of dependents is " << num_add_remove << endl;
            if (clients[num].dependents > 10)
            {
                clients[num].dependents -= num_add_remove; //Esuring the number of dependents is valid

            }
        }
        else if (add_or_remove == 'R'|| add_or_remove == 'r') //Case if user wants to remove dependents
        {
            clients[num].dependents -= num_add_remove;
            cout << "\n\nThe adjusted number of of dependents is " << num_add_remove << endl;
             if (clients[num].dependents > 10)
            {
                clients[num].dependents += num_add_remove; //Esuring the number of dependents is valid

            }
        }
        cout << "\n\nThe adjustment has been made" << endl;
        cout << "\nClient insurance information" << endl;  //Displaying the adjusted information to the user
        cout << "\tClient Name \t Risk Level \t Monthly Payment \t Num of dependents" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << i + 1 << "\t";
            cout << clients[i].name;
            printf("\t \t %c \t\t R %.2f \t\t\t %d\n", clients[i].risk, clients[i].payment, clients[i].dependents);
        }

    }


    for (int i = 0; i < n; i++) //Iterating thought the array and adjusting values accordingly
    {
        if (tolower(clients[i].risk) == 'm' || tolower(clients[i].risk) == 'h')
        {
            if (clients[i].dependents <= 2)
            {
                (clients[i].payment = clients[i].payment * 1.025);
            }
            else if (clients[i].dependents <= 4)
            {
                (clients[i].payment = clients[i].payment * 1.035);
            }
            else if (clients[i].dependents > 4)
            {
                (clients[i].payment = clients[i].payment * 1.04);
            }
        }
    }

    cout << "\n\nPayment adjustment for medium and high risk clients ADDED!" << endl;
    cout << "\nClient insurance information" << endl;  //Outputting the final result
    cout << "\tClient Name \t Risk Level \t Monthly Payment \t Num of dependents" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "\t";
        cout << clients[i].name;
        printf("\t \t %c \t\t R %.2f \t\t\t %d\n", clients[i].risk, clients[i].payment, clients[i].dependents);
    }

    return 0;
}
