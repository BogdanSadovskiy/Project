#include "Errors.h"
Errors::Errors() {
		this->error[1]  = "Invalid input\n";
		this->error[2]  = "Input correct Email\n";
		this->error[3]  = "Can not open the file\n";
		this->error[4]  = "Login or password are incorrect\n";
		this->error[5] = "\t\t\t\t\tThis Login already exist\n";
		this->error[8]  = "Password is too short\n";
		this->error[10] = "Password must have Uppercase, lowercase and number\n";

		this->error[0] = "Nothing\n";
		this->error[6] = "Nothing\n";
		this->error[7] = "Nothing\n";
		this->error[9] = "Nothing\n";
}

string Errors::getTheError(int numOfError) {
	return this->error[numOfError];
}
