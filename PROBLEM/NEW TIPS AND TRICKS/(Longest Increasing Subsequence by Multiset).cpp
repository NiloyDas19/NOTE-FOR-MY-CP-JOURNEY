// BLOG LINK : https://codeforces.com/blog/entry/13225

ll LIS_BY_MULTISET(vector<ll> &a)
{
	multiset<ll> s;
	for (ll i = 0; i < a.size(); i++)
	{
		s.insert(a[i]);
		auto it = s.upper_bound(a[i]);
		if (it != s.end())
			s.erase(it);
	}
	return (ll)s.size();
}