
#include "PmergeMe.hpp"

double	get_time_u()
{
	struct timeval	tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

int	jacobsthal(int k)
{
	if (k == 0)
		return 0;
	if (k == 1)
		return 1;
	return jacobsthal(k - 1) + 2 * jacobsthal(k - 2);
}

static void	make_pairs_vec(std::vector<int> &vec, std::vector<std::pair<int, int> > &pairs)
{
	for (size_t i = 0; i + 1 < vec.size(); i += 2)
	{
		if (vec[i] < vec[i + 1])
			pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
		else
			pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
	}

	std::vector<int> winners;
	for (size_t i = 0; i < pairs.size(); i++)
		winners.push_back(pairs[i].second);
	if (winners.size() > 1)
		sort_vector(winners);

	std::vector<std::pair<int, int> > sorted_pairs;
	for (size_t i = 0; i < winners.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (pairs[j].second == winners[i])
			{
				sorted_pairs.push_back(pairs[j]);
				pairs.erase(pairs.begin() + j);
				break;
			}
		}
	}
	pairs = sorted_pairs;
}

void	sort_vector(std::vector<int> &vec)
{
	if (vec.size() <= 1)
		return;
	std::vector<std::pair<int, int> > pairs;
	make_pairs_vec(vec, pairs);

	std::vector<int> sorted;
	for (size_t i = 0; i < pairs.size(); i++)
		sorted.push_back(pairs[i].second);
	sorted.insert(sorted.begin(), pairs[0].first);
	insert_jacobs(sorted, pairs);

	if (vec.size() % 2 == 1)
	{
		int last = vec[vec.size() - 1];
		std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), last);
		sorted.insert(pos, last);
	}
	vec = sorted;
}

static void	make_pairs_deq(std::deque<int> &deq, std::deque<std::pair<int, int> > &pairs)
{
	for (size_t i = 0; i + 1 < deq.size(); i += 2)
	{
		if (deq[i] < deq[i + 1])
			pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
		else
			pairs.push_back(std::make_pair(deq[i + 1], deq[i]));
	}

	std::deque<int> winners;
	for (size_t i = 0; i < pairs.size(); i++)
		winners.push_back(pairs[i].second);
	if (winners.size() > 1)
		sort_deque(winners);

	std::deque<std::pair<int, int> > sorted_pairs;
	for (size_t i = 0; i < winners.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (pairs[j].second == winners[i])
			{
				sorted_pairs.push_back(pairs[j]);
				pairs.erase(pairs.begin() + j);
				break;
			}
		}
	}
	pairs = sorted_pairs;
}

void	sort_deque(std::deque<int> &deq)
{
	if (deq.size() <= 1)
		return;
	std::deque<std::pair<int, int> > pairs;
	make_pairs_deq(deq, pairs);

	std::deque<int> sorted;
	for (size_t i = 0; i < pairs.size(); i++)
		sorted.push_back(pairs[i].second);
	sorted.push_front(pairs[0].first);
	insert_jacobs(sorted, pairs);

	if (deq.size() % 2 == 1)
	{
		int last = deq[deq.size() - 1];
		std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), last);
		sorted.insert(pos, last);
	}
	deq = sorted;
}