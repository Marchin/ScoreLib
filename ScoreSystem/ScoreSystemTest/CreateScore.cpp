#include "stdafx.h"
#include "CppUnitTest.h"
#include "../ScoreLib/ScoreSystem.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace scoreSystem {
	TEST_CLASS(CreateScoreClass) {
public:

	TEST_METHOD(CreateScore) {
		unsigned int size = 15;
		ScoreSystem highscore(size);
		for (int i = 0; i < size; i++) {
			Score score = highscore.GetScore(i);
			Assert::AreEqual(score._name.c_str(), "(Empty)");
			Assert::AreEqual(score._value, 0);
		}
	}

	TEST_METHOD(AddAScore) {
		unsigned int size = 15;
		ScoreSystem highscore(size);
		Assert::IsTrue(highscore.AddScore("pepe", 10));
		Score score = highscore.GetScore(0);
		Assert::AreEqual(score._name.c_str(), "pepe");
		Assert::AreEqual(score._value, 10);
	}

	TEST_METHOD(AddTooLowScore) {
		unsigned int size = 15;
		ScoreSystem highscore(size);
		for (int i = 0; i < size; i++) {
			Assert::IsTrue(highscore.AddScore("pepe", 10));
		}
		//Assert::IsFalse(highscore.AddScore("juan", 12));
	}

	};
}