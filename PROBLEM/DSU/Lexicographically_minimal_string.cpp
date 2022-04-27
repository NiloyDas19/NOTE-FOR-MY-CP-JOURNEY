/*
https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/lexicographically-minimal-string-6edc1406/
*/

#include <iostream>
using namespace std;
int parent[26];

void make(int v){
	parent[v] = v;
}

int find(int v)
{
	if(parent[v]==v) return v;
	return parent[v]=find(parent[v]);
}

void Union(int a,int b){
	a = find(a);
	b = find(b);
	if(a!=b){
		if(a>b) 
		   swap(a,b);
		parent[b] = a;
	}
}
int main() {
	string a,b,c;
	cin >> a >> b >> c;
	for(int i=0;i<26;i++)
		make(i);
	for(int i=0;i<a.size();i++){
		int u = a[i]-'a';
		int v = b[i]-'a';
		Union(u,v);
	}
	
	for(int i=0;i<c.size();i++){
		int r = c[i]-'a';
		r = find(r);
		c[i] = r+'a';
	}

	cout << c << "\n";
}