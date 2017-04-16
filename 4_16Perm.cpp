#include<cstdio>
#include<cstring>
#define MAX 10
using namespace std;
#pragma warning(disable:4996)
void swap(char str[], int i, int j)
{
	int temp;
	temp = str[i];
	str[i] = str[j];
	str[j] = temp;
}

void perm(char str[], int k, int m)
{
	int i;
	if (k>m)
	{
		for (i = 0; i <= m; i++)
			printf("%c", str[i]);
		printf("\n");
	}
	else
	{
		for (i = k; i <= m; i++)
		{
			swap(str, k, i);
			perm(str, k + 1, m);
			swap(str, k, i);
		}
	}
}

int main(int argc, char *argv[])
{
	/*char str[3];
	while (scanf("%s", str) != EOF)
	{
		int len = strlen(str);
		perm(str, 0, len - 1);
		printf("\n");
	}*/
	char str[3] = {'a','b','c'};
	perm(str,0, 2);

	return 0;
}