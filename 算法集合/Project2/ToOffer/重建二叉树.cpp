#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

template<typename T>
struct node
{
	node<T>* l;
	node<T>* r;
	T v;
};

template<typename T>
node<typename T::value_type>* rebulid_tree(typename T::iterator prestarter, typename T::iterator preender,
																				typename T::iterator instarter, typename T::iterator inender)
{
	if (prestarter == preender)
		return 0;
	else
	{
		node<T::value_type>* parent = new node < T::value_type > ;
		parent->v = *prestarter;
		int leftsize = find(instarter, inender, parent->v) - instarter;
		int rightsize = preender - prestarter - leftsize - 1;
		if (rightsize < 0)
			throw runtime_error("Input Array is no an Tree !!");
		parent->l = rebulid_tree<T>(prestarter + 1, prestarter + leftsize + 1, instarter, instarter + leftsize);
		parent->r = rebulid_tree<T>(preender - rightsize, preender, inender - rightsize, inender);
		return parent;
	}
}

template<typename T>
node<T>* rebulid_tree(T* prestarter, T* preender, T* instarter, T * inender)
{
	if (prestarter == preender ||
		prestarter == 0 || preender == 0 ||
		instarter == 0 || inender == 0)
		return 0;
	else
	{
		node<T>* parent = new node < T > ;
		parent->v = *prestarter;
		int leftsize = find(instarter, inender, parent->v) - instarter;
		int rightsize = preender - prestarter - leftsize - 1;
		if (rightsize < 0)
			throw runtime_error("Input Array is no an Tree !!");
		parent->l = rebulid_tree(prestarter + 1, prestarter + leftsize + 1, instarter, instarter + leftsize);
		parent->r = rebulid_tree(preender - rightsize, preender, inender - rightsize, inender);
		return parent;
	}
}



int main()
{
	int prearry[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int inarry[] = { 4, 7, 2, 1, 3, 5, 8, 6 };
	vector<int> v1(prearry, prearry + 8), v2(inarry, inarry + 8);
	node<int>* root;
	try{
		root = rebulid_tree(prearry, prearry + 8, inarry, inarry + 8);
		v1[4] = 0;
		root = rebulid_tree<vector<int> >(v1.begin(), v1.end(), v2.begin(), v2.end());
	}
	catch (exception e){
		cout << "error!  " << e.what();
	}
	return 0;
}