// BLOG LINK : https://codeforces.com/blog/entry/13225

//LIS for full array
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

// LIS for every index as a higest number
vector<int> LIS(vector<int>& a) {
	vector<int> lis,ans;
	for(auto &it:a){
		int indx = upper_bound(lis.begin(),lis.end(),it)-lis.begin();
		if(indx==(int)lis.size()) lis.push_back(it);
		else lis[indx] = it;
		ans.push_back(indx+1);
	}
	return ans;
}
