#include <iostream>
#include <fmt/core.h>
#include <string>
#include <vector>
using namespace std;

class Node {
public:
	string key;
	int value;
	Node* next;
	Node(string key, int value)
	{
		this->key = key;
		this->value = value;
		next = nullptr;
	}
};
class HashTable {
private:
	static const int SIZE = 7;
	Node* dataMap[SIZE];
	int hash(string key)
	{
		int hash = 0;
		for (int i = 0; i < key.length(); ++i)
		{
			int asciiValue = int(key[i]);
			hash = (hash + asciiValue * 23) % SIZE;
		}
		return hash;
	}
public:
	HashTable()
	{
		for (int i = 0; i < SIZE; ++i)
			dataMap[i] = nullptr;
	}
	~HashTable()
	{
		for (int i = 0; i < SIZE; ++i)
		{
			Node* head = dataMap[i];
			Node* temp = head;
			while (head != nullptr)
			{
				head = head->next;
				delete temp;
				temp = head;
			}
		}
	}
	void printTable()
	{
		for (int i = 0; i < SIZE; ++i)
		{
			fmt::print("Index {} \n", i);
			if (dataMap[i])
			{
				fmt::print("Contains => ");
				Node* temp = dataMap[i];
				while (temp != nullptr)
				{
					fmt::print("{{ {} , {} }}", temp->key, temp->value);
					temp = temp->next;
					if (temp != nullptr) fmt::print(", ");
				}
				fmt::print("\n");
			}
			else
			{
				fmt::print("Empty");
			}
		}
	}
	void set(string key, int value)
	{
		int index = hash(key);
		Node* newNode = new Node(key, value);
		if (dataMap[index] == nullptr)
		{
			dataMap[index] = newNode;
		}
		else
		{
			Node* temp = dataMap[index];
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}
	int get(string key)
	{
		int index = hash(key);
		Node* temp = dataMap[index];
		while (temp != nullptr)
		{
			if (temp->key == key) return temp->value;
			temp = temp->next;
		}
		return 0;
	}
	vector<string> keys()
	{
		vector<string> allKeys;
		for (int i = 0; i < SIZE; ++i)
		{
			Node* temp = dataMap[i];
			while (temp != nullptr)
			{
				allKeys.push_back(temp->key);
				temp = temp->next;
			}
		}
		return allKeys;
	}
};

int main()
{
	fmt::print("===== HASH TABLE TEST =====\n\n");

	HashTable myTable;

	fmt::print("Inserting values:\n");

	myTable.set("apple", 100);
	myTable.set("banana", 200);
	myTable.set("orange", 300);
	myTable.set("grape", 400);
	myTable.set("melon", 500);

	fmt::print("\nCurrent table:\n");
	myTable.printTable();

	fmt::print("\n\nTesting get():\n");

	fmt::print("apple -> {}\n", myTable.get("apple"));
	fmt::print("banana -> {}\n", myTable.get("banana"));
	fmt::print("orange -> {}\n", myTable.get("orange"));
	fmt::print("kiwi -> {}\n", myTable.get("kiwi")); // nu există

	fmt::print("\nAll keys in table:\n");

	vector<string> allKeys = myTable.keys();

	for (const auto& key : allKeys)
	{
		fmt::print("{} ", key);
	}

	fmt::print("\n");

	return 0;
}
