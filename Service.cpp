#include "Service.h"

const std::vector<Melodie>& Service::get_all_service()
{
	return repo.get_all_repo();
}

int Service::cate_cu_acelasi_rank(const Melodie& mld) const
{
	int rank = mld.get_rank();
	int cnt = 0;

	for (const Melodie& melod : repo.get_all_repo())
		if (rank == melod.get_rank() && !(melod == mld))
			cnt++;

	return cnt;
}

void Service::modifica_titlu_si_rank_serv(int id, const std::string titluN, int rankN)
{
	auto it = find_if(repo.get_all_repo().begin(), repo.get_all_repo().end(), [id](const Melodie& mld) {return mld.get_id() == id; });
	if (it == repo.get_all_repo().end())
		throw(std::exception("Inexistenta()"));

	actiuni.push_back(new UndoModifica{ repo, id, (*it).get_titlu(), (*it).get_rank() });

	repo.modifica_titlu_si_rank_repo(id, titluN, rankN);
}

void Service::sterge_melodie_serv(int id)
{
	auto it = find_if(repo.get_all_repo().begin(), repo.get_all_repo().end(), [id](const Melodie& mld) {return mld.get_id() == id; });
	if (it == repo.get_all_repo().end())
		throw(std::exception("Inexistenta!\n"));

	Melodie mld = *(it);

	int cnt = 0;
	for (const Melodie& m : repo.get_all_repo())
		if (m.get_artist() == mld.get_artist())
			cnt++;

	if (cnt == 1)
		throw(std::exception("Ultima melodie a artistului. Nu se poate sterge!\n"));

	repo.sterge_melodie_repo(mld);

	actiuni.push_back(new UndoSterge{ mld, repo });
}

int Service::cate_cu_acest_rank(int rank)
{
	int cnt = 0;
	for (const Melodie& mld : repo.get_all_repo())
		if (mld.get_rank() == rank)
			cnt++;

	return cnt;
}

void Service::undo()
{
	auto actiune = actiuni.back();
	actiune->doUndo();

	actiuni.pop_back();
}
