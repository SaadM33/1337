
#include "PmergeMe.hpp"

double	get_time_u()
{
	struct timeval	tv;
	
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

int		jacobsthal(int k)
{
	if (k == 0)
		return 0;
	else if (k == 1)
		return 1;
	else
		return jacobsthal(k - 1) + 2 * jacobsthal(k - 2);
}

bool	compareSecond(std::pair<int, int>& a, std::pair<int, int>& b)
{
	return a.second < b.second ;
}


void	sort_vector(std::vector<int> &vec)
{
	if (vec.size() <= 1)
		return ;

	std::vector<std::pair<int, int> >	pairs;
	sort_pairs(vec, pairs);
	

	std::vector<int>	sorted;
	for (size_t i = 0; i < pairs.size(); i++)
		sorted.push_back(pairs[i].second);
	sorted.insert(sorted.begin(), pairs[0].first);
	
	insert_jacobs(sorted, pairs);

	if (vec.size() % 2 == 1)
	{
		int	last = vec[vec.size() - 1];
		std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), last);
		sorted.insert(pos, last);
	}
	
	vec = sorted;
}

void	sort_deque(std::deque<int> &deq)
{
	if (deq.size() <= 1)
		return ;
	
	std::deque<std::pair<int, int> >	pairs;
	sort_pairs(deq, pairs);

	std::deque<int>	sorted;

	for (size_t i = 0; i < pairs.size(); i++)
		sorted.push_back(pairs[i].second);
	sorted.push_front(pairs[0].first);

	insert_jacobs(sorted, pairs);

	if (deq.size() % 2 == 1)
	{
		int	last = deq[deq.size() - 1];
		std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), last);
		sorted.insert(pos, last);
	}

	deq = sorted;
}