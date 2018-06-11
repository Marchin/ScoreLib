#include "ScoreSystem.h"

namespace scoreSystem {

	ScoreSystem::ScoreSystem(unsigned int size = 10) {
		m_size = size;
		m_scoreArray = new Score[size];
		for (int i = 0; i < m_size; i++) {
			m_scoreArray[i]._name = "(Empty)";
			m_scoreArray[i]._value = 0;
		}
	}

	ScoreSystem::~ScoreSystem() {
		delete[] m_scoreArray;
	}

	unsigned int ScoreSystem::GetSize() {
		return m_size;
	}

	bool ScoreSystem::AddScore(std::string name, int score) {
		int i = m_size;
		while ((score > m_scoreArray[i - 1]._value) && i > 0) {
			i--;
		}
		return i < m_size ? true : false;
	}

	Score ScoreSystem::GetScore(unsigned int index) const {
		return m_scoreArray[index];
	}

	void ScoreSystem::PrintScore(std::string name) {
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

	void ScoreSystem::PrintScoreList() {
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
}