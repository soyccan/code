#include "Gift.h"

int AnnGuess(int N)
{
	/*
	* 以下是一個範例程式碼，在N=3時會通過測試。
	* 開始解題時，請你刪除以下程式碼，想一個較好的方法解題。
	* 注意: 你必須自行引入你需要使用的函式庫(#include <XXX.h>)，並且不能輸出任何東西至標準輸出。
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