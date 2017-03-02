#include<string>
#include<iostream>
using std::string;

using namespace std;

class GradeBook
{
public:
	GradeBook(string);
	void setCourseName(string);
	string getCourseName();
	void displayMessage();
private:
	string courseName;
};