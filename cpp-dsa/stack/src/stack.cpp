#include <iostream>
#include <fmt/core.h>

class Node {
public:
	int value;
	Node* next;
	Node(int value)
	{
		this->value = value;
		next = nullptr;
	}
};

class Stack{
private:
	Node* top;
	int height;
public:
	Stack(int value)
	{
		Node* newNode = new Node(value);
		top = newNode;
		height = 1;
	}
	~Stack()
	{
		Node* temp = top;
		while (top != nullptr)
		{
			top = top->next;
			delete temp;
			temp = top;
		}
	}
	void printStack()
	{
		Node* temp = top;
		while (temp != nullptr)
		{
			fmt::print("{} ", temp->value);
			temp = temp->next;
		}
		fmt::print("\n");
	}
	Node* getTop()
	{
		return top;
	}
	int topValue()
	{
		if (top != nullptr) return top->value;
		return INT_MIN;
	}
	int getHight()
	{
		return height;
	}
	void makeEmpty()
	{
		Node* temp;
		while (top != nullptr)
		{
			temp = top;
			top = top->next;
			delete temp;
		}
		height = 0;
	}
	void push(int value)
	{
		Node* newNode = new Node(value);
		newNode->next = top;
		top = newNode;
		height++;
	}
	int pop()
	{
		if (height == 0) return INT_MIN;
		Node* temp = top;
		int poppedValue = top->value;
		top = top->next;
		delete temp;
		height--;
		return poppedValue;
	}
};

int main()
{
	fmt::print("Creating stack with initial value 4\n");
	Stack myStack(4);

	fmt::print("Initial stack:\n");
	myStack.printStack();
	fmt::print("\n\n");

	fmt::print("Push 10\n");
	myStack.push(10);
	myStack.printStack();
	fmt::print("\n\n");

	fmt::print("Push 20\n");
	myStack.push(20);
	myStack.printStack();
	fmt::print("\n\n");

	fmt::print("Top value: {}\n\n", myStack.topValue());

	fmt::print("Pop value: {}\n", myStack.pop());
	myStack.printStack();
	fmt::print("\n\n");

	fmt::print("Pop value: {}\n", myStack.pop());
	myStack.printStack();
	fmt::print("\n\n");

	fmt::print("Stack height: {}\n\n", myStack.getHight());

	fmt::print("Emptying stack...\n");
	myStack.makeEmpty();

	fmt::print("Stack height after empty: {}\n", myStack.getHight());

	return 0;
}
