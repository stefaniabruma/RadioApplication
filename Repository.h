#pragma once
#include "Domain.h"
#include <vector>
#include <fstream>
#include <algorithm>

class Repository
{
private:

	std::vector<Melodie> melodii;
	std::string filename;

	void readFromFile();
	void writeToFile();

public:

	Repository(const std::string& filename) : filename{ filename } { readFromFile(); }

	~Repository() = default;

	Repository& operator=(const Repository& repo) = delete;

	const std::vector<Melodie>& get_all_repo();

	void modifica_titlu_si_rank_repo(int id, const std::string& titlu, int rank);

	void sterge_melodie_repo(const Melodie& mld);

	void adauga_melodie_repo(const Melodie& mld);
};