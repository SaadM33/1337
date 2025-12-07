
#pragma once

template <typename T, typename F>
void	iter(T *arr, const int len, F func)
{
	for (int i = 0; i < len; i++)
	{
		func(arr[i]);
	}	
}