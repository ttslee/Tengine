#include "Errors.h"
namespace Tengine{
	void fatalError(std::string errorMSG){
		std::cout << errorMSG << std::endl;
		std::cout << "Enter Any Key To Continue..." << std::endl;
		int tmp;
		std::cin >> tmp;
		SDL_Quit();
		exit(1);
	}
}