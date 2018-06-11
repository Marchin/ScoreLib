#pragma once
#include <string>
#include <iostream>

namespace scoreSystem {

	struct Score {
		std::string _name;
		int _value;
	};

	class ScoreSystem {
	public:
		ScoreSystem(unsigned int size);
		~ScoreSystem();
		unsigned int GetSize();
		bool AddScore(std::string name, int score);
		Score GetScore(unsigned int index) const;
		void PrintScore(std::string name);
		void PrintScoreList();
		void RemoveScore(unsigned int index);
	private:
		unsigned int m_size;
		Score* m_scoreArray;
	};
}
