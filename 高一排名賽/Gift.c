#include "Gift.h"

int AnnGuess(int N)
{
	/*
	* �H�U�O�@�ӽd�ҵ{���X�A�bN=3�ɷ|�q�L���աC
	* �}�l���D�ɡA�ЧA�R���H�U�{���X�A�Q�@�Ӹ��n����k���D�C
	* �`�N: �A�����ۦ�ޤJ�A�ݭn�ϥΪ��禡�w(#include <XXX.h>)�A�åB�����X����F��ܼзǿ�X�C
	*/
	int arr[1];

	arr[0]=0;
	if(AskNana(1,arr))
		return 0;
	arr[0]=1;
	if(AskNana(1,arr))
		return 1;
	arr[0]=2;
	if(AskNana(1,arr))
		return 2;
}