// Week5 Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

using namespace std;
void ShowUsage();
void Display();
void MakePurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge, int& iTotalXXS);
void DisplayPurchase(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXXS);
void DisplayTotal(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXXS);

int main()
{
    //For Menu Navigation
    bool Continue = true;
    const string prompt_Selection = "Please enter selection: ";
    char menu_Select = ' ';




    //Size Amounts
    int iTotalXXS = 0;
    int iTotalSmall = 0;
    int iTotalMedium = 0;
    int iTotalLarge = 0;



    ShowUsage();

    while (Continue == true)
    {
        //Getting Input
        cout << prompt_Selection;
        cin >> menu_Select;
        menu_Select = toupper(menu_Select);

        //Seleecting Menu Options
        switch (menu_Select)
        {
        case 'S':
            ShowUsage();
            break;
        case 'P':
            MakePurchase(iTotalSmall, iTotalMedium, iTotalLarge, iTotalXXS);
            break;
        case 'C':
            DisplayPurchase(iTotalSmall, iTotalMedium, iTotalLarge, iTotalXXS);
            break;
        case 'T':
            DisplayTotal(iTotalSmall, iTotalMedium, iTotalLarge, iTotalXXS);
            break;
        case 'Q':
            cout << "Thank you" << endl;
            Continue = false;
            break;
        }

    }

    system("pause");
    return 0;
}


void Display()
{
    cout << "************************************************************" << endl;
    cout << "***** Welcome to my Johnny Utah's PointBreak Surf Shop *****" << endl;
    cout << "************************************************************" << endl;
    cout << endl;
    cout << endl;
}


void ShowUsage()
{
    system("cls");

    Display();

    cout << "To show program usage 'S'" << endl;
    cout << "To purchase a surfboard press 'P'" << endl;
    cout << "To display current purchase press 'C'" << endl;
    cout << "To display total amount due press 'T'" << endl;
    cout << "To quit the program press 'Q'" << endl;
    cout << endl;
}


void MakePurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge, int& iTotalXXS)
{

    //Purchase Menu Variables
    string initial_input = " ";
    int Amount_Wanted = 0;
    char Size_Wanted = ' ';

    cout << "Please enter the quanity and type (X = XXXS for squirrel surfing, S=small, M=medium, L=large) of surfboard you would like to purchase: ";
    cin >> initial_input;
    cout << endl;

    //Getting numbers and letters froom input string. This way they can enter in any order, as long character count is 2, and the program will run. If there is an easier way let me know.
    if (initial_input.length() == 2)
    {
        for (int i = 0; i <= 1; ++i)
        {
            if (isdigit(initial_input[i])) // getting numbers
            {
                Amount_Wanted = initial_input[i] - '0';
            }
            else if ((initial_input[i] >= 'A' && initial_input[i] <= 'Z') || (initial_input[i] >= 'a' && initial_input[i] <= 'z')) //testing to make sure no special characters // getting only letters
            {
                Size_Wanted = toupper(initial_input[i]);
            }

        }
    }

    //Adding amopunt of sizes requested
    switch (Size_Wanted)
    {
    case 'S':
        iTotalSmall += Amount_Wanted;
        break;
    case 'M':
        iTotalMedium += Amount_Wanted;
        break;
    case 'L':
        iTotalLarge += Amount_Wanted;
        break;
    case 'X':
        iTotalXXS += Amount_Wanted;
        break;
    }


}


void DisplayPurchase(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXXS)
{
    if ((iTotalSmall == 0) && (iTotalMedium == 0) && (iTotalLarge == 0) && (iTotalXXS == 0))
    {
        cout << "No purchase made yet." << endl;
    }
    if (iTotalSmall > 0)
        cout << "The total number of small surfboards is " << iTotalSmall << endl;
    if (iTotalMedium > 0)
        cout << "The total number of meduim surfboards is " << iTotalMedium << endl;
    if (iTotalLarge > 0)
        cout << "The total number of large surfboards is " << iTotalLarge << endl;
    cout << endl;
    if (iTotalXXS > 0)
        cout << "The total number of XXXS for squirrel surfboards is " << iTotalXXS << endl;

}


void DisplayTotal(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXXS)
{
    //local variables
    const double small_Price = 175.00;
    const double Medium_Price = 190.00;
    const double Large_Price = 200.00;
    const double X_Price = 2.00;


    double sTotal = iTotalSmall * small_Price;
    double mTotal = iTotalMedium * Medium_Price;
    double lTotal = iTotalLarge * Large_Price;
    double xTotal = iTotalXXS * X_Price;

    double amount_due = sTotal + mTotal + lTotal + xTotal;


    if ((iTotalSmall == 0) && (iTotalMedium == 0) && (iTotalLarge == 0) && (iTotalXXS == 0))
    {
        cout << "No purchase made yet." << endl;
    }

    if (iTotalSmall > 0)
        cout << "The total number of small surfboards is " << iTotalSmall << " at a total of $" << sTotal << endl;
    if (iTotalMedium > 0)
        cout << "The total number of meduim surfboards is " << iTotalMedium << " at a total of $" << mTotal << endl;
    if (iTotalLarge > 0)
        cout << "The total number of large surfboards is " << iTotalLarge << " at a total of $" << lTotal << endl;
    if (iTotalXXS > 0)
        cout << "The total number of XXXS for squirrel surfboards is " << iTotalLarge << " at a total of $" << xTotal << endl;

        cout << "Amount due: $" << amount_due << endl;
    cout << endl;
}

