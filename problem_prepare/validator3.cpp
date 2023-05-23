#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
	registerValidation(argc, argv);

	int t = inf.readInt(1, 1e5);
	inf.readEoln();

	for (int i = 0; i < t; i++)
	{
		int n = inf.readInt(3, 200 * 1000, "n");
		inf.readEoln();
		inf.readInts(n, 1, 1000 * 1000 * 1000, "a");
		inf.readEoln();
	}
	inf.readEof();
}