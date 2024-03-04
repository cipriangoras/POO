#include "NumberList.h"


int main()
{
	NumberList Nrlist;
	Nrlist.Init();
	Nrlist.Add(12);
	Nrlist.Add(15);
	Nrlist.Add(17);
	Nrlist.Add(6);
	Nrlist.Print();
	Nrlist.Sort();
	Nrlist.Print();
}