#include<iostream>

using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "/t"

class Teacher
{
	string name;
	string second_name;
	double age;
public:
	/*-----------------------------------------------------*/
	const string& get_name()const
	{
		return name;
	}

	const string& get_second_name()const
	{
		return second_name;
	}

	double get_age()const
	{
		return age;
	}

	void set_name(const string& name)
	{
		this->name = name;
	}

	void set_second_name(const string& second_name)
	{
		this->second_name = second_name;
	}

	void set_age(double age)
	{
		this->age = age;
	}

	/*-----------------------------------------------------*/
	Teacher(string name = "Teacher", string second_name = "class", double age = 0)
	{
		this->name = name; this->second_name = second_name; this->age = age;
	}
	~Teacher() {}
	/*-----------------------------------------------------*/

	void info()const
	{
		if (age < 20)
		{
			cout << "Это не учитель ";
		}
		cout << name << " " << second_name << " " << age << " лет" << endl;
		cout << "/*-----------------------------------------------------*/" << endl << endl;
	}

};

class Student :public Teacher
{
	int point_average;
	int course;
public:
	int get_point_average()const
	{
		return point_average;
	}
	int get_course()const
	{
		return course;
	}
	void set_point_average(int point_average)
	{
		this->point_average = point_average;
	}
	void set_course(int course)
	{
		this->course = course;
	}
	/*-----------------------------------------------------*/
	Student(string name = "Student", string second_name = "class", double age = 0, int point_average = 0, int course = 1) :Teacher(name, second_name, age)
	{
		this->point_average = point_average;
		this->course = course;
	}
	~Student() {}
	/*-----------------------------------------------------*/
	void info()const
	{
		if (this->get_age() < 15)
		{
			cout << "Ученик еще не закончил школу ";
		}
		cout << this->get_name() << " " << this->get_second_name() << " " << this->get_age() << " лет " << course << " курс " << "\tСредный балл : " << point_average << endl;
		cout << "/*-----------------------------------------------------*/" << endl << endl;
	}
};

class Graduate :public Student
{
	bool graduate;
	string graduate_work;
public:
	bool get_graduate()const
	{
		return graduate;
	}
	const string& get_graduate_work()const
	{
		return graduate_work;
	}
	void set_graduate(bool graduate)
	{
		this->graduate = graduate;
	}
	void set_graduate_work(const string& graduate_work)
	{
		this->graduate_work = graduate_work;
	}
	Graduate
	(string name = "Student", string second_name = "class", double age = 0, int point_average = 0, int course = 1, bool graduate = false, string graduate_work = "default_graduate_work"
	) :Student(name, second_name, age, point_average, course)
	{
		this->graduate = graduate;
		this->graduate_work = graduate_work;
	}
	~Graduate() {}
	void info()const
	{
		if (this->get_age() < 15)
		{
			cout << "Ученик еще не закончил школу ";
		}
		cout << this->get_name() << " " << this->get_second_name() << " " << this->get_age() << " лет " << this->get_course() << " курс " << "\tСредный балл : " << this->get_point_average() << endl;
		cout << (this->graduate ? this->graduate_work : "Не дипломник") << endl;
		cout << "/*-----------------------------------------------------*/" << endl << endl;
	}
};


int main()
{
	setlocale(LC_ALL, "rus");
	Teacher teahcer("Иванов", "Дмитрий", 19);
	teahcer.info();
	teahcer.set_age(90);
	teahcer.set_name("Мария");
	teahcer.set_second_name("Ивановна");
	teahcer.info();



	Student student("ivan", "Pavlov", 17, 66, 1);
	student.info();

	Graduate graduate("NeDiplom", "NeDiplomovich", 18, 100, 3, false, "Тема : Разработка программы мониторинга сетевой активности компьютера.");
	graduate.info();

	Graduate graduate2("Diplom", "Diplomovich", 18, 100, 4, true, "Тема : Разработка программы мониторинга сетевой активности компьютера.");
	graduate2.info();


	graduate2.set_graduate_work("Тема : Технология ADSL");	
	graduate2.info();


	return 0;
}
