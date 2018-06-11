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
		for (unsigned int i = 0; i < size; i++) {
			Score score = highscore.GetScore(i);
			Assert::AreEqual(score._name, "(Empty)");
			Assert::AreEqual(score._value, 0);
		}
	}

	TEST_METHOD(AddAScoreInEmpty) {
		unsigned int size = 15;
		ScoreSystem highscore(size);
		Assert::IsTrue(highscore.AddScore("pepe", 10));
		Score score = highscore.GetScore(0);
		Assert::AreEqual(score._name, "pepe");
		Assert::AreEqual(score._value, 10);
	}

	TEST_METHOD(AddScoreInFull) {
		unsigned int size = 3;
		ScoreSystem highscore(size);
		for (unsigned int i = 5; i < size + 5; i++) {
			Assert::IsTrue(highscore.AddScore("pepe", i));
		}
		Assert::IsFalse(highscore.AddScore("juan", 4));
		Assert::IsTrue(highscore.AddScore("oliver", 5));
		Assert::IsTrue(highscore.AddScore("oscar", 6));
		Assert::IsTrue(highscore.AddScore("ramon", 8));
	}

	};
}