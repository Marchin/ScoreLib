#pragma once
#include <string>
#include <iostream>

namespace scoreSystem {

	struct Score {
		char _name[15] = "(Empty)";
		int _value = 0;
	};

	class ScoreSystem {
	public:
		ScoreSystem(const unsigned int size);
		~ScoreSystem();
		unsigned int GetSize() const;
		bool AddScore(const char* name,const int score);
		Score GetScore(unsigned int index) const;
		void RemoveScore(const unsigned int index);
	private:
		void ShiftDownSystem(const unsigned int index, const unsigned int amount);
		unsigned int m_size;
		Score* m_scoreArray;
	};
}
