#include "Domain.h"

bool Melodie::operator==(const Melodie& mld) const
{
	return this->id == mld.id;
}

int Melodie::get_id() const
{
	return id;
}

const std::string& Melodie::get_titlu() const
{
	return titlu;
}

const std::string& Melodie::get_artist() const
{
	return artist;
}

int Melodie::get_rank() const
{
	return rank;
}

void Melodie::set_titlu(const std::string& titluN)
{
	titlu = titluN;
}

void Melodie::set_rank(int rankN)
{
	rank = rankN;
}