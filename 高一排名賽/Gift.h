#ifndef GIFT_H
#define GIFT_H

#include <stdio.h>
#include <stdlib.h>
int _count;
int _mylist[1000000];
int _ask_cnt=0;
int AnnGuess(int);
int main()
{
	scanf("%d",&_count);
	for(int i=0;i<_count;i++)
		scanf("%d",&_mylist[i]);
	int res=AnnGuess(_count);
	printf("Ann asked %d times and guessed #%d. ",_ask_cnt,res);
	if(res>=0 && res<_count && _mylist[res])
		puts("There is really a gift in it.");
	else
		puts("But there's no gift in it.  :(\n\nAnn will not get the gift and you'll not get any score. QAQ");
}
int AskNana(int n, int index[])
{
	_ask_cnt++;
	int i;
	for(i=0;i<n;i++)
	{
		if(index[i]<0 || index[i]>=_count)
			exit(1);
		if(_mylist[index[i]]==1)
			return 1;
	}
	return 0;
}

#endif