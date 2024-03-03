#pragma once
#include "Repository.h"
class ActiuneUndo
{
public:

	virtual void doUndo() = 0;
	
	virtual ~ActiuneUndo() {};
};

class UndoSterge : public ActiuneUndo
{
private:
	Melodie mldStearsa;
	Repository& repo;

public:

	UndoSterge(const Melodie& mld, Repository& repo) : mldStearsa{ mld }, repo{ repo } {}

	void doUndo() override
	{
		repo.adauga_melodie_repo(mldStearsa);
	}
};

class UndoModifica : public ActiuneUndo
{
private:
	Repository& repo;
	int idMldMod;
	int rankVechi;
	std::string titluVechi;
public:
	
	UndoModifica(Repository& repo, int idMld, std::string titluVechi, int rankVechi) : repo{ repo }, idMldMod{ idMld }, titluVechi { titluVechi }, rankVechi{ rankVechi } {}

	void doUndo() override
	{
		repo.modifica_titlu_si_rank_repo(idMldMod, titluVechi, rankVechi);
	}
};