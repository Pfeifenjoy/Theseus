/**
*  @Author: Philipp Pütz
*/

#ifndef _THESEUS_MESSAGES_EXMATRICULATION_H
#define _THESEUS_MESSAGES_EXMATRICULATION_H

namespace theseus
{
	namespace messages {
		class Exmatriculation
		{
		private:
			bool professorSended = false;

		public:
			~Exmatriculation();

			void setProfessorSended();

			bool getProfessorSended() const;
		};
	}
}
#endif

