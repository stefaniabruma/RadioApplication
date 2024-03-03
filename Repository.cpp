#include "Repository.h"
#include <qwidget.h>
void Repository::readFromFile()
{
	std::ifstream fin(filename);

	if (!fin.is_open())
		throw(std::exception("open()"));

	while (!fin.eof())
	{
		int id;
		fin >> id;

		if (fin.eof())
			break;

		std::string titlu;
		fin >> titlu;

		std::string artist;
		fin >> artist;

		int rank;
		fin >> rank;

		Melodie mld{ id, titlu, artist, rank };
		melodii.push_back(mld);

		sort(melodii.begin(), melodii.end(), [](const Melodie& mld1, const Melodie& mld2) {return mld1.get_rank() < mld2.get_rank(); });
	}

	fin.close();
}

void Repository::writeToFile()
{
	std::ofstream fout(filename);

	if (!fout.is_open())
		throw(std::exception("open()"));

	for (const Melodie& mld : melodii)
	{
		fout << mld.get_id() << '\n';
		fout << mld.get_titlu() << '\n';
		fout << mld.get_artist() << '\n';
		fout << mld.get_rank() << '\n';

		fout << '\n';
	}

	fout.close();
}

const std::vector<Melodie>& Repository::get_all_repo()
{
	return melodii;
}

void Repository::modifica_titlu_si_rank_repo(int id, const std::string& titlu, int rank)
{
	for(Melodie& mld : melodii)
		if (mld.get_id() == id)
		{
			mld.set_titlu(titlu);
			mld.set_rank(rank);
			break;
		}

	sort(melodii.begin(), melodii.end(), [](const Melodie& mld1, const Melodie& mld2) {return mld1.get_rank() < mld2.get_rank(); });

	writeToFile();
}

void Repository::sterge_melodie_repo(const Melodie& mld)
{
	auto it = find(melodii.begin(), melodii.end(), mld);

	melodii.erase(it);

	writeToFile();
}

void Repository::adauga_melodie_repo(const Melodie& mld)
{
	melodii.push_back(mld);
	sort(melodii.begin(), melodii.end(), [](const Melodie& mld1, const Melodie& mld2) {return mld1.get_rank() < mld2.get_rank(); });
	writeToFile();

}

