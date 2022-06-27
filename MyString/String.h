#pragma once
#include <iostream>
#include <string>
using namespace std;

class String
{
	char* text = nullptr;
	unsigned int length = 0;
	unsigned int capacity = 80;

public:
    String();

	String(const char* text);

	explicit String(unsigned int capacity);

	String(const String& original);

	String(const char* text, unsigned int capacity);

	~String();

	// геттеры-сеттеры
	string GetString() const;

	void SetString(const char* text, unsigned int capacity);

	int GetLength() const;

	int GetCapacity() const;

	char GetCharAt(unsigned int index) const;

	int CompareTo(const String& another);

	void Clear();

	void ShrinkToFit();
	
	void ShowInfo() const;

	void Concat(const String& another);

	bool Contains(const String& another);

	bool EndsWith(const String& another) const;

	bool Equals(const String& another);

	bool StartsWith(const String& another) const;

	int IndexOf(char symbol) const;

	int LastIndexOf(char symbol) const;

	void GetLine();

	void Print();
};
	
