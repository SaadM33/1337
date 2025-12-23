
#include "PmergeMe.hpp"

double	get_time_u()
{
	struct timeval	tv;
	
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

double	sort_vector(std::vector<int> &vec)
{
	if (vec.size() <= 1)
		return 0;
	
	double	start_time = get_time_u();
	std::sort(vec.begin(), vec.end());


	return (get_time_u() - start_time);
}

double	sort_deque(std::deque<int> &deq)
{
	if (deq.size() <= 1)
		return 0;
	
	double	start_time = get_time_u();
	std::sort(deq.begin(), deq.end());

	
	return (get_time_u() - start_time);
}