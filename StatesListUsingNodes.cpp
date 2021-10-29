//Dillon Lin
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

struct Node
{
    Node *Previous = NULL;
    Node *Next = NULL;
    string State = "N/A";
    int Value = 0;
};

int main()
{
    Node *First = NULL;
    Node *Last = NULL;
    Node *P;
    Node *TempNext;
    Node *TempPrevious;

    string stringtemp;
    int option,elements=1,temp,temp2;
    bool found;

    ofstream outFile;
    ifstream inFile;

    inFile.open("States2.dat",ios::in);
    if (!inFile)
    {
        cout << "Error: File could not be opened.\n\n";
        system("pause");
        exit(0);
    }
    P = new Node;
    First = P;
    Last = P;
    inFile >> P->State >> P->Value;
    while(!inFile.eof())
    {
        //cout << "\nNode #" << elements << ": " << P -> State << "\t" << P -> Value << " @ Memory Address (" << P << ")\tBeing Pointed By: " << P -> Previous;
        P = new Node;
        inFile >> P->State >> P->Value;

        P -> Next = NULL;
        P -> Previous = Last;
        Last = P;
        P = P -> Previous;
        P -> Next = Last;
        P = Last;
        elements++;

    }
    inFile.close();

    do
    {
        system("cls");
        cout << "\n1 - Insert New Node to the BEGINNING of the List (" << elements << " Nodes)"
             << "\n2 - Insert New Node to the END of the List (" << elements << " Nodes)"
             << "\n3 - Insert New Node into the MIDDLE of the List (" << elements << " Nodes)"
             << "\n4 - Display ALL Nodes From Front to the Last Node"
             << "\n5 - Display ALL Nodes From Last to the Front Node"
             << "\n6 - Search Node By State Name"
             << "\n7 - Search Node By State Name and Make Changes"
             << "\n8 - Delete a Node"
             << "\n9 - QUIT"
             << "\nEnter an Option 1-9: ";
        cin >> option;

        switch(option)
        {
            case 1:
                    system("cls");
                    P = new Node;
                    cout << "\nNew Node Created @ Memory Address " << P;
                    cout << "\nEnter State for New Node: ";
                    cin >> stringtemp;
                    P->State = stringtemp;
                    cout << "\nEnter Integer Value for New Node: ";
                    cin >> temp;
                    P -> Value = temp;
                    if (elements == 0)
                    {
                        First = P;
                        Last = P;
                    }
                    else
                    {
                        P -> Next = First;
                        P -> Previous = NULL;
                        First = P;
                        P = P -> Next;
                        P -> Previous = First;
                    }
                    elements++;
                    break;

            case 2:
                    system("cls");
                    P = new Node;
                    cout << "\nNew Node Created @ Memory Address " << P;
                    cout << "\nEnter State for New Node: ";
                    cin >> stringtemp;
                    P->State = stringtemp;
                    cout << "\nEnter Integer Value for New Node: ";
                    cin >> temp;
                    P -> Value = temp;
                    if (elements == 0)
                    {
                        First = P;
                        Last = P;
                    }
                    else
                    {
                        P -> Next = NULL;
                        P -> Previous = Last;
                        Last = P;
                        P = P -> Previous;
                        P -> Next = Last;
                    }
                    elements++;
                    break;

            case 3:
                    found = false;
                    system("cls");
                    cout << "\nEnter State Name You Wish To Find: ";
                    cin >> stringtemp;
                    P = First;
                    for(int n=1; n<=elements; n++)
                    {
                        if(P->State == stringtemp)
                        {
                            //Hold Address of Target and Its Next Since They Will Be Used/Updated
                            TempPrevious = P;
                            TempNext = P->Next;
                            //Create New Node
                            P = new Node;
                            elements++;
                            cout << "\nNew Node Created @ Memory Address " << P
                                 << "\nEnter State for New Node: ";
                            cin >> stringtemp;
                            P->State = stringtemp;
                            cout << "\nEnter Integer Value for New Node: ";
                            cin >> temp;
                            P->Value = temp;
                            //Input the Held Addresses into New Node
                            P->Previous = TempPrevious;
                            P->Next = TempNext;
                            //Update the Previous and Next of the Two That The New Node is between
                            TempNext = P;
                            P = P->Next;
                            P->Previous = TempNext;
                            //Go Back To Origin Node
                            P=P->Previous; P=P->Previous;
                            P->Next = TempNext;
                            found = true;
                            break;
                        }
                        P = P->Next;
                    }
                    if (found == false)
                    {
                        cout << "\State NOT Found in List\n\n";
                        system("pause");
                    }
                    break;


            case 4:
                    system("cls");
                    P = First;
                    for (int n=1; n<= elements; n++)
                    {
                        cout << "\nNode \t#" << n << ": " << P -> State << "\t" << P -> Value << " @ Memory Address (" << P << ")\tPointing to: " << P -> Next;
                        P = P -> Next;
                    }
                    cout << "\n\n";
                    system("pause");
                    break;

            case 5:
                    system("cls");
                    P = Last;
                    for (int n=1; n<= elements; n++)
                    {
                        cout << "\nNode \t#" << n << ": " << P -> State << "\t" << P -> Value << " @ Memory Address (" << P << ")\tPointing to: " << P -> Previous;
                        P = P -> Previous;
                    }
                    cout << "\n\n";
                    system("pause");
                    break;

            case 6:
                    found = false;
                    system("cls");
                    cout << "\nEnter State Name You Wish To Find: ";
                    cin >> stringtemp;
                    P = First;
                    for(int n=1; n<=elements; n++)
                    {
                        if(P->State == stringtemp)
                        {
                            cout << "\n" << P -> State << "\t" << P -> Value << " @ Memory Address (" << P << ")\n\n";
                            system("pause");
                            found = true;
                            break;
                        }
                        P = P->Next;
                    }
                    if (found == false)
                    {
                        cout << "\State NOT Found in List\n\n";
                        system("pause");
                    }
                    break;

            case 7:
                    found = false;
                    system("cls");
                    cout << "\nEnter State Name You Wish To Find: ";
                    cin >> stringtemp;
                    P = First;
                    for(int n=1; n<=elements; n++)
                    {
                        if(P->State == stringtemp)
                        {
                            do
                            {
                                system("cls");
                                cout << "\n" << P->State << " " << P->Value << " is found @ Memory Address " << P
                                     << "\n\n1 - Change State Name"
                                     << "\n2 - Change State Value"
                                     << "\n3 - QUIT"
                                     << "\nEnter an Option 1-2: ";
                                cin >> temp;
                                switch(temp)
                                {
                                    case 1:
                                            cout << "\n\nEnter NEW State Name: ";
                                            cin >> stringtemp;
                                            P->State = stringtemp;
                                            break;
                                    case 2:
                                            cout << "\n\nEnter NEW Value: ";
                                            cin >> temp2;
                                            P->Value = temp2;
                                            break;

                                }
                            }while(temp != 3);

                            cout << "\nEDITS APPLIED\n\n";
                            system("pause");
                            found = true;
                            break;
                        }
                        P = P->Next;
                    }
                    if (found == false)
                    {
                        cout << "\nValue NOT Found in List\n\n";
                        system("pause");
                    }
                    break;

            case 8:
                    found = false;
                    system("cls");
                    cout << "\nEnter State Which You Wish To Delete: ";
                    cin >> stringtemp;
                    P = First;
                    for(int n=1; n<=elements; n++)
                    {
                        if(P->State == stringtemp)
                        {
                            if(P == First)
                            {
                                TempNext = P->Next;
                                delete P;
                                P = TempNext;
                                P->Previous = NULL;
                                First = P;
                                elements--;
                            }
                            else if(P == Last)
                            {
                                TempPrevious = P->Previous;
                                delete P;
                                P = TempPrevious;
                                P->Next = NULL;
                                Last = P;
                                elements--;
                            }
                            else
                            {
                                TempNext = P->Next;
                                TempPrevious = P->Previous;
                                delete P;
                                P = TempPrevious;
                                P-> Next = TempNext;
                                P = P->Next;
                                P->Previous = TempPrevious;
                                elements--;
                            }
                            cout << "\nSTATE DELETED\n\n";
                            system("pause");
                            found = true;
                            break;
                        }
                        P = P->Next;
                    }
                    if (found == false)
                    {
                        cout << "\State NOT Found in List\n\n";
                        system("pause");
                    }
                    break;

            case 9:
                    system("cls");
                    outFile.open("States2.dat");
                    P = First;
                    for (int n=1; n<=elements; n++)
                    {
                        outFile << P->State << " " << P->Value << "\n";
                        P = P->Next;
                    }
                    outFile.close();
                    cout << "\nALL INFO COPIED TO DATAFILE...\n\n";
                    system("pause");
        }

    }while (option != 9);

}
