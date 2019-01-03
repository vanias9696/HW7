#include "employee.h"

AbstractEmployee::AbstractEmployee() : first_name_("none"), last_name_("none"), job_("none"){}

AbstractEmployee::AbstractEmployee(const std::string& fn, const std::string& ln, const std::string& j)
{
	first_name_ = fn;
	last_name_ = ln;
	job_ = j;
}

void AbstractEmployee::showAll() const
{
	std::cout << "First name: " << first_name_ << "." << std::endl;
	std::cout << "Last name: " << last_name_ << "." << std::endl;
	std::cout << "Job: " << job_ << "." << std::endl;
}

void AbstractEmployee::setAll()
{
	std::cout << "Enter first name: ";
	std::cin >> first_name_;
	std::cout << "Enter last name: ";
	std::cin >> last_name_;
	std::cout << "Enter job: ";
	std::cin >> job_;
}

std::ostream& operator<<(std::ostream& os, const AbstractEmployee& e)
{
	os << e.first_name_ << " " << e.last_name_;
	return (os);
}

Employee::Employee() : AbstractEmployee(){}

Employee::Employee(const std::string& fn, const std::string& ln, const std::string& j) :
	AbstractEmployee(fn, ln, j) {}

void Employee::showAll() const
{
	std::cout << "Employee:" << std::endl;
	AbstractEmployee::showAll();
}

void Employee::setAll()
{
	std::cout << "Enter information for employee:" << std::endl;
	AbstractEmployee::setAll();
}

Manager::Manager() :
	AbstractEmployee(), in_charge_of_(0) {}

Manager::Manager(const std::string& fn, const std::string& ln,const std::string& j, int ico) :
	AbstractEmployee(fn, ln, j), in_charge_of_(ico) {}

Manager::Manager(const AbstractEmployee& e, int ico) :
	AbstractEmployee(e), in_charge_of_(ico){}

Manager::Manager(const Manager& m) :
	AbstractEmployee(m), in_charge_of_(m.in_charge_of_){}

void Manager::showAll() const
{
	std::cout << "Manager:" << std::endl;
	AbstractEmployee::showAll();
	std::cout << "Number of employees managers: " << in_charge_of_ << "." << std::endl;
}
void Manager::setAll()
{
	std::cout << "Enter information for manager:" << std::endl;
	AbstractEmployee::setAll();
	std::cout << "Enter number of employees managers: ";
	std::cin >> in_charge_of_;
}

Fink::Fink() :
	AbstractEmployee(), reports_to_("none"){}

Fink::Fink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo) :
	AbstractEmployee(fn, ln, j), reports_to_(rpo) {}

Fink::Fink(const AbstractEmployee& e, const std::string& rpo) :
	AbstractEmployee(e), reports_to_(rpo) {}

Fink::Fink(const Fink & e) :
	AbstractEmployee(e), reports_to_(e.reports_to_){}

void Fink::showAll() const
{
	std::cout << "Fink:" << std::endl;
	AbstractEmployee::showAll();
	std::cout << "Person, who he reports to: " << reports_to_ << "." << std::endl;
}

void Fink::setAll()
{
	std::cout << "Enter information for fink:" << std::endl;
	AbstractEmployee::setAll();
	std::cout << "Person, who he reports to: ";
	std::cin >> reports_to_;
}

HighFink::HighFink() :
	AbstractEmployee(), Manager(), Fink(){}

HighFink::HighFink(const std::string& fn, const std::string& ln,const std::string& j, const std::string& rpo, int ico) :
	AbstractEmployee(fn, ln, j), Manager(fn, ln, j, ico), Fink(fn, ln, j, rpo) {}

HighFink::HighFink(const AbstractEmployee& e, const std::string& rpo, int ico) :
	AbstractEmployee(e), Manager(e, ico), Fink(e, rpo){}

HighFink::HighFink(const Fink& f, int ico) :
	AbstractEmployee(f), Manager(f, ico), Fink(f) {}

HighFink::HighFink(const Manager& m, const std::string& rpo) :
	AbstractEmployee(m), Manager(m), Fink(m, rpo){}

HighFink::HighFink(const HighFink& h) :
	AbstractEmployee(h), Manager(h), Fink(h) {}

void HighFink::showAll() const
{
	std::cout << "High Fink:" << std::endl;
	AbstractEmployee::showAll();
	std::cout << "Number of employees managers: " << inChargeOf() << "." << std::endl;
	std::cout << "Person, who he reports to: " << reportsTo() << "." << std::endl;
}

void HighFink::setAll()
{
	int tmpI = 0;
	std::string tmpS;

	std::cout << "Enter information for high fink:" << std::endl;
	AbstractEmployee::setAll();
	std::cout << "Person, who he reports to: ";
	std::cin >> tmpS;
	setReportsTo(tmpS);
	std::cout << "Enter number of employees managers: ";
	std::cin >> tmpI;
	setInChargeOf(tmpI);
}
