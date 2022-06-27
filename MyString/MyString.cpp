#include "String.h"



    String::String() : String("", 80) {}

	String::String(const char* text) : String(text, 80) {}

	String::String(unsigned int capacity) : String("", capacity) {}
	
	String::String(const String& original) : String(original.text, original.capacity) {}

	String::String(const char* text, unsigned int capacity)
	{
		SetString(text, capacity);
	}

	String::~String()
	{
		if (text != nullptr)
		{
			delete[] text;
			text = nullptr;
		}
	}

	// геттеры-сеттеры
	string String::GetString() const
	{
		return text;
	}

	void String::SetString(const char* text, unsigned int capacity = 80)
	{
		length = strlen(text);

		if (capacity <= length)
			capacity = length + 1;

		this->capacity = capacity;

		delete[] this->text;

		this->text = new char[capacity];
		strcpy_s(this->text, length + 1, text);
	}

	int String::GetLength() const
	{
		return length;
	}

	// метода SetLength не должно быть!

	int String::GetCapacity() const
	{
		return capacity;
	}

	char String::GetCharAt(unsigned int index) const
	{
		if (index >= length || index < 0)
		{
			throw "incorrect index!!!";
			return 0;
		}
		else
		{
			return text[index];
		}
	}
	//strcmp();
	int String::CompareTo(const String& another)
	{
		return strcmp(text, another.text);
	}

	void String::Clear()
	{
		text[0] = '\0';
		length = 0;
	}

	// подгоняем capacity под length + 1
	void String::ShrinkToFit()
	{
		if (capacity == length + 1)
		{
			return;
		}

		capacity = length + 1;
		char* temp = new char[capacity];
		strcpy_s(temp, capacity, text);
		delete[] text;
		text = temp;
	}

	// отладочный метод, потом можно будет удалить
	void String::ShowInfo() const
	{
		cout << "Text: " << GetString() << endl;
		cout << "Length: " << GetLength() << endl;
		cout << "Capacity: " << GetCapacity() << endl;
	}
	void String::Concat(const String& another)
	{
		string a = text;
		delete[] this->text;

		capacity += another.capacity;
		this->text = new char[capacity];
		for (int i = 0; i < length; i++)
		{
			text[i] = a[i];
		}

		for (int i = 0; i < another.length; i++)
		{
			text[i + length] = another.text[i];
		}
		length += another.length;
		text[length] = '\0';

		ShrinkToFit();
	}
	bool String::Contains(const String& another)
	{
		string a = text;
		string b = another.text;
		if (a.find(b) != EOF)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool String::EndsWith(const String& another) const
	{
		string a = text;
		if (a.rfind(another.text) != -1 && a[length] == another.text[another.length])
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool String::Equals(const String& another)
	{
		if (strcmp(text, another.text) == 0)
		{
			cout << "true" << "\n";
			return true;
		}
		else if (strcmp(text, another.text) == -1)
		{
			cout << "false" << "\n";
			return false;
		}
		else if (strcmp(text, another.text) == 1)
		{
			cout << "true" << "\n";
			return true;
		}
	}
	bool String::StartsWith(const String& another) const
	{
		string a = text;
		if (a.find(another.text) != -1 && a[0] == another.text[0])
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	int String::IndexOf(char symbol) const
	{
		string a = text;
		if (a.find(symbol) != -1)
		{
			return a.find(symbol);
		}
		else
		{
			return -1;
		}
	}

	int String::LastIndexOf(char symbol) const
	{
		string a = text;
		if (a.rfind(symbol) != 1)
		{
			return a.find(symbol);
		}
		else
		{
			return -1;
		}
	}

	void String::GetLine()
	{
		cin >> text;
	}

	void String::Print()
	{
		cout << text << "\n";
	}

int main()
{
	//String a("Vlad");
	//cout << a.CompareTo("Kolya") << "\n";


	
	
}