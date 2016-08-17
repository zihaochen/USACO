/*
ID: zihaoch1
PROG: heritage
LANG: C++
*/
#include<fstream>
#include<cstring>
using namespace std; 

	ifstream cin("heritage.in"); 
	ofstream cout("heritage.out"); 

struct node
{
	char ch; 
	node *left, *right; 
	node(char c):ch(c)
	{
		left = right = NULL; 
	}
	node()
	{
		left = right = NULL; 
	}
};

void build(string s1, string s2, node* &root)
{
	if (s1.size() == 0) return;
	root = new node(s2[0]); 
	int i; 
	int len1 = s1.size(); 
	int len2 = s2.size(); 
	for (i = 0; i < len1; i++)
		if (s1[i] == s2[0]) 
			break;

	build(s1.substr(0, i), s2.substr(1, i), root -> left); 
	if (len1 > i + 1)
		build(s1.substr(i + 1, len1 - i - 1), s2.substr(i + 1, len1 - i - 1), root -> right); 

}

void postOrder(node *root)
{
	if (root == NULL) return;
	postOrder(root -> left); 
	postOrder(root -> right); 
	cout << root -> ch; 
}

void clear(node *root)
{
	if (root == NULL) return; 
	clear(root -> left); 
	clear(root -> right); 
	delete root; 
}

int main()
{
	string s1, s2; 
	node* root; 

	cin >> s1; //ÖÐÐò
	cin >> s2; //Ç°Ðò
	
	build(s1, s2, root); 

	postOrder(root); 
	cout << endl; 
	clear(root);
}

