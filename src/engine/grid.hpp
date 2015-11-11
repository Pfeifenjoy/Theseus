#ifndef _THESEUS_ENGINE_GRID_H
#define _THESEUS_ENGINE_GRID_H 

#include <array>
#include <utility>
#include <SFML/System.hpp>
#include <algorithm>
#include <cassert>
#include <vector>
#include <unordered_map>

namespace theseus
{
namespace engine
{

template <class T, int width, int height, int cellSize>
class Grid
{
	private:
		std::vector<std::unordered_multimap<T, sf::Vector2<float> >> entries;

		std::pair<int, int> toCellCoordinates(sf::Vector2f position) const
		{
			int x = position.x / cellSize;
			int y = position.y / cellSize;

			if (x < 0) x = 0;
			if (y < 0) y = 0;
			if (x >= width) x = width - 1;
			if (y >= height) y = height - 1;

			return std::make_pair(x, y);
		}

		std::unordered_multimap<T, sf::Vector2<float> >& cell(sf::Vector2f position)
		{
			int x, y;
			std::tie(x, y) = toCellCoordinates(position);
			return entries[y * width + x];
		}

	public:

		Grid()
		{
			entries.reserve(width * height);
			for (int i = 0; i < width * height; ++i)
			{
				entries.emplace_back();
			}
		}

		void insert(sf::Vector2f position, T value)
		{
			cell(position).insert(std::make_pair(value, position));
		}

		void remove(sf::Vector2f position, T value)
		{
			cell(position).erase(value);
		}

		void updatePosition(sf::Vector2f oldPosition, sf::Vector2f newPosition, T value)
		{
			auto& oldCell = cell(oldPosition);
			auto& newCell = cell(newPosition);
			
			// find the entry in the old cell
			auto it_OldEntry = oldCell.find(value);
			assert(it_OldEntry != oldCell.end());

			// update it!
			if (&oldCell == &newCell)
			{
				it_OldEntry->second = newPosition;
			}
			else
			{
				oldCell.erase(it_OldEntry);
				newCell.insert(std::make_pair(value, newPosition));
			}
		}

		std::vector<std::pair<sf::Vector2f, T> > find(sf::Vector2f tl, sf::Vector2f br) const
		{
			int minX, maxX, minY, maxY;
			std::tie(minX, minY) = toCellCoordinates(tl);
			std::tie(maxX, maxY) = toCellCoordinates(br);
			
			std::vector<std::pair<sf::Vector2f, T> > result;

			for (int x = minX; x <=maxX; ++x)
			{
				for (int y = minY; y <= maxY; ++y)
				{
					auto& cell = entries[y * width + x];
					for (auto entry : cell)
					{
						result.push_back(std::make_pair(entry.second, entry.first));
					}
				}
			}

			return result;
		}
};
}
}

#endif
