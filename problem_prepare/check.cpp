#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int findans(vector<int> a)
{
}
int main(int argc, char *argv[])
{
	registerTestlibCmd(argc, argv);

	int t = inf.readInt();

	for (int i = 0; i < t; ++i)
	{
		int n = inf.readInt();
		vector<int> a(n);
		for (int i = 0; i < n; ++i)
			a[i] = inf.readInt();

		int jans = readAnswer(ans);

		int pans = readAnswer(ouf);
	}

	int pans = readAnswer(ouf);

	if (jans == -1)
	{
		if (pans != -1)
			quitf(_fail, "Participant found answer but jury doesn't");
	}
	else
	{
		if (pans == -1)
			quitf(_wa, "Jury found answer but participant doesn't");
	}

	quitf(_ok, "%d", pans);
}
