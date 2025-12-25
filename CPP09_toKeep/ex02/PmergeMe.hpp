
#pragma once

# include <iostream>
# include <sstream>
# include <climits>

# include <algorithm>
# include <vector>
# include <deque>

# include <ctime>
# include <sys/time.h>


void	sort_vector(std::vector<int> &vec);
void	sort_deque(std::deque<int> &deq);

double	get_time_u();
int		jacobsthal(int n);

bool	compareSecond(std::pair<int, int>& a, std::pair<int, int>& b);

template <typename C, typename P>
void	sort_pairs( C &vec, P &pairs)
{
	for (size_t i = 0; i + 1 < vec.size(); i += 2)
	{
		if (vec[i] < vec[i + 1])
			pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
		else
			pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
	}

	std::sort(pairs.begin(), pairs.end(), compareSecond);
}

template <typename T, typename P>
void	insert_jacobs( T &sorted, P &pairs)
{
	int	size = (int)pairs.size();
	int	k = 3;
	int	prev_j = 1;

	while (prev_j < size)
	{
		int curr_j = std::min(jacobsthal(k), size);

		for (int i = curr_j - 1; i >= prev_j; i--)
		{
			int	to_insert = pairs[i].first;
			typename T::iterator limit = std::find(sorted.begin(), sorted.end(), pairs[i].second);
			typename T::iterator pos = std::lower_bound(sorted.begin(), limit, to_insert);
			sorted.insert(pos, to_insert);
		}
		prev_j = curr_j;
		k++;
	}
}
