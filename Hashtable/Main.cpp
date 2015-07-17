//I <tyler> have not used any code other than my own(or that in the textbook) for this project.
//I also have not used any function or data - structure from the Standard - Template Library.
//I understand that any violation of this disclaimer will result in a 0 for the project.
#pragma once
#include <cctype>
#include <cstdlib>
#include <iostream>
#include "Hash_Table.h"
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

double get_total_weight(Hash_Table &hash_table, string line_input, int i);

void read_in_table(Hash_Table &hash_table, string line_input);

int main()
{
	string line_input;
	Hash_Table hash_table;
	string pathway = "PeriodicTableElements.txt";
	ifstream input;
	input.open(pathway);
	if (input.fail())
	{
		cerr << "Could not open input file." << endl;
		system("PAUSE");
		exit(0);
	}
	while (input.peek() != EOF)
	{
		getline(input, line_input, '\n');
		read_in_table(hash_table, line_input);
	}
	input.close();
	string pathway1 = "formulas.txt";
	ifstream input1;
	input1.open(pathway1);
	if (input1.fail())
	{
		cerr << "Could not open formula file." << endl;
		system("PAUSE");
		exit(0);
	}
	while (input1.peek() != EOF)
	{
		getline(input1, line_input, '\n');
		double total_weight = get_total_weight(hash_table, line_input, 0);
		cout << line_input << " = " << total_weight << endl;
	}
	input1.close();
	cout << endl;
	system("PAUSE");
	return EXIT_SUCCESS;
}
void read_in_table(Hash_Table &hash_table, string line_input)
{
	double weight;
	int element_number;
	char element[4];
	sscanf_s(line_input.c_str(), "%d %3[^ ] %lf", &element_number, &element, 3, &weight);
	hash_table.insert(element, weight, element[0]);
}
double get_total_weight(Hash_Table &hash_table, string line_input, int i)
{
	int j;
	int multiplier;
	double total_weight = 0.0;
	double weight;
	while (line_input[i] != '\0')
	{
		j = i;
		if (line_input[i] == '(')
		{
			++i;
			int k = i;
			while (line_input[k + 1] != ')')
				k++;
			string line_help = line_input.substr(i, k - i + 1);
			weight = get_total_weight(hash_table, line_help, 0);
			i = k + 2;
			if (line_input[i] == '\0')
				total_weight = total_weight + weight * 1;
		}
		else
		{
			while (islower(line_input[i + 1]))
				i++;
			int k = i - j + 1;
			string element = line_input.substr(j, k);
			double element_number = element[0] - 0;
			weight = hash_table.retrieve(element_number, element);
			++i;
			if (!(isdigit(line_input[i])))
				total_weight = total_weight + weight * 1;
		}
		j = i;
		while (isdigit(line_input[i]))
			i++;
		int k = i - j;
		string line_input_passer = line_input.substr(j, k);
		istringstream convert(line_input_passer);
		if (!(convert >> multiplier))
			multiplier = 0;
		total_weight = total_weight + weight*multiplier;
	}
	return total_weight;
}