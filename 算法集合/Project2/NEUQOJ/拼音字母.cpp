#include<iostream>
#include<string>
#include<locale>

using namespace std;

wstring wstr;
wchar_t index[] = {
	'°¡', '°Å', '²Á', '´î', '¶ê', '·¢', '¸Á',
	'¹þ', '»÷', '»÷', '¿¦', 'À¬', 'Âè', 'ÄÃ',
	'Å¶', 'Å¾', 'ÆÚ', 'È»', 'Èö', 'Ëú', 'ÍÚ',
	'ÍÚ', 'ÍÚ', 'Îô', 'Ñ¹', 'ÔÑ',
};



int main()
{
	int n;
	int v;
	cin >> n;
	wcin.imbue(locale("chs"));
	wcout.imbue(locale("chs"));
	for (int i = 0; i != n; ++i)
	{
		wcin >> wstr;
		for (int j = 0; j != wstr.size(); ++j)
		{
			for (int k = 25; k != -1; --k)
			{
				v = (int)wstr[j];
				if (v >= index[k])
				{
					wcout << char('A' + k); break;
				}
			}
		}
		wcout << endl;
	}
	return 0;
}