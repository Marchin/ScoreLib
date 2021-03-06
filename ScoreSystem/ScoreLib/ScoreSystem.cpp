#include "ScoreSystem.h"

namespace scoreSystem {

	ScoreSystem::ScoreSystem(unsigned int size = 10) {
		m_size = size;
		m_scoreArray = new Score[m_size];
	}

	ScoreSystem::~ScoreSystem() {
		delete[] m_scoreArray;
	}

	unsigned int ScoreSystem::GetSize() const {
		return m_size;
	}

	bool ScoreSystem::AddScore(const char* name, const int score) {
		if (score < m_scoreArray[m_size - 1]._value) {
			return false;
		} else if (score >= m_scoreArray[0]._value) {
			ShiftDownSystem(0, 1);
			strcpy_s(m_scoreArray[0]._name, sizeof(Score::_name), name);
			m_scoreArray[0]._value = score;
			return true;
		} else {
			int iter = m_size - 1;
			while ((score >= m_scoreArray[iter - 1]._value) && (iter > 1)) {
				iter--;
			}
			ShiftDownSystem(iter, 1);
			strcpy_s(m_scoreArray[iter]._name, sizeof(Score::_name), name);
			m_scoreArray[iter]._value = score;
			return true;
		}
	}

	Score ScoreSystem::GetScore(unsigned int index) const {
		return m_scoreArray[index];
	}

	Score* ScoreSystem::GetScore(const char* name, unsigned int& sizeReceiver) const {
		Score* checker = new Score[m_size];
		Score* coincidences;
		unsigned int& counter = sizeReceiver;
		counter = 0;
		for (unsigned int i = 0; i < m_size; i++) {
			if (strcmp(m_scoreArray[i]._name,name) == 0) {
				checker[counter] = m_scoreArray[i];
				counter++;
			}
		}
		if (counter == 0) {
			coincidences = nullptr;
		} else {
			coincidences = new Score[counter];
			for (int i = 0; i < counter; i++) {
				coincidences[i] = checker[i];
			}
		}
		delete checker;
		return coincidences;
	}

	void ScoreSystem::RemoveScore(unsigned int index) {
		if (index >(m_size - 1)) {
			throw std::out_of_range("Index out of range");
		}
		while (index < m_size) {
			m_scoreArray[index] = m_scoreArray[index + 1];
			index++;
		}
		strcpy_s(m_scoreArray[index - 1]._name, sizeof(Score::_name),"(Empty)");
		m_scoreArray[index - 1]._value = 0;
	}

	void ScoreSystem::ShiftDownSystem(const unsigned int index, const unsigned int amount) {
		if (index > (m_size - 1)) {
			throw std::out_of_range("Index out of range");
		}
		for (unsigned int i = m_size - 1; i >= (index + amount); i--) {
			if ((i - amount) < index) {
				m_scoreArray[i] = Score();
			} else {
				m_scoreArray[i] = m_scoreArray[i - amount];
			}
		}
		for (unsigned int i = 0; i < amount; i++) {
			m_scoreArray[index - i] = Score();
		}
	}

}