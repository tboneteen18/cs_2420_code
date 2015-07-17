#pragma once
class queue
{
public:
	static const int CAPACITY = 30;
	queue();
	~queue();
	void pop();
	void push(const int& entry);
	bool empty() const { return (count == 0); }
	int top() const;
	int size() const { return count; }
private:
	int data[CAPACITY]; 
	int first; 
	int last;  
	int count; 
	int next_index(int i) const { return (i + 1) % CAPACITY; }
};
