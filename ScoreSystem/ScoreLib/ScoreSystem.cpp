#include "ScoreSystem.h"

namespace scoreSystem {

	ScoreSystem::ScoreSystem(unsigned int size = 10) {
		m_size = size;
		m_scoreArray = new Score[m_size];
		/*for (int i = 0; i < m_size; i++) {
			m_scoreArray[i]._name = "(Empty)";
			m_scoreArray[i]._value = 0;
		}*/
	}

	ScoreSystem::~ScoreSystem() {
		delete[] m_scoreArray;
	}

	unsigned int ScoreSystem::GetSize() const {
		return m_size;
	}

	bool ScoreSystem::AddScore(const std::string& name, const int score) {
		if (score < m_scoreArray[m_size]._value) {
			return false;
		} else if (score > m_scoreArray[0]._value) {
			
		}
		int i = m_size - 1;
		while ((score > m_scoreArray[i]._value) && i > 0) {
			i--;
		}
		if (score > m_scoreArray[i]._value) {
			int j = i;
			while (j < (m_size - 1)) {
				m_scoreArray[j + 1]._name
					= m_scoreArray[j]._name;
				m_scoreArray[j + 1]._value
					= m_scoreArray[j]._value;
				j++;
			}
			m_scoreArray[i]._name = name;
			m_scoreArray[i]._value = score;
			return true;
		} else if (score < m_scoreArray[i]._value
			&& (i < m_size - 1)) {

			int j = i + 1;
			while (j < (m_size - 1)) {
				m_scoreArray[j + 1]._name
					= m_scoreArray[j]._name;
				m_scoreArray[j + 1]._value
					= m_scoreArray[j]._value;
				j++;
			}
			m_scoreArray[i]._name = name;
			m_scoreArray[i]._value = score;
			return true;
		} else {
			return false;
		}
	}

	Score ScoreSystem::GetScore(unsigned int index) const {
		return m_scoreArray[index];
	}

	void ScoreSystem::PrintScore(const std::string& name) {
		for (int i = 0; i <= m_size; i++) {
			if (i == m_size) {
				std::cout << "Name not Found" << std::endl;
			} else if (m_scoreArray[i]._name == name) {
				std::cout << name << ": "
					<< m_scoreArray[i]._value << std::endl;
				break;
			}
		}
	}

	void ScoreSystem::PrintScoreSystem() {
		for (int i = 0; i < m_size; i++) {
			std::cout << m_scoreArray[i]._name << ": "
				<< m_scoreArray[i]._value << std::endl;
		}
	}

	void ScoreSystem::RemoveScore(unsigned int index) {
		while (index < (m_size - 1)) {
			m_scoreArray[index] = m_scoreArray[index + 1];
			index++;
		}
		m_scoreArray[index - 1]._name = "(Empty)";
		m_scoreArray[index - 1]._value = 0;
	}

	void ScoreSystem::ShiftDownSystem(const unsigned int index, const unsigned int amount) {
		if (index > (m_size - 1)) {
			throw std::out_of_range("Index out of range");
		}
		for (int i = m_size - 1; i >= (index - amount); i--) {
			if ((i - amount) < index) {
				m_scoreArray[i] = Score();
			} else {
				m_scoreArray[i] = m_scoreArray[i - amount];
			}
		}
		for (int i = 0; i < amount; i++) {
			m_scoreArray[index - i] = Score();
		}
	}

}