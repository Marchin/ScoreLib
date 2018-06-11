#pragma once
#include <string>
#include <iostream>

namespace scoreSystem {

	struct Score {
		std::string _name = "(Empty)";
		int _value = 0;
	};

	class ScoreSystem {
	public:
		ScoreSystem(const unsigned int size);
		~ScoreSystem();
		unsigned int GetSize() const;
		bool AddScore(const std::string& name,const int score);
		Score GetScore(unsigned int index) const;
		void PrintScore(const std::string& name);
		void PrintScoreSystem();
		void RemoveScore(const unsigned int index);
	private:
		void ShiftDownSystem(const unsigned int index, const unsigned int amount);
		unsigned int m_size;
		Score* m_scoreArray;
	};
}
