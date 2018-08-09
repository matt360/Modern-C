#include <iostream>

using namespace std;


void mightGoWrong() {

	bool error1 = false;
	bool error2 = true;

	if (error1) {
		throw "Something went wrong.";
	}

	if (error2) {
		throw string("Something else went wrong");
	}

}

void usesMightGoWrong()
{
	mightGoWrong();
}


int main() {

	try {
		usesMightGoWrong();
	}
	catch(int e) {
		cout << "Error code: " << e << endl;
	}
	catch (const char* e) {
		cout << "Error code: " << e << endl;
	}
	catch (string& e) {
		cout << "String error code: " << endl;
	}

	std::cout << "Still running!";

	cin.get();

	return 0;
}