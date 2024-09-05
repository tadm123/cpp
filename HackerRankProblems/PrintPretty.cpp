/*
  Given a text file with many lines of numbers to format and print, for each row of  space-separated doubles, 
  format and print the numbers using the specifications in the Output Format section below.
*/

#include <iostream>
#include <iomanip> 

int main() {
	int T; std::cin >> T;
	std::cout << std::setiosflags(std::ios::uppercase);
	std::cout << std::setw(0xf) << std::internal;
	while(T--) {
		double A; std::cin >> A;
		double B; std::cin >> B;
		double C; std::cin >> C;

        //A
        std::cout << std::hex << std::left << std::showbase << std::nouppercase;
        std::cout << static_cast<long long>(A) << '\n';

        //B
        std::cout << std::dec << std::right << std::showpos << std::setw(15) << std::setfill('_') << std::fixed << std::setprecision(2);

        std::cout << std::right << std::fixed;
        std::cout << B << '\n'; // we're still in hex


        //C
        std::cout << std::noshowpos <<std::scientific << std::uppercase << std::setprecision(9);
        std::cout << C << '\n'; 

	}
	return 0;

}
