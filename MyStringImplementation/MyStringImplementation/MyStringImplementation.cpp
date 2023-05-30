// MyStringImplementation.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class MyString {
	friend std::ostream& operator <<(std::ostream& os, const MyString& S);
public:
	MyString():str{nullptr},lenght{0}
	{
		//str[0] = 0;
		//str = nullptr;
	}

	MyString(const MyString& other) 
	{	
		this->lenght = other.lenght;
		str = new char[this->lenght];
		
		this->str = other.str;
	}

	MyString(MyString&& other)  
	{
		this->lenght = other.lenght;
		this->str = other.str;

		other.str = nullptr;
	}

	MyString( const char* str)
	{
		int i = 0; 
		while (str[lenght] != '\0')
		{
			++lenght;
			++i;
		}
		this->str = new char[lenght + 1];

		for (int i = 0; i < lenght; i++)
		{
			this->str[i] = str[i];
		}
		this->str[lenght] = '\0';

	}
	void print()
	{
		std::cout << str;
	}

	MyString& operator =(const MyString& other);
	MyString operator +(const MyString& other);

	MyString operator +(const char* other)
	{
		MyString NewStr;

		int ThisLenght = this->lenght;
		int OtherLenght = 0;
		int j = 0;
		while (other[j] != '\0')
		{
			++OtherLenght;
			++j;
		}
		NewStr.str = new char[ThisLenght + OtherLenght + 1];

		int i = 0;

		for (; i < ThisLenght; i++)
			NewStr.str[i] = this->str[i];

		for (int j = 0; j < OtherLenght; j++, i++)
			NewStr.str[i] = other[j];

		NewStr.str[ThisLenght + OtherLenght] = '\0';

		return NewStr;
	}
	bool operator ==(const MyString& other);
	bool operator !=(const MyString& other);
	
	char& operator [](int index)
	{
		return this->str[index];
	}

	int Size()
	{
		int i = 0;
		while (str[i] != '\0')
		{
			++lenght;
			++i;
		}
		return lenght;
	}

	~MyString()
	{
		delete[] this->str;
		this->str = nullptr;
	}

private:
	char* str = nullptr;
	int lenght = 0;
};


std::ostream& operator<<(std::ostream& os, const MyString& S)
{
	os << S.str;
	return os;
}

int main()
{
	MyString str1("Thj");
	MyString str2("Thj");
	MyString result = str1 + "dtu";
	MyString end = str1 + str2;
	//char st[] = "ygy";
	//MyString("dy");
	MyString result1 = MyString("dy") + str1;
	result.print();
	std::cout << '\n';
	int size = result.Size();
	std::cout<<"size = "<<size;
	std::cout << '\n';
	result.print();
	std::cout << "\n";

	for(int i=0; i< size; ++i)
	std::cout << result[i];
	
	int size_of_end = end.Size();
	std::cout << "\n";
	for (int i = 0; i < size_of_end; ++i)
		std::cout << end[i];

	int size_of_result1 = result1.Size();
	std::cout << "\n";
	for (int i = 0; i < size_of_result1; ++i)
		std::cout << result1[i];

	
	std::cout << '\n';
	bool equal = str1 == str2;
	std::cout << equal << std::endl;
	std::cout << '\n';
	bool unequal = str1 != str2;
	std::cout << unequal << std::endl;

	
	return 0;
}


MyString MyString:: operator +(const MyString& other)
{
	MyString NewStr;

	int ThisLenght = this->lenght;
	int OtherLenght = 0;
	int j = 0;
	while (other.str[j] != '\0')
	{
		++OtherLenght;
		++j;
	}
	NewStr.str = new char[ThisLenght + OtherLenght + 1];

	int i = 0;

	for (; i < ThisLenght; i++)
		NewStr.str[i] = this->str[i];

	for (int j = 0; j < OtherLenght; j++, i++)
		NewStr.str[i] = other.str[j];

	NewStr.str[ThisLenght + OtherLenght] = '\0';

	return NewStr;
}

bool MyString:: operator ==(const MyString& other)
{
	if (this->lenght != other.lenght) return false;

	for (int i = 0; i < this->lenght; i++)
		if (this->str[i] != other.str[i])
			return false;

	return true;
}

bool MyString:: operator !=(const MyString& other)
{
	return this == &other;
}

MyString& MyString:: operator =(const MyString& other)
{
	if (this->str != nullptr)
	{
		delete[] str;
	}
	
	if (this != &other)
	{
		this->str = new char[lenght + 1];

		for (int i = 0; i < lenght; i++)
		{
			this->str[i] = str[i];
		}
		this->str[lenght] = '\0';
	}

	return *this;
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
