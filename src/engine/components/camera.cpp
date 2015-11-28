/**
 * Autor: Tobias Dorra
 */
#include "camera.hpp"

using namespace theseus::engine::components;

sf::View& Camera::view()
{
	return m_view;
}
		
const sf::View& Camera::view() const
{
	return m_view;
}

Camera::~Camera()
{}
