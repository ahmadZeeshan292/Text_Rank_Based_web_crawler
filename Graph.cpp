#include "Graph_list.h"

void Graph_list::insert_vertix(std::string s)
{
	auto it = find(start.begin(), start.end(), s);

	if (it == start.end()) start.push_back(s);
	          
}

void Graph_list::insert_edge(std::string source, std::string destination)
{
	auto it_s = find(start.begin(), start.end(), source);
	auto it_d = find(start.begin(), start.end(), destination);

	if (it_s == start.end() || it_d == start.end()) return;        // 3

	it_s->s.push_back(destination);                  // 1                  
}

void Graph_list::del_vertix(std::string s)
{
	auto it = find(start.begin(), start.end(), s);

	if (it == start.end()) return;

	start.erase(it, next(it));

	auto it_s = start.begin();

	while (it_s != start.end()) {
		if (find(it_s->s.begin(), it_s->s.end(), s) != it_s->s.end()) {
			it_s->s.remove(s);
		}
		it_s++;
	}
}

void Graph_list::del_egde(std::string source, std::string destination)
{
	auto it_s = find(start.begin(), start.end(), source);
	auto it_d = find(start.begin(),start.end(),destination);

	if (it_s == start.end() || it_d == start.end()) return;

	it_s->s.remove(destination);
}

bool Graph_list::Graphisempty()
{
	return start.size() == 0 ? true : false;
}

int Graph_list::vertex_num()
{
	return start.size();
}

int Graph_list::edge_num()
{
	int count = 0;
	for (auto val : start) {
		count += val.s.size();
	}
	return count;
}

bool Graph_list::edge_exist(std::string source, std::string destination)
{
	auto it_s = find(start.begin(), start.end(), source);
	auto it_d = find(start.begin(), start.end(), destination);

	if (it_s == start.end() || it_d == start.end()) return false;

	auto it_s_nei = find((*it_s).s.begin(), (*it_s).s.end(), destination);

	if (it_s_nei != (*it_s).s.end()) return true;

	return false;
}

bool Graph_list::vertex_exist(std::string a)
{
	auto it = find(start.begin(), start.end(), a);

	return it != start.end() ? true : false;
}

// should be an an BFS 
std::string Graph_list::shortest_path(std::string source, std::string destination)
{
	std::string path;
	std::queue<std::string> myq;
	std::vector<std::string> seen;

	myq.push(source);
	seen.push_back(source);

	while (!myq.empty()) {
		std::string current_vertix = myq.front();

		path += current_vertix;

		std::list<std::string> neighbours = (*find(start.begin(), start.end(), current_vertix)).s;

		for (auto nei : neighbours) {
			if (find(seen.begin(), seen.end(), nei) != seen.end()) {
				if (nei == destination) {
					path += destination;
					return path;
				}
				seen.push_back(nei);
				myq.push(nei);
			}
		}
		myq.pop();
	}
}



