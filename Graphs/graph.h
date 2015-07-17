#pragma once
class graph
{
public:
	static const int MAXIMUM = 20;

	graph() { many_vertices = 0; }
	~graph();
	bool addEdge(int u, int v, double w);
	void add_vertex(const int label);
	void remove_edge(int source, int target);
	int size() { return many_vertices; }
	bool is_edge(int source, int target)const;
	int neighbors(int vertex)const;
private:
	int many_vertices;
	bool edges[MAXIMUM][MAXIMUM];
	int labels[MAXIMUM];
};