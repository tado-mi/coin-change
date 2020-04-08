#include<iostream>
#include<vector>

using namespace std;

#define INF ~(1 << 31)

int coin_change(const int &val, vector<int> &coins) {

  const int n = coins.size();

  /*
    table[val + 1][n]: the solution matrix
    table[i][j]: the optimal solution for value i, using c_0 ... c_j coins

    > final answer will be in table[val][n - 1]
  */
  vector< vector<int> > table(val + 1, vector<int>(n));

  // initialization
  for(unsigned int i = 0; i < val + 1; i = i + 1) {

    for(unsigned int j = 0; j < n; j = j + 1) {

      // it is impossible to pay any amount i with using no coins
      table[i][j] = INF; // ie it would require an inifine amount of coins

    }

  }

  for(unsigned int j = 0; j < n; j = j + 1) {

      table[0][j] = 0; // // one can pay value 0 with j coins for any j

  }

  for(unsigned int j = 0; j < val + 1; j = j + 1) {

    /*
      let sol be a temporary variable to minimize over all possible solutions
    */

    // assume there is no solution for table[j][i]
    int sol = INF;

    for(unsigned int i = 1; i < n; i = i + 1) {

      /* note:
        table[j][i - 1] is an optimal solution for value j, not using coin[i]
        thus, it is also a candidate for an optimal solution for table[j][i]
      */
      sol = table[j][i - 1];

      /* consider:
        using the coin[i]
        a solution for the amount = j - coins[i]
      */
      int amount = j - coins[i];
      if ( amount >= 0) {

        // the optimal solution for amount using up to i - 1 coins
        int tmp = table[amount][i - 1];

        /* note:
          if we add coin[i], we can pay j = amount + coin[i]
          thus, tmp + 1 is a candidate for an optimal solution for table[j][i]
        */
        if (tmp != INF) { // condition required to account for overflows

          tmp = tmp + 1;

        }

        if (sol > tmp) {

          sol = tmp;

        }

        // update table[j][i] if needed
        if (table[j][i] > sol) {

          table[j][i] = sol;

        }


      }

    }
  }

  return table[val][n - 1];

}

int main(int argc, char* argv[]){

  int a = 0; // amount
  int n = 0; // number of coins
  vector<int> *coins;
  if (argc < 3) { // the number of provided arguments is less than 3

    if (argc == 2) { // amount is provided

      a = stoi(argv[1]);

    } else { // amount is not provided

      cout << "Enter the amount: ";
      cin >> a;

    }

    // record the coins
    cout << "Enter the number of coins: ";
    cin >> n;
    n = n + 1;
    coins = new vector<int>(n);
    cout << "Enter the coins (each on a new line): " << endl;
    for(unsigned int i = 1; i < n; i++)
      cin >> (*coins)[i];

  } else {

    // amount is provided
    a = stoi(argv[1]);

    // coins are provided
    n = argc - 1;
    coins = new vector<int>(n);
    for(unsigned int i = 2; i < argc; i++) {

      (*coins)[i - 1] = stoi(argv[i]);

    }

  }

  int ans = coin_change(a, *coins);
  if(ans == INF) {

	  cout << "There is no solution." << endl;

  } else {

	  cout << "The answer is: " << ans << "." << endl;

  }

  return 0;

}
