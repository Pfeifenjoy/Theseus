#ifndef THESEUS_ENGINE_QUADTREE_H
#define THESEUS_ENGINE_QUADTREE_H

#include "components/position.hpp"
#include <SFML/System.hpp>
#include <memory>
#include <utility>
#include <list>
#include <algorithm>
#include <limits>

namespace theseus
{
namespace engine
{

template <class T>
class QuadTree
{
private:
	sf::Vector2f center;
	T value;
	bool isEmpty;
	std::unique_ptr<QuadTree> child_lt = nullptr; // l = left
	std::unique_ptr<QuadTree> child_rt = nullptr; // r = right
	std::unique_ptr<QuadTree> child_lb = nullptr; // t = top
	std::unique_ptr<QuadTree> child_rb = nullptr; // b = bottom

	float max_x;
	float min_x;
	float max_y;
	float min_y;

	sf::Vector2f lastRemovedPosition;

public:

	/**
	 * Default constructor
	 */
	QuadTree()
	{
		isEmpty = true;
		max_x = std::numeric_limits<float>::min();
		min_x = std::numeric_limits<float>::max();
		max_y = std::numeric_limits<float>::min();
		min_y = std::numeric_limits<float>::max();
	}

	/**
	 * Constructor for a leaf node
	 */
	QuadTree(sf::Vector2f position, T value)
	{
		center = position;
		this->value = value;
		isEmpty = false;
		max_x = position.x;
		min_x = position.x;
		max_y = position.y;
		min_y = position.y;
	}
private:

	/**
	 * Returns a reference to the child node which is responsible for the given position. (const)
	 */
	const std::unique_ptr<QuadTree>& chooseChildNode(sf::Vector2f position) const
	{
		if (position.x <= center.x && position.y <= center.y)
			return child_lt;
		if (position.x > center.x && position.y <= center.y)
			return child_rt;
		if (position.x <= center.x && position.y > center.y)
			return child_lb;
		return child_rb;
	}

	/**
	 * Returns a reference to the child node which is responsible for the given position. (non-const)
	 */
	std::unique_ptr<QuadTree>& chooseChildNode(sf::Vector2f position)
	{
		if (position.x <= center.x && position.y <= center.y)
			return child_lt;
		if (position.x > center.x && position.y <= center.y)
			return child_rt;
		if (position.x <= center.x && position.y > center.y)
			return child_lb;
		return child_rb;
	}

	float maxYAboveCenter(float defaultValue)
	{
		if (child_lt != nullptr && child_rt != nullptr)
			return std::max(child_lt->max_y, child_rt->max_y);
		if (child_lt != nullptr)
			return child_lt->max_y;
		if (child_rt != nullptr)
			return child_rt->max_y;
		return defaultValue;
	}

	float minYbelowCenter(float defaultValue)
	{
		if (child_lb != nullptr && child_rb != nullptr)
			return std::min(child_lb->min_y, child_rb->min_y);
		if (child_lb != nullptr)
			return child_lb->min_y;
		if (child_rb != nullptr)
			return child_rb->min_y;
		return defaultValue;
	}

	float maxXleftFromCenter(float defaultValue)
	{
		if (child_lt != nullptr && child_lb != nullptr)
			return std::max(child_lt->max_x, child_lb->max_x);
		if (child_lt != nullptr)
			return child_lt->max_x;
		if (child_lb != nullptr)
			return child_lb->max_x;
		return defaultValue;
	}

	float minXrightFromCenter(float defaultValue)
	{
		if (child_rt != nullptr && child_rb != nullptr)
			return std::min(child_rt->min_x, child_rb->min_x);
		if (child_rt != nullptr)
			return child_rt->min_x;
		if (child_rb != nullptr)
			return child_rb->min_x;
		return defaultValue;
	}

	float calcMaxY(float defaultValue)
	{
		if (child_lb != nullptr && child_rb != nullptr)
			return std::max(child_lb->max_y, child_rb->max_y);
		if (child_lb != nullptr)
			return child_lb->max_y;
		if (child_rb != nullptr)
			return child_rb->max_y;
		if (!isEmpty)
			return center.y;
		return maxYAboveCenter(defaultValue);
	}

	float calcMinY(float defaultValue)
	{
		if (child_lt != nullptr && child_rt != nullptr)
			return std::min(child_lt->min_y, child_rt->min_y);
		if (child_lt != nullptr)
			return child_lt->min_y;
		if (child_rt != nullptr)
			return child_rt->min_y;
		if (!isEmpty)
			return center.y;
		return minYbelowCenter(defaultValue);
	}

	float calcMinX(float defaultValue)
	{
		if (child_lt != nullptr && child_lb != nullptr)
			return std::min(child_lt->min_x, child_lb->min_x);
		if (child_lt != nullptr)
			return child_lt->min_x;
		if (child_lb != nullptr)
			return child_lb->min_x;
		if (!isEmpty)
			return center.x;
		return minXrightFromCenter(defaultValue);
	}

	float calcMaxX(float defaultValue)
	{
		if (child_rt != nullptr && child_rb != nullptr)
			return std::max(child_rt->max_x, child_rb->max_x);
		if (child_rt != nullptr)
			return child_rt->max_x;
		if (child_rb != nullptr)
			return child_rb->max_x;
		if (!isEmpty)
			return center.x;
		return maxXleftFromCenter(defaultValue);
	}

	void recalcMinMaxAfterRemove()
	{
		if (lastRemovedPosition.x == max_x)
			max_x = calcMaxX(std::numeric_limits<float>::min());
		if (lastRemovedPosition.x == min_x)
			min_x = calcMinX(std::numeric_limits<float>::max());
		if (lastRemovedPosition.y == max_y)
			max_y = calcMaxY(std::numeric_limits<float>::min());
		if (lastRemovedPosition.y == min_y)
			min_y = calcMinY(std::numeric_limits<float>::max());
	}

public:

	/**
	 * Inserts a value into the quadtree
	 */
	void insert(sf::Vector2f position, T v)
	{
		// update the max- and min-values
		if (position.x > max_x)
			max_x = position.x;
		if (position.x < min_x)
			min_x = position.x;
		if (position.y > max_y)
			max_y = position.y;
		if (position.y < min_y)
			min_y = position.y;

		// try to refill empty nodes
		if (isEmpty
				&& position.x >= maxXleftFromCenter(position.x - 1)
				&& position.x < minXrightFromCenter(position.x + 1)
				&& position.y >= maxYAboveCenter(position.y - 1)
				&& position.y <  minYbelowCenter(position.y + 1)
				)
		{
			value = v;
			center = position;
			isEmpty = false;
			return;
		}

		// insert into the correct child node
		auto& child = chooseChildNode(position);
		if (child == nullptr)
		{
			child = std::unique_ptr<QuadTree>(new QuadTree(position, v));
		}
		else
		{
			child->insert(position, v);
		}
	}

	/**
	 * Returns a set of all entries that are in the rectangle defined by the parameters left_top and right_bottom.
	 */
	std::list<std::pair<sf::Vector2f, T> >	find(sf::Vector2f left_top, sf::Vector2f right_bottom) const
	{
		auto& left_top_child = chooseChildNode(left_top);
		auto& right_bottom_child = chooseChildNode(right_bottom);
		
		// if the rect spans over all child nodes: recurse into all of them
		if (&left_top_child == &child_lt && &right_bottom_child == &child_rb)
		{
			// recursion
			std::list<std::pair<sf::Vector2f, T> > result;
			if (child_lt != nullptr)
			{
				result = child_lt->find(left_top, right_bottom);
			}
			if (child_rt != nullptr)
			{
				auto result_rt = child_rt->find(left_top, right_bottom);
				result.splice(result.begin(), result_rt);
			}
			if (child_lb != nullptr)
			{
				auto result_lb = child_lb->find(left_top, right_bottom);
				result.splice(result.begin(), result_lb);
			}
			if (child_rb != nullptr)
			{
				auto result_rb = child_rb->find(left_top, right_bottom);
				result.splice(result.begin(), result_rb);
			}

			// insert own value
			if (!isEmpty)
				result.push_back(std::make_pair(center, value));

			// return
			return result;
		}

		// if the rect spans only over a single child, it's results can be forwarded.
		//  ... in most cases...
		if (&left_top_child == &right_bottom_child)
		{
			if (left_top_child != nullptr)
			{
				return left_top_child->find(left_top, right_bottom);
			}

		}

		// in all other cases, the rect spans over two child notes.
		// then, the recursive results for these nodes have to be combined.
		std::list<std::pair<sf::Vector2f, T> > result;
		if (left_top_child != nullptr)
		{
			result = left_top_child->find(left_top, right_bottom);
		}
		if (right_bottom_child != nullptr)
		{
			auto result_rb = right_bottom_child->find(left_top, right_bottom);
			result.splice(result.begin(), result_rb);
		}
		return result;
	}

	/**
	 * removes an element from the tree
	 *
	 * return value:
	 * 	true: 	if the element was removed successfully.
	 * 	false: 	if the element was not found at the given position.
	 */
	bool remove(sf::Vector2f position, T value)
	{
		// This node contains the value -> remove it
		if (!isEmpty && value == this->value)
		{
			isEmpty = true;
			lastRemovedPosition = center;
			recalcMinMaxAfterRemove();
			return true;
		}

		// This node does not contain the searched value -> remove recursively
		auto& childToRemoveFrom = chooseChildNode(position);
		if (childToRemoveFrom != nullptr)
		{
			bool success = childToRemoveFrom->remove(position, value);
			if (success)
				lastRemovedPosition = childToRemoveFrom->lastRemovedPosition;
			if (childToRemoveFrom->isEmpty
					&& childToRemoveFrom->child_lt == nullptr
					&& childToRemoveFrom->child_rt == nullptr
					&& childToRemoveFrom->child_lb == nullptr
					&& childToRemoveFrom->child_rb == nullptr)
				childToRemoveFrom.reset();
			if (success)
				recalcMinMaxAfterRemove();
			return success;
		}

		// Value was not found
		return false;
	}

	/**
	 * Reinserts an element into the quadtree with a new position.
	 */
	void updatePosition(sf::Vector2f oldPosition, sf::Vector2f newPosition, T value)
	{
		// Keep it simple for now. 
		remove(oldPosition, value);
		insert(newPosition, value);
	}
};
}
}

#endif
