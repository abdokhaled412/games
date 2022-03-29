

#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>
using namespace std;
//name:abdelrhman khaled farouk
//id;20210203
int Game_Win(std::list<int> lis) {
    if (lis.size() < 3) {
        return false;
    }

    else {
        for (int i = 0; lis.size(); i++) {
            for (int j = 0; j < lis.size(); j++) {
                for (int m = 0; m < lis.size(); m++) {
                    if (((i + m + j) == 15) && (i != j) && (i != m) && (j != m)) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
int main()
{
    int game1 = 0;
    int game2 = 0;
    std::list<int> lis1;
    std::list<int> lis2;

    string p1, p2;
    cout << "Player1 enter your name: ";
    cin >> p1;
    cout << "Player2 enter your name: ";
    cin >> p2;

    while (game1 < 15)
    {
        int player1;
        cout << p1 << " enter your number: ";
        cin >> player1;
        while (cin.fail())
        {
            cout << "Invalid input !";
            cin.clear();
            cin.ignore(256, '\n');
            cout << endl << "Enter number: ";
            cin >> player1;
        }
        if (player1 < 1 || player1>9)
            while (player1 < 1 || player1>9)
            {
                cout << p1 << " enter a number between 1 and 9 only: ";
                cin >> player1;
            }
        if (std::find(std::begin(lis1), std::end(lis1), player1) != std::end(lis1) || std::find(std::begin(lis2), std::end(lis2), player1) != std::end(lis2))
            while (std::find(std::begin(lis1), std::end(lis1), player1) != std::end(lis1) || std::find(std::begin(lis2), std::end(lis2), player1) != std::end(lis2)) {
                cout << p1 << " enter a number not used before: ";
                cin >> player1;
            }

        lis1.push_back(player1);
        game1 += player1;
        //cout << "Picked Numbers " << p1 << " =" ; print(lis1)

        if (Game_Win(lis1))
            cout << p1 << " win \n";


        // Player 2 turn
        if (game2 < 15)
        {
            int player2;
            cout << p2 << " enter your number: ";
            cin >> player2;
            while (cin.fail())
            {
                cout << "Invalid input !";
                cin.clear();
                cin.ignore(256, '\n');
                cout << endl << "Enter number: ";
                cin >> player2;
            }
            if (player2 < 1 || player2>9)
                while (player2 < 1 || player2>9)
                {
                    cout << p2 << " enter a number between 1 and 9 only: ";
                    cin >> player2;
                }
            if (std::find(std::begin(lis1), std::end(lis1), player2) != std::end(lis1) || std::find(std::begin(lis2), std::end(lis2), player2) != std::end(lis2))
                while (std::find(std::begin(lis1), std::end(lis1), player2) != std::end(lis1) || std::find(std::begin(lis2), std::end(lis2), player2) != std::end(lis2)) {
                    cout << p2 << " enter a number not used before: ";
                    cin >> player2;
                }
            lis2.push_back(player2);
            game2 += player2;

            //cout << "Picked Numbers " << p2 << " =" << lis2;

            if (Game_Win(lis2))
                cout << p2 << " win \n";


        }
    }
    return 0;

}

