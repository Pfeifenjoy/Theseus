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
			float exmatriculationAmount;

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
		};
	}
}
#endif

