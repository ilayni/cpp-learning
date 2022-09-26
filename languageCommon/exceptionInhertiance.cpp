#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;
#include <string>
class BadLengthException : public std::exception
{
    int n;
    public:
    BadLengthException(int num) 
    {
        n = num;
        //cout << "ctr n " << n << endl;
    }
    const char * what() const throw()
    {
        //string my_str = "Too short: " + to_string(n)  + "\n";
        static string my_str = to_string(n);//if this is not static string is lost and than gibrish is returned
        const char * tmp = my_str.c_str();
        //cout << "tmp " << tmp;
        //cout << "what " << my_str << endl;
        return my_str.c_str();//"Too short: " + to_string(n)  + "\n"; 
    }
    /* this should also work
     int what() {
            return n;
        }
        */
       // see https://www.hackerrank.com/challenges/inherited-code/forum
};
/* Define the exception here */


bool checkUsername(string username) {
	bool isValid = true;
	int n = username.length();
	if(n < 5) {
		throw BadLengthException(n);
	}
	for(int i = 0; i < n-1; i++) {
		if(username[i] == 'w' && username[i+1] == 'w') {
			isValid = false;
		}
	}
	return isValid;
}

int main() {
	int T; cin >> T;
	while(T--) {
		string username;
		cin >> username;
		try {
			bool isValid = checkUsername(username);
			if(isValid) {
				cout << "Valid" << '\n';
			} else {
				cout << "Invalid" << '\n';
			}
		} catch (BadLengthException e) {
			cout << "Too short: " << e.what() << '\n';
		}
	}
	return 0;
}