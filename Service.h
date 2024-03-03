#pragma once
#include "Repository.h"
#include "Undo.h"

class Service
{
private:
	Repository& repo;
	std::vector<ActiuneUndo*> actiuni;

public:

	Service(Repository& repo) : repo{ repo } {};

	~Service()
	{
		for (auto& a : actiuni)
			delete a;
	}

	const std::vector<Melodie>& get_all_service();

	int cate_cu_acelasi_rank(const Melodie& mld) const;

	void modifica_titlu_si_rank_serv(int id, const std::string titluN, int rankN);

	void sterge_melodie_serv(int id);

	int cate_cu_acest_rank(int rank);

	void undo();
};