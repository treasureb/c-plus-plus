#include"GradeBook.h"

GradeBook::GradeBook(string name)
{
	setCourseName(name);
}

void GradeBook::setCourseName(string name)
{
	if (name.length() <= 25)
	{
		courseName = name;
	}
	if (name.length() > 25)
	{
		courseName = name.substr(0, 25);
		cout << "Name\"" << name << "\"exceeds maximum lenth (25).\n" << "Limiting courseName to first 25 characters.\n" << endl;
	}

}

string GradeBook::getCourseName()
{
	return courseName;
}

void GradeBook::displayMessage()
{
	cout << "Welcome to the grade book for\n" << getCourseName() << "!"<<endl;
}

int main()
{
	GradeBook gradebook1("CS101 Introduction to Programming in C++");
	GradeBook gradebook2("CS102 C++ Date Structures");

	cout << "gradebook1's initial course name is:"
		<< gradebook1.getCourseName()
		<< "\ngradebook2's initial course name is:"
		<< gradebook2.getCourseName() << endl;

	gradebook1.setCourseName("CS101 C++ Programming");

	cout << "\ngradebook1's initial course name is:"
		<< gradebook1.getCourseName()
		<< "\ngradebook2's initial course name is:"
		<< gradebook2.getCourseName() << endl;

	return 0;
}