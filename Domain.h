#pragma once
#include <string>

class Melodie
{
private:
	int id;
	std::string titlu;
	std::string artist;
	int rank;

public:

	Melodie(int id, const std::string& titlu, std::string& artist, int rank) : id{ id }, titlu{ titlu }, artist{ artist },  rank{ rank } {}

	~Melodie() = default;

	Melodie& operator=(const Melodie& mld) = default;

	bool operator==(const Melodie& mld) const;

	int get_id() const;

	const std::string& get_titlu() const;

	const std::string& get_artist() const;

	int get_rank() const;

	void set_titlu(const std::string& titluN);

	void set_rank(int rankN);
};