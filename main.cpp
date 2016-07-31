#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
#include <stdlib.h>
#include <unistd.h>
#include <thread>

int main(int argc, char *argv[]) {

	if(argc == 3){
		std::string strIP = argv[1];
		std::string strNetmask = argv[2];
	    std::istringstream issNetmask(strNetmask);
	    std::string token;
	    int subnetElement = 0;
	    int cidr = 0;
	    std::string strIpCidr = "";

	    // Do until substrings available
		while(std::getline(issNetmask, token, '.')) {
		    // Convert substring to integer
		    subnetElement = std::stoi(token);

		    // Convert integer to CIDR representation
			while(subnetElement)
			{
			    cidr += (subnetElement & 0x01 );
			    subnetElement >>= 1;
			}
		}

		strIpCidr = strIP + "/" + std::to_string(cidr);

		std::cout << strIpCidr << std::endl;
	}else{
		std::cout << "Please use correct input format. E.g.: ./subnet2cidr 192.168.178.23 255.255.255.0" << std::endl;
	}
}