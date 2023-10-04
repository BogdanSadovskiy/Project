#include "Errors.h"
Errors::Errors() {
		this->error[1] = "Invalid input\n";
		this->error[2] = "Input correct Email\n";
		this->error[8] = "Password is too short\n";
		this->error[10] = "Password must have Uppercase, lowercase and number\n";

}
string Errors::getTheError(int numOfError) {
	return this->error[numOfError];
}
