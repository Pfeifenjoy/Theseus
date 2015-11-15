/**
*  @Author: Philipp Pütz
*/

#ifndef _THESEUS_MESSAGES_EXMATRICULATION_H
#define _THESEUS_MESSAGES_EXMATRICULATION_H

#include <SFML/System.hpp>

namespace theseus
{
	namespace messages {
		class Exmatriculation
		{
		private:
			bool professorSended = false;
			float exmatriculationAmount;
			sf::Vector2f origin;

		public:
			~Exmatriculation();

			/**
			 * Whether the exmatriculation was sent from a professor or a mad student (in the higher levels)
			 */
			void setProfessorSended();
			bool getProfessorSended() const;
			
			/**
			 * How strong the exmatriculation signal is.
			 */
			void setExmatriculationAmount(float value);
			float getExmatriculationAmount() const;

			/**
			 * Where does the signal come from?
			 */
			void setOrigin(sf::Vector2f value);
			sf::Vector2f getOrigin() const;
		};
	}
}
#endif

