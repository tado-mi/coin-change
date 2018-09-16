#include<iostream>
#include<vector>

#define INF ~(1 << 31)

int min_coins(int &a, int &b){
  std::cout << "a: " << a << " b: " << b << std::endl;
  return(a<b?a:b);
}
//template<std::size_t input, std::size_t n>
void print(std::vector< std::vector<int> > &table){
  //int table[input][n] = *my_table;
  std::cout << std::endl;
  int input = table.size();
  int n = table[0].size(); 
  for(unsigned int i = 0; i < n; i++){
    for(unsigned int j = 0; j < input; j++){
      //std::cout << table <<std::endl
      if(table[j][i] == INF)
	      std::cout << "I ";
      else std::cout << table[j][i] << " "; 
    }
    std::cout << std::endl;
  }
}
/*
   int coin_change_T(int &input, int &c_i , int** &table){	
   if(input == 0) return 0;
   else return ~(1 << 32);
   for(unsigned int j = 0; j < input; j++)
   if(j-c_i < 0) continue;
   table[i][j] = min_coins(table[i-1][j], table[i-1][j-c_i]+1)
//table[i][j] = min_coins(coin_change_T(j,coins, i-1, table), coin_change_T(j-coins[i], coins, i-1, table)+1)
}
*/	
template<typename C , std::size_t N , std::size_t M>
void print_element(C (&ele)[N][M]){
  for(unsigned int i = 0; i < N; i++)
    for(unsigned int j = 0; j < M; j++)
      std::cout << ele[i][j] << std::endl;
}
//template<std::size_t N
int coin_change(const int &input, std::vector<int> &coins){
  //pass code here
  const int n = coins.size();
  std::vector< std::vector< int > > table(input+1 , std::vector<int>(n));
  //int** table = new int[input][n];
  //print_element(a);
  //print_element('c');
  //print_element(true);
  //print_element(1.2);
  //initialization for the table
  table[0][0] = 0;
  std::cout << "the size of the table " << table.size() << std::endl;
  for(unsigned int i = 1; i < input+1; i++)
    table[i][0] = INF;
  print(table);
  for(unsigned int i = 1; i < n; i++){ 
    for(unsigned int j = 0; j < input+1; j++){
      if(j == 0){
	table[j][i] = 0; 
	continue;
      }
      int a = table[j][i-1];
      int b = 0;
      if(((int)j - coins[i]) < 0){
        b = INF; 
        //continue;
      }
      else
        b = table[j-coins[i]][i-1];
      	if(b != INF)
		b++;
      
      //std::cout << "i : " << i << " , j : " << j << std::endl;
      //std::cout << "min coins " << min_coins(a, b) <<std::endl;
      table[j][i] = min_coins(a, b);
      //if(table[j][i] < INF)
	//table[j][i]++;
      //std::cout << "printing the table while evaluating the problem at j : " << j <<  std::endl;
      //print(table);
    }
  }
  //print(table);
  return table[input][n-1];
}

int main(int argc, char* argv[]){
  int input = 0;
  int n = 0;
  std::vector<int> *coins;
  if( argc == 1 ){
    int n;
    std::cout << "what is the value that you are looking for: ";
    std::cin >> input;
    std::cout << "how many coins would you like to provide: ";
    std::cin >> n;
    coins = new std::vector<int>(n+1);
    for(unsigned int i = 1; i < n+1; i++)
      std::cin >> (*coins)[i];

  }
  else if( argc == 2 ){
    input = std::stoi(argv[1]);
    std::cout << "how many coins would you like to provide: ";
    std::cin >> n;	
    coins = new std::vector<int>(n+1);
    for(unsigned int i = 1; i < n+1; i++)
      std::cin >> (*coins)[i];
  }
  else{
    coins = new std::vector<int>(argc-1);
    for(unsigned int i = 3; i < argc; i++)
      (*coins)[i-2] = std::stoi(argv[i-1]);
  }		

  std::cout << "The number of coins used to get the value " << input << " is : " << coin_change(input , *coins) << std::endl;
  return 1;
}
