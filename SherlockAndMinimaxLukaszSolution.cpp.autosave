#include <cstdio>
#include <algorithm>

using namespace std;

int t[10000];

int solve(int p, int q, int n)
{
	if (q <= t[0]) return p;
	if (p >= t[n - 1]) return q;

	pair<int, int> best = {0, 0};
	if (p <= t[0]) best = {t[0] - p, p};
	for (int i = 0; i + 1 < n; i++)
	{
		int s = t[i] + t[i + 1];
		s /= 2;
		if (p <= s && s <= q)
		{
			if (s - t[i] > best.first) best = {s - t[i], s};
		}
		else if (t[i] <= p && p <= t[i + 1])
		{
			if (p < s) if (p - t[i] > best.first) best = {p - t[i], p};
			if (p > s) if (t[i + 1] - p > best.first) best = {t[i + 1] - p, p};
		}
		else if (t[i] <= q && q <= t[i + 1])
		{
			if (q < s) if (q - t[i] > best.first) best = {q - t[i], q};
			if (q > s) if (t[i + 1] - q > best.first) best = {t[i + 1] - q, q};
		}
	}
	if (q >= t[n - 1]) if (q - t[n - 1] > best.first) best = {q - t[n - 1], q};
	return best.second;
}

int main()
{
	int n, p, q;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", t + i);
	}
	scanf("%d%d", &p, &q);
	sort(t, t + n);
	printf("%d\n", solve(p, q, n));

	return 0;

}
