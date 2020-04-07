#include<iostream>
#include<vector>

#define INF ~(1 << 31)

int coin_change(const int &val, std::vector<int> &coins) {

  const int n = coins.size();

  /*
    table[val + 1][n]: the solution matrix
    table[i][j]: the optimal solution for value i, using c_0 ... c_j coins

    > final answer will be in table[val][n - 1]
  */
  std::vector< std::vector<int> > table(val + 1, std::vector<int>(n));

  // initialization
  for(unsigned int i = 0; i < n; i = i + 1) {

    for(unsigned int j = 0; j < val + 1; j = j + 1) {

      // it is impossible to pay any amount i with using no coins
      table[j][i] = INF; // ie it would require an inifine amount of coins

    }

  }

  // initialization
  for(unsigned int i = 0; i < n; i = i + 1) {

      // it is impossible to pay any amount i with using no coins
      table[0][i] = 0; // ie it would require an inifine amount of coins

  }

  table[0][0] = 0; // one can pay value 0 with 0 coins

  // for(unsigned int i = 1; i < n; i = i + 1) {

  for(unsigned int j = 0; j < val + 1; j = j + 1) {

    for(unsigned int i = 1; i < n; i = i + 1) {

      // assume there is no solution for table[j][i]
      int sol = INF;

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
        if (tmp != INF) {

          sol = tmp + 1;

        }

      }

      /* note:
        table[j][i - 1] is an optimal solution for value j, not using coin[i]
        thus, it is also a candidate for an optimal solution for table[j][i]
      */
      // > update solution if applicable
      if (sol > table[j][i - 1]) {

        sol = table[j][i - 1];

      }

      // update table[j][i] if needed
      if (table[j][i] > sol) {

        table[j][i] = sol;

      }

    }

  }

  return table[val][n - 1];

}

int main(int argc, char* argv[]){

  int a = 0; // amount
  int n = 0; // number of coins
  std::vector<int> *coins;
  if (argc < 3) { // the number of provided arguments is less than 3

    if (argc == 2) { // amount is provided

      a = std::stoi(argv[1]);

    } else { // amount is not provided

      std::cout << "what is the value that you are looking for: ";
      std::cin >> a;

    }

    // record the coins
    std::cout << "how many coins would you like to provide: ";
    std::cin >> n;
    n = n + 1;
    coins = new std::vector<int>(n);
    for(unsigned int i = 1; i < n; i++)
      std::cin >> (*coins)[i];

  } else {

    // amount is provided
    a = std::stoi(argv[1]);

    // coins are provided
    n = argc - 1;
    coins = new std::vector<int>(n);
    for(unsigned int i = 2; i < argc; i++) {

      (*coins)[i - 1] = std::stoi(argv[i]);

    }

  }

  int ans = coin_change(a, *coins);
  if(ans == INF) {

	  std::cout << "The coins provided cannot give the total value required " << std::endl;

  } else {

	  std::cout << "The number of coins used to get the value " << a << " is : " << ans << std::endl;

  }

  return 0;

}
