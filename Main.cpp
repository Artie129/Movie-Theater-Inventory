#include <iostream>
#include <vector>
#include <string.h>
#include <stdlib.h>
using namespace std;

void ShellSort(vector<string>&movietitles);

struct THEATER_INFO
{
  string theater_address = "";
  string theater_name = "";
};

int main()
{
  THEATER_INFO usertheater;
  string tempstring = "";
  int tempint = 0;
  double tempdouble = 0;
  bool endloop = false;

  while (endloop == false)
    {
  cout << "Enter your theater's name:\n";
  getline(cin, usertheater.theater_name);
      
  cout << "Enter your theater's address:\n";
  getline(cin, usertheater.theater_address);
  cout << "Theater Name: " << usertheater.theater_name << "\n";
  cout << "Theater Address: " << usertheater.theater_address << "\n";
  cout << "Are you satisfied with this information? (1 to continue, 2 to reenter.\n";
  cin >> tempint;
      switch (tempint)
        {
          case 1:
          cout << "Continue selected.\n";
          endloop = true;
          break;

          case 2:
          cout << "Reenter selected.\n";
          endloop = false;
          break;

          default:
          cout << "Error. Invalid choice, resetting loop.\n";
          endloop = false;
          break;
          
        }
      
    }

  string snacks[5];
  double prices[5];
  cout << "Setup Task 1: Snacks and Prices.\n";
  for (int i = 0; i < 5; i++)
    {
      cout << "Enter snack " << i + 1 << " of 5\n";
      cin >> snacks[i];
    }

  for (int i = 0; i < 5; i++)
    {
      cout << "Enter the price of snack " << i + 1 << " of 5\n";
      cin >> prices[i];
    }

  cout << usertheater.theater_name << " Snack Menu:\n";
  for (int i = 0; i < 5; i++)
    {
      cout << "Snack: " << snacks[i] << "  Price: " << prices[i] << "\n";
    }

  cout << "\n";
  cout << "\n";
  cout << "\n";
  cout << "Part 2: Theater Controls\n";
  double ticketcost = 0.0;
  int theatercount = 0;
  endloop = false;
  while (endloop == false)
  {
  cout << "Enter the cost of one ticket.";
  cin >> ticketcost;
  cout << "How many films can your theater show at once?";
  cin >> theatercount;
  cout << "Are you satisfied with this information? (1 to continue, 2 to reenter.\n";
  cin >> tempint;
        switch (tempint)
        {
          case 1:
          cout << "Continue selected.\n";
          endloop = true;
          break;

          case 2:
          cout << "Reenter selected.\n";
          endloop = false;
          break;

          default:
          cout << "Error. Invalid choice, resetting loop.\n";
          endloop = false;
          break;
          
        }
  }

  vector<string> movietitles;
  vector<double> movieseats;
  vector<double> earnings;
  double currentearnings;
  string tempmovie;
  double tempseats;
  cout << "Enter information:\n";
  for (int i = 0; i < theatercount; i++)
    {
      cout << "Enter film " << i + 1 << " :\n";
      getline(cin, tempmovie);
      movietitles.push_back(tempmovie);
    }
  
  for (int i = 0; i < theatercount; i++)
    {
      cout << "Enter the amount of seats for " << movietitles[i] << " :";
      cin >> tempseats;
      movieseats.push_back(tempseats);
      currentearnings = tempseats * ticketcost;
      earnings.push_back(currentearnings);
    }

  for (int i = 0; i < theatercount; i++)
    {
      cout << "Film: " << movietitles[i] << "  Seats: " << movieseats[i] << "  Maximum Earnings: " << earnings[i] << "\n";
    }

  ShellSort(movietitles);
  cout << "Movie Titles sorted alphabetically:";
  for (int index = 0; index < movietitles.size(); index++)
    {
    cout << movietitles[index] << endl;
    }


}

void ShellSort(vector<string>&movietitles)
  {
    int i, flag = 1, numLength = movietitles.size();
    string temp;
    int d = numLength;
    while( flag || (d > 1)) // boolean flag (true when not equal to 0)
       {
          flag = 0; // reset flag to 0 to check for future swaps
          d = (d+1) / 2;
          for (i = 0; i < (numLength - d); i++)   
            {
              if (movietitles[i + d] < movietitles[i])   
                {
                  temp = movietitles[i + d]; // swap positions i+d and i
                  movietitles[i + d] = movietitles[i];
                  movietitles[i] = temp;
                  flag = 1; // tells swap has occurred
                }
             }
       }
  }
