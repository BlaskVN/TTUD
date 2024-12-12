#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

int main()
{
    string command;
    int callCount = 0;
    do
    {
        cin >> command;
        if (command == "#") {continue;}
        ++callCount;

    } while (command != "#");

    do
    {
        cin >> command;
        if (command == "#") {continue;}
        if (command == "?check_phone_number")
        {
            /* code */
        }
        else if (command == "?number_calls_from")
        {
            /* code */
        }
        else if (command == "?number_total_calls")
        {
            /* code */
        }
        else if (command == "?count_time_calls_from")
        {

        }
    } while (command != "#");

    return 0;
}
